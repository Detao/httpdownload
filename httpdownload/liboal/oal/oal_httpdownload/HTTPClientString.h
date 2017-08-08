
#ifndef _HTTP_CLIENT_STRING
#define _HTTP_CLIENT_STRING

#include "HTTPClientWrapper.h" // Cross platform support
#include "HTTPClient.h" 

///////////////////////////////////////////////////////////////////////////////
//
// Section      : HTTP Api global definitions
// Last updated : 01/09/2005
//
///////////////////////////////////////////////////////////////////////////////

BOOL                    HTTPStrInsensitiveCompare   (OAL_S8 *pSrc, OAL_S8* pDest, OAL_U32 nLength);
BOOL                    HTTPStrSearch               (OAL_S8 *pSrc, OAL_S8 *pSearched, OAL_U32 nOffset, OAL_U32 nScope,HTTP_PARAM *HttpParam);
OAL_S8                  HTTPStrExtract              (OAL_S8 *pParam,OAL_U32 nOffset,OAL_S8 Restore);
OAL_S8*                 HTTPStrCaseStr              (OAL_S8 *pSrc,OAL_U32 nSrcLength,OAL_S8 *pFind);
OAL_S8*                 HTTPStrGetToken             (OAL_S8 *pSrc, OAL_U32 nSrcLength, OAL_S8 *pDest, OAL_U32 *nDestLength);
OAL_U32                 HTTPStrGetDigestToken       (HTTP_PARAM pParamSrc, OAL_S8 *pSearched, HTTP_PARAM *pParamDest);
OAL_U32                 HTTPStrHToL                 (OAL_S8 * s); 
OAL_S8*                 HTTPStrLToH                 (OAL_S8 * dest,OAL_U32 nSrc);        
#endif
