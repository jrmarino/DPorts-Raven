# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-python
PORTREVISION=	1

COMMENT=	Python table support for OpenSMTPD

PLIST_FILES=	libexec/opensmtpd/table-python

CONFIGURE_ARGS+=	--with-table-python --with-python-type=${PYTHON_VERSION}

USES=		python:2 pkgconfig

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
