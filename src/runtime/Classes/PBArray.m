// Protocol Buffers for Objective C
//
// Copyright 2010 Booyah Inc.
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
//
// Author: Jon Parise <jon@booyah.com>

#import "PBArray.h"

NSString * const PBArrayTypeMismatchException = @"PBArrayTypeMismatchException";
NSString * const PBArrayNumberExpectedException = @"PBArrayNumberExpectedException";
NSString * const PBArrayAllocationFailureException = @"PBArrayAllocationFailureException";

#pragma mark NSNumber Setters

typedef void (*PBArrayValueSetter)(NSNumber *number, void *value);

static void PBArraySetBoolValue(NSNumber *number, void *value)
{
	*((BOOL *)value) = [number charValue];
}

static void PBArraySetInt32Value(NSNumber *number, void *value)
{
	*((int32_t *)value) = [number intValue];
}

static void PBArraySetUInt32Value(NSNumber *number, void *value)
{
	*((uint32_t *)value) = [number unsignedIntValue];
}

static void PBArraySetInt64Value(NSNumber *number, void *value)
{
	*((int64_t *)value) = [number longLongValue];
}

static void PBArraySetUInt64Value(NSNumber *number, void *value)
{
	*((uint64_t *)value) = [number unsignedLongLongValue];
}

static void PBArraySetFloatValue(NSNumber *number, void *value)
{
	*((Float32 *)value) = [number floatValue];
}

static void PBArraySetDoubleValue(NSNumber *number, void *value)
{
	*((Float64 *)value) = [number doubleValue];
}

#pragma mark Array Value Types

typedef struct _PBArrayValueTypeInfo
{
	const size_t size;
	const PBArrayValueSetter setter;
} PBArrayValueTypeInfo;

static PBArrayValueTypeInfo PBValueTypes[] =
{
	{ sizeof(BOOL),		PBArraySetBoolValue		},
	{ sizeof(int32_t),	PBArraySetInt32Value	},
	{ sizeof(uint32_t),	PBArraySetUInt32Value	},
	{ sizeof(int64_t),	PBArraySetInt64Value	},
	{ sizeof(uint64_t),	PBArraySetUInt64Value	},
	{ sizeof(Float32),	PBArraySetFloatValue	},
	{ sizeof(Float64),	PBArraySetDoubleValue	},
};

#define PBArrayValueTypeSize(type)		PBValueTypes[type].size
#define PBArrayValueTypeSetter(type)	PBValueTypes[type].setter

#pragma mark Helper Macros

#define PBArraySlot(index) (_data + (index * PBArrayValueTypeSize(_valueType)))

