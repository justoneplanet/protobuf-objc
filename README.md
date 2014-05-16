# Protocol Buffers, Objective C

An implementation of Protocol Buffers in Objective C.

Protocol Buffers are a way of encoding structured data in an efficient yet extensible format.
This project is based on an implementation of Protocol Buffers from Google.  See the
[Google protobuf project][g-protobuf] for more information.

[g-protobuf]: http://code.google.com/p/protobuf/

## Project Overview

This project contains two components:

- Protocol Buffer compiler plugin (protoc-gen-objc), that will allow (protoc) to generate the specialized Objective-C classes necessary to both read and write instances of the messages.
- Protocol Buffer static library, written in Objective-C that you link into any project that you want protobuf support for.

The (protoc-gen-objc) compiler plugin supports almost all the features of the protobuf 2 language.  Once installed, (protoc) will generate Objective-C classes when the "--objc_out" parameter is used to process a .proto file. These classes, along with the supplied static library, will then allow your code to read and write protobuf instances simply and in a typesafe manner.

## Installation

1. Download source or clone repository to local machine
2. `cd` into root directory of project
3. Run `$ ./autogen.sh`
4. Run `$ ./configure`
5. Run `$ make` and `$ make install`
6. Verify that you have correctly installed protoc-gen-objc `$ protoc --objc_out=./ foo.proto`

If this fails make sure you have autoconf/automake installed and that protoc-gen-objc is in your $PATH.

After building

# Credits

Booyah Inc.
-------------------------------------------------------------------------------
- Jon Parise <jon@booyah.com>


Google Protocol Buffers, Objective C
-------------------------------------------------------------------------------
- Cyrus Najmabadi  (http://code.google.com/p/metasyntactic/wiki/ProtocolBuffers)
- Sergey Martynov  (http://github.com/martynovs/protobuf-objc)


Google Protocol Buffers
-------------------------------------------------------------------------------
- Kenton Varda, Sanjay Ghemawat, Jeff Dean, and others
