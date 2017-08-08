#ifndef _OAL_SOCKET_H_
#define _OAL_SOCKET_H_

#ifdef _WIN32
#include "win32socket.h"
#endif

#ifdef _MARVELL_MXX00
#include "mw300socket.h"
#endif

#ifdef _MT768X
#include "mt768xsocket.h"
#endif

#include "oal_type.h"

#ifndef SHUT_RD
#  define SHUT_RD SD_RECEIVE
#endif
#ifndef SHUT_WR
#  define SHUT_WR SD_SEND
#endif
#ifndef SHUT_RDWR
#  define SHUT_RDWR SD_BOTH
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// network - power management API
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#undef _MUSICENGINE_SOCKET_STATISTICAL
#ifdef _MUSICENGINE_SOCKET_STATISTICAL
#define OAL_socket(x,y,z) OAL_socket2(x,y,z, __FILE__, __LINE__)
#define OAL_accept(x,y,z) OAL_accept2(x, y,z, __FILE__, __LINE__)
#else
#define OAL_socket(x,y,z) OAL_socket1(x,y,z)
#define OAL_accept(x,y,z) OAL_accept1(x, y,z)
#endif

int OAL_socket1(int domain, int type, int protocol);
int OAL_socket2(int domain, int type, int protocol, char *file, int line);
int OAL_accept1(int s, struct sockaddr *addr, socklen_t *addrlen);
int OAL_accept2(int s, struct sockaddr *addr, socklen_t *addrlen, char *file, int line);
int OAL_socketClose(int s);
int OAL_socketBind(int s, const struct sockaddr *name, socklen_t namelen);
int OAL_socketShutdown(int s, int how);
int OAL_socketGetPeerName(int s, struct sockaddr *name, socklen_t *namelen);
int OAL_socketGetSockName(int s, struct sockaddr *name, socklen_t *namelen);
int OAL_socketGetSockOpt(int s, int level, int optname, void *optval, socklen_t *optlen);
int OAL_socketSetSockOpt(int s, int level, int optname, const void *optval, socklen_t optlen);
int OAL_socketConnect(int s, const struct sockaddr *name, socklen_t namelen);
int OAL_socketListen(int s, int backlog);
int OAL_socketRecv(int s, void *mem, size_t len, int flags);
int OAL_socketRecvFrom(int s, void *mem, size_t len, int flags, struct sockaddr *from, socklen_t *fromlen);
int OAL_socketSend(int s, const void *dataptr, size_t size, int flags);
int OAL_socketSendTo(int s, const void *dataptr, size_t size, int flags, const struct sockaddr *to, socklen_t tolen);
int OAL_socketSelect(int maxfdp1, fd_set *readset, fd_set *writeset, fd_set *exceptset, struct timeval *timeout);
int OAL_socketIoCtl(int s, long cmd, void *argp);
int OAL_socketParseAddress(int family, const char *src, void *dst, int dstlen);
int OAL_socketSetNONBlock(int s);

// hardware method
int OAL_SetMACVer6(char *macAddr);
int OAL_SetIp(int ip);

int OAL_GetMACVer(char *mcVer); // length is lessthan 20 chars
int OAL_GetMACVer6(char *macAddr); // length is 6 chars
int OAL_GetIp();
int OAL_GetHWVer(char *hwVer); // length is lessthan 20 chars
int OAL_GetSWVer(char *swVer); // length is lessthan 20 chars

OAL_BOOL OAL_InitNetwork();
OAL_BOOL OAL_UninitNetwork();


#endif
