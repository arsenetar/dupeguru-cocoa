/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import <Cocoa/Cocoa.h>
#import "DetailsPanel.h"
#import "PyDupeGuru.h"

@interface DetailsPanelPicture : DetailsPanel
{
    IBOutlet NSImageView *dupeImage;
    IBOutlet NSProgressIndicator *dupeProgressIndicator;
    IBOutlet NSImageView *refImage;
    IBOutlet NSProgressIndicator *refProgressIndicator;
    
    PyDupeGuru *pyApp;
    BOOL _needsRefresh;
    NSString *_dupePath;
    NSString *_refPath;
}

@property (readwrite, retain) NSImageView *dupeImage;
@property (readwrite, retain) NSProgressIndicator *dupeProgressIndicator;
@property (readwrite, retain) NSImageView *refImage;
@property (readwrite, retain) NSProgressIndicator *refProgressIndicator;

- (id)initWithApp:(PyDupeGuru *)aApp;
@end