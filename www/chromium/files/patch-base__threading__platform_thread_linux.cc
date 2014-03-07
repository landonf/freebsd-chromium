--- ./base/threading/platform_thread_linux.cc.orig	2014-03-04 03:16:25.000000000 +0100
+++ ./base/threading/platform_thread_linux.cc	2014-03-07 14:10:32.000000000 +0100
@@ -16,7 +16,9 @@
 #include "base/tracked_objects.h"
 
 #if !defined(OS_NACL)
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/resource.h>
 #include <sys/syscall.h>
 #include <sys/time.h>
@@ -48,7 +50,7 @@
   ThreadIdNameManager::GetInstance()->SetName(CurrentId(), name);
   tracked_objects::ThreadData::InitializeThreadContext(name);
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
   // On linux we can get the thread names to show up in the debugger by setting
   // the process name for the LWP.  We don't want to do this for the main
   // thread because that would rename the process, causing tools like killall
