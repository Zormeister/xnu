#! /bin/bash

# makes life easier when running ProjectBuilder

export SRCROOT=$PWD
export OBJROOT=$PWD
export SYMROOT=$PWD/sym

SDK=$(xcrun --sdk macosx10.15.internal -show-sdk-path)

if [ ! "$SDK" ]; then
SDK=$(xcrun --sdk macosx -show-sdk-path)
fi

# will we ever build armv7?
# actually it might be useful to have an ARMv7/ARM32 build of darwinOS for BCM2837
ARM_MACHINES=("S7002", "T8002", "T8004")

# dont't bother with 2711, 2712 or VMQ yet
ARM64_MACHINES=("T7000" "T7001" "S8000" "S8001" "T8010" "T8011" "BCM2837")

# do i even need to DSTROOT
make ARCH_CONFIGS="X86_64"
make ARCH_CONFIGS="X86_64" install_config

for i in $ARM64_MACHINES; do 
make ARCH_CONFIGS="ARM64" MACHINE_CONFIGS="$ARM64_MACHINES[$i]"
make ARCH_CONFIGS="ARM64" MACHINE_CONFIGS="$ARM64_MACHINES[$i] install"
fi