#define PBArrayValueTypeAssert(type) \
	if (__builtin_expect(_valueType != type, 0)) \
		[NSException raise:PBArrayTypeMismatchException \
					format:@"array value type mismatch (expected '%s')", #type];

#define PBArrayValueRangeAssert(index) \
	if (__builtin_expect(index >= _count, 0)) \
		[NSException raise:NSRangeException format: @"index (%@) beyond bounds (%@)", @(index), @(_count)];

#define PBArrayNumberAssert(value) \
	if (__builtin_expect(![value isKindOfClass:[NSNumber class]], 0)) \
		[NSException raise:PBArrayNumberExpectedException format:@"NSNumber expected (got '%@')", [value class]];

#define PBArrayAllocationAssert(p, size) \
	if (__builtin_expect(p == NULL, 0)) \
		[NSException raise:PBArrayAllocationFailureException format:@"failed to allocate %lu bytes", size];

#pragma mark -
#pragma mark PBArray

@implementation PBArray

@synthesize valueType = _valueType;
@dynamic data;

- (instancetype)initWithCount:(NSUInteger)count valueType:(PBArrayValueType)valueType
{
	if ((self = [super init]))
	{
		_valueType = valueType;
		_count = count;
		_capacity = count;

		if (_capacity)
		{
            _data = malloc(_capacity * PBArrayValueTypeSize(_valueType));
            if (_data == NULL)
            {
                self = nil;
            }
		}
	}

	return self;
}

- (instancetype)copyWithZone:(NSZone *)zone
{
	PBArray *copy = [[[self class] alloc] initWithCount:_count valueType:_valueType];
	if (copy)
	{
        memcpy(copy->_data, _data, _count * PBArrayValueTypeSize(_valueType));
	}

	return copy;
}

- (void)dealloc {
    if (_data) {
		free(_data);
	}
}

- (NSString *)description
{
	return [NSString stringWithFormat:@"<%@ %p>{valueType = %@, count = %@, capacity = %@, data = %p}",
			[self class], self, @(_valueType), @(_count), @(_capacity), _data];
}

- (NSUInteger)count {
	return _count;
}

- (const void *)data {
	return _data;
}

- (BOOL)boolAtIndex:(NSUInteger)index
{
	PBArrayValueRangeAssert(index);
	PBArrayValueTypeAssert(PBArrayValueTypeBool);
	return ((BOOL *)_data)[index];
}

- (int32_t)int32AtIndex:(NSUInteger)index
{
	PBArrayValueRangeAssert(index);
	PBArrayValueTypeAssert(PBArrayValueTypeInt32);
	return ((int32_t *)_data)[index];
}

- (uint32_t)uint32AtIndex:(NSUInteger)index
{
	PBArrayValueRangeAssert(index);
	PBArrayValueTypeAssert(PBArrayValueTypeUInt32);
	return ((uint32_t *)_data)[index];
}

- (int64_t)int64AtIndex:(NSUInteger)index
{
	PBArrayValueRangeAssert(index);
	PBArrayValueTypeAssert(PBArrayValueTypeInt64);
	return ((int64_t *)_data)[index];
}

- (uint64_t)uint64AtIndex:(NSUInteger)index
{
	PBArrayValueRangeAssert(index);
	PBArrayValueTypeAssert(PBArrayValueTypeUInt64);
	return ((uint64_t *)_data)[index];
}

- (Float32)floatAtIndex:(NSUInteger)index
{
	PBArrayValueRangeAssert(index);
	PBArrayValueTypeAssert(PBArrayValueTypeFloat);
	return ((Float32 *)_data)[index];
}

- (Float64)doubleAtIndex:(NSUInteger)index
{
	PBArrayValueRangeAssert(index);
	PBArrayValueTypeAssert(PBArrayValueTypeDouble);
	return ((Float64 *)_data)[index];
}

- (BOOL)isEqualToArray:(PBArray *)array
{
	if (self == array)
	{
		return YES;
	}
	else if (array->_count != _count)
	{
		return NO;
	}
	else
	{
		return memcmp(array->_data, _data, _count * PBArrayValueTypeSize(_valueType)) == 0;
	}
}

- (BOOL)isEqual:(id)object
{
	BOOL equal = NO;
	if ([object isKindOfClass:[PBArray class]])
	{
		equal = [self isEqualToArray:object];
	}
	return equal;
}

@end

@implementation PBArray (PBArrayExtended)

- (instancetype)arrayByAppendingArray:(PBArray *)array
{
	PBArrayValueTypeAssert(array.valueType);

   
	PBArray *result = [[[self class] alloc] initWithCount:_count + array.count valueType:_valueType];
	if (result)
	{
        const size_t elementSize = PBArrayValueTypeSize(_valueType);
        const size_t originalSize = _count * elementSize;

        memcpy(result->_data, _data, originalSize);
        memcpy(result->_data + originalSize, array.data, array.count * elementSize);
	}

	return result;
}

@end

@implementation PBArray (PBArrayCreation)

+ (instancetype)arrayWithValueType:(PBArrayValueType)valueType
{
	return [[self alloc] initWithValueType:valueType];
}

+ (instancetype)arrayWithValues:(const void *)values count:(NSUInteger)count valueType:(PBArrayValueType)valueType
{
	return [[self alloc] initWithValues:values count:count valueType:valueType];
}

+ (instancetype)arrayWithArray:(NSArray *)array valueType:(PBArrayValueType)valueType
{
	return [[self alloc] initWithArray:array valueType:valueType];
}

- (instancetype)initWithValueType:(PBArrayValueType)valueType
{
	return [self initWithCount:0 valueType:valueType];
}

- (instancetype)initWithValues:(const void *)values count:(NSUInteger)count valueType:(PBArrayValueType)valueType
{
	if ((self = [self initWithCount:count valueType:valueType]))
	{
        memcpy(_data, values, count * PBArrayValueTypeSize(_valueType));
	}

	return self;
}

- (instancetype)initWithArray:(NSArray *)array valueType:(PBArrayValueType)valueType
{
	if ((self = [self initWithCount:[array count] valueType:valueType]))
	{
		const size_t elementSize = PBArrayValueTypeSize(valueType);
		
        __block size_t offset = 0;
        PBArrayValueSetter setter = PBArrayValueTypeSetter(valueType);
        [array enumerateObjectsUsingBlock:^(id obj,NSUInteger idx,BOOL *stop){
            PBArrayNumberAssert(obj);
            setter((NSNumber *)obj, _data + offset);
            offset += elementSize;
        }];
            
	}

	return self;
}

@end

#pragma mark -
#pragma mark PBAppendableArray

@implementation PBAppendableArray

- (void)ensureAdditionalCapacity:(NSUInteger)additionalSlots
{
	const NSUInteger requiredSlots = _count + additionalSlots;

//    bool wasAllocated=YES;
	if (requiredSlots > _capacity)
	{
		// If we haven't allocated any capacity yet, simply reserve
		// enough capacity to cover the required number of slots.
		if (_capacity == 0)
		{
			_capacity = requiredSlots;
//            wasAllocated=NO;
		}
		else
		{
			// Otherwise, continue to double our capacity until we
			// can accomodate the required number of slots.
			while (_capacity < requiredSlots)
			{
				_capacity *= 2;
			}
		}
        const size_t size = _capacity * PBArrayValueTypeSize(_valueType);
        _data = reallocf(_data, size);
        PBArrayAllocationAssert(_data, size);
	}
}


- (void)addBool:(BOOL)value
{
	PBArrayValueTypeAssert(PBArrayValueTypeBool);
	[self ensureAdditionalCapacity:1];
	*(BOOL *)PBArraySlot(_count) = value;
	_count++;
}

- (void)addInt32:(int32_t)value
{
	PBArrayValueTypeAssert(PBArrayValueTypeInt32);
	[self ensureAdditionalCapacity:1];
	*(int32_t *)PBArraySlot(_count) = value;
	_count++;
}

- (void)addUint32:(uint32_t)value
{
	PBArrayValueTypeAssert(PBArrayValueTypeUInt32);
	[self ensureAdditionalCapacity:1];
	*(uint32_t *)PBArraySlot(_count) = value;
	_count++;
}

- (void)addInt64:(int64_t)value
{
	PBArrayValueTypeAssert(PBArrayValueTypeInt64);
	[self ensureAdditionalCapacity:1];
	*(int64_t *)PBArraySlot(_count) = value;
	_count++;
}

- (void)addUint64:(uint64_t)value
{
	PBArrayValueTypeAssert(PBArrayValueTypeUInt64);
	[self ensureAdditionalCapacity:1];
	*(uint64_t *)PBArraySlot(_count) = value;
	_count++;
}

- (void)addFloat:(Float32)value
{
	PBArrayValueTypeAssert(PBArrayValueTypeFloat);
	[self ensureAdditionalCapacity:1];
	*(Float32 *)PBArraySlot(_count) = value;
	_count++;
}

- (void)addDouble:(Float64)value
{
	PBArrayValueTypeAssert(PBArrayValueTypeDouble);
	[self ensureAdditionalCapacity:1];
	*(Float64 *)PBArraySlot(_count) = value;
	_count++;
}

- (void)appendArray:(PBArray *)array
{
	PBArrayValueTypeAssert(array.valueType);


    [self ensureAdditionalCapacity:array.count];
    const size_t elementSize = PBArrayValueTypeSize(_valueType);
    memcpy(_data + (_count * elementSize), array.data, array.count * elementSize);
    _count += array.count;
    
}

/**
 * This method does not work for object types
 */
- (void)appendValues:(const void *)values count:(NSUInteger)count
{
	[self ensureAdditionalCapacity:count];

    const size_t elementSize = PBArrayValueTypeSize(_valueType);
    memcpy(_data + (_count * elementSize), values, count * elementSize);
    _count += count;
	
}

@end
