--- ./build/features_override.gypi.orig	2010-12-13 12:04:11.000000000 +0100
+++ ./build/features_override.gypi	2010-12-20 20:41:37.000000000 +0100
@@ -69,7 +69,7 @@
     'enable_svg%': '<(enable_svg)',
     'enable_touch_events%': '<(enable_touch_events)',
     'conditions': [
-      ['(OS=="win" or OS=="linux" or OS=="mac") and use_accelerated_compositing==1', {
+      ['(OS=="win" or OS=="linux" or OS=="mac" or OS=="freebsd") and use_accelerated_compositing==1', {
         'feature_defines': [
           'WTF_USE_ACCELERATED_COMPOSITING=1',
           'ENABLE_3D_RENDERING=1',
