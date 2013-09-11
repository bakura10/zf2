
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
ZEPHIR_INIT_CLASS(Zend_ServiceManager_FactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ServiceManager, FactoryInterface, zend, servicemanager_factoryinterface, zend_servicemanager_factoryinterface_method_entry);


	return SUCCESS;

}

/**
 * Create service using a factory
 *
 * @param  ServiceLocatorInterface serviceLocator
 * @param  array                   creationOptions
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zend_ServiceManager_FactoryInterface, createService);

