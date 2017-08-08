#ifndef _OAL_BROADCAST_H_
#define _OAL_BROADCAST_H_

int OAL_socketUDPCast();
int OAL_socketUDPCastSend(int s, unsigned short port, char *data, int len);
int OAL_socketUDPCastRecv(int s, unsigned short port, char *data, int len);
int OAL_socketInitServer(unsigned short *port, int use_ipv6, int use_udp);


#endif


