//
//  MutableExtensionRegistry.h
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//

#import "ExtensionRegistry.h"


@protocol PBExtensionField;


@interface PBMutableExtensionRegistry : PBExtensionRegistry

+ (instancetype)registry;

- (void)addExtension:(id<PBExtensionField>)extension;

@end
