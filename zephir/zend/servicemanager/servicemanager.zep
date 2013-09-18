/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\ServiceManager;

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
    protected invokables;

    /**
     * List of factories
     *
     * A factory is used to create an object and allows to inject any dependencies
     *
     * @var array|FactoryInterface[]
     */
    protected factories;

    /**
     * List of abstract factories
     *
     * An abstract factory is a factory that is run if neither invokables or factories
     * is found for a given object
     *
     * @var array|AbstractFactoryInterface[]
     */
    protected abstractFactories;

    /**
     * List of delegators
     *
     * A delegator allows to delegate the creation of an instance to another factory
     *
     * @var array|DelegatorFactoryInterface[]
     */
    protected delegators;

    /**
     * List of initializers
     *
     * An initializer is run for every object that is created by the service manager
     * in order to inject any other dependencies
     *
     * @var array|InitializerInterface[]
     */
    protected initializers;

    /**
     * List of aliases
     *
     * An alias is simply a key to map to another existing key
     *
     * @var array
     */
    protected aliases;

    /**
     * List of shared
     *
     * Define an array of key => boolean in order to specify if the service should
     * be shared or not
     *
     * @var array
     */
    protected shared;

    /**
     * Set if the instances are shared by default in this service manager
     *
     * @var bool
     */
    protected sharedByDefault = true;

    /**
     * List of already created instances
     *
     * @var array
     */
    protected instances;

    /**
     * @param ServiceManagerConfig config
     */
    public function __construct(config = null)
    {
        if config {
            this->configureServiceManager(config);
        }
    }

    /**
     * Add invokables
     *
     * @param  array config
     * @return void
     */
    public function addInvokables(config)
    {
        let this->invokables = array_merge(this->invokables, config);
    }

    /**
     * Set invokables (overriding old ones)
     *
     * @param array config
     * @return void
     */
    public function setInvokables(config)
    {
        let this->invokables = [];
        this->setInvokables(config);
    }

    /**
     * Add factories
     *
     * @param  array config
     * @return void
     */
    public function addFactories(config)
    {
        let this->factories = array_merge(this->factories, config);
    }

    /**
     * Set factories (overriding old ones)
     *
     * @param array config
     * @return void
     */
    public function setFactories(config)
    {
        let this->factories = [];
        this->addFactories(config);
    }

    /**
     * Add abstract factories
     *
     * @param  array config
     * @return void
     */
    public function addAbstractFactories(config)
    {
        var abstractFactory, abstractFactories;
        let abstractFactories = [];

        // We do not lazy load abstract factories and directly create instances for
        // performance reasons
        for abstractFactory in config {
            if typeof name == "string" {
                let abstractFactory = new name();
            }

            let abstractFactories[] = abstractFactory;
        }

        let this->abstractFactories = array_merge(this->abstractFactories, abstractFactories);
    }

    /**
     * Set abstract factories (overriding old ones)
     *
     * @param  array config
     * @return void
     */
    public function setAbstractFactories(config)
    {
        let this->abstractFactories = [];
        this->addAbstractFactories(config);
    }

    /**
     * Add delegators
     *
     * @param  array config
     * @return void
     */
    public function addDelegators(config)
    {
        let this->delegators = array_merge(this->delegators, config);
    }

    /**
     * Set delegators (overriding old ones)
     *
     * @param array config
     * @return void
     */
    public function setDelegators(config)
    {
        let this->delegators = [];
        this->addDelegators(config);
    }

    /**
     * Add initializers
     *
     * @param  array config
     * @return void
     */
    public function addInitializers(config)
    {
        var initializer, initializers;
        let initializers = [];

        // We do not lazy load initializers and directly create instances for performance reasons
        for initializer in config {
            if typeof name == "string" {
                let initializer = new name();
            }

            let initializers[] = initializer;
        }

        let this->initializers = array_merge(this->initializers, initializers);
    }

    /**
     * Set initializers (overriding old ones)
     *
     * @param array config
     * @return void
     */
    public function setInitializers(config)
    {
        let this->initializers = [];
        this->addInitializers(config);
    }

    /**
     * Add aliases
     *
     * @param  array config
     * @return void
     */
    public function addAliases(config)
    {
        let this->aliases = array_merge(this->aliases, config);
    }

    /**
     * Set aliases (overriding old ones)
     *
     * @param array config
     * @return void
     */
    public function setAliases(config)
    {
        let this->aliases = [];
        this->addAliases(config);
    }

    /**
     * Add shared objects
     *
     * @param  array config
     * @return void
     */
    public function addShared(config)
    {
        let this->shared = array_merge(this->shared, config);
    }

    /**
     * Set shared objects (overriding old ones)
     *
     * @param array config
     * @return void
     */
    public function setShared(config)
    {
        let this->shared = [];
        this->addShared(config);
    }

    /**
     * Set if instances are shared by default
     *
     * @param  bool sharedByDefault
     * @return void
     */
    public function setSharedByDefault(sharedByDefault)
    {
        let this->sharedByDefault = (bool) sharedByDefault;
    }

    /**
     * Get if this service manager is configured so that instances are shared by default
     *
     * @return bool
     */
    public function isSharedByDefault()
    {
        return this->sharedByDefault;
    }

    /**
     * {@inheritDoc}
     */
    public function set(name, instance)
    {
        let this->instances[name] = instance;
    }

    /**
     * {@inheritDoc}
     */
    public function get(name, creationOptions = null)
    {
        boolean shared;
        var sharedInstances, instances, instance;

        let name = this->resolveAlias(name);

        // Check if the instance for that name has already been created and is not shared
        let sharedInstances = this->shared;
        if !fetch shared, sharedInstances[name] {
            let shared = (bool) this->sharedByDefault;
        }

        let instances = this->instances;
        if shared && isset instances[name] {
            return instances[name];
        }

        let instance = this->create(name, creationOptions);

        if shared {
            let this->instances[name] = instance;
        }

        return instance;
    }

    /**
     * {@inheritDoc}
     */
    public function has(name, checkAbstractFactories = true)
    {
        boolean found;
        var invokables, factories, instances;

        let invokables = this->invokables;
        let factories  = this->factories;
        let instances  = this->instances;

        let name  = this->resolveAlias($name);
        let found = isset invokables[name] || isset factories[name] || isset instances[name];

        if found || checkAbstractFactories == false {
            return found;
        }

        var abstractFactory, abstractFactories;
        let abstractFactories = this->abstractFactories;

        for abstractFactory in abstractFactories {
            if abstractFactory->canCreateServiceWithName(this, name) {
                return true;
            }
        }

        return false;
    }

    /**
     * Resolve an alias
     *
     * @param  string name
     * @return string
     */
    public function resolveAlias(name)
    {
        var aliases;
        let aliases = this->aliases;

        while isset aliases[name] {
            let name = aliases[name];
        }

        return name;
    }

    /**
     * Create a new instance
     *
     * This will always return a new instance, even if it has already been created (for most cases, you
     * should use "get" method). Note that this method does not work with aliases, it expects the name
     * to be already resolved
     *
     * @param  string name
     * @param  array  creationOptions
     * @return mixed
     * @throws Exception\ServiceNotFoundException
     */
    public function create(name, creationOptions = null)
    {
        var instance, invokables, factories, initializers;

        let instance     = null;
        let invokables   = this->invokables;
        let factories    = this->factories;
        let initializers = this->initializers;

        /*if isset invokables[name] {
            let instance = this->createFromInvokable(name, creationOptions);
        } else if isset factories[name] {
            let instance = this->createFromFactory(name, creationOptions);
        } else {
            let instance = this->createFromAbstractFactory(name, creationOptions);
        }*/

        if isset invokables[name] {
            let instance = this->createFromInvokable(name, creationOptions);
        } else {
            let instance = this->createFromAbstractFactory(name, creationOptions);
        }

        if !instance {
            throw new Zend\ServiceManager\Exception\ServiceNotFoundException(sprintf(
                "No invokable, factory or abstract factory were found for creating \"%s\"",
                name
            ));
        }

        // Now use each initializers

        var initializer;
        for initializer in initializers {
            //if ($initializer instanceof InitializerInterface) {
            //                $initializer->initialize($instance, $this);

            if is_callable(initializer) {
                initializer(instance, this);
            }
        }

        return instance;
    }

    /**
     * Retrieve a keyed list of all registered services. Handy for debugging!
     *
     * @return array
     */
    public function getRegisteredServices()
    {
        return [
            "invokables": array_keys(this->invokables),
            "factories" : array_keys(this->factories),
            "aliases"   : array_keys(this->aliases),
            "instances" : array_keys(this->instances)
        ];
    }

    /**
     * Configure the service manager
     *
     * @param  ServiceManagerConfig config
     * @return void
     */
    protected function configureServiceManager(config)
    {
        this->addInvokables(config->getInvokablesConfig());
        this->addFactories(config->getFactoriesConfig());
        this->addAbstractFactories(config->getAbstractFactoriesConfig());
        this->addDelegators(config->getDelegatorsConfig());
        this->addInitializers(config->getInitializersConfig());
        this->addAliases(config->getAliasesConfig());
        this->addShared(config->getSharedConfig());
    }

    /**
     * Create an object from the invokable
     *
     * @param string name
     * @param array  creationOptions
     * @return mixed
     */
    protected function createFromInvokable(name, creationOptions = null)
    {
        var invokables, invokableClass;

        let invokables     = this->invokables;
        let invokableClass = invokables[name];

        return new invokableClass(creationOptions);
    }

    /**
     * Create an object from the factory
     *
     * @param  string name
     * @param  array  creationOptions
     * @return mixed
     */
    protected function createFromFactory(name, creationOptions = null)
    {
        var factories, factory;

        let factories = this->factories;
        let factory   = factories[name];

        if typeof factory == "string" {
            let this->factories[name] = new factory();
        }
/*
        if (is_string($factory) && $factory instanceof FactoryInterface) {
            $this->factories[$name] = new $factory();
        }

        if ($factory instanceof FactoryInterface) {
            return $factory->createService($this, $creationOptions);
        }
*/

        if is_callable($factory) {
            return factory(this, creationOptions);
        }

        return null;
    }

    /**
     * Create an object from the abstract factory
     *
     * @param  string name
     * @param  array  creationOptions
     * @return mixed
     */
    protected function createFromAbstractFactory(name, creationOptions = null)
    {
        var abstractFactories, abstractFactory;
        let abstractFactories = this->abstractFactories;

        for abstractFactory in abstractFactories {
            if abstractFactory->canCreateServiceWithName(this, name) {
                return abstractFactory->createServiceWithName(this, name, creationOptions);
            }
        }

        return null;
    }
}
