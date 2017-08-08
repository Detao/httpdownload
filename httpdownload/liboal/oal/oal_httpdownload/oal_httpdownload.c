#include "oal_httpdownload.h"
#include "HTTPClient.h"
///////////////////////////////////////////////////////////////////////////////
//
// Function     : HTTPDebug
// Purpose      : HTTP API Debugging callback
// Gets         : arguments
// Returns      : OAL_U32
// Last updated : 01/09/2005
//
///////////////////////////////////////////////////////////////////////////////
#ifdef _HTTP_DEBUGGING_
VOID HTTPDebug(const char* FunctionName, const char *DebugDump, OAL_U32 iLength, char *DebugDescription, ...) // Requested operation
{

	va_list            pArgp;
	char               szBuffer[2048];

	memset(szBuffer, 0, 2048);
	va_start(pArgp, DebugDescription);
	vsprintf((char*)szBuffer, DebugDescription, pArgp); //Copy Data To The Buffer
	va_end(pArgp);

	printf("%s %s %s\n", FunctionName, DebugDump, szBuffer);
}
#endif
///////////////////////////////////////////////////////////////////////////////
//
// Function     : 
// Purpose      : 
// Gets         : 
// Returns      : 
// Last updated : 01/09/2005
//
///////////////////////////////////////////////////////////////////////////////

void GetUrl_R(OAL_S8 *pUrl)
{
	if (pUrl == NULL)
	{
		return;
	}

	while (*pUrl != '\0')
	{
		if (*pUrl == '\r')
		{
			*pUrl = '\0';
			break;
		}
		pUrl++;
	}
}
///////////////////////////////////////////////////////////////////////////////
//
// Function     : 
// Purpose      : 
// Gets         : 
// Returns      : 
// Last updated : 13/07/2017
//
///////////////////////////////////////////////////////////////////////////////
OAL_S32 Is_Redirection(HTTP_SESSION_HANDLE  *pHTTP_R,
	HTTPParameters  *ClientParams)  //[IN]save URL

{
	OAL_S32                  nRetCode;
	P_HTTP_SESSION  pHTTPSession = NULL;  // Session pointer
    OAL_U32 n = 5;
    //do {
        *pHTTP_R = HTTPClientOpenRequest(0);

        // Set the Verb
        if ((nRetCode = HTTPClientSetVerb(*pHTTP_R, VerbGet)) != HTTP_CLIENT_SUCCESS)
        {
            OAL_log("HTTPClientSetVerb %d", nRetCode);
            return nRetCode;
        }
		pHTTPSession = (P_HTTP_SESSION)*pHTTP_R;
		// Send a request for the home page
		if ((nRetCode = HTTPClientSendRequest(*pHTTP_R, ClientParams->Url, NULL, 0, FALSE, 0, 0, ClientParams->Range, ClientParams->Range_V)) != HTTP_CLIENT_SUCCESS)
		{
			OAL_log("HTTPClientSendRequest_again%d", nRetCode);
            //HTTPClientCloseRequest(pHTTP_R);
            //continue;
            //OAL_log("HTTPClientSendRequest or HTTPClientRecvResponse %d", nRetCode);
            return nRetCode;
		}
		// Retrieve the the headers and analyze them
        if ((nRetCode = HTTPClientRecvResponse(*pHTTP_R, 30)) != HTTP_CLIENT_SUCCESS)
		{
			OAL_log("HTTPClientRecvResponse %d", nRetCode);
            //HTTPClientCloseRequest(pHTTP_R);
            //OAL_log("HTTPClientSendRequest or HTTPClientRecvResponse %d", nRetCode);
            return nRetCode;
		}

    //} while (n-- > 0 && nRetCode != HTTP_CLIENT_SUCCESS);

    //if (n < 0)
    //{
        //OAL_log("HTTPClientSendRequest or HTTPClientRecvResponse %d", nRetCode);
        //return nRetCode;
    //}
	if (pHTTPSession->HttpHeadersInfo.nHTTPStatus == HTTP_STATUS_OBJECT_MOVED || pHTTPSession->HttpHeadersInfo.nHTTPStatus == HTTP_STATUS_OBJECT_MOVED_PERMANENTLY)
	{
		OAL_free(ClientParams->Url);
		ClientParams->Url = OAL_malloc(strlen(pHTTPSession->HttpHeadersInfo.HttpRedirectURL.pParam) + 1);
		if (!ClientParams->Url)
		{
			return -1;
		}
		strcpy(ClientParams->Url, pHTTPSession->HttpHeadersInfo.HttpRedirectURL.pParam);

		GetUrl_R(ClientParams->Url);
        HTTPClientCloseRequest(pHTTP_R);
		nRetCode = Is_Redirection(pHTTP_R, ClientParams);
	}


	return nRetCode;

}//////////////////////////////////////////////////////////////////////////////
//
// Function     : 
// Purpose      : 
// Gets         : 
// Returns      : 0 // HTTP Success status   1 // Unknown error                  2  // an Invalid handle or possible bad pointer was passed to a function
//                3  // Buffer too small or a failure while in memory allocation 4  // an attempt to use an invalid socket handle was made
//                5  // Can't send socket parameters                             6  // Error while resolving host name
//                7  // Error while connecting to the remote server              8  // socket time out error
//                9  // Error while receiving data                               10 // Error while sending data
//                11 // Error while receiving the remote HTTP headers            12 // Could not find element within header
//                13 // The headers search clue was too large for the internal API buffer
//                14 // No content length was specified for the outgoing data. the caller should specify chunking mode in the session creation
//                15 // The HTTP chunk token that was received from the server was too big and possibly wrong
//                16 // Could not authenticate with the remote host               17 // Could not authenticate with the remote proxy // 18 // Bad or not supported HTTP verb was passed to a function   19 // a function received a parameter that was too large
//                20 // The session state prevents the current function from proceeding  21 // Could not parse the chunk length while in chunked transfer
//                22 // Could not parse curtail elements from the URL (such as the host name, HTTP prefix act')
//                23 // Could not detect key elements in the received headers     24 // Error while attempting to resize a buffer
//                25 // Authentication schema is not supported                   26 // The selected authentication schema does not match the server response
//                27 // an element was missing while parsing the digest authentication challenge  28 // Digest algorithem could be MD5 or MD5-sess other types are not supported
//                29 // Binding error30 // Tls negotiation error 64// Feature is not (yet) implemented                1000        // HTTP end of stream message
// Last updated : 13/07/2017
//
///////////////////////////////////////////////////////////////////////////////
HTTP_DOWNLOAD_HANDLE * OAL_httpDownloadOpen(char *url)

