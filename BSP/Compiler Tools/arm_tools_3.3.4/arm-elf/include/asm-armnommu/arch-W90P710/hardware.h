/********************************************************/
/*							*/
/* Winbond W90P710					*/
/* PC34 Lsshi				*/
/*							*/
/********************************************************/
#ifndef __ASM_ARCH_HARDWARE_H
#define __ASM_ARCH_HARDWARE_H

/*
 * define W90P710 CPU master clock
 */
#define MHz		1000000
#define fMCLK_MHz	(15 * MHz)
#define fMCLK		(fMCLK_MHz / MHz)
#define MCLK2		(fMCLK_MHz / 2)

#define pcibios_assign_all_busses()        1

/*
 * ASIC Address Definition
 */

#define Base_Addr		0xFFF00000
#define AHB_IO_BASE		Base_Addr
#define APB_IO_BASE		0xFFF80000

#define VPint	*(volatile unsigned int *)
#define VPshort	*(volatile unsigned short *)
#define VPchar	*(volatile unsigned char *)

#ifndef CSR_WRITE
#   define CSR_WRITE(addr,data)	(VPint(addr) = (data))
#endif

#ifndef CSR_READ
#   define CSR_READ(addr)	(VPint(addr))
#endif

#ifndef CAM_Reg
#   define CAM_Reg(x)		(VPint(CAMBASE+(x*0x4)))
#endif

/* ************************ */
/* System Manager Registers */
/* ************************ */
#define PDID		(Base_Addr+0x00000)
#define ARBCON		(Base_Addr+0x00004)
#define PLLCON		(Base_Addr+0x00008)
#define CLKSEL		(Base_Addr+0x0000c)

/*****************************/
/* Cache Control Register Map*/
/*****************************/
#define CAHCNF		(Base_Addr+0x02000)
#define CAHCON		(Base_Addr+0x02004)
#define CAHADR		(Base_Addr+0x02008)

#define NON_CANCHABLE 0x80000000
//#define NONCACHE
/*****************************/
/* EBI Control Registers Map */
/*****************************/
#define EBICON		(Base_Addr+0x01000)
#define ROMCON0		(Base_Addr+0x01004)
#define DRAMCON0	(Base_Addr+0x01008)
#define DRAMCON1	(Base_Addr+0x0100c)
#define SDTIME0		(Base_Addr+0x01010)
#define SDTIME1		(Base_Addr+0x01014)

/********************************/
/* GPIO Controller Registers Map*/
/********************************/
#define GPIO_CFG		(Base_Addr+0x83000) /*	GPIO Configuration Register */
#define GPIO_DIR		(Base_Addr+0x83004) /*	GPIO Direction Register */
#define GPIO_DATAOUT	(Base_Addr+0x83008) /*	GPIO Data Output Register */
#define GPIO_DATAIN		(Base_Addr+0x8300c) /*	GPIO Data Input Register */
#define GPIO_DEBNCE		(Base_Addr+0x83010) /*	GPIO De-bounce Control Register */
#define GPIO_INV		(Base_Addr+0x83014) /*	GPIO Data Input Inverse Register */


/* *********************** */
/* Ethernet BDMA Registers */
/* *********************** */
#define BDMATXCON	(Base_Addr+0x9000)
#define BDMARXCON	(Base_Addr+0x9004)
#define BDMATXPTR	(Base_Addr+0x9008)
#define BDMARXPTR	(Base_Addr+0x900C)
#define BDMARXLSZ	(Base_Addr+0x9010)
#define BDMASTAT	(Base_Addr+0x9014)
#define CAMBASE		(Base_Addr+0x9100)
/*
 * CAM		0x9100 ~ 0x917C
 * BDMATXBUF	0x9200 ~ 0x92FC
 * BDMARXBUF	0x9800 ~ 0x99FC
 */

/* ********************** */
/* Ethernet MAC Registers */
/* ********************** */

#define  MAC_BASE  	(Base_Addr+0x3000)

#if 0
#define MACON		(Base_Addr+0xA000)
#define CAMCON		(Base_Addr+0xA004)
#define MACTXCON	(Base_Addr+0xA008)
#define MACTXSTAT	(Base_Addr+0xA00C)
#define MACRXCON	(Base_Addr+0xA010)
#define MACRXSTAT	(Base_Addr+0xA014)
#define STADATA		(Base_Addr+0xA018)
#define STACON		(Base_Addr+0xA01C)
#define CAMEN		(Base_Addr+0xA028)
#define EMISSCNT	(Base_Addr+0xA03C)
#define EPZCNT		(Base_Addr+0xA040)
#define ERMPZCNT	(Base_Addr+0xA044)
#define EXTSTAT		(Base_Addr+0x9040)
#endif
/* ************************ */
/* HDLC Channel A Registers */
/* ************************ */

