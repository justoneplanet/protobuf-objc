//
//  ExtensionRegistry.h
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//


@protocol PBExtensionField;


@interface PBExtensionRegistry : NSObject {
@protected
    NSDictionary *_classMap;
}

+ (instancetype)emptyRegistry;
- (id<PBExtensionField>)getExtension:(Class)aClass fieldNumber:(NSInteger)fieldNumber;

/* @protected */
- (instancetype)initWithClassMap:(NSDictionary*)classMap;
- (id) keyForClass:(Class)aClass;

@end
