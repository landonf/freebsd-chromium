--- net/dns/address_sorter_posix.cc.orig	2017-06-05 19:03:10 UTC
+++ net/dns/address_sorter_posix.cc
@@ -13,6 +13,7 @@
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
+#include <net/if_var.h>
 #include <netinet/in_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
