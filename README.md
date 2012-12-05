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

## Reference
 
 - http://redmine.bring.out.ba/projects/harbour-b-out-ba/wiki/HarbourRunFromRuby


## bench


   - 300 000 83minute, 92 MB RAM
