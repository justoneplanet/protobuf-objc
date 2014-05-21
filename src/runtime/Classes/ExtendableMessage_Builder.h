//
//  ExtendableMessage_Builder.h
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//

#import "GeneratedMessage_Builder.h"


@class PBExtendableMessage;
@protocol PBExtensionField;


@interface PBExtendableMessage_Builder : PBGeneratedMessage_Builder

- (id)getExtension:(id<PBExtensionField>) extension;

- (BOOL)hasExtension:(id<PBExtensionField>) extension;

- (instancetype)setExtension:(id<PBExtensionField>)extension
                                        value:(id)value;

- (instancetype)addExtension:(id<PBExtensionField>)extension
                                        value:(id)value;

- (instancetype)setExtension:(id<PBExtensionField>)extension
                                        index:(int32_t)index
                                        value:(id)value;

- (instancetype)clearExtension:(id<PBExtensionField>)extension;

/* @protected */
- (void)mergeExtensionFields:(PBExtendableMessage*) other;

@end