{
	HTTP_DOWNLOAD_HANDLE *head = OAL_calloc(1, sizeof(HTTP_DOWNLOAD_HANDLE));
	if (!head)
	{
		return NULL;
	}
	// Reset the parameters structure
	memset(&(head->ClientParams), 0, sizeof(HTTPParameters));
	// Parse the user command line arguments
	if (url)
	{
		head->ClientParams.Url = OAL_malloc(strlen(url) + 1);
		strcpy(head->ClientParams.Url, url);
	}
	if (strlen(head->ClientParams.Url) == 0)
	{
		OAL_free(head->ClientParams.Url);
        head->ClientParams.Url = NULL;
		OAL_free(head);
		head = NULL;
		return NULL;
    }
	if ((head->nRetCode = Is_Redirection(&(head->pHTTP_R), &head->ClientParams)) != HTTP_CLIENT_SUCCESS)
	{
		OAL_httpDownloadClose(head);
		return NULL;
	}

	return head;
}
int OAL_httpDownloadSeek(HTTP_DOWNLOAD_HANDLE *httpHandle, int offset)
{
	if (!httpHandle || offset < 0)
	{
		return -1;
	}
    sprintf(httpHandle->ClientParams.Range, "bytes=%d-", offset);
	httpHandle->ClientParams.Range_V = 1;
    HTTPClientCloseRequest(&(httpHandle->pHTTP_R));
	if ((httpHandle->nRetCode = Is_Redirection(&(httpHandle->pHTTP_R), &httpHandle->ClientParams)) != HTTP_CLIENT_SUCCESS)
	{
		return -1;
	}
	return 0;
}
int OAL_httpDownloadRead(HTTP_DOWNLOAD_HANDLE *httpHandle,
	char * Buffer,      //[OUT]save data
	int  nSize_B)    //[IN]size of our buffer				
{
	int nSize_D;
	int nSize = 0;
	char *buffer = Buffer;
	if (Buffer == NULL || httpHandle == NULL)
	{
		return -1;
	}
	// Get the data
	if (httpHandle->nRetCode == HTTP_CLIENT_SUCCESS || httpHandle->nRetCode != HTTP_CLIENT_EOS)
	{
		do {
			nSize_D = nSize_B;
			httpHandle->nRetCode = HTTPClientReadData(httpHandle->pHTTP_R, buffer, nSize_D, 0, &nSize_D);
			if (httpHandle->nRetCode != HTTP_CLIENT_SUCCESS&&httpHandle->nRetCode != HTTP_CLIENT_EOS) {
				OAL_log("HTTPClientReadData: %d", httpHandle->nRetCode);
				return nSize;
			}
			nSize += nSize_D;
			buffer += nSize_D;
			nSize_B = nSize_B - nSize_D;
		} while (nSize_B > 0 && httpHandle->nRetCode == HTTP_CLIENT_SUCCESS);
		return nSize;
	}
	return 0;
}
int OAL_httpDownloadSize(HTTP_DOWNLOAD_HANDLE *httpHandle)
{
	if (!httpHandle)
	{
		return -1;
	}
	P_HTTP_SESSION  pHTTPSession = NULL;  // Session pointer
	pHTTPSession = (P_HTTP_SESSION)httpHandle->pHTTP_R;
	return pHTTPSession->HttpHeadersInfo.nHTTPContentLength;

}
int OAL_httpDownloadClose(HTTP_DOWNLOAD_HANDLE *httpHandle)
{
	if (!httpHandle)
	{
		return -1;
	}
	if (httpHandle->ClientParams.Url)
	{
		OAL_free(httpHandle->ClientParams.Url);
		httpHandle->ClientParams.Url = NULL;
	}
	HTTPClientCloseRequest(&(httpHandle->pHTTP_R));
	OAL_free(httpHandle);
	httpHandle = NULL;
	return 0;
}
