#ifndef _led_H
#define _led_H
#include "system.h"



#define LED_KT PBout(12) //���������ſ�
#define LED_WS PBout(0) //���ҵ����ſ�
#define JDY_FS PBout(1) //���Ƽ̵����������ſ�
	
extern void ledshow(void);
extern void LED_Init(void);
#endif
