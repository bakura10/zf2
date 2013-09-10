<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\ServiceManager\Compiler;

use Zend\ServiceManager\ServiceLocatorInterface;

/**
 * Defines a compiler for service locator
 */
interface ServiceLocatorCompilerInterface
{
    /**
     * @param  ServiceLocatorInterface $serviceLocator
     * @return mixed
     */
    public function compile(ServiceLocatorInterface $serviceLocator);
}
