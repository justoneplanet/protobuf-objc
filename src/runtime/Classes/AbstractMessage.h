//
//  AbstractMessage.h
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//

#import "Message.h"


@interface PBAbstractMessage : NSObject<PBMessage>

/**
 * Writes a string description of the message into the given mutable string
 * respecting a given indent.
 */
- (void)writeDescriptionTo:(NSMutableString*)output
                withIndent:(NSString*)indent;

@end
