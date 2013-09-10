<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace ServiceManager;

/**
 * Service manager is a simple implementation of a service locator
 */
class ServiceManager implements ServiceLocatorInterface
{
    /**
     * List of invokables
     *
     * An invokable is created using the constructor. An invokable must not have
     * any required parameters in its constructor
     *
     * @var array
     */
    protected $invokables = array();

    /**
     * List of factories
     *
     * A factory is used to create an object and allows to inject any dependencies
     *
     * @var array|FactoryInterface[]
     */
    protected $factories = array();

    /**
     * List of abstract factories
     *
     * An abstract factory is a factory that is run if neither invokables or factories
     * is found for a given object
     *
     * @var array|AbstractFactoryInterface[]
     */
    protected $abstractFactories = array();

    /**
     * List of initializers
     *
     * An initializer is run for every object that is created by the service manager
     * in order to inject any other dependencies
     *
     * @var array|InitializerInterface[]
     */
    protected $initializers = array();

    /**
     * List of aliases
     *
     * An alias is simply a key to map to another existing key
     *
     * @var array
     */
    protected $aliases = array();

    /**
     * List of shared
     *
     * Define an array of key => boolean in order to specify if the service should
     * be shared or not
     *
     * @var array
     */
    protected $shared = array();

    /**
     * Set if the instances are shared by default in this service manager
     *
     * @var bool
     */
    protected $sharedByDefault = true;

    /**
     * List of already created instances
     *
     * @var array
     */
    protected $instances = array();

    /**
     * @param ServiceManagerConfig $config
     */
    public function __construct(ServiceManagerConfig $config = null)
    {
        if (null !== $config) {
            $this->configureServiceManager($config);
        }
    }

    /**
     * Add invokables
     *
     * @param  array $config
     * @return void
     */
    public function addInvokables(array $config)
    {
        $this->invokables = array_merge($this->invokables, $config);
    }

    /**
     * Add factories
     *
     * @param  array $config
     * @return void
     */
    public function addFactories(array $config)
    {
        $this->factories = array_merge($this->factories, $config);
    }

    /**
     * Add abstract factories
     *
     * @param  array $config
     * @return void
     */
    public function addAbstractFactories(array $config)
    {
        // We do not lazy load abstract factories and directly create instances for
        // performance reasons
        foreach ($config as &$abstractFactory) {
            if (is_string($abstractFactory) && $abstractFactory instanceof AbstractFactoryInterface) {
                $abstractFactory = new $abstractFactory();
            }
        }

        $this->abstractFactories = array_merge($this->abstractFactories, $config);
    }

    /**
     * Add initializers
     *
     * @param  array $config
     * @return void
     */
    public function addInitializers(array $config)
    {
        // We do not lazy load initializers and directly create instances for performance reasons
        foreach ($config as &$initializer) {
            if (is_string($initializer) && $initializer instanceof InitializerInterface) {
                $initializer = new $initializer();
            }
        }

        $this->initializers = array_merge($this->initializers, $config);
    }

    /**
     * Add aliases
     *
     * @param  array $config
     * @return void
     */
    public function addAliases(array $config)
    {
        $this->aliases = array_merge($this->aliases, $config);
    }

    /**
     * Add shared objects
     *
     * @param  array $config
     * @return void
     */
    public function addShared(array $config)
    {
        $this->shared = array_merge($this->shared, $config);
    }

    /**
     * Set if instances are shared by default
     *
     * @param  bool $sharedByDefault
     * @return void
     */
    public function setSharedByDefault($sharedByDefault)
    {
        $this->sharedByDefault = (bool) $sharedByDefault;
    }

    /**
     * Get if this service manager is configured so that instances are shared by default
     *
     * @return bool
     */
    public function isSharedByDefault()
    {
        return $this->sharedByDefault;
    }

