#include <node.h>
#include <v8.h>

#include "hbvm.h"
#include "hbapiitm.h"
/*
#include "hbvm.h"

#include "hbvmpub.h"
#include "hbpcode.h"
#include "hbinit.h"
#include "hbxvm.h"

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC_EXTERN( ECHO_JSON );
HB_FUNC_EXTERN( QOUT );
HB_FUNC_EXTERN( STRTRAN );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( STR );


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_NODE_0 )
{ "ECHO_JSON", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ECHO_JSON )}, NULL },
{ "QOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( QOUT )}, NULL },
{ "STRTRAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( STRTRAN )}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_NODE_0, "node_0.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_NODE_0
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_NODE_0 )
   #include "hbiniseg.h"
#endif

#include "hbapi.h"
#include "hbapiitm.h"
*/


/*
#include "hbapierr.h"
#include "hbstack.h"
#include "hbvmpub.h"
*/

/*

*/

//#include "hbapicdp.h"

static int __counter = 0;
static int __initialized_harbour = 0;

/*
//#if defined( HB_PRAGMA_STARTUP )
HB_CALL_ON_STARTUP_BEGIN( _hb_codepage_Init_ );
//#else
 //   HB_CALL_ON_STARTUP_BEGIN( HB_MACRONAME_JOIN( _hb_codepage_Init_, HB_CP_ID ) )
//#endif

#define HB_CP_ID        SL852
#define HB_CP_INFO      "Slovenian CP-852"
#define HB_CP_UNITB     HB_UNITB_852
#define HB_CP_ACSORT    HB_CDP_ACSORT_NONE
#define HB_CP_UPPER     "ABC¬<8f>DÑEFGHIJKLMNOPQRSæTUVWXYZ¦"
#define HB_CP_LOWER     "abc<9f><86>dÐefghijklmnopqrsçtuvwxyz§"

#include "hbcdpreg.h"

HB_CALL_ON_STARTUP_END( _hb_codepage_Init_ );
*/

/*
HB_FUNC_EXTERN(ECHO_JSON);

//void init_symbols() {

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_F18_UTILS )
{ "ECHO_JSON", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ECHO_JSON )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_NODE_1, "node_1.prg", 0x0, 0x0003 )
*/

/*
#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_NODE_1
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_NODE_1 )
   #include "hbiniseg.h"
#endif
*/

/*
HB_FUNC_EXTERN( HB_GT_STD );
void _hb_lnk_ForceLink_build( void )
{
     HB_FUNC_EXEC( HB_GT_STD );
}

HB_CALL_ON_STARTUP_BEGIN( hb_lnk_SetDefault_build )
     s_defaultGT = "STD";
HB_CALL_ON_STARTUP_END( hb_lnk_SetDefault_build )
*/

using namespace v8;

char arr[40] = "{a: 1, test:2}";
char eval[40] = "{\"eval\": \"+\", \"args\": [1, 2]}";

static inline char *TO_CHAR(Handle<Value> val) {

  String::Utf8Value utf8(val->ToString());

  int len = utf8.length() + 1;
  char *str = (char *) calloc(sizeof(char), len);
  strncpy(str, *utf8, len);

  return str;
}

Handle<Value> EchoJson(const Arguments& args)
{
  HandleScope scope;
  args.This();

  Handle<String> args1;
  char *chr;
    args1 = args[0]->ToString();

  chr = TO_CHAR(args1);

  hb_memvarsClear(HB_TRUE);

  PHB_ITEM p1 = hb_itemPutC(NULL, chr);
  PHB_ITEM func = hb_itemPutCPtr(NULL, "echo_json");
  p1 = hb_itemPutC(NULL, chr); 
  PHB_ITEM pResult = hb_itemDo( func, 1, p1, 0);

  printf("\npreuzimam parametar iz harboura sa hb_itemGetCPtr ..\n");

  if (!HB_IS_STRING(pResult))
     printf("\nrezultat nije string ?!\n");


  const char *ret = hb_itemGetCPtr(pResult);
  printf("\nrezultat koji je hello.cc primio je %s\n", ret);
  Local<String> result = String::New(ret);

  //hb_itemRelease(p1);
  hb_itemRelease(pResult);

  hb_memvarsClear(HB_TRUE);

 
  return scope.Close(result);


}

Handle<Value> Hello(const Arguments& args) {
  HandleScope scope;
  return scope.Close(String::New("world"));
}

void init(Handle<Object> target) {

  if (!__initialized_harbour) {

      //printf("point vminit 1\n");
      hb_vmInit( HB_FALSE);
      //printf("point std 2\n");
      //hb_vmSetDefaultGT("STD");

      hb_itemDoC( "init_harbour_hello_node", 0, 0);
      printf("point 3\n");
      __initialized_harbour = 1;
  }
 
  target->Set(String::NewSymbol("echo_json"),
     FunctionTemplate::New(EchoJson)->GetFunction());


  target->Set(String::NewSymbol("hello"),
      FunctionTemplate::New(Hello)->GetFunction());


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
