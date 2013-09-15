
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2013 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */
/**
 * Service manager is a simple implementation of a service locator
 */
ZEPHIR_INIT_CLASS(Test_ServiceManager_ServiceManager) {

	ZEPHIR_REGISTER_CLASS(Test\\ServiceManager, ServiceManager, test, servicemanager_servicemanager, test_servicemanager_servicemanager_method_entry, 0);

/**
 * List of invokables
 *
 * An invokable is created using the constructor. An invokable must not have
 * any required parameters in its constructor
 *
 * @var array
 */
	zend_declare_property_null(test_servicemanager_servicemanager_ce, SL("invokables"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * List of factories
 *
 * A factory is used to create an object and allows to inject any dependencies
 *
 * @var array|FactoryInterface[]
 */
	zend_declare_property_null(test_servicemanager_servicemanager_ce, SL("factories"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * List of abstract factories
 *
 * An abstract factory is a factory that is run if neither invokables or factories
 * is found for a given object
 *
 * @var array|AbstractFactoryInterface[]
 */
	zend_declare_property_null(test_servicemanager_servicemanager_ce, SL("abstractFactories"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * List of delegators
 *
 * A delegator allows to delegate the creation of an instance to another factory
 *
 * @var array|DelegatorFactoryInterface[]
 */
	zend_declare_property_null(test_servicemanager_servicemanager_ce, SL("delegators"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * List of initializers
 *
 * An initializer is run for every object that is created by the service manager
 * in order to inject any other dependencies
 *
 * @var array|InitializerInterface[]
 */
	zend_declare_property_null(test_servicemanager_servicemanager_ce, SL("initializers"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * List of aliases
 *
 * An alias is simply a key to map to another existing key
 *
 * @var array
 */
	zend_declare_property_null(test_servicemanager_servicemanager_ce, SL("aliases"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * List of shared
 *
 * Define an array of key => boolean in order to specify if the service should
 * be shared or not
 *
 * @var array
 */
	zend_declare_property_null(test_servicemanager_servicemanager_ce, SL("shared"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Set if the instances are shared by default in this service manager
 *
 * @var bool
 */
	zend_declare_property_bool(test_servicemanager_servicemanager_ce, SL("sharedByDefault"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * List of already created instances
 *
 * @var array
 */
	zend_declare_property_null(test_servicemanager_servicemanager_ce, SL("instances"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param ServiceManagerConfig config
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, __construct) {

	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		ZEPHIR_CPY_WRT(config, ZEPHIR_GLOBAL(global_null));
	}


	if (zend_is_true(config)) {
		zephir_call_method_p1_noret(this_ptr, "configureservicemanager", config);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Add invokables
 *
 * @param  array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, addInvokables) {

	zval *config, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("invokables"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("invokables"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set invokables (overriding old ones)
 *
 * @param array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, setInvokables) {

	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("invokables"), _0 TSRMLS_CC);
	zephir_call_method_p1_noret(this_ptr, "setinvokables", config);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add factories
 *
 * @param  array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, addFactories) {

	zval *config, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("factories"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("factories"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set factories (overriding old ones)
 *
 * @param array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, setFactories) {

	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("factories"), _0 TSRMLS_CC);
	zephir_call_method_p1_noret(this_ptr, "addfactories", config);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add abstract factories
 *
 * @param  array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, addAbstractFactories) {

	zend_class_entry *_3;
	HashTable *_1;
	HashPosition _0;
	zval *config, *abstractFactory = NULL, *abstractFactories, **_2, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(abstractFactories);
	array_init(abstractFactories);
	zephir_is_iterable(config, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(abstractFactory, _2);
		if (Z_TYPE_P(name) == IS_STRING) {
			ZEPHIR_INIT_NVAR(abstractFactory);
			_3 = zend_fetch_class(SL("name"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(abstractFactory, _3);
		}
		zephir_array_append(&abstractFactories, abstractFactory, PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_this(&_5, this_ptr, SL("abstractFactories"), PH_NOISY_CC);
	zephir_fast_array_merge(_4, &(_5), &(abstractFactories) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("abstractFactories"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set abstract factories (overriding old ones)
 *
 * @param  array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, setAbstractFactories) {

	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("abstractFactories"), _0 TSRMLS_CC);
	zephir_call_method_p1_noret(this_ptr, "addabstractfactories", config);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add delegators
 *
 * @param  array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, addDelegators) {

	zval *config, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("delegators"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("delegators"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set delegators (overriding old ones)
 *
 * @param array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, setDelegators) {

	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("delegators"), _0 TSRMLS_CC);
	zephir_call_method_p1_noret(this_ptr, "adddelegators", config);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add initializers
 *
 * @param  array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, addInitializers) {

	zend_class_entry *_3;
	HashTable *_1;
	HashPosition _0;
	zval *config, *initializer = NULL, *initializers, **_2, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(initializers);
	array_init(initializers);
	zephir_is_iterable(config, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(initializer, _2);
		if (Z_TYPE_P(name) == IS_STRING) {
			ZEPHIR_INIT_NVAR(initializer);
			_3 = zend_fetch_class(SL("name"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(initializer, _3);
		}
		zephir_array_append(&initializers, initializer, PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_this(&_5, this_ptr, SL("initializers"), PH_NOISY_CC);
	zephir_fast_array_merge(_4, &(_5), &(initializers) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("initializers"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set initializers (overriding old ones)
 *
 * @param array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, setInitializers) {

	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("initializers"), _0 TSRMLS_CC);
	zephir_call_method_p1_noret(this_ptr, "addinitializers", config);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add aliases
 *
 * @param  array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, addAliases) {

	zval *config, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("aliases"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("aliases"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set aliases (overriding old ones)
 *
 * @param array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, setAliases) {

	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("aliases"), _0 TSRMLS_CC);
	zephir_call_method_p1_noret(this_ptr, "addaliases", config);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add shared objects
 *
 * @param  array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, addShared) {

	zval *config, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("shared"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("shared"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set shared objects (overriding old ones)
 *
 * @param array config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, setShared) {

	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("shared"), _0 TSRMLS_CC);
	zephir_call_method_p1_noret(this_ptr, "addshared", config);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set if instances are shared by default
 *
 * @param  bool sharedByDefault
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, setSharedByDefault) {

	zval *sharedByDefault, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sharedByDefault);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, zephir_get_boolval(sharedByDefault));
	zephir_update_property_this(this_ptr, SL("sharedByDefault"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get if this service manager is configured so that instances are shared by default
 *
 * @return bool
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, isSharedByDefault) {


	RETURN_MEMBER(this_ptr, "sharedByDefault");

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, set) {

	zval *name, *instance;

	zephir_fetch_params(0, 2, 0, &name, &instance);



	zephir_update_property_array(this_ptr, SL("instances"), name, instance TSRMLS_CC);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, get) {

	zend_bool shared;
	zval *name = NULL, *creationOptions = NULL, *sharedInstances, *instances, *instance, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &creationOptions);

	ZEPHIR_SEPARATE_PARAM(name);
	if (!creationOptions) {
		ZEPHIR_CPY_WRT(creationOptions, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "resolvealias", name);
	ZEPHIR_CPY_WRT(name, _0);
	ZEPHIR_OBS_VAR(sharedInstances);
	zephir_read_property_this(&sharedInstances, this_ptr, SL("shared"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(shared);
	if (!(zephir_array_isset_fetch(&shared, sharedInstances, name))) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("sharedByDefault"), PH_NOISY_CC);
		shared = (zephir_get_boolval(_1)) ? 1 : 0;
	}
	ZEPHIR_OBS_VAR(instances);
	zephir_read_property_this(&instances, this_ptr, SL("instances"), PH_NOISY_CC);
	if ((shared && zephir_array_isset(instances, name))) {
		zephir_array_fetch(&return_value, instances, name, PH_NOISY);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(instance);
	zephir_call_method_p2(instance, this_ptr, "create", name, creationOptions);
	if (shared) {
		zephir_update_property_array(this_ptr, SL("instances"), name, instance TSRMLS_CC);
	}
	RETURN_CCTOR(instance);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, has) {

	HashTable *_2;
	HashPosition _1;
	zend_bool found;
	zval *name = NULL, *checkAbstractFactories = NULL, *invokables, *factories, *instances, *_0 = NULL, *abstractFactory = NULL, *abstractFactories, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &checkAbstractFactories);

	ZEPHIR_SEPARATE_PARAM(name);
	if (!checkAbstractFactories) {
		ZEPHIR_CPY_WRT(checkAbstractFactories, ZEPHIR_GLOBAL(global_true));
	}


	ZEPHIR_OBS_VAR(invokables);
	zephir_read_property_this(&invokables, this_ptr, SL("invokables"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(factories);
	zephir_read_property_this(&factories, this_ptr, SL("factories"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(instances);
	zephir_read_property_this(&instances, this_ptr, SL("instances"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "resolvealias", name);
	ZEPHIR_CPY_WRT(name, _0);
	found = ((zephir_array_isset(invokables, name) || zephir_array_isset(factories, name)) || zephir_array_isset(instances, name));
	if ((found || ZEPHIR_IS_FALSE(checkAbstractFactories))) {
		RETURN_MM_BOOL(found);
	}
	ZEPHIR_OBS_VAR(abstractFactories);
	zephir_read_property_this(&abstractFactories, this_ptr, SL("abstractFactories"), PH_NOISY_CC);
	zephir_is_iterable(abstractFactories, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(abstractFactory, _3);
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_method_p2(_0, abstractFactory, "cancreateservicewithname", this_ptr, name);
		if (zend_is_true(_0)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Resolve an alias
 *
 * @param  string name
 * @return string
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, resolveAlias) {

	zval *name = NULL, *aliases;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);

	ZEPHIR_SEPARATE_PARAM(name);


	ZEPHIR_OBS_VAR(aliases);
	zephir_read_property_this(&aliases, this_ptr, SL("aliases"), PH_NOISY_CC);
	while (1) {
		if (!(zephir_array_isset(aliases, name))) {
			break;
		}
		ZEPHIR_OBS_NVAR(name);
		zephir_array_fetch(&name, aliases, name, PH_NOISY);
	}
	RETURN_CCTOR(name);

}

/**
 * Create a new instance
 *
 * This will always return a new instance, even if it has already been created (for most cases, you
 * should use "get" method). Note that this method does not work with aliases, it expects the name
 * to be already resolved
 *
 * @param  string name
 * @param  array  creationOptions
 * @return mixed
 * @throws Exception\ServiceNotFoundException
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, create) {

	HashTable *_4;
	HashPosition _3;
	zval *name, *creationOptions = NULL, *instance, *invokables, *factories, *initializers, *_0, _1, *_2, *initializer = NULL, **_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &creationOptions);

	if (!creationOptions) {
		ZEPHIR_CPY_WRT(creationOptions, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(instance);
	ZVAL_NULL(instance);
	ZEPHIR_OBS_VAR(invokables);
	zephir_read_property_this(&invokables, this_ptr, SL("invokables"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(factories);
	zephir_read_property_this(&factories, this_ptr, SL("factories"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(initializers);
	zephir_read_property_this(&initializers, this_ptr, SL("initializers"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(instance);
	if (zephir_array_isset(invokables, name)) {
		zephir_call_method_p2(instance, this_ptr, "createfrominvokable", name, creationOptions);
	} else {
		zephir_call_method_p2(instance, this_ptr, "createfromabstractfactory", name, creationOptions);
	}
	if (!(zend_is_true(instance))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, test_servicemanager_exception_servicenotfoundexception_ce);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "No invokable, factory or abstract factory were found for creating \\"%s\\"", 0);
		ZEPHIR_INIT_VAR(_2);
		zephir_call_func_p2(_2, "sprintf", &_1, name);
		zephir_call_method_p1_noret(_0, "__construct", _2);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(initializers, &_4, &_3, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(initializer, _5);
		if (zephir_is_callable(initializer TSRMLS_CC)) {
			//missing fcall
		}
	}
	RETURN_CCTOR(instance);

}

/**
 * Retrieve a keyed list of all registered services. Handy for debugging!
 *
 * @return array
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, getRegisteredServices) {

	zval *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();

	array_init(return_value);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("invokables"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "array_keys", _0);
	zephir_array_update_string(&return_value, SL("invokables"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("factories"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p1(_1, "array_keys", _2);
	zephir_array_update_string(&return_value, SL("factories"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("aliases"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p1(_1, "array_keys", _3);
	zephir_array_update_string(&return_value, SL("aliases"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("instances"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p1(_1, "array_keys", _4);
	zephir_array_update_string(&return_value, SL("instances"), &_1, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Configure the service manager
 *
 * @param  ServiceManagerConfig config
 * @return void
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, configureServiceManager) {

	zval *config, *_0, *_1, *_2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, config, "getinvokablesconfig");
	zephir_call_method_p1_noret(this_ptr, "addinvokables", _0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, config, "getfactoriesconfig");
	zephir_call_method_p1_noret(this_ptr, "addfactories", _1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_method(_2, config, "getabstractfactoriesconfig");
	zephir_call_method_p1_noret(this_ptr, "addabstractfactories", _2);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_method(_3, config, "getdelegatorsconfig");
	zephir_call_method_p1_noret(this_ptr, "adddelegators", _3);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_method(_4, config, "getinitializersconfig");
	zephir_call_method_p1_noret(this_ptr, "addinitializers", _4);
	ZEPHIR_INIT_VAR(_5);
	zephir_call_method(_5, config, "getaliasesconfig");
	zephir_call_method_p1_noret(this_ptr, "addaliases", _5);
	ZEPHIR_INIT_VAR(_6);
	zephir_call_method(_6, config, "getsharedconfig");
	zephir_call_method_p1_noret(this_ptr, "addshared", _6);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create an object from the invokable
 *
 * @param string name
 * @param array  creationOptions
 * @return mixed
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, createFromInvokable) {

	zend_class_entry *_0;
	zval *name, *creationOptions = NULL, *invokables, *invokableClass;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &creationOptions);

	if (!creationOptions) {
		ZEPHIR_CPY_WRT(creationOptions, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_OBS_VAR(invokables);
	zephir_read_property_this(&invokables, this_ptr, SL("invokables"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(invokableClass);
	zephir_array_fetch(&invokableClass, invokables, name, PH_NOISY);
	_0 = zend_fetch_class(SL("invokableClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _0);
	RETURN_MM();

}

/**
 * Create an object from the factory
 *
 * @param  string name
 * @param  array  creationOptions
 * @return mixed
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, createFromFactory) {

	zend_class_entry *_1;
	zval *name, *creationOptions = NULL, *factories, *factory, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &creationOptions);

	if (!creationOptions) {
		ZEPHIR_CPY_WRT(creationOptions, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_OBS_VAR(factories);
	zephir_read_property_this(&factories, this_ptr, SL("factories"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(factory);
	zephir_array_fetch(&factory, factories, name, PH_NOISY);
	if (Z_TYPE_P(factory) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zend_fetch_class(SL("factory"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_0, _1);
		zephir_update_property_array(this_ptr, SL("factories"), name, _0 TSRMLS_CC);
	}
	if (zephir_is_callable(factory TSRMLS_CC)) {
		zephir_call_func_p2(return_value, "factory", this_ptr, creationOptions);
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Create an object from the abstract factory
 *
 * @param  string name
 * @param  array  creationOptions
 * @return mixed
 */
PHP_METHOD(Test_ServiceManager_ServiceManager, createFromAbstractFactory) {

	HashTable *_1;
	HashPosition _0;
	zval *name, *creationOptions = NULL, *abstractFactories, *abstractFactory = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &creationOptions);

	if (!creationOptions) {
		ZEPHIR_CPY_WRT(creationOptions, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_OBS_VAR(abstractFactories);
	zephir_read_property_this(&abstractFactories, this_ptr, SL("abstractFactories"), PH_NOISY_CC);
	zephir_is_iterable(abstractFactories, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(abstractFactory, _2);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method_p2(_3, abstractFactory, "cancreateservicewithname", this_ptr, name);
		if (zend_is_true(_3)) {
			zephir_call_method_p3(return_value, abstractFactory, "createservicewithname", this_ptr, name, creationOptions);
			RETURN_MM();
		}
	}
	RETURN_MM_NULL();

}

