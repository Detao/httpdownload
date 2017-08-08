#ifndef _OAL_HTTPDOWNLOAD_H_
#define _OAL_HTTPDOWNLOAD_H_

#include "oal.h"


typedef struct _HTTPParameters
{
        OAL_S8 *Url;
        OAL_S8 Range[20];
        OAL_U32 Range_V;
} HTTPParameters;
typedef struct {
        OAL_U32  nRetCode;
        OAL_U32  pHTTP_R;
        HTTPParameters ClientParams;
}HTTP_DOWNLOAD_HANDLE;
HTTP_DOWNLOAD_HANDLE* OAL_httpDownloadOpen(char * url);
int OAL_httpDownloadRead(HTTP_DOWNLOAD_HANDLE  *httpHandle, char *buffer, int len);
int OAL_httpDownloadSeek(HTTP_DOWNLOAD_HANDLE  *httpHandle, int offset);
int OAL_httpDownloadClose(HTTP_DOWNLOAD_HANDLE *httpHandle);
int OAL_httpDownloadSize(HTTP_DOWNLOAD_HANDLE  *httpHandle);

#endif // HTTP_CLIENT_SAMPLE




