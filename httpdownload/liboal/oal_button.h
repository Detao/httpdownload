#ifndef _OAL_BUTTON_H_
#define _OAL_BUTTON_H_

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// button - power management API
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// btnNo must be: 0, 1, 2
// ev: 0: pressed, 1: released
// pFunc: user callback function
// usr: user data
typedef void(*OAL_BUTTON_CALLBACK)(int ev, unsigned int msTimePressed, void *usr);

int OAL_RegistButton(int btnNo, OAL_BUTTON_CALLBACK pFunc, void *usr);
void OAL_InitButton();
void OAL_UninitButton();


#endif


