// Protocol Buffers for Objective C
//
// Copyright 2010 Booyah Inc.
// Copyright 2008 Cyrus Najmabadi
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

#import "GeneratedMessage.h"

#import "UnknownFieldSet.h"

@interface PBGeneratedMessage ()
@property (strong) PBUnknownFieldSet* unknownFields;
@end


@implementation PBGeneratedMessage


- (id) init {
  if ((self = [super init])) {
    _unknownFields = [PBUnknownFieldSet defaultInstance];
    memoizedSerializedSize = -1;
  }

  return self;
}

+ (instancetype)defaultInstance {
    @throw [NSException exceptionWithName:@"ImproperSubclassing" reason:@"" userInfo:nil];
}

- (instancetype)defaultInstance {
    // defined here for autocomplete / type checking rather than id<PBMessage>
    @throw [NSException exceptionWithName:@"ImproperSubclassing" reason:@"" userInfo:nil];
}

+ (id<PBMessage_Builder>) builder {
    // required so the parseFromData methods can be moved down into the library
    @throw [NSException exceptionWithName:@"ImproperSubclassing" reason:@"" userInfo:nil];
}

+ (instancetype) parseFromData:(NSData*)data {
    return [[[self builder] mergeFromData:data] build];
}

+ (instancetype) parseFromData:(NSData*)data
             extensionRegistry:(PBExtensionRegistry*)extensionRegistry
{
    return [[[self builder] mergeFromData:data
                        extensionRegistry:extensionRegistry] build];
}

+ (instancetype) parseFromInputStream:(NSInputStream*)input {
    return [[[self builder] mergeFromInputStream:input] build];
}

+ (instancetype) parseFromInputStream:(NSInputStream*)input
                    extensionRegistry:(PBExtensionRegistry*)extensionRegistry
{
    return [[[self builder] mergeFromInputStream:input
                               extensionRegistry:extensionRegistry] build];
}

+ (instancetype) parseFromCodedInputStream:(PBCodedInputStream*)input {
    return [[[self builder] mergeFromCodedInputStream:input] build];
}

+ (instancetype) parseFromCodedInputStream:(PBCodedInputStream*)input
                         extensionRegistry:(PBExtensionRegistry*)extensionRegistry
{
    return [[[self builder] mergeFromCodedInputStream:input
                                    extensionRegistry:extensionRegistry] build];
}

@end
