--- gfx/qcms/qcmstypes.h.orig	2009-08-24 17:52:41.000000000 +0200
+++ gfx/qcms/qcmstypes.h
@@ -23,7 +23,7 @@ typedef PRUint64 uint64_t;
 #ifdef __OS2__
 /* OS/2's stdlib typdefs uintptr_t. So we'll just include that so we don't collide */
 #include <stdlib.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 /* FreeBSD typedefs uintptr_t in /usr/include/sys/types.h */
 #else
 typedef PRUptrdiff uintptr_t;
