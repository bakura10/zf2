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
 * A plugin manager is a service manager that is specialized in creating only one
 * type of object (filters, validators...)
 */
abstract class AbstractPluginManager extends ServiceManager
{
    /**
     * {@inheritDoc}
     */
    public function get($name, array $creationOptions = array())
    {
        $plugin = parent::get($name, $creationOptions);

        $this->validatePlugin($plugin);

        return $plugin;
    }

    /**
     * Validate a plugin object
     *
     * @param  object $plugin
     * @return void
     */
    abstract public function validatePlugin($plugin);
}
