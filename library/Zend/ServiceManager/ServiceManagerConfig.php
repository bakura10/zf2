<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\ServiceManager;

/**
 * Simple object that wrap a configuration for a service manager
 */
class ServiceManagerConfig
{
    /**
     * @var array
     */
    protected $config = array();

    /**
     * @param array $config
     */
    public function __construct(array $config = array())
    {
        $this->config = $config;
    }

    /**
     * Get invokables configuration
     *
     * @return array
     */
    public function getInvokablesConfig()
    {
        return isset($this->config['invokables']) ? $this->config['invokables'] : array();
    }

    /**
     * Get factories configuration
     *
     * @return array
     */
    public function getFactoriesConfig()
    {
        return isset($this->config['factories']) ? $this->config['factories'] : array();
    }

    /**
     * Get abstract factories configuration
     *
     * @return array
     */
    public function getAbstractFactoriesConfig()
    {
        return isset($this->config['abstract_factories']) ? $this->config['abstract_factories'] : array();
    }

    /**
     * Get the delegators factories configuration
     *
     * @return array
     */
    public function getDelegatorsConfig()
    {
        return isset($this->config['delegators']) ? $this->config['delegators'] : array();
    }

    /**
     * Get initializers configuration
     *
     * @return array
     */
    public function getInitializersConfig()
    {
        return isset($this->config['initializers']) ? $this->config['initializers'] : array();
    }

    /**
     * Get aliases configuration
     *
     * @return array
     */
    public function getAliasesConfig()
    {
        return isset($this->config['aliases']) ? $this->config['aliases'] : array();
    }

    /**
     * Get shard configuration
     *
     * @return array
     */
    public function getSharedConfig()
    {
        return isset($this->config['shared']) ? $this->config['shared'] : array();
    }
}
