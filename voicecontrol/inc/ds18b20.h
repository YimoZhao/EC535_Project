#ifndef _ds18b20_H
#define _ds18b20_H

#include "system.h"

#define DS0 GPIO_Pin_0	 	//�ܽź궨��


////IO��������											   
#define	DS18B20_0_DQ_OUT1 GPIO_SetBits(GPIOC,DS0)	 //IO������ߵ�ƽ
#define	DS18B20_0_DQ_OUT0 GPIO_ResetBits(GPIOC,DS0) //IO������͵�ƽ
#define DS18B20_0_DQ_IN   GPIO_ReadInputDataBit(GPIOC,DS0) //��ȡ��״̬



extern float DsTemp[6];

void DS18B20_0_IO_IN(void);
void DS18B20_0_IO_OUT(void);
uint8_t DS18B20_0_Init(void);			//��ʼ��DS18B20
float DS18B20_0_GetTemperture(void);	//��ȡ�¶�
void DS18B20_0_Start(void);		//��ʼ�¶�ת��
void DS18B20_0_Write_Byte(uint8_t dat);//д��һ���ֽ�
uint8_t DS18B20_0_Read_Byte(void);		//����һ���ֽ�
uint8_t DS18B20_0_Read_Bit(void);		//����һ��λ
uint8_t DS18B20_0_Check(void);			//����Ƿ����DS18B20
void DS18B20_0_Reset(void);			//��λDS18B20  


void Ds18b20Init(void);
int get18b20(void);


#endif
