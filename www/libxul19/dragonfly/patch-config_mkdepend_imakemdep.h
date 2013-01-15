$NetBSD: patch-af,v 1.1.1.1 2011/04/19 11:16:07 tnn Exp $

--- config/mkdepend/imakemdep.h.orig	2009-06-29 18:14:41.000000000 +0200
+++ config/mkdepend/imakemdep.h
@@ -235,7 +235,7 @@ in this Software without prior written a
 #ifdef _CRAY
 #define DEFAULT_CPP "/lib/pcpp"
 #endif
-#if defined(__386BSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__386BSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #define DEFAULT_CPP "/usr/libexec/cpp"
 #endif
 #ifdef	MACH
@@ -273,7 +273,7 @@ char *cpp_argv[ARGUMENTS] = {
 #ifdef unix
 	"-Uunix",	/* remove unix symbol so that filename unix.c okay */
 #endif
-#if defined(__386BSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(MACH)
+#if defined(__386BSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(MACH) || defined(__DragonFly__)
 # ifdef __i386__
 	"-D__i386__",
 # endif
@@ -713,6 +713,9 @@ struct symtab	predefs[] = {
 #ifdef __sgi
 	{"__sgi", "1"},
 #endif
+#ifdef __DragonFly__
+	{"__DragonFly__", "1"},
+#endif
 #ifdef __FreeBSD__
 	{"__FreeBSD__", "1"},
 #endif
