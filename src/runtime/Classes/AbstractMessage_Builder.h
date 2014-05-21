//
//  AbstractMessage_Builder.h
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//

#import "Message_Builder.h"

/**
 * A partial implementation of the {@link Message.Builder} interface which
 * implements as many methods of that interface as possible in terms of
 * other methods.
 */
@interface PBAbstractMessage_Builder : NSObject<PBMessage_Builder>

@end
