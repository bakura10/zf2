
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "ext/standard/info.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

zend_class_entry *test_servicemanager_abstractfactoryinterface_ce;
zend_class_entry *test_servicemanager_delegatorfactoryinterface_ce;
zend_class_entry *test_servicemanager_exception_exceptioninterface_ce;
zend_class_entry *test_servicemanager_factoryinterface_ce;
zend_class_entry *test_servicemanager_initializerinterface_ce;
zend_class_entry *test_servicemanager_servicelocatorinterface_ce;
zend_class_entry *test_servicemanager_exception_invalidargumentexception_ce;
zend_class_entry *test_servicemanager_exception_runtimeexception_ce;
zend_class_entry *test_servicemanager_exception_servicenotfoundexception_ce;
zend_class_entry *test_servicemanager_servicemanager_ce;
zend_class_entry *test_servicemanager_servicemanagerconfig_ce;

ZEND_DECLARE_MODULE_GLOBALS(test)

PHP_MINIT_FUNCTION(test){

	ZEPHIR_INIT(Test_ServiceManager_AbstractFactoryInterface);
	ZEPHIR_INIT(Test_ServiceManager_DelegatorFactoryInterface);
	ZEPHIR_INIT(Test_ServiceManager_Exception_ExceptionInterface);
	ZEPHIR_INIT(Test_ServiceManager_FactoryInterface);
	ZEPHIR_INIT(Test_ServiceManager_InitializerInterface);
	ZEPHIR_INIT(Test_ServiceManager_ServiceLocatorInterface);
	ZEPHIR_INIT(Test_ServiceManager_Exception_InvalidArgumentException);
	ZEPHIR_INIT(Test_ServiceManager_Exception_RuntimeException);
	ZEPHIR_INIT(Test_ServiceManager_Exception_ServiceNotFoundException);
	ZEPHIR_INIT(Test_ServiceManager_ServiceManager);
	ZEPHIR_INIT(Test_ServiceManager_ServiceManagerConfig);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(test){

	assert(ZEPHIR_GLOBAL(function_cache) == NULL);
	//assert(ZEPHIR_GLOBAL(orm).parser_cache == NULL);
	//assert(ZEPHIR_GLOBAL(orm).ast_cache == NULL);

	return SUCCESS;
}
#endif

static PHP_RINIT_FUNCTION(test){

	php_zephir_init_globals(ZEPHIR_VGLOBAL TSRMLS_CC);
	//test_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(test){

	if (ZEPHIR_GLOBAL(start_memory) != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	if (ZEPHIR_GLOBAL(function_cache) != NULL) {
		zend_hash_destroy(ZEPHIR_GLOBAL(function_cache));
		FREE_HASHTABLE(ZEPHIR_GLOBAL(function_cache));
		ZEPHIR_GLOBAL(function_cache) = NULL;
	}

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(test)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "Version", PHP_TEST_VERSION);
	php_info_print_table_end();
}

static PHP_GINIT_FUNCTION(test)
{
	zephir_memory_entry *start;

	php_zephir_init_globals(test_globals TSRMLS_CC);

	/* Start Memory Frame */
	start = (zephir_memory_entry *) pecalloc(1, sizeof(zephir_memory_entry), 1);
	start->addresses       = pecalloc(24, sizeof(zval*), 1);
	start->capacity        = 24;
	start->hash_addresses  = pecalloc(8, sizeof(zval*), 1);
	start->hash_capacity   = 8;

	test_globals->start_memory = start;

	/* Global Constants */
	ALLOC_PERMANENT_ZVAL(test_globals->global_false);
	INIT_PZVAL(test_globals->global_false);
	ZVAL_FALSE(test_globals->global_false);
	Z_ADDREF_P(test_globals->global_false);

	ALLOC_PERMANENT_ZVAL(test_globals->global_true);
	INIT_PZVAL(test_globals->global_true);
	ZVAL_TRUE(test_globals->global_true);
	Z_ADDREF_P(test_globals->global_true);

	ALLOC_PERMANENT_ZVAL(test_globals->global_null);
	INIT_PZVAL(test_globals->global_null);
	ZVAL_NULL(test_globals->global_null);
	Z_ADDREF_P(test_globals->global_null);
}

static PHP_GSHUTDOWN_FUNCTION(test)
{
	assert(test_globals->start_memory != NULL);

	pefree(test_globals->start_memory->hash_addresses, 1);
	pefree(test_globals->start_memory->addresses, 1);
	pefree(test_globals->start_memory, 1);
	test_globals->start_memory = NULL;
}

zend_module_entry test_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_TEST_EXTNAME,
	NULL,
	PHP_MINIT(test),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(test),
#else
	NULL,
#endif
	PHP_RINIT(test),
	PHP_RSHUTDOWN(test),
	PHP_MINFO(test),
	PHP_TEST_VERSION,
	ZEND_MODULE_GLOBALS(test),
	PHP_GINIT(test),
	PHP_GSHUTDOWN(test),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_TEST
ZEND_GET_MODULE(test)
#endif
