#ifndef _OAL_LED_H_
#define _OAL_LED_H_


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// led  - power management API
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum {
	OAL_LED_MODE_OFF = 0,
	OAL_LED_MODE_KEEP_ON = 1,
	OAL_LED_MODE_BREATH = 2,
	OAL_LED_MODE_BLINK = 3,
	OAL_LED_MODE_BRIGHTNESS = 4,
}OAL_LED_MODE;

int OAL_LedOnOff(int ledNo, int ifOn, int blink_ms);

// R,G,B: 1 or 0, on or off
// mode: 0:turn off
//		 1:turn on (keep light)
//		 2:breathing lamp
//		 3:blink
int OAL_RGBLedOnOff(char R, char G, char B, char L, char N, OAL_LED_MODE mode);
void OAL_RestoreLed();
void OAL_InitLed();
void OAL_UninitLed();


#endif


