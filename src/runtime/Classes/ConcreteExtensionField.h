//
//  ConcreteExtensionField.h
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//

#import <Foundation/Foundation.h>

@protocol PBExtensionField;

typedef NS_ENUM(NSUInteger, PBExtensionType) {
    PBExtensionTypeBool,
    PBExtensionTypeFixed32,
    PBExtensionTypeSFixed32,
    PBExtensionTypeFloat,
    PBExtensionTypeFixed64,
    PBExtensionTypeSFixed64,
    PBExtensionTypeDouble,
    PBExtensionTypeInt32,
    PBExtensionTypeInt64,
    PBExtensionTypeSInt32,
    PBExtensionTypeSInt64,
    PBExtensionTypeUInt32,
    PBExtensionTypeUInt64,
    PBExtensionTypeBytes,
    PBExtensionTypeString,
    PBExtensionTypeMessage,
    PBExtensionTypeGroup,
    PBExtensionTypeEnum,
};

@interface PBConcreteExtensionField : NSObject<PBExtensionField>

+ (instancetype)extensionWithType:(PBExtensionType) type
                     extendedClass:(Class) extendedClass
                       fieldNumber:(int32_t) fieldNumber
                      defaultValue:(id) defaultValue
               messageOrGroupClass:(Class) messageOrGroupClass
                        isRepeated:(BOOL) isRepeated
                          isPacked:(BOOL) isPacked
            isMessageSetWireFormat:(BOOL) isMessageSetWireFormat;

@end
