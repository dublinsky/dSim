//
//  AppDelegate.h
//  test
//
//  Created by XuHao on 14-4-11.
//  Copyright (c) 2014年 xuhao. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MyOpenGl.h"
#import "myWin.h"
#include "cocoa_gameCore.h"
#include "cocoa_hil_core.h"
#include "base_gameCore.h"

//#define HIL

@interface AppDelegate : NSObject <NSApplicationDelegate>
@property (unsafe_unretained) IBOutlet myWin *win;
- (IBAction)reset:(id)sender;
@property (weak) IBOutlet NSButton *button0;
@property (weak) IBOutlet NSTextField *text0;
@property (weak) IBOutlet MyOpenGl *opengl;
@property (weak) NSTimer *timer;
#ifdef HIL
@property cocoa_hil_core *core;
#else
@property cocoa_gameCore *core;
#endif
- (IBAction)left:(id)sender;
- (IBAction)right:(id)sender;
- (IBAction)slide:(id)sender;
- (void)update;
@property (weak) IBOutlet NSSlider *Slider0;

@end
