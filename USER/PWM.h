#ifndef _PWM_H_
#define _PWM_H_

#ifdef _PWM_C_
	#define _PWMDEC_
#else
	#define _PWMDEC_ extern
#endif

_PWMDEC_ void PWM_init();
_PWMDEC_ void SetBL_PWM(uint8_t PWMvalue);


#endif