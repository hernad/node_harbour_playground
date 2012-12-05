#!/bin/bash

CUR_DIR=`pwd`
cd ../harbour
source set_envars_mac.sh
cd $CUR_DIR

HB_LIB=/opt/knowhowERP/hbout/lib/harbour/
hbmk2 node
cp -av libnode.a $HB_LIB


