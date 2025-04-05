#! /bin/bash

# makes life easier when running ProjectBuilder

export SRCROOT=$PWD
export OBJROOT=$PWD
export SYMROOT=$PWD/sym

SDK=$(xcrun --sdk macosx.internal -show-sdk-path)

if [ ! -f "$SDK" ]; then
SDK=$(xcrun --sdk macosx -show-sdk-path)
fi

make DSTROOT=$SDK KERNEL_CONFIGS="RELEASE" ARCH_CONFIGS="X86_64" installhdrs
make DSTROOT=$SDK KERNEL_CONFIGS="RELEASE" ARCH_CONFIGS="ARM64" installhdrs
