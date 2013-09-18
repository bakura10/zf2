PHP_ARG_ENABLE(zephir, whether to enable zephir, [ --enable-zephir   Enable Zephir framework])

if test "$PHP_ZEPHIR" = "yes"; then
	AC_DEFINE(HAVE_ZEPHIR, 1, [Whether you have Zephir])
	zephir_sources="zephir.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/alternative/fcall.c kernel/operators.c kernel/concat.c zephir/servicemanager/abstractfactoryinterface.c zephir/servicemanager/delegatorfactoryinterface.c zephir/servicemanager/exception/exceptioninterface.c zephir/servicemanager/exception/invalidargumentexception.c zephir/servicemanager/exception/runtimeexception.c zephir/servicemanager/exception/servicenotfoundexception.c zephir/servicemanager/factoryinterface.c zephir/servicemanager/initializerinterface.c zephir/servicemanager/servicelocatorinterface.c zephir/servicemanager/servicemanager.c zephir/servicemanager/servicemanagerconfig.c"
	PHP_NEW_EXTENSION(zephir, $zephir_sources, $ext_shared)
fi
