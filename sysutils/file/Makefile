# Created by: Jason Harris <jharris@widomaker.com>
# $FreeBSD$

PORTNAME=	file
PORTVERSION=	5.29
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.astron.com/pub/file/ \
		ftp://ftp.fu-berlin.de/unix/tools/file/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Utility to determine file type

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	zlib>0:archivers/zlib

USES=		libtool localbase:ldflags
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-fsect-man5
CONFIGURE_ARGS+=	--enable-shared=no
MAKE_ENV+=	INSTALL_STRIP_FLAG="${STRIP}"
CONFIGURE_ARGS+=	--datarootdir=/usr/share

CONFLICTS=	tct-[0-9]*

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)/misc|$$(datadir)/${PORTNAME}|g' \
		${WRKSRC}/configure

post-install:
	${MV} ${STAGEDIR}/usr/share/file ${STAGEDIR}${PREFIX}/share/
	${RMDIR} ${STAGEDIR}/usr/share

.include <bsd.port.mk>
