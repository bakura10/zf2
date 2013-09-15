
extern zend_class_entry *test_servicemanager_servicelocatorinterface_ce;

ZEPHIR_INIT_CLASS(Test_ServiceManager_ServiceLocatorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_servicemanager_servicelocatorinterface_set, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_servicemanager_servicelocatorinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, creationOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_test_servicemanager_servicelocatorinterface_has, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(test_servicemanager_servicelocatorinterface_method_entry) {
	PHP_ABSTRACT_ME(Test_ServiceManager_ServiceLocatorInterface, set, arginfo_test_servicemanager_servicelocatorinterface_set)
	PHP_ABSTRACT_ME(Test_ServiceManager_ServiceLocatorInterface, get, arginfo_test_servicemanager_servicelocatorinterface_get)
	PHP_ABSTRACT_ME(Test_ServiceManager_ServiceLocatorInterface, has, arginfo_test_servicemanager_servicelocatorinterface_has)
	PHP_FE_END
};
