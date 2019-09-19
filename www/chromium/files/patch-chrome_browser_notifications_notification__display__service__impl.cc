--- chrome/browser/notifications/notification_display_service_impl.cc.orig	2019-09-09 21:55:09 UTC
+++ chrome/browser/notifications/notification_display_service_impl.cc
@@ -31,7 +31,7 @@
 #include "chrome/browser/notifications/notification_platform_bridge_message_center.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/send_tab_to_self/desktop_notification_handler.h"
 #endif
 
@@ -120,7 +120,7 @@ NotificationDisplayServiceImpl::NotificationDisplaySer
     AddNotificationHandler(NotificationHandler::Type::WEB_PERSISTENT,
                            std::make_unique<PersistentNotificationHandler>());
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     AddNotificationHandler(
         NotificationHandler::Type::SEND_TAB_TO_SELF,
         std::make_unique<send_tab_to_self::DesktopNotificationHandler>(