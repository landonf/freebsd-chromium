--- ./chrome/test/ui/ui_layout_test.cc.orig	2010-12-13 12:04:45.000000000 +0100
+++ ./chrome/test/ui/ui_layout_test.cc	2010-12-20 20:41:37.000000000 +0100
@@ -19,7 +19,7 @@
 static const char kPlatformName[] = "chromium-win";
 #elif defined(OS_MACOSX)
 static const char kPlatformName[] = "chromium-mac";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 static const char kPlatformName[] = "chromium-linux";
 #else
 #error No known OS defined
