--- ./ui/events/event_switches.h.orig	2014-08-13 21:01:28.000000000 +0200
+++ ./ui/events/event_switches.h	2014-08-21 21:41:50.000000000 +0200
@@ -20,7 +20,7 @@
 EVENTS_BASE_EXPORT extern const char kUnifiedGestureDetectorEnabled[];
 EVENTS_BASE_EXPORT extern const char kUnifiedGestureDetectorDisabled[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 #endif
 
