
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
 * Interface for factories that can create delegates for services
 */
ZEPHIR_INIT_CLASS(Test_ServiceManager_DelegatorFactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Test\\ServiceManager, DelegatorFactoryInterface, test, servicemanager_delegatorfactoryinterface, test_servicemanager_delegatorfactoryinterface_method_entry);


	return SUCCESS;

}

/**
 * A factory that creates delegates of a given service
 *
 * @param ServiceLocatorInterface serviceLocator the service locator which requested the service
 * @param string                  name           the normalized service name
 * @param string                  requestedName  the requested service name
 * @param Callable                callback       the callback that is responsible for creating the service
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Test_ServiceManager_DelegatorFactoryInterface, createDelegatorWithName);

