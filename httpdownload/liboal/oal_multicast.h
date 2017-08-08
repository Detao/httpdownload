#ifndef _OAL_MULTICAST_H_
#define _OAL_MULTICAST_H_

int OAL_socketMultiCast(unsigned int addr, unsigned short port);
int OAL_socketLoopback(unsigned short port, int listen);
unsigned char *OAL_socketGetAddress(void *sockaddr, int *length);
void OAL_GetIpv4MulticastMac(unsigned int ipaddr, unsigned char *mac_addr);


#endif


