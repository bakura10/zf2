srcdir = /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext
builddir = /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext
top_srcdir = /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext
top_builddir = /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext
EGREP = /usr/bin/grep -E
SED = /usr/bin/sed
CONFIGURE_COMMAND = './configure' '--enable-test'
CONFIGURE_OPTIONS = '--enable-test'
SHLIB_SUFFIX_NAME = dylib
SHLIB_DL_SUFFIX_NAME = so
ZEND_EXT_TYPE = zend_extension
RE2C = re2c
AWK = awk
shared_objects_test = test.lo kernel/main.lo kernel/memory.lo kernel/exception.lo kernel/hash.lo kernel/debug.lo kernel/backtrace.lo kernel/object.lo kernel/array.lo kernel/string.lo kernel/fcall.lo kernel/alternative/fcall.lo kernel/operators.lo kernel/concat.lo test/servicemanager/abstractfactoryinterface.lo test/servicemanager/delegatorfactoryinterface.lo test/servicemanager/exception/exceptioninterface.lo test/servicemanager/exception/invalidargumentexception.lo test/servicemanager/exception/runtimeexception.lo test/servicemanager/exception/servicenotfoundexception.lo test/servicemanager/factoryinterface.lo test/servicemanager/initializerinterface.lo test/servicemanager/servicelocatorinterface.lo test/servicemanager/servicemanager.lo test/servicemanager/servicemanagerconfig.lo
PHP_PECL_EXTENSION = test
PHP_MODULES = $(phplibdir)/test.la
PHP_ZEND_EX =
all_targets = $(PHP_MODULES) $(PHP_ZEND_EX)
install_targets = install-modules install-headers
prefix = /usr/local/php5
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /usr/local/php5
phplibdir = /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/modules
phpincludedir = /usr/local/php5/include/php
CC = gcc
CFLAGS = -O0 -g
CFLAGS_CLEAN = $(CFLAGS)
CPP = gcc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX =
CXXFLAGS =
CXXFLAGS_CLEAN = $(CXXFLAGS)
EXTENSION_DIR = /usr/local/php5/lib/php/extensions/no-debug-non-zts-20100525
PHP_EXECUTABLE = /usr/local/php5/bin/php
EXTRA_LDFLAGS =
EXTRA_LIBS =
INCLUDES = -I/usr/local/php5/include/php -I/usr/local/php5/include/php/main -I/usr/local/php5/include/php/TSRM -I/usr/local/php5/include/php/Zend -I/usr/local/php5/include/php/ext -I/usr/local/php5/include/php/ext/date/lib
LFLAGS =
LDFLAGS =
SHARED_LIBTOOL =
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SHELL = /bin/sh
INSTALL_HEADERS =
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -DPHP_ATOM_INC -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)

all: $(all_targets) 
	@echo
	@echo "Build complete."
	@echo "Don't forget to run 'make test'."
	@echo
	
build-modules: $(PHP_MODULES) $(PHP_ZEND_EX)

build-binaries: $(PHP_BINARIES)

libphp$(PHP_MAJOR_VERSION).la: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) $(EXTRA_CFLAGS) -rpath $(phptempdir) $(EXTRA_LDFLAGS) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@
	-@$(LIBTOOL) --silent --mode=install cp $@ $(phptempdir)/$@ >/dev/null 2>&1

libs/libphp$(PHP_MAJOR_VERSION).bundle: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(CC) $(MH_BUNDLE_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(PHP_GLOBAL_OBJS:.lo=.o) $(PHP_SAPI_OBJS:.lo=.o) $(PHP_FRAMEWORKS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@ && cp $@ libs/libphp$(PHP_MAJOR_VERSION).so

install: $(all_targets) $(install_targets)

install-sapi: $(OVERALL_TARGET)
	@echo "Installing PHP SAPI module:       $(PHP_SAPI)"
	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
	-@if test ! -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); then \
		for i in 0.0.0 0.0 0; do \
			if test -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i; then \
				$(LN_S) $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); \
				break; \
			fi; \
		done; \
	fi
	@$(INSTALL_IT)

