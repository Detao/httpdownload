#ifndef _OAL_FILE_H_
#define _OAL_FILE_H_

#include "oal_type.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File - power management API
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define 	OAL_FILE_BEGIN           0
#define 	OAL_FILE_CURRENT         1
#define 	OAL_FILE_END             2
#define		OAL_FILE_READ			0x01
#define		OAL_FILE_WRITE			0x02

typedef struct {
	OAL_S16		fdate;			/* Last modified date */
	OAL_S16		ftime;			/* Last modified time */
	OAL_U8		fattrib;		/* Attribute */
	char			lfname[256];			/* Pointer to the LFN buffer */
	OAL_U32 	lfsize;			/* Size of LFN buffer in TCHAR */
}OAL_FILE_INFORMATION;

OAL_S32 OAL_FileSize(OAL_HANDLE hFile);
OAL_S32 OAL_FileRead(OAL_HANDLE hFile, void *buf, OAL_U32 count);
OAL_S32 OAL_FileWrite(OAL_HANDLE hFile, void *buf, OAL_U32 count);
OAL_RESULT OAL_FileSeek(OAL_HANDLE hFile, int seek_mode, OAL_S64 offset);
OAL_S64 OAL_FileTell(OAL_HANDLE hFile);
OAL_HANDLE OAL_FileCreate(const char *path);
OAL_RESULT OAL_FileDelete(const char *path);
OAL_HANDLE OAL_FileOpen(const char *path, OAL_U32 flag);
OAL_RESULT OAL_FileClose(OAL_HANDLE hFile);
OAL_RESULT OAL_FileFlush(OAL_HANDLE hFile);
OAL_HANDLE OAL_DirOpen(const char *path);
OAL_RESULT OAL_DirClose(OAL_HANDLE hDir);
OAL_RESULT OAL_DirRead(OAL_HANDLE hDir, OAL_FILE_INFORMATION *info);
OAL_HANDLE OAL_FindFirst(OAL_FILE_INFORMATION *info, const char *path, const char *pattern);
OAL_RESULT OAL_FindNext(OAL_HANDLE hFind, OAL_FILE_INFORMATION *info);
OAL_RESULT OAL_FindClose(OAL_HANDLE hFind);

void OAL_InitFileSystem();
void OAL_UninitFileSystem();


#endif


