/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import "ProblemDialog.h"
#import "Utils.h"

@implementation ProblemDialog

@synthesize model;
@synthesize problemTableView;

- (id)initWithPyRef:(PyObject *)aPyRef
{
    self = [super initWithWindowNibName:@"ProblemDialog"];
    [self window];
    self.model = [[PyProblemDialog alloc] initWithModel:aPyRef];
    problemTable = [[HSTable alloc] initWithPyRef:[self.model problemTable] tableView:problemTableView];
    [self initializeColumns];
    return self;
}

- (void)dealloc
{
    [problemTable release];
    [super dealloc];
}

- (void)initializeColumns
{
    HSColumnDef defs[] = {
        {@"path", 202, 40, 0, NO, nil},
        {@"msg", 228, 40, 0, NO, nil},
        nil
    };
    [[problemTable columns] initializeColumns:defs];
    [[problemTable columns] setColumnsAsReadOnly];
}

- (IBAction)revealSelected:(id)sender
{
    [model revealSelected];
}
@end