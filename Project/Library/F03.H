#ifndef   __F03_H__
#define   __F03_H__
//
/*  BYTE Registers  */
//Core Register
sfr      ACC      = 0xE0;
sfr      B        = 0xF0;
sfr      SP       = 0x81;
sfr      DPL      = 0x82;
sfr      DPH      = 0x83;
sfr      PSW      = 0xD0;
//Peripheral Register
sfr      PCON     = 0x87;
sfr      RST_FLAG = 0xB7;
sfr      INTn_IE  = 0xE8;
sfr      INTn_IF  = 0x88;
sfr      INTn_IP  = 0xF8;
sfr      WDT_C    = 0x84;
sfr      WDT_OP   = 0x85;
sfr      HRC_TRML = 0x89;
sfr      HRC_TRMH = 0x8A;
sfr      UART_TXM = 0x86;

sfr      PORT_C0  = 0x86;

sfr      P0_OE    = 0x8B;
sfr      P1_OE    = 0x8C;
sfr      P2_OE    = 0x8D;
sfr      P3_OE    = 0x8E;

sfr      P0_DAT   = 0x80;
sfr      P1_DAT   = 0x90;
sfr      P2_DAT   = 0xA0;
sfr      P3_DAT   = 0xB0;

sfr      LED_C0   = 0x8F;
sfr      LED_C1   = 0x91;
sfr      COM_D    = 0x92;
sfr      COM_EN   = 0x93;
sfr      SEGDL    = 0x94;
sfr      SEGDH    = 0x95;

sfr      TMRn_IF   = 0xA8;
sfr      TMRn_IE   = 0x9D;

sfr      PWMn_IF   = 0xC8;
sfr      PWMn_IE   = 0x9E;

sfr      CAPn_IF   = 0xC8;
sfr      CAPn_IE   = 0x9E;

sfr      ANA_IF   = 0xC0;
sfr      ANA_IE   = 0xA1;
sfr      AN_IF    = 0xC0;
sfr      AN_IE    = 0xA1;


sfr      TMR0_C0  = 0xA2;
sfr      TMR0_C1  = 0xA3;
sfr      TMR0L    = 0xA4;
sfr      TMR0H    = 0xA5;
sfr      TMR0_CYL    = 0xA6;
sfr      TMR0_CYH    = 0xA7;

sfr      TMR1_C0  = 0xA9;
sfr      TMR1_C1  = 0xA3;
sfr      TMR1L    = 0xAA;
sfr      TMR1H    = 0xAB;
sfr      TMR1_CYL    = 0xAC;
sfr      TMR1_CYH    = 0xAD;

sfr      TMR2_C0  = 0xAE;
sfr      TMR2_C1  = 0xA3;
sfr      TMR2L    = 0xB1;
sfr      TMR2H    = 0xB2;
sfr      TMR2_CYL    = 0xB3;
sfr      TMR2_CYH    = 0xB4;

sfr      TMR3_C0  = 0xAF;
sfr      TMR3_C1  = 0xA3;
sfr      TMR3L    = 0xB5;
sfr      TMR3H    = 0xB6;
sfr      TMR3_CYL    = 0xB9;
sfr      TMR3_CYH    = 0xBA;

sfr      PWM0_C     = 0xBB;
sfr      PWM0_OC    = 0xBC;
sfr      PWM0_R0L   = 0xBD;
sfr      PWM0_R0H   = 0xBE;
sfr      PWM0_R1L   = 0xC1;
sfr      PWM0_R1H   = 0xC2;
sfr      PWM0_DT    = 0xBF;

sfr      CAP0_C     = 0xBB;
sfr      CAP0_DL    = 0xBD;
sfr      CAP0_DH    = 0xBE;

sfr      PWM1_C     = 0xC3;
sfr      PWM1_OC    = 0xC4;
sfr      PWM1_R0L   = 0xC5;
sfr      PWM1_R0H   = 0xC6;
sfr      PWM1_R1L   = 0xC9;
sfr      PWM1_R1H   = 0xCA;
sfr      PWM1_DT    = 0xC7;

