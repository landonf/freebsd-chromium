--- ./chrome/browser/memory_details.cc.orig	2014-08-13 21:02:26.000000000 +0200
+++ ./chrome/browser/memory_details.cc	2014-08-21 21:41:49.000000000 +0200
@@ -32,7 +32,7 @@
 #include "grit/generated_resources.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #endif
 
@@ -202,7 +202,7 @@
 void MemoryDetails::CollectChildInfoOnUIThread() {
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   const pid_t zygote_pid = content::ZygoteHost::GetInstance()->GetPid();
 #endif
 
@@ -334,7 +334,7 @@
       }
     }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     if (process.pid == zygote_pid) {
       process.process_type = content::PROCESS_TYPE_ZYGOTE;
     }
