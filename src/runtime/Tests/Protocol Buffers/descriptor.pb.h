//
// descriptor.pb.h
// 
// Generated by the objc protocol buffer compiler plugin.  DO NOT EDIT!
// source: google/protobuf/descriptor.proto
//

#import <Foundation/Foundation.h>

#import <ProtocolModels/ProtocolModels.h>

// @@protoc_insertion_point(imports)

@class PBDescriptorProto;
@class PBDescriptorProto_Builder;
@class PBDescriptorProto_ExtensionRange;
@class PBDescriptorProto_ExtensionRange_Builder;
@class PBEnumDescriptorProto;
@class PBEnumDescriptorProto_Builder;
@class PBEnumOptions;
@class PBEnumOptions_Builder;
@class PBEnumValueDescriptorProto;
@class PBEnumValueDescriptorProto_Builder;
@class PBEnumValueOptions;
@class PBEnumValueOptions_Builder;
@class PBFieldDescriptorProto;
@class PBFieldDescriptorProto_Builder;
@class PBFieldOptions;
@class PBFieldOptions_Builder;
@class PBFileDescriptorProto;
@class PBFileDescriptorProto_Builder;
@class PBFileDescriptorSet;
@class PBFileDescriptorSet_Builder;
@class PBFileOptions;
@class PBFileOptions_Builder;
@class PBMessageOptions;
@class PBMessageOptions_Builder;
@class PBMethodDescriptorProto;
@class PBMethodDescriptorProto_Builder;
@class PBMethodOptions;
@class PBMethodOptions_Builder;
@class PBServiceDescriptorProto;
@class PBServiceDescriptorProto_Builder;
@class PBServiceOptions;
@class PBServiceOptions_Builder;
@class PBSourceCodeInfo;
@class PBSourceCodeInfo_Builder;
@class PBSourceCodeInfo_Location;
@class PBSourceCodeInfo_Location_Builder;
@class PBUninterpretedOption;
@class PBUninterpretedOption_Builder;
@class PBUninterpretedOption_NamePart;
@class PBUninterpretedOption_NamePart_Builder;

#ifndef __has_feature
  #define __has_feature(x) 0 // Compatibility with non-clang compilers.
#endif // __has_feature

#ifndef NS_RETURNS_NOT_RETAINED
  #if __has_feature(attribute_ns_returns_not_retained)
    #define NS_RETURNS_NOT_RETAINED __attribute__((ns_returns_not_retained))
  #else
    #define NS_RETURNS_NOT_RETAINED
  #endif
#endif

typedef NS_ENUM(NSInteger, PBFieldDescriptorProto_Type) {
  PBFieldDescriptorProto_TypeTYPEDOUBLE = 1,
  PBFieldDescriptorProto_TypeTYPEFLOAT = 2,
  PBFieldDescriptorProto_TypeTYPEINT64 = 3,
  PBFieldDescriptorProto_TypeTYPEUINT64 = 4,
  PBFieldDescriptorProto_TypeTYPEINT32 = 5,
  PBFieldDescriptorProto_TypeTYPEFIXED64 = 6,
  PBFieldDescriptorProto_TypeTYPEFIXED32 = 7,
  PBFieldDescriptorProto_TypeTYPEBOOL = 8,
  PBFieldDescriptorProto_TypeTYPESTRING = 9,
  PBFieldDescriptorProto_TypeTYPEGROUP = 10,
  PBFieldDescriptorProto_TypeTYPEMESSAGE = 11,
  PBFieldDescriptorProto_TypeTYPEBYTES = 12,
  PBFieldDescriptorProto_TypeTYPEUINT32 = 13,
  PBFieldDescriptorProto_TypeTYPEENUM = 14,
  PBFieldDescriptorProto_TypeTYPESFIXED32 = 15,
  PBFieldDescriptorProto_TypeTYPESFIXED64 = 16,
  PBFieldDescriptorProto_TypeTYPESINT32 = 17,
  PBFieldDescriptorProto_TypeTYPESINT64 = 18,
};

BOOL PBFieldDescriptorProto_TypeIsValidValue(PBFieldDescriptorProto_Type value);

typedef NS_ENUM(NSInteger, PBFieldDescriptorProto_Label) {
  PBFieldDescriptorProto_LabelLABELOPTIONAL = 1,
  PBFieldDescriptorProto_LabelLABELREQUIRED = 2,
  PBFieldDescriptorProto_LabelLABELREPEATED = 3,
};

BOOL PBFieldDescriptorProto_LabelIsValidValue(PBFieldDescriptorProto_Label value);

typedef NS_ENUM(NSInteger, PBFileOptions_OptimizeMode) {
  PBFileOptions_OptimizeModeSPEED = 1,
  PBFileOptions_OptimizeModeCODESIZE = 2,
  PBFileOptions_OptimizeModeLITERUNTIME = 3,
};

BOOL PBFileOptions_OptimizeModeIsValidValue(PBFileOptions_OptimizeMode value);

typedef NS_ENUM(NSInteger, PBFieldOptions_CType) {
  PBFieldOptions_CTypeSTRING = 0,
  PBFieldOptions_CTypeCORD = 1,
  PBFieldOptions_CTypeSTRINGPIECE = 2,
};

BOOL PBFieldOptions_CTypeIsValidValue(PBFieldOptions_CType value);


@interface PBDescriptorRoot : NSObject {
}
+ (PBExtensionRegistry*) extensionRegistry;
+ (void) registerAllExtensions:(PBMutableExtensionRegistry*)registry;
@end


#pragma mark - PBFileDescriptorSet

@interface PBFileDescriptorSet : PBGeneratedMessage

@property (readonly, strong) NSArray *file;


- (PBFileDescriptorProto*)fileAtIndex:(NSUInteger)index;

- (PBFileDescriptorSet_Builder*)builder;
+ (PBFileDescriptorSet_Builder*)builder;
+ (PBFileDescriptorSet_Builder*)builderWithPrototype:(PBFileDescriptorSet*)prototype;
- (PBFileDescriptorSet_Builder*)toBuilder;

