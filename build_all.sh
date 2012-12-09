#!/bin/bash

source common.sh

source config.sh
LIBH=$HB_LIB/libharbour.so

if [ ! -f libharbour.so ]; then
    cp -v $LIBH .
    err_exit "libharbour"
else
    echo "$LIBH exists .."
fi

echo linux=$linux

if [ ! $linux -eq 1 ]; then
 cd ../harbour
 source set_envars_mac.sh
 cd $CUR_DIR
else
     echo "linux ne treba set_envars "
fi

hbmk2 node

if [ "$?" != "0" ]; then
   echo "error harbour build"
   exit 1
fi
cp -av libnode.a $HB_LIB/

node-gyp configure
touch hello.cc
node-gyp build

