
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
ZEPHIR_INIT_CLASS(Zend_ServiceManager_AbstractFactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ServiceManager, AbstractFactoryInterface, zend, servicemanager_abstractfactoryinterface, zend_servicemanager_abstractfactoryinterface_method_entry);


	return SUCCESS;

}

/**
 * Determine if we can create a service with name
 *
 * @param ServiceLocatorInterface serviceLocator
 * @param string                  name
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zend_ServiceManager_AbstractFactoryInterface, canCreateServiceWithName);

/**
 * Create service with name
 *
 * @param ServiceLocatorInterface serviceLocator
 * @param string                  name
 * @param array                   creationOptions
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zend_ServiceManager_AbstractFactoryInterface, createServiceWithName);

