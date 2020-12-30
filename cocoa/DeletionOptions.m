/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import "DeletionOptions.h"
#import "HSPyUtil.h"

@implementation DeletionOptions

@synthesize messageTextField;
@synthesize linkButton;
@synthesize linkTypeRadio;
@synthesize directButton;

- (id)initWithPyRef:(PyObject *)aPyRef
{
    self = [super initWithWindowNibName:@"DeletionOptions"];
    [self window];
    model = [[PyDeletionOptions alloc] initWithModel:aPyRef];
    [model bindCallback:createCallback(@"DeletionOptionsView", self)];
    return self;
}

- (void)dealloc
{
    [model release];
    [super dealloc];
}

- (IBAction)updateOptions:(id)sender
{
    [model setLinkDeleted:[linkButton state] == NSControlStateValueOn];
    [model setUseHardlinks:[linkTypeRadio selectedColumn] == 1];
    [model setDirect:[directButton state] == NSControlStateValueOn];
}

- (IBAction)proceed:(id)sender
{
    [NSApp stopModalWithCode:NSModalResponseOK];
}

- (IBAction)cancel:(id)sender
{
    [NSApp stopModalWithCode:NSModalResponseCancel];
}

/* model --> view */
- (void)updateMsg:(NSString *)msg
{
    [messageTextField setStringValue:msg];
}

- (BOOL)show
{
    [linkButton setState:NSControlStateValueOff];
    [directButton setState:NSControlStateValueOff];
    [linkTypeRadio selectCellAtRow:0 column:0];
    NSInteger r = [NSApp runModalForWindow:[self window]];
    [[self window] close];
    return r == NSModalResponseOK;
}

- (void)setHardlinkOptionEnabled:(BOOL)enabled
{
    [linkTypeRadio setEnabled:enabled];
}
@end
