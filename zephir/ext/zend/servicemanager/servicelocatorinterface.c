
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "kernel/main.h"


/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */
/**
 * Service locator interface
 */
ZEPHIR_INIT_CLASS(Zend_ServiceManager_ServiceLocatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ServiceManager, ServiceLocatorInterface, zend, servicemanager_servicelocatorinterface, zend_servicemanager_servicelocatorinterface_method_entry);


	return SUCCESS;

}

/**
 * Set a registered instance
 *
 * @param  string name
 * @param  mixed  instance
 * @return void
 */
ZEPHIR_DOC_METHOD(Zend_ServiceManager_ServiceLocatorInterface, set);

/**
 * Retrieve a registered instance
 *
 * @param  string  name
 * @param  array   creationOptions
 * @throws Exception\ServiceNotFoundException
 * @return object|array
 */
ZEPHIR_DOC_METHOD(Zend_ServiceManager_ServiceLocatorInterface, get);

/**
 * Check for a registered instance
 *
 * @param  string|array name
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zend_ServiceManager_ServiceLocatorInterface, has);

