//
//  AbstractMessage_Builder.m
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//

#import "AbstractMessage_Builder.h"

#import "CodedInputStream.h"
#import "ExtensionRegistry.h"
#import "Message_Builder.h"
#import "UnknownFieldSet.h"
#import "UnknownFieldSet_Builder.h"


@implementation PBAbstractMessage_Builder

- (id<PBMessage_Builder>) clone {
    return nil;
}

- (id<PBMessage_Builder>) clear {
    return nil;
}

- (id<PBMessage_Builder>)mergeFromCodedInputStream:(PBCodedInputStream*)input {
    NSParameterAssert(input);
    
    return [self mergeFromCodedInputStream:input
                         extensionRegistry:[PBExtensionRegistry emptyRegistry]];
}

- (id<PBMessage_Builder>)mergeFromCodedInputStream:(PBCodedInputStream*)input
                                 extensionRegistry:(PBExtensionRegistry*)extensionRegistry {
    return nil;
}

- (id<PBMessage_Builder>)mergeUnknownFields:(PBUnknownFieldSet*)unknownFields {
    NSParameterAssert(unknownFields);
    
    PBUnknownFieldSet* merged =
    [[[PBUnknownFieldSet builderWithUnknownFields:self.unknownFields]
      mergeUnknownFields:unknownFields] build];
    
    [self setUnknownFields:merged];
    return self;
}

- (id<PBMessage_Builder>)mergeFromData:(NSData*)data {
    NSParameterAssert(data);
    
    PBCodedInputStream* input = [PBCodedInputStream streamWithData:data];
    [self mergeFromCodedInputStream:input];
    [input checkLastTagWas:0];
    return self;
}

- (id<PBMessage_Builder>)mergeFromData:(NSData*)data
                     extensionRegistry:(PBExtensionRegistry*)extensionRegistry
{
    NSParameterAssert(data);
    
    PBCodedInputStream* input = [PBCodedInputStream streamWithData:data];
    [self mergeFromCodedInputStream:input extensionRegistry:extensionRegistry];
    [input checkLastTagWas:0];
    return self;
}

- (id<PBMessage_Builder>) mergeFromInputStream:(NSInputStream*)input {
    NSParameterAssert(input);
    
    PBCodedInputStream* codedInput = [PBCodedInputStream streamWithInputStream:input];
    [self mergeFromCodedInputStream:codedInput];
    [codedInput checkLastTagWas:0];
    return self;
}

- (id<PBMessage_Builder>)mergeFromInputStream:(NSInputStream*)input
                            extensionRegistry:(PBExtensionRegistry*)extensionRegistry
{
    NSParameterAssert(input);
    
    PBCodedInputStream* codedInput = [PBCodedInputStream streamWithInputStream:input];
    [self mergeFromCodedInputStream:codedInput extensionRegistry:extensionRegistry];
    [codedInput checkLastTagWas:0];
    return self;
}

- (id<PBMessage>)build {
    return nil;
}

- (id<PBMessage>)buildPartial {
    return nil;
}

- (BOOL) isInitialized {
    return NO;
}

- (id<PBMessage>)defaultInstance {
    return nil;
}

- (PBUnknownFieldSet*)unknownFields {
    return nil;
}

- (id<PBMessage_Builder>)setUnknownFields:(PBUnknownFieldSet*)unknownFields {
    return nil;
}


@end
