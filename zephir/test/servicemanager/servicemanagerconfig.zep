/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Test\ServiceManager;

/**
 * Simple object that wrap a configuration for a service manager
 */
class ServiceManagerConfig
{
    /**
     * @var array
     */
    protected config = null;

    /**
     * @param array config
     */
    public function __construct(config = null)
    {
        let this->config = config;
    }

    /**
     * Get invokables configuration
     *
     * @return array
     */
    public function getInvokablesConfig()
    {
        var config, invokablesConfig;
        let config = this->config;

        if fetch invokablesConfig, config["invokables"] {
            return invokablesConfig;
        }

        return null;
    }

    /**
     * Get factories configuration
     *
     * @return array
     */
    public function getFactoriesConfig()
    {
        var config, factoriesConfig;
        let config = this->config;

        if fetch factoriesConfig, config["factories"] {
            return factoriesConfig;
        }

        return null;
    }

    /**
     * Get abstract factories configuration
     *
     * @return array
     */
    public function getAbstractFactoriesConfig()
    {
        var config, abstractFactoriesConfig;
        let config = this->config;

        if fetch abstractFactoriesConfig, config["abstract_factories"] {
            return abstractFactoriesConfig;
        }

        return null;
    }

    /**
     * Get the delegators factories configuration
     *
     * @return array
     */
    public function getDelegatorsConfig()
    {
        var config, delegatorsConfig;
        let config = this->config;

        if fetch delegatorsConfig, config["delegators"] {
            return delegatorsConfig;
        }

        return null;
    }

    /**
     * Get initializers configuration
     *
     * @return array
     */
    public function getInitializersConfig()
    {
        var config, initializersConfig;
        let config = this->config;

        if fetch initializersConfig, config["initializers"] {
            return initializersConfig;
        }

        return null;
    }

    /**
     * Get aliases configuration
     *
     * @return array
     */
    public function getAliasesConfig()
    {
        var config, aliasesConfig;
        let config = this->config;

        if fetch aliasesConfig, config["aliases"] {
            return aliasesConfig;
        }

        return null;
    }

    /**
     * Get shard configuration
     *
     * @return array
     */
    public function getSharedConfig()
    {
        var config, sharedConfig;
        let config = this->config;

        if fetch sharedConfig, config["shared"] {
            return sharedConfig;
        }

        return null;
    }
}
