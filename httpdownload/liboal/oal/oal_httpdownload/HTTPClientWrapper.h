#ifndef HTTP_CLIENT_WRAPPER
#define HTTP_CLIENT_WRAPPER
#include "oal_type.h"
#include "oal_socket.h"
#include "oal_mem.h"
#include "oal_string.h"
#include "oal_thread.h"
#ifdef __cplusplus 
extern "C" { 
#endif

    // STDC Wrapper implimentation
    int                                 HTTPWrapperIsAscii              (int c);
    int                                 HTTPWrapperToUpper              (int c);
    int                                 HTTPWrapperToLower              (int c);
    int                                 HTTPWrapperIsAlpha              (int c);
    int                                 HTTPWrapperIsAlNum              (int c);
    char*                               HTTPWrapperItoa                 (char *buff,int i);
    void                                HTTPWrapperInitRandomeNumber    ();
    long                                HTTPWrapperGetUpTime            ();
    int                                 HTTPWrapperGetRandomeNumber     ();
    unsigned long                       HTTPWrapperGetHostByName        (char *name,unsigned long *address);
    int                                 HTTPWrapperShutDown             (int s,int in);  
    // SSL Wrapper prototypes
    int                                 HTTPWrapperSSLConnect           (int s,const struct sockaddr *name,int namelen,char *hostname);
    int                                 HTTPWrapperSSLNegotiate         (int s,const struct sockaddr *name,int namelen,char *hostname);
    int                                 HTTPWrapperSSLSend              (int s,char *buf, int len,int flags);
    int                                 HTTPWrapperSSLRecv              (int s,char *buf, int len,int flags);
    int                                 HTTPWrapperSSLClose             (int s);
    int                                 HTTPWrapperSSLRecvPending       (int s);
    // Global wrapper Functions
#define                             IToA                            HTTPWrapperItoa
#define                             GetUpTime                       HTTPWrapperGetUpTime
#define                             HostByName                      HTTPWrapperGetHostByName
#define                             InitRandomeNumber               HTTPWrapperInitRandomeNumber
#define                             GetRandomeNumber                HTTPWrapperGetRandomeNumber

#ifdef __cplusplus 
}
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Section      : Global type definitions
// Last updated : 01/09/2005
//
///////////////////////////////////////////////////////////////////////////////
#define VOID void
#ifndef NULL
#define NULL                         0
#endif
typedef int                          BOOL;

// Global socket structures and definitions
#define                              HTTP_INVALID_SOCKET (-1)
typedef struct sockaddr_in           HTTP_SOCKADDR_IN;
typedef struct timeval               HTTP_TIMEVAL; 
typedef struct hostent               HTTP_HOSTNET;
typedef struct sockaddr              HTTP_SOCKADDR;
typedef struct in_addr               HTTP_INADDR;


#endif // HTTP_CLIENT_WRAPPER
