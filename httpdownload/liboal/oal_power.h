#ifndef _OAL_POWER_H_
#define _OAL_POWER_H_

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Battery
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef void(*POWER_SAVE_STATE_CHANGE_CB_FN) (int event,void *data);
// batteryValue will be fill with 0 ~ 100
// return value: 0: in charging; 1: in battery using
int OAL_GetBattery(int *batteryValue);

void OAL_EnterPowerMode();
void OAL_ExitPowerMode();
int  OAL_GetPowerMode();
void OAL_PowerModeEnable(int e);

void OAL_InitPowerManager();
void OAL_UninitPowerManager();

#endif


