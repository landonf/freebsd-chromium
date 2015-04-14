--- chrome/browser/ui/toolbar/wrench_menu_model.cc.orig.port	Tue Mar 10 23:41:40 2015
+++ chrome/browser/ui/toolbar/wrench_menu_model.cc	Wed Mar 11 07:22:50 2015
@@ -747,7 +747,7 @@ bool WrenchMenuModel::IsCommandIdVisible(int command_i
 #endif
     case IDC_UPGRADE_DIALOG:
       return UpgradeDetector::GetInstance()->notify_upgrade();
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
     case IDC_BOOKMARK_PAGE:
       return !chrome::ShouldRemoveBookmarkThisPageUI(browser_->profile());
     case IDC_BOOKMARK_ALL_TABS:
