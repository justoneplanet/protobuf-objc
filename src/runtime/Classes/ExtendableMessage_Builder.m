//
//  ExtendableMessage_Builder.m
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//

#import "ExtendableMessage_Builder.h"

#import "ExtensionField.h"
#import "ExtendableMessage.h"
#import "ExtensionRegistry.h"
#import "WireFormat.h"


/**
 * Generated message builders for message types that contain extension ranges
 * subclass this.
 *
 * <p>This class implements type-safe accessors for extensions.  They
 * implement all the same operations that you can do with normal fields --
 * e.g. "get", "set", and "add" -- but for extensions.  The extensions are
 * identified using instances of the class {@link GeneratedExtension}; the
 * protocol compiler generates a static instance of this class for every
 * extension in its input.  Through the magic of generics, all is made
 * type-safe.
 *
 * <p>For example, imagine you have the {@code .proto} file:
 *
 * <pre>
 * option java_class = "MyProto";
 *
 * message Foo {
 *   extensions 1000 to max;
 * }
 *
 * extend Foo {
 *   optional int32 bar;
 * }
 * </pre>
 *
 * <p>Then you might write code like:
 *
 * <pre>
 * MyProto.Foo foo =
 *   MyProto.Foo.newBuilder()
 *     .setExtension(MyProto.bar, 123)
 *     .build();
 * </pre>
 *
 * <p>See also {@link ExtendableMessage}.
 */


@implementation PBExtendableMessage_Builder

- (PBExtendableMessage*)internalGetResult {
    return nil;
}

/**
 * Called by subclasses to parse an unknown field or an extension.
 * @return {@code YES} unless the tag is an end-group tag.
 */
- (BOOL)parseUnknownField:(PBCodedInputStream*)input
            unknownFields:(PBUnknownFieldSet_Builder*)unknownFields
        extensionRegistry:(PBExtensionRegistry*) extensionRegistry
                      tag:(int32_t)tag
{
    NSParameterAssert(input);
    NSParameterAssert(unknownFields);
    
    PBExtendableMessage* message = [self internalGetResult];
    int32_t wireType = PBWireFormatGetTagWireType(tag);
    int32_t fieldNumber = PBWireFormatGetTagFieldNumber(tag);
    
    id<PBExtensionField> extension = [extensionRegistry getExtension:[message class]
                                                         fieldNumber:fieldNumber];
    
    if (extension != nil) {
        if ([extension wireType] == wireType) {
            [extension mergeFromCodedInputStream:input
                                   unknownFields:unknownFields
                               extensionRegistry:extensionRegistry
                                         builder:self
                                             tag:tag];
            return YES;
        }
    }
    
    return [super parseUnknownField:input unknownFields:unknownFields extensionRegistry:extensionRegistry tag:tag];
}


- (id)getExtension:(id<PBExtensionField>)extension {
    NSParameterAssert(extension);
    return [[self internalGetResult] getExtension:extension];
}


- (BOOL)hasExtension:(id<PBExtensionField>)extension {
    NSParameterAssert(extension);
    return [[self internalGetResult] hasExtension:extension];
}


- (instancetype)setExtension:(id<PBExtensionField>)extension
                       value:(id) value
{
    NSParameterAssert(extension);
    
    PBExtendableMessage* message = [self internalGetResult];
    [message ensureExtensionIsRegistered:extension];
    
    if ([extension isRepeated]) {
        // Must call addExtension() for repeated types.
        return nil;
    }
    
    if (message.extensionMap == nil) {
        message.extensionMap = [NSMutableDictionary dictionary];
    }
    [message.extensionMap setObject:value forKey:[NSNumber numberWithInt:[extension fieldNumber]]];
    return self;
}


- (instancetype)addExtension:(id<PBExtensionField>)extension
                       value:(id) value
{
    NSParameterAssert(extension);
    
    PBExtendableMessage* message = [self internalGetResult];
    [message ensureExtensionIsRegistered:extension];
    
    if (![extension isRepeated]) {
        // Must call setExtension() for singular types.
        return nil;
    }
    
    if (message.extensionMap == nil) {
        message.extensionMap = [NSMutableDictionary dictionary];
    }
    NSNumber* fieldNumber = [NSNumber numberWithInt:[extension fieldNumber]];
    NSMutableArray* list = [message.extensionMap objectForKey:fieldNumber];
    if (list == nil) {
        list = [NSMutableArray array];
        [message.extensionMap setObject:list forKey:fieldNumber];
    }
    
    [list addObject:value];
    return self;
}


- (instancetype)setExtension:(id<PBExtensionField>)extension
                       index:(int32_t) index
                       value:(id) value
{
    NSParameterAssert(extension);
    
    PBExtendableMessage* message = [self internalGetResult];
    [message ensureExtensionIsRegistered:extension];
    
    if (![extension isRepeated]) {
        // Must call setExtension() for singular types.
        return nil;
    }
    
    if (message.extensionMap == nil) {
        message.extensionMap = [NSMutableDictionary dictionary];
    }
    
    NSNumber* fieldNumber = [NSNumber numberWithInt:[extension fieldNumber]];
    NSMutableArray* list = [message.extensionMap objectForKey:fieldNumber];
    
    [list replaceObjectAtIndex:index withObject:value];
    
    return self;
}


- (instancetype)clearExtension:(id<PBExtensionField>)extension {
    NSParameterAssert(extension);
    
    PBExtendableMessage* message = [self internalGetResult];
    [message ensureExtensionIsRegistered:extension];
    [message.extensionMap removeObjectForKey:[NSNumber numberWithInt:[extension fieldNumber]]];
    
    return self;
}

- (void)mergeExtensionFields:(PBExtendableMessage*)other {
    NSParameterAssert(other);
    
    PBExtendableMessage* thisMessage = [self internalGetResult];
    if ([thisMessage class] != [other class]) {
        NSAssert(NO, @"Cannot merge extensions from a different type");
    }
    
    if (other.extensionMap.count > 0) {
        if (thisMessage.extensionMap == nil) {
            thisMessage.extensionMap = [NSMutableDictionary dictionary];
        }
        
        NSDictionary* registry = other.extensionRegistry;
        for (NSNumber* fieldNumber in other.extensionMap) {
            id<PBExtensionField> thisField = [registry objectForKey:fieldNumber];
            id value = [other.extensionMap objectForKey:fieldNumber];
            
            if ([thisField isRepeated]) {
                NSMutableArray* list = [thisMessage.extensionMap objectForKey:fieldNumber];
                if (list == nil) {
                    list = [NSMutableArray array];
                    [thisMessage.extensionMap setObject:list forKey:fieldNumber];
                }
                
                [list addObjectsFromArray:value];
            } else {
                [thisMessage.extensionMap setObject:value forKey:fieldNumber];
            }
        }
    }
}


@end
