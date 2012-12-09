#!/bin/bash

source common.sh

HB_MODULE=node

source config.sh

HB_VER=3.2

if [ $linux -eq 0 ]; then
  echo "mac ne trazi .so sa verzijom"
  HB_SO=libharbour.so
else
  HB_SO=libharbour.so.$HB_VER
fi

if [ ! -f $HB_SO ]; then
    cp -v $HB_LIB/$HB_SO .
    err_exit "libharbour $HB_SO"
else
    echo "$HB_SO exists .."
fi

echo linux=$linux

if [ ! $linux -eq 1 ]; then
 cd ../harbour
 source set_envars_mac.sh
 cd $CUR_DIR
else
     echo "linux ne treba set_envars "
fi

hbmk2 $HB_MODULE

if [ "$?" != "0" ]; then
   echo "error harbour build"
   exit 1
fi
cp -av lib$HB_MODULE.a $HB_LIB/

node-gyp configure
touch hello.cc
node-gyp build V=1


ls -l -h  build/Release/hello.node
ls -l -h  lib$HB_MODULE.a
