--- ./chrome/plugin/plugin_main_linux.cc.orig	2010-12-13 12:04:29.000000000 +0100
+++ ./chrome/plugin/plugin_main_linux.cc	2010-12-20 20:41:37.000000000 +0100
@@ -5,13 +5,13 @@
 #include <signal.h>
 #include <string.h>
 #include <sys/types.h>
-#include <syscall.h>
+#include <sys/syscall.h>
 #include <unistd.h>
 
 #include "build/build_config.h"
 
 // This whole file is only useful on 64-bit architectures.
-#if defined(ARCH_CPU_64_BITS)
+#if defined(ARCH_CPU_64_BITS) && !defined(OS_FREEBSD)
 
 namespace {
 