@end


@interface PBFileDescriptorSet_Builder : PBGeneratedMessage_Builder

- (PBFileDescriptorSet*)defaultMessageInstance;

- (PBFileDescriptorSet*)build;
- (PBFileDescriptorSet*)buildPartial;

- (instancetype)mergeFrom:(PBFileDescriptorSet*)other;

- (NSMutableArray *)file;
- (PBFileDescriptorProto*)fileAtIndex:(NSUInteger)index;
- (instancetype)addFile:(PBFileDescriptorProto*)value;
- (instancetype)setFileArray:(NSArray *)array;
- (instancetype)clearFile;

@end


#pragma mark - PBFileDescriptorProto

@interface PBFileDescriptorProto : PBGeneratedMessage

@property (readonly, strong) NSString * name;
@property (readonly, strong) NSString * package;
@property (readonly, strong) NSArray * dependency;
@property (readonly, strong) PBArray * publicDependency;
@property (readonly, strong) PBArray * weakDependency;
@property (readonly, strong) NSArray *messageType;
@property (readonly, strong) NSArray *enumType;
@property (readonly, strong) NSArray *service;
@property (readonly, strong) NSArray *extension;
@property (readonly, strong)  PBFileOptions* options;
@property (readonly, strong)  PBSourceCodeInfo* sourceCodeInfo;

- (BOOL)hasName;
- (BOOL)hasPackage;
- (BOOL)hasOptions;
- (BOOL)hasSourceCodeInfo;

- (NSString *)dependencyAtIndex:(NSUInteger)index;
- (int32_t)publicDependencyAtIndex:(NSUInteger)index;
- (int32_t)weakDependencyAtIndex:(NSUInteger)index;
- (PBDescriptorProto*)messageTypeAtIndex:(NSUInteger)index;
- (PBEnumDescriptorProto*)enumTypeAtIndex:(NSUInteger)index;
- (PBServiceDescriptorProto*)serviceAtIndex:(NSUInteger)index;
- (PBFieldDescriptorProto*)extensionAtIndex:(NSUInteger)index;

- (PBFileDescriptorProto_Builder*)builder;
+ (PBFileDescriptorProto_Builder*)builder;
+ (PBFileDescriptorProto_Builder*)builderWithPrototype:(PBFileDescriptorProto*)prototype;
- (PBFileDescriptorProto_Builder*)toBuilder;

@end


@interface PBFileDescriptorProto_Builder : PBGeneratedMessage_Builder

- (PBFileDescriptorProto*)defaultMessageInstance;

- (PBFileDescriptorProto*)build;
- (PBFileDescriptorProto*)buildPartial;

- (instancetype)mergeFrom:(PBFileDescriptorProto*)other;

- (BOOL)hasName;
- (NSString *)name;
- (instancetype)setName:(NSString *) value;
- (instancetype)clearName;

- (BOOL)hasPackage;
- (NSString *)package;
- (instancetype)setPackage:(NSString *) value;
- (instancetype)clearPackage;

- (NSArray *)dependency;
- (NSString *)dependencyAtIndex:(NSUInteger)index;
- (instancetype)addDependency:(NSString *)value;
- (instancetype)setDependencyArray:(NSArray *)array;
- (instancetype)clearDependency;

- (PBAppendableArray *)publicDependency;
- (int32_t)publicDependencyAtIndex:(NSUInteger)index;
- (instancetype)addPublicDependency:(int32_t)value;
- (instancetype)setPublicDependencyArray:(NSArray *)array;
- (instancetype)setPublicDependencyValues:(const int32_t *)values count:(NSUInteger)count;
- (instancetype)clearPublicDependency;

- (PBAppendableArray *)weakDependency;
- (int32_t)weakDependencyAtIndex:(NSUInteger)index;
- (instancetype)addWeakDependency:(int32_t)value;
- (instancetype)setWeakDependencyArray:(NSArray *)array;
- (instancetype)setWeakDependencyValues:(const int32_t *)values count:(NSUInteger)count;
- (instancetype)clearWeakDependency;

- (NSMutableArray *)messageType;
- (PBDescriptorProto*)messageTypeAtIndex:(NSUInteger)index;
- (instancetype)addMessageType:(PBDescriptorProto*)value;
- (instancetype)setMessageTypeArray:(NSArray *)array;
- (instancetype)clearMessageType;

- (NSMutableArray *)enumType;
- (PBEnumDescriptorProto*)enumTypeAtIndex:(NSUInteger)index;
- (instancetype)addEnumType:(PBEnumDescriptorProto*)value;
- (instancetype)setEnumTypeArray:(NSArray *)array;
- (instancetype)clearEnumType;

- (NSMutableArray *)service;
- (PBServiceDescriptorProto*)serviceAtIndex:(NSUInteger)index;
- (instancetype)addService:(PBServiceDescriptorProto*)value;
- (instancetype)setServiceArray:(NSArray *)array;
- (instancetype)clearService;

- (NSMutableArray *)extension;
- (PBFieldDescriptorProto*)extensionAtIndex:(NSUInteger)index;
- (instancetype)addExtension:(PBFieldDescriptorProto*)value;
- (instancetype)setExtensionArray:(NSArray *)array;
- (instancetype)clearExtension;

- (BOOL)hasOptions;
- (PBFileOptions*)options;
- (instancetype)setOptions:(PBFileOptions*)value;
- (instancetype)setOptionsBuilder:(PBFileOptions_Builder*)builderForValue;
- (instancetype)mergeOptions:(PBFileOptions*)value;
- (instancetype)clearOptions;

- (BOOL)hasSourceCodeInfo;
- (PBSourceCodeInfo*)sourceCodeInfo;
- (instancetype)setSourceCodeInfo:(PBSourceCodeInfo*)value;
- (instancetype)setSourceCodeInfoBuilder:(PBSourceCodeInfo_Builder*)builderForValue;
- (instancetype)mergeSourceCodeInfo:(PBSourceCodeInfo*)value;
- (instancetype)clearSourceCodeInfo;

