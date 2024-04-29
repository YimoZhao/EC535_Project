/***************************�����Ƶ���****************************
**  �ļ����ƣ�LDV4����ʶ�𿪷��� ��������������
**	CPU: STM32f103RCT6
**	����8MHZ
**	�����ʣ�9600 bit/S
**	���ײ�Ʒ��Ϣ��YS-LDV4����ʶ�𿪷���
**                http://yuesheng001.taobao.com
**  ���ߣ�zdings
**  ��ϵ��751956552@qq.com
**  �޸����ڣ�2014.09.15
**  ˵���������� �߱�����ʶ�𡢴���ͨ�š����������������ʾ��
** ˵�����������޸��� ICRoute��˾ ���׵�Դ���򣬰�Ȩ�������С�
***************************�����Ƶ���******************************/
/*************�˿���Ϣ********************
 * ����˵��
 LD3320�ӿ� 	  STM32�ӿ�
 * RST              PB6
 * CS   	        PB8
 * WR/SPIS          PB9
 * P2/SDCK          PB3
 * P1/SDO           PB4
 * P0/SDI           PB5
 * IRQ              PC1
 * A0		        PB7
 * RD               PA0
 --------------------------
 * K1               RST ����λ����
 * K2               PA1 ��U�̴���������
 * K3               PA2 ��δ���幦�ܣ�

 * LED1             PC4 ����ˮ�ƣ�
 * LED2             PC2 ����ˮ�ƣ�
 * LED3             PC3 ����ˮ�ƣ� 
 * LED4             PC0 ����ˮ�ƣ� 
*****************************************/

// Reg_RW.h  ��дLD3320оƬ�ļĴ������������ַ�����
#ifndef REG_RW_H
#define REG_RW_H

#define uint8 unsigned char
#define uint16 unsigned int
#define uint32 unsigned long


#define LD_RST_H() GPIO_SetBits(GPIOB, GPIO_Pin_6)
#define LD_RST_L() GPIO_ResetBits(GPIOB, GPIO_Pin_6)

#define LD_CS_H()	GPIO_SetBits(GPIOB, GPIO_Pin_8)
#define LD_CS_L()	GPIO_ResetBits(GPIOB, GPIO_Pin_8)

#define LD_SPIS_H()  GPIO_SetBits(GPIOB, GPIO_Pin_9)
#define LD_SPIS_L()  GPIO_ResetBits(GPIOB, GPIO_Pin_9)



/****************************************************************
�������� LD_WriteReg
���ܣ�дLD3320оƬ�ļĴ���
������  address, 8λ�޷�����������ַ
		dataout��8λ�޷���������Ҫд�������
����ֵ����
****************************************************************/ 
void LD_WriteReg( unsigned char address, unsigned char dataout );

/****************************************************************
�������� LD_ReadReg
���ܣ���LD3320оƬ�ļĴ���
������  address, 8λ�޷�����������ַ
����ֵ��8λ�޷�����������ȡ�Ľ��
****************************************************************/ 
unsigned char LD_ReadReg( unsigned char address );



#endif
