/* 
   NSScroller.h

   The scroller class

   Copyright (C) 1996 Free Software Foundation, Inc.

   Author:  Scott Christley <scottc@net-community.com>
   Date: 1996
   
   This file is part of the GNUstep GUI Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; see the file COPYING.LIB.
   If not, write to the Free Software Foundation,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/ 

#ifndef _GNUstep_H_NSScroller
#define _GNUstep_H_NSScroller

#include <AppKit/stdappkit.h>
#include <AppKit/NSControl.h>
#include <Foundation/NSCoder.h>

@interface NSScroller : NSControl <NSCoding>

{
  // Attributes
  BOOL is_horizontal;
  SEL action;
  id target;
  float percent;
  float cur_value;

  // Reserved for back-end use
  void *be_scroll_reserved;
}

//
// Laying out the NSScroller 
//
+ (float)scrollerWidth;
- (NSScrollArrowPosition)arrowsPosition;
- (void)checkSpaceForParts;
- (NSRect)rectForPart:(NSScrollerPart)partCode;
- (void)setArrowsPosition:(NSScrollArrowPosition)where;
- (NSUsableScrollerParts)usableParts;

//
// Setting the NSScroller's Values
//

- (float)knobProportion;

- (void)setFloatValue:(float)aFloat
       knobProportion:(float)ratio;

//
// Displaying 
//
- (void)drawArrow:(NSScrollerArrow)whichButton
	highlight:(BOOL)flag;
- (void)drawKnob;
- (void)drawParts;
- (void)highlight:(BOOL)flag;

//
// Handling Events 
//
- (NSScrollerPart)hitPart;
- (NSScrollerPart)testPart:(NSPoint)thePoint;
- (void)trackKnob:(NSEvent *)theEvent;
- (void)trackScrollButtons:(NSEvent *)theEvent;

//
// NSCoding protocol
//
- (void)encodeWithCoder:aCoder;
- initWithCoder:aDecoder;

@end

#endif // _GNUstep_H_NSScroller