sfr      CAP1_C     = 0xC3;
sfr      CAP1_DL    = 0xC4;
sfr      CAP1_DH    = 0xC6;

sfr      PWM2_C     = 0xCB;
sfr      PWM2_OC    = 0xCC;
sfr      PWM2_R0L   = 0xCD;
sfr      PWM2_R0H   = 0xCE;
sfr      PWM2_R1L   = 0xD1;
sfr      PWM2_R1H   = 0xD2;
sfr      PWM2_DT    = 0xCF;

sfr      CAP2_C     = 0xCB;
sfr      CAP2_DL    = 0xCD;
sfr      CAP2_DH    = 0xCE;

sfr      UART0_BRL = 0xD3;
sfr      UART0_BRH = 0xD4;
sfr      UART0_RXC  = 0xD5;
sfr      UART0_RXB  = 0xD6;
sfr      UART0_TXC  = 0xD7;
sfr      UART0_TXB  = 0xD9;

sfr      UART_IF    = 0xB8;
sfr      UART_IE    = 0x9F;
sfr      IICn_IF    = 0xB8;
sfr      IICn_IE    = 0x9F;

sfr      SPIn_IF    = 0xB8;
sfr      SPIn_IE    = 0x9F;

sfr      IIC_C0     = 0xDA;
sfr      IIC_C1     = 0xDB;
sfr      IIC_STA    = 0xDC;
sfr      IIC_ADDR   = 0xDD;
sfr      IIC_BRR    = 0xDD;
sfr      IIC_DATA   = 0xDE;
sfr      IIC_TOC    = 0xDF;

sfr      ADC_C0     = 0xE1;
sfr      ADC_C1     = 0xE2;
sfr      ADC_C2     = 0xE3;
sfr      ADC_DL     = 0xE4;
sfr      ADC_DH     = 0xE5;
sfr      ADC_CMP_C0    = 0xE6;
sfr      ADC_TG_R0L    = 0x99;
sfr      ADC_TG_R0H    = 0x9A;

sfr      ACP_C0    = 0xE7;
sfr      ACP_C1    = 0xE9;
sfr      ACP_C2    = 0xEB;
sfr      TK_C0     = 0xEA;
sfr      TK_C1     = 0xE9;
sfr      TK_C2     = 0xEB;
sfr      TK_CHEL    = 0xEC;
sfr      TK_CHEM    = 0xED;
sfr      TK_CHEH    = 0xEE;
sfr      TK_CNTL   = 0xF1;
sfr      TK_CNTH   = 0xF2;

sfr      VREF_C    = 0xEF;

sfr      LVD_C    = 0xF3;

sfr      AMP_C0    = 0xF4;
sfr      AMP_C1    = 0xF5;

sfr      SPI_C0   = 0xF6;
sfr      SPI_C1   = 0xF7;
sfr      SPI_DATA   = 0xF9;


sfr      UART1_BRL = 0xFA;
sfr      UART1_BRH = 0xFB;
sfr      UART1_RXC  = 0xFC;
sfr      UART1_RXB  = 0xFD;
sfr      UART1_TXC  = 0xFE;
sfr      UART1_TXB  = 0xFF;




////System Register
#define IAP_PR    *((unsigned char xdata *)(0x9000))
#define IAP_AS    *((unsigned char xdata *)(0x9001))
#define IAP_AL    *((unsigned char xdata *)(0x9002))
#define IAP_AH    *((unsigned char xdata *)(0x9003))
#define IAP_D     *((unsigned char xdata *)(0x9004))
#define IAP_C0    *((unsigned char xdata *)(0x9005))
#define IAP_C1    *((unsigned char xdata *)(0x9006))
#define CLK_PR    *((unsigned char xdata *)(0x9020))
#define CLK_C0    *((unsigned char xdata *)(0x9021))
#define CLK_C1    *((unsigned char xdata *)(0x9022))
#define PCK_GTC0  *((unsigned char xdata *)(0x9023))
#define PCK_GTC1  *((unsigned char xdata *)(0x9024))

