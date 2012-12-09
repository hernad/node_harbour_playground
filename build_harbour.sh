#!/bin/bash

source common.sh
source config.sh

if [ $linux -eq 0 ]; then
  CUR_DIR=`pwd`
  cd ../harbour
  source set_envars_mac.sh
  cd $CUR_DIR
fi

bmk2 node
cp -av libnode.a $HB_LIB/