@end


#pragma mark - PBDescriptorProto

@interface PBDescriptorProto : PBGeneratedMessage

@property (readonly, strong) NSString * name;
@property (readonly, strong) NSArray *field;
@property (readonly, strong) NSArray *extension;
@property (readonly, strong) NSArray *nestedType;
@property (readonly, strong) NSArray *enumType;
@property (readonly, strong) NSArray *extensionRange;
@property (readonly, strong)  PBMessageOptions* options;

- (BOOL)hasName;
- (BOOL)hasOptions;

- (PBFieldDescriptorProto*)fieldAtIndex:(NSUInteger)index;
- (PBFieldDescriptorProto*)extensionAtIndex:(NSUInteger)index;
- (PBDescriptorProto*)nestedTypeAtIndex:(NSUInteger)index;
- (PBEnumDescriptorProto*)enumTypeAtIndex:(NSUInteger)index;
- (PBDescriptorProto_ExtensionRange*)extensionRangeAtIndex:(NSUInteger)index;

- (PBDescriptorProto_Builder*)builder;
+ (PBDescriptorProto_Builder*)builder;
+ (PBDescriptorProto_Builder*)builderWithPrototype:(PBDescriptorProto*)prototype;
- (PBDescriptorProto_Builder*)toBuilder;

@end


@interface PBDescriptorProto_Builder : PBGeneratedMessage_Builder

- (PBDescriptorProto*)defaultMessageInstance;

- (PBDescriptorProto*)build;
- (PBDescriptorProto*)buildPartial;

- (instancetype)mergeFrom:(PBDescriptorProto*)other;

- (BOOL)hasName;
- (NSString *)name;
- (instancetype)setName:(NSString *) value;
- (instancetype)clearName;

- (NSMutableArray *)field;
- (PBFieldDescriptorProto*)fieldAtIndex:(NSUInteger)index;
- (instancetype)addField:(PBFieldDescriptorProto*)value;
- (instancetype)setFieldArray:(NSArray *)array;
- (instancetype)clearField;

- (NSMutableArray *)extension;
- (PBFieldDescriptorProto*)extensionAtIndex:(NSUInteger)index;
- (instancetype)addExtension:(PBFieldDescriptorProto*)value;
- (instancetype)setExtensionArray:(NSArray *)array;
- (instancetype)clearExtension;

- (NSMutableArray *)nestedType;
- (PBDescriptorProto*)nestedTypeAtIndex:(NSUInteger)index;
- (instancetype)addNestedType:(PBDescriptorProto*)value;
- (instancetype)setNestedTypeArray:(NSArray *)array;
- (instancetype)clearNestedType;

- (NSMutableArray *)enumType;
- (PBEnumDescriptorProto*)enumTypeAtIndex:(NSUInteger)index;
- (instancetype)addEnumType:(PBEnumDescriptorProto*)value;
- (instancetype)setEnumTypeArray:(NSArray *)array;
- (instancetype)clearEnumType;

- (NSMutableArray *)extensionRange;
- (PBDescriptorProto_ExtensionRange*)extensionRangeAtIndex:(NSUInteger)index;
- (instancetype)addExtensionRange:(PBDescriptorProto_ExtensionRange*)value;
- (instancetype)setExtensionRangeArray:(NSArray *)array;
- (instancetype)clearExtensionRange;

- (BOOL)hasOptions;
- (PBMessageOptions*)options;
- (instancetype)setOptions:(PBMessageOptions*)value;
- (instancetype)setOptionsBuilder:(PBMessageOptions_Builder*)builderForValue;
- (instancetype)mergeOptions:(PBMessageOptions*)value;
- (instancetype)clearOptions;

@end


#pragma mark - PBDescriptorProto_ExtensionRange

@interface PBDescriptorProto_ExtensionRange : PBGeneratedMessage

@property (readonly) int32_t start;
@property (readonly) int32_t end;

- (BOOL)hasStart;
- (BOOL)hasEnd;


- (PBDescriptorProto_ExtensionRange_Builder*)builder;
+ (PBDescriptorProto_ExtensionRange_Builder*)builder;
+ (PBDescriptorProto_ExtensionRange_Builder*)builderWithPrototype:(PBDescriptorProto_ExtensionRange*)prototype;
- (PBDescriptorProto_ExtensionRange_Builder*)toBuilder;

@end


@interface PBDescriptorProto_ExtensionRange_Builder : PBGeneratedMessage_Builder

- (PBDescriptorProto_ExtensionRange*)defaultMessageInstance;

- (PBDescriptorProto_ExtensionRange*)build;
- (PBDescriptorProto_ExtensionRange*)buildPartial;

- (instancetype)mergeFrom:(PBDescriptorProto_ExtensionRange*)other;

- (BOOL)hasStart;
- (int32_t)start;
- (instancetype)setStart:(int32_t) value;
- (instancetype)clearStart;

- (BOOL)hasEnd;
- (int32_t)end;
- (instancetype)setEnd:(int32_t) value;
- (instancetype)clearEnd;

@end


#pragma mark - PBFieldDescriptorProto

@interface PBFieldDescriptorProto : PBGeneratedMessage

@property (readonly, strong) NSString * name;
@property (readonly) int32_t number;
@property (readonly) PBFieldDescriptorProto_Label label;
@property (readonly) PBFieldDescriptorProto_Type type;
@property (readonly, strong) NSString * typeName;
@property (readonly, strong) NSString * extendee;
@property (readonly, strong) NSString * defaultValue;
@property (readonly, strong)  PBFieldOptions* options;

- (BOOL)hasName;
- (BOOL)hasNumber;
- (BOOL)hasLabel;
- (BOOL)hasType;
- (BOOL)hasTypeName;
- (BOOL)hasExtendee;
- (BOOL)hasDefaultValue;
- (BOOL)hasOptions;


