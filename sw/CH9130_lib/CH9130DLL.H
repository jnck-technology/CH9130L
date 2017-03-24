//
//****************************************
//**  Copyright  (C)  W.ch  1999-2011   **
//**  Web:  http://www.winchiphead.com  **
//****************************************
//**  DLL for HID interface chip CH9326  **
//**  C, VC6.0                          **
//****************************************
//
// CH9130DLLӦ�ò�ӿڿ�  V1.0
// �Ͼ��ߺ�������޹�˾  ����: zyw@wch.cn 2014.01
// CH9130DLL  V1.0 
// 
// 
//

#ifndef		_CH9130_DLL_H
#define		_CH9130_DLL_H

#ifdef __cplusplus
extern "C" {
#endif
// ��VC�У�unsigned long��4�ֽڣ�unsigned short��2�ֽڣ�HANDLE�ǣ��ֽ�����
typedef void * CH9130Handle;

#define	BIT_PERI_GPIO	( 1<<0 )		/* GPIO״̬��0���رգ�1��ռ�� */
#define	BIT_PERI_UART0	( 1<<1 )		/* UART0״̬��0���رգ�1��ռ�� */
#define	BIT_PERI_UART1	( 1<<2 )		/* UART1״̬��0���رգ�1��ռ�� */
#define	BIT_PERI_SPI0	( 1<<3 )		/* SPI0״̬��0���رգ�1��ռ�� */
#define	BIT_PERI_SPI1	( 1<<4 )		/* SPI1״̬��0���رգ�1��ռ�� */
#define	BIT_PERI_PWM0	( 1<<5 )		/* PWM0״̬��0���رգ�1��ռ�� */
#define	BIT_PERI_PWM1	( 1<<6 )		/* PWM1״̬��0���رգ�1��ռ�� */
#define	BIT_PERI_PWM2	( 1<<7 )		/* PWM2״̬��0���رգ�1��ռ�� */
#define	BIT_PERI_PARA	( 1<<8 )		/* ����״̬��0���رգ�1��ռ�� */
#define	BIT_PERI_ADC	( 1<<9 )		/* ADC״̬��0���رգ�1��ռ�� */

/* ��ʵ�Ĵ����������λBIT_CTL_PARAM_REG_VIR������0 */
#define DEF_R8_PD_DIR_2     0x004000C2      // RW, GPIO PD I/O direction byte 2
#define DEF_R8_PD_DIR_3     0x004000C3      // RW, GPIO PD I/O direction byte 3
#define DEF_R8_PD_PIN_2		0x004000C6		/* GPIO0��7�������ݼĴ��� */
#define DEF_R8_PD_PIN_3		0x004000C7		/* GPIO8��15�������ݼĴ��� */
#define DEF_R8_PD_OUT_2		0x004000CA		/* GPIO0��7�������ݼĴ��� */
#define DEF_R8_PD_OUT_3		0x004000CB		/* GPIO8��15�������ݼĴ��� */
#define DEF_R8_UART0_THR	0x0040D000		/* Uart0���ͼĴ��� */
#define	DEF_R8_UART0_RBR	0x0040D000		/* Uart0���ռĴ��� */
#define DEF_R8_UART1_THR	0x0040D800		/* Uart1���ͼĴ��� */
#define	DEF_R8_UART1_RBR	0x0040D800		/* Uart1���ռĴ��� */
#define	DEF_R8_SPI0_BUFFER	0x0040C004		/* SPI0���ݻ����� */
#define	DEF_R8_SPI1_BUFFER	0x0040C804		/* SPI1���ݻ����� */
#define	DEF_R16_ADC_DATA	0x0040A004		/* ADC���ݻ����� */
#define	DEF_R32_TMR0_FIFO	0x00408010		/* PWM0���ݻ����� */
#define	DEF_R32_TMR1_FIFO	0x00408410		/* PWM1���ݻ����� */
#define	DEF_R32_TMR2_FIFO	0x00408810		/* PWM2���ݻ����� */
#define	DEF_RX_XBUS_BASE	0x00C00000		/* �ⲿ���߻�ַ��8��16��32λ */
#define DEF_R8_SLV_DOUT		0x00400016		/* ����������������Ĵ��� */
#define DEF_R8_SLV_DIN		0x00400043		/* ����������������Ĵ��� */


/* CtrlParamλ���� */
#define	BIT_CTL_PARAM_REG_DIR	( 1<<0 )		/* �Ĵ�����д����λ��0��д��1���� */
#define	BIT_CTL_PARAM_ADR_INC	( 1<<1 )		/* ��ַ��д�Լӿ���λ��0�����֣�1���Լ� */
#define	BIT_CTL_PARAM_REG_CFG	( 1<<2 )		/* �Ĵ������0�����ݼĴ�����1�����üĴ��� */
#define	BIT_CTL_PARAM_REG_VIR	( 1<<3 )		/* �Ĵ���ӳ��0����ʵ�Ĵ�����1������Ĵ��� */
#define	BIT_CTL_PARAM_REG_ACK	( 1<<4 )		/* ״̬�����0���Ƕ������Ӧ���״̬����1������λ�������ϱ���״̬�� */
#define	BIT_CTL_PARAM_SPI_RDGO	( 1<<5 )		/* SPIд��������־��д�����ݺ���Ŷ����ݣ�0����������1������ */
#define	BIT_CTL_PARAM_SPI_WRRD	( 1<<6 )		/* SPIдͬʱ����־��д����ͬʱ�����ݣ�0����ͬ����1��ͬ�� */

#define	CH9130_STATUS_OK			        (  0 )
#define	CH9130_STATUS_WIN32_ERROR	        ( -1 )
#define	CH9130_STATUS_NETWORK_ERROR	        ( -2 )
#define	CH9130_STATUS_ACK_TIMEOUT	        ( -3 )
#define	CH9130_STATUS_INVALID_PARAMETER		( -4 )
#define	CH9130_STATUS_DEV_USED		        ( -5 )
#define	CH9130_STATUS_DEV_REMOVE		    ( -6 )

typedef	 VOID ( CALLBACK	* pCheckDevRmv ) (PVOID RevData );  
/* 
��ʼ����
����  ��
		��
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130Init();

/*
��������IP�ַ���(����"192.168.1.1")ת����4�ֽ�ULONG�����ģʽ���ȼ���htonl(inet_addr(cp))
����  ��
		cp����NULL��β��IP��ַ�ַ���(����"192.168.1.1")
����ֵ��
		4�ֽ�����IP��ַ�����ģʽ������ֱֵ�Ӹ�CH9130Connect�ĵ�1������ʹ��
*/
ULONG WINAPI  CH9130StrToAddr(const char* cp);

/*
�����豸�������豸���
����  ��
		uIP��  �豸������IP��ַ
		uPort���豸�Ķ˿�
����ֵ��
		�����豸���
*/
PVOID WINAPI  CH9130Connect(ULONG uIP,USHORT uPort);

/*
�����豸�������豸���
����  ��
		strIP���豸���ַ���IP��ַ��ͬCH9130StrToAddr��cp����
		uPort���豸�Ķ˿�
����ֵ��
		�����豸���
*/
PVOID WINAPI  CH9130ConnectS(PCHAR strIP,USHORT uPort);

/*
�Ͽ����ӣ����ͷ�CH9130Connect�������Դ
����  ��
		pDevInf���豸���
		TimeOut����ʱʱ�䣬��λ�����롣��ʱ��Ҫ�����ڵȴ����������ص�FIN
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130Disconnect(PVOID pDevInf,ULONG TimeOut);

/*
�����豸�쳣ʱ�Ļص����������ڼ�鵽û��û��Ӧ�������쳣ʱ�����pFuc����
����  ��
		pDevInf���豸���
		pFuc��   �ص�������ַ
		pArg��   ����pFucʱ�����ݸ�pFuc�Ĳ���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130SetCallBack(PVOID pDevInf ,pCheckDevRmv pFuc,PVOID pArg );

/*
�������Ĵ�����
����  ��
		pDevInf���豸���
����ֵ��
		���ش�����
*/
DWORD WINAPI  CH9130GetLastError(PVOID pDevInf );

/*
������������룬��CH9130GetLastError����CH9130_STATUS_NETWORK_ERROR�����Ե���CH9130GetNetWorkErrorID���ؾ�������������
����  ��
		pDevInf���豸���
����ֵ��
		���ش�����
*/
DWORD WINAPI  CH9130GetNetWorkErrorID(PVOID pDevInf );

/*
��Ҫ�������ô�����Ϊ0
����  ��
		pDevInf���豸���
����ֵ��
		��
*/
VOID  WINAPI  CH9130SetLastError(PVOID pDevInf );

/*
����ڲ�������
����  ��
		pDevInf���豸���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ClearBufData( PVOID pDevInf );

/*
�ڲ��������ֽ�������UART0��UART1��SPI0����ģʽ��ADC��ģʽ��PARA����ģʽʱ��DLL����Ȱ����ݻ�������
��ѯ�ڲ��������ֽ���
����  ��
		pDevInf���豸���
		pRecvLen����������ʱ�����ڲ��������ֽ���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130QueryBufLen( PVOID pDevInf , PULONG pRecvLen);


/*
��ȡ�豸�Ƿ������ͻ��˴�
����  ��
		pDevInf    �豸���
		pDevStatus �豸״̬��������BIT_PERI_GPIO�ȶ���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130GetDevStatus(PVOID pDevInf,PUSHORT pDevStatus);

/*
��GPIO�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130OpenGPIO(PVOID pDevInf);

/*
�ر�GPIO�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130CloseGPIO(PVOID pDevInf);



/*
����GPIO��D0~D7����
����  ��
		pDevInf    �豸���
		Data	   BIT0��ӦD0��BIT7��ӦD7,��ӦλΪ0��ʾ���룬Ϊ1��ʾ�����
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130SetGPIODir0(PVOID pDevInf,UCHAR Data);

/*
����GPIO��D8~D15����
����  ��
		pDevInf    �豸���
		Data	   BIT0��ӦD8��BIT7��ӦD15,��ӦλΪ0��ʾ���룬Ϊ1��ʾ�����
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130SetGPIODir1(PVOID pDevInf,UCHAR Data);

/*
��ȡGPIO��D0~D7��ֵ
����  ��
		pDevInf    �豸���
		Data	   BIT0��ӦD0��BIT7��ӦD7����ӦλΪ0��ʾ�͵�ƽ��Ϊ1��ʾ�ߵ�ƽ��
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadGPIOData0(PVOID pDevInf,PUCHAR pData);

/*
��ȡGPIO��D8~D15��ֵ
����  ��
		pDevInf    �豸���
		Data	   BIT0��ӦD8��BIT7��ӦD15����ӦλΪ0��ʾ�͵�ƽ��Ϊ1��ʾ�ߵ�ƽ��
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadGPIOData1(PVOID pDevInf,PUCHAR pData);

/*
����GPIO��D0~D7��ֵ
����  ��
		pDevInf    �豸���
		Data	   BIT0��ӦD0��BIT7��ӦD7����ӦλΪ0��ʾ�͵�ƽ��Ϊ1��ʾ�ߵ�ƽ��
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130WriteGPIOData0(PVOID pDevInf,UCHAR Data);

/*
����GPIO��D8~D15��ֵ
����  ��
		pDevInf    �豸���
		Data	   BIT0��ӦD8��BIT7��ӦD15��,��ӦλΪ0��ʾ�͵�ƽ��Ϊ1��ʾ�ߵ�ƽ��
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130WriteGPIOData1(PVOID pDevInf,UCHAR Data);

/*
��UART0�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130OpenUART0(PVOID pDevInf);

/*
�ر�UART0�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130CloseUART0(PVOID pDevInf);



/*	BAUD rate setting	*/
#define B300		300
#define B600		600
#define B1200		1200
#define B2400		2400
#define B4800		4800
#define B9600		9600
#define B14400      14400
#define B19200		19200
#define B28800      28800
#define B38400		38400
#define B57600		57600
#define B76800      76800
#define B115200 	115200
#define B230400 	230400
#define B460800 	460800
#define B921600 	921600

/* Parity define	*/
#define P_ODD		0x00        //��У��
#define P_EVEN		0x01		//żУ��
#define P_MARK		0x02		//��־λ
#define P_SPC		0x03		//�հ�λ
#define P_NONE		0x04		//��У��
/* Stop bits define	*/
#define STOP_1		0x00			
#define STOP_2		0x01

/*	Data bits define		*/
#define BIT_5		0x00			
#define BIT_6		0x01
#define BIT_7		0x02
#define BIT_8		0x03
/*
��ʼ��UART0�豸
����  ��
		pDevInf    �豸���
		ulRate     ���ڲ�����(����9600�����ʣ�ulRateֱ�Ӵ�ֵ9600)��������BAUD rate setting
		ucCheck    ����λ��������Parity define
		ucStop     ֹͣλ��������Stop bits define
		ucData     ����λ��������Data bits define
		ucFlowCtrl ����ʹ�ܣ�0����ֹ��1��ʹ��
		ucFIFO     FIFO��С��0=1byte, 1=4bytes(�Ƽ�ֵ), 2=8bytes, 3=14bytes
		bHalf      ��˫��ģʽ���ƣ�0����ֹ��1��ʹ��
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130InitUART0(PVOID pDevInf,ULONG ulRate,UCHAR ucCheck,UCHAR ucStop,UCHAR ucData,UCHAR ucFIFO,UCHAR ucFlowCtrl,BOOL bHalf);

/*
��UART0�豸�������ݣ�ע�ⳬʱʱ��Ҫ���Ǵ��ڵĲ��������⣬������600�����ʷ���512�ֽڵĻ�������ʱ������9�룬��ʱʱ��Ҫ���óɴ���9��
����  ��
		pDevInf    �豸���
		pData      ����������
		Len        ���������ȣ����Ȳ�Ҫ����512�ֽ�
		TimeOut    ��ʱʱ�䣬��λ�����롣�������쳣�����豸�쳣ʱ�������û��Ӧ����������ʱ������ʱ����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130WriteUART0Data(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);

/*
��UART0�豸���ݣ�ע�ⳬʱʱ�����ڲ�������û������ʱ�ĵȴ�ʱ��
����  ��
		pDevInf    �豸���
		pData      ����������
		Len        ��������ǰ�ǻ��������ȣ����Ȳ�Ҫ����512�ֽڡ��������غ���ʵ�ʶ��������ݳ���
		TimeOut    ��ʱʱ�䣬��λ�����롣�������쳣�����豸�쳣ʱ�������û��Ӧ����������ʱ������ʱ����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadUART0Data(PVOID pDevInf,PVOID pData,PULONG Len,ULONG TimeOut);

/*
��UART1�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130OpenUART1(PVOID pDevInf);

/*
�ر�UART1�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130CloseUART1(PVOID pDevInf);



/*
��ʼ��UART1�豸
����  ��
		pDevInf    �豸���
		ulRate     ���ڲ�����(����9600�����ʣ�ulRateֱ�Ӵ�ֵ9600)��������BAUD rate setting
		ucCheck    ����λ��������Parity define
		ucStop     ֹͣλ��������Stop bits define
		ucData     ����λ��������Data bits define
		ucFlowCtrl ����ʹ�ܣ�0����ֹ��1��ʹ��
		ucFIFO     FIFO��С��0=2byte, 1=8bytes(�Ƽ�ֵ), 2=16bytes, 3=28bytes
		bHalf      ��˫��ģʽ���ƣ�0����ֹ��1��ʹ��
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130InitUART1(PVOID pDevInf,ULONG ulRate,UCHAR ucCheck,UCHAR ucStop,UCHAR ucData,UCHAR ucFIFO,UCHAR ucFlowCtrl,BOOL bHalf);

/*
��UART1�豸�������ݣ�ע�ⳬʱʱ��Ҫ���Ǵ��ڵĲ��������⣬������600�����ʷ���512�ֽڵĻ�������ʱ������9�룬��ʱʱ��Ҫ���óɴ���9��
����  ��
		pDevInf    �豸���
		pData      ����������
		Len        ���������ȣ����Ȳ�Ҫ����512�ֽ�
		TimeOut    ��ʱʱ�䣬��λ�����롣�������쳣�����豸�쳣ʱ�������û��Ӧ����������ʱ������ʱ����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130WriteUART1Data(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);

/*
��UART1�豸���ݣ�ע�ⳬʱʱ�����ڲ�������û������ʱ�ĵȴ�ʱ��
����  ��
		pDevInf    �豸���
		pData      ����������
		Len        ��������ǰ�ǻ��������ȣ����Ȳ�Ҫ����512�ֽڡ��������غ���ʵ�ʶ��������ݳ���
		TimeOut    ��ʱʱ�䣬��λ�����롣�������쳣�����豸�쳣ʱ�������û��Ӧ����������ʱ������ʱ����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadUART1Data(PVOID pDevInf,PVOID pData,PULONG Len,ULONG TimeOut);

/*
��SPI0�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130OpenSPI0(PVOID pDevInf);

/*
��ʼ��SPI0�豸
����  ��
		pDevInf    �豸���
		bDevMod    SPI����ģʽѡ��λ��0������ģʽ��1���豸ģʽ 
		ucSckMod3  ����ģʽ��ʱ��ģʽ����λ��0��ģʽ0��SCK����Ϊ�͵�ƽ����1��ģʽ3��SCK����Ϊ�ߵ�ƽ��
		ucClkDiv   ��Ƶϵ����>=2
		bHostFlowEnable  �ӻ�ģʽ������ʹ�ܣ�0����ֹ��1��ʹ��
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130InitSPI0(PVOID pDevInf,BOOL bDevMod,BOOL ucSckMod3,UCHAR ucClkDiv,BOOL bHostFlowEnable);

/*
�ر�SPI0�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130CloseSPI0(PVOID pDevInf);



/*
SPI0����ģʽ��д����
����  ��
		pDevInf    �豸���
		pData      ����������
		Len        ���������ȣ����Ȳ�Ҫ����512�ֽ�
		TimeOut    ��ʱʱ�䣬��λ�����롣�������쳣�����豸�쳣ʱ�������û��Ӧ����������ʱ������ʱ����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130WriteDataSPI0Host(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);

/*
SPI0����ģʽ�¶�����
����  ��
		pDevInf    �豸���
		pData      ����������
		Len        ��������ǰ�ǻ��������ȣ����Ȳ�Ҫ����512�ֽڡ��������غ���ʵ�ʶ��������ݳ���
		TimeOut    ��ʱʱ�䣬��λ�����롣�������쳣�����豸�쳣ʱ�������û��Ӧ����������ʱ������ʱ����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadDataSPI0Host(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);
BOOL  WINAPI  CH9130WriteReadSPI0Host(PVOID pDevInf,PVOID pWData,ULONG WLen,PVOID pRData,ULONG RLen,ULONG TimeOut);

/*
SPI0����ģʽ��д����
����  ��
		pDevInf    �豸���
		pData      ����������
		Len        ���������ȣ����Ȳ�Ҫ����512�ֽ�
		TimeOut    ��ʱʱ�䣬��λ�����롣�������쳣�����豸�쳣ʱ�������û��Ӧ����������ʱ������ʱ����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130WriteDataSPI0Device(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);

/*
SPI0����ģʽ�¶�����
����  ��
		pDevInf    �豸���
		pData      ����������
		Len        ��������ǰ�ǻ��������ȣ����Ȳ�Ҫ����512�ֽڡ��������غ���ʵ�ʶ��������ݳ���
		TimeOut    ��ʱʱ�䣬��λ�����롣�������쳣�����豸�쳣ʱ�������û��Ӧ����������ʱ������ʱ����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadDataSPI0Device(PVOID pDevInf,PVOID pData,PULONG Len,ULONG TimeOut);


/*
��SPI1�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130OpenSPI1(PVOID pDevInf);

/*
��ʼ��SPI1�豸
����  ��
		pDevInf    �豸���
		bDevMod    SPI����ģʽѡ��λ��0������ģʽ��1���豸ģʽ 
		ucSckMod3  ����ģʽ��ʱ��ģʽ����λ��0��ģʽ0��SCK����Ϊ�͵�ƽ����1��ģʽ3��SCK����Ϊ�ߵ�ƽ��
		ucClkDiv   ��Ƶϵ����>=2
		bHostFlowEnable  �ӻ�ģʽ������ʹ�ܣ�0����ֹ��1��ʹ��
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130InitSPI1(PVOID pDevInf,BOOL bDevMod,BOOL ucSckMod3,UCHAR ucClkDiv,BOOL bHostFlowEnable);

/*
�ر�SPI1�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130CloseSPI1(PVOID pDevInf);



/*
SPI1����ģʽ��д����
����  ��
		pDevInf    �豸���
		pData      ����������
		Len        ���������ȣ����Ȳ�Ҫ����512�ֽ�
		TimeOut    ��ʱʱ�䣬��λ�����롣�������쳣�����豸�쳣ʱ�������û��Ӧ����������ʱ������ʱ����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130WriteDataSPI1Host(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);

/*
SPI1����ģʽ�¶�����
����  ��
		pDevInf    �豸���
		pData      ����������
		Len        ��������ǰ�ǻ��������ȣ����Ȳ�Ҫ����512�ֽڡ��������غ���ʵ�ʶ��������ݳ���
		TimeOut    ��ʱʱ�䣬��λ�����롣�������쳣�����豸�쳣ʱ�������û��Ӧ����������ʱ������ʱ����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadDataSPI1Host(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);
BOOL  WINAPI  CH9130WriteReadSPI1Host(PVOID pDevInf,PVOID pWData,ULONG WLen,PVOID pRData,ULONG RLen,ULONG TimeOut);

/*
��PWM0�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130OpenPWM0(PVOID pDevInf);

/*
��ʼ��PWM0�豸
����  ��
		pDevInf    �豸���
		ucRpt      �ظ�������0:�ظ�1��,1:�ظ�4��,2:�ظ�8��,3:�ظ�16�� 
		bDMALoop   DMA��ַѭ��ģʽ��0����ֹ��1��ʹ��
		bPOLAR     Ĭ�������������λ��0��Ĭ�ϵ͵�ƽ���ߵ�ƽ��Ч��1��Ĭ�ϸߵ�ƽ���͵�ƽ��Ч
		PwmCyc     ���ڣ����룺10��2680000000����Сֵ����Ƶ����
		PwmDuty    ռ�ձȣ�0%��100%
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130InitPWM0(PVOID pDevInf,UCHAR ucRpt,BOOL bDMALoop,BOOL bPOLAR,ULONG PwmCyc,UCHAR PwmDuty);

/*
�ر�PWM0�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ClosePWM0(PVOID pDevInf);



/*
����PWM0�豸ռ�ձ�
����  ��
		pDevInf    �豸���
		Data       �ٷֱȣ�0~100
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130SetPWM0Duty(PVOID pDevInf,ULONG Data);

/*
ʹ��PWM0�豸���
����  ��
		pDevInf    �豸���
		Data       TRUE:��ʼ���PWM���Σ�FALSE:ֹͣ���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130SetPWM0Out(PVOID pDevInf,BOOL bEnable);

/*
��PWM1�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130OpenPWM1(PVOID pDevInf);

/*
��ʼ��PWM1�豸
����  ��
		pDevInf    �豸���
		ucRpt      �ظ�������0:�ظ�1��,1:�ظ�4��,2:�ظ�8��,3:�ظ�16�� 
		bDMALoop   DMA��ַѭ��ģʽ��0����ֹ��1��ʹ��
		bPOLAR     Ĭ�������������λ��0��Ĭ�ϵ͵�ƽ���ߵ�ƽ��Ч��1��Ĭ�ϸߵ�ƽ���͵�ƽ��Ч
		PwmCyc     ���ڣ����룺10��2680000000����Сֵ����Ƶ����
		PwmDuty    ռ�ձȣ�0%��100%
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130InitPWM1(PVOID pDevInf,UCHAR ucRpt,BOOL bDMALoop,BOOL bPOLAR,ULONG PwmCyc,UCHAR PwmDuty);

/*
�ر�PWM1�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ClosePWM1(PVOID pDevInf);



/*
����PWM1�豸ռ�ձ�
����  ��
		pDevInf    �豸���
		Data       �ٷֱȣ�0~100
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130SetPWM1Duty(PVOID pDevInf,ULONG Data);

/*
ʹ��PWM1�豸���
����  ��
		pDevInf    �豸���
		Data       TRUE:��ʼ���PWM���Σ�FALSE:ֹͣ���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130SetPWM1Out(PVOID pDevInf,BOOL bEnable);

/*
��PWM2�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130OpenPWM2(PVOID pDevInf);

/*
��ʼ��PWM2�豸
����  ��
		pDevInf    �豸���
		ucRpt      �ظ�������0:�ظ�1��,1:�ظ�4��,2:�ظ�8��,3:�ظ�16�� 
		bDMALoop   DMA��ַѭ��ģʽ��0����ֹ��1��ʹ��
		bPOLAR     Ĭ�������������λ��0��Ĭ�ϵ͵�ƽ���ߵ�ƽ��Ч��1��Ĭ�ϸߵ�ƽ���͵�ƽ��Ч
		PwmCyc     ���ڣ����룺10��2680000000����Сֵ����Ƶ����
		PwmDuty    ռ�ձȣ�0%��100%
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130InitPWM2(PVOID pDevInf,UCHAR ucRpt,BOOL bDMALoop,BOOL bPOLAR,ULONG PwmCyc,UCHAR PwmDuty);

/*
�ر�PWM2�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ClosePWM2(PVOID pDevInf);



/*
����PWM2�豸ռ�ձ�
����  ��
		pDevInf    �豸���
		Data       �ٷֱȣ�0~100
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130SetPWM2Duty(PVOID pDevInf,ULONG Data);

/*
ʹ��PWM2�豸���
����  ��
		pDevInf    �豸���
		Data       TRUE:��ʼ���PWM���Σ�FALSE:ֹͣ���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130SetPWM2Out(PVOID pDevInf,BOOL bEnable);


/*
��ADC�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130OpenADC(PVOID pDevInf);

/*
��ʼ��ADC�豸
����  ��
		pDevInf    �豸���
		ucCycClk   ADCʱ�Ӳ���ģʽ��0���ֶ��������������Զ��������ڵ�ʱ����
		bAutoWid   �Զ�������������λ��0��1ʱ�����ڣ�1��2ʱ������
		ucClkDiv   ʱ�ӷ�Ƶϵ��
		ucAdcChan  ����ͨ��
		ucAutoCnt  �Զ���������
		usRefValue δʵ��
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130InitADC(PVOID pDevInf,UCHAR ucCycClk,BOOL bAutoWid,UCHAR ucClkDiv,UCHAR ucAdcChan,UCHAR ucAutoCnt,USHORT usRefValue);

/*
�ر�ADC�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130CloseADC(PVOID pDevInf);




/*
ʹ��ADC�Զ�����
����  ��
		pDevInf    �豸���
		bEnable    TRUE:����ADC�Զ�������FALSE:�ر�ADC�Զ�����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130SetADCAutoData(PVOID pDevInf,BOOL bEnable);

/*
��������һ��ADC����
����  ��
		pDevInf    �豸���
		pData      ��������ADCֵ��ע�⣺16λΪ1����������
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadADCData(PVOID pDevInf,PUSHORT pData);

/*
�ı�ADC����ͨ��
����  ��
		pDevInf    �豸���
		Data       ͨ��ֵ��0��ͨ��0��1��ͨ��1��2��ͨ��2
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ChangeADCChan(PVOID pDevInf,UCHAR Data);

/*
�Զ�������ADC����
����  ��
		pDevInf    �豸���
		pData      ��������ַ��ע�⣺16λΪ1����������
		pLen       ����������
		TimeOut    ��ʱʱ�䣬��λ�����롣
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadADCDataStream(PVOID pDevInf,PUSHORT pData,PULONG pLen,ULONG TimeOut);

/*
��PARA�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�򿪳ɹ�����TRUE����ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130OpenPARA(PVOID pDevInf);

/*
��ʼ��PARA�豸
����  ��
		pDevInf    �豸���
		bSlvMode   ģʽѡ��,0���ⲿ����ʹ�ܣ�1����������ʹ��
		bTwoClk    �ⲿ���߶�д���ڣ�0��1��ʱ�����ڣ�1��2��ʱ������
		bWordWidth �ⲿ��������λ������0��8λ�������ߣ�1��16λ��32λ��������
		bSlvEn     �����������أ�0����ֹ��1��ʹ��
		ucRwCyc    �ⲿ���ߵĶ�д������
		ucHldCyc   �ⲿ���ߵĶ�д�źŽ�����ʱ����
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130InitPARA(PVOID pDevInf,BOOL bSlvMode,BOOL bTwoClk,BOOL bWordWidth,BOOL bSlvEn,UCHAR ucRwCyc,UCHAR ucHldCyc);

/*
�ر�PARA�豸
����  ��
		pDevInf    �豸���
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ClosePARA(PVOID pDevInf);



/*
������PARA�豸����
����  ��
		pDevInf    �豸���
		pData      ��������ַ��ע�⣺16λΪ1����������
		pLen       ��������ǰ�ǻ��������ȣ����Ȳ�Ҫ����512�ֽڡ��������غ���ʵ�ʶ��������ݳ���
		TimeOut    ��ʱʱ�䣬��λ�����롣
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadSlavePARAData(PVOID pDevInf,PVOID pData,PULONG pLen,ULONG TimeOut);

/*
д����PARA�豸����
����  ��
		pDevInf    �豸���
		pData      ��������ַ
		pLen       ����������
		TimeOut    ��ʱʱ�䣬��λ�����롣
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130WriteSlavePARAData(PVOID pDevInf,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
���ֽڷ�ʽ��������PARA�豸����
����  ��
		pDevInf    �豸���
		OffsetAddr �ⲿ���ߵ�ַ
		bAddInc    �ⲿ���ߵ�ַ�Ƿ����
		pData      ��������ַ��ע�⣺���Ȳ�Ҫ����512�ֽ�
		uLen       ����������
		TimeOut    ��ʱʱ�䣬��λ�����롣
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadMasterPARAByte(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
���ַ�ʽ��������PARA�豸����
����  ��
		pDevInf    �豸���
		OffsetAddr �ⲿ���ߵ�ַ
		bAddInc    �ⲿ���ߵ�ַ�Ƿ����
		pData      ��������ַ��ע�⣺���Ȳ�Ҫ����512�ֽ�
		uLen       ����������
		TimeOut    ��ʱʱ�䣬��λ�����롣
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadMasterPARAWord(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
��˫�ַ�ʽ��������PARA�豸����
����  ��
		pDevInf    �豸���
		OffsetAddr �ⲿ���ߵ�ַ
		bAddInc    �ⲿ���ߵ�ַ�Ƿ����
		pData      ��������ַ��ע�⣺���Ȳ�Ҫ����512�ֽ�
		uLen       ����������
		TimeOut    ��ʱʱ�䣬��λ�����롣
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130ReadMasterPARADword(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
���ֽڷ�ʽ��д����PARA�豸����
����  ��
		pDevInf    �豸���
		OffsetAddr �ⲿ���ߵ�ַ
		bAddInc    �ⲿ���ߵ�ַ�Ƿ����
		pData      ��������ַ��ע�⣺���Ȳ�Ҫ����512�ֽ�
		uLen       ����������
		TimeOut    ��ʱʱ�䣬��λ�����롣
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130WriteMasterPARAByte(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
���ַ�ʽ��д����PARA�豸����
����  ��
		pDevInf    �豸���
		OffsetAddr �ⲿ���ߵ�ַ
		bAddInc    �ⲿ���ߵ�ַ�Ƿ����
		pData      ��������ַ��ע�⣺���Ȳ�Ҫ����512�ֽ�
		uLen       ����������
		TimeOut    ��ʱʱ�䣬��λ�����롣
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130WriteMasterPARAWord(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
��˫�ַ�ʽ��д����PARA�豸����
����  ��
		pDevInf    �豸���
		OffsetAddr �ⲿ���ߵ�ַ
		bAddInc    �ⲿ���ߵ�ַ�Ƿ����
		pData      ��������ַ��ע�⣺���Ȳ�Ҫ����512�ֽ�
		uLen       ����������
		TimeOut    ��ʱʱ�䣬��λ�����롣
����ֵ��
		�ɹ�����TRUE��ʧ�ܷ���FALSE
*/
BOOL  WINAPI  CH9130WriteMasterPARADword(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);


#ifdef __cplusplus
}
#endif

#endif		// _CH9130_DLL_H