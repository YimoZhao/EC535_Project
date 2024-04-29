/*************�˿���Ϣ********************
 * ����˵��
 LD3320�ӿ� 	  STM32�ӿ�
 * RST              PB6
 * CS   	        PB8
 * WR/SPIS          PB9
 * P2/SDCK          PB13
 * P1/SDO           PB14
 * P0/SDI           PB15
 * IRQ              PA3               
 * A0		        PB7
 * RD               PA0
 
#define LED_KT PBout(12) //���������ſ�   
#define LED_WS PBout(0) //���ҵ����ſ�
#define JDY_FS PBout(1) //���Ƽ̵����������ſ�

*****************************************/

#include "system.h"
#include "SysTick.h"
#include "variable.h"
#include "usart.h"
#include "spi.h"
#include "led.h"
#include "timer.h"
#include "LDchip.h"
#include <stdio.h>

volatile float mm=0; 

extern void  LD3320_main(void);
int main()
{  	
	
	Systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	USART1_Init(115200);
	//TIM3_Int_Init(5000-1,72-1);
	TIM4_Int_Init(999,72-1);

	LED_Init();

	//TIM_Cmd(TIM3,ENABLE);
	TIM_Cmd(TIM4,ENABLE);
    printf("��ʼ�����\r\n");
    LD3320_main();		//LD3320 ����������
	while(1)
	{
		TimerTreat();
		ledshow();
       
	}
}
