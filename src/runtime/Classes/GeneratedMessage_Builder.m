//
//  GeneratedMessage_Builder.h
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//

#import "GeneratedMessage_Builder.h"

#import "GeneratedMessage.h"
#import "Message.h"
#import "Message_Builder.h"
#import "UnknownFieldSet.h"
#import "UnknownFieldSet_Builder.h"


@interface PBGeneratedMessage ()
@property (strong) PBUnknownFieldSet* unknownFields;
@end


@implementation PBGeneratedMessage_Builder

- (instancetype)clear {
    return nil;
}

- (instancetype)clone {
    return nil;
}

- (instancetype)mergeFromCodedInputStream:(PBCodedInputStream*)input {
    return nil;
}

- (instancetype)mergeFromCodedInputStream:(PBCodedInputStream*)input
                        extensionRegistry:(PBExtensionRegistry*)extensionRegistry {
    return nil;
}

/**
 * Get the message being built.  We don't just pass this to the
 * constructor because it becomes null when build() is called.
 */
- (PBGeneratedMessage*)internalGetResult {
    return nil;
}

- (void)checkInitialized {
    PBGeneratedMessage* result = self.internalGetResult;
    if (result != nil && !result.isInitialized) {
        // Error
        return;
    }
}

- (PBUnknownFieldSet*)unknownFields {
    return self.internalGetResult.unknownFields;
}

- (id<PBMessage_Builder>)setUnknownFields:(PBUnknownFieldSet*)unknownFields {
    self.internalGetResult.unknownFields = unknownFields;
    return self;
}

- (id<PBMessage_Builder>)mergeUnknownFields:(PBUnknownFieldSet*)unknownFields {
    NSParameterAssert(unknownFields);
    
    PBGeneratedMessage* result = self.internalGetResult;
    result.unknownFields =
    [[[PBUnknownFieldSet builderWithUnknownFields:result.unknownFields]
      mergeUnknownFields:unknownFields] build];
    return self;
}

- (BOOL)isInitialized {
    return self.internalGetResult.isInitialized;
}

/**
 * Called by subclasses to parse an unknown field.
 * @return {@code YES} unless the tag is an end-group tag.
 */
- (BOOL) parseUnknownField:(PBCodedInputStream*)input
             unknownFields:(PBUnknownFieldSet_Builder*)unknownFields
         extensionRegistry:(PBExtensionRegistry*)extensionRegistry
                       tag:(int32_t)tag
{
    NSParameterAssert(input);
    NSParameterAssert(unknownFields);
    
    return [unknownFields mergeFieldFrom:tag input:input];
}

- (void)checkInitializedParsed {
    PBGeneratedMessage* result = self.internalGetResult;
    if (result != nil && !result.isInitialized) {
        // Error
        return;
    }
}


@end