- (PBFieldDescriptorProto_Builder*)builder;
+ (PBFieldDescriptorProto_Builder*)builder;
+ (PBFieldDescriptorProto_Builder*)builderWithPrototype:(PBFieldDescriptorProto*)prototype;
- (PBFieldDescriptorProto_Builder*)toBuilder;

@end


@interface PBFieldDescriptorProto_Builder : PBGeneratedMessage_Builder

- (PBFieldDescriptorProto*)defaultMessageInstance;

- (PBFieldDescriptorProto*)build;
- (PBFieldDescriptorProto*)buildPartial;

- (instancetype)mergeFrom:(PBFieldDescriptorProto*)other;

- (BOOL)hasName;
- (NSString *)name;
- (instancetype)setName:(NSString *) value;
- (instancetype)clearName;

- (BOOL)hasNumber;
- (int32_t)number;
- (instancetype)setNumber:(int32_t) value;
- (instancetype)clearNumber;

- (BOOL)hasLabel;
- (PBFieldDescriptorProto_Label)label;
- (instancetype)setLabel:(PBFieldDescriptorProto_Label)value;
- (instancetype)clearLabel;

- (BOOL)hasType;
- (PBFieldDescriptorProto_Type)type;
- (instancetype)setType:(PBFieldDescriptorProto_Type)value;
- (instancetype)clearType;

- (BOOL)hasTypeName;
- (NSString *)typeName;
- (instancetype)setTypeName:(NSString *) value;
- (instancetype)clearTypeName;

- (BOOL)hasExtendee;
- (NSString *)extendee;
- (instancetype)setExtendee:(NSString *) value;
- (instancetype)clearExtendee;

- (BOOL)hasDefaultValue;
- (NSString *)defaultValue;
- (instancetype)setDefaultValue:(NSString *) value;
- (instancetype)clearDefaultValue;

- (BOOL)hasOptions;
- (PBFieldOptions*)options;
- (instancetype)setOptions:(PBFieldOptions*)value;
- (instancetype)setOptionsBuilder:(PBFieldOptions_Builder*)builderForValue;
- (instancetype)mergeOptions:(PBFieldOptions*)value;
- (instancetype)clearOptions;

@end


#pragma mark - PBEnumDescriptorProto

@interface PBEnumDescriptorProto : PBGeneratedMessage

@property (readonly, strong) NSString * name;
@property (readonly, strong) NSArray *value;
@property (readonly, strong)  PBEnumOptions* options;

- (BOOL)hasName;
- (BOOL)hasOptions;

- (PBEnumValueDescriptorProto*)valueAtIndex:(NSUInteger)index;

- (PBEnumDescriptorProto_Builder*)builder;
+ (PBEnumDescriptorProto_Builder*)builder;
+ (PBEnumDescriptorProto_Builder*)builderWithPrototype:(PBEnumDescriptorProto*)prototype;
- (PBEnumDescriptorProto_Builder*)toBuilder;

@end


@interface PBEnumDescriptorProto_Builder : PBGeneratedMessage_Builder

- (PBEnumDescriptorProto*)defaultMessageInstance;

- (PBEnumDescriptorProto*)build;
- (PBEnumDescriptorProto*)buildPartial;

- (instancetype)mergeFrom:(PBEnumDescriptorProto*)other;

- (BOOL)hasName;
- (NSString *)name;
- (instancetype)setName:(NSString *) value;
- (instancetype)clearName;

- (NSMutableArray *)value;
- (PBEnumValueDescriptorProto*)valueAtIndex:(NSUInteger)index;
- (instancetype)addValue:(PBEnumValueDescriptorProto*)value;
- (instancetype)setValueArray:(NSArray *)array;
- (instancetype)clearValue;

- (BOOL)hasOptions;
- (PBEnumOptions*)options;
- (instancetype)setOptions:(PBEnumOptions*)value;
- (instancetype)setOptionsBuilder:(PBEnumOptions_Builder*)builderForValue;
- (instancetype)mergeOptions:(PBEnumOptions*)value;
- (instancetype)clearOptions;

@end


#pragma mark - PBEnumValueDescriptorProto

@interface PBEnumValueDescriptorProto : PBGeneratedMessage

@property (readonly, strong) NSString * name;
@property (readonly) int32_t number;
@property (readonly, strong)  PBEnumValueOptions* options;

- (BOOL)hasName;
- (BOOL)hasNumber;
- (BOOL)hasOptions;


- (PBEnumValueDescriptorProto_Builder*)builder;
+ (PBEnumValueDescriptorProto_Builder*)builder;
+ (PBEnumValueDescriptorProto_Builder*)builderWithPrototype:(PBEnumValueDescriptorProto*)prototype;
- (PBEnumValueDescriptorProto_Builder*)toBuilder;

@end


@interface PBEnumValueDescriptorProto_Builder : PBGeneratedMessage_Builder

- (PBEnumValueDescriptorProto*)defaultMessageInstance;

- (PBEnumValueDescriptorProto*)build;
- (PBEnumValueDescriptorProto*)buildPartial;

- (instancetype)mergeFrom:(PBEnumValueDescriptorProto*)other;

- (BOOL)hasName;
- (NSString *)name;
- (instancetype)setName:(NSString *) value;
- (instancetype)clearName;

- (BOOL)hasNumber;
- (int32_t)number;
- (instancetype)setNumber:(int32_t) value;
- (instancetype)clearNumber;

- (BOOL)hasOptions;
- (PBEnumValueOptions*)options;
- (instancetype)setOptions:(PBEnumValueOptions*)value;
- (instancetype)setOptionsBuilder:(PBEnumValueOptions_Builder*)builderForValue;
- (instancetype)mergeOptions:(PBEnumValueOptions*)value;
- (instancetype)clearOptions;

@end


#pragma mark - PBServiceDescriptorProto

@interface PBServiceDescriptorProto : PBGeneratedMessage

