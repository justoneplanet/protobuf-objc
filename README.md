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

The (protoc-gen-objc) compiler plugin supports almost all the features of the protobuf 2 language.  Once installed, (protoc) will be able to generate Objective-C classes when the `--objc_out` parameter is used to process a .proto file. These classes, along with the supplied static library, will then allow your code to read and write protobuf instances simply and in a typesafe manner.


## Features of this Fork

- Produces modern, ARC enabled, Objective-C code
- Supports the latest version of google protocol buffers and most language features
- Uses NSArrays for arrays of object types (PBArray for value types)
- `imports` and `global_scope` insertion points for plugins [@gregschlom][gregschlom]


[gregschlom]: https://github.com/booyah/protobuf-objc/pull/23


## Creating the Protocol Buffer Compiler Plugin

### Requirements:

Ensure the following have been built and installed the current release versions of the following tools. Some instructions may be found in this project's wiki.

- Xcode and the current "Xcode command line tools" package
- autoconf/automake
- google protocol buffers


### Building:

1. Download source or clone repository to the build machine
2. `cd` into root directory of the project
3. Run `$ ./autogen.sh`
4. Run `$ ./configure`
5. Run `$ make` and `$ make install`


### Installation:

Ensure (protoc-gen-objc) is in a directory specified by your `$PATH` environment variable. By default, it will be installed into the same directory as the google compiler (protoc).


### Generating Objective-C Classes:

The protocol buffer compiler (protoc) produces Objective-C output when invoked with the `--objc_out=` command-line flag. The parameter to the `--objc_out=` option is the directory where you want the compiler to write your Objective-C output. The compiler creates a header file and an implementation file for each .proto file input. The names of the output files are computed by taking the name of the .proto file and making two changes:

- The extension (.proto) is replaced with either .pb.h or .pb.m for the header or implementation file, respectively.
- Generated files will be in the location specified. The proto path (specified with the `--proto_path=` command-line parameter) is replaced with the output path (specified with the `--objc_out=` flag).


## Integrating the Protocol Buffer Static Library

Once you have generated the .pb.h and .pb.m files from the .proto files, you can then add them to your project. However, in order to build properly there is a one time, per project, configuration process to integrate the runtime source files.

- Open your existing project and a reference to the "ProtocolBuffers" project found in /src/runtime.
- Add "ProtocolBuffers" as a Direct Dependency of your build target.

Some instructions and screenshots illustrating this process may be found in this project's wiki.


## Credits

Protocol Buffers, Objective C iOS5, Regwez Inc.
- Ragy Eleish <ragy@regwez.com> (https://github.com/regwez/protobuf-objc-iOS5)

Protocol Buffers for Objective C, Booyah Inc.
- Jon Parise <jon@booyah.com> (https://github.com/booyah/protobuf-objc)

Google Protocol Buffers, Objective C
- Cyrus Najmabadi  (http://code.google.com/p/metasyntactic/wiki/ProtocolBuffers)
- Sergey Martynov  (http://github.com/martynovs/protobuf-objc)

Google Protocol Buffers
- Kenton Varda, Sanjay Ghemawat, Jeff Dean, and others
