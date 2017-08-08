#ifndef _OAL_STRING_H_
#define _OAL_STRING_H_

#include "oal_type.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// String
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define OAL_assert(x) if(!(x))OAL_log("!!!!!! OAL_assert: %d£¬ %s, %s",x, __FILE__, __LINE__)
#define printf OAL_printf

void OAL_enableLog(int enable);
int	OAL_printf(const char *format, ...);
int	OAL_log(const char *format, ...);
int	OAL_logx(const char *format, ...);
int	OAL_AT_ACK(const char *format, ...);

OAL_S32 OAL_strncasecmp(char* str, char* str1, int len);
OAL_S32 OAL_strcasecmp(char* str, char* str1);
OAL_S32 OAL_strlen(char* str, OAL_U32 CodePage);

#endif


