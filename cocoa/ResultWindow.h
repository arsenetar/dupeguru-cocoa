/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import <Cocoa/Cocoa.h>
#import <Quartz/Quartz.h>
#import "StatsLabel.h"
#import "ResultTable.h"
#import "HSTableView.h"
#import "PyDupeGuru.h"

@class AppDelegate;

@interface ResultWindow : NSWindowController
{
@protected
    NSSegmentedControl *optionsSwitch;
    NSToolbarItem *optionsToolbarItem;
    HSTableView *matches;
    NSTextField *stats;
    NSSearchField *filterField;
    
    AppDelegate *app;
    PyDupeGuru *model;
    ResultTable *table;
    StatsLabel *statsLabel;
    QLPreviewPanel* previewPanel;
}

@property (readwrite, retain) NSSegmentedControl *optionsSwitch;
@property (readwrite, retain) NSToolbarItem *optionsToolbarItem;
@property (readwrite, retain) HSTableView *matches;
@property (readwrite, retain) NSTextField *stats;
@property (readwrite, retain) NSSearchField *filterField;

- (id)initWithParentApp:(AppDelegate *)app;

/* Helpers */
- (void)fillColumnsMenu;
- (void)updateOptionSegments;
- (void)adjustUIToLocalization;
- (void)initResultColumns:(ResultTable *)aTable;

/* Actions */
- (IBAction)changeOptions:(id)sender;
- (IBAction)copyMarked:(id)sender;
- (IBAction)trashMarked:(id)sender;
- (IBAction)exportToXHTML:(id)sender;
- (IBAction)exportToCSV:(id)sender;
- (IBAction)filter:(id)sender;
- (IBAction)focusOnFilterField:(id)sender;
- (IBAction)ignoreSelected:(id)sender;
- (IBAction)invokeCustomCommand:(id)sender;
- (IBAction)markAll:(id)sender;
- (IBAction)markInvert:(id)sender;
- (IBAction)markNone:(id)sender;
- (IBAction)markSelected:(id)sender;
- (IBAction)moveMarked:(id)sender;
- (IBAction)openClicked:(id)sender;
- (IBAction)openSelected:(id)sender;
- (IBAction)removeMarked:(id)sender;
- (IBAction)removeSelected:(id)sender;
- (IBAction)renameSelected:(id)sender;
- (IBAction)reprioritizeResults:(id)sender;
- (IBAction)resetColumnsToDefault:(id)sender;
- (IBAction)revealSelected:(id)sender;
- (IBAction)saveResults:(id)sender;
- (IBAction)switchSelected:(id)sender;
- (IBAction)toggleColumn:(id)sender;
- (IBAction)toggleDelta:(id)sender;
- (IBAction)toggleDetailsPanel:(id)sender;
- (IBAction)togglePowerMarker:(id)sender;
- (IBAction)toggleQuicklookPanel:(id)sender;
@end
