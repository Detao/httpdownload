#ifndef _OAL_TCP_H_
#define _OAL_TCP_H_

// all os api abstract tcp method
int OAL_TcpOpen(char *ip, int port);
int OAL_TcpSend(int sockHandle, char *buffer, unsigned int length);
int OAL_TcpRecv(int sockHandle, char *buffer, unsigned int length);
int OAL_TcpClose(int sockHandle);

int OAL_GetTimeOfDay(struct  timeval*tv, struct  timezone *tz);




#endif


