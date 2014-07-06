//
//  AppDelegate.m
//  OTWebImageDemo
//
//  Created by openthread on 6/7/14.
//  Copyright (c) 2014 openfibers. All rights reserved.
//

#import "AppDelegate.h"
#import "NSImageView+WebCache.h"

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    NSView *windowContentView = self.window.contentView;
    NSImageView *imageView = [[NSImageView alloc] initWithFrame:windowContentView.bounds];
    [imageView setImageURL:[NSURL URLWithString:@"http://p3.music.126.net/xaewG0WYxo0Ry0pw8puIBw==/1907652674296516.jpg"]];
    [windowContentView addSubview:imageView];
}

- (BOOL)applicationShouldHandleReopen:(NSApplication *)theApplication hasVisibleWindows:(BOOL)flag
{
    [self.window makeKeyAndOrderFront:self];
    return YES;
}

@end
