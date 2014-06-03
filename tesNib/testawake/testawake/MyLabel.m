//
//  MyLabel.m
//  testawake
//
//  Created by 许英旗 on 13-9-1.
//  Copyright (c) 2013年 许英旗. All rights reserved.
//

#import "MyLabel.h"

@implementation MyLabel

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        NSLog(@"this is MyLabel");
        // Initialization code
    }
    return self;
}

- (void)awakeFromNib
{
    [super awakeFromNib];
    self.text = @"awakFromNib";
    [self sizeToFit];
}
/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

@end
