<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\ServiceManager\Compiler;

use ProxyManager\Configuration;
use ProxyManager\Factory\AccessInterceptorValueHolderFactory;
use ProxyManager\Proxy\AccessInterceptorInterface;
use ReflectionProperty;
use Zend\Code\Generator\ClassGenerator;
use Zend\ServiceManager\InitializerInterface;
use Zend\ServiceManager\ServiceLocatorInterface;
use Zend\ServiceManager\ServiceManager;

/**
 * This compiler creates a new service manager that extends the base one, and provide
 * a big switch so that creation is much faster
 */
class ServiceManagerCompiler implements ServiceLocatorCompilerInterface
{
    /**
     * @var ClassGenerator
     */
    protected $classGenerator;

    /**
     * @var array
     */
    protected $loggedInitializers = array();

    /**
     * {@inheritDoc}
     */
    public function compile(ServiceLocatorInterface $serviceLocator)
    {
        // We only handle ServiceManager instance here
        if (!$serviceLocator instanceof ServiceManager) {
            return;
        }

        $this->classGenerator = new ClassGenerator(
            'Compilation',
            'Zend\ServiceManager',
            null,
            'Zend\ServiceManager\ServiceManager'
        );

        $config  = new Configuration();
        $factory = new AccessInterceptorValueHolderFactory($config);

        // Get what we can currently compile

        $registeredServices = $serviceLocator->getRegisteredServices();
        $registeredServices = array(
            $registeredServices['invokables'],
            $registeredServices['factories'],
            $registeredServices['aliases']
        );

        // We wrap each initializer around a proxy so that we can check what is going on
        $initializersRefl = new ReflectionProperty($serviceLocator, 'initializers');
        $initializersRefl->setAccessible(true);

        $initializers      = $initializersRefl->getValue();
        $proxyInitializers = array();

        foreach ($initializers as $initializer) {
            $proxyInitializer = $factory->createProxy($initializer);

            // We add an prefix interceptor
            $proxyInitializer->setMethodPrefixInterceptor('initialize', array($this, 'logInitializerCall'));
            $proxyInitializers[] = $proxyInitializer;
        }

        $serviceLocator->setInitializers($proxyInitializers);

        $this->compileInvokables($registeredServices['invokables'], $serviceLocator);
    }

    /**
     * @param AccessInterceptorInterface    $initializerProxy
     * @param InitializerInterface|Callable $initializer
     */
    public function logInitializerCall($initializerProxy, $initializer)
    {
        $this->loggedInitializers[] = $initializer;
    }

    /**
     * @param array          $invokables
     * @param ServiceManager $serviceManager
     */
    protected function compileInvokables(array $invokables, ServiceManager $serviceManager)
    {
        $cases = '';

        foreach ($invokables as $invokableKey => $invokableValue) {
            $cases .= "case '$invokableKey':";

            $this->loggedInitializers = array(); // reset initializers that were intercepted

            $serviceManager->get($invokableKey);

            // We now have a list of initializers that were called for this invokable
            $cases .= sprintf(
                '$instance = new %s()',
                $invokableValue
            );

            foreach ($this->loggedInitializers as $loggedInitializer) {
                $cases .= sprintf(
                    '$initializer = new %s(); $initializer->initialize($instance);',
                    get_class($loggedInitializer)
                );
            }

            $cases .= "\nbreak;";
        }
    }
}
