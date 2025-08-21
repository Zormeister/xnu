#! /bin/bash

# Handle libplatform here

if [ -f $PWD/depconfig/libplatform ] then

git clone --branch $(cat $PWD/depconfig/libplatform) https://github.com/apple-oss-distributions/libplatform.git ~/libplatform
mkdir -p $(xcrun --sdk macosx -show-sdk-path)/usr/local/include/os/internal
cp ~/libplatform/private/os/internal/* $(xcrun --sdk macosx -show-sdk-path)/usr/local/include/os/internal/

fi
