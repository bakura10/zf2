
#ifndef PHP_ZEPHIR_H
#define PHP_ZEPHIR_H 1

#include "kernel/globals.h"

#define PHP_ZEPHIR_VERSION "0.0.1"
#define PHP_ZEPHIR_EXTNAME "zephir"

ZEND_BEGIN_MODULE_GLOBALS(zephir)

	/* Memory */
	zephir_memory_entry *start_memory;
	zephir_memory_entry *active_memory;

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/* Function cache */
	HashTable *function_cache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;

ZEND_END_MODULE_GLOBALS(zephir)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(zephir)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(zephir_globals_id, zend_zephir_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (zephir_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_zephir_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(zephir_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(zephir_globals)
#endif

#define zephir_globals zephir_globals
#define zend_zephir_globals zend_zephir_globals

extern zend_module_entry zephir_module_entry;
#define phpext_zephir_ptr &zephir_module_entry

#endif
