#!/bin/bash

CUR_DIR=`pwd`
cd ../harbour
source set_envars_mac.sh
cd $CUR_DIR

HB_LIB=/opt/knowhowERP/hbout/lib/harbour/
hbmk2 node

if [ "$?" != "0" ]; then
   echo "error harbour build"
   exit 1
fi
cp -av libnode.a $HB_LIB

node-gyp configure
touch hello.cc
node-gyp build