@property (readonly, strong) NSString * name;
@property (readonly, strong) NSArray *method;
@property (readonly, strong)  PBServiceOptions* options;

- (BOOL)hasName;
- (BOOL)hasOptions;

- (PBMethodDescriptorProto*)methodAtIndex:(NSUInteger)index;

- (PBServiceDescriptorProto_Builder*)builder;
+ (PBServiceDescriptorProto_Builder*)builder;
+ (PBServiceDescriptorProto_Builder*)builderWithPrototype:(PBServiceDescriptorProto*)prototype;
- (PBServiceDescriptorProto_Builder*)toBuilder;

@end


@interface PBServiceDescriptorProto_Builder : PBGeneratedMessage_Builder

- (PBServiceDescriptorProto*)defaultMessageInstance;

- (PBServiceDescriptorProto*)build;
- (PBServiceDescriptorProto*)buildPartial;

- (instancetype)mergeFrom:(PBServiceDescriptorProto*)other;

- (BOOL)hasName;
- (NSString *)name;
- (instancetype)setName:(NSString *) value;
- (instancetype)clearName;

- (NSMutableArray *)method;
- (PBMethodDescriptorProto*)methodAtIndex:(NSUInteger)index;
- (instancetype)addMethod:(PBMethodDescriptorProto*)value;
- (instancetype)setMethodArray:(NSArray *)array;
- (instancetype)clearMethod;

- (BOOL)hasOptions;
- (PBServiceOptions*)options;
- (instancetype)setOptions:(PBServiceOptions*)value;
- (instancetype)setOptionsBuilder:(PBServiceOptions_Builder*)builderForValue;
- (instancetype)mergeOptions:(PBServiceOptions*)value;
- (instancetype)clearOptions;

@end


#pragma mark - PBMethodDescriptorProto

@interface PBMethodDescriptorProto : PBGeneratedMessage

@property (readonly, strong) NSString * name;
@property (readonly, strong) NSString * inputType;
@property (readonly, strong) NSString * outputType;
@property (readonly, strong)  PBMethodOptions* options;

- (BOOL)hasName;
- (BOOL)hasInputType;
- (BOOL)hasOutputType;
- (BOOL)hasOptions;


- (PBMethodDescriptorProto_Builder*)builder;
+ (PBMethodDescriptorProto_Builder*)builder;
+ (PBMethodDescriptorProto_Builder*)builderWithPrototype:(PBMethodDescriptorProto*)prototype;
- (PBMethodDescriptorProto_Builder*)toBuilder;

@end


@interface PBMethodDescriptorProto_Builder : PBGeneratedMessage_Builder

- (PBMethodDescriptorProto*)defaultMessageInstance;

- (PBMethodDescriptorProto*)build;
- (PBMethodDescriptorProto*)buildPartial;

- (instancetype)mergeFrom:(PBMethodDescriptorProto*)other;

- (BOOL)hasName;
- (NSString *)name;
- (instancetype)setName:(NSString *) value;
- (instancetype)clearName;

- (BOOL)hasInputType;
- (NSString *)inputType;
- (instancetype)setInputType:(NSString *) value;
- (instancetype)clearInputType;

- (BOOL)hasOutputType;
- (NSString *)outputType;
- (instancetype)setOutputType:(NSString *) value;
- (instancetype)clearOutputType;

- (BOOL)hasOptions;
- (PBMethodOptions*)options;
- (instancetype)setOptions:(PBMethodOptions*)value;
- (instancetype)setOptionsBuilder:(PBMethodOptions_Builder*)builderForValue;
- (instancetype)mergeOptions:(PBMethodOptions*)value;
- (instancetype)clearOptions;

@end


#pragma mark - PBFileOptions

@interface PBFileOptions : PBExtendableMessage

@property (readonly, strong) NSString * javaPackage;
@property (readonly, strong) NSString * javaOuterClassname;
@property (readonly) BOOL javaMultipleFiles;
@property (readonly) BOOL javaGenerateEqualsAndHash;
@property (readonly) PBFileOptions_OptimizeMode optimizeFor;
@property (readonly, strong) NSString * goPackage;
@property (readonly) BOOL ccGenericServices;
@property (readonly) BOOL javaGenericServices;
@property (readonly) BOOL pyGenericServices;
@property (readonly, strong) NSArray *uninterpretedOption;

- (BOOL)hasJavaPackage;
- (BOOL)hasJavaOuterClassname;
- (BOOL)hasJavaMultipleFiles;
- (BOOL)hasJavaGenerateEqualsAndHash;
- (BOOL)hasOptimizeFor;
- (BOOL)hasGoPackage;
- (BOOL)hasCcGenericServices;
- (BOOL)hasJavaGenericServices;
- (BOOL)hasPyGenericServices;

- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;

- (PBFileOptions_Builder*)builder;
+ (PBFileOptions_Builder*)builder;
+ (PBFileOptions_Builder*)builderWithPrototype:(PBFileOptions*)prototype;
- (PBFileOptions_Builder*)toBuilder;

@end


@interface PBFileOptions_Builder : PBExtendableMessage_Builder

- (PBFileOptions*)defaultMessageInstance;

- (PBFileOptions*)build;
- (PBFileOptions*)buildPartial;

- (instancetype)mergeFrom:(PBFileOptions*)other;

- (BOOL)hasJavaPackage;
- (NSString *)javaPackage;
- (instancetype)setJavaPackage:(NSString *) value;
- (instancetype)clearJavaPackage;

- (BOOL)hasJavaOuterClassname;
- (NSString *)javaOuterClassname;
- (instancetype)setJavaOuterClassname:(NSString *) value;
- (instancetype)clearJavaOuterClassname;

- (BOOL)hasJavaMultipleFiles;
- (BOOL)javaMultipleFiles;
- (instancetype)setJavaMultipleFiles:(BOOL) value;
- (instancetype)clearJavaMultipleFiles;

