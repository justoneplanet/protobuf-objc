//
//  AbstractMessage.m
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//

#import "AbstractMessage.h"

#import "CodedOutputStream.h"


/**
 * A partial implementation of the {@link Message} interface which implements
 * as many methods of that interface as possible in terms of other methods.
 *
 * @author Cyrus Najmabadi
 */


@implementation PBAbstractMessage

- (instancetype)init {
    if ((self = [super init])) {
    }
    
    return self;
}

- (NSData*)data {
    NSMutableData* data = [NSMutableData dataWithLength:self.serializedSize];
    PBCodedOutputStream* stream = [PBCodedOutputStream streamWithData:data];
    [self writeToCodedOutputStream:stream];
    return data;
}

- (BOOL)isInitialized {
    return NO;
}

- (int32_t)serializedSize {
    NSAssert(NO, @"serializedSize not implemented in subclass.");
    return -1;
}

- (void) writeToCodedOutputStream:(PBCodedOutputStream*)output {
    // not implemented in this base class
}

- (void)writeToOutputStream:(NSOutputStream*)output {
    NSParameterAssert(output);
    
    PBCodedOutputStream* codedOutput = [PBCodedOutputStream streamWithOutputStream:output];
    [self writeToCodedOutputStream:codedOutput];
    [codedOutput flush];
}

- (id<PBMessage>)defaultInstance {
    return nil;
}

- (PBUnknownFieldSet*)unknownFields {
    return nil;
}

- (id<PBMessage_Builder>)builder {
    return nil;
}

- (id<PBMessage_Builder>)toBuilder {
    return nil;
}

- (void)writeDescriptionTo:(NSMutableString*) output
                withIndent:(NSString*) indent {
    // not implemented in this base class
}

- (NSString*)description {
    NSMutableString* output = [NSMutableString string];
    [self writeDescriptionTo:output withIndent:@""];
    return output;
}


@end
