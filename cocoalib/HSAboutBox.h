/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import <Cocoa/Cocoa.h>
#import "PyBaseApp.h"

@interface HSAboutBox : NSWindowController
{
    IBOutlet NSTextField *titleTextField;
    IBOutlet NSTextField *versionTextField;
    IBOutlet NSTextField *copyrightTextField;
    
    PyBaseApp *app;
}

@property (readwrite, retain) NSTextField *titleTextField;
@property (readwrite, retain) NSTextField *versionTextField;
@property (readwrite, retain) NSTextField *copyrightTextField;

- (id)initWithApp:(PyBaseApp *)app;
- (void)updateFields;
@end