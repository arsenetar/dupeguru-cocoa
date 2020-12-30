/* 
Copyright 2017 Virgil Dupras

This software is licensed under the "GPLv3" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.gnu.org/licenses/gpl-3.0.html
*/

#import "HSErrorReportWindow.h"

@implementation HSErrorReportWindow

@synthesize contentTextView;
@synthesize githubUrl;

+ (void)showErrorReportWithContent:(NSString *)content githubUrl:(NSString *)githubUrl
{
    HSErrorReportWindow *report = [[HSErrorReportWindow alloc] initWithContent:content githubUrl:githubUrl];
    [NSApp runModalForWindow:[report window]];
    [report release];
}

- (id)initWithContent:(NSString *)content githubUrl:(NSString *)aGithubUrl
{
    self = [super initWithWindowNibName:@"ErrorReportWindow"];
    [self window];
    [contentTextView alignLeft:nil];
    [[[contentTextView textStorage] mutableString] setString:content];
    self.githubUrl = aGithubUrl;
    return self;
}

- (IBAction)goToGithub:(id)sender
{
    [[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:self.githubUrl]];
}

- (IBAction)close:(id)sender
{
    [[self window] orderOut:self];
    [NSApp stopModalWithCode:NSOKButton];
}
@end