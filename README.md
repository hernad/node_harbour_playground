# node - harbour

## node

    node-gyp configure
    node-gyp build

    HB_LIB=/opt/knowhowERP/hbout/lib/harbour/
    cp $HB_LIB/libharbour.dylib .
    node hello.js

## harbour


    HB_LIB=/opt/knowhowERP/hbout/lib/harbour/
    hbmk2 node
    cp libnode.a $HB_LIB

## usage

    export LD_LIBRARY_PATH=$HB_LIB:.
    node hello.js

## Reference
 
 - http://redmine.bring.out.ba/projects/harbour-b-out-ba/wiki/HarbourRunFromRuby


## bench

## mac
   - 300 000 83minute, 92 MB RAM
   - 300 000 2 minute, 110 MB RAM bez hb_gc .... !

## linux
    - 300 000 5m26sec, 65 MB RAM bez hb_gc
