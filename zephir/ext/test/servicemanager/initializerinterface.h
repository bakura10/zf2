
extern zend_class_entry *test_servicemanager_initializerinterface_ce;

ZEPHIR_INIT_CLASS(Test_ServiceManager_InitializerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_servicemanager_initializerinterface_initialize, 0, 0, 0)
	ZEND_ARG_INFO(0, instance)
	ZEND_ARG_INFO(0, serviceLocator)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(test_servicemanager_initializerinterface_method_entry) {
	PHP_ABSTRACT_ME(Test_ServiceManager_InitializerInterface, initialize, arginfo_test_servicemanager_initializerinterface_initialize)
	PHP_FE_END
};
