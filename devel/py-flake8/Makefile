# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	flake8
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Code checking using pep8 and pyflakes

LICENSE=	MIT

BUILD_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner
RUN_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}mccabe>=0.5.0:devel/py-mccabe \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>=2.0.0:devel/py-pycodestyle \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=0.8.1:devel/py-pyflakes

USES?=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.mk>
