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

static int __counter = 0;
static int __initialized_harbour = 0;

extern HB_FUNC(DELETE_REC_SERVER_AND_DBF);
// -------------------------

extern HB_FUNC(ECHO_JSON_0);
extern HB_FUNC(ECHO_JSON);
extern HB_FUNC(EVAL_JSON);
extern HB_FUNC(HB_GT_STD);

// --------------------------------------------------

HB_FUNC( USEX );
HB_FUNC_EXTERN( MY_USE );
HB_FUNC( F18_CREATE_DIR );
HB_FUNC_EXTERN( _PATH_QUOTE );
HB_FUNC_EXTERN( ADIR );
HB_FUNC_EXTERN( DIRMAKE );
HB_FUNC_EXTERN( LOG_WRITE );
HB_FUNC( F18_IME_DBF );
HB_FUNC_EXTERN( FILEBASE );
HB_FUNC_EXTERN( GET_A_DBF_REC );
HB_FUNC_EXTERN( MY_HOME );
HB_FUNC( F18_HELP );
HB_FUNC_EXTERN( QOUT );
HB_FUNC( SET_F18_PARAMS );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( HB_PVALUE );
HB_FUNC_EXTERN( TEST_MODE );
HB_FUNC_EXTERN( ERRORLEVEL );
HB_FUNC_EXTERN( __QUIT );
HB_FUNC_EXTERN( SPACE );
HB_FUNC_EXTERN( VAL );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( STR );
HB_FUNC( PP );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( HB_VALTOSTR );
//HB_FUNC( VPN_SUPPORT );
HB_FUNC_EXTERN( PADR );
HB_FUNC_EXTERN( FETCH_METRIC );
HB_FUNC_EXTERN( MY_USER );
HB_FUNC_EXTERN( BOX );
HB_FUNC_EXTERN( DEVPOS );
HB_FUNC_EXTERN( DEVOUT );
HB_FUNC_EXTERN( SETPOS );
HB_FUNC_EXTERN( ROW );
HB_FUNC_EXTERN( COL );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( __GET );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( ATAIL );
HB_FUNC_EXTERN( READMODAL );
HB_FUNC_EXTERN( BOXC );
HB_FUNC_EXTERN( LASTKEY );
HB_FUNC_EXTERN( SET_METRIC );
//HB_FUNC_STATIC( _VPN_START_STOP );
HB_FUNC_EXTERN( HB_RUN );
HB_FUNC_EXTERN( MSGBEEP );
HB_FUNC_EXTERN( __DBGENTRY );
//HB_FUNC_INITLINES();


