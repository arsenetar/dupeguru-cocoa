/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import <Cocoa/Cocoa.h>
#import "PyDeletionOptions.h"

@interface DeletionOptions : NSWindowController
{
    
    PyDeletionOptions *model;
    
    IBOutlet NSTextField *messageTextField;
    IBOutlet NSButton *linkButton;
    IBOutlet NSMatrix *linkTypeRadio;
    IBOutlet NSButton *directButton;
}

@property (readwrite, retain) NSTextField *messageTextField;
@property (readwrite, retain) NSButton *linkButton;
@property (readwrite, retain) NSMatrix *linkTypeRadio;
@property (readwrite, retain) NSButton *directButton;

- (id)initWithPyRef:(PyObject *)aPyRef;

- (IBAction)updateOptions:(id)sender;
- (IBAction)proceed:(id)sender;
- (IBAction)cancel:(id)sender;
@end