- (BOOL)hasJavaGenerateEqualsAndHash;
- (BOOL)javaGenerateEqualsAndHash;
- (instancetype)setJavaGenerateEqualsAndHash:(BOOL) value;
- (instancetype)clearJavaGenerateEqualsAndHash;

- (BOOL)hasOptimizeFor;
- (PBFileOptions_OptimizeMode)optimizeFor;
- (instancetype)setOptimizeFor:(PBFileOptions_OptimizeMode)value;
- (instancetype)clearOptimizeFor;

- (BOOL)hasGoPackage;
- (NSString *)goPackage;
- (instancetype)setGoPackage:(NSString *) value;
- (instancetype)clearGoPackage;

- (BOOL)hasCcGenericServices;
- (BOOL)ccGenericServices;
- (instancetype)setCcGenericServices:(BOOL) value;
- (instancetype)clearCcGenericServices;

- (BOOL)hasJavaGenericServices;
- (BOOL)javaGenericServices;
- (instancetype)setJavaGenericServices:(BOOL) value;
- (instancetype)clearJavaGenericServices;

- (BOOL)hasPyGenericServices;
- (BOOL)pyGenericServices;
- (instancetype)setPyGenericServices:(BOOL) value;
- (instancetype)clearPyGenericServices;

- (NSMutableArray *)uninterpretedOption;
- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;
- (instancetype)addUninterpretedOption:(PBUninterpretedOption*)value;
- (instancetype)setUninterpretedOptionArray:(NSArray *)array;
- (instancetype)clearUninterpretedOption;

@end


#pragma mark - PBMessageOptions

@interface PBMessageOptions : PBExtendableMessage

@property (readonly) BOOL messageSetWireFormat;
@property (readonly) BOOL noStandardDescriptorAccessor;
@property (readonly, strong) NSArray *uninterpretedOption;

- (BOOL)hasMessageSetWireFormat;
- (BOOL)hasNoStandardDescriptorAccessor;

- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;

- (PBMessageOptions_Builder*)builder;
+ (PBMessageOptions_Builder*)builder;
+ (PBMessageOptions_Builder*)builderWithPrototype:(PBMessageOptions*)prototype;
- (PBMessageOptions_Builder*)toBuilder;

@end


@interface PBMessageOptions_Builder : PBExtendableMessage_Builder

- (PBMessageOptions*)defaultMessageInstance;

- (PBMessageOptions*)build;
- (PBMessageOptions*)buildPartial;

- (instancetype)mergeFrom:(PBMessageOptions*)other;

- (BOOL)hasMessageSetWireFormat;
- (BOOL)messageSetWireFormat;
- (instancetype)setMessageSetWireFormat:(BOOL) value;
- (instancetype)clearMessageSetWireFormat;

- (BOOL)hasNoStandardDescriptorAccessor;
- (BOOL)noStandardDescriptorAccessor;
- (instancetype)setNoStandardDescriptorAccessor:(BOOL) value;
- (instancetype)clearNoStandardDescriptorAccessor;

- (NSMutableArray *)uninterpretedOption;
- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;
- (instancetype)addUninterpretedOption:(PBUninterpretedOption*)value;
- (instancetype)setUninterpretedOptionArray:(NSArray *)array;
- (instancetype)clearUninterpretedOption;

@end


#pragma mark - PBFieldOptions

@interface PBFieldOptions : PBExtendableMessage

@property (readonly) PBFieldOptions_CType ctype;
@property (readonly) BOOL packed;
@property (readonly) BOOL lazy;
@property (readonly) BOOL deprecated;
@property (readonly, strong) NSString * experimentalMapKey;
@property (readonly) BOOL weak;
@property (readonly, strong) NSArray *uninterpretedOption;

- (BOOL)hasCtype;
- (BOOL)hasPacked;
- (BOOL)hasLazy;
- (BOOL)hasDeprecated;
- (BOOL)hasExperimentalMapKey;
- (BOOL)hasWeak;

- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;

- (PBFieldOptions_Builder*)builder;
+ (PBFieldOptions_Builder*)builder;
+ (PBFieldOptions_Builder*)builderWithPrototype:(PBFieldOptions*)prototype;
- (PBFieldOptions_Builder*)toBuilder;

@end


@interface PBFieldOptions_Builder : PBExtendableMessage_Builder

- (PBFieldOptions*)defaultMessageInstance;

- (PBFieldOptions*)build;
- (PBFieldOptions*)buildPartial;

- (instancetype)mergeFrom:(PBFieldOptions*)other;

- (BOOL)hasCtype;
- (PBFieldOptions_CType)ctype;
- (instancetype)setCtype:(PBFieldOptions_CType)value;
- (instancetype)clearCtype;

- (BOOL)hasPacked;
- (BOOL)packed;
- (instancetype)setPacked:(BOOL) value;
- (instancetype)clearPacked;

- (BOOL)hasLazy;
- (BOOL)lazy;
- (instancetype)setLazy:(BOOL) value;
- (instancetype)clearLazy;

- (BOOL)hasDeprecated;
- (BOOL)deprecated;
- (instancetype)setDeprecated:(BOOL) value;
- (instancetype)clearDeprecated;

- (BOOL)hasExperimentalMapKey;
- (NSString *)experimentalMapKey;
- (instancetype)setExperimentalMapKey:(NSString *) value;
- (instancetype)clearExperimentalMapKey;

- (BOOL)hasWeak;
- (BOOL)weak;
- (instancetype)setWeak:(BOOL) value;
- (instancetype)clearWeak;

- (NSMutableArray *)uninterpretedOption;
- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;
- (instancetype)addUninterpretedOption:(PBUninterpretedOption*)value;
- (instancetype)setUninterpretedOptionArray:(NSArray *)array;
- (instancetype)clearUninterpretedOption;

@end


#pragma mark - PBEnumOptions

@interface PBEnumOptions : PBExtendableMessage

@property (readonly) BOOL allowAlias;
@property (readonly, strong) NSArray *uninterpretedOption;

- (BOOL)hasAllowAlias;

- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;

