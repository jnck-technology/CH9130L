//
//****************************************
//**  Copyright  (C)  W.ch  1999-2011   **
//**  Web:  http://www.winchiphead.com  **
//****************************************
//**  DLL for HID interface chip CH9326  **
//**  C, VC6.0                          **
//****************************************
//
// CH9130DLL应用层接口库  V1.0
// 南京沁恒电子有限公司  作者: zyw@wch.cn 2014.01
// CH9130DLL  V1.0 
// 
// 
//

#ifndef		_CH9130_DLL_H
#define		_CH9130_DLL_H

#ifdef __cplusplus
extern "C" {
#endif
// 在VC中，unsigned long是4字节，unsigned short是2字节，HANDLE是４字节类型
typedef void * CH9130Handle;

#define	BIT_PERI_GPIO	( 1<<0 )		/* GPIO状态，0：关闭，1：占用 */
#define	BIT_PERI_UART0	( 1<<1 )		/* UART0状态，0：关闭，1：占用 */
#define	BIT_PERI_UART1	( 1<<2 )		/* UART1状态，0：关闭，1：占用 */
#define	BIT_PERI_SPI0	( 1<<3 )		/* SPI0状态，0：关闭，1：占用 */
#define	BIT_PERI_SPI1	( 1<<4 )		/* SPI1状态，0：关闭，1：占用 */
#define	BIT_PERI_PWM0	( 1<<5 )		/* PWM0状态，0：关闭，1：占用 */
#define	BIT_PERI_PWM1	( 1<<6 )		/* PWM1状态，0：关闭，1：占用 */
#define	BIT_PERI_PWM2	( 1<<7 )		/* PWM2状态，0：关闭，1：占用 */
#define	BIT_PERI_PARA	( 1<<8 )		/* 并口状态，0：关闭，1：占用 */
#define	BIT_PERI_ADC	( 1<<9 )		/* ADC状态，0：关闭，1：占用 */

/* 真实寄存器，命令包位BIT_CTL_PARAM_REG_VIR必须清0 */
#define DEF_R8_PD_DIR_2     0x004000C2      // RW, GPIO PD I/O direction byte 2
#define DEF_R8_PD_DIR_3     0x004000C3      // RW, GPIO PD I/O direction byte 3
#define DEF_R8_PD_PIN_2		0x004000C6		/* GPIO0～7接收数据寄存器 */
#define DEF_R8_PD_PIN_3		0x004000C7		/* GPIO8～15接收数据寄存器 */
#define DEF_R8_PD_OUT_2		0x004000CA		/* GPIO0～7发送数据寄存器 */
#define DEF_R8_PD_OUT_3		0x004000CB		/* GPIO8～15发送数据寄存器 */
#define DEF_R8_UART0_THR	0x0040D000		/* Uart0发送寄存器 */
#define	DEF_R8_UART0_RBR	0x0040D000		/* Uart0接收寄存器 */
#define DEF_R8_UART1_THR	0x0040D800		/* Uart1发送寄存器 */
#define	DEF_R8_UART1_RBR	0x0040D800		/* Uart1接收寄存器 */
#define	DEF_R8_SPI0_BUFFER	0x0040C004		/* SPI0数据缓冲区 */
#define	DEF_R8_SPI1_BUFFER	0x0040C804		/* SPI1数据缓冲区 */
#define	DEF_R16_ADC_DATA	0x0040A004		/* ADC数据缓冲区 */
#define	DEF_R32_TMR0_FIFO	0x00408010		/* PWM0数据缓冲区 */
#define	DEF_R32_TMR1_FIFO	0x00408410		/* PWM1数据缓冲区 */
#define	DEF_R32_TMR2_FIFO	0x00408810		/* PWM2数据缓冲区 */
#define	DEF_RX_XBUS_BASE	0x00C00000		/* 外部总线基址，8、16或32位 */
#define DEF_R8_SLV_DOUT		0x00400016		/* 被动并口数据输出寄存器 */
#define DEF_R8_SLV_DIN		0x00400043		/* 被动并口数据输入寄存器 */


/* CtrlParam位定义 */
#define	BIT_CTL_PARAM_REG_DIR	( 1<<0 )		/* 寄存器读写控制位，0：写，1：读 */
#define	BIT_CTL_PARAM_ADR_INC	( 1<<1 )		/* 地址读写自加控制位，0：保持，1：自加 */
#define	BIT_CTL_PARAM_REG_CFG	( 1<<2 )		/* 寄存器类别，0：数据寄存器，1：配置寄存器 */
#define	BIT_CTL_PARAM_REG_VIR	( 1<<3 )		/* 寄存器映像，0：真实寄存器，1：虚拟寄存器 */
#define	BIT_CTL_PARAM_REG_ACK	( 1<<4 )		/* 状态包类别，0：是对命令包应答的状态包，1：是下位机主动上报的状态包 */
#define	BIT_CTL_PARAM_SPI_RDGO	( 1<<5 )		/* SPI写后连读标志，写完数据后接着读数据，0：不连读，1：连读 */
#define	BIT_CTL_PARAM_SPI_WRRD	( 1<<6 )		/* SPI写同时读标志，写数据同时读数据，0：不同读，1：同读 */

#define	CH9130_STATUS_OK			        (  0 )
#define	CH9130_STATUS_WIN32_ERROR	        ( -1 )
#define	CH9130_STATUS_NETWORK_ERROR	        ( -2 )
#define	CH9130_STATUS_ACK_TIMEOUT	        ( -3 )
#define	CH9130_STATUS_INVALID_PARAMETER		( -4 )
#define	CH9130_STATUS_DEV_USED		        ( -5 )
#define	CH9130_STATUS_DEV_REMOVE		    ( -6 )

typedef	 VOID ( CALLBACK	* pCheckDevRmv ) (PVOID RevData );  
/* 
初始化库
参数  ：
		无
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130Init();

/*
将包含的IP字符串(例如"192.168.1.1")转换成4字节ULONG，大端模式。等价于htonl(inet_addr(cp))
参数  ：
		cp，以NULL结尾的IP地址字符串(例如"192.168.1.1")
返回值：
		4字节网络IP地址，大端模式。返回值直接给CH9130Connect的第1个参数使用
*/
ULONG WINAPI  CH9130StrToAddr(const char* cp);

/*
连接设备，返回设备句柄
参数  ：
		uIP，  设备的网络IP地址
		uPort，设备的端口
返回值：
		返回设备句柄
*/
PVOID WINAPI  CH9130Connect(ULONG uIP,USHORT uPort);

/*
连接设备，返回设备句柄
参数  ：
		strIP，设备的字符型IP地址，同CH9130StrToAddr的cp参数
		uPort，设备的端口
返回值：
		返回设备句柄
*/
PVOID WINAPI  CH9130ConnectS(PCHAR strIP,USHORT uPort);

/*
断开连接，并释放CH9130Connect分配的资源
参数  ：
		pDevInf，设备句柄
		TimeOut，超时时间，单位：毫秒。超时主要是用于等待服务器返回的FIN
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130Disconnect(PVOID pDevInf,ULONG TimeOut);

/*
设置设备异常时的回调函数，库在检查到没有没有应答，网络异常时会调用pFuc函数
参数  ：
		pDevInf，设备句柄
		pFuc，   回调函数地址
		pArg，   调用pFuc时，传递给pFuc的参数
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130SetCallBack(PVOID pDevInf ,pCheckDevRmv pFuc,PVOID pArg );

/*
返回最后的错误码
参数  ：
		pDevInf，设备句柄
返回值：
		返回错误码
*/
DWORD WINAPI  CH9130GetLastError(PVOID pDevInf );

/*
返回网络错误码，在CH9130GetLastError返回CH9130_STATUS_NETWORK_ERROR，可以调用CH9130GetNetWorkErrorID返回具体的网络错误码
参数  ：
		pDevInf，设备句柄
返回值：
		返回错误码
*/
DWORD WINAPI  CH9130GetNetWorkErrorID(PVOID pDevInf );

/*
主要用来设置错误码为0
参数  ：
		pDevInf，设备句柄
返回值：
		无
*/
VOID  WINAPI  CH9130SetLastError(PVOID pDevInf );

/*
清空内部缓冲区
参数  ：
		pDevInf，设备句柄
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ClearBufData( PVOID pDevInf );

/*
内部缓冲区字节数：在UART0，UART1，SPI0被动模式，ADC流模式，PARA被动模式时，DLL库会先把数据缓冲下来
查询内部缓冲区字节数
参数  ：
		pDevInf，设备句柄
		pRecvLen，函数返回时返回内部缓冲区字节数
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130QueryBufLen( PVOID pDevInf , PULONG pRecvLen);


/*
获取设备是否被其他客户端打开
参数  ：
		pDevInf    设备句柄
		pDevStatus 设备状态，见上文BIT_PERI_GPIO等定义
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130GetDevStatus(PVOID pDevInf,PUSHORT pDevStatus);

/*
打开GPIO设备
参数  ：
		pDevInf    设备句柄
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130OpenGPIO(PVOID pDevInf);

/*
关闭GPIO设备
参数  ：
		pDevInf    设备句柄
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130CloseGPIO(PVOID pDevInf);



/*
设置GPIO的D0~D7方向
参数  ：
		pDevInf    设备句柄
		Data	   BIT0对应D0，BIT7对应D7,相应位为0表示输入，为1表示输出。
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130SetGPIODir0(PVOID pDevInf,UCHAR Data);

/*
设置GPIO的D8~D15方向
参数  ：
		pDevInf    设备句柄
		Data	   BIT0对应D8，BIT7对应D15,相应位为0表示输入，为1表示输出。
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130SetGPIODir1(PVOID pDevInf,UCHAR Data);

/*
读取GPIO的D0~D7的值
参数  ：
		pDevInf    设备句柄
		Data	   BIT0对应D0，BIT7对应D7，相应位为0表示低电平，为1表示高电平。
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadGPIOData0(PVOID pDevInf,PUCHAR pData);

/*
读取GPIO的D8~D15的值
参数  ：
		pDevInf    设备句柄
		Data	   BIT0对应D8，BIT7对应D15，相应位为0表示低电平，为1表示高电平。
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadGPIOData1(PVOID pDevInf,PUCHAR pData);

/*
设置GPIO的D0~D7的值
参数  ：
		pDevInf    设备句柄
		Data	   BIT0对应D0，BIT7对应D7，相应位为0表示低电平，为1表示高电平。
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130WriteGPIOData0(PVOID pDevInf,UCHAR Data);

/*
设置GPIO的D8~D15的值
参数  ：
		pDevInf    设备句柄
		Data	   BIT0对应D8，BIT7对应D15，,相应位为0表示低电平，为1表示高电平。
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130WriteGPIOData1(PVOID pDevInf,UCHAR Data);

/*
打开UART0设备
参数  ：
		pDevInf    设备句柄
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130OpenUART0(PVOID pDevInf);

/*
关闭UART0设备
参数  ：
		pDevInf    设备句柄
返回值：
		成功返回TRUE，失败返回FALSE
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
#define P_ODD		0x00        //奇校验
#define P_EVEN		0x01		//偶校验
#define P_MARK		0x02		//标志位
#define P_SPC		0x03		//空白位
#define P_NONE		0x04		//无校验
/* Stop bits define	*/
#define STOP_1		0x00			
#define STOP_2		0x01

/*	Data bits define		*/
#define BIT_5		0x00			
#define BIT_6		0x01
#define BIT_7		0x02
#define BIT_8		0x03
/*
初始化UART0设备
参数  ：
		pDevInf    设备句柄
		ulRate     串口波特率(例如9600波特率，ulRate直接传值9600)，见上文BAUD rate setting
		ucCheck    检验位，见上文Parity define
		ucStop     停止位，见上文Stop bits define
		ucData     数据位，见上文Data bits define
		ucFlowCtrl 流控使能，0：禁止，1：使能
		ucFIFO     FIFO大小，0=1byte, 1=4bytes(推荐值), 2=8bytes, 3=14bytes
		bHalf      半双工模式控制，0：禁止，1：使能
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130InitUART0(PVOID pDevInf,ULONG ulRate,UCHAR ucCheck,UCHAR ucStop,UCHAR ucData,UCHAR ucFIFO,UCHAR ucFlowCtrl,BOOL bHalf);

/*
向UART0设备发送数据，注意超时时间要考虑串口的波特率问题，例如在600波特率发送512字节的话，所需时间差不多是9秒，超时时间要设置成大于9秒
参数  ：
		pDevInf    设备句柄
		pData      缓冲区数据
		Len        缓冲区长度，长度不要超过512字节
		TimeOut    超时时间，单位：毫秒。在网络异常或者设备异常时，会出现没有应答的情况，这时函数超时返回
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130WriteUART0Data(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);

/*
读UART0设备数据，注意超时时间是内部缓冲区没有数据时的等待时间
参数  ：
		pDevInf    设备句柄
		pData      缓冲区数据
		Len        函数调用前是缓冲区长度，长度不要超过512字节。函数返回后是实际读到的数据长度
		TimeOut    超时时间，单位：毫秒。在网络异常或者设备异常时，会出现没有应答的情况，这时函数超时返回
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadUART0Data(PVOID pDevInf,PVOID pData,PULONG Len,ULONG TimeOut);

/*
打开UART1设备
参数  ：
		pDevInf    设备句柄
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130OpenUART1(PVOID pDevInf);

/*
关闭UART1设备
参数  ：
		pDevInf    设备句柄
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130CloseUART1(PVOID pDevInf);



/*
初始化UART1设备
参数  ：
		pDevInf    设备句柄
		ulRate     串口波特率(例如9600波特率，ulRate直接传值9600)，见上文BAUD rate setting
		ucCheck    检验位，见上文Parity define
		ucStop     停止位，见上文Stop bits define
		ucData     数据位，见上文Data bits define
		ucFlowCtrl 流控使能，0：禁止，1：使能
		ucFIFO     FIFO大小，0=2byte, 1=8bytes(推荐值), 2=16bytes, 3=28bytes
		bHalf      半双工模式控制，0：禁止，1：使能
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130InitUART1(PVOID pDevInf,ULONG ulRate,UCHAR ucCheck,UCHAR ucStop,UCHAR ucData,UCHAR ucFIFO,UCHAR ucFlowCtrl,BOOL bHalf);

/*
向UART1设备发送数据，注意超时时间要考虑串口的波特率问题，例如在600波特率发送512字节的话，所需时间差不多是9秒，超时时间要设置成大于9秒
参数  ：
		pDevInf    设备句柄
		pData      缓冲区数据
		Len        缓冲区长度，长度不要超过512字节
		TimeOut    超时时间，单位：毫秒。在网络异常或者设备异常时，会出现没有应答的情况，这时函数超时返回
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130WriteUART1Data(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);

/*
读UART1设备数据，注意超时时间是内部缓冲区没有数据时的等待时间
参数  ：
		pDevInf    设备句柄
		pData      缓冲区数据
		Len        函数调用前是缓冲区长度，长度不要超过512字节。函数返回后是实际读到的数据长度
		TimeOut    超时时间，单位：毫秒。在网络异常或者设备异常时，会出现没有应答的情况，这时函数超时返回
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadUART1Data(PVOID pDevInf,PVOID pData,PULONG Len,ULONG TimeOut);

/*
打开SPI0设备
参数  ：
		pDevInf    设备句柄
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130OpenSPI0(PVOID pDevInf);

/*
初始化SPI0设备
参数  ：
		pDevInf    设备句柄
		bDevMod    SPI主从模式选择位，0：主机模式，1：设备模式 
		ucSckMod3  主机模式下时钟模式配置位，0：模式0（SCK空闲为低电平），1：模式3（SCK空闲为高电平）
		ucClkDiv   分频系数，>=2
		bHostFlowEnable  从机模式，流控使能，0：禁止，1：使能
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130InitSPI0(PVOID pDevInf,BOOL bDevMod,BOOL ucSckMod3,UCHAR ucClkDiv,BOOL bHostFlowEnable);

/*
关闭SPI0设备
参数  ：
		pDevInf    设备句柄
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130CloseSPI0(PVOID pDevInf);



/*
SPI0主动模式下写数据
参数  ：
		pDevInf    设备句柄
		pData      缓冲区数据
		Len        缓冲区长度，长度不要超过512字节
		TimeOut    超时时间，单位：毫秒。在网络异常或者设备异常时，会出现没有应答的情况，这时函数超时返回
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130WriteDataSPI0Host(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);

/*
SPI0主动模式下读数据
参数  ：
		pDevInf    设备句柄
		pData      缓冲区数据
		Len        函数调用前是缓冲区长度，长度不要超过512字节。函数返回后是实际读到的数据长度
		TimeOut    超时时间，单位：毫秒。在网络异常或者设备异常时，会出现没有应答的情况，这时函数超时返回
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadDataSPI0Host(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);
BOOL  WINAPI  CH9130WriteReadSPI0Host(PVOID pDevInf,PVOID pWData,ULONG WLen,PVOID pRData,ULONG RLen,ULONG TimeOut);

/*
SPI0被动模式下写数据
参数  ：
		pDevInf    设备句柄
		pData      缓冲区数据
		Len        缓冲区长度，长度不要超过512字节
		TimeOut    超时时间，单位：毫秒。在网络异常或者设备异常时，会出现没有应答的情况，这时函数超时返回
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130WriteDataSPI0Device(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);

/*
SPI0被动模式下读数据
参数  ：
		pDevInf    设备句柄
		pData      缓冲区数据
		Len        函数调用前是缓冲区长度，长度不要超过512字节。函数返回后是实际读到的数据长度
		TimeOut    超时时间，单位：毫秒。在网络异常或者设备异常时，会出现没有应答的情况，这时函数超时返回
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadDataSPI0Device(PVOID pDevInf,PVOID pData,PULONG Len,ULONG TimeOut);


/*
打开SPI1设备
参数  ：
		pDevInf    设备句柄
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130OpenSPI1(PVOID pDevInf);

/*
初始化SPI1设备
参数  ：
		pDevInf    设备句柄
		bDevMod    SPI主从模式选择位，0：主机模式，1：设备模式 
		ucSckMod3  主机模式下时钟模式配置位，0：模式0（SCK空闲为低电平），1：模式3（SCK空闲为高电平）
		ucClkDiv   分频系数，>=2
		bHostFlowEnable  从机模式，流控使能，0：禁止，1：使能
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130InitSPI1(PVOID pDevInf,BOOL bDevMod,BOOL ucSckMod3,UCHAR ucClkDiv,BOOL bHostFlowEnable);

/*
关闭SPI1设备
参数  ：
		pDevInf    设备句柄
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130CloseSPI1(PVOID pDevInf);



/*
SPI1主动模式下写数据
参数  ：
		pDevInf    设备句柄
		pData      缓冲区数据
		Len        缓冲区长度，长度不要超过512字节
		TimeOut    超时时间，单位：毫秒。在网络异常或者设备异常时，会出现没有应答的情况，这时函数超时返回
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130WriteDataSPI1Host(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);

/*
SPI1主动模式下读数据
参数  ：
		pDevInf    设备句柄
		pData      缓冲区数据
		Len        函数调用前是缓冲区长度，长度不要超过512字节。函数返回后是实际读到的数据长度
		TimeOut    超时时间，单位：毫秒。在网络异常或者设备异常时，会出现没有应答的情况，这时函数超时返回
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadDataSPI1Host(PVOID pDevInf,PVOID pData,ULONG Len,ULONG TimeOut);
BOOL  WINAPI  CH9130WriteReadSPI1Host(PVOID pDevInf,PVOID pWData,ULONG WLen,PVOID pRData,ULONG RLen,ULONG TimeOut);

/*
打开PWM0设备
参数  ：
		pDevInf    设备句柄
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130OpenPWM0(PVOID pDevInf);

/*
初始化PWM0设备
参数  ：
		pDevInf    设备句柄
		ucRpt      重复次数，0:重复1次,1:重复4次,2:重复8次,3:重复16次 
		bDMALoop   DMA地址循环模式，0：禁止，1：使能
		bPOLAR     默认输出极性设置位，0：默认低电平，高电平有效，1：默认高电平，低电平有效
		PwmCyc     周期，纳秒：10～2680000000，最小值由主频决定
		PwmDuty    占空比，0%～100%
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130InitPWM0(PVOID pDevInf,UCHAR ucRpt,BOOL bDMALoop,BOOL bPOLAR,ULONG PwmCyc,UCHAR PwmDuty);

/*
关闭PWM0设备
参数  ：
		pDevInf    设备句柄
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ClosePWM0(PVOID pDevInf);



/*
设置PWM0设备占空比
参数  ：
		pDevInf    设备句柄
		Data       百分比，0~100
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130SetPWM0Duty(PVOID pDevInf,ULONG Data);

/*
使能PWM0设备输出
参数  ：
		pDevInf    设备句柄
		Data       TRUE:开始输出PWM波形，FALSE:停止输出
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130SetPWM0Out(PVOID pDevInf,BOOL bEnable);

/*
打开PWM1设备
参数  ：
		pDevInf    设备句柄
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130OpenPWM1(PVOID pDevInf);

/*
初始化PWM1设备
参数  ：
		pDevInf    设备句柄
		ucRpt      重复次数，0:重复1次,1:重复4次,2:重复8次,3:重复16次 
		bDMALoop   DMA地址循环模式，0：禁止，1：使能
		bPOLAR     默认输出极性设置位，0：默认低电平，高电平有效，1：默认高电平，低电平有效
		PwmCyc     周期，纳秒：10～2680000000，最小值由主频决定
		PwmDuty    占空比，0%～100%
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130InitPWM1(PVOID pDevInf,UCHAR ucRpt,BOOL bDMALoop,BOOL bPOLAR,ULONG PwmCyc,UCHAR PwmDuty);

/*
关闭PWM1设备
参数  ：
		pDevInf    设备句柄
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ClosePWM1(PVOID pDevInf);



/*
设置PWM1设备占空比
参数  ：
		pDevInf    设备句柄
		Data       百分比，0~100
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130SetPWM1Duty(PVOID pDevInf,ULONG Data);

/*
使能PWM1设备输出
参数  ：
		pDevInf    设备句柄
		Data       TRUE:开始输出PWM波形，FALSE:停止输出
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130SetPWM1Out(PVOID pDevInf,BOOL bEnable);

/*
打开PWM2设备
参数  ：
		pDevInf    设备句柄
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130OpenPWM2(PVOID pDevInf);

/*
初始化PWM2设备
参数  ：
		pDevInf    设备句柄
		ucRpt      重复次数，0:重复1次,1:重复4次,2:重复8次,3:重复16次 
		bDMALoop   DMA地址循环模式，0：禁止，1：使能
		bPOLAR     默认输出极性设置位，0：默认低电平，高电平有效，1：默认高电平，低电平有效
		PwmCyc     周期，纳秒：10～2680000000，最小值由主频决定
		PwmDuty    占空比，0%～100%
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130InitPWM2(PVOID pDevInf,UCHAR ucRpt,BOOL bDMALoop,BOOL bPOLAR,ULONG PwmCyc,UCHAR PwmDuty);

/*
关闭PWM2设备
参数  ：
		pDevInf    设备句柄
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ClosePWM2(PVOID pDevInf);



/*
设置PWM2设备占空比
参数  ：
		pDevInf    设备句柄
		Data       百分比，0~100
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130SetPWM2Duty(PVOID pDevInf,ULONG Data);

/*
使能PWM2设备输出
参数  ：
		pDevInf    设备句柄
		Data       TRUE:开始输出PWM波形，FALSE:停止输出
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130SetPWM2Out(PVOID pDevInf,BOOL bEnable);


/*
打开ADC设备
参数  ：
		pDevInf    设备句柄
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130OpenADC(PVOID pDevInf);

/*
初始化ADC设备
参数  ：
		pDevInf    设备句柄
		ucCycClk   ADC时钟采样模式，0：手动采样，其它：自动采样周期的时钟数
		bAutoWid   自动采样脉宽设置位，0：1时钟周期，1：2时钟周期
		ucClkDiv   时钟分频系数
		ucAdcChan  采样通道
		ucAutoCnt  自动采样计数
		usRefValue 未实现
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130InitADC(PVOID pDevInf,UCHAR ucCycClk,BOOL bAutoWid,UCHAR ucClkDiv,UCHAR ucAdcChan,UCHAR ucAutoCnt,USHORT usRefValue);

/*
关闭ADC设备
参数  ：
		pDevInf    设备句柄
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130CloseADC(PVOID pDevInf);




/*
使能ADC自动采样
参数  ：
		pDevInf    设备句柄
		bEnable    TRUE:开启ADC自动采样，FALSE:关闭ADC自动采样
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130SetADCAutoData(PVOID pDevInf,BOOL bEnable);

/*
主动采样一次ADC数据
参数  ：
		pDevInf    设备句柄
		pData      函数返回ADC值，注意：16位为1个采样数据
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadADCData(PVOID pDevInf,PUSHORT pData);

/*
改变ADC采样通道
参数  ：
		pDevInf    设备句柄
		Data       通道值，0：通道0，1：通道1，2：通道2
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ChangeADCChan(PVOID pDevInf,UCHAR Data);

/*
自动采样的ADC数据
参数  ：
		pDevInf    设备句柄
		pData      缓冲区地址，注意：16位为1个采样数据
		pLen       缓冲区长度
		TimeOut    超时时间，单位：毫秒。
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadADCDataStream(PVOID pDevInf,PUSHORT pData,PULONG pLen,ULONG TimeOut);

/*
打开PARA设备
参数  ：
		pDevInf    设备句柄
返回值：
		打开成功返回TRUE，打开失败返回FALSE
*/
BOOL  WINAPI  CH9130OpenPARA(PVOID pDevInf);

/*
初始化PARA设备
参数  ：
		pDevInf    设备句柄
		bSlvMode   模式选择,0：外部总线使能，1：被动并口使能
		bTwoClk    外部总线读写周期，0：1个时钟周期，1：2个时钟周期
		bWordWidth 外部总线数据位控制域，0：8位数据总线，1：16位或32位数据总线
		bSlvEn     被动并口流控：0：禁止，1：使能
		ucRwCyc    外部总线的读写总周期
		ucHldCyc   外部总线的读写信号结束点时钟数
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130InitPARA(PVOID pDevInf,BOOL bSlvMode,BOOL bTwoClk,BOOL bWordWidth,BOOL bSlvEn,UCHAR ucRwCyc,UCHAR ucHldCyc);

/*
关闭PARA设备
参数  ：
		pDevInf    设备句柄
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ClosePARA(PVOID pDevInf);



/*
读被动PARA设备数据
参数  ：
		pDevInf    设备句柄
		pData      缓冲区地址，注意：16位为1个采样数据
		pLen       函数调用前是缓冲区长度，长度不要超过512字节。函数返回后是实际读到的数据长度
		TimeOut    超时时间，单位：毫秒。
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadSlavePARAData(PVOID pDevInf,PVOID pData,PULONG pLen,ULONG TimeOut);

/*
写被动PARA设备数据
参数  ：
		pDevInf    设备句柄
		pData      缓冲区地址
		pLen       缓冲区长度
		TimeOut    超时时间，单位：毫秒。
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130WriteSlavePARAData(PVOID pDevInf,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
按字节方式，读主动PARA设备数据
参数  ：
		pDevInf    设备句柄
		OffsetAddr 外部总线地址
		bAddInc    外部总线地址是否递增
		pData      缓冲区地址，注意：长度不要超过512字节
		uLen       缓冲区长度
		TimeOut    超时时间，单位：毫秒。
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadMasterPARAByte(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
按字方式，读主动PARA设备数据
参数  ：
		pDevInf    设备句柄
		OffsetAddr 外部总线地址
		bAddInc    外部总线地址是否递增
		pData      缓冲区地址，注意：长度不要超过512字节
		uLen       缓冲区长度
		TimeOut    超时时间，单位：毫秒。
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadMasterPARAWord(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
按双字方式，读主动PARA设备数据
参数  ：
		pDevInf    设备句柄
		OffsetAddr 外部总线地址
		bAddInc    外部总线地址是否递增
		pData      缓冲区地址，注意：长度不要超过512字节
		uLen       缓冲区长度
		TimeOut    超时时间，单位：毫秒。
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130ReadMasterPARADword(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
按字节方式，写主动PARA设备数据
参数  ：
		pDevInf    设备句柄
		OffsetAddr 外部总线地址
		bAddInc    外部总线地址是否递增
		pData      缓冲区地址，注意：长度不要超过512字节
		uLen       缓冲区长度
		TimeOut    超时时间，单位：毫秒。
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130WriteMasterPARAByte(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
按字方式，写主动PARA设备数据
参数  ：
		pDevInf    设备句柄
		OffsetAddr 外部总线地址
		bAddInc    外部总线地址是否递增
		pData      缓冲区地址，注意：长度不要超过512字节
		uLen       缓冲区长度
		TimeOut    超时时间，单位：毫秒。
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130WriteMasterPARAWord(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);

/*
按双字方式，写主动PARA设备数据
参数  ：
		pDevInf    设备句柄
		OffsetAddr 外部总线地址
		bAddInc    外部总线地址是否递增
		pData      缓冲区地址，注意：长度不要超过512字节
		uLen       缓冲区长度
		TimeOut    超时时间，单位：毫秒。
返回值：
		成功返回TRUE，失败返回FALSE
*/
BOOL  WINAPI  CH9130WriteMasterPARADword(PVOID pDevInf,UCHAR OffsetAddr,BOOL bAddInc,PVOID pData,ULONG uLen,ULONG TimeOut);


#ifdef __cplusplus
}
#endif

#endif		// _CH9130_DLL_H
