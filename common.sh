#!/bin/bash

function set_global_variables {
uname | grep -q Linux

if [ $? -eq 0 ]; then
    let 'linux=1'
    echo "ovo je linux"
else
    let 'linux=0'
    echo "ovo je garant mac"
fi

CUR_DIR=`pwd`

echo "linux=$linux,  CUR_DIR=$CUR_DIR"
}


function err_exit {

if [ ! $? -eq 0 ]; then
    echo "$1 unsuccessfull !?"
    exit 1
fi

}

set_global_variables
