#ifndef _OAL_TYPE_H_
#define _OAL_TYPE_H_

//////////////////////////////////////////////////////////////////////////
// Basic types definitions
//////////////////////////////////////////////////////////////////////////
typedef char					OAL_S8;
typedef short					OAL_S16;
typedef int						OAL_S32;
typedef signed long long		OAL_S64;
typedef unsigned char			OAL_U8;
typedef unsigned short			OAL_U16;
typedef unsigned int			OAL_U32;
typedef unsigned long long		OAL_U64;
typedef unsigned char           OAL_BYTE;
typedef int						OAL_BOOL;
typedef	void*					OAL_HANDLE;
typedef	void*					OAL_PTR;
typedef void*					OAL_THREAD;
typedef void*					OAL_MUTEX;
typedef void*					OAL_SEM;
typedef void*					OAL_TIMER;

//////////////////////////////////////////////////////////////////////////
// Error values
//////////////////////////////////////////////////////////////////////////
typedef enum {
	OAL_SUCCESS	= 0,
	OAL_FAILED = -1,
	OAL_END = -2,
	OAL_ENOTSUPPORT	= -3
}OAL_RESULT;

#define OAL_MAX_PATH			260
#define OAL_INVALID_SOCKET  	-1
#define OAL_INVALID_SIZE		0xFFFFFFFF

//////////////////////////////////////////////////////////////////////////
// Booleans
//////////////////////////////////////////////////////////////////////////
#define OAL_FALSE			(0)
#define OAL_TRUE			(!OAL_FALSE)

#define OAL_FOURCC_BE( a, b, c, d ) \
( ((OAL_U32)d) | ( ((OAL_U32)c) << 8 ) \
| ( ((OAL_U32)b) << 16 ) | ( ((OAL_U32)a) << 24 ) )
#define OAL_TWOCC_BE( a, b ) \
( (OAL_U16)(b) | ( (OAL_U16)(a) << 8 ) )

#define OAL_FOURCC( a, b, c, d ) \
( ((OAL_U32)a) | ( ((OAL_U32)b) << 8 ) \
| ( ((OAL_U32)c) << 16 ) | ( ((OAL_U32)d) << 24 ) )
#define OAL_TWOCC( a, b ) \
( (OAL_U16)(a) | ( (OAL_U16)(b) << 8 ) )

#define MAXIMUM(a,b)            ((a) > (b) ? (a) : (b))
#define MINIMUM(a,b)            ((a) < (b) ? (a) : (b))


#endif
