--- ./chrome/browser/ui/views/frame/browser_view.cc.orig	2010-12-13 12:04:28.000000000 +0100
+++ ./chrome/browser/ui/views/frame/browser_view.cc	2010-12-20 20:41:37.000000000 +0100
@@ -4,7 +4,7 @@
 
 #include "chrome/browser/views/frame/browser_view.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include <gtk/gtk.h>
 #endif
 
@@ -86,7 +86,7 @@
 #include "app/win_util.h"
 #include "chrome/browser/aeropeek_manager.h"
 #include "chrome/browser/jumplist_win.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "chrome/browser/views/accelerator_table_gtk.h"
 #include "views/window/hit_test.h"
 #include "views/window/window_gtk.h"
@@ -1127,7 +1127,7 @@
   std::wstring message = l10n_util::GetString(message_id);
   win_util::MessageBox(GetNativeHandle(), message, title,
                        MB_OK | MB_ICONWARNING | MB_TOPMOST);
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   std::string title = l10n_util::GetStringUTF8(IDS_PRODUCT_NAME);
   std::string message = l10n_util::GetStringUTF8(message_id);
   GtkWidget* dialog = gtk_message_dialog_new(GetNativeHandle(),
@@ -1225,7 +1225,7 @@
   views::FocusManager* focus_manager = GetFocusManager();
   DCHECK(focus_manager);
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
   // Views and WebKit use different tables for GdkEventKey -> views::KeyEvent
   // conversion. We need to use View's conversion table here to keep consistent
   // behavior with views::FocusManager::OnKeyEvent() method.
