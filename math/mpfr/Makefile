# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpfr
PORTVERSION=	3.1.5
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://www.mpfr.org/mpfr-current/
DIST_SUBDIR=	${DISTNAME}

PATCH_SITES=	${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Library for multiple-precision floating-point computations

LICENSE=	LGPL3

#PATCH_DEPENDS=	gpatch:devel/patch
BUILD_DEPENDS=	gmp>0:math/gmp

PATCHLEVEL=	2
PATCHFILES!=	/usr/bin/jot -s " " -w patch%02d ${PATCHLEVEL} 1 ${PATCHLEVEL}
#PATCH=		${LOCALBASE}/bin/gpatch

USES=		libtool tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} \
		--enable-shared=no
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

INFO=		mpfr

PORTDOCS=	*

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
