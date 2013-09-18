/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zephir\ServiceManager;

interface FactoryInterface
{
    /**
     * Create service using a factory
     *
     * @param  ServiceLocatorInterface serviceLocator
     * @param  array                   creationOptions
     * @return mixed
     */
    public function createService(serviceLocator, creationOptions = null);
}
