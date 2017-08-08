#ifndef _OAL_MEM_H_
#define _OAL_MEM_H_

#include "oal_type.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Memory
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ENABLE_OAL_MEMORY_STATISTICAL
#ifdef ENABLE_OAL_MEMORY_STATISTICAL
#define OAL_malloc(x) OAL_malloc2(x, __FILE__, __LINE__)
#define OAL_calloc(x,y) OAL_calloc2(x, y, __FILE__, __LINE__)
#define OAL_realloc(x,y) OAL_realloc2(x, y, __FILE__, __LINE__)
#define OAL_free(x) OAL_free2(x, __FILE__, __LINE__)//do{if(x)OAL_free2(x);x=0;}while(0)
#else
#define OAL_malloc(x) OAL_malloc1(x)
#define OAL_calloc(x,y) OAL_calloc1(x,y)
#define OAL_realloc(x,y) OAL_realloc1(x,y)
#define OAL_free(x) OAL_free1(x)//do{if(x)OAL_free1(x);x=0;}while(0)
#endif

unsigned int OAL_MemFreeSize();
void* OAL_malloc1(OAL_U32 size);
void* OAL_malloc2(OAL_U32 size, char *file, int line);
void* OAL_calloc1(OAL_U32 count, OAL_U32 size);
void* OAL_calloc2(OAL_U32 count, OAL_U32 size, char *file, int line);
void* OAL_realloc1(void *memory, OAL_U32 size);
void* OAL_realloc2(void *memory, OAL_U32 size, char *file, int line);
void OAL_free1(void *memory);
void OAL_free2(void *memory, char *file, int line);

void *OAL_memcpy(void *dst, const void *src, OAL_U32 size);
void* OAL_memset(void *dst, int c, OAL_U32 size);
void OAL_InitMemoryUsage();
void OAL_DumpMemoryUsage(unsigned int overSize2display);

#endif