- (PBEnumOptions_Builder*)builder;
+ (PBEnumOptions_Builder*)builder;
+ (PBEnumOptions_Builder*)builderWithPrototype:(PBEnumOptions*)prototype;
- (PBEnumOptions_Builder*)toBuilder;

@end


@interface PBEnumOptions_Builder : PBExtendableMessage_Builder

- (PBEnumOptions*)defaultMessageInstance;

- (PBEnumOptions*)build;
- (PBEnumOptions*)buildPartial;

- (instancetype)mergeFrom:(PBEnumOptions*)other;

- (BOOL)hasAllowAlias;
- (BOOL)allowAlias;
- (instancetype)setAllowAlias:(BOOL) value;
- (instancetype)clearAllowAlias;

- (NSMutableArray *)uninterpretedOption;
- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;
- (instancetype)addUninterpretedOption:(PBUninterpretedOption*)value;
- (instancetype)setUninterpretedOptionArray:(NSArray *)array;
- (instancetype)clearUninterpretedOption;

@end


#pragma mark - PBEnumValueOptions

@interface PBEnumValueOptions : PBExtendableMessage

@property (readonly, strong) NSArray *uninterpretedOption;


- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;

- (PBEnumValueOptions_Builder*)builder;
+ (PBEnumValueOptions_Builder*)builder;
+ (PBEnumValueOptions_Builder*)builderWithPrototype:(PBEnumValueOptions*)prototype;
- (PBEnumValueOptions_Builder*)toBuilder;

@end


@interface PBEnumValueOptions_Builder : PBExtendableMessage_Builder

- (PBEnumValueOptions*)defaultMessageInstance;

- (PBEnumValueOptions*)build;
- (PBEnumValueOptions*)buildPartial;

- (instancetype)mergeFrom:(PBEnumValueOptions*)other;

- (NSMutableArray *)uninterpretedOption;
- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;
- (instancetype)addUninterpretedOption:(PBUninterpretedOption*)value;
- (instancetype)setUninterpretedOptionArray:(NSArray *)array;
- (instancetype)clearUninterpretedOption;

@end


#pragma mark - PBServiceOptions

@interface PBServiceOptions : PBExtendableMessage

@property (readonly, strong) NSArray *uninterpretedOption;


- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;

- (PBServiceOptions_Builder*)builder;
+ (PBServiceOptions_Builder*)builder;
+ (PBServiceOptions_Builder*)builderWithPrototype:(PBServiceOptions*)prototype;
- (PBServiceOptions_Builder*)toBuilder;

@end


@interface PBServiceOptions_Builder : PBExtendableMessage_Builder

- (PBServiceOptions*)defaultMessageInstance;

- (PBServiceOptions*)build;
- (PBServiceOptions*)buildPartial;

- (instancetype)mergeFrom:(PBServiceOptions*)other;

- (NSMutableArray *)uninterpretedOption;
- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;
- (instancetype)addUninterpretedOption:(PBUninterpretedOption*)value;
- (instancetype)setUninterpretedOptionArray:(NSArray *)array;
- (instancetype)clearUninterpretedOption;

@end


#pragma mark - PBMethodOptions

@interface PBMethodOptions : PBExtendableMessage

@property (readonly, strong) NSArray *uninterpretedOption;


- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;

- (PBMethodOptions_Builder*)builder;
+ (PBMethodOptions_Builder*)builder;
+ (PBMethodOptions_Builder*)builderWithPrototype:(PBMethodOptions*)prototype;
- (PBMethodOptions_Builder*)toBuilder;

@end


@interface PBMethodOptions_Builder : PBExtendableMessage_Builder

- (PBMethodOptions*)defaultMessageInstance;

- (PBMethodOptions*)build;
- (PBMethodOptions*)buildPartial;

- (instancetype)mergeFrom:(PBMethodOptions*)other;

- (NSMutableArray *)uninterpretedOption;
- (PBUninterpretedOption*)uninterpretedOptionAtIndex:(NSUInteger)index;
- (instancetype)addUninterpretedOption:(PBUninterpretedOption*)value;
- (instancetype)setUninterpretedOptionArray:(NSArray *)array;
- (instancetype)clearUninterpretedOption;

@end


#pragma mark - PBUninterpretedOption

@interface PBUninterpretedOption : PBGeneratedMessage

@property (readonly, strong) NSArray *name;
@property (readonly, strong) NSString * identifierValue;
@property (readonly) uint64_t positiveIntValue;
@property (readonly) int64_t negativeIntValue;
@property (readonly) Float64 doubleValue;
@property (readonly, strong) NSData * stringValue;
@property (readonly, strong) NSString * aggregateValue;

- (BOOL)hasIdentifierValue;
- (BOOL)hasPositiveIntValue;
- (BOOL)hasNegativeIntValue;
- (BOOL)hasDoubleValue;
- (BOOL)hasStringValue;
- (BOOL)hasAggregateValue;

- (PBUninterpretedOption_NamePart*)nameAtIndex:(NSUInteger)index;

- (PBUninterpretedOption_Builder*)builder;
+ (PBUninterpretedOption_Builder*)builder;
+ (PBUninterpretedOption_Builder*)builderWithPrototype:(PBUninterpretedOption*)prototype;
- (PBUninterpretedOption_Builder*)toBuilder;

@end


@interface PBUninterpretedOption_Builder : PBGeneratedMessage_Builder

- (PBUninterpretedOption*)defaultMessageInstance;

- (PBUninterpretedOption*)build;
- (PBUninterpretedOption*)buildPartial;

- (instancetype)mergeFrom:(PBUninterpretedOption*)other;

- (NSMutableArray *)name;
- (PBUninterpretedOption_NamePart*)nameAtIndex:(NSUInteger)index;
- (instancetype)addName:(PBUninterpretedOption_NamePart*)value;
- (instancetype)setNameArray:(NSArray *)array;
- (instancetype)clearName;