#define CLK_LP    *((unsigned char xdata *)(0x9026))
#define WKUP_T    *((unsigned char xdata *)(0x9027))


#define CAL_PR      *((unsigned char xdata *)(0x9080))
#define IBCAL       *((unsigned char xdata *)(0x9081))
#define VBGCAL      *((unsigned char xdata *)(0x9082))
#define VRCAL       *((unsigned char xdata *)(0x9083))

#define VREFCAL     *((unsigned char xdata *)(0x9088))
#define OPA_COS     *((unsigned char xdata *)(0x908a))
#define ACP_COS     *((unsigned char xdata *)(0x908b))
#define INTOSC_CS   *((unsigned char xdata *)(0x908c))
#define WDTCAL      *((unsigned char xdata *)(0x908d))
#define TK_CH0_EN   *((unsigned char xdata *)(0x908e))

#define TEST_PR     *((unsigned char xdata *)(0x9090))
#define TEST_MODE1  *((unsigned char xdata *)(0x9092))
#define CLK_CAL     *((unsigned char xdata *)(0x9094))
#define WDT_CAL_CYCL *((unsigned char xdata *)(0x9095))
#define WDT_CAL_CYCH *((unsigned char xdata *)(0x9096))
#define LRC_CAL     *((unsigned char xdata *)(0x9097))

#define SYS_RST_FLAG *((unsigned char xdata *)(0x90F0))
#define SOFT_BOR     *((unsigned char xdata *)(0x90F1))
#define BOR_OPT      *((unsigned char xdata *)(0x90F2))
#define SOFT_RST     *((unsigned char xdata *)(0x90FF))

#define P0_IE        *((unsigned char xdata *)(0x9100))
#define P1_IE        *((unsigned char xdata *)(0x9101))
#define P2_IE        *((unsigned char xdata *)(0x9102))
#define P3_IE        *((unsigned char xdata *)(0x9103))

#define P0_PUE       *((unsigned char xdata *)(0x9108))
#define P1_PUE       *((unsigned char xdata *)(0x9109))
#define P2_PUE       *((unsigned char xdata *)(0x910A))
#define P3_PUE       *((unsigned char xdata *)(0x910B))

#define P0_PDE       *((unsigned char xdata *)(0x9110))
#define P1_PDE       *((unsigned char xdata *)(0x9111))
#define P2_PDE       *((unsigned char xdata *)(0x9112))
#define P3_PDE       *((unsigned char xdata *)(0x9113))

#define P0_ODE       *((unsigned char xdata *)(0x9118))
#define P1_ODE       *((unsigned char xdata *)(0x9119))
#define P2_ODE       *((unsigned char xdata *)(0x911A))
#define P3_ODE       *((unsigned char xdata *)(0x911B))

#define P0_SMITE     *((unsigned char xdata *)(0x9120))
#define P1_SMITE     *((unsigned char xdata *)(0x9121))
#define P2_SMITE     *((unsigned char xdata *)(0x9122))
#define P3_SMITE     *((unsigned char xdata *)(0x9123))

#define P0_FUN0     *((unsigned char xdata *)(0x9130))
#define P0_FUN1     *((unsigned char xdata *)(0x9131))
#define P0_FUN2     *((unsigned char xdata *)(0x9132))
#define P0_FUN3     *((unsigned char xdata *)(0x9133))

#define P1_FUN0     *((unsigned char xdata *)(0x9134))
#define P1_FUN1     *((unsigned char xdata *)(0x9135))
#define P1_FUN2     *((unsigned char xdata *)(0x9136))
#define P1_FUN3     *((unsigned char xdata *)(0x9137))

#define P2_FUN0     *((unsigned char xdata *)(0x9138))
#define P2_FUN1     *((unsigned char xdata *)(0x9139))
#define P2_FUN2     *((unsigned char xdata *)(0x913A))
#define P2_FUN3     *((unsigned char xdata *)(0x913B))

