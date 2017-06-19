--- chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/ui/webui/settings/appearance_handler.cc
@@ -32,7 +32,7 @@ void AppearanceHandler::RegisterMessages() {
       "useDefaultTheme",
       base::Bind(&AppearanceHandler::HandleUseDefaultTheme,
                  base::Unretained(this)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   web_ui()->RegisterMessageCallback(
       "useSystemTheme",
       base::Bind(&AppearanceHandler::HandleUseSystemTheme,
@@ -50,7 +50,7 @@ void AppearanceHandler::HandleUseDefaultTheme(const ba
   ThemeServiceFactory::GetForProfile(profile_)->UseDefaultTheme();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 void AppearanceHandler::HandleUseSystemTheme(const base::ListValue* args) {
   if (profile_->IsSupervised())
     NOTREACHED();
