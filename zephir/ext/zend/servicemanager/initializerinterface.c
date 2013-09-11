
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
ZEPHIR_INIT_CLASS(Zend_ServiceManager_InitializerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ServiceManager, InitializerInterface, zend, servicemanager_initializerinterface, zend_servicemanager_initializerinterface_method_entry);


	return SUCCESS;

}

/**
 * Initialize
 *
 * @param  mixed                   instance
 * @param  ServiceLocatorInterface serviceLocator
 * @return void
 */
ZEPHIR_DOC_METHOD(Zend_ServiceManager_InitializerInterface, initialize);