- (BOOL)hasIdentifierValue;
- (NSString *)identifierValue;
- (instancetype)setIdentifierValue:(NSString *) value;
- (instancetype)clearIdentifierValue;

- (BOOL)hasPositiveIntValue;
- (uint64_t)positiveIntValue;
- (instancetype)setPositiveIntValue:(uint64_t) value;
- (instancetype)clearPositiveIntValue;

- (BOOL)hasNegativeIntValue;
- (int64_t)negativeIntValue;
- (instancetype)setNegativeIntValue:(int64_t) value;
- (instancetype)clearNegativeIntValue;

- (BOOL)hasDoubleValue;
- (Float64)doubleValue;
- (instancetype)setDoubleValue:(Float64) value;
- (instancetype)clearDoubleValue;

- (BOOL)hasStringValue;
- (NSData *)stringValue;
- (instancetype)setStringValue:(NSData *) value;
- (instancetype)clearStringValue;

- (BOOL)hasAggregateValue;
- (NSString *)aggregateValue;
- (instancetype)setAggregateValue:(NSString *) value;
- (instancetype)clearAggregateValue;

@end


#pragma mark - PBUninterpretedOption_NamePart

@interface PBUninterpretedOption_NamePart : PBGeneratedMessage

@property (readonly, strong) NSString * namePart;
@property (readonly) BOOL isExtension;

- (BOOL)hasNamePart;
- (BOOL)hasIsExtension;


- (PBUninterpretedOption_NamePart_Builder*)builder;
+ (PBUninterpretedOption_NamePart_Builder*)builder;
+ (PBUninterpretedOption_NamePart_Builder*)builderWithPrototype:(PBUninterpretedOption_NamePart*)prototype;
- (PBUninterpretedOption_NamePart_Builder*)toBuilder;

@end


@interface PBUninterpretedOption_NamePart_Builder : PBGeneratedMessage_Builder

- (PBUninterpretedOption_NamePart*)defaultMessageInstance;

- (PBUninterpretedOption_NamePart*)build;
- (PBUninterpretedOption_NamePart*)buildPartial;

- (instancetype)mergeFrom:(PBUninterpretedOption_NamePart*)other;

- (BOOL)hasNamePart;
- (NSString *)namePart;
- (instancetype)setNamePart:(NSString *) value;
- (instancetype)clearNamePart;

- (BOOL)hasIsExtension;
- (BOOL)isExtension;
- (instancetype)setIsExtension:(BOOL) value;
- (instancetype)clearIsExtension;

@end


#pragma mark - PBSourceCodeInfo

@interface PBSourceCodeInfo : PBGeneratedMessage

@property (readonly, strong) NSArray *location;


- (PBSourceCodeInfo_Location*)locationAtIndex:(NSUInteger)index;

- (PBSourceCodeInfo_Builder*)builder;
+ (PBSourceCodeInfo_Builder*)builder;
+ (PBSourceCodeInfo_Builder*)builderWithPrototype:(PBSourceCodeInfo*)prototype;
- (PBSourceCodeInfo_Builder*)toBuilder;

@end


@interface PBSourceCodeInfo_Builder : PBGeneratedMessage_Builder

- (PBSourceCodeInfo*)defaultMessageInstance;

- (PBSourceCodeInfo*)build;
- (PBSourceCodeInfo*)buildPartial;

- (instancetype)mergeFrom:(PBSourceCodeInfo*)other;

- (NSMutableArray *)location;
- (PBSourceCodeInfo_Location*)locationAtIndex:(NSUInteger)index;
- (instancetype)addLocation:(PBSourceCodeInfo_Location*)value;
- (instancetype)setLocationArray:(NSArray *)array;
- (instancetype)clearLocation;

@end


#pragma mark - PBSourceCodeInfo_Location

@interface PBSourceCodeInfo_Location : PBGeneratedMessage

@property (readonly, strong) PBArray * path;
@property (readonly, strong) PBArray * span;
@property (readonly, strong) NSString * leadingComments;
@property (readonly, strong) NSString * trailingComments;

- (BOOL)hasLeadingComments;
- (BOOL)hasTrailingComments;

- (int32_t)pathAtIndex:(NSUInteger)index;
- (int32_t)spanAtIndex:(NSUInteger)index;

- (PBSourceCodeInfo_Location_Builder*)builder;
+ (PBSourceCodeInfo_Location_Builder*)builder;
+ (PBSourceCodeInfo_Location_Builder*)builderWithPrototype:(PBSourceCodeInfo_Location*)prototype;
- (PBSourceCodeInfo_Location_Builder*)toBuilder;

@end


@interface PBSourceCodeInfo_Location_Builder : PBGeneratedMessage_Builder

- (PBSourceCodeInfo_Location*)defaultMessageInstance;

- (PBSourceCodeInfo_Location*)build;
- (PBSourceCodeInfo_Location*)buildPartial;

- (instancetype)mergeFrom:(PBSourceCodeInfo_Location*)other;

- (PBAppendableArray *)path;
- (int32_t)pathAtIndex:(NSUInteger)index;
- (instancetype)addPath:(int32_t)value;
- (instancetype)setPathArray:(NSArray *)array;
- (instancetype)setPathValues:(const int32_t *)values count:(NSUInteger)count;
- (instancetype)clearPath;

- (PBAppendableArray *)span;
- (int32_t)spanAtIndex:(NSUInteger)index;
- (instancetype)addSpan:(int32_t)value;
- (instancetype)setSpanArray:(NSArray *)array;
- (instancetype)setSpanValues:(const int32_t *)values count:(NSUInteger)count;
- (instancetype)clearSpan;

- (BOOL)hasLeadingComments;
- (NSString *)leadingComments;
- (instancetype)setLeadingComments:(NSString *) value;
- (instancetype)clearLeadingComments;

- (BOOL)hasTrailingComments;
- (NSString *)trailingComments;
- (instancetype)setTrailingComments:(NSString *) value;
- (instancetype)clearTrailingComments;

@end


// @@protoc_insertion_point(global_scope)
