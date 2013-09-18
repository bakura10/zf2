/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\ServiceManager;

/**
 * Service locator interface
 */
interface ServiceLocatorInterface
{
    /**
     * Set a registered instance
     *
     * @param  string name
     * @param  mixed  instance
     * @return void
     */
    public function set(name, instance);

    /**
     * Retrieve a registered instance
     *
     * @param  string  name
     * @param  array   creationOptions
     * @throws Exception\ServiceNotFoundException
     * @return object|array
     */
    public function get(name, creationOptions = null);

    /**
     * Check for a registered instance
     *
     * @param  string|array name
     * @return bool
     */
    public function has(name);
}
