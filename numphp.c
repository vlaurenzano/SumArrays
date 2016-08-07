/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_numphp.h"

/* If you declare any globals in php_numphp.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(numphp)
*/

/* True global resources - no need for thread safety here */
static int le_numphp;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("numphp.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_numphp_globals, numphp_globals)
    STD_PHP_INI_ENTRY("numphp.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_numphp_globals, numphp_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_numphp_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_numphp_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "numphp", arg);

	RETURN_STR(strg);
}

PHP_FUNCTION(sum_arrays)
{
    HashTable *h1;
    HashTable *h2;
    long num_key;
    zval * val;
    zval * ar1;
    zval * ar2;
	zval * zv1;
	zval * zv2;
    zend_string *key;
    uint i, j;
    double z;
    Bucket *p;

    ZEND_PARSE_PARAMETERS_START(2,"a");
    Z_PARAM_ZVAL(ar1);
    Z_PARAM_ZVAL(ar2);
    ZEND_PARSE_PARAMETERS_END();

    h1 = Z_ARRVAL_P(ar1);
    h2 = Z_ARRVAL_P(ar2);

    array_init(return_value);

    for(i = 0; i < h1->nNumOfElements; i++){
        zv1 = &h1->arData[i].val;
		zv2 = &h2->arData[i].val;
		if(Z_TYPE_P(zv1) == IS_LONG && Z_TYPE_P(zv2) == IS_LONG) {
			add_next_index_double(return_value, Z_LVAL_P(zv1) + Z_LVAL_P(zv2));
		} else if(Z_TYPE_P(zv1) == IS_DOUBLE && Z_TYPE_P(zv2) == IS_DOUBLE) {
			add_next_index_double(return_value, Z_DVAL_P(zv1) + Z_DVAL_P(zv2));
		}
    }
}

/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/

/* {{{ php_numphp_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_numphp_init_gloibals(zend_numphp_globals *numphp_globals)
{
	numphp_globals->global_value = 0;
	numphp_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(numphp)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(numphp)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(numphp)
{
#if defined(COMPILE_DL_NUMPHP) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(numphp)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(numphp)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "numphp support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ numphp_functions[]
 *
 * Every user visible function must have an entry in numphp_functions[].
 */
const zend_function_entry numphp_functions[] = {
	PHP_FE(confirm_numphp_compiled,	NULL)/* For testing, remove later. */
	PHP_FE(sum_arrays, NULL)
	PHP_FE_END	/* Must be the last line in numphp_functions[] */
};
/* }}} */

/* {{{ numphp_module_entry
 */
zend_module_entry numphp_module_entry = {
	STANDARD_MODULE_HEADER,
	"numphp",
	numphp_functions,
	PHP_MINIT(numphp),
	PHP_MSHUTDOWN(numphp),
	PHP_RINIT(numphp),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(numphp),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(numphp),
	PHP_NUMPHP_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_NUMPHP
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(numphp)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
