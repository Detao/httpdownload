#ifndef _WIN32_NETWORK_H_
#define _WIN32_NETWORK_H_

#include <winsock2.h>
#include <WinInet.h>
#include <Shlwapi.h>
#include <Ws2tcpip.h>

#define SOCKET_GET_ERROR()      WSAGetLastError()
#define SOCKET_SET_ERROR(value) WSASetLastError(value)
#define SOCKET_ERRORNAME(name)  WSA##name

#endif


