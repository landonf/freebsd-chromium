--- ./webkit/glue/plugins/pepper_plugin_instance.cc.orig	2010-12-13 12:03:08.000000000 +0100
+++ ./webkit/glue/plugins/pepper_plugin_instance.cc	2010-12-20 20:41:38.000000000 +0100
@@ -301,10 +301,10 @@
       plugin_private_interface_(NULL),
       plugin_selection_interface_(NULL),
       plugin_zoom_interface_(NULL),
-#if defined (OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
       num_pages_(0),
       pdf_output_done_(false),
-#endif  // defined (OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
       plugin_print_interface_(NULL),
       plugin_graphics_3d_interface_(NULL),
       always_on_top_(false),
@@ -835,17 +835,17 @@
   if (!num_pages)
     return 0;
   current_print_settings_ = print_settings;
-#if defined (OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   num_pages_ = num_pages;
   pdf_output_done_ = false;
-#endif  // (OS_LINUX)
+#endif  // OS_LINUX || OS_FREEBSD
   return num_pages;
 }
 
 bool PluginInstance::PrintPage(int page_number, WebKit::WebCanvas* canvas) {
   DCHECK(plugin_print_interface_);
   PP_PrintPageNumberRange_Dev page_range;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   if (current_print_settings_.format == PP_PRINTOUTPUTFORMAT_PDF) {
     // On Linux we will try and output all pages as PDF in the first call to
     // PrintPage. This is a temporary hack.
@@ -856,9 +856,9 @@
     page_range.first_page_number = 0;
     page_range.last_page_number = num_pages_ - 1;
   }
-#else  // defined(OS_LINUX)
+#else  // defined(OS_LINUX) || defined(OS_FREEBSD)
   page_range.first_page_number = page_range.last_page_number = page_number;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
   PP_Resource print_output =
       plugin_print_interface_->PrintPages(pp_instance(), &page_range, 1);
@@ -886,10 +886,10 @@
   memset(&current_print_settings_, 0, sizeof(current_print_settings_));
 #if defined(OS_MACOSX)
   last_printed_page_ = NULL;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   num_pages_ = 0;
   pdf_output_done_ = false;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 }
 
 bool PluginInstance::IsFullscreen() {
@@ -957,7 +957,7 @@
 #endif  // defined(OS_WIN)
 
   bool ret = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // On Linux we need to get the backing PdfPsMetafile and write the bits
   // directly.
   cairo_t* context = canvas->beginPlatformPaint();
