#ifndef _OAL_AUDIO_H_
#define _OAL_AUDIO_H_

#include "oal_string.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// audio sound chip  - power management API
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// audio volume interface for 100 levels
#define USER_VOLUME_LEVEL	100
#define USER_VOLUME_DEFAULT	60


//isInputMode : 0 for output, 1 for input
void* OAL_OpenAudio(unsigned char isInputMode,
	unsigned int maxInputOutputSize,
	unsigned int sampleRate, unsigned short channelNum, unsigned short bitsOfsample);
void OAL_CloseAudio(void *p);

void OAL_InputPCM(void *p, unsigned int* data, unsigned int length);
void OAL_OutputPCM(void *p, unsigned int* data, unsigned int length);

int OAL_SetVolume(int volume);
int OAL_GetVolume();
int OAL_SetMute(int onOff);
int OAL_IsHeadphoneExist();

void OAL_RestoreAudio();
void OAL_InitAudio();
void OAL_UninitAudio();


#endif


