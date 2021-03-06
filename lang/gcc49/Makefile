# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.9.4
PORTREVISION=	1
CATEGORIES=	lang java
MASTER_SITES=	GCC/releases/gcc-${DISTVERSION}
PKGNAMESUFFIX=	${SUFFIX}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	GNU Compiler Collection 4.9

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils

.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	runtest:misc/dejagnu
.endif

CONFLICTS=	gcc-4.9.*
CPE_VENDOR=	gnu

# GCC_VERSION and SUFFIX relate to names of executables and directories
# once installed.
GCC_VERSION=	${PORTVERSION}
SUFFIX=		${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}
ONLY_FOR_ARCHS=	amd64 armv6 i386 powerpc powerpc64 sparc64
USES=		compiler cpe gmake iconv libtool makeinfo perl5 tar:bzip2
USE_BINUTILS=	yes
USE_PERL5=	build
SSP_UNSAFE=	yes

OPTIONS_DEFINE=		BOOTSTRAP
OPTIONS_DEFINE_i386=	JAVA
OPTIONS_DEFINE_x86_64=	JAVA
OPTIONS_DEFINE_powerpc64=	JAVA
OPTIONS_DEFAULT=	BOOTSTRAP
OPTIONS_DEFAULT_i386=	JAVA
OPTIONS_DEFAULT_x86_64=	JAVA
OPTIONS_EXCLUDE_DragonFly=	JAVA
BOOTSTRAP_DESC=		Build using a full bootstrap

.if exists(/usr/lib32/libc.so)
OPTIONS_DEFINE_powerpc64+=	MULTILIB
OPTIONS_DEFAULT_powerpc64+=	MULTILIB
MULTILIB_DESC=		Build support for 32-bit and 64-bit targets
MULTILIB_CONFIGURE_ENABLE=	multilib
.else
CONFIGURE_ARGS+=	--disable-multilib
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "x86_64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.endif

.if ${ARCH} == powerpc64
CONFIGURE_ENV+=	UNAME_m="powerpc64"
.endif

.if ${ARCH} == "armv6"
# Override sys.mk including -O in CFLAGS which breaks libgomp building.
CFLAGS:=	${CFLAGS:S/-O/-O2/g}
. if ${COMPILER_TYPE} == clang
.  if empty(PORT_OPTIONS:MBOOTSTRAP)
MAKE_ARGS+=CXXFLAGS=-fbracket-depth=512
.  else
MAKE_ARGS+=STAGE1_CXXFLAGS=-fbracket-depth=512
.  endif
. endif
.endif

LANGUAGES:=	c,c++,objc,fortran
TARGLIB=	${PREFIX}/lib/gcc${SUFFIX}
LIBEXEC=	${PREFIX}/libexec/gcc${SUFFIX}
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
.if empty(PORT_OPTIONS:MBOOTSTRAP)
CONFIGURE_ARGS+=--disable-bootstrap
.else
CONFIGURE_ARGS+=--with-build-config=bootstrap-debug
ALL_TARGET=	bootstrap-lean
.endif
CONFIGURE_ARGS+=--disable-nls \
		--enable-gnu-indirect-function \
		--libdir=${TARGLIB} \
		--libexecdir=${LIBEXEC} \
		--program-suffix=${SUFFIX} \
		--with-as=${LOCALBASE}/bin/as \
		--with-gmp=${LOCALBASE} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/ \
		--with-ld=${LOCALBASE}/bin/ld \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection" \
		--with-system-zlib
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=	${TARGLIB}
PLIST_SUB=	GCC_VERSION=${GCC_VERSION} \
		GNU_HOST=${CONFIGURE_TARGET} \
		SUFFIX=${SUFFIX}
INFO=		gcc${SUFFIX}/cpp \
		gcc${SUFFIX}/cppinternals \
		gcc${SUFFIX}/gcc \
		gcc${SUFFIX}/gccinstall \
		gcc${SUFFIX}/gccint \
		gcc${SUFFIX}/gfortran \
		gcc${SUFFIX}/libgomp
# Release tarballs (as opposed to snapshots) always carry this.
#.if ${ARCH} == "i386" || ${ARCH} == "x86_64"
INFO+=		gcc${SUFFIX}/libquadmath
#.endif
.if ${ARCH} == "i386" || ${ARCH} == "x86_64" || ${ARCH} == "armv6"
INFO+=		gcc${SUFFIX}/libitm
.endif

SUB_FILES=	pkg-message
SUB_LIST+=	TARGLIB=${TARGLIB}

.if ${PORT_OPTIONS:MJAVA}
ECJ_JAR=	${LOCALBASE}/share/java/ecj-4.5.jar
BUILD_DEPENDS+=	${ECJ_JAR}:lang/gcc-ecj45 \
		zip:archivers/zip
RUN_DEPENDS+=	${ECJ_JAR}:lang/gcc-ecj45
EXTRA_PATCHES+=	${FILESDIR}/java-patch-hier
CONFIGURE_ARGS+=--with-ecj-jar=${ECJ_JAR}
LANGUAGES:=	${LANGUAGES},java
INFO+=		gcc${SUFFIX}/cp-tools \
		gcc${SUFFIX}/gcj
PLIST_SUB+=	JAVA=""
.else
CONFIGURE_ARGS+=--disable-libgcj
PLIST_SUB+=	JAVA="@comment "
.endif
CONFIGURE_ARGS+=--enable-languages=${LANGUAGES}

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for ${CONFIGURE_TARGET} [${LANGUAGES}]"

pre-configure:
	cd ${WRKSRC} ; contrib/gcc_update --touch
	@${RM} ${WRKSRC}/gcc/*/*.info*

.if defined(MAINTAINER_MODE)
full-regression-test: build
	cd ${TEST_WRKSRC}; ${MAKE_CMD} -sk check \
	; ${WRKSRC}/contrib/test_summary
.endif

post-stage:
	${RM} ${STAGEDIR}${PREFIX}/man/man7/*
	${RM} ${STAGEDIR}${PREFIX}/bin/rebuild-gcj-db${SUFFIX} \
	         ${STAGEDIR}${PREFIX}/man/man1/rebuild-gcj-db${SUFFIX}.1
	# Add target libraries and include files to packaging list.
	${RM} ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} ${LIBEXEC:S/^${PREFIX}\///} include/gcj include/gnu include/java include/javax
	cd ${STAGEDIR}${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
