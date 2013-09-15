PHP_ARG_ENABLE(test, whether to enable test, [ --enable-test   Enable Test framework])

if test "$PHP_TEST" = "yes"; then
	AC_DEFINE(HAVE_TEST, 1, [Whether you have Test])
	test_sources="test.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/alternative/fcall.c kernel/operators.c kernel/concat.c test/servicemanager/abstractfactoryinterface.c test/servicemanager/delegatorfactoryinterface.c test/servicemanager/exception/exceptioninterface.c test/servicemanager/exception/invalidargumentexception.c test/servicemanager/exception/runtimeexception.c test/servicemanager/exception/servicenotfoundexception.c test/servicemanager/factoryinterface.c test/servicemanager/initializerinterface.c test/servicemanager/servicelocatorinterface.c test/servicemanager/servicemanager.c test/servicemanager/servicemanagerconfig.c"
	PHP_NEW_EXTENSION(test, $test_sources, $ext_shared)
fi
