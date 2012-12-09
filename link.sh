

LD=g++
LD=gcc


harbour -gc3 -n node_0.prg

cd build

HBMK2="-Wl,--start-group -lhbextern -lhbdebug -lhbvm -lhbrtl -lhblang -lhbcpage -lgtcgi -lgtpca -lgtstd -lgttrm -lhbrdd -lhbuddall -lhbusrrdd -lrddntx -lrddcdx -lrddnsx -lrddfpt -lhbrdd -lhbhsx -lhbsix -lhbmacro -lhbcplr -lhbpp -lhbcommon -lm -ldl -lrt -lz -lhbpcre   -Wl,--end-group -L/opt/knowhowERP/hbout/lib/harbour"


LIBS="-lhbextern -lhbdebug -lhbvm -lhbrtl -lhblang -lhbcpage -lgtstd -lgttrm -lhbrdd -lhbuddall -lhbusrrdd -lrddntx -lrddcdx -lrddfpt -lhbrdd -lhbhsx -lhbsix -lhbmacro -lhbcplr -lhbpp -lhbcommon -lm -ldl -lrt -lz -lhbpcre"

LFLAG="-L/opt/knowhowERP/hbout/lib/harbour"
IFLAG="-I/opt/knowhowERP/hbout/include/harbour"
CMD="$LD -shared -pthread -m32  -o Release/hello.node $IFLAG ../stub.c  ../node_0.c Release/obj.target/hello/hello.o $LFLAG -Wl,--start-group $LIBS -Wl,--end-group"
echo $CMD
$CMD


#-L/opt/knowhowERP/hbout/lib/harbour  -lhbct -Wl,-Bstatic -lpq -lhbpgsql -lhbtip -lminizip -lhbmzip -lgtstd -lhbdebug -lnode -Wl,-Bdynamic -lharbour
cd .. 
 
ls -l build/Release/hello.node

# SOLINK_MODULE(target) Release/obj.target/hello.node


# gcc -o test test.c node_0.c -L/opt/knowhowERP/hbout/lib/harbour -I/opt/knowhowERP/hbout/include/harbour -lharbour -lxhb






