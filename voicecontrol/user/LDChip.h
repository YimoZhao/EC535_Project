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
***************************�����Ƶ���******************************/

#ifndef LD_CHIP_H
#define LD_CHIP_H

#define uint8 unsigned char
#define uint16 unsigned int
#define uint32 unsigned long

//	��������״̬����������¼������������ASRʶ����������MP3����
#define LD_MODE_IDLE		0x00
#define LD_MODE_ASR_RUN		0x08
#define LD_MODE_MP3		 	0x40


//	�������״̬����������¼������������ASRʶ������е��ĸ�״̬
#define LD_ASR_NONE				0x00	//	��ʾû������ASRʶ��
#define LD_ASR_RUNING			0x01	//	��ʾLD3320������ASRʶ����
#define LD_ASR_FOUNDOK			0x10	//	��ʾһ��ʶ�����̽�������һ��ʶ����
#define LD_ASR_FOUNDZERO 		0x11	//	��ʾһ��ʶ�����̽�����û��ʶ����
#define LD_ASR_ERROR	 		0x31	//	��ʾһ��ʶ��������LD3320оƬ�ڲ����ֲ���ȷ��״̬


#define CLK_IN   	22	/* user need modify this value according to clock in */
#define LD_PLL_11			(uint8)((CLK_IN/2.0)-1)
#define LD_PLL_MP3_19		0x0f
#define LD_PLL_MP3_1B		0x18
#define LD_PLL_MP3_1D   	(uint8)(((90.0*((LD_PLL_11)+1))/(CLK_IN))-1)

#define LD_PLL_ASR_19 		(uint8)(CLK_IN*32.0/(LD_PLL_11+1) - 0.51)
#define LD_PLL_ASR_1B 		0x48
#define LD_PLL_ASR_1D 		0x1f

// LD chip fixed values.
#define        RESUM_OF_MUSIC               0x01
#define        CAUSE_MP3_SONG_END           0x20

#define        MASK_INT_SYNC				0x10
#define        MASK_INT_FIFO				0x04
#define    	   MASK_AFIFO_INT				0x01
#define        MASK_FIFO_STATUS_AFULL		0x08



void LD_reset(void);
uint8 RunASR(void);

void LD_Init_Common(void);

void LD_Init_ASR(void);

void LD_ReloadMp3Data(void);
void LD_ReloadMp3Data_2(void);

uint8 LD_ProcessAsr(uint32 RecogAddr);
void LD_AsrStart(void);
uint8 LD_AsrRun(void);
uint8 LD_AsrAddFixed(void);
uint8 LD_GetResult(void);

void LD_ReadMemoryBlock(uint8 dev, uint8 * ptr, uint32 addr, uint8 count);
void LD_WriteMemoryBlock(uint8 dev, uint8 * ptr, uint32 addr, uint8 count);

extern uint8  nLD_Mode;


	//����Ϊʶ����ĺ궨�����ر����壬0-ff�������޸�ֵ������˳��Ҫ�ظ���
#define CODE_DD       0X01	  /*�򿪿�����*/
#define CODE_GD	  	  0X02	  /*�رտ�����*/
#define CODE_QDD 	  0X03    /*�����ҵ�*/
#define CODE_DG		  0X04	  /*�ر����ҵ�*/
#define CODE_LSD	  0X05	  /*ȫ����*/
#define CODE_SSD	  0X06	  /*ȫ���ر�*/
#define CODE_DDR	  0X07	  /*�򿪼̵���*/
#define CODE_RDD	  0X08	  /*�̵����㶯*/

//#define CODE_PLAY	  0X09	  /*���Ÿ���*/
//#define CODE_NAME	  0X0A    /*���ʲô����*/
//#define CODE_DO		  0X0B    /*�����ʲô*/


void  LD3320_delay(unsigned long uldata);

#define MIC_VOL 0x43    //��˷�������������ֵԽ��Խ����Ҳ������ʶ��

#endif
