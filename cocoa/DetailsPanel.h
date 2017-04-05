/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import <Cocoa/Cocoa.h>
#import <Python.h>
#import "PyDetailsPanel.h"

@interface DetailsPanel : NSWindowController <NSTableViewDataSource>
{
    IBOutlet NSTableView *detailsTable;
    
    PyDetailsPanel *model;
}

@property (readwrite, retain) NSTableView *detailsTable;

- (id)initWithPyRef:(PyObject *)aPyRef;
- (PyDetailsPanel *)model;

- (NSString *)getWindowNibName;
- (BOOL)isVisible;
- (void)toggleVisibility;

/* Python --> Cocoa */
- (void)refresh;
@end