install-binaries: build-binaries $(install_binary_targets)

install-modules: build-modules
	@test -d modules && \
	$(mkinstalldirs) $(INSTALL_ROOT)$(EXTENSION_DIR)
	@echo "Installing shared extensions:     $(INSTALL_ROOT)$(EXTENSION_DIR)/"
	@rm -f modules/*.la >/dev/null 2>&1
	@$(INSTALL) modules/* $(INSTALL_ROOT)$(EXTENSION_DIR)

install-headers:
	-@if test "$(INSTALL_HEADERS)"; then \
		for i in `echo $(INSTALL_HEADERS)`; do \
			i=`$(top_srcdir)/build/shtool path -d $$i`; \
			paths="$$paths $(INSTALL_ROOT)$(phpincludedir)/$$i"; \
		done; \
		$(mkinstalldirs) $$paths && \
		echo "Installing header files:          $(INSTALL_ROOT)$(phpincludedir)/" && \
		for i in `echo $(INSTALL_HEADERS)`; do \
			if test "$(PHP_PECL_EXTENSION)"; then \
				src=`echo $$i | $(SED) -e "s#ext/$(PHP_PECL_EXTENSION)/##g"`; \
			else \
				src=$$i; \
			fi; \
			if test -f "$(top_srcdir)/$$src"; then \
				$(INSTALL_DATA) $(top_srcdir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			elif test -f "$(top_builddir)/$$src"; then \
				$(INSTALL_DATA) $(top_builddir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			else \
				(cd $(top_srcdir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i; \
				cd $(top_builddir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i) 2>/dev/null || true; \
			fi \
		done; \
	fi

PHP_TEST_SETTINGS = -d 'open_basedir=' -d 'output_buffering=0' -d 'memory_limit=-1'
PHP_TEST_SHARED_EXTENSIONS =  ` \
	if test "x$(PHP_MODULES)" != "x"; then \
		for i in $(PHP_MODULES)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d extension=$$dlname"; \
		done; \
	fi; \
	if test "x$(PHP_ZEND_EX)" != "x"; then \
		for i in $(PHP_ZEND_EX)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d $(ZEND_EXT_TYPE)=$(top_builddir)/modules/$$dlname"; \
		done; \
	fi`
PHP_DEPRECATED_DIRECTIVES_REGEX = '^(magic_quotes_(gpc|runtime|sybase)?|(zend_)?extension(_debug)?(_ts)?)[\t\ ]*='

test: all
	-@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		INI_FILE=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r 'echo php_ini_loaded_file();' 2> /dev/null`; \
		if test "$$INI_FILE"; then \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_FILE" > $(top_builddir)/tmp-php.ini; \
		else \
			echo > $(top_builddir)/tmp-php.ini; \
		fi; \
		INI_SCANNED_PATH=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r '$$a = explode(",\n", trim(php_ini_scanned_files())); echo $$a[0];' 2> /dev/null`; \
		if test "$$INI_SCANNED_PATH"; then \
			INI_SCANNED_PATH=`$(top_srcdir)/build/shtool path -d $$INI_SCANNED_PATH`; \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_SCANNED_PATH"/*.ini >> $(top_builddir)/tmp-php.ini; \
		fi; \
		TEST_PHP_EXECUTABLE=$(PHP_EXECUTABLE) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(PHP_EXECUTABLE) -n -c $(top_builddir)/tmp-php.ini $(PHP_TEST_SETTINGS) $(top_srcdir)/run-tests.php -n -c $(top_builddir)/tmp-php.ini -d extension_dir=$(top_builddir)/modules/ $(PHP_TEST_SHARED_EXTENSIONS) $(TESTS); \
		rm $(top_builddir)/tmp-php.ini; \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean:
	find . -name \*.gcno -o -name \*.gcda | xargs rm -f
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f 
	find . -name \*.so | xargs rm -f
	find . -name .libs -a -type d|xargs rm -rf
	rm -f libphp$(PHP_MAJOR_VERSION).la $(SAPI_CLI_PATH) $(OVERALL_TARGET) modules/* libs/*

distclean: clean
	rm -f Makefile config.cache config.log config.status Makefile.objects Makefile.fragments libtool main/php_config.h stamp-h sapi/apache/libphp$(PHP_MAJOR_VERSION).module buildmk.stamp
	$(EGREP) define'.*include/php' $(top_srcdir)/configure | $(SED) 's/.*>//'|xargs rm -f

.PHONY: all clean install distclean test
.NOEXPORT:
test.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test.c -o test.lo 
kernel/main.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/main.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/main.c -o kernel/main.lo 
kernel/memory.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/memory.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/memory.c -o kernel/memory.lo 
kernel/exception.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/exception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/exception.c -o kernel/exception.lo 
kernel/hash.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/hash.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/hash.c -o kernel/hash.lo 
kernel/debug.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/debug.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/debug.c -o kernel/debug.lo 
kernel/backtrace.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/backtrace.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/backtrace.c -o kernel/backtrace.lo 
kernel/object.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/object.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/object.c -o kernel/object.lo 
kernel/array.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/array.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/array.c -o kernel/array.lo 
kernel/string.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/string.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/string.c -o kernel/string.lo 
kernel/fcall.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/fcall.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/fcall.c -o kernel/fcall.lo 
kernel/alternative/fcall.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/alternative/fcall.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/alternative/fcall.c -o kernel/alternative/fcall.lo 
kernel/operators.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/operators.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/operators.c -o kernel/operators.lo 
kernel/concat.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/concat.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/kernel/concat.c -o kernel/concat.lo 
test/servicemanager/abstractfactoryinterface.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/abstractfactoryinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/abstractfactoryinterface.c -o test/servicemanager/abstractfactoryinterface.lo 
test/servicemanager/delegatorfactoryinterface.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/delegatorfactoryinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/delegatorfactoryinterface.c -o test/servicemanager/delegatorfactoryinterface.lo 
test/servicemanager/exception/exceptioninterface.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/exception/exceptioninterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/exception/exceptioninterface.c -o test/servicemanager/exception/exceptioninterface.lo 
test/servicemanager/exception/invalidargumentexception.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/exception/invalidargumentexception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/exception/invalidargumentexception.c -o test/servicemanager/exception/invalidargumentexception.lo 
test/servicemanager/exception/runtimeexception.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/exception/runtimeexception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/exception/runtimeexception.c -o test/servicemanager/exception/runtimeexception.lo 
test/servicemanager/exception/servicenotfoundexception.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/exception/servicenotfoundexception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/exception/servicenotfoundexception.c -o test/servicemanager/exception/servicenotfoundexception.lo 
test/servicemanager/factoryinterface.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/factoryinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/factoryinterface.c -o test/servicemanager/factoryinterface.lo 
test/servicemanager/initializerinterface.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/initializerinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/initializerinterface.c -o test/servicemanager/initializerinterface.lo 
test/servicemanager/servicelocatorinterface.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/servicelocatorinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/servicelocatorinterface.c -o test/servicemanager/servicelocatorinterface.lo 
test/servicemanager/servicemanager.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/servicemanager.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/servicemanager.c -o test/servicemanager/servicemanager.lo 
test/servicemanager/servicemanagerconfig.lo: /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/servicemanagerconfig.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/michael/Sites/zend-skeleton-light/vendor/zendframework/zendframework/zephir/ext/test/servicemanager/servicemanagerconfig.c -o test/servicemanager/servicemanagerconfig.lo 
$(phplibdir)/test.la: ./test.la
	$(LIBTOOL) --mode=install cp ./test.la $(phplibdir)

./test.la: $(shared_objects_test) $(TEST_SHARED_DEPENDENCIES)
	$(LIBTOOL) --mode=link $(CC) $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(phplibdir) $(EXTRA_LDFLAGS) $(shared_objects_test) $(TEST_SHARED_LIBADD)