#define P3_FUN0     *((unsigned char xdata *)(0x913C))
#define P3_FUN1     *((unsigned char xdata *)(0x913D))
#define P3_FUN2     *((unsigned char xdata *)(0x913E))
#define P3_FUN3     *((unsigned char xdata *)(0x913F))

#define P0_IOL_CL    *((unsigned char xdata *)(0x9150))
#define P0_IOL_CH    *((unsigned char xdata *)(0x9151))
#define P1_IOL_CL    *((unsigned char xdata *)(0x9152))
#define P1_IOL_CH    *((unsigned char xdata *)(0x9153))
#define P2_IOL_CL    *((unsigned char xdata *)(0x9154))
#define P2_IOL_CH    *((unsigned char xdata *)(0x9155))
#define P3_IOL_CL    *((unsigned char xdata *)(0x9156))
#define P3_IOL_CH    *((unsigned char xdata *)(0x9157))

#define P0_IOH_CL    *((unsigned char xdata *)(0x9160))
#define P0_IOH_CH    *((unsigned char xdata *)(0x9161))
#define P1_IOH_CL    *((unsigned char xdata *)(0x9162))
#define P1_IOH_CH    *((unsigned char xdata *)(0x9163))
#define P2_IOH_CL    *((unsigned char xdata *)(0x9164))
#define P2_IOH_CH    *((unsigned char xdata *)(0x9165))
#define P3_IOH_CL    *((unsigned char xdata *)(0x9166))
#define P3_IOH_CH    *((unsigned char xdata *)(0x9167))

sfr      EINT0n_IF = 0x98;
sfr      EINT1n_IF = 0xD8;

#define EINT0_IE     *((unsigned char xdata *)(0x9180))
#define EINT1_IE     *((unsigned char xdata *)(0x9181))
#define EINT0_MD     *((unsigned char xdata *)(0x9182))
#define EINT1_MD     *((unsigned char xdata *)(0x9183))
#define EINT0_IOS    *((unsigned char xdata *)(0x9184))
#define EINT1_IOS    *((unsigned char xdata *)(0x9185))



////Bit Opteration Mapped
//IO
sbit  P0_0               =     P0_DAT^0;
sbit  P0_1               =     P0_DAT^1;
sbit  P0_2               =     P0_DAT^2;
sbit  P0_3               =     P0_DAT^3;
sbit  P0_4               =     P0_DAT^4;
sbit  P0_5               =     P0_DAT^5;

                         
sbit  P1_0               =     P1_DAT^0;
sbit  P1_1               =     P1_DAT^1;
sbit  P1_2               =     P1_DAT^2;
sbit  P1_3               =     P1_DAT^3;
sbit  P1_4               =     P1_DAT^4;
sbit  P1_5               =     P1_DAT^5;
sbit  P1_6               =     P1_DAT^6;
sbit  P1_7               =     P1_DAT^7;

sbit  P2_0               =     P2_DAT^0;
sbit  P2_1               =     P2_DAT^1;
sbit  P2_2               =     P2_DAT^2;
sbit  P2_3               =     P2_DAT^3;
sbit  P2_4               =     P2_DAT^4;
sbit  P2_5               =     P2_DAT^5;
sbit  P2_6               =     P2_DAT^6;
sbit  P2_7               =     P2_DAT^7;

sbit  P3_0               =     P3_DAT^0;
sbit  P3_1               =     P3_DAT^1;
sbit  P3_2               =     P3_DAT^2;
sbit  P3_3               =     P3_DAT^3;
sbit  P3_4               =     P3_DAT^4;
sbit  P3_5               =     P3_DAT^5;
sbit  P3_6               =     P3_DAT^6;
sbit  P3_7               =     P3_DAT^7;



//INT_IF
sbit  INT6_IF            =     INTn_IF^6;
sbit  INT5_IF            =     INTn_IF^5;
sbit  INT4_IF            =     INTn_IF^4;
sbit  INT3_IF            =     INTn_IF^3;
sbit  INT2_IF            =     INTn_IF^2;
sbit  INT1_IF            =     INTn_IF^1;
sbit  INT0_IF            =     INTn_IF^0;

