// Protocol Buffers for Objective C
//
// Copyright 2010 Booyah Inc.
// Copyright 2008 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "objc_enum_field.h"

#include <map>
#include <string>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/printer.h>
#include <google/protobuf/wire_format.h>
#include <google/protobuf/stubs/strutil.h>

#include "objc_helpers.h"

namespace google {
namespace protobuf {
namespace compiler {
namespace objectivec {

  namespace {
    
    void SetEnumVariables(const FieldDescriptor* descriptor,
                          map<string, string>* variables) {
      
      const EnumValueDescriptor* default_value;
      default_value = descriptor->default_value_enum();

      string type = ClassName(descriptor->enum_type());
      string name = UnderscoresToCamelCase(descriptor, false);

      (*variables)["classname"]         = ClassName(descriptor->containing_type());
      (*variables)["name"]              = name;
      (*variables)["capitalized_name"]  = UnderscoresToCamelCase(descriptor, true);
      (*variables)["list_name"]         = name + "Array";
      (*variables)["number"]            = SimpleItoa(descriptor->number());
      (*variables)["type"]              = type;
      (*variables)["default"]           = EnumValueName(default_value);
      (*variables)["tag"]      = SimpleItoa(internal::WireFormat::MakeTag(descriptor));
      (*variables)["tag_size"] = SimpleItoa(internal::WireFormat::TagSize(descriptor->number(),
                                                                          descriptor->type()));
    }
    
  }  // namespace

  EnumFieldGenerator::EnumFieldGenerator(const FieldDescriptor* descriptor)
    : descriptor_(descriptor) {
      SetEnumVariables(descriptor, &variables_);
  }

  EnumFieldGenerator::~EnumFieldGenerator() { }

  void EnumFieldGenerator::GenerateHasFieldHeader(io::Printer* printer) const {
    printer->Print(variables_, "BOOL _has$capitalized_name$:1;\n");
  }

  void EnumFieldGenerator::GenerateHasFieldSource(io::Printer* printer) const {
    printer->Print(variables_, "BOOL _has$capitalized_name$:1;\n");
  }

  void EnumFieldGenerator::GenerateFieldHeader(io::Printer* printer) const {
    printer->Print(variables_, "$type$ _$name$;\n");
  }

  void EnumFieldGenerator::GenerateFieldSource(io::Printer* printer) const {
    // the property declaration implies a backing variable of _$name$
    // printer->Print(variables_, "$type$ _$name$;\n");
  }

  void EnumFieldGenerator::GenerateHasPropertyHeader(io::Printer* printer) const {
    printer->Print(variables_, "- (BOOL)has$capitalized_name$;\n");
  }

  void EnumFieldGenerator::GeneratePropertyHeader(io::Printer* printer) const {
    printer->Print(variables_,
      "@property (readonly) $type$ $name$;\n");
  }

  void EnumFieldGenerator::GenerateExtensionSource(io::Printer* printer) const {
    printer->Print(variables_,
      "@property $type$ $name$;\n");
  }

  void EnumFieldGenerator::GenerateMembersHeader(io::Printer* printer) const {
  }

  void EnumFieldGenerator::GenerateMembersSource(io::Printer* printer) const {
  }

  void EnumFieldGenerator::GenerateSynthesizeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "- (BOOL)has$capitalized_name$ {\n"
      "  return !!_has$capitalized_name$;\n"
      "}\n"
      "- (void)setHas$capitalized_name$:(BOOL)value {\n"
      "  _has$capitalized_name$ = !!value;\n"
      "}\n");
  }

  void EnumFieldGenerator::GenerateInitializationSource(io::Printer* printer) const {
    printer->Print(variables_, "_$name$ = $default$;\n");
  }

  void EnumFieldGenerator::GenerateBuilderMembersHeader(io::Printer* printer) const {
    printer->Print(variables_,
      "- (BOOL)has$capitalized_name$;\n"
      "- ($type$)$name$;\n"\
      "- (instancetype)set$capitalized_name$:($type$)value;\n"
      "- (instancetype)clear$capitalized_name$;\n");
  }

