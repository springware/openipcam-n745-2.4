## $Id: Makefile.am,v 1.1.1.1 2006-07-11 09:31:22 andy Exp $

## Process this file with automake to produce Makefile.in 

## here the correct driver is substituted in by the configure script
## (or empty for none)

EXTRA_DIST = lirc.h

DIST_SUBDIRS = lirc_serial lirc_parallel lirc_i2c lirc_sir lirc_dev lirc_gpio
SUBDIRS = @lirc_driver@

CLEANFILES = *~

install-exec-local: mklink mkdev
uninstall-local: rmlink mkdev

mklink:
	test "@irtty@" = "" || test -L @devdir@/lirc || (cd `dirname @irtty@` && $(LN_S) `basename @irtty@` lirc)

rmlink:
	test "@irtty@" = "" || $(RM) @devdir@/lirc

mkdev:
	test "@driver@" != "mediafocusI" || test -c @devdir@/lirc || @mknod@ @devdir@/lirc c @lirc_major@ 0

rmdev:
	test "@driver@" != "mediafocusI" || test -c @devdir@/lirc && $(RM) @devdir@/lirc
