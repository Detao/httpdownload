#ifndef _OAL_MESSAGE_H_
#define _OAL_MESSAGE_H_

#include "oal_type.h"

// OAL_MESSAGE
typedef struct {
	unsigned short id;
	unsigned short priority;
	unsigned int wParam;
	unsigned int lParam;
	void*		 data;
}OAL_MESSAGE_BODY;

typedef struct {
	unsigned short				msg_num;
	unsigned short				msg_max_count;
	unsigned short				msg_get_index;
	unsigned short				msg_post_index;
	OAL_SEM						msg_get_sem;
	OAL_SEM						msg_post_sem;
	OAL_MESSAGE_BODY			*msg_buff;
	OAL_MUTEX					get_lock;
	OAL_MUTEX					post_lock;
}OAL_MESSAGE;

OAL_MESSAGE *OAL_MessageCreate(unsigned short max_count);
void OAL_MessageDestroy(OAL_MESSAGE *msg);

//Blocking API:  if the message buffer is full, the api will blocking until anohter thread get to an exist message.
void OAL_MessageSend(OAL_MESSAGE *msg, OAL_MESSAGE_BODY body);

//Unblocking API: may failed if the message buffer is full, it will return immediately
OAL_RESULT OAL_MessagePost(OAL_MESSAGE *msg, OAL_MESSAGE_BODY body);

OAL_RESULT OAL_MessageGet(OAL_MESSAGE *msg, OAL_MESSAGE_BODY *pmsg, unsigned int timoutInMilliSeconds);
OAL_RESULT OAL_MessagePeek(OAL_MESSAGE *msg, OAL_MESSAGE_BODY *pmsg, unsigned int timoutInMilliSeconds);


#endif


