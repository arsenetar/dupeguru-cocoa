/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import <Cocoa/Cocoa.h>
#import "PyPrioritizeDialog.h"
#import "HSPopUpList.h"
#import "HSSelectableList.h"
#import "PrioritizeList.h"
#import "PyDupeGuru.h"

@interface PrioritizeDialog : NSWindowController
{
    IBOutlet NSPopUpButton *categoryPopUpView;
    IBOutlet NSTableView *criteriaTableView;
    IBOutlet NSTableView *prioritizationTableView;
    
    PyPrioritizeDialog *model;
    HSPopUpList *categoryPopUp;
    HSSelectableList *criteriaList;
    PrioritizeList *prioritizationList;
}

@property (readwrite, retain) NSPopUpButton *categoryPopUpView;
@property (readwrite, retain) NSTableView *criteriaTableView;
@property (readwrite, retain) NSTableView *prioritizationTableView;

- (id)initWithApp:(PyDupeGuru *)aApp;
- (PyPrioritizeDialog *)model;

- (IBAction)addSelected:(id)sender;
- (IBAction)removeSelected:(id)sender;
- (IBAction)ok:(id)sender;
- (IBAction)cancel:(id)sender;
@end;