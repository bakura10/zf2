/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Test\ServiceManager;

interface AbstractFactoryInterface
{
    /**
     * Determine if we can create a service with name
     *
     * @param ServiceLocatorInterface serviceLocator
     * @param string                  name
     * @return bool
     */
    public function canCreateServiceWithName(serviceLocator, name);

    /**
     * Create service with name
     *
     * @param ServiceLocatorInterface serviceLocator
     * @param string                  name
     * @param array                   creationOptions
     * @return mixed
     */
    public function createServiceWithName(serviceLocator, name, creationOptions = null);
}