/* ************************ */
/* HDLC Channel B Registers */
/* ************************ */

/* ******************* */
/* I/O Ports Registers */
/* ******************* */
#define IOPMOD		(Base_Addr+0x5000)
#define IOPCON		(Base_Addr+0x5004)
#define IOPDATA		(Base_Addr+0x5008)


/* ****************************** */
/* AIC Registers Map			  */
/* ****************************** */
#define AIC_SCR1	(Base_Addr+0x82004)
#define AIC_SCR2	(Base_Addr+0x82008)
#define AIC_SCR3	(Base_Addr+0x8200c)
#define AIC_SCR4	(Base_Addr+0x82010)
#define AIC_SCR5	(Base_Addr+0x82014)
#define AIC_SCR6	(Base_Addr+0x82018)
#define AIC_SCR7	(Base_Addr+0x8201c)
#define AIC_SCR8	(Base_Addr+0x82010)
#define AIC_SCR9	(Base_Addr+0x82024)
#define AIC_SCR10	(Base_Addr+0x82028)
#define AIC_SCR11	(Base_Addr+0x8202c)
#define AIC_SCR12	(Base_Addr+0x82030)
#define AIC_SCR13	(Base_Addr+0x82034)
#define AIC_SCR14	(Base_Addr+0x82038)
#define AIC_SCR15	(Base_Addr+0x8203c)
#define AIC_SCR16	(Base_Addr+0x82040)

#define AIC_SCR17	(Base_Addr+0x82044)
#define AIC_SCR18	(Base_Addr+0x82048)

#define AIC_SCR19	(Base_Addr+0x8204c)
#define AIC_SCR20	(Base_Addr+0x82050)
#define AIC_SCR21	(Base_Addr+0x82054)
#define AIC_SCR22	(Base_Addr+0x82058)
#define AIC_SCR23	(Base_Addr+0x8205c)
#define AIC_SCR24	(Base_Addr+0x82060)
#define AIC_SCR25	(Base_Addr+0x82064)
#define AIC_SCR26	(Base_Addr+0x82068)
#define AIC_SCR27	(Base_Addr+0x8206c)
#define AIC_SCR28	(Base_Addr+0x82070)
#define AIC_SCR29	(Base_Addr+0x82074)
#define AIC_SCR30	(Base_Addr+0x82078)

#define AIC_IRSR	(Base_Addr+0x82100)
#define AIC_IASR	(Base_Addr+0x82104)
#define AIC_ISR		(Base_Addr+0x82108)
#define AIC_IPER	(Base_Addr+0x8210c)
#define AIC_ISNR	(Base_Addr+0x82110)
#define AIC_IMR		(Base_Addr+0x82114)
#define AIC_OISR	(Base_Addr+0x82118)
#define AIC_MECR	(Base_Addr+0x82120)
#define AIC_MDCR	(Base_Addr+0x82124)
#define AIC_SSCR	(Base_Addr+0x82128)
#define AIC_SCCR	(Base_Addr+0x8212c)
#define AIC_EOSCR	(Base_Addr+0x82130)
#define AIC_TEST	(Base_Addr+0x82200)


#define IntScr(index,value)		(VPint(Base_Addr+0x82000+4*index)=value)
#define IntPend		(VPint(AIC_EOSCR))
#define IntMask		(VPint(AIC_MDCR))
#define IntUnMask	(VPint(AIC_MECR))

#define INT_ENABLE(n)		IntUnMask = (1<<(n))
#define INT_DISABLE(n)		IntMask = (1<<(n))
//#define CLEAR_PEND_INT(n)	IntPend = (0)
//#define SET_PEND_INT(n)		IntPndTst |= (1<<(n))

/* ***************** */
/* I2C Bus Registers */
/* ***************** */

/* ************** */
/* GDMA Registers */
/* ************** */

/* ************** */
/* UART Registers */
/* ************** */

#define DEBUG_CONSOLE	(0)

