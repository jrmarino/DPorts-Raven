# $FreeBSD$

PORTNAME=	stlink
PORTVERSION=	1.3.0.20170131
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	lev@FreeBSD.org
COMMENT=	STM32 ST-Link JTAG variant tools

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=		GTK3
OPTIONS_SUB=		GTK3
GTK3_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-pacth-turn-off-gtk
GTK3_USE=		GNOME=gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	texane
GH_TAGNAME=	f62895b

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

PORTDOCS=	README.md tested-boards.md tutorial.md

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README.md
	${INSTALL_DATA} ${WRKSRC}/doc/tested-boards.md ${STAGEDIR}${DOCSDIR}/tested-boards.md
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial.md ${STAGEDIR}${DOCSDIR}/tutorial.md

.include <bsd.port.mk>
