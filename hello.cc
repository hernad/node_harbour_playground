#include <node.h>
#include <v8.h>

//#include "hbapiitm.h"
//#include "hbapierr.h"


#include "hbapi.h"
#include "hbapiitm.h"
#include "hbapierr.h"
#include "hbvm.h"
#include "hbstack.h"

HB_EXTERN_BEGIN
extern  char * s_defaultGT;
extern  char * s_pszLinkedMain;
HB_EXTERN_END


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

/*
HB_FUNC( HB_ZEBRA_CREATE_ITF )
{
   PHB_ITEM pItem = hb_param( 1, HB_IT_STRING );
  // if( pItem )
  // {
  //    hb_zebra_ret( hb_zebra_create_itf( hb_itemGetCPtr( pItem ), hb_itemGetCLen( pItem ), hb_parni( 2 ) ) );
  // }
  // else
  //   hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
}

*/

/* NOTE: DO() as a function is a Harbour extension. [vszakats] */

/* NOTE: use hb_stackItemFromBase( uiParam ) instead of
 *       hb_param( uiParam, HB_IT_ANY ) to keep references to
 *       parameters passed by refeence. [druzus]
 */

Handle<Value> Method2(const Arguments& args)
{
   HandleScope scope;

   //HB_FUNC_EXEC(HB_GT_CRS);
   hb_vmInit(0);

   PHB_ITEM p1 = hb_itemPutND(NULL, 22);
   hb_itemDoC( "QOUT", 2, p1, p1, 0);
   /*
   HB_USHORT uiPCount = ( HB_USHORT ) hb_pcount();
   PHB_ITEM pSelf = NULL;

   if( uiPCount > 0 )
   {
      PHB_ITEM pItem = hb_param( 1, HB_IT_ANY );

      if( HB_IS_STRING( pItem ) )
      {
         //PHB_DYNS pDynSym = hb_dynsymFindName( hb_itemGetCPtr( pItem ) );
         PHB_DYNS pDynSym = hb_dynsymFindName( "QOUT" );

         if( !pDynSym )
         {
            hb_errRT_BASE( EG_NOFUNC, 1001, NULL, hb_itemGetCPtr( pItem ), HB_ERR_ARGS_BASEPARAMS );
            return scope.Close(String::New("world2 error"));
         }
         hb_vmPushDynSym( pDynSym );
      }
      else if( HB_IS_BLOCK( pItem ) )
      {
         hb_vmPushEvalSym();
         pSelf = pItem;
      }
      else if( HB_IS_SYMBOL( pItem ) )
         hb_vmPush( pItem );
      else
         uiPCount = 0;
   }

   if( uiPCount > 0 )
   {
      HB_USHORT uiParam;

      if( pSelf )
         hb_vmPush( pSelf );
      else
         hb_vmPushNil();

      for( uiParam = 2; uiParam <= uiPCount; ++uiParam )
         hb_vmPush( hb_stackItemFromBase( uiParam ) );

      if( pSelf )
         hb_vmSend( ( HB_USHORT ) ( uiPCount - 1 ) );
      else
         hb_vmProc( ( HB_USHORT ) ( uiPCount - 1 ) );
   }
   else
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );

  */
   
  return scope.Close(String::New("world2"));

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