#define COM_TX			(Base_Addr+0x80000)
#define COM_RX			(Base_Addr+0x80000)
#define COM_DLL 		(Base_Addr+0x80000)
#define COM_DLM 		(Base_Addr+0x80004)
#define COM_IER 		(Base_Addr+0x80004)
#define COM_IIR 		(Base_Addr+0x80008)
#define COM_FCR 		(Base_Addr+0x80008)
#define COM_LCR 		(Base_Addr+0x8000c)
#define COM_MCR 		(Base_Addr+0x80010)
#define COM_LSR 		(Base_Addr+0x80014)
#define COM_MSR 		(Base_Addr+0x80018)
#define COM_TOR 		(Base_Addr+0x8001c)

#define UART_BASE0		COM_TX

#define UART_BASE1		(Base_Addr+0x80100)
#define UART_BASE2		(Base_Addr+0x80200)
#define UART_BASE3		(Base_Addr+0x80300)

#if DEBUG_CONSOLE == 0
	#define DEBUG_TX_BUFF_BASE	COM_TX
	#define DEBUG_RX_BUFF_BASE	COM_RX
	#define DEBUG_UARTLCON_BASE	COM_LCR
	#define DEBUG_UARTCONT_BASE	COM_LCR                  
	#define DEBUG_UARTBRD_BASE	COM_DLL
	#define DEBUG_CHK_STAT_BASE	COM_IIR
#endif

#define DEBUG_ULCR_REG_VAL	(0x3)
#define DEBUG_ULCR_REG_VAL	(0x3)
#define DEBUG_UDLL_REG_VAL	(0x6)
#define DEBUG_RX_CHECK_BIT	(0X20)
#define DEBUG_TX_CAN_CHECK_BIT	(0X40)
#define DEBUG_TX_DONE_CHECK_BIT	(0X80)


/* **************** */
/* Timers Registers */
/* **************** */
#define TCR0		(Base_Addr+0x81000)
#define TCR1		(Base_Addr+0x81004)
#define TICR0		(Base_Addr+0x81008)
#define TICR1		(Base_Addr+0x8100c)
#define TDR0		(Base_Addr+0x81010)
#define TDR1		(Base_Addr+0x81014)
#define TISR		(Base_Addr+0x81018)
#define WTCR		(Base_Addr+0x8101c)

/*******************/
/* SYSCFG Register */
/*******************/

#define SYS_INIT_BASE	EXTDBWTH
#define rSYSCFG		(0x87FFFF90)	/* disable Cache/Write buffer */

/**********************************/
/* System Memory Control Register */
/**********************************/
#define DSR0		(2<<0)	/* ROM Bank0 */
#define DSR1		(0<<2)	/* 0: Disable, 1: Byte, 2: Half-Word, 3: Word */
#define DSR2		(0<<4)
#define DSR3		(0<<6)
#define DSR4		(0<<8)
#define DSR5		(0<<10)
#define DSD0		(2<<12) /* RAM Bank0 */
#define DSD1		(0<<14)
#define DSD2		(0<<16)
#define DSD3		(0<<18)
#define DSX0		(0<<20)	/* EXTIO0 */
#define DSX1		(0<<22)
#define DSX2		(0<<24)
#define DSX3		(0<<26)

#define rEXTDBWTH	(DSR0|DSR1|DSR2|DSR3|DSR4|DSR5 | DSD0|DSD1|DSD2|DSD3 | DSX0|DSX1|DSX2|DSX3)

/****************************************/
/* ROMCON0: ROM Bank 0 Control Register */
/****************************************/
#define PMC0		(0x0<<0)	/*00: Normal ROM   01: 4 word page*/
					/*10: 8 word page  11:16 word page*/
#define tPA0		(0x0<<2)	/*00: 5 cycles     01: 2 cycles*/
					/*10: 3 cycles     11: 4 cycles*/
#define tACC0		(0x6<<4)	/*000: Disable bank 001: 2 cycles*/
					/*010: 3 cycles     011: 4 cycles*/
					/*110: 7 cycles     111: Reserved*/
#define ROM_BASE0_R	((0x00000000>>16)<<10)
#define ROM_NEXT0_R	((0x00200000>>16)<<20)
#define ROM_BASE0_B	((0x01000000>>16)<<10)
#define ROM_NEXT0_B	((0x01200000>>16)<<20)
#define rROMCON0_R	(ROM_NEXT0_R|ROM_BASE0_R|tACC0|tPA0|PMC0)
#define rROMCON0_B	(ROM_NEXT0_B|ROM_BASE0_B|tACC0|tPA0|PMC0)

