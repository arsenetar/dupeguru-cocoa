/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import <Cocoa/Cocoa.h>
#import "HSOutlineView.h"
#import "HSRecentFiles.h"
#import "DirectoryOutline.h"
#import "PyDupeGuru.h"

@class AppDelegate;

@interface DirectoryPanel : NSWindowController <NSOpenSavePanelDelegate>
{
    AppDelegate *_app;
    PyDupeGuru *model;
    HSRecentFiles *_recentDirectories;
    DirectoryOutline *outline;
    BOOL _alwaysShowPopUp;
    IBOutlet NSSegmentedControl *appModeSelector;
    IBOutlet NSPopUpButton *scanTypePopup;
    IBOutlet NSPopUpButton *addButtonPopUp;
    IBOutlet NSPopUpButton *loadRecentButtonPopUp;
    IBOutlet HSOutlineView *outlineView;
    IBOutlet NSButton *removeButton;
    IBOutlet NSButton *loadResultsButton;
}

@property (readwrite, retain) NSSegmentedControl *appModeSelector;
@property (readwrite, retain) NSPopUpButton *scanTypePopup;
@property (readwrite, retain) NSPopUpButton *addButtonPopUp;
@property (readwrite, retain) NSPopUpButton *loadRecentButtonPopUp;
@property (readwrite, retain) HSOutlineView *outlineView;
@property (readwrite, retain) NSButton *removeButton;
@property (readwrite, retain) NSButton *loadResultsButton;

- (id)initWithParentApp:(AppDelegate *)aParentApp;

- (void)fillPopUpMenu;
- (void)fillScanTypeMenu;
- (void)adjustUIToLocalization;

- (void)askForDirectory;
- (IBAction)changeAppMode:(id)sender;
- (IBAction)popupAddDirectoryMenu:(id)sender;
- (IBAction)popupLoadRecentMenu:(id)sender;
- (IBAction)removeSelectedDirectory:(id)sender;
- (IBAction)startDuplicateScan:(id)sender;

- (void)addDirectory:(NSString *)directory;
- (void)refreshRemoveButtonText;
- (void)markAll;

@end