    /**
     * {@inheritDoc}
     */
    public function get($name, array $creationOptions = array())
    {
        $name = $this->resolveAlias($name);

        // Check if the instance for that name has already been created and is not shared
        $shared = isset($this->shared[$name]) ? $this->shared[$name] : $this->sharedByDefault;

        if (isset($this->instances[$name]) || isset($this->shared[$name]) && !$this->shared[$name]) {
            return $this->instances[$name];
        }

        $instance = $this->create($name, $creationOptions);

        // Add the object to identity map is configured this way
        if ($shared) {
            $this->instances[$name] = $instance;
        }

        return $instance;
    }

    /**
     * {@inheritDoc}
     */
    public function has($name, $checkAbstractFactories = true)
    {
        $name  = $this->resolveAlias($name);
        $found = isset($this->invokables[$name]) || isset($this->factories[$name]);

        if ($found || !$checkAbstractFactories) {
            return $found;
        }

        foreach ($this->abstractFactories as $abstractFactory) {
            if ($abstractFactory->canCreateServiceWithName($name)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Resolve an alias
     *
     * @param  string $name
     * @return string
     */
    public function resolveAlias($name)
    {
        while (isset($this->aliases[$name])) {
            $name = $this->aliases[$name];
        }

        return $name;
    }

    /**
     * Create a new instance
     *
     * This will always return a new instance, even if it has already been created (for most cases, you
     * should use "get" method). Note that this method does not work with aliases, it expects the name
     * to be already resolved
     *
     * @param  string $name
     * @param  array $creationOptions
     * @return mixed
     * @throws Exception\ServiceNotFoundException
     */
    public function create($name, array $creationOptions = array())
    {
        $instance = null;

        if (isset($this->invokables[$name])) {
            $instance = $this->createFromInvokable($name, $creationOptions);
        } elseif (isset($this->factories[$name])) {
            $instance = $this->createFromFactory($name, $creationOptions);
        } else {
            $instance = $this->createFromAbstractFactory($name, $creationOptions);
        }

        if (null === $instance) {
            throw new Exception\ServiceNotFoundException(sprintf(
                'No invokable, factory or abstract factory were found for creating "%s"',
                $name
            ));
        }

        // Now use each initializers
        foreach ($this->initializers as $initializer) {
            if ($initializer instanceof InitializerInterface) {
                $initializer->initialize($instance);
            } else {
                $initializer($instance, $this);
            }
        }

        return $instance;
    }

    /**
     * Configure the service manager
     *
     * @param  ServiceManagerConfig $config
     * @return void
     */
    protected function configureServiceManager(ServiceManagerConfig $config)
    {
        $this->addInvokables($config->getInvokablesConfig());
        $this->addFactories($config->getFactoriesConfig());
        $this->addAbstractFactories($config->getAbstractFactoriesConfig());
        $this->addInitializers($config->getInitializersConfig());
        $this->addAliases($config->getAliasesConfig());
        $this->addShared($config->getSharedConfig());
    }

    /**
     * Create an object from the invokable
     *
     * @param string $name
     * @param array  $creationOptions
     * @return mixed
     */
    protected function createFromInvokable($name, array $creationOptions = array())
    {
        return isset($this->invokables[$name]) ? new $this->invokables[$name]($creationOptions) : null;
    }

    /**
     * Create an object from the factory
     *
     * @param  string $name
     * @param  array  $creationOptions
     * @return mixed
     */
    protected function createFromFactory($name, array $creationOptions = array())
    {
        $factory = $this->factories[$name];

        if (is_string($factory) && $factory instanceof FactoryInterface) {
            $this->factories[$name] = new $factory();
        }

        if ($factory instanceof FactoryInterface) {
            return $factory->createService($this, $creationOptions);
        }

        if (is_callable($factory)) {
            return $factory($this, $creationOptions);
        }

        return null;
    }

    /**
     * Create an object from the abstract factory
     *
     * @param  string $name
     * @param  array  $creationOptions
     * @return mixed
     */
    protected function createFromAbstractFactory($name, array $creationOptions = array())
    {
        foreach ($this->abstractFactories as $abstractFactory) {
            if ($abstractFactory->canCreateServiceWithName($name)) {
                return $abstractFactory->createServiceWithName($name, $creationOptions);
            }
        }

        return null;
    }
}
