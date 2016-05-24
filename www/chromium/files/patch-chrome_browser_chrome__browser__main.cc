--- chrome/browser/chrome_browser_main.cc.orig	2016-05-11 19:02:13 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -169,7 +169,7 @@
 #include "chrome/browser/feedback/feedback_profile_observer.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #include "chrome/browser/sxs_linux.h"
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
@@ -1087,7 +1087,7 @@ int ChromeBrowserMainParts::PreCreateThr
   }
 #endif  // !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
   // Set the product channel for crash reports.
   base::debug::SetCrashKeyValue(crash_keys::kChannel,
                                 chrome::GetChannelString());
@@ -1437,7 +1437,7 @@ int ChromeBrowserMainParts::PreMainMessa
     return chrome::RESULT_CODE_MACHINE_LEVEL_INSTALL_EXISTS;
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   if (sxs_linux::ShouldMigrateUserDataDir())
     return sxs_linux::MigrateUserDataDir();
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)