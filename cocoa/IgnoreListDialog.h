/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import <Cocoa/Cocoa.h>
#import "PyIgnoreListDialog.h"
#import "HSTable.h"

@interface IgnoreListDialog : NSWindowController
{
	IBOutlet NSTableView *ignoreListTableView;

    PyIgnoreListDialog *model;
    HSTable *ignoreListTable;
}

@property (readwrite, retain) PyIgnoreListDialog *model;
@property (readwrite, retain) NSTableView *ignoreListTableView;

- (id)initWithPyRef:(PyObject *)aPyRef;
- (void)initializeColumns;
- (IBAction)removeSelected:(id)sender;
- (IBAction)clear:(id)sender;
@end