//TMR_IF
sbit  TMR0_IF            =     TMRn_IF^0;
sbit  TMR1_IF            =     TMRn_IF^1;
sbit  TMR2_IF            =     TMRn_IF^2;
sbit  TMR3_IF            =     TMRn_IF^3;

//PWM_IF
sbit  PWM0_IF            =     PWMn_IF^0;
sbit  PWM1_IF            =     PWMn_IF^1;
sbit  PWM2_IF            =     PWMn_IF^2;
sbit  STP0_IF            =     PWMn_IF^4;
sbit  STP1_IF            =     PWMn_IF^5;
sbit  STP2_IF            =     PWMn_IF^6;

//CAP_IF
sbit  CAP0_IF            =     CAPn_IF^0;
sbit  CAP1_IF            =     CAPn_IF^1;
sbit  CAP2_IF            =     CAPn_IF^2;
//UART_IF
sbit  TX1_IF              =     UART_IF^3;
sbit  RX1_IF              =     UART_IF^2;
sbit  TX0_IF              =     UART_IF^1;
sbit  RX0_IF              =     UART_IF^0;
//IIC_IF
sbit  IIC_IF             =     IICn_IF^4;
//SPI_IF
sbit  SPI_IF             =     SPIn_IF^6;
//AN_IF
sbit  COM_IF             =     AN_IF^5;
sbit  LED_IF             =     AN_IF^4;
sbit  LVD_IF             =     AN_IF^2;
sbit  TK_IF              =     AN_IF^1;
sbit  ADC_IF             =     AN_IF^0;
//PSW
sbit  CY                 =     PSW^7;
sbit  AC                 =     PSW^6;
sbit  F0                 =     PSW^5;
sbit  RS1                =     PSW^4;
sbit  RS0                =     PSW^3;
sbit  OV                 =     PSW^2;
sbit  P                  =     PSW^0;
//ACC
//INT_IE
sbit  GIE                =     INTn_IE^7;
sbit  INT6_IE            =     INTn_IE^6;
sbit  INT5_IE            =     INTn_IE^5;
sbit  INT4_IE            =     INTn_IE^4;
sbit  INT3_IE            =     INTn_IE^3;
sbit  INT2_IE            =     INTn_IE^2;
sbit  INT1_IE            =     INTn_IE^1;
sbit  INT0_IE            =     INTn_IE^0;
//B
//INT_IP
sbit  INT6_IP            =     INTn_IP^6;
sbit  INT5_IP            =     INTn_IP^5;
sbit  INT4_IP            =     INTn_IP^4;
sbit  INT3_IP            =     INTn_IP^3;
sbit  INT2_IP            =     INTn_IP^2;
sbit  INT1_IP            =     INTn_IP^1;
sbit  INT0_IP            =     INTn_IP^0;
//
sbit  EINT00_IF           =     EINT0n_IF^0;
sbit  EINT01_IF           =     EINT0n_IF^1;
sbit  EINT02_IF           =     EINT0n_IF^2;
sbit  EINT03_IF           =     EINT0n_IF^3;
sbit  EINT04_IF           =     EINT0n_IF^4;
sbit  EINT05_IF           =     EINT0n_IF^5;
sbit  EINT06_IF           =     EINT0n_IF^6;
sbit  EINT07_IF           =     EINT0n_IF^7;

sbit  EINT10_IF           =     EINT1n_IF^0;
sbit  EINT11_IF           =     EINT1n_IF^1;
sbit  EINT12_IF           =     EINT1n_IF^2;
sbit  EINT13_IF           =     EINT1n_IF^3;
sbit  EINT14_IF           =     EINT1n_IF^4;
sbit  EINT15_IF           =     EINT1n_IF^5;
sbit  EINT16_IF           =     EINT1n_IF^6;
sbit  EINT17_IF           =     EINT1n_IF^7;

//
#endif