#define rROMCON1	0x0
#define rROMCON2	0x0
#define rROMCON3	0x0
#define rROMCON4	0x0
#define rROMCON5	0x0


/********************************************/
/* SDRAMCON0: SDRAM Bank 0 Control Register */
/********************************************/
#define StRC0		(0x1<<7)
#define StRP0		(0x3<<8)
#define SDRAM_BASE0_R	((0x01000000>>16)<<10)
#define SDRAM_NEXT0_R	((0x01800000>>16)<<20)
#define SDRAM_BASE0_B	((0x00000000>>16)<<10)
#define SDRAM_NEXT0_B	((0x00800000>>16)<<20)
#define SCAN0		(0x0<<30)
#define rSDRAMCON0_R	(SCAN0|SDRAM_NEXT0_R|SDRAM_BASE0_R|StRP0|StRC0)
#define rSDRAMCON0_B	(SCAN0|SDRAM_NEXT0_B|SDRAM_BASE0_B|StRP0|StRC0)

#define rSDRAMCON1	0x0
#define rSDRAMCON2	0x0
#define rSDRAMCON3	0x0

/************************************************/
/* DRAM Refresh & External I/O Control Register */
/************************************************/
#define ExtIOBase	(0x360<<0)
#define VSF		(0x1<<15)
#define REN		(0x1<<16)
#define tCHR		(0x0<<17)
#define tCSR		(0x0<<20)
#define RefCountValue	((2048+1-(16*fMCLK))<<21)
#define rREFEXTCON	(RefCountValue|tCSR|tCHR|REN|VSF|ExtIOBase)

/********/
/* Misc */
/********/

#define TMOD_TIMER0_VAL	0x3	/* Timer0  TOGGLE, and Run */
#define TAG_BASE	0x11000000

#define HARD_RESET_NOW()

/*PCI*/
#define PCIBIOS_MIN_IO		0x6000
#define PCIBIOS_MIN_MEM 	0x01000000

//*************************************************************************

//lsshi add 2004-1-2 12:28
#ifndef DWORD_WRITE // 32-bit
#   define DWORD_WRITE(addr,data)	(*((unsigned int volatile *)(addr))=data)
#endif

#ifndef DWORD_READ
#   define DWORD_READ(addr)	(*((unsigned int volatile *)(addr)))
#endif

#ifndef WORD_WRITE //16-bit
#   define WORD_WRITE(addr,data)	(*((unsigned short volatile *)(addr))=data)
#endif

#ifndef WORD_READ
#   define WORD_READ(addr)		(*((unsigned short volatile *)(addr)))
#endif

#ifndef BYTE_WRITE //8-bit
#   define BYTE_WRITE(addr,data)	(*((unsigned char volatile *)(addr))=data)
#endif

#ifndef BYTE_READ
#   define BYTE_READ(addr)		(*((unsigned char volatile *)(addr)))
#endif



/* EBI 0-3 control Registers Map */
/*****************************/
#define EXT0CON	(Base_Addr+0x01018)
#define EXT1CON	(Base_Addr+0x0101c)
#define EXT2CON	(Base_Addr+0x01020)
#define EXT3CON	(Base_Addr+0x01024)

//EBI Config bits
#define SIZE_256k		(0<<16)
#define SIZE_512k		(1<<16)
#define SIZE_1M		(2<<16)
#define SIZE_16M		(6<<16)
#define SIZE_32M		(7<<16)

#define ADRS			(1<<15)
#define tACC			(15<<11)
#define tCOH			(7<<8)
#define tACS			(7<<5)
#define tCOS			(7<<2)

#define DBWD0		(2)//16-bit bus width for DoC
#define DBWD1		(1)//8-bit bus width
#define DBWD2		(1)
#define DBWD3		(1)

#define EXT0_BASS	0x70000000
#define EXT1_BASS	0x73000000
#define EXT2_BASS	0x74000000
#define EXT3_BASS	0x78000000


#define EXT0CON_DATA	((EXT0_BASS<<1)|SIZE_32M|ADRS|tACC|tCOH|tACS|tCOS|DBWD0)
#define EXT1CON_DATA	((EXT1_BASS<<1)|SIZE_256k|ADRS|tACC|tCOH|tACS|tCOS|DBWD1)
#define EXT2CON_DATA	((EXT2_BASS<<1)|SIZE_256k|ADRS|tACC|tCOH|tACS|tCOS|DBWD2)
#define EXT3CON_DATA	((EXT3_BASS<<1)|SIZE_32M|ADRS|tACC|tCOH|tACS|tCOS|DBWD3)


