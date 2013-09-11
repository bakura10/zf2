
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_zend.h"
#include "zend.h"

#include "ext/standard/info.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

zend_class_entry *zend_servicemanager_servicelocatorinterface_ce;

ZEND_DECLARE_MODULE_GLOBALS(zend)

PHP_MINIT_FUNCTION(zend){

	ZEPHIR_INIT(Zend_ServiceManager_ServiceLocatorInterface);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(zend){

	assert(ZEPHIR_GLOBAL(function_cache) == NULL);
	//assert(ZEPHIR_GLOBAL(orm).parser_cache == NULL);
	//assert(ZEPHIR_GLOBAL(orm).ast_cache == NULL);

	return SUCCESS;
}
#endif

static PHP_RINIT_FUNCTION(zend){

	php_zephir_init_globals(ZEPHIR_VGLOBAL TSRMLS_CC);
	//zend_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(zend){

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

static PHP_MINFO_FUNCTION(zend)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "Version", PHP_ZEND_VERSION);
	php_info_print_table_end();
}

static PHP_GINIT_FUNCTION(zend)
{
	zephir_memory_entry *start;

	php_zephir_init_globals(zend_globals TSRMLS_CC);

	/* Start Memory Frame */
	start = (zephir_memory_entry *) pecalloc(1, sizeof(zephir_memory_entry), 1);
	start->addresses       = pecalloc(24, sizeof(zval*), 1);
	start->capacity        = 24;
	start->hash_addresses  = pecalloc(8, sizeof(zval*), 1);
	start->hash_capacity   = 8;

	zend_globals->start_memory = start;

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

static PHP_GSHUTDOWN_FUNCTION(zend)
{
	assert(zend_globals->start_memory != NULL);

	pefree(zend_globals->start_memory->hash_addresses, 1);
	pefree(zend_globals->start_memory->addresses, 1);
	pefree(zend_globals->start_memory, 1);
	zend_globals->start_memory = NULL;
}

zend_module_entry zend_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_ZEND_EXTNAME,
	NULL,
	PHP_MINIT(zend),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(zend),
#else
	NULL,
#endif
	PHP_RINIT(zend),
	PHP_RSHUTDOWN(zend),
	PHP_MINFO(zend),
	PHP_ZEND_VERSION,
	ZEND_MODULE_GLOBALS(zend),
	PHP_GINIT(zend),
	PHP_GSHUTDOWN(zend),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_ZEND
ZEND_GET_MODULE(zend)
#endif
