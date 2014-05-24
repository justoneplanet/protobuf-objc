//
//  GeneratedMessage.h
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//

#import "GeneratedMessage.h"

#import "UnknownFieldSet.h"


@interface PBGeneratedMessage ()
@property (strong) PBUnknownFieldSet* unknownFields;
@end


@implementation PBGeneratedMessage

- (instancetype) init {
    self = [super init];
    if (self == nil) {
        return nil;
    }
    
    _unknownFields = [PBUnknownFieldSet defaultInstance];
    _cachedSerializedSize = -1;
    
    return self;
}

+ (instancetype)defaultInstance {
    return nil;
}

- (instancetype)defaultInstance {
    // defined here for autocomplete / type checking rather than id<PBMessage>
    return [[self class] defaultInstance];
}

+ (id<PBMessage_Builder>)builder {
    // required so the parseFromData methods can be moved down into the library
    return nil;
}

+ (instancetype)parseFromData:(NSData*)data {
    NSParameterAssert(data);
    
    return [[[self builder] mergeFromData:data] build];
}

+ (instancetype)parseFromData:(NSData*)data
            extensionRegistry:(PBExtensionRegistry*)extensionRegistry
{
    NSParameterAssert(data);
    
    return [[[self builder] mergeFromData:data
                        extensionRegistry:extensionRegistry] build];
}

+ (instancetype)parseFromInputStream:(NSInputStream*)input {
    NSParameterAssert(input);
    
    return [[[self builder] mergeFromInputStream:input] build];
}

+ (instancetype)parseFromInputStream:(NSInputStream*)input
                   extensionRegistry:(PBExtensionRegistry*)extensionRegistry
{
    NSParameterAssert(input);
    
    return [[[self builder] mergeFromInputStream:input
                               extensionRegistry:extensionRegistry] build];
}

+ (instancetype)parseFromCodedInputStream:(PBCodedInputStream*)input {
    NSParameterAssert(input);
    
    return [[[self builder] mergeFromCodedInputStream:input] build];
}

+ (instancetype)parseFromCodedInputStream:(PBCodedInputStream*)input
                        extensionRegistry:(PBExtensionRegistry*)extensionRegistry
{
    NSParameterAssert(input);
    
    return [[[self builder] mergeFromCodedInputStream:input
                                    extensionRegistry:extensionRegistry] build];
}


@end
