
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"


/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */
/**
 * Simple object that wrap a configuration for a service manager
 */
ZEPHIR_INIT_CLASS(Zend_ServiceManager_ServiceManagerConfig) {

	ZEPHIR_REGISTER_CLASS(Zend\\ServiceManager, ServiceManagerConfig, zend, servicemanager_servicemanagerconfig, zend_servicemanager_servicemanagerconfig_method_entry, 0);

/**
 * @var array
 */
	zend_declare_property_null(zend_servicemanager_servicemanagerconfig_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param array config
 */
PHP_METHOD(Zend_ServiceManager_ServiceManagerConfig, __construct) {

	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		ZEPHIR_CPY_WRT(config, ZEPHIR_GLOBAL(global_null));
	}


	zephir_update_property_this(this_ptr, SL("config"), config TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get invokables configuration
 *
 * @return array
 */
PHP_METHOD(Zend_ServiceManager_ServiceManagerConfig, getInvokablesConfig) {

	zval *config, *invokablesConfig;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(invokablesConfig);
	if (zephir_array_isset_string_fetch(&invokablesConfig, config, SS("invokables"))) {
		RETURN_CCTOR(invokablesConfig);
	}
	RETURN_MM_NULL();

}

/**
 * Get factories configuration
 *
 * @return array
 */
PHP_METHOD(Zend_ServiceManager_ServiceManagerConfig, getFactoriesConfig) {

	zval *config, *factoriesConfig;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(factoriesConfig);
	if (zephir_array_isset_string_fetch(&factoriesConfig, config, SS("factories"))) {
		RETURN_CCTOR(factoriesConfig);
	}
	RETURN_MM_NULL();

}

/**
 * Get abstract factories configuration
 *
 * @return array
 */
PHP_METHOD(Zend_ServiceManager_ServiceManagerConfig, getAbstractFactoriesConfig) {

	zval *config, *abstractFactoriesConfig;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(abstractFactoriesConfig);
	if (zephir_array_isset_string_fetch(&abstractFactoriesConfig, config, SS("abstract_factories"))) {
		RETURN_CCTOR(abstractFactoriesConfig);
	}
	RETURN_MM_NULL();

}

/**
 * Get the delegators factories configuration
 *
 * @return array
 */
PHP_METHOD(Zend_ServiceManager_ServiceManagerConfig, getDelegatorsConfig) {

	zval *config, *delegatorsConfig;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(delegatorsConfig);
	if (zephir_array_isset_string_fetch(&delegatorsConfig, config, SS("delegators"))) {
		RETURN_CCTOR(delegatorsConfig);
	}
	RETURN_MM_NULL();

}

/**
 * Get initializers configuration
 *
 * @return array
 */
PHP_METHOD(Zend_ServiceManager_ServiceManagerConfig, getInitializersConfig) {

	zval *config, *initializersConfig;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(initializersConfig);
	if (zephir_array_isset_string_fetch(&initializersConfig, config, SS("initializers"))) {
		RETURN_CCTOR(initializersConfig);
	}
	RETURN_MM_NULL();

}

/**
 * Get aliases configuration
 *
 * @return array
 */
PHP_METHOD(Zend_ServiceManager_ServiceManagerConfig, getAliasesConfig) {

	zval *config, *aliasesConfig;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(aliasesConfig);
	if (zephir_array_isset_string_fetch(&aliasesConfig, config, SS("aliases"))) {
		RETURN_CCTOR(aliasesConfig);
	}
	RETURN_MM_NULL();

}

/**
 * Get shard configuration
 *
 * @return array
 */
PHP_METHOD(Zend_ServiceManager_ServiceManagerConfig, getSharedConfig) {

	zval *config, *sharedConfig;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(sharedConfig);
	if (zephir_array_isset_string_fetch(&sharedConfig, config, SS("shared"))) {
		RETURN_CCTOR(sharedConfig);
	}
	RETURN_MM_NULL();

}

