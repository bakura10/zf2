
extern zend_class_entry *zend_servicemanager_delegatorfactoryinterface_ce;

ZEPHIR_INIT_CLASS(Zend_ServiceManager_DelegatorFactoryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zend_servicemanager_delegatorfactoryinterface_createdelegatorwithname, 0, 0, 0)
	ZEND_ARG_INFO(0, serviceLocator)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, requestedName)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zend_servicemanager_delegatorfactoryinterface_method_entry) {
	PHP_ABSTRACT_ME(Zend_ServiceManager_DelegatorFactoryInterface, createDelegatorWithName, arginfo_zend_servicemanager_delegatorfactoryinterface_createdelegatorwithname)
	PHP_FE_END
};
