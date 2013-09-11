
extern zend_class_entry *zend_servicemanager_servicemanager_ce;

ZEPHIR_INIT_CLASS(Zend_ServiceManager_ServiceManager);

PHP_METHOD(Zend_ServiceManager_ServiceManager, __construct);
PHP_METHOD(Zend_ServiceManager_ServiceManager, addInvokables);
PHP_METHOD(Zend_ServiceManager_ServiceManager, setInvokables);
PHP_METHOD(Zend_ServiceManager_ServiceManager, addFactories);
PHP_METHOD(Zend_ServiceManager_ServiceManager, setFactories);
PHP_METHOD(Zend_ServiceManager_ServiceManager, addAbstractFactories);
PHP_METHOD(Zend_ServiceManager_ServiceManager, setAbstractFactories);
PHP_METHOD(Zend_ServiceManager_ServiceManager, addDelegators);
PHP_METHOD(Zend_ServiceManager_ServiceManager, setDelegators);
PHP_METHOD(Zend_ServiceManager_ServiceManager, addInitializers);
PHP_METHOD(Zend_ServiceManager_ServiceManager, setInitializers);
PHP_METHOD(Zend_ServiceManager_ServiceManager, addAliases);
PHP_METHOD(Zend_ServiceManager_ServiceManager, setAliases);
PHP_METHOD(Zend_ServiceManager_ServiceManager, addShared);
PHP_METHOD(Zend_ServiceManager_ServiceManager, setShared);
PHP_METHOD(Zend_ServiceManager_ServiceManager, setSharedByDefault);
PHP_METHOD(Zend_ServiceManager_ServiceManager, isSharedByDefault);
PHP_METHOD(Zend_ServiceManager_ServiceManager, set);
PHP_METHOD(Zend_ServiceManager_ServiceManager, get);
PHP_METHOD(Zend_ServiceManager_ServiceManager, has);
PHP_METHOD(Zend_ServiceManager_ServiceManager, resolveAlias);
PHP_METHOD(Zend_ServiceManager_ServiceManager, create);
PHP_METHOD(Zend_ServiceManager_ServiceManager, getRegisteredServices);
PHP_METHOD(Zend_ServiceManager_ServiceManager, configureServiceManager);
PHP_METHOD(Zend_ServiceManager_ServiceManager, createFromInvokable);
PHP_METHOD(Zend_ServiceManager_ServiceManager, createFromAbstractFactory);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_addinvokables, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_setinvokables, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_addfactories, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_setfactories, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_addabstractfactories, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_setabstractfactories, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_adddelegators, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_setdelegators, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_addinitializers, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_setinitializers, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_addaliases, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_setaliases, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_addshared, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_setshared, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_setsharedbydefault, 0, 0, 0)
	ZEND_ARG_INFO(0, sharedByDefault)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_set, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, creationOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_has, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, checkAbstractFactories)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_resolvealias, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_create, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, creationOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_configureservicemanager, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_createfrominvokable, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, creationOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_servicemanager_createfromabstractfactory, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, creationOptions)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_servicemanager_servicemanager_method_entry) {
	PHP_ME(Zend_ServiceManager_ServiceManager, __construct, arginfo_zend_servicemanager_servicemanager___construct, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, addInvokables, arginfo_zend_servicemanager_servicemanager_addinvokables, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, setInvokables, arginfo_zend_servicemanager_servicemanager_setinvokables, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, addFactories, arginfo_zend_servicemanager_servicemanager_addfactories, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, setFactories, arginfo_zend_servicemanager_servicemanager_setfactories, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, addAbstractFactories, arginfo_zend_servicemanager_servicemanager_addabstractfactories, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, setAbstractFactories, arginfo_zend_servicemanager_servicemanager_setabstractfactories, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, addDelegators, arginfo_zend_servicemanager_servicemanager_adddelegators, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, setDelegators, arginfo_zend_servicemanager_servicemanager_setdelegators, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, addInitializers, arginfo_zend_servicemanager_servicemanager_addinitializers, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, setInitializers, arginfo_zend_servicemanager_servicemanager_setinitializers, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, addAliases, arginfo_zend_servicemanager_servicemanager_addaliases, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, setAliases, arginfo_zend_servicemanager_servicemanager_setaliases, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, addShared, arginfo_zend_servicemanager_servicemanager_addshared, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, setShared, arginfo_zend_servicemanager_servicemanager_setshared, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, setSharedByDefault, arginfo_zend_servicemanager_servicemanager_setsharedbydefault, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, isSharedByDefault, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, set, arginfo_zend_servicemanager_servicemanager_set, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, get, arginfo_zend_servicemanager_servicemanager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, has, arginfo_zend_servicemanager_servicemanager_has, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, resolveAlias, arginfo_zend_servicemanager_servicemanager_resolvealias, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, create, arginfo_zend_servicemanager_servicemanager_create, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, getRegisteredServices, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zend_ServiceManager_ServiceManager, configureServiceManager, arginfo_zend_servicemanager_servicemanager_configureservicemanager, ZEND_ACC_PROTECTED)
	PHP_ME(Zend_ServiceManager_ServiceManager, createFromInvokable, arginfo_zend_servicemanager_servicemanager_createfrominvokable, ZEND_ACC_PROTECTED)
	PHP_ME(Zend_ServiceManager_ServiceManager, createFromAbstractFactory, arginfo_zend_servicemanager_servicemanager_createfromabstractfactory, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
