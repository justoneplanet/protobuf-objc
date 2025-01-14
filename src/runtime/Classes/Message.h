//
//  Message.h
//  Protocol Buffers for Objective C
//
//  Copyright 2014 Ed Preston
//  Copyright 2010 Booyah Inc.
//  Copyright 2008 Cyrus Najmabadi
//

@class PBCodedOutputStream;
@class PBUnknownFieldSet;
@protocol PBMessage_Builder;

/**
 * Abstract interface implemented by Protocol Message objects.
 *
 * @author Cyrus Najmabadi
 */
@protocol PBMessage<NSObject>
/**
 * Get an instance of the type with all fields set to their default values.
 * This may or may not be a singleton.  This differs from the
 * {@code getDefaultInstance()} method of generated message classes in that
 * this method is an abstract method of the {@code Message} interface
 * whereas {@code getDefaultInstance()} is a static method of a specific
 * class.  They return the same thing.
 */
- (id<PBMessage>)defaultInstance;

/**
 * Get the {@code UnknownFieldSet}
 */
- (PBUnknownFieldSet*)unknownFields;

/**
 * Get the number of bytes required to encode this message.  The result
 * is only computed on the first call and cached after that.
 */
- (int32_t)serializedSize;

/**
 * Returns true if all required fields in the message and all embedded
 * messages are set, false otherwise.
 */
- (BOOL)isInitialized;

/**
 * Serializes the message and writes it to {@code output}.  This does not
 * flush or close the stream.
 */
- (void)writeToCodedOutputStream:(PBCodedOutputStream*)output;
- (void)writeToOutputStream:(NSOutputStream*)output;

/**
 * Serializes the message to a {@code ByteString} and returns it. This is
 * just a trivial wrapper around
 * {@link #writeTo(CodedOutputStream)}.
 */
- (NSData*)data;

/**
 * Constructs a new builder for a message of the same type as this message.
 */
- (id<PBMessage_Builder>)builder;

/**
 * Constructs a builder initialized with the current message.  Use this to
 * derive a new message from the current one.
 */
- (id<PBMessage_Builder>)toBuilder;

/**
 * Returns a string description of the message.
 */
- (NSString*)description;

/**
 * Writes a string description of the message into the given mutable string
 * respecting a given indent.
 */
- (void)writeDescriptionTo:(NSMutableString*)output
                withIndent:(NSString*)indent;

@end
