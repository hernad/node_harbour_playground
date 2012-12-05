#include <node.h>
#include <v8.h>

//#include "hbapiitm.h"
//#include "hbapierr.h"


#include "hbapi.h"
#include "hbapiitm.h"
#include "hbapierr.h"
#include "hbvm.h"
#include "hbstack.h"

#include "hbvmpub.h"
#include "hbinit.h"

extern HB_FUNC(ECHO_JSON_0);
extern HB_FUNC(ECHO_JSON);

HB_EXTERN_BEGIN
extern  char * s_defaultGT;
extern  char * s_pszLinkedMain;
HB_EXTERN_END

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_NODE_1 )
{ "ECHO_JSON_0", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ECHO_JSON_0 )}, NULL },
{ "ECHO_JSON", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ECHO_JSON )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_NODE_1, "node_1.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_NODE_1
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_NODE_1 )
   #include "hbiniseg.h"
#endif




/*
HB_FUNC_EXTERN( HB_GT_CRS );
void _hb_lnk_ForceLink_build( void )
{
     HB_FUNC_EXEC( HB_GT_CRS );
}

HB_CALL_ON_STARTUP_BEGIN( hb_lnk_SetDefault_build )
     s_defaultGT = "CRS";
HB_CALL_ON_STARTUP_END( hb_lnk_SetDefault_build )
*/


using namespace v8;

Handle<Value> Method(const Arguments& args) {
  HandleScope scope;
  return scope.Close(String::New("world"));
}

Handle<Value> Method2(const Arguments& args)
{
   HandleScope scope;

   //HB_FUNC_EXEC(HB_GT_CRS);
   hb_vmInit(0);

   //PHB_ITEM p1 = hb_itemPutND(NULL, 22);
   PHB_ITEM p1 = hb_itemPutCConst(hb_stackAllocItem(), "[a:1]");
   hb_itemDoC( "QOUT", 1, p1, 0);
   //PHB_ITEM pRez = hb_itemDoC( "echo_json_0", 0, 0);
   //PHB_ITEM pRez = hb_itemDoC( "echo_json_0", 0);
   PHB_ITEM pRez = hb_itemDoC( "echo_json", 1, p1, 0);

   const char * ret;

   if HB_IS_STRING(pRez) {
       ret = hb_itemGetCPtr(pRez);
       printf("rezultat koji je hello.cc primio je %s\n", ret);
       String str = String::New(ret);

       // dealociraj harbour resurse
       hb_itemRelease(pRez);
       hb_itemRelease(p1);
       return scope.Close(str);
   } else {
       return scope.Close(String::New("nepoznat hb ret ?!"));
   }

}

void init(Handle<Object> target) {
  target->Set(String::NewSymbol("hello"),
      FunctionTemplate::New(Method)->GetFunction());


  target->Set(String::NewSymbol("hello2"),
      FunctionTemplate::New(Method2)->GetFunction());

}

/*
HB_FUNC_EXTERN( HB_GT_CRS );
void _hb_lnk_ForceLink_build( void )
{
     HB_FUNC_EXEC( HB_GT_CRS );
}

HB_CALL_ON_STARTUP_BEGIN( hb_lnk_SetDefault_build )
     s_defaultGT = "CRS";
HB_CALL_ON_STARTUP_END( hb_lnk_SetDefault_build )
*/

NODE_MODULE(hello, init)
