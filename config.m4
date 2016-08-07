dnl $Id$
dnl config.m4 for extension numphp

dnl Comments in this file start with the string 'dnl'.

PHP_ARG_ENABLE(numphp, whether to enable numphp support, [  --enable-numphp           Enable numphp support])

if test "$PHP_NUMPHP" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-numphp -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/numphp.h"  # you most likely want to change this
  dnl if test -r $PHP_NUMPHP/$SEARCH_FOR; then # path given as parameter
  dnl   NUMPHP_DIR=$PHP_NUMPHP
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for numphp files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       NUMPHP_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$NUMPHP_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the numphp distribution])
  dnl fi

  dnl # --with-numphp -> add include path
  dnl PHP_ADD_INCLUDE($NUMPHP_DIR/include)

  dnl # --with-numphp -> check for lib and symbol presence
  dnl LIBNAME=numphp # you may want to change this
  dnl LIBSYMBOL=numphp # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $NUMPHP_DIR/$PHP_LIBDIR, NUMPHP_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_NUMPHPLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong numphp lib version or lib not found])
  dnl ],[
  dnl   -L$NUMPHP_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(NUMPHP_SHARED_LIBADD)

  PHP_NEW_EXTENSION(numphp, numphp.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
