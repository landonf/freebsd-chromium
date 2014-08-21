--- ./media/base/audio_splicer.cc.orig	2014-08-13 21:02:32.000000000 +0200
+++ ./media/base/audio_splicer.cc	2014-08-21 22:33:57.000000000 +0200
@@ -137,7 +137,7 @@
       output_timestamp_helper_.GetTimestamp();
   const base::TimeDelta delta = timestamp - expected_timestamp;
 
-  if (std::abs(delta.InMilliseconds()) >
+  if (std::labs(delta.InMilliseconds()) >
       AudioSplicer::kMaxTimeDeltaInMilliseconds) {
     DVLOG(1) << "Timestamp delta too large: " << delta.InMicroseconds() << "us";
     return false;
@@ -147,7 +147,7 @@
   if (delta != base::TimeDelta())
     frames_to_fill = output_timestamp_helper_.GetFramesToTarget(timestamp);
 
-  if (frames_to_fill == 0 || std::abs(frames_to_fill) < kMinGapSize) {
+  if (frames_to_fill == 0 || std::labs(frames_to_fill) < kMinGapSize) {
     AddOutputBuffer(input);
     return true;
   }
