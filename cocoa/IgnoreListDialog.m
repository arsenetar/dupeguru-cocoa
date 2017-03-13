/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import "IgnoreListDialog.h"
#import "HSPyUtil.h"

@implementation IgnoreListDialog

@synthesize model;
@synthesize ignoreListTableView;

- (id)initWithPyRef:(PyObject *)aPyRef
{
    self = [super initWithWindowNibName:@"IgnoreListDialog"];
    [self window]; //So the detailsTable is initialized.
    self.model = [[[PyIgnoreListDialog alloc] initWithModel:aPyRef] autorelease];
    [self.model bindCallback:createCallback(@"IgnoreListDialogView", self)];
    ignoreListTable = [[HSTable alloc] initWithPyRef:[model ignoreListTable] tableView:ignoreListTableView];
    [self initializeColumns];
    return self;
}

- (void)dealloc
{
    [ignoreListTable release];
    [super dealloc];
}

- (void)initializeColumns
{
    HSColumnDef defs[] = {
        {@"path1", 240, 40, 0, NO, nil},
        {@"path2", 240, 40, 0, NO, nil},
        nil
    };
    [[ignoreListTable columns] initializeColumns:defs];
    [[ignoreListTable columns] setColumnsAsReadOnly];
}

- (IBAction)removeSelected:(id)sender
{
    [model removeSelected];
}

- (IBAction)clear:(id)sender
{
    [model clear];
}

/* model --> view */
- (void)show
{
    [self showWindow:self];
}
@end