--- include/netdb.h.orig	2008-02-28 07:34:17.000000000 +0200
+++ include/netdb.h
@@ -492,7 +492,7 @@ int		innetgr_r __P((const char *, const
 #endif
 #else
  /* defined(sun) || defined(bsdi) */
-#if defined(__GLIBC__) || defined(__FreeBSD__) && (__FreeBSD_version + 0 >= 601103)
+#if defined(__GLIBC__) || defined(__DragonFly__) || defined(__FreeBSD__) && (__FreeBSD_version + 0 >= 601103)
 int gethostbyaddr_r __P((const char *, int, int, struct hostent *,
 		         char *, size_t, struct hostent **, int *));
 int gethostbyname_r __P((const char *, struct hostent *,
@@ -509,7 +509,7 @@ struct hostent	*gethostent_r __P((struct
 void		sethostent_r __P((int));
 void		endhostent_r __P((void));
 
-#if defined(__GLIBC__) || defined(__FreeBSD__) && (__FreeBSD_version + 0 >= 601103)
+#if defined(__GLIBC__) || defined(__DragonFly__) || defined(__FreeBSD__) && (__FreeBSD_version + 0 >= 601103)
 int getnetbyname_r __P((const char *, struct netent *,
 			char *, size_t, struct netent **, int*));
 int getnetbyaddr_r __P((unsigned long int, int, struct netent *,
@@ -525,7 +525,7 @@ struct netent	*getnetent_r __P((struct n
 void		setnetent_r __P((int));
 void		endnetent_r __P((void));
 
-#if defined(__GLIBC__) || defined(__FreeBSD__) && (__FreeBSD_version + 0 >= 601103)
+#if defined(__GLIBC__) || defined(__DragonFly__) || defined(__FreeBSD__) && (__FreeBSD_version + 0 >= 601103)
 int getprotobyname_r __P((const char *, struct protoent *, char *,
 			  size_t, struct protoent **));
 int getprotobynumber_r __P((int, struct protoent *, char *, size_t,
@@ -541,7 +541,7 @@ struct protoent	*getprotoent_r __P((stru
 void		setprotoent_r __P((int));
 void		endprotoent_r __P((void));
 
-#if defined(__GLIBC__) || defined(__FreeBSD__) && (__FreeBSD_version + 0 >= 601103)
+#if defined(__GLIBC__) || defined(__DragonFly__) || defined(__FreeBSD__) && (__FreeBSD_version + 0 >= 601103)
 int getservbyname_r __P((const char *name, const char *,
 			 struct servent *, char *, size_t, struct servent **));
 int getservbyport_r __P((int port, const char *,
