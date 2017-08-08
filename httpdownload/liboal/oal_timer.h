#ifndef _OAL_TIMER_H_
#define _OAL_TIMER_H_

#include "oal_type.h"
/** OS Timer reload Options
*
*/
typedef enum {
	/**
	* Create one shot timer. Timer will be in the dormant state after
	* it expires.
	*/
	OAL_TIMER_ONE_SHOT,
	/**
	* Create a periodic timer. Timer will auto-reload after it expires.
	*/
	OAL_TIMER_PERIODIC,
} OAL_TIMER_RELOAD;

/**
* OS Timer Activate Options
*/
typedef enum {
	/** Start the timer on creation. */
	OAL_TIMER_AUTO_ACTIVATE,
	/** Do not start the timer on creation. */
	OAL_TIMER_NO_ACTIVATE,
} OAL_TIMER_ACTIVATE;

typedef void(*OAL_TIMER_ROUTINE)(void*);

int OAL_TimerCreate(OAL_TIMER *timer_t, const char *name, int ticks,
	OAL_TIMER_ROUTINE pfunc, void *cb_arg,
	OAL_TIMER_RELOAD reload, OAL_TIMER_ACTIVATE activate);

int OAL_TimerActivate(OAL_TIMER *timer_t, OAL_TIMER_ACTIVATE activate);
int OAL_TimerDelete(OAL_TIMER *timer_t);



#endif


