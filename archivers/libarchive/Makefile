# $FreeBSD$

PORTNAME=	libarchive
PORTVERSION=	3.2.2
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://libarchive.org/downloads/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Library to create and read several streaming archive formats

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	xz>0:archivers/xz \
		bzip2>0:archivers/bzip2 \
		zlib>0:archivers/zlib \
		expat>0:textproc/expat2 \
		libressl>0:security/libressl

OPTIONS_DEFINE=	LZ4 LZO #NETTLE
OPTIONS_DEFAULT=LZ4 LZO

LZ4_DESC=	Support lz4 compression via liblz4
LZO_DESC=	Support lzo compression via liblzo2
NETTLE_DESC=	Use Nettle instead of OpenSSL

USES=		cpe iconv libtool pathfix
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--without-xml2 \
		--enable-shared=no \
		--enable-static=yes

PLIST_FILES=	bin/bsdcat \
		bin/bsdcpio \
		bin/bsdtar \
		include/archive.h \
		include/archive_entry.h \
		lib/libarchive.a \
		libdata/pkgconfig/libarchive.pc \
		man/man1/bsdcat.1.gz \
		man/man1/bsdcpio.1.gz \
		man/man1/bsdtar.1.gz \
		man/man3/archive_entry.3.gz \
		man/man3/archive_entry_acl.3.gz \
		man/man3/archive_entry_linkify.3.gz \
		man/man3/archive_entry_paths.3.gz \
		man/man3/archive_entry_perms.3.gz \
		man/man3/archive_entry_stat.3.gz \
		man/man3/archive_entry_time.3.gz \
		man/man3/archive_read.3.gz \
		man/man3/archive_read_add_passphrase.3.gz \
		man/man3/archive_read_data.3.gz \
		man/man3/archive_read_disk.3.gz \
		man/man3/archive_read_extract.3.gz \
		man/man3/archive_read_filter.3.gz \
		man/man3/archive_read_format.3.gz \
		man/man3/archive_read_free.3.gz \
		man/man3/archive_read_header.3.gz \
		man/man3/archive_read_new.3.gz \
		man/man3/archive_read_open.3.gz \
		man/man3/archive_read_set_options.3.gz \
		man/man3/archive_util.3.gz \
		man/man3/archive_write.3.gz \
		man/man3/archive_write_blocksize.3.gz \
		man/man3/archive_write_data.3.gz \
		man/man3/archive_write_disk.3.gz \
		man/man3/archive_write_filter.3.gz \
		man/man3/archive_write_finish_entry.3.gz \
		man/man3/archive_write_format.3.gz \
		man/man3/archive_write_free.3.gz \
		man/man3/archive_write_header.3.gz \
		man/man3/archive_write_new.3.gz \
		man/man3/archive_write_open.3.gz \
		man/man3/archive_write_set_options.3.gz \
		man/man3/archive_write_set_passphrase.3.gz \
		man/man3/libarchive.3.gz \
		man/man3/libarchive_changes.3.gz \
		man/man3/libarchive_internals.3.gz \
		man/man5/cpio.5.gz \
		man/man5/libarchive-formats.5.gz \
		man/man5/mtree.5.gz \
		man/man5/tar.5.gz

CFLAGS+=	"-I${LOCALBASE}/include"
CPPFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

LZO_BUILD_DEPENDS=	lzo2>0:archivers/lzo2
LZO_CONFIGURE_WITH=	lzo2
LZ4_BUILD_DEPENDS=	liblz4>0:archivers/liblz4
LZ4_CONFIGURE_WITH=	lz4

NETTLE_LIB_DEPENDS=	libnettle.so:security/nettle
NETTLE_CONFIGURE_WITH=	nettle
NETTLE_CONFIGURE_ON=	--without-openssl
NETTLE_USE_OFF=		OPENSSL=yes
NETTLE_CONFIGURE_OFF=	--with-openssl

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.if empty(ICONV_LIB)
CONFIGURE_ENV+=	ac_cv_header_localcharset_h=no \
		ac_cv_func_locale_charset=no \
		ac_cv_lib_charset_locale_charset=no
.endif

check:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check)

.include <bsd.port.post.mk>
