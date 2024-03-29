#include "hbapi.h"

HB_FUNC_EXTERN( TEST );

void _hb_lnk_ForceLink_hbmk( void )
{
       HB_FUNC_EXEC( TEST );
}

#include "hbinit.h"

HB_CALL_ON_STARTUP_BEGIN( _hb_hbmk_setdef_ )
       hb_vmSetLinkedMain( "TEST" );
HB_CALL_ON_STARTUP_END( _hb_hbmk_setdef_ )

#if defined( HB_PRAGMA_STARTUP )
       #pragma startup _hb_hbmk_setdef_
#elif defined( HB_DATASEG_STARTUP )
       #define HB_DATASEG_BODY    HB_DATASEG_FUNC( _hb_hbmk_setdef_ )
       #include "hbiniseg.h"
#endif
