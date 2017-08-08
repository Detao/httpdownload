#ifndef _OAL_THREAD_H_
#define _OAL_THREAD_H_

#include "oal_type.h"

typedef enum {
	OAL_THREAD_PRIORITY_HIGH = 4,
	OAL_THREAD_PRIORITY_LOW_HIGH = 3,
	OAL_THREAD_PRIORITY_NORMAL = 2,
	OAL_THREAD_PRIORITY_LOW_NORMAL = 1,
	OAL_THREAD_PRIORITY_LOW = 0
}OAL_THREAD_PRIORITY;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// thread
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OAL_sleep(OAL_U64 milliseconds);
unsigned int OAL_GetTickCount();

#define OAL_WAIT_FOREVER	0xFFFFFFFF
OAL_SEM OAL_SemCreate(OAL_S32 initcount);
OAL_SEM OAL_SemCreateCount(OAL_S32 initcount, OAL_S32 maxcount);
OAL_RESULT OAL_SemDestroy(OAL_SEM *sem);
OAL_RESULT OAL_SemWait(OAL_SEM *sem);
OAL_RESULT OAL_SemWaitTimeout(OAL_SEM *sem, OAL_U32 milliseconds);
void OAL_SemPost(OAL_SEM *sem);

OAL_MUTEX OAL_MutexCreate();
OAL_RESULT OAL_MutexDestroy(OAL_MUTEX *mutex);
OAL_RESULT OAL_MutexLock(OAL_MUTEX *mutex);
void OAL_MutexUnlock(OAL_MUTEX *mutex);

#define	OAL_THREAD_STACK_SIZE_1K 1024
#define	OAL_THREAD_STACK_SIZE_2K 2048
#define	OAL_THREAD_STACK_SIZE_4K 4096
#define	OAL_THREAD_STACK_SIZE_8K 8192
#define	OAL_THREAD_STACK_SIZE_16K 16384

typedef void * (*OAL_THREAD_START_ROUTINE)(void*);

typedef struct {
	void*		pUserParameter;
	void*		handle;
	OAL_SEM		exitSem;
    OAL_THREAD_START_ROUTINE pFunc;
}OAL_THREAD_HANDLE;

OAL_THREAD OAL_ThreadCreate(OAL_THREAD_START_ROUTINE pFun, void *pUserParameter, char *name, OAL_THREAD_PRIORITY pri, unsigned int stackSize);
OAL_RESULT OAL_ThreadPriority(OAL_THREAD thread, OAL_S32 nPriority);
void OAL_ThreadJoin(OAL_THREAD thread);

#endif