void init_symbols() {

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_F18_UTILS )
{ "USEX", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( USEX )}, NULL },
{ "MY_USE", {HB_FS_PUBLIC}, {HB_FUNCNAME( MY_USE )}, NULL },
{ "F18_CREATE_DIR", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( F18_CREATE_DIR )}, NULL },
{ "_PATH_QUOTE", {HB_FS_PUBLIC}, {HB_FUNCNAME( _PATH_QUOTE )}, NULL },
{ "ADIR", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADIR )}, NULL },
{ "DIRMAKE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DIRMAKE )}, NULL },
{ "LOG_WRITE", {HB_FS_PUBLIC}, {HB_FUNCNAME( LOG_WRITE )}, NULL },
{ "F18_IME_DBF", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( F18_IME_DBF )}, NULL },
{ "FILEBASE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FILEBASE )}, NULL },
{ "GET_A_DBF_REC", {HB_FS_PUBLIC}, {HB_FUNCNAME( GET_A_DBF_REC )}, NULL },
{ "MY_HOME", {HB_FS_PUBLIC}, {HB_FUNCNAME( MY_HOME )}, NULL },
{ "F18_HELP", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( F18_HELP )}, NULL },
{ "QOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( QOUT )}, NULL },
{ "SET_F18_PARAMS", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( SET_F18_PARAMS )}, NULL },
{ "CPARAMS", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "HB_PVALUE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_PVALUE )}, NULL },
{ "CTOK", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "TEST_MODE", {HB_FS_PUBLIC}, {HB_FUNCNAME( TEST_MODE )}, NULL },
{ "ERRORLEVEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORLEVEL )}, NULL },
{ "__QUIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( __QUIT )}, NULL },
{ "CHOSTNAME", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "SPACE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SPACE )}, NULL },
{ "VAL", {HB_FS_PUBLIC}, {HB_FUNCNAME( VAL )}, NULL },
{ "NPORT", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "CDATABASE", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "CUSER", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "CPASSWORD", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "CDBFDATAPATH", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "CSCHEMA", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "PP", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( PP )}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "KEYS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "HB_VALTOSTR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_VALTOSTR )}, NULL },
//{ "VPN_SUPPORT", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( VPN_SUPPORT )}, NULL },
{ "PADR", {HB_FS_PUBLIC}, {HB_FUNCNAME( PADR )}, NULL },
{ "FETCH_METRIC", {HB_FS_PUBLIC}, {HB_FUNCNAME( FETCH_METRIC )}, NULL },
{ "MY_USER", {HB_FS_PUBLIC}, {HB_FUNCNAME( MY_USER )}, NULL },
{ "BOX", {HB_FS_PUBLIC}, {HB_FUNCNAME( BOX )}, NULL },
{ "DEVPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( DEVPOS )}, NULL },
{ "M_X", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "M_Y", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "DEVOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( DEVOUT )}, NULL },
{ "SETPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETPOS )}, NULL },
{ "ROW", {HB_FS_PUBLIC}, {HB_FUNCNAME( ROW )}, NULL },
{ "COL", {HB_FS_PUBLIC}, {HB_FUNCNAME( COL )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "GETLIST", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "__GET", {HB_FS_PUBLIC}, {HB_FUNCNAME( __GET )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "DISPLAY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ATAIL", {HB_FS_PUBLIC}, {HB_FUNCNAME( ATAIL )}, NULL },
{ "READMODAL", {HB_FS_PUBLIC}, {HB_FUNCNAME( READMODAL )}, NULL },
{ "BOXC", {HB_FS_PUBLIC}, {HB_FUNCNAME( BOXC )}, NULL },
{ "LASTKEY", {HB_FS_PUBLIC}, {HB_FUNCNAME( LASTKEY )}, NULL },
{ "SET_METRIC", {HB_FS_PUBLIC}, {HB_FUNCNAME( SET_METRIC )}, NULL },
//{ "_VPN_START_STOP", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( _VPN_START_STOP )}, NULL },
{ "HB_RUN", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_RUN )}, NULL },
{ "MSGBEEP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGBEEP )}, NULL },
{ "__DBGENTRY", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGENTRY )}, NULL },
//{ "(_INITLINES)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITLINES}, NULL },
//HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_F18_UTILS, "../F18_knowhow/common/f18_utils.prg", 0x0, 0x0003 )
//HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_NODE_1 )
{ "EVAL_JSON_0", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( EVAL_JSON )}, NULL },
{ "ECHO_JSON_0", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ECHO_JSON_0 )}, NULL },
{ "ECHO_JSON", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ECHO_JSON )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_NODE_1, "node_1.prg", 0x0, 0x0003 )

}

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_F18_UTILS
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_F18_UTILS )
   #include "hbiniseg.h"
#endif




#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_NODE_1
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_NODE_1 )
   #include "hbiniseg.h"
#endif


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

