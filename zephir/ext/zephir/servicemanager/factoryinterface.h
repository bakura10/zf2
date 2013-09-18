
extern zend_class_entry *zephir_servicemanager_factoryinterface_ce;

ZEPHIR_INIT_CLASS(Zephir_ServiceManager_FactoryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephir_servicemanager_factoryinterface_createservice, 0, 0, 0)
	ZEND_ARG_INFO(0, serviceLocator)
	ZEND_ARG_INFO(0, creationOptions)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zephir_servicemanager_factoryinterface_method_entry) {
	PHP_ABSTRACT_ME(Zephir_ServiceManager_FactoryInterface, createService, arginfo_zephir_servicemanager_factoryinterface_createservice)
	PHP_FE_END
};
