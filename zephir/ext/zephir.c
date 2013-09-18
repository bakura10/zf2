
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "php_ext.h"
#include "zephir.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"

zend_class_entry *zephir_servicemanager_abstractfactoryinterface_ce;
zend_class_entry *zephir_servicemanager_delegatorfactoryinterface_ce;
zend_class_entry *zephir_servicemanager_exception_exceptioninterface_ce;
zend_class_entry *zephir_servicemanager_factoryinterface_ce;
zend_class_entry *zephir_servicemanager_initializerinterface_ce;
zend_class_entry *zephir_servicemanager_servicelocatorinterface_ce;
zend_class_entry *zephir_servicemanager_exception_invalidargumentexception_ce;
zend_class_entry *zephir_servicemanager_exception_runtimeexception_ce;
zend_class_entry *zephir_servicemanager_exception_servicenotfoundexception_ce;
zend_class_entry *zephir_servicemanager_servicemanager_ce;
zend_class_entry *zephir_servicemanager_servicemanagerconfig_ce;

ZEND_DECLARE_MODULE_GLOBALS(zephir)

PHP_MINIT_FUNCTION(zephir){

	ZEPHIR_INIT(Zephir_ServiceManager_AbstractFactoryInterface);
	ZEPHIR_INIT(Zephir_ServiceManager_DelegatorFactoryInterface);
	ZEPHIR_INIT(Zephir_ServiceManager_Exception_ExceptionInterface);
	ZEPHIR_INIT(Zephir_ServiceManager_FactoryInterface);
	ZEPHIR_INIT(Zephir_ServiceManager_InitializerInterface);
	ZEPHIR_INIT(Zephir_ServiceManager_ServiceLocatorInterface);
	ZEPHIR_INIT(Zephir_ServiceManager_Exception_InvalidArgumentException);
	ZEPHIR_INIT(Zephir_ServiceManager_Exception_RuntimeException);
	ZEPHIR_INIT(Zephir_ServiceManager_Exception_ServiceNotFoundException);
	ZEPHIR_INIT(Zephir_ServiceManager_ServiceManager);
	ZEPHIR_INIT(Zephir_ServiceManager_ServiceManagerConfig);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(zephir){

	assert(ZEPHIR_GLOBAL(function_cache) == NULL);
	//assert(ZEPHIR_GLOBAL(orm).parser_cache == NULL);
	//assert(ZEPHIR_GLOBAL(orm).ast_cache == NULL);

	return SUCCESS;
}
#endif

static PHP_RINIT_FUNCTION(zephir){

	php_zephir_init_globals(ZEPHIR_VGLOBAL TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(zephir){

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

static PHP_MINFO_FUNCTION(zephir)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "Version", PHP_ZEPHIR_VERSION);
	php_info_print_table_end();
}

static PHP_GINIT_FUNCTION(zephir)
{
	zephir_memory_entry *start;

	php_zephir_init_globals(zephir_globals TSRMLS_CC);

	/* Start Memory Frame */
	start = (zephir_memory_entry *) pecalloc(1, sizeof(zephir_memory_entry), 1);
	start->addresses       = pecalloc(24, sizeof(zval*), 1);
	start->capacity        = 24;
	start->hash_addresses  = pecalloc(8, sizeof(zval*), 1);
	start->hash_capacity   = 8;

	zephir_globals->start_memory = start;

	/* Global Constants */
	ALLOC_PERMANENT_ZVAL(zephir_globals->global_false);
	INIT_PZVAL(zephir_globals->global_false);
	ZVAL_FALSE(zephir_globals->global_false);
	Z_ADDREF_P(zephir_globals->global_false);

	ALLOC_PERMANENT_ZVAL(zephir_globals->global_true);
	INIT_PZVAL(zephir_globals->global_true);
	ZVAL_TRUE(zephir_globals->global_true);
	Z_ADDREF_P(zephir_globals->global_true);

	ALLOC_PERMANENT_ZVAL(zephir_globals->global_null);
	INIT_PZVAL(zephir_globals->global_null);
	ZVAL_NULL(zephir_globals->global_null);
	Z_ADDREF_P(zephir_globals->global_null);
}

static PHP_GSHUTDOWN_FUNCTION(zephir)
{
	assert(zephir_globals->start_memory != NULL);

	pefree(zephir_globals->start_memory->hash_addresses, 1);
	pefree(zephir_globals->start_memory->addresses, 1);
	pefree(zephir_globals->start_memory, 1);
	zephir_globals->start_memory = NULL;
}

zend_module_entry zephir_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_ZEPHIR_EXTNAME,
	NULL,
	PHP_MINIT(zephir),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(zephir),
#else
	NULL,
#endif
	PHP_RINIT(zephir),
	PHP_RSHUTDOWN(zephir),
	PHP_MINFO(zephir),
	PHP_ZEPHIR_VERSION,
	ZEND_MODULE_GLOBALS(zephir),
	PHP_GINIT(zephir),
	PHP_GSHUTDOWN(zephir),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_ZEPHIR
ZEND_GET_MODULE(zephir)
#endif