Handle<Value> EvalJson(const Arguments& args)
{
  HandleScope scope;
  args.This();

  Handle<String> args1;
  char *chr;
  //if (args.Length() == 1) {
    args1 = args[0]->ToString();
  //}

  chr = TO_CHAR(args1);

     //hb_stackInit();
     //init_symbols();
     //printf("\nbefore push nill\n");
     //hb_vmPushNil();
   hb_memvarsClear(HB_TRUE);
 

  PHB_ITEM func = hb_itemPutCPtr(NULL, "eval_json");
  PHB_ITEM p1 = hb_itemPutC(NULL, chr);
  PHB_ITEM pResult = hb_itemDo( func, 1, p1, 0);

  printf("\npreuzimam parametar iz harboura sa hb_itemGetCPtr ..\n");
  //const char *ret = hb_itemGetCPtr(pRez);

  //PHB_ITEM pResult = hb_itemNew(hb_stackReturnItem());

  if (!HB_IS_STRING(pResult))
     printf("\nrezultat nije string ?!\n");


  const char *ret = hb_itemGetCPtr(pResult);
  printf("\nrezultat koji je hello.cc primio je %s\n", ret);
  Local<String> result = String::New(ret);

   // dealociraj harbour resurse
   //hb_itemRelease(func);

   hb_itemRelease(p1);
   //hb_itemRelease(pResult);

   hb_memvarsClear(HB_TRUE);

   //++ __counter;

   //if (__counter % 10 == 0)
   //hb_gcCollectAll(HB_TRUE);

   //hb_errExit();
   //hb_conRelease();
   //hb_xexit(); 
   return scope.Close(result);


}


Handle<Value> Method(const Arguments& args) {
  HandleScope scope;
  return scope.Close(String::New("world"));
}

Handle<Value> Method2(const Arguments& args)
{
   HandleScope scope;

#if 0

   PHB_ITEM p1 = hb_itemPutCPtr(NULL, eval);
   PHB_ITEM pRez = hb_itemDoC( "eval_json", 1, p1, 0);
   
   const char * ret = hb_itemGetCPtr(pRez);

   printf("\nrezultat koji je hello.cc primio je %s\n", ret);

   Local<String> result = String::New("test");

   // dealociraj harbour resurse
   //hb_itemRelease(p1);
   //hb_itemRelease(pRez);

   /*
   hb_memvarsClear(HB_TRUE);
   hb_gcCollectAll(HB_TRUE);

   hb_errExit();
   hb_conRelease();
   hb_xexit(); 
*/

   return scope.Close(result);

#endif


#if 1

   //PHB_ITEM p1 = hb_itemPutCConst(hb_stackAllocItem(), "{a:1, test:2}");
   //PHB_ITEM p1 = hb_itemPutND(NULL, 22);
   PHB_ITEM p1 = hb_itemPutCPtr(NULL, arr);
   //PHB_ITEM pRez = hb_itemDoC( "echo_json", 1, p1, 0);
   PHB_ITEM pRez = hb_itemDoC( "echo_json", 1, p1, 0);
   
   const char * ret = hb_itemGetCPtr(pRez);
   //const char * ret = NULL;
   //hb_retc(ret);

   printf("\nrezultat koji je hello.cc primio je %s\n-----xxx---\n", ret);

   Local<String> result = String::New(ret);

   //delete(ret);

   // dealociraj harbour resurse
   //hb_itemMove(p1, pRez);

   hb_itemRelease(p1);
   hb_itemRelease(pRez);

   hb_memvarsClear(HB_TRUE);
   hb_gcCollectAll(HB_TRUE);

   hb_errExit();
   hb_conRelease();
   hb_xexit(); 


   return scope.Close(result);
#endif

#if 0
   
   PHB_ITEM pRez = hb_itemDoC( "echo_json_0", 0);


   const char * ret = hb_itemGetCPtr(pRez);
   printf("\nrezultat koji je hello.cc primio je %s\n", ret);

   Local<String> result = String::New(ret);

   // dealociraj harbour resurse
   hb_itemRelease(pRez);

   return scope.Close(result);
#endif


}

void init(Handle<Object> target) {

  if (!__initialized_harbour) {
      hb_vmInit( HB_FALSE);
      hb_vmSetDefaultGT("STD");
      __initialized_harbour = 1;
  }
 
  target->Set(String::NewSymbol("eval_json"),
      FunctionTemplate::New(EvalJson)->GetFunction());



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
