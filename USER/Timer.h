#ifndef _TIMER_H_
#define _TIMER_H_

#ifdef _TIMER_C_
	#define _TIMERDEC_
#else
	#define _TIMERDEC_ extern
#endif

_TIMERDEC_ void delay(uint32_t uSec0268);
_TIMERDEC_ void Init_Timer0(void);
_TIMERDEC_ void Time_Callback0 (void);
_TIMERDEC_ void Init_Timer2(void);
_TIMERDEC_ void Time_Callback2(void);
_TIMERDEC_ void Time_Callback3(void);

#endif