--- ./chrome/plugin/plugin_thread.cc.orig	2010-12-13 12:04:29.000000000 +0100
+++ ./chrome/plugin/plugin_thread.cc	2010-12-20 20:41:37.000000000 +0100
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if defined(USE_X11)
+#if defined(TOOLKIT_USES_GTK)
 #include <gtk/gtk.h>
 #elif defined(OS_MACOSX)
 #include <CoreFoundation/CoreFoundation.h>
@@ -57,7 +57,7 @@
           switches::kPluginPath);
 
   lazy_tls.Pointer()->Set(this);
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
   {
     // XEmbed plugins assume they are hosted in a Gtk application, so we need
     // to initialize Gtk in the plugin process.
