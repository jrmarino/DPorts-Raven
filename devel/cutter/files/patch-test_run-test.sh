
$FreeBSD: devel/cutter/files/patch-test_run-test.sh 300896 2012-07-14 13:54:48Z beat $

--- test/run-test.sh.orig
+++ test/run-test.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 BASE_DIR="`dirname $0`"
 export BASE_DIR
