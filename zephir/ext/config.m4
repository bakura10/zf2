PHP_ARG_ENABLE(test, whether to enable zend, [ --enable-zend   Enable Zend framework])

if test "$PHP_TEST" = "yes"; then
	AC_DEFINE(HAVE_ZEND, 1, [Whether you have Zend])
	test_sources="zend.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/alternative/fcall.c kernel/operators.c kernel/concat.c zend/servicemanager/servicelocatorinterface.c"
	PHP_NEW_EXTENSION(zend, $zend_sources, $ext_shared)
fi
