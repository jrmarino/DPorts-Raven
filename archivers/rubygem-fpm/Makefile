# $FreeBSD$

PORTNAME=	fpm
PORTVERSION=	1.8.0
CATEGORIES=	archivers rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Build packages for multiple platforms with great ease and sanity

RUN_DEPENDS=	rubygem-archive-tar-minitar>=0:archivers/rubygem-archive-tar-minitar \
		rubygem-arr-pm>=0.0.10:devel/rubygem-arr-pm \
		rubygem-backports>0:devel/rubygem-backports \
		rubygem-cabin>=0.6.0:devel/rubygem-cabin \
		rubygem-childprocess>=0:devel/rubygem-childprocess \
		rubygem-clamp>=1.0.0:devel/rubygem-clamp \
		rubygem-ffi>=0:devel/rubygem-ffi \
		rubygem-mustache>=0:devel/rubygem-mustache \
		rubygem-json1>=1.7:devel/rubygem-json1 \
		rubygem-pleaserun>=0.0.24:devel/rubygem-pleaserun \
		rubygem-ruby-xz>=0:archivers/rubygem-ruby-xz

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/fpm

post-patch:
	@${REINPLACE_CMD} -e 's/1\.0\.0/1.0/' ${WRKSRC}/fpm.gemspec

.include <bsd.port.mk>