//EBI Device Base address
//define for DOC
#define DOC_BASE_ADDR		EXT0_BASS
//define for LCM
#define LCM_BASE_ADDR		(EXT3_BASS|0x1000000)
#define PLD_BASE_ADDR		(EXT3_BASS|0x80000000)
//define for W83977
#define W83977AF_BASE_ADDR	EXT1_BASS
#define W83977EF_BASE_ADDR	EXT2_BASS

//USB Host/Device Base addr
#define USB_HOST		(AHB_IO_BASE+0x5000) // USB Host
#define	USB_DEVICE    	(AHB_IO_BASE+0x6000) /* USB Device */

/****************************************************************************************************
 *
 * Real Time Clock (RTC) PC34 Lsshi 2005-4-18 12:52
 *
 ****************************************************************************************************/
#define _INIR			(VPint(APB_IO_BASE+0x4000)) /*	RTC Initiation Register */
#define _AER			(VPint(APB_IO_BASE+0x4004)) /*	RTC Access Enable Register */
#define _FCR			(VPint(APB_IO_BASE+0x4008)) /*	RTC Frequency Compensation Register */

#define _TLR			(VPint(APB_IO_BASE+0x400c)) /*	Time Loading Register */
#define _CLR			(VPint(APB_IO_BASE+0x4010)) /*	Calendar Loading Register */
#define _DWR			(VPint(APB_IO_BASE+0x4018)) /*	Day of the Week Register */

#define _TSSR			(VPint(APB_IO_BASE+0x4014)) /*	Time Scale Selection Register */

#define _TAR			(VPint(APB_IO_BASE+0x401c)) /*	Time Alarm Register */
#define _CAR			(VPint(APB_IO_BASE+0x4020)) /*	Calendar Alarm Register */
#define _LIR			(VPint(APB_IO_BASE+0x4024)) /*	Leap year Indicator Register */

#define _RIER			(VPint(APB_IO_BASE+0x4028)) /*	RTC Interrupt Enable Register */
#define _RIIR			(VPint(APB_IO_BASE+0x402c)) /*	RTC Interrupt Indicator Register */
#define _TTR			(VPint(APB_IO_BASE+0x4030)) /*	RTC Time Tick Register */

//normal address

#define INIR			(APB_IO_BASE+0x4000) /*	RTC Initiation Register */
#define AER				(APB_IO_BASE+0x4004) /*	RTC Access Enable Register */
#define FCR				(APB_IO_BASE+0x4008) /*	RTC Frequency Compensation Register */

#define TLR				(APB_IO_BASE+0x400c) /*	Time Loading Register */
#define CLR				(APB_IO_BASE+0x4010) /*	Calendar Loading Register */
#define DWR				(APB_IO_BASE+0x4018) /*	Day of the Week Register */

#define TSSR			(APB_IO_BASE+0x4014) /*	Time Scale Selection Register */

#define TAR				(APB_IO_BASE+0x401c) /*	Time Alarm Register */
#define CAR				(APB_IO_BASE+0x4020) /*	Calendar Alarm Register */
#define LIR				(APB_IO_BASE+0x4024) /*	Leap year Indicator Register */

#define RIER			(APB_IO_BASE+0x4028) /*	RTC Interrupt Enable Register */
#define RIIR			(APB_IO_BASE+0x402c) /*	RTC Interrupt Indicator Register */
#define TTR				(APB_IO_BASE+0x4030) /*	RTC Time Tick Register */

#ifndef CSR_READ_OFFSET
	#define CSR_READ_OFFSET(addr,offset)	*((volatile unsigned char *)((addr)+offset))
#endif


 // Routines to Enable/Disable Interrupts
#define Enable_Int(n)     (VPint(AIC_MECR)) = (1<<(n))
#define Disable_Int(n)    (VPint(AIC_MDCR)) = (1<<(n))
#define Enable_Int_All()  (VPint(AIC_MECR)) = 0xffff
#define Disable_Int_All() (VPint(AIC_MDCR)) = 0xffff

//***************************************************************************

#endif /* __ASM_ARCH_HARDWARE_H */