  void EnumFieldGenerator::GenerateBuilderMembersSource(io::Printer* printer) const {
    printer->Print(variables_,
      "- (BOOL)has$capitalized_name$ {\n"
      "  return _result.has$capitalized_name$;\n"
      "}\n"
      "- ($type$)$name$ {\n"
      "  return _result.$name$;\n"
      "}\n"
      "- ($classname$_Builder*)set$capitalized_name$:($type$)value {\n"
      "  _result.has$capitalized_name$ = YES;\n"
      "  _result.$name$ = value;\n"
      "  return self;\n"
      "}\n"
      "- ($classname$_Builder*)clear$capitalized_name$ {\n"
      "  _result.has$capitalized_name$ = NO;\n"
      "  _result.$name$ = $default$;\n"
      "  return self;\n"
      "}\n");
  }

  void EnumFieldGenerator::GenerateMergingCodeHeader(io::Printer* printer) const {
  }

  void EnumFieldGenerator::GenerateMergingCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "if (other.has$capitalized_name$) {\n"
      "  [self set$capitalized_name$:other.$name$];\n"
      "}\n");
  }

  void EnumFieldGenerator::GenerateBuildingCodeHeader(io::Printer* printer) const {
  }

  void EnumFieldGenerator::GenerateBuildingCodeSource(io::Printer* printer) const {
  }

  void EnumFieldGenerator::GenerateParsingCodeHeader(io::Printer* printer) const {
  }

  void EnumFieldGenerator::GenerateParsingCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "int32_t value = [input readEnum];\n"
      "if ($type$IsValidValue(value)) {\n"
      "  [self set$capitalized_name$:value];\n"
      "} else {\n"
      "  [unknownFields mergeVarintField:$number$ value:value];\n"
      "}\n");
  }

  void EnumFieldGenerator::GenerateSerializationCodeHeader(io::Printer* printer) const {
  }

  void EnumFieldGenerator::GenerateSerializationCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "if (self.has$capitalized_name$) {\n"
      "  [output writeEnum:$number$ value:self.$name$];\n"
      "}\n");
  }

  void EnumFieldGenerator::GenerateSerializedSizeCodeHeader(io::Printer* printer) const {
  }

  void EnumFieldGenerator::GenerateSerializedSizeCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "if (self.has$capitalized_name$) {\n"
      "  size_ += computeEnumSize($number$, self.$name$);\n"
      "}\n");
  }

  void EnumFieldGenerator::GenerateDescriptionCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "if (self.has$capitalized_name$) {\n"
      "  [output appendFormat:@\"%@%@: %@\\n\", indent, @\"$name$\", @(self.$name$)];\n"
      "}\n");
  }

  void EnumFieldGenerator::GenerateIsEqualCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "self.has$capitalized_name$ == otherMessage.has$capitalized_name$ &&\n"
      "(!self.has$capitalized_name$ || self.$name$ == otherMessage.$name$) &&");
  }

  void EnumFieldGenerator::GenerateHashCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "if (self.has$capitalized_name$) {\n"
      "  hashCode = hashCode * 31 + self.$name$;\n"
      "}\n");
  }

  string EnumFieldGenerator::GetBoxedType() const {
    return ClassName(descriptor_->enum_type());
  }

  RepeatedEnumFieldGenerator::RepeatedEnumFieldGenerator(const FieldDescriptor* descriptor)
    : descriptor_(descriptor) {
      SetEnumVariables(descriptor, &variables_);
  }

  RepeatedEnumFieldGenerator::~RepeatedEnumFieldGenerator() {
  }

  void RepeatedEnumFieldGenerator::GenerateHasFieldHeader(io::Printer* printer) const {
  }
  
  void RepeatedEnumFieldGenerator::GenerateHasFieldSource(io::Printer* printer) const {
  }

  void RepeatedEnumFieldGenerator::GenerateFieldHeader(io::Printer* printer) const {
    printer->Print(variables_, "NSMutableArray * _$list_name$;\n");
    if (descriptor_->options().packed()) {
      printer->Print(variables_, "int32_t _$name$MemoizedSerializedSize;\n");
    }
  }
  
  void RepeatedEnumFieldGenerator::GenerateFieldSource(io::Printer* printer) const {
    printer->Print(variables_, "NSMutableArray * _$list_name$;\n");
    if (descriptor_->options().packed()) {
      printer->Print(variables_, "int32_t _$name$MemoizedSerializedSize;\n");
    }
  }

  void RepeatedEnumFieldGenerator::GenerateHasPropertyHeader(io::Printer* printer) const {
  }

  void RepeatedEnumFieldGenerator::GeneratePropertyHeader(io::Printer* printer) const {
		// arrays of enums are always of primative type
    printer->Print(variables_, "@property (readonly, strong) NSArray *$name$;\n");
  }

  void RepeatedEnumFieldGenerator::GenerateExtensionSource(io::Printer* printer) const {
    // arrays of enums are always of primative type
    printer->Print(variables_, "@property (strong) NSMutableArray *$list_name$;\n");
  }

  void RepeatedEnumFieldGenerator::GenerateSynthesizeSource(io::Printer* printer) const {
    printer->Print(variables_, "@dynamic $name$;\n");
  }

  void RepeatedEnumFieldGenerator::GenerateInitializationSource(io::Printer* printer) const {
  }

  void RepeatedEnumFieldGenerator::GenerateMembersHeader(io::Printer* printer) const {
    printer->Print(variables_,
      "- ($type$)$name$AtIndex:(NSUInteger)index;\n");
  }

  void RepeatedEnumFieldGenerator::GenerateBuilderMembersHeader(io::Printer* printer) const {
    printer->Print(variables_,
      "- (NSMutableArray *)$name$;\n"
      "- ($type$)$name$AtIndex:(NSUInteger)index;\n"
      "- (instancetype)add$capitalized_name$:($type$)value;\n"
      "- (instancetype)set$capitalized_name$Array:(NSArray *)array;\n"
      "- (instancetype)clear$capitalized_name$;\n");
  }

  void RepeatedEnumFieldGenerator::GenerateMergingCodeHeader(io::Printer* printer) const {
  }

  void RepeatedEnumFieldGenerator::GenerateBuildingCodeHeader(io::Printer* printer) const {
  }

  void RepeatedEnumFieldGenerator::GenerateParsingCodeHeader(io::Printer* printer) const {
  }

  void RepeatedEnumFieldGenerator::GenerateSerializationCodeHeader(io::Printer* printer) const {
  }

  void RepeatedEnumFieldGenerator::GenerateSerializedSizeCodeHeader(io::Printer* printer) const {
  }

  void RepeatedEnumFieldGenerator::GenerateMembersSource(io::Printer* printer) const {
    printer->Print(variables_,
      "- (NSArray *)$name$ {\n"
      "  return _$list_name$;\n"
      "}\n"
      "- ($type$)$name$AtIndex:(NSUInteger)index {\n"
      "  NSNumber *value = _$list_name$[index];"
      "  return value.intValue;"
      "}\n");
  }

  void RepeatedEnumFieldGenerator::GenerateBuilderMembersSource(io::Printer* printer) const {
    printer->Print(variables_,
      "- (NSMutableArray *)$name$ {\n"
      "  return _result.$list_name$;\n"
      "}\n"
      "- ($type$)$name$AtIndex:(NSUInteger)index {\n"
      "  return [_result $name$AtIndex:index];\n"
      "}\n"
      "- ($classname$_Builder *)add$capitalized_name$:($type$)value {\n"
      "  if (_result.$list_name$ == nil) {\n"
      "    _result.$list_name$ = [NSMutableArray array];\n"
      "  }\n"
      "  [_result.$list_name$ addObject:@(value)];\n"
      "  return self;\n"
      "}\n"
      "- ($classname$_Builder *)set$capitalized_name$Array:(NSArray *)array {\n"
      "  _result.$list_name$ = [NSMutableArray arrayWithArray:array];\n"
      "  return self;\n"
      "}\n"
      "- ($classname$_Builder *)clear$capitalized_name$ {\n"
      "  _result.$list_name$ = nil;\n"
      "  return self;\n"
      "}\n");
  }

  void RepeatedEnumFieldGenerator::GenerateMergingCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "if (other.$list_name$.count > 0) {\n"
      "  if (_result.$list_name$ == nil) {\n"
      "    _result.$list_name$ = [[NSMutableArray alloc] initWithArray:other.$list_name$];\n"
      "  } else {\n"
      "    [_result.$list_name$ addObjectsFromArray:other.$list_name$];\n"
      "  }\n"
      "}\n");
  }

  void RepeatedEnumFieldGenerator::GenerateBuildingCodeSource(io::Printer* printer) const {
  }

  void RepeatedEnumFieldGenerator::GenerateParsingCodeSource(io::Printer* printer) const {
    // If packed, set up the while loop
    if (descriptor_->options().packed()) {
      printer->Print(variables_,
        "int32_t length = [input readRawVarint32];\n"
        "int32_t oldLimit = [input pushLimit:length];\n"
        "while (input.bytesUntilLimit > 0) {\n");
      printer->Indent();
    }

    printer->Print(variables_,
      "int32_t value = [input readEnum];\n"
      "if ($type$IsValidValue(value)) {\n"
      "  [self add$capitalized_name$:value];\n"
      "} else {\n"
      "  [unknownFields mergeVarintField:$number$ value:value];\n"
      "}\n");

    if (descriptor_->options().packed()) {
      printer->Outdent();
      printer->Print(variables_,
        "}\n"
        "[input popLimit:oldLimit];\n");
    }
  }

  void RepeatedEnumFieldGenerator::GenerateSerializationCodeSource(io::Printer* printer) const {

    if (descriptor_->options().packed()) {
      printer->Print(variables_,
        "if (self.$list_name$.count > 0) {\n"
        "  [output writeRawVarint32:$tag$];\n"
        "  [output writeRawVarint32:_$name$MemoizedSerializedSize];\n"
        "}\n"
        "for (NSNumber *element in self.$list_name$) {"
        "  [output writeEnumNoTag:element.intValue];\n"
        "}\n");
      
    } else {
      printer->Print(variables_,
        "for (NSNumber *element in self.$list_name$) {"
        "  [output writeEnum:$number$ value:element.intValue];"
        "}\n");
    }
  }

  void RepeatedEnumFieldGenerator::GenerateSerializedSizeCodeSource(io::Printer* printer) const {
    
    if (descriptor_->options().packed()) {
      printer->Print(variables_,
        "_$name$MemoizedSerializedSize = size_;\n");
      printer->Print(variables_,
        "for (NSNumber *element in self.$list_name$) {\n"
        "  size_ += computeEnumSizeNoTag(element.intValue);\n"
        "}\n"
        "_$name$MemoizedSerializedSize = size_ - _$name$MemoizedSerializedSize;\n");
      printer->Print(variables_,
        "if (self.$list_name$.count > 0) {\n"
        "  size_ += $tag_size$;  // tag size\n"
        "  size_ += computeRawVarint32Size(_$name$MemoizedSerializedSize);\n"
        "}\n");
      
    } else {
      printer->Print(variables_,
        "for (NSNumber *element in self.$list_name$) {\n"
        "  size_ += computeEnumSize($number$, element.intValue);\n"
        "}\n");
    }
  }

  void RepeatedEnumFieldGenerator::GenerateDescriptionCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "for (NSNumber* element in self.$list_name$) {\n"
      "  [output appendFormat:@\"%@%@: %@\\n\", indent, @\"$name$\", element];\n"
      "}\n");
  }

  void RepeatedEnumFieldGenerator::GenerateIsEqualCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "((self.$list_name$ == nil && otherMessage.$list_name$ == nil) || "
      "[self.$list_name$ isEqualToArray:otherMessage.$list_name$]) &&");
  }

  void RepeatedEnumFieldGenerator::GenerateHashCodeSource(io::Printer* printer) const {
    printer->Print(variables_,
      "for (NSNumber* element in self.$list_name$) {\n"
      "  hashCode = hashCode * 31 + element.intValue;\n"
      "}\n");
  }
  
}  // namespace objectivec
}  // namespace compiler
}  // namespace protobuf
}  // namespace google
