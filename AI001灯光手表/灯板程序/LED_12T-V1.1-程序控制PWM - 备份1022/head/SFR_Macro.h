
/**** P0		80H *****/
#define set_P00			P00		=		1
#define set_P01			P01		=		1
#define set_P02			P02		=		1
#define set_P03			P03		=		1
#define set_P04			P04		=		1
#define set_P05			P05		=		1
#define set_P06			P06		=		1
#define set_P07			P07		=		1

#define clr_P00			P00		=		0
#define clr_P01			P01		=		0
#define clr_P02			P02		=		0
#define clr_P03			P03		=		0
#define clr_P04			P04		=		0
#define clr_P05			P05		=		0
#define clr_P06			P06		=		0
#define clr_P07			P07		=		0

//**** SP  	81H **** 
//**** DPH  82H **** 
//**** DPL  83H **** 
//**** RWK  86H **** 

//**** PCON	87H *****
#define set_SMOD    PCON    |= SET_BIT7
#define set_SMOD0   PCON    |= SET_BIT6
#define set_POF     PCON    |= SET_BIT4
#define set_GF1     PCON    |= SET_BIT3
#define set_GF0     PCON    |= SET_BIT2 
#define set_PD      PCON    |= SET_BIT1
#define set_IDL    	PCON    |= SET_BIT0
                            
#define clr_SMOD    PCON    &= ~SET_BIT7
#define clr_SMOD0   PCON    &= ~SET_BIT6
#define clr_POF     PCON    &= ~SET_BIT4
#define clr_GF1     PCON    &= ~SET_BIT3
#define clr_GF0     PCON    &= ~SET_BIT2 
#define clr_PD      PCON    &= ~SET_BIT1
#define clr_IDL    	PCON    &= ~SET_BIT0

/**** TCON		88H ****/
#define set_TF1			TF1		=		1
#define set_TR1			TR1		=		1
#define set_TF0			TF0		=		1
#define set_TR0			TR0		=		1
#define set_IE1			IE1		=		1
#define set_IT1			IT1		=		1
#define set_IE0			IE0		=		1
#define set_IT0			IT0		=		1

#define clr_TF1			TF1		=		0
#define clr_TR1			TR1		=		0
#define clr_TF0			TF0		=		0
#define clr_TR0			TR0		=		0
#define clr_IE1			IE1		=		0
#define clr_IT1			IT1		=		0
#define clr_IE0			IE0		=		0
#define clr_IT0			IT0		=		0

//**** TMOD		89H **** 
#define set_GATE_T1 	TMOD 		|= 	SET_BIT7
#define set_CT_T1 		TMOD   	|= 	SET_BIT6
#define set_M1_T1 		TMOD  	|= 	SET_BIT5
#define set_M0_T1 		TMOD   	|= 	SET_BIT4
#define set_GATE_T0 	TMOD 		|= 	SET_BIT3
#define set_CT_T0 		TMOD 	  |= 	SET_BIT2
#define set_M1_T0 		TMOD   	|= 	SET_BIT1
#define set_M0_T0 		TMOD   	|= 	SET_BIT0
                            
#define clr_GATE_T1 	TMOD 		&= 	~SET_BIT7
#define clr_CT_T1 		TMOD   	&= 	~SET_BIT6
#define clr_M1_T1 		TMOD   	&= 	~SET_BIT5
#define clr_M0_T1 		TMOD   	&= 	~SET_BIT4
#define clr_GATE_T0 	TMOD 		&= 	~SET_BIT3
#define clr_CT_T0 		TMOD   	&= 	~SET_BIT2
#define clr_M1_T0 		TMOD   	&= 	~SET_BIT1
#define clr_M0_T0 		TMOD   	&= 	~SET_BIT0

//**** TH1		8AH **** 
//**** TH0		8BH **** 
//**** TL1		8CH	**** 
//**** TL0		8DH **** 

//**** CKCON	8EH ****
#define set_PWMCKS  CKCON   |= SET_BIT6
#define set_T1M     CKCON   |= SET_BIT4
#define set_T0M     CKCON   |= SET_BIT3
#define set_CLOEN   CKCON   |= SET_BIT1
                            
#define clr_PWMCKS  CKCON   &= ~SET_BIT6
#define clr_T1M     CKCON   &= ~SET_BIT4
#define clr_T0M     CKCON   &= ~SET_BIT3
#define clr_CLOEN   CKCON   &= ~SET_BIT1

//**** WKCON	8FH ****
#define set_WKTCK   WKCON   |= SET_BIT5
#define set_WKTF    WKCON   |= SET_BIT4
#define set_WKTR    WKCON   |= SET_BIT3
#define set_WKPS2   WKCON   |= SET_BIT2
#define set_WKPS1   WKCON   |= SET_BIT1
#define set_WKPS0   WKCON   |= SET_BIT0
                            
#define clr_WKTCK   WKCON   &= ~SET_BIT5
#define clr_WKTF    WKCON   &= ~SET_BIT4
#define clr_WKTR    WKCON   &= ~SET_BIT3
#define clr_WKPS2   WKCON   &= ~SET_BIT2
#define clr_WKPS1   WKCON   &= ~SET_BIT1
#define clr_WKPS0   WKCON   &= ~SET_BIT0

/**** P1		90H *****/
#define set_P10			P10		=		1
#define set_P11			P11		=		1
#define set_P12			P12		=		1
#define set_P13			P13		=		1
#define set_P14			P14		=		1
#define set_P15			P15		=		1
#define set_P16			P16		=		1
#define set_P17			P17		=		1

#define clr_P10			P10		=		0
#define clr_P11			P11		=		0
#define clr_P12			P12		=		0
#define clr_P13			P13		=		0
#define clr_P14			P14		=		0
#define clr_P15			P15		=		0
#define clr_P16			P16		=		0
#define clr_P17			P17		=		0

//****SFRS		91H ****
#define set_SFRPAGE  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=SET_BIT0;EA=BIT_TMP
#define clr_SFRPAGE  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS&=~SET_BIT0;EA=BIT_TMP

//****CAPCON0	92H ****
#define set_CAPEN2  CAPCON0 |= SET_BIT6
#define set_CAPEN1  CAPCON0 |= SET_BIT5
#define set_CAPEN0  CAPCON0 |= SET_BIT4
#define set_CAPF2   CAPCON0 |= SET_BIT2
#define set_CAPF1   CAPCON0 |= SET_BIT1
#define set_CAPF0   CAPCON0 |= SET_BIT0

#define clr_CAPEN2  CAPCON0 &= ~SET_BIT6
#define clr_CAPEN1  CAPCON0 &= ~SET_BIT5
#define clr_CAPEN0  CAPCON0 &= ~SET_BIT4
#define clr_CAPF2   CAPCON0 &= ~SET_BIT2
#define clr_CAPF1   CAPCON0 &= ~SET_BIT1
#define clr_CAPF0   CAPCON0 &= ~SET_BIT0

//**** CAPCON1	93H ****
#define set_CAP2LS1 CAPCON1 |= SET_BIT5
#define set_CAP2LS0 CAPCON1 |= SET_BIT4
#define set_CAP1LS1 CAPCON1 |= SET_BIT3
#define set_CAP1LS0 CAPCON1 |= SET_BIT2
#define set_CAP0LS1 CAPCON1 |= SET_BIT1
#define set_CAP0LS0 CAPCON1 |= SET_BIT0

#define clr_CAP2LS1 CAPCON1 &= ~SET_BIT5
#define clr_CAP2LS0 CAPCON1 &= ~SET_BIT4
#define clr_CAP1LS1 CAPCON1 &= ~SET_BIT3
#define clr_CAP1LS0 CAPCON1 &= ~SET_BIT2
#define clr_CAP0LS1 CAPCON1 &= ~SET_BIT1
#define clr_CAP0LS0 CAPCON1 &= ~SET_BIT0

//**** CAPCON2		94H ****
#define set_ENF2  CAPCON2   |= SET_BIT6
#define set_ENF1  CAPCON2   |= SET_BIT5
#define set_ENF0  CAPCON2   |= SET_BIT4
                            
#define clr_ENF2  CAPCON2   &= ~SET_BIT6
#define clr_ENF1  CAPCON2   &= ~SET_BIT5
#define clr_ENF0  CAPCON2   &= ~SET_BIT4

//**** CKDIV		95H ****

//**** CKSWT		96H ****  TA protect register
#define set_HIRCST  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKSWT|=SET_BIT5;EA=BIT_TMP;
#define set_LIRCST  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKSWT|=SET_BIT4;EA=BIT_TMP;
#define set_ECLKST  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKSWT|=SET_BIT3;EA=BIT_TMP;
#define set_OSC1    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKSWT|=SET_BIT2;EA=BIT_TMP;
#define set_OSC0    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKSWT|=SET_BIT1;EA=BIT_TMP;

#define clr_HIRCST  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKSWT&=~SET_BIT5;EA=BIT_TMP;
#define clr_LIRCST  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKSWT&=~SET_BIT4;EA=BIT_TMP;
#define clr_ECLKST  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKSWT&=~SET_BIT3;EA=BIT_TMP;
#define clr_OSC1    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKSWT&=~SET_BIT2;EA=BIT_TMP;
#define clr_OSC0    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKSWT&=~SET_BIT1;EA=BIT_TMP;

//**** CKEN 	97H **** TA protect register
#define set_EXTEN1  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN|=SET_BIT7;EA=BIT_TMP;
#define set_EXTEN0  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN|=SET_BIT6;EA=BIT_TMP;
#define set_HIRCEN  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN|=SET_BIT5;EA=BIT_TMP;
#define set_CKSWTF  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN|=SET_BIT0;EA=BIT_TMP;
       
#define clr_EXTEN1  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN&=~SET_BIT7;EA=BIT_TMP;
#define clr_EXTEN0  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN&=~SET_BIT6;EA=BIT_TMP;
#define clr_HIRCEN  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN&=~SET_BIT5;EA=BIT_TMP;
#define clr_CKSWTF  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN&=~SET_BIT0;EA=BIT_TMP;

//**** SCON		98H ****
#define set_FE      FE    = 1
#define set_SM1     SM1   = 1
#define set_SM2     SM2   = 1
#define set_REN     REN   = 1
#define set_TB8     TB8   = 1
#define set_RB8     RB8   = 1
#define set_TI      TI    = 1
#define set_RI      RI    = 1

#define clr_FE      FE    = 0
#define clr_SM1     SM1   = 0
#define clr_SM2     SM2   = 0
#define clr_REN     REN   = 0
#define clr_TB8     TB8   = 0
#define clr_RB8     RB8   = 0
#define clr_TI      TI    = 0
#define clr_RI      RI    = 0

//**** SBUF		99H ****
//**** SBUF_1	9AH ****

//**** EIE		9BH ****                      
#define set_ET2     EIE     |= SET_BIT7
#define set_ESPI    EIE     |= SET_BIT6
#define set_EFB     EIE     |= SET_BIT5
#define set_EWDT    EIE     |= SET_BIT4
#define set_EPWM    EIE     |= SET_BIT3
#define set_ECAP    EIE     |= SET_BIT2
#define set_EPI     EIE     |= SET_BIT1
#define set_EI2C    EIE     |= SET_BIT0
                            
#define clr_ET2     EIE     &= ~SET_BIT7
#define clr_ESPI    EIE     &= ~SET_BIT6
#define clr_EFB     EIE     &= ~SET_BIT5
#define clr_EWDT    EIE     &= ~SET_BIT4
#define clr_EPWM    EIE     &= ~SET_BIT3
#define clr_ECAP    EIE     &= ~SET_BIT2
#define clr_EPI     EIE     &= ~SET_BIT1
#define clr_EI2C    EIE     &= ~SET_BIT0

//**** EIE1		9CH ****                      
#define set_EWKT    EIE1    |= SET_BIT2
#define set_ET3     EIE1    |= SET_BIT1
#define set_ES_1    EIE1    |= SET_BIT0
                            
#define clr_EWKT    EIE1    &= ~SET_BIT2
#define clr_ET3     EIE1    &= ~SET_BIT1
#define clr_ES_1    EIE1    &= ~SET_BIT0
                            
//**** CHPCON		9DH ****  TA protect register
#define set_SWRST   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT7 ;EA=BIT_TMP;
#define set_IAPFF   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT6 ;EA=BIT_TMP;
#define set_BS      BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT1 ;EA=BIT_TMP;
#define set_IAPEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT0 ;EA=BIT_TMP;
       
#define clr_SWRST   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=~SET_BIT7;EA=BIT_TMP;
#define clr_IAPFF   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=~SET_BIT6;EA=BIT_TMP;
#define clr_BS      BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=~SET_BIT1;EA=BIT_TMP;
#define clr_IAPEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=~SET_BIT0;EA=BIT_TMP;

//**** P2		A0H ****

//**** AUXR1	A2H ****
#define set_SWRF    AUXR1   |= SET_BIT7
#define set_RSTPINF AUXR1   |= SET_BIT6
#define set_HARDF  	AUXR1   |= SET_BIT5
#define set_GF2     AUXR1   |= SET_BIT3
#define set_UART0PX AUXR1   |= SET_BIT2
#define set_DPS     AUXR1   |= SET_BIT0
                            
#define clr_SWRF    AUXR1   &= ~SET_BIT7
#define clr_RSTPINF AUXR1   &= ~SET_BIT6
#define clr_HARDF  	AUXR1   &= ~SET_BIT5
#define clr_GF2     AUXR1   &= ~SET_BIT3
#define clr_UART0PX AUXR1   &= ~SET_BIT2
#define clr_DPS     AUXR1   &= ~SET_BIT0

//**** BODCON0	A3H ****  TA protect register
#define set_BODEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT7;EA=BIT_TMP
#define set_BOV2    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT6;EA=BIT_TMP
#define set_BOV1    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT5;EA=BIT_TMP
#define set_BOV0    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT4;EA=BIT_TMP
#define set_BOF     BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT3;EA=BIT_TMP
#define set_BORST   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT2;EA=BIT_TMP
#define set_BORF    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT1;EA=BIT_TMP
#define set_BOS     BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT0;EA=BIT_TMP

#define clr_BODEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=~SET_BIT7;EA=BIT_TMP
#define clr_BOV2    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=~SET_BIT6;EA=BIT_TMP
#define clr_BOV1    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=~SET_BIT5;EA=BIT_TMP
#define clr_BOV0    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=~SET_BIT4;EA=BIT_TMP
#define clr_BOF     BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=~SET_BIT3;EA=BIT_TMP
#define clr_BORST   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=~SET_BIT2;EA=BIT_TMP
#define clr_BORF    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=~SET_BIT1;EA=BIT_TMP
#define clr_BOS     BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=~SET_BIT0;EA=BIT_TMP

//**** IAPTRG		A4H	****  TA protect register
#define set_IAPGO   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPTRG|=SET_BIT0 ;EA=BIT_TMP
#define clr_IAPGO   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPTRG&=~SET_BIT0;EA=BIT_TMP

//**** IAPUEN		A5H **** TA protect register
#define set_CFUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN|=SET_BIT2;EA=BIT_TMP
#define set_LDUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN|=SET_BIT1;EA=BIT_TMP
#define set_APUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN|=SET_BIT0;EA=BIT_TMP

#define clr_CFUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN&=~SET_BIT2;EA=BIT_TMP
#define clr_LDUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN&=~SET_BIT1;EA=BIT_TMP
#define clr_APUEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN&=~SET_BIT0;EA=BIT_TMP

//**** IAPAL	A6H ****
//**** IAPAH	A7H ****

//**** IE			A8H ****
#define set_EA      EA       = 1
#define set_EADC    EADC     = 1
#define set_EBOD    EBOD     = 1
#define set_ES      ES       = 1
#define set_ET1     ET1      = 1
#define set_EX1     EX1      = 1
#define set_ET0     ET0      = 1
#define set_EX0     EX0      = 1

#define clr_EA      EA       = 0
#define clr_EADC    EADC     = 0
#define clr_EBOD    EBOD     = 0
#define clr_ES      ES       = 0
#define clr_ET1     ET1      = 0
#define clr_EX1     EX1      = 0
#define clr_ET0     ET0      = 0
#define clr_EX0     EX0      = 0

//**** SADDR		A9H ****

//**** WDCON		AAH **** TA protect register
#define set_WDTR   	BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT7;EA=BIT_TMP;
#define set_WDCLR   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT6;EA=BIT_TMP;
#define set_WDTF    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT5;EA=BIT_TMP;
#define set_WIDPD		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT4;EA=BIT_TMP;
#define set_WDTRF   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT3;EA=BIT_TMP;
#define set_WPS2    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT2;EA=BIT_TMP;
#define set_WPS1    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT1;EA=BIT_TMP;
#define set_WPS0    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT0;EA=BIT_TMP;
        
#define clr_WDTEN   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=~SET_BIT7;EA=BIT_TMP;
#define clr_WDCLR   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=~SET_BIT6;EA=BIT_TMP;
#define clr_WDTF    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=~SET_BIT5;EA=BIT_TMP;
#define clr_WDTRF   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=~SET_BIT3;EA=BIT_TMP;
#define clr_WPS2    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=~SET_BIT2;EA=BIT_TMP;
#define clr_WPS1    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=~SET_BIT1;EA=BIT_TMP;
#define clr_WPS0    BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=~SET_BIT0;EA=BIT_TMP;

//**** BODCON1 ABH **** TA protect register
#define set_LPBOD1  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1|=SET_BIT2 ;EA=BIT_TMP;
#define set_LPBOD0  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1|=SET_BIT1 ;EA=BIT_TMP;
#define set_BODFLT  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1|=SET_BIT0 ;EA=BIT_TMP;
        
#define clr_LPBOD1  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1&=~SET_BIT2;EA=BIT_TMP;
#define clr_LPBOD0  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1&=~SET_BIT1;EA=BIT_TMP;
#define clr_BODFLT  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1&=~SET_BIT0;EA=BIT_TMP;


//**** P3M1		ACH PAGE0 ****
#define set_P3M1_0  P3M1    |= SET_BIT0
#define clr_P3M1_0  P3M1    &= ~SET_BIT0

//**** P3S		ACH PAGE1 **** SFRS must set as 1 to modify this register  
#define set_P3S_0   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P3S|=SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P3S_0   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P3S&=~SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

//**** P3M2		ADH PAGE0 ****
#define set_P3M2_0  P3M2    |= SET_BIT0
#define clr_P3M2_0  P3M2    &= ~SET_BIT0

//**** P3SR		ADH PAGE1 **** SFRS must set as 1 to modify this register  
#define set_P3SR_0  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P3SR|=SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P3SR_0  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P3SR&=~SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

//**** IAPFD	AEH ****

//**** IAPCN	AFH ****
#define set_FOEN    IAPN    |= SET_BIT5
#define set_FCEN    IAPN    |= SET_BIT4
#define set_FCTRL3  IAPN    |= SET_BIT3
#define set_FCTRL2  IAPN    |= SET_BIT2
#define set_FCTRL1  IAPN    |= SET_BIT1
#define set_FCTRL0  IAPN    |= SET_BIT0
                            
#define clr_FOEN    IAPN    &= ~SET_BIT5
#define clr_FCEN    IAPN    &= ~SET_BIT4
#define clr_FCTRL3  IAPN    &= ~SET_BIT3
#define clr_FCTRL2  IAPN    &= ~SET_BIT2
#define clr_FCTRL1  IAPN    &= ~SET_BIT1
#define clr_FCTRL0  IAPN    &= ~SET_BIT0

//**** P3		B0H ****
#define set_P30     P30      = 1
#define clr_P30     P30      = 0

//**** P0M1	B1H PAGE0 ****
#define set_P0M1_7  P0M1    |= SET_BIT7
#define set_P0M1_6  P0M1    |= SET_BIT6
#define set_P0M1_5  P0M1    |= SET_BIT5 
#define set_P0M1_4  P0M1    |= SET_BIT4
#define set_P0M1_3  P0M1    |= SET_BIT3
#define set_P0M1_2  P0M1    |= SET_BIT2
#define set_P0M1_1  P0M1    |= SET_BIT1
#define set_P0M1_0  P0M1    |= SET_BIT0

#define clr_P0M1_7  P0M1    &= ~SET_BIT7
#define clr_P0M1_6  P0M1    &= ~SET_BIT6
#define clr_P0M1_5  P0M1    &= ~SET_BIT5
#define clr_P0M1_4  P0M1    &= ~SET_BIT4
#define clr_P0M1_3  P0M1    &= ~SET_BIT3
#define clr_P0M1_2  P0M1    &= ~SET_BIT2
#define clr_P0M1_1  P0M1    &= ~SET_BIT1
#define clr_P0M1_0  P0M1    &= ~SET_BIT0

//**** P0S	B2H PAGE1 **** SFRS must set as 1 to modify this register  
#define set_P0S_7   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S|=SET_BIT7;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0S_6   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S|=SET_BIT6;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0S_5   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S|=SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0S_4   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S|=SET_BIT4;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0S_3   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S|=SET_BIT3;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0S_2   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S|=SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0S_1   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S|=SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0S_0   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S|=SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

#define clr_P0S_7   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S&=~SET_BIT7;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0S_6   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S&=~SET_BIT6;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0S_5   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S&=~SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0S_4   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S&=~SET_BIT4;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0S_3   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S&=~SET_BIT3;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0S_2   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S&=~SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0S_1   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S&=~SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0S_0   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0S&=~SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

//**** P0M2		B2H PAGE0 ****
#define set_P0M2_7  P0M2    |= SET_BIT7
#define set_P0M2_6  P0M2    |= SET_BIT6
#define set_P0M2_5  P0M2    |= SET_BIT5 
#define set_P0M2_4  P0M2    |= SET_BIT4
#define set_P0M2_3  P0M2    |= SET_BIT3
#define set_P0M2_2  P0M2    |= SET_BIT2
#define set_P0M2_1  P0M2    |= SET_BIT1
#define set_P0M2_0  P0M2    |= SET_BIT0

#define clr_P0M2_7  P0M2    &= ~SET_BIT7
#define clr_P0M2_6  P0M2    &= ~SET_BIT6
#define clr_P0M2_5  P0M2    &= ~SET_BIT5
#define clr_P0M2_4  P0M2    &= ~SET_BIT4
#define clr_P0M2_3  P0M2    &= ~SET_BIT3
#define clr_P0M2_2  P0M2    &= ~SET_BIT2
#define clr_P0M2_1  P0M2    &= ~SET_BIT1
#define clr_P0M2_0  P0M2    &= ~SET_BIT0


//**** P0SR		B0H PAGE1 **** SFRS must set as 1 to modify this register  
#define set_P0SR_7  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR|=SET_BIT7;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0SR_6  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR|=SET_BIT6;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0SR_5  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR|=SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0SR_4  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR|=SET_BIT4;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0SR_3  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR|=SET_BIT3;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0SR_2  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR|=SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0SR_1  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR|=SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P0SR_0  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR|=SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

#define clr_P0SR_7  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR&=~SET_BIT7;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0SR_6  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR&=~SET_BIT6;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0SR_5  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR&=~SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0SR_4  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR&=~SET_BIT4;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0SR_3  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR&=~SET_BIT3;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0SR_2  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR&=~SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0SR_1  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR&=~SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P0SR_0  BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P0SR&=~SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP


//**** P1M1	B3H PAGE0 ****
#define set_P1M1_7  P1M1	|= SET_BIT7
#define set_P1M1_6  P1M1	|= SET_BIT6
#define set_P1M1_5  P1M1	|= SET_BIT5 
#define set_P1M1_4  P1M1	|= SET_BIT4
#define set_P1M1_3  P1M1	|= SET_BIT3
#define set_P1M1_2  P1M1	|= SET_BIT2
#define set_P1M1_1  P1M1	|= SET_BIT1
#define set_P1M1_0  P1M1	|= SET_BIT0

#define clr_P1M1_7  P1M1	&= ~SET_BIT7
#define clr_P1M1_6  P1M1	&= ~SET_BIT6
#define clr_P1M1_5  P1M1	&= ~SET_BIT5
#define clr_P1M1_4  P1M1	&= ~SET_BIT4
#define clr_P1M1_3  P1M1	&= ~SET_BIT3
#define clr_P1M1_2  P1M1	&= ~SET_BIT2
#define clr_P1M1_1  P1M1	&= ~SET_BIT1
#define clr_P1M1_0  P1M1	&= ~SET_BIT0

//**** P1S B3H PAGE1 **** SFRS must set as 1 to modify this register  
#define set_P1S_7		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S|=SET_BIT7;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1S_6		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S|=SET_BIT6;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1S_5		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S|=SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1S_4		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S|=SET_BIT4;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1S_3		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S|=SET_BIT3;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1S_2   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S|=SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1S_1   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S|=SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1S_0   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S|=SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

#define clr_P1S_7		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S&=~SET_BIT7;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1S_6		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S&=~SET_BIT6;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1S_5		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S&=~SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1S_4		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S&=~SET_BIT4;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1S_3		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S&=~SET_BIT3;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1S_2   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S&=~SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1S_1   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S&=~SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1S_0   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1S&=~SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

//**** P1M2		B4H PAGE0 ****                      
#define set_P12UP   P1M2    |= SET_BIT2
#define set_P1M2_1  P1M2    |= SET_BIT1
#define set_P1M2_0  P1M2    |= SET_BIT0
                            
#define clr_P12UP   P1M2    &= ~SET_BIT2
#define clr_P1M2_1  P1M2    &= ~SET_BIT1
#define clr_P1M2_0  P1M2    &= ~SET_BIT0

//**** P1SR		B4H PAGE1 **** SFRS must set as 1 to modify this register  
#define set_P1SR_7		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR|=SET_BIT7;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1SR_6		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR|=SET_BIT6;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1SR_5		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR|=SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1SR_4		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR|=SET_BIT4;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1SR_3		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR|=SET_BIT3;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1SR_2		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR|=SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1SR_1		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR|=SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_P1SR_0		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR|=SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

#define clr_P1SR_7		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR&=~SET_BIT7;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1SR_6		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR&=~SET_BIT6;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1SR_5		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR&=~SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1SR_4		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR&=~SET_BIT4;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1SR_3		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR&=~SET_BIT3;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1SR_2		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR&=~SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1SR_1		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR&=~SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_P1SR_0		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;P1SR&=~SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP


//**** P2S		B5H	****
#define set_P2S_0   P2S     |= SET_BIT0
#define clr_P2S_0   P2S     &= ~SET_BIT0

//**** IPH    B7H PAGE0 ****                    
#define set_PADCH   IPH		|= SET_BIT6
#define set_PBODH   IPH		|= SET_BIT5
#define set_PSH     IPH		|= SET_BIT4
#define set_PT1H    IPH		|= SET_BIT3
#define set_PX11    IPH		|= SET_BIT2
#define set_PT0H    IPH		|= SET_BIT1
#define set_PX0H    IPH		|= SET_BIT0
                            
#define clr_PADCH   IPH		&= ~SET_BIT6
#define clr_PBODH   IPH		&= ~SET_BIT5
#define clr_PSH     IPH		&= ~SET_BIT4
#define clr_PT1H    IPH		&= ~SET_BIT3
#define clr_PX11    IPH		&= ~SET_BIT2
#define clr_PT0H    IPH		&= ~SET_BIT1
#define clr_PX0H    IPH		&= ~SET_BIT0

//**** PWMINTC B7H PAGE1 **** SFRS must set as 1 to modify this register  
#define set_INTTYP1		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC|=SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_INTTYP0		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC|=SET_BIT4;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_INTSEL2		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC|=SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_INTSEL1		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC|=SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_INTSEL0		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC|=SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

#define clr_INTTYP1   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=~SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_INTTYP0   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=~SET_BIT4;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_INTSEL2		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=~SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_INTSEL1		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=~SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_INTSEL0		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=~SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

//**** IP		B8H	****
#define set_PADC    PADC     = 1
#define set_PBOD    PBOD     = 1
#define set_PS      PS       = 1
#define set_PT1     PT1      = 1
#define set_PX1     PX1      = 1
#define set_PT0     PT0      = 1
#define set_PX0     PX0      = 1

#define clr_PADC    PADC     = 0
#define clr_PBOD    PBOD     = 0
#define clr_PS      PS       = 0
#define clr_PT1     PT1      = 0
#define clr_PX1     PX1      = 0
#define clr_PT0     PT0      = 0
#define clr_PX0     PX0      = 0

//**** SADEN		B9H ****
//**** SADEN_1	8AH ****
//**** SADDR_1	BBH ****
//**** I2DAT		BCH ****
//**** I2STAT		BDH ****
//**** I2CLK		BEH ****

//**** I2TOC		BFH ****
#define set_I2TOCEN		I2TOC		|= SET_BIT2
#define set_DIV				I2TOC		|= SET_BIT1
#define set_I2TOF			I2TOC		|= SET_BIT0

#define clr_I2TOCEN		I2TOC		&= ~SET_BIT2
#define clr_DIV				I2TOC		&= ~SET_BIT1
#define clr_I2TOF			I2TOC		&= ~SET_BIT0

//**** I2CON  C0H **** 
#define set_I2CEN   	I2CEN		= 1
#define set_STA     	STA			= 1
#define set_STO				STO			= 1
#define set_SI				SI			= 1
#define set_AA				AA			= 1
#define set_I2CPX			I2CPX		= 1

#define clr_I2CEN			I2CEN		= 0
#define clr_STA				STA			= 0
#define clr_STO				STO			= 0
#define clr_SI				SI			= 0
#define clr_AA				AA			= 0
#define clr_I2CPX			I2CPX		= 0 

//**** I2ADDR		C1H ****
#define set_GC      I2ADDR  |= SET_BIT0
#define clr_GC      I2ADDR  &= ~SET_BIT0

//**** ADCRL		C2H ****
//**** ADCRH		C3H ****

//**** T3CON		C4H	PAGE0 ****                     
#define set_SMOD_1  T3CON   |= SET_BIT7
#define set_SMOD0_1 T3CON   |= SET_BIT6
#define set_BRCK    T3CON   |= SET_BIT5
#define set_TF3     T3CON   |= SET_BIT4
#define set_TR3     T3CON   |= SET_BIT3
#define set_T3PS2   T3CON   |= SET_BIT2
#define set_T3PS1   T3CON   |= SET_BIT1
#define set_T3PS0   T3CON   |= SET_BIT0
                            
#define clr_SMOD_1  T3CON   &= ~SET_BIT7
#define clr_SMOD0_1 T3CON   &= ~SET_BIT6
#define clr_BRCK    T3CON   &= ~SET_BIT5
#define clr_TF3     T3CON   &= ~SET_BIT4
#define clr_TR3     T3CON   &= ~SET_BIT3
#define clr_T3PS2   T3CON   &= ~SET_BIT2
#define clr_T3PS1   T3CON   &= ~SET_BIT1
#define clr_T3PS0   T3CON   &= ~SET_BIT0

//**** PWM4H	C4H	PAGE1 **** SFRS must set as 1 to modify this register  
//**** RL3		C5H PAGE0 ****
//**** PWM5H	C5H PAGE1 **** SFRS must set as 1 to modify this register  
//**** RH3		C6H PAGE0 ****

//**** PIOCON1 C6H PAGE1 **** SFRS must set as 1 to modify this register  
#define set_PIO15		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PIOCON1|=SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_PIO13   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PIOCON1|=SET_BIT3;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_PIO12   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PIOCON1|=SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_PIO11   BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PIOCON1|=SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

#define clr_PIO15		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PIOCON1&=~SET_BIT5;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_PIO13		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PIOCON1&=~SET_BIT3;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_PIO12		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PIOCON1&=~SET_BIT2;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_PIO11		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PIOCON1&=~SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

//**** T2CON  C8H ****
#define set_TF2     TF2      = 1
#define set_TR2     TR2      = 1
#define set_CMRL2   CMRL2    = 1

#define clr_TF2     TF2      = 0
#define clr_TR2     TR2      = 0
#define clr_CMRL2   CMRL2    = 0

//**** T2MOD	C9H ****                     
#define set_LDEN    T2MOD   |= SET_BIT7
#define set_T2DIV2  T2MOD   |= SET_BIT6
#define set_T2DIV1  T2MOD   |= SET_BIT5
#define set_T2DIV0  T2MOD   |= SET_BIT4
#define set_CAPCR   T2MOD   |= SET_BIT3
#define set_CMPCR   T2MOD   |= SET_BIT2
#define set_LDTS1   T2MOD   |= SET_BIT1
#define set_LDTS0   T2MOD   |= SET_BIT0
                            
#define clr_LDEN    T2MOD   &= ~SET_BIT7
#define clr_T2DIV2  T2MOD   &= ~SET_BIT6
#define clr_T2DIV1  T2MOD   &= ~SET_BIT5
#define clr_T2DIV0  T2MOD   &= ~SET_BIT4
#define clr_CAPCR   T2MOD   &= ~SET_BIT3
#define clr_CMPCR   T2MOD   &= ~SET_BIT2
#define clr_LDTS1   T2MOD   &= ~SET_BIT1
#define clr_LDTS0   T2MOD   &= ~SET_BIT0

//**** RCMP2H CAH ****
//**** RCMP2L CBH ****
//**** TL2		CCH PAGE0 ****
//**** PWM4L 	CCH PAGE1 **** SFRS must set as 1 to modify this register  
//**** TH2		CDH PAGE0 ****
//**** PWM5L	CDH PAGE1 **** SFRS must set as 1 to modify this register  
//**** ADCMPL	CEH **** 
//**** ADCMPH	CFH ****

/****  PSW 		D0H ****/
#define set_CY   	CY	= 1
#define set_AC		AC  = 1
#define set_F0    F0	= 1 
#define set_RS1		RS1 = 1
#define set_RS0		RS0 = 1
#define set_OV		OV 	= 1
#define set_P			P		= 1

#define clr_CY   	CY	= 0
#define clr_AC		AC  = 0
#define clr_F0    F0	= 0 
#define clr_RS1		RS1 = 0
#define clr_RS0		RS0 = 0
#define clr_OV		OV 	= 0
#define clr_P			P		= 0

//**** PWMPH		D1H ****
//**** PWM0H		D2H ****
//**** PWM1H		D3H ****
//**** PWM2H		D4H ****
//**** PWM3H		D5H	****

//**** PNP			D6H ****
#define set_PNP5    PNP     |= SET_BIT5
#define set_PNP4    PNP     |= SET_BIT4
#define set_PNP3    PNP     |= SET_BIT3
#define set_PNP2    PNP     |= SET_BIT2
#define set_PNP1    PNP     |= SET_BIT1
#define set_PNP0    PNP     |= SET_BIT0

#define clr_PNP5    PNP     &= ~SET_BIT5
#define clr_PNP4    PNP     &= ~SET_BIT4
#define clr_PNP3    PNP     &= ~SET_BIT3
#define clr_PNP2    PNP     &= ~SET_BIT2
#define clr_PNP1    PNP     &= ~SET_BIT1
#define clr_PNP0    PNP     &= ~SET_BIT0

//**** FBD		D7H ****
#define set_FBF     FBD     |= SET_BIT7
#define set_FBINLS  FBD     |= SET_BIT6
#define set_FBD5    FBD     |= SET_BIT5
#define set_FBD4    FBD     |= SET_BIT4
#define set_FBD3    FBD     |= SET_BIT3
#define set_FBD2    FBD     |= SET_BIT2
#define set_FBD1    FBD     |= SET_BIT1
#define set_FBD0    FBD     |= SET_BIT0

#define clr_FBF     FBD     &= ~SET_BIT7
#define clr_FBINLS  FBD     &= ~SET_BIT6
#define clr_FBD5    FBD     &= ~SET_BIT5
#define clr_FBD4    FBD     &= ~SET_BIT4
#define clr_FBD3    FBD     &= ~SET_BIT3
#define clr_FBD2    FBD     &= ~SET_BIT2
#define clr_FBD1    FBD     &= ~SET_BIT1
#define clr_FBD0    FBD     &= ~SET_BIT0

/**** PWMCON0			D8H ****/
#define set_PWMRUN  PWMRUN   = 1
#define set_LOAD    LOAD     = 1
#define set_PWMF    PWMF     = 1
#define set_CLRPWM  CLRPWM   = 1

#define clr_PWMRUN  PWMRUN   = 0
#define clr_LOAD    LOAD     = 0
#define clr_PWMF    PWMF     = 0 
#define clr_CLRPWM  CLRPWM   = 0

//**** PWMPL		D9H ****
//**** PWM0L		DAH ****
//**** PWM1L		DBH ****
//**** PWM2L		DCH ****
//**** PWM3L		DDH ****

//**** PIOCON0	DEH ****
#define set_PIO05    PIOCON0     |= SET_BIT5
#define set_PIO04    PIOCON0     |= SET_BIT4
#define set_PIO03    PIOCON0     |= SET_BIT3
#define set_PIO02    PIOCON0     |= SET_BIT2
#define set_PIO01    PIOCON0     |= SET_BIT1
#define set_PIO00    PIOCON0     |= SET_BIT0

#define clr_PIO05    PIOCON0     &= ~SET_BIT5
#define clr_PIO04    PIOCON0     &= ~SET_BIT4
#define clr_PIO03    PIOCON0     &= ~SET_BIT3
#define clr_PIO02    PIOCON0     &= ~SET_BIT2
#define clr_PIO01    PIOCON0     &= ~SET_BIT1
#define clr_PIO00    PIOCON0     &= ~SET_BIT0

//**** PWMCON1	DFH ****
#define set_PWMMOD1		PWMCON1  |= SET_BIT7
#define set_PWMMOD0		PWMCON1  |= SET_BIT6
#define set_GP      	PWMCON1  |= SET_BIT5
#define set_PWMTYP  	PWMCON1  |= SET_BIT4
#define set_FBINEN		PWMCON1  |= SET_BIT3
#define set_PWMDIV2		PWMCON1  |= SET_BIT2 
#define set_PWMDIV1		PWMCON1  |= SET_BIT1
#define set_PWMDIV0		PWMCON1  |= SET_BIT0
                            
#define clr_PWMMOD1		PWMCON1  &= ~SET_BIT7
#define clr_PWMMOD0		PWMCON1  &= ~SET_BIT6
#define clr_GP				PWMCON1  &= ~SET_BIT5
#define clr_PWMTYP		PWMCON1  &= ~SET_BIT4
#define clr_FBINEN		PWMCON1  &= ~SET_BIT3
#define clr_PWMDIV2		PWMCON1  &= ~SET_BIT2 
#define clr_PWMDIV1		PWMCON1  &= ~SET_BIT1
#define clr_PWMDIV0		PWMCON1  &= ~SET_BIT0

//**** ACC	E0H ****

//**** ADCCON1	E1H ****
#define set_STADCPX ADCCON1  |= SET_BIT6
#define set_ETGTYP1 ADCCON1  |= SET_BIT3
#define set_ETGTYP0 ADCCON1  |= SET_BIT2
#define set_ADCEX   ADCCON1  |= SET_BIT1
#define set_ADCEN   ADCCON1  |= SET_BIT0

#define clr_STADCPX ADCCON1  &= ~SET_BIT6
#define clr_ETGTYP1 ADCCON1  &= ~SET_BIT3
#define clr_ETGTYP0 ADCCON1  &= ~SET_BIT2
#define clr_ADCEX   ADCCON1  &= ~SET_BIT1
#define clr_ADCEN   ADCCON1  &= ~SET_BIT0

//**** ADCON2		E2H ****
#define set_ADFBEN  ADCCON2  |= SET_BIT7
#define set_ADCMPOP ADCCON2  |= SET_BIT6
#define set_ADCMPEN ADCCON2  |= SET_BIT5
#define set_ADCMPO  ADCCON2  |= SET_BIT4

#define clr_ADFBEN  ADCCON2  &= ~SET_BIT7
#define clr_ADCMPOP ADCCON2  &= ~SET_BIT6
#define clr_ADCMPEN ADCCON2  &= ~SET_BIT5
#define clr_ADCMPO  ADCCON2  &= ~SET_BIT4

//**** ADCDLY		E3H ****
//**** C0L			E4H ****
//**** C0H			E5H ****
//**** C1L			E6H ****
//**** C1H			E7H ****

//**** ADCCON0	EAH ****
#define set_ADCF    ADCF     = 1
#define set_ADCS    ADCS     = 1
#define set_ETGSEL1 ETGSEL1  = 1
#define set_ETGSEL0 ETGSEL0  = 1
#define set_ADCHS3  ADCHS3   = 1
#define set_ADCHS2  ADCHS2   = 1
#define set_ADCHS1  ADCHS1   = 1
#define set_ADCHS0  ADCHS0   = 1

#define clr_ADCF    ADCF     = 0
#define clr_ADCS    ADCS     = 0
#define clr_ETGSEL1 ETGSEL1  = 0
#define clr_ETGSEL0 ETGSEL0  = 0
#define clr_ADCHS3  ADCHS3   = 0
#define clr_ADCHS2  ADCHS2   = 0
#define clr_ADCHS1  ADCHS1   = 0
#define clr_ADCHS0  ADCHS0   = 0

//**** PICON	E9H	****
#define set_PIT67   PICON   |= SET_BIT7
#define set_PIT45   PICON   |= SET_BIT6
#define set_PIT3    PICON   |= SET_BIT5
#define set_PIT2    PICON   |= SET_BIT4
#define set_PIT1    PICON   |= SET_BIT3
#define set_PIT0    PICON   |= SET_BIT2
#define set_PIPS1   PICON   |= SET_BIT1
#define set_PIPS0   PICON   |= SET_BIT0
                            
#define clr_PIT67   PICON   &= ~SET_BIT7
#define clr_PIT45   PICON   &= ~SET_BIT6
#define clr_PIT3    PICON   &= ~SET_BIT5
#define clr_PIT2    PICON   &= ~SET_BIT4
#define clr_PIT1    PICON   &= ~SET_BIT3
#define clr_PIT0    PICON   &= ~SET_BIT2
#define clr_PIPS1   PICON   &= ~SET_BIT1
#define clr_PIPS0   PICON   &= ~SET_BIT0

//**** PINEN		EAH **** 
#define set_PINEN7  PINEN   |= SET_BIT7
#define set_PINEN6  PINEN   |= SET_BIT6
#define set_PINEN5  PINEN   |= SET_BIT5
#define set_PINEN4  PINEN   |= SET_BIT4
#define set_PINEN3  PINEN   |= SET_BIT3
#define set_PINEN2  PINEN   |= SET_BIT2
#define set_PINEN1  PINEN   |= SET_BIT1
#define set_PINEN0  PINEN   |= SET_BIT0
                            
#define clr_PINEN7  PINEN   &= ~SET_BIT7
#define clr_PINEN6  PINEN   &= ~SET_BIT6
#define clr_PINEN5  PINEN   &= ~SET_BIT5
#define clr_PINEN4  PINEN   &= ~SET_BIT4
#define clr_PINEN3  PINEN   &= ~SET_BIT3
#define clr_PINEN2  PINEN   &= ~SET_BIT2
#define clr_PINEN1  PINEN   &= ~SET_BIT1
#define clr_PINEN0  PINEN   &= ~SET_BIT0
                            
//**** PIPEN 		EBH ****
#define set_PIPEN7  PIPEN   |= SET_BIT7
#define set_PIPEN6  PIPEN   |= SET_BIT6
#define set_PIPEN5  PIPEN   |= SET_BIT5
#define set_PIPEN4  PIPEN   |= SET_BIT4
#define set_PIPEN3  PIPEN   |= SET_BIT3
#define set_PIPEN2  PIPEN   |= SET_BIT2
#define set_PIPEN1  PIPEN   |= SET_BIT1
#define set_PIPEN0  PIPEN   |= SET_BIT0
                            
#define clr_PIPEN7  PIPEN   &= ~SET_BIT7
#define clr_PIPEN6  PIPEN   &= ~SET_BIT6
#define clr_PIPEN5  PIPEN   &= ~SET_BIT5
#define clr_PIPEN4  PIPEN   &= ~SET_BIT4
#define clr_PIPEN3  PIPEN   &= ~SET_BIT3
#define clr_PIPEN2  PIPEN   &= ~SET_BIT2
#define clr_PIPEN1  PIPEN   &= ~SET_BIT1
#define clr_PIPEN0  PIPEN   &= ~SET_BIT0
   
//**** PIF	ECH ****
#define set_PIF7    PIF     |= SET_BIT7
#define set_PIF6    PIF     |= SET_BIT6
#define set_PIF5    PIF     |= SET_BIT5
#define set_PIF4    PIF     |= SET_BIT4
#define set_PIF3    PIF     |= SET_BIT3
#define set_PIF2    PIF     |= SET_BIT2
#define set_PIF1    PIF     |= SET_BIT1
#define set_PIF0    PIF     |= SET_BIT0

#define clr_PIF7    PIF     &= ~SET_BIT7
#define clr_PIF6    PIF     &= ~SET_BIT6
#define clr_PIF5    PIF     &= ~SET_BIT5
#define clr_PIF4    PIF     &= ~SET_BIT4
#define clr_PIF3    PIF     &= ~SET_BIT3
#define clr_PIF2    PIF     &= ~SET_BIT2
#define clr_PIF1    PIF     &= ~SET_BIT1
#define clr_PIF0    PIF     &= ~SET_BIT0

//**** C2L  EDH ****  
//**** C2H	EEH ****

//**** EIP	EFH ****                      
#define set_PT2     EIP     |= SET_BIT7
#define set_PSPI    EIP     |= SET_BIT6
#define set_PFB     EIP     |= SET_BIT5
#define set_PWDT    EIP     |= SET_BIT4
#define set_PPWM    EIP     |= SET_BIT3
#define set_PCAP    EIP     |= SET_BIT2
#define set_PPI     EIP     |= SET_BIT1
#define set_PI2C    EIP     |= SET_BIT0
                            
#define clr_PT2     EIP     &= ~SET_BIT7
#define clr_PSPI    EIP     &= ~SET_BIT6
#define clr_PFB     EIP     &= ~SET_BIT5
#define clr_PWDT    EIP     &= ~SET_BIT4
#define clr_PPWM    EIP     &= ~SET_BIT3
#define clr_PCAP    EIP     &= ~SET_BIT2
#define clr_PPI     EIP     &= ~SET_BIT1
#define clr_PI2C    EIP     &= ~SET_BIT0

//**** B	F0H ****

//**** CAPCON3		F1H ****
#define set_CAP13   CAPCON3    |= SET_BIT7
#define set_CAP12   CAPCON3    |= SET_BIT6
#define set_CAP11   CAPCON3    |= SET_BIT5
#define set_CAP10   CAPCON3    |= SET_BIT4
#define set_CAP03   CAPCON3    |= SET_BIT3
#define set_CAP02   CAPCON3    |= SET_BIT2
#define set_CAP01   CAPCON3    |= SET_BIT1
#define set_CAP00   CAPCON3    |= SET_BIT0

#define clr_CAP13   CAPCON3    &= ~SET_BIT7
#define clr_CAP12   CAPCON3    &= ~SET_BIT6
#define clr_CAP11   CAPCON3    &= ~SET_BIT5
#define clr_CAP10   CAPCON3    &= ~SET_BIT4
#define clr_CAP03   CAPCON3    &= ~SET_BIT3
#define clr_CAP02   CAPCON3    &= ~SET_BIT2
#define clr_CAP01   CAPCON3    &= ~SET_BIT1
#define clr_CAP00   CAPCON3    &= ~SET_BIT0

//**** CAPCON4		F2H ****
#define set_CAP23    CAPCON4    |= SET_BIT3
#define set_CAP22    CAPCON4    |= SET_BIT2
#define set_CAP21    CAPCON4    |= SET_BIT1
#define set_CAP20    CAPCON4    |= SET_BIT0

#define clr_CAP23    CAPCON4    &= ~SET_BIT3
#define clr_CAP22    CAPCON4    &= ~SET_BIT2
#define clr_CAP21    CAPCON4    &= ~SET_BIT1
#define clr_CAP20    CAPCON4    &= ~SET_BIT0

//**** SPCR		F3H PAGE0 ****
#define set_SSOE    SPCR    |= SET_BIT7
#define set_SPIEN   SPCR    |= SET_BIT6
#define set_LSBFE   SPCR    |= SET_BIT5
#define set_MSTR    SPCR    |= SET_BIT4
#define set_CPOL    SPCR    |= SET_BIT3
#define set_CPHA    SPCR    |= SET_BIT2
#define set_SPR1    SPCR    |= SET_BIT1
#define set_SPR0    SPCR    |= SET_BIT0

#define clr_SSOE    SPCR    &= ~SET_BIT7
#define clr_SPIEN   SPCR    &= ~SET_BIT6
#define clr_LSBFE   SPCR    &= ~SET_BIT5
#define clr_MSTR    SPCR    &= ~SET_BIT4
#define clr_CPOL    SPCR    &= ~SET_BIT3
#define clr_CPHA    SPCR    &= ~SET_BIT2
#define clr_SPR1    SPCR    &= ~SET_BIT1
#define clr_SPR0    SPCR    &= ~SET_BIT0

//**** SPCR2		F3H PAGE1 **** SFRS must set as 1 to modify this register  
#define set_SPIS1		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;SPCR2|=SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define set_SPIS0		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x00;SPCR2|=SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

#define clr_SPIS1		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x00;SPCR2&=~SET_BIT1;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define clr_SPIS0		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x00;SPCR2&=~SET_BIT0;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP

//**** SPSR			F4H ****
#define set_SPIF    SPSR    |= SET_BIT7
#define set_WCOL    SPSR    |= SET_BIT6
#define set_SPIOVF  SPSR    |= SET_BIT5
#define set_MODF    SPSR    |= SET_BIT4
#define set_DISMODF SPSR    |= SET_BIT3
                            
#define clr_SPIF    SPSR    &= ~SET_BIT7
#define clr_WCOL    SPSR    &= ~SET_BIT6
#define clr_SPIOVF  SPSR    &= ~SET_BIT5
#define clr_MODF    SPSR    &= ~SET_BIT4
#define clr_DISMODF SPSR    &= ~SET_BIT3

//**** SPDR		F5H ****

//**** AINDIDS	F6H ****
#define set_P11DIDS AINDIDS  |= SET_BIT7
#define set_P03DIDS AINDIDS  |= SET_BIT6
#define set_P04DIDS AINDIDS  |= SET_BIT5
#define set_P05DIDS AINDIDS  |= SET_BIT4
#define set_P06DIDS AINDIDS  |= SET_BIT3
#define set_P07DIDS AINDIDS  |= SET_BIT2
#define set_P30DIDS AINDIDS  |= SET_BIT1
#define set_P17DIDS AINDIDS  |= SET_BIT0

#define clr_P11DIDS AINDIDS  &= ~SET_BIT7
#define clr_P03DIDS AINDIDS  &= ~SET_BIT6
#define clr_P04DIDS AINDIDS  &= ~SET_BIT5
#define clr_P05DIDS AINDIDS  &= ~SET_BIT4
#define clr_P06DIDS AINDIDS  &= ~SET_BIT3
#define clr_P07DIDS AINDIDS  &= ~SET_BIT2
#define clr_P30DIDS AINDIDS  &= ~SET_BIT1
#define clr_P17DIDS AINDIDS  &= ~SET_BIT0

//**** EIPH			F7H ****
#define set_PT2H    EIPH    |= SET_BIT7
#define set_PSPIH   EIPH    |= SET_BIT6
#define set_PFBH    EIPH    |= SET_BIT5
#define set_PWDTH   EIPH    |= SET_BIT4
#define set_PPWMH   EIPH    |= SET_BIT3
#define set_PCAPH   EIPH    |= SET_BIT2
#define set_PPIH    EIPH    |= SET_BIT1
#define set_PI2CH   EIPH    |= SET_BIT0
                            
#define clr_PT2H    EIPH    &= ~SET_BIT7
#define clr_PSPIH   EIPH    &= ~SET_BIT6
#define clr_PFBH    EIPH    &= ~SET_BIT5
#define clr_PWDTH   EIPH    &= ~SET_BIT4
#define clr_PPWMH   EIPH    &= ~SET_BIT3
#define clr_PCAPH   EIPH    &= ~SET_BIT2
#define clr_PPIH    EIPH    &= ~SET_BIT1
#define clr_PI2CH   EIPH    &= ~SET_BIT0

/**** SCON_1		F8H ****/
#define set_FE_1    FE_1  = 1
#define set_SM1_1   SM1_1 = 1
#define set_SM2_1   SM2_1 = 1
#define set_REN_1   REN_1 = 1
#define set_TB8_1   TB8_1 = 1
#define set_RB8_1   RB8_1 = 1
#define set_TI_1    TI_1  = 1
#define set_RI_1    RI_1  = 1

#define clr_FE_1    FE_1  = 0
#define clr_SM1_1   SM1_1 = 0
#define clr_SM2_1   SM2_1 = 0
#define clr_REN_1   REN_1 = 0
#define clr_TB8_1   TB8_1 = 0
#define clr_RB8_1   RB8_1 = 0
#define clr_TI_1    TI_1  = 0
#define clr_RI_1    RI_1  = 0

//**** PDTEN		F9H ****
#define set_PDT45EN BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|= SET_BIT2  ;EA=BIT_TMP;
#define set_PDT23EN BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|= SET_BIT1  ;EA=BIT_TMP;
#define set_PDT01EN BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|= SET_BIT0  ;EA=BIT_TMP;

#define clr_PDT45EN BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN &= ~SET_BIT2 ;EA=BIT_TMP;
#define clr_PDT23EN BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN &= ~SET_BIT1 ;EA=BIT_TMP;
#define clr_PDT01EN BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN &= ~SET_BIT0 ;EA=BIT_TMP;

//**** PDTCNT		FAH ****

//**** PMEN   	FBH ****                   
#define set_PMEN5   PMEN    |= SET_BIT5
#define set_PMEN4   PMEN    |= SET_BIT4
#define set_PMEN3   PMEN    |= SET_BIT3
#define set_PMEN2   PMEN    |= SET_BIT2
#define set_PMEN1   PMEN    |= SET_BIT1
#define set_PMEN0   PMEN    |= SET_BIT0
                            
#define clr_PMEN5   PMEN    &= ~SET_BIT5
#define clr_PMEN4   PMEN    &= ~SET_BIT4
#define clr_PMEN3   PMEN    &= ~SET_BIT3
#define clr_PMEN2   PMEN    &= ~SET_BIT2
#define clr_PMEN1   PMEN    &= ~SET_BIT1
#define clr_PMEN0   PMEN    &= ~SET_BIT0
                            
//**** PMD		FCH ****                       
#define set_PMD7    PMD     |= SET_BIT7
#define set_PMD6    PMD     |= SET_BIT6
#define set_PMD5    PMD     |= SET_BIT5
#define set_PMD4    PMD     |= SET_BIT4
#define set_PMD3    PMD     |= SET_BIT3
#define set_PMD2    PMD     |= SET_BIT2
#define set_PMD1    PMD     |= SET_BIT1
#define set_PMD0    PMD     |= SET_BIT0
                            
#define clr_PMD7    PMD     &= ~SET_BIT7
#define clr_PMD6    PMD     &= ~SET_BIT6
#define clr_PMD5    PMD     &= ~SET_BIT5
#define clr_PMD4    PMD     &= ~SET_BIT4
#define clr_PMD3    PMD     &= ~SET_BIT3
#define clr_PMD2    PMD     &= ~SET_BIT2
#define clr_PMD1    PMD     &= ~SET_BIT1
#define clr_PMD0    PMD     &= ~SET_BIT0

//****	EIP1 		FEH ****                     
#define set_PWKT    EIP1    |= SET_BIT2
#define set_PT3     EIP1    |= SET_BIT1
#define set_PS_1    EIP1    |= SET_BIT0
                            
#define clr_PWKT    EIP1    &= ~SET_BIT2
#define clr_PT3     EIP1    &= ~SET_BIT1
#define clr_PS_1    EIP1    &= ~SET_BIT0

//**** EIPH1		FFH ****                
#define set_PWKTH   EIPH1   |= SET_BIT2
#define set_PT3H    EIPH1   |= SET_BIT1
#define set_PSH_1   EIPH1   |= SET_BIT0
                            
#define clr_PWKTH   EIPH1   &= ~SET_BIT2
#define clr_PT3H    EIPH1   &= ~SET_BIT1
#define clr_PSH_1   EIPH1   &= ~SET_BIT0

/******************************************************************************************************************************/
#include <intrins.h>
#include <stdio.h>

#define nop _nop_();


//16 --> 8 x 2
#define HIBYTE(v1)              ((UINT8)((v1)>>8))                      //v1 is UINT16
#define LOBYTE(v1)              ((UINT8)((v1)&0xFF))
//8 x 2 --> 16
#define MAKEWORD(v1,v2)         ((((UINT16)(v1))<<8)+(UINT16)(v2))      //v1,v2 is UINT8
//8 x 4 --> 32
#define MAKELONG(v1,v2,v3,v4)   (UINT32)((v1<<32)+(v2<<16)+(v3<<8)+v4)  //v1,v2,v3,v4 is UINT8
//32 --> 16 x 2
#define YBYTE1(v1)              ((UINT16)((v1)>>16))                    //v1 is UINT32
#define YBYTE0(v1)              ((UINT16)((v1)&0xFFFF))
//32 --> 8 x 4
#define TBYTE3(v1)              ((UINT8)((v1)>>24))                     //v1 is UINT32
#define TBYTE2(v1)              ((UINT8)((v1)>>16))
#define TBYTE1(v1)              ((UINT8)((v1)>>8)) 
#define TBYTE0(v1)              ((UINT8)((v1)&0xFF))

#define SET_BIT0        0x01
#define SET_BIT1        0x02
#define SET_BIT2        0x04
#define SET_BIT3        0x08
#define SET_BIT4        0x10
#define SET_BIT5        0x20
#define SET_BIT6        0x40
#define SET_BIT7        0x80
#define SET_BIT8        0x0100
#define SET_BIT9        0x0200
#define SET_BIT10       0x0400
#define SET_BIT11       0x0800
#define SET_BIT12       0x1000
#define SET_BIT13       0x2000
#define SET_BIT14       0x4000
#define SET_BIT15       0x8000

#define CLR_BIT0        0xFE
#define CLR_BIT1        0xFD
#define CLR_BIT2        0xFB
#define CLR_BIT3        0xF7
#define CLR_BIT4        0xEF
#define CLR_BIT5        0xDF
#define CLR_BIT6        0xBF
#define CLR_BIT7        0x7F

#define CLR_BIT8        0xFEFF
#define CLR_BIT9        0xFDFF
#define CLR_BIT10       0xFBFF
#define CLR_BIT11       0xF7FF
#define CLR_BIT12       0xEFFF
#define CLR_BIT13       0xDFFF
#define CLR_BIT14       0xBFFF
#define CLR_BIT15       0x7FFF

#define FAIL            1
#define PASS            0

/*****************************************************************************************
* For GPIO INIT setting 
*****************************************************************************************/
//------------------- Define Port as Quasi mode  -------------------
#define P00_Quasi_Mode				P0M1&=~SET_BIT0;P0M2&=~SET_BIT0
#define P01_Quasi_Mode				P0M1&=~SET_BIT1;P0M2&=~SET_BIT1
#define P02_Quasi_Mode				P0M1&=~SET_BIT2;P0M2&=~SET_BIT2
#define P03_Quasi_Mode				P0M1&=~SET_BIT3;P0M2&=~SET_BIT3
#define P04_Quasi_Mode				P0M1&=~SET_BIT4;P0M2&=~SET_BIT4
#define P05_Quasi_Mode				P0M1&=~SET_BIT5;P0M2&=~SET_BIT5
#define P06_Quasi_Mode				P0M1&=~SET_BIT6;P0M2&=~SET_BIT6
#define P07_Quasi_Mode				P0M1&=~SET_BIT7;P0M2&=~SET_BIT7
#define P10_Quasi_Mode				P1M1&=~SET_BIT0;P1M2&=~SET_BIT0
#define P11_Quasi_Mode				P1M1&=~SET_BIT1;P1M2&=~SET_BIT1
#define P12_Quasi_Mode				P1M1&=~SET_BIT2;P1M2&=~SET_BIT2
#define P13_Quasi_Mode				P1M1&=~SET_BIT3;P1M2&=~SET_BIT3
#define P14_Quasi_Mode				P1M1&=~SET_BIT4;P1M2&=~SET_BIT4
#define P15_Quasi_Mode				P1M1&=~SET_BIT5;P1M2&=~SET_BIT5
#define P16_Quasi_Mode				P1M1&=~SET_BIT6;P1M2&=~SET_BIT6
#define P17_Quasi_Mode				P1M1&=~SET_BIT7;P1M2&=~SET_BIT7
#define P30_Quasi_Mode				P3M1&=~SET_BIT0;P3M2&=~SET_BIT0
//------------------- Define Port as Push Pull mode -------------------
#define P00_PushPull_Mode			P0M1&=~SET_BIT0;P0M2|=SET_BIT0
#define P01_PushPull_Mode			P0M1&=~SET_BIT1;P0M2|=SET_BIT1
#define P02_PushPull_Mode			P0M1&=~SET_BIT2;P0M2|=SET_BIT2
#define P03_PushPull_Mode			P0M1&=~SET_BIT3;P0M2|=SET_BIT3
#define P04_PushPull_Mode			P0M1&=~SET_BIT4;P0M2|=SET_BIT4
#define P05_PushPull_Mode			P0M1&=~SET_BIT5;P0M2|=SET_BIT5
#define P06_PushPull_Mode			P0M1&=~SET_BIT6;P0M2|=SET_BIT6
#define P07_PushPull_Mode			P0M1&=~SET_BIT7;P0M2|=SET_BIT7
#define P10_PushPull_Mode			P1M1&=~SET_BIT0;P1M2|=SET_BIT0
#define P11_PushPull_Mode			P1M1&=~SET_BIT1;P1M2|=SET_BIT1
#define P12_PushPull_Mode			P1M1&=~SET_BIT2;P1M2|=SET_BIT2
#define P13_PushPull_Mode			P1M1&=~SET_BIT3;P1M2|=SET_BIT3
#define P14_PushPull_Mode			P1M1&=~SET_BIT4;P1M2|=SET_BIT4
#define P15_PushPull_Mode			P1M1&=~SET_BIT5;P1M2|=SET_BIT5
#define P16_PushPull_Mode			P1M1&=~SET_BIT6;P1M2|=SET_BIT6
#define P17_PushPull_Mode			P1M1&=~SET_BIT7;P1M2|=SET_BIT7
#define P30_PushPull_Mode			P3M1&=~SET_BIT0;P3M2|=SET_BIT0
#define GPIO1_PushPull_Mode		P1M1&=~SET_BIT0;P1M2|=SET_BIT0
//------------------- Define Port as Input Only mode -------------------
#define P00_Input_Mode				P0M1|=SET_BIT0;P0M2&=~SET_BIT0
#define P01_Input_Mode				P0M1|=SET_BIT1;P0M2&=~SET_BIT1
#define P02_Input_Mode				P0M1|=SET_BIT2;P0M2&=~SET_BIT2
#define P03_Input_Mode				P0M1|=SET_BIT3;P0M2&=~SET_BIT3
#define P04_Input_Mode				P0M1|=SET_BIT4;P0M2&=~SET_BIT4
#define P05_Input_Mode				P0M1|=SET_BIT5;P0M2&=~SET_BIT5
#define P06_Input_Mode				P0M1|=SET_BIT6;P0M2&=~SET_BIT6
#define P07_Input_Mode				P0M1|=SET_BIT7;P0M2&=~SET_BIT7
#define P10_Input_Mode				P1M1|=SET_BIT0;P1M2&=~SET_BIT0
#define P11_Input_Mode				P1M1|=SET_BIT1;P1M2&=~SET_BIT1
#define P12_Input_Mode				P1M1|=SET_BIT2;P1M2&=~SET_BIT2
#define P13_Input_Mode				P1M1|=SET_BIT3;P1M2&=~SET_BIT3
#define P14_Input_Mode				P1M1|=SET_BIT4;P1M2&=~SET_BIT4
#define P15_Input_Mode				P1M1|=SET_BIT5;P1M2&=~SET_BIT5
#define P16_Input_Mode				P1M1|=SET_BIT6;P1M2&=~SET_BIT6
#define P17_Input_Mode				P1M1|=SET_BIT7;P1M2&=~SET_BIT7
#define P30_Input_Mode				P3M1|=SET_BIT0;P3M2&=~SET_BIT0
//-------------------Define Port as Open Drain mode -------------------
#define P00_OpenDrain_Mode		P0M1|=SET_BIT0;P0M2|=SET_BIT0
#define P01_OpenDrain_Mode		P0M1|=SET_BIT1;P0M2|=SET_BIT1
#define P02_OpenDrain_Mode		P0M1|=SET_BIT2;P0M2|=SET_BIT2
#define P03_OpenDrain_Mode		P0M1|=SET_BIT3;P0M2|=SET_BIT3
#define P04_OpenDrain_Mode		P0M1|=SET_BIT4;P0M2|=SET_BIT4
#define P05_OpenDrain_Mode		P0M1|=SET_BIT5;P0M2|=SET_BIT5
#define P06_OpenDrain_Mode		P0M1|=SET_BIT6;P0M2|=SET_BIT6
#define P07_OpenDrain_Mode		P0M1|=SET_BIT7;P0M2|=SET_BIT7
#define P10_OpenDrain_Mode		P1M1|=SET_BIT0;P1M2|=SET_BIT0
#define P11_OpenDrain_Mode		P1M1|=SET_BIT1;P1M2|=SET_BIT1
#define P12_OpenDrain_Mode		P1M1|=SET_BIT2;P1M2|=SET_BIT2
#define P13_OpenDrain_Mode		P1M1|=SET_BIT3;P1M2|=SET_BIT3
#define P14_OpenDrain_Mode		P1M1|=SET_BIT4;P1M2|=SET_BIT4
#define P15_OpenDrain_Mode		P1M1|=SET_BIT5;P1M2|=SET_BIT5
#define P16_OpenDrain_Mode		P1M1|=SET_BIT6;P1M2|=SET_BIT6
#define P17_OpenDrain_Mode		P1M1|=SET_BIT7;P1M2|=SET_BIT7
#define P30_OpenDrain_Mode		P3M1|=SET_BIT0;P3M2|=SET_BIT0
//--------- Define all port as quasi mode ---------
#define Set_All_GPIO_Quasi_Mode			P0M1=0;P0M1=0;P1M1=0;P1M2=0;P3M1=0;P3M2=0

#define 		set_GPIO1		P12=1
#define 		clr_GPIO1		P12=0

/****************************************************************************
   Enable INT port 0~3
***************************************************************************/
#define 	Enable_INT_Port0					PICON &= 0xFB;
#define		Enable_INT_Port1					PICON |= 0x01;
#define		Enable_INT_Port2					PICON |= 0x02;
#define		Enable_INT_Port3					PICON |= 0x03;
/*****************************************************************************
 Enable each bit low level trig mode
*****************************************************************************/
#define		Enable_BIT7_LowLevel_Trig			PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define		Enable_BIT6_LowLevel_Trig			PICON&=0x7F;PINEN|=0x40;PIPEN&=0xBF
#define		Enable_BIT5_LowLevel_Trig			PICON&=0xBF;PINEN|=0x20;PIPEN&=0xDF
#define		Enable_BIT4_LowLevel_Trig			PICON&=0xBF;PINEN|=0x10;PIPEN&=0xEF
#define		Enable_BIT3_LowLevel_Trig			PICON&=0xDF;PINEN|=0x08;PIPEN&=0xF7
#define		Enable_BIT2_LowLevel_Trig			PICON&=0xEF;PINEN|=0x04;PIPEN&=0xFB
#define		Enable_BIT1_LowLevel_Trig			PICON&=0xF7;PINEN|=0x02;PIPEN&=0xFD
#define		Enable_BIT0_LowLevel_Trig			PICON&=0xFD;PINEN|=0x01;PIPEN&=0xFE
/*****************************************************************************
 Enable each bit high level trig mode
*****************************************************************************/
#define		Enable_BIT7_HighLevel_Trig			PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define		Enable_BIT6_HighLevel_Trig			PICON&=0x7F;PINEN&=0xBF;PIPEN|=0x40
#define		Enable_BIT5_HighLevel_Trig			PICON&=0xBF;PINEN&=0xDF;PIPEN|=0x20
#define		Enable_BIT4_HighLevel_Trig			PICON&=0xBF;PINEN&=0xEF;PIPEN|=0x10
#define		Enable_BIT3_HighLevel_Trig			PICON&=0xDF;PINEN&=0xF7;PIPEN|=0x08
#define		Enable_BIT2_HighLevel_Trig			PICON&=0xEF;PINEN&=0xFB;PIPEN|=0x04
#define		Enable_BIT1_HighLevel_Trig			PICON&=0xF7;PINEN&=0xFD;PIPEN|=0x02
#define		Enable_BIT0_HighLevel_Trig			PICON&=0xFD;PINEN&=0xFE;PIPEN|=0x01
/*****************************************************************************
 Enable each bit falling edge trig mode
*****************************************************************************/
#define		Enable_BIT7_FallEdge_Trig			PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define		Enable_BIT6_FallEdge_Trig			PICON|=0x80;PINEN|=0x40;PIPEN&=0xBF
#define		Enable_BIT5_FallEdge_Trig			PICON|=0x40;PINEN|=0x20;PIPEN&=0xDF
#define		Enable_BIT4_FallEdge_Trig			PICON|=0x40;PINEN|=0x10;PIPEN&=0xEF
#define		Enable_BIT3_FallEdge_Trig			PICON|=0x20;PINEN|=0x08;PIPEN&=0xF7
#define		Enable_BIT2_FallEdge_Trig			PICON|=0x10;PINEN|=0x04;PIPEN&=0xFB
#define		Enable_BIT1_FallEdge_Trig			PICON|=0x08;PINEN|=0x02;PIPEN&=0xFD
#define		Enable_BIT0_FallEdge_Trig			PICON|=0x04;PINEN|=0x01;PIPEN&=0xFE
/*****************************************************************************
 Enable each bit rasing edge trig mode
*****************************************************************************/
#define		Enable_BIT7_RasingEdge_Trig			PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define		Enable_BIT6_RasingEdge_Trig			PICON|=0x80;PINEN&=0xBF;PIPEN|=0x40
#define		Enable_BIT5_RasingEdge_Trig			PICON|=0x40;PINEN&=0xDF;PIPEN|=0x20
#define		Enable_BIT4_RasingEdge_Trig			PICON|=0x40;PINEN&=0xEF;PIPEN|=0x10
#define		Enable_BIT3_RasingEdge_Trig			PICON|=0x20;PINEN&=0xF7;PIPEN|=0x08
#define		Enable_BIT2_RasingEdge_Trig			PICON|=0x10;PINEN&=0xFB;PIPEN|=0x04
#define		Enable_BIT1_RasingEdge_Trig			PICON|=0x08;PINEN|=0xFD;PIPEN&=0x02
#define		Enable_BIT0_RasingEdge_Trig			PICON|=0x04;PINEN|=0xFE;PIPEN&=0x01


/*****************************************************************************************
* For TIMER VALUE setting is base on " option -> C51 -> Preprocesser Symbols -> Define "
*****************************************************************************************/
#ifdef FOSC_110592		// if Fsys = 11.0592MHz 
    #define TIMER_DIV12_VALUE_10us			65536-9			//9*12/11.0592 = 10 uS,  				// Timer divider = 12 for TM0/TM1
    #define TIMER_DIV12_VALUE_1ms				65536-923		//923*12/11.0592 = 1 mS					// Timer divider = 12
		#define	TIMER_DIV12_VALUE_10ms			65536-9216	//18432*12/22118400 = 10 ms			// Timer divider = 12
    #define TIMER_DIV4_VALUE_10us				65536-28		//28*4/11.0592 = 10 uS					// Timer divider = 4	for TM2/TM3
    #define TIMER_DIV4_VALUE_1ms				65536-2765	//2765*4/11.0592 = 1 mS					// Timer divider = 4
		#define TIMER_DIV4_VALUE_100us			65536-277		//553*4/22118400 = 100 us				// Timer divider = 4
		#define TIMER_DIV4_VALUE_200us			65536-553		//1106*4/22118400 = 200 us			// Timer divider = 4
		#define TIMER_DIV4_VALUE_500us			65536-1383	//2765*4/22118400 = 500 us			// Timer divider = 4		
		#define TIMER_DIV16_VALUE_10ms			65536-6912	//1500*16/22118400 = 10 ms			// Timer divider = 16
		#define TIMER_DIV64_VALUE_30ms			65536-5184	//10368*64/22118400 = 30 ms			// Timer divider = 64
		#define	TIMER_DIV128_VALUE_100ms		65536-8640	//17280*128/22118400 = 100 ms		// Timer divider = 128
		#define	TIMER_DIV128_VALUE_200ms		65536-17280	//34560*128/22118400 = 200 ms		// Timer divider = 128
		#define TIMER_DIV256_VALUE_500ms		65536-21600	//43200*256/22118400 = 500 ms 	// Timer divider = 256
		#define TIMER_DIV512_VALUE_1s				65536-21600	//43200*512/22118400 = 1 s			// Timer divider = 512
#endif
#ifdef FOSC_160000		// if Fsys = 16MHz 
		#define TIMER_DIV12_VALUE_10us			65536-13		//13*12/16000000 = 10 uS,  			// Timer divider = 12 for TM0/TM1
		#define TIMER_DIV12_VALUE_100us			65536-130		//130*12/16000000 = 10 uS,  			// Timer divider = 12 for TM0/TM1
		#define TIMER_DIV12_VALUE_1ms				65536-1334	//1334*12/16000000 = 1 mS, 			// Timer divider = 12 
		#define TIMER_DIV12_VALUE_10ms			65536-13334	//13334*12/16000000 = 10 mS 			// Timer divider = 12 
		#define TIMER_DIV4_VALUE_10us				65536-40		//40*4/16000000 = 10 uS,    		// Timer divider = 4	for TM2/TM3
		#define TIMER_DIV4_VALUE_100us			65536-400		//400*4/16000000 = 100 us				// Timer divider = 4
		#define TIMER_DIV4_VALUE_200us			65536-800		//800*4/16000000 = 200 us				// Timer divider = 4
		#define TIMER_DIV4_VALUE_500us			65536-2000	//2000*4/16000000 = 500 us			// Timer divider = 4
    #define TIMER_DIV4_VALUE_1ms				65536-4000	//4000*4/16000000 = 1 mS,   		// Timer divider = 4
		#define TIMER_DIV16_VALUE_10ms			65536-10000	//10000*16/16000000 = 10 ms			// Timer	divider = 16
		#define TIMER_DIV64_VALUE_30ms			65536-7500	//7500*64/16000000 = 30 ms			// Timer divider = 64
		#define	TIMER_DIV128_VALUE_100ms		65536-12500	//12500*128/16000000 = 100 ms		// Timer divider = 128
		#define	TIMER_DIV128_VALUE_200ms		65536-25000	//25000*128/16000000 = 200 ms		// Timer divider = 128
		#define TIMER_DIV256_VALUE_500ms		65536-31250	//31250*256/16000000 = 500 ms 	// Timer divider = 256
		#define	TIMER_DIV512_VALUE_1s				65536-31250	//31250*512/16000000 = 1 s.  		// Timer Divider = 512
#endif
#ifdef FOSC_184320		// if Fsys = 18.432MHz 
    #define TIMER_DIV12_VALUE_10us			65536-15    //15*12/18.432 = 10 uS,  Timer Clock = Fsys/12
    #define TIMER_DIV12_VALUE_1ms				65536-1536  //1536*12/18.432 = 1 mS, Timer Clock = Fsys/12
    #define TIMER_DIV4_VALUE_10us				65536-46    //46*4/18.432 = 10 uS,   Timer Clock = Fsys/4
    #define TIMER_DIV4_VALUE_1ms				65536-4608  //4608*4/18.432 = 1 mS,  Timer Clock = Fsys/4
#endif
#ifdef FOSC_200000		// if Fsys = 20 MHz
    #define TIMER_DIV12_VALUE_10us			65536-17 	 //17*12/20000000 = 10 uS,  Timer Clock = Fsys/12
    #define TIMER_DIV12_VALUE_1ms				65536-1667  	//1667*12/20000000 = 1 mS, Timer Clock = Fsys/12
    #define TIMER_DIV4_VALUE_10us				65536-50    	//50*4/20000000 = 10 uS,    Timer Clock = Fsys/4
    #define TIMER_DIV4_VALUE_1ms				65536-5000  	//5000*4/20000000 = 1 mS,   Timer Clock = Fsys/4
#endif
#ifdef FOSC_221184		// if Fsys = 22.1184 MHz 
		#define TIMER_DIV12_VALUE_10us			65536-18   			//18*12/22118400 = 10 uS,  			// Timer divider = 12
		#define TIMER_DIV12_VALUE_1ms				65536-1843  		//1843*12/22118400 = 1 mS, 			// Timer divider = 12
		#define	TIMER_DIV12_VALUE_10ms			65536-18432			//18432*12/22118400 = 10 ms			// Timer divider = 12
		#define TIMER_DIV4_VALUE_10us				65536-56				//9*4/22118400 = 10 uS,    			// Timer divider = 4
		#define TIMER_DIV4_VALUE_1ms				65536-5530			//923*4/22118400 = 1 mS,   			// Timer divider = 4
		#define TIMER_DIV4_VALUE_100us			65536-553				//553*4/22118400 = 100 us				// Timer divider = 4
		#define TIMER_DIV4_VALUE_200us			65536-1106			//1106*4/22118400 = 200 us			// Timer divider = 4
		#define TIMER_DIV4_VALUE_500us			65536-2765			//2765*4/22118400 = 500 us			// Timer divider = 4		
		#define TIMER_DIV16_VALUE_10ms			65536-13824			//1500*16/22118400 = 10 ms			// Timer divider = 16
		#define TIMER_DIV64_VALUE_30ms			65536-10368			//10368*64/22118400 = 30 ms			// Timer divider = 64
		#define	TIMER_DIV128_VALUE_100ms		65536-17280			//17280*128/22118400 = 100 ms		// Timer divider = 128
		#define	TIMER_DIV128_VALUE_200ms		65536-34560			//34560*128/22118400 = 200 ms		// Timer divider = 128
		#define TIMER_DIV256_VALUE_500ms		65536-43200			//43200*256/22118400 = 500 ms 	// Timer divider = 256
		#define TIMER_DIV512_VALUE_1s				65536-43200			//43200*512/22118400 = 1 s			// Timer divider = 512
#endif
#ifdef FOSC_240000		// if Fsys = 20 MHz
		#define TIMER_DIV12_VALUE_10us			65536-20				//20*12/24000000 = 10 uS,  			// Timer divider = 12
    #define TIMER_DIV12_VALUE_1ms				65536-2000			//2000*12/24000000 = 1 mS, 			// Timer divider = 12
		#define TIMER_DIV12_VALUE_10ms			65536-20000			//2000*12/24000000 = 10 mS 			// Timer divider = 12
		#define TIMER_DIV4_VALUE_10us				65536-60				//60*4/24000000 = 10 uS,    		// Timer divider = 4
		#define TIMER_DIV4_VALUE_100us			65536-600				//600*4/24000000 = 100 us				// Timer divider = 4
		#define TIMER_DIV4_VALUE_200us			65536-1200			//1200*4/24000000 = 200 us			// Timer divider = 4
		#define TIMER_DIV4_VALUE_500us			65536-3000			//3000*4/24000000 = 500 us			// Timer divider = 4
    #define TIMER_DIV4_VALUE_1ms				65536-6000			//6000*4/24000000 = 1 mS,   		// Timer divider = 4
		#define TIMER_DIV16_VALUE_10ms			65536-15000			//15000*16/24000000 = 10 ms			// Timer	divider = 16
		#define TIMER_DIV64_VALUE_30ms			65536-11250			//11250*64/24000000 = 30 ms			// Timer divider = 64
		#define	TIMER_DIV128_VALUE_100ms		65536-18750			//37500*128/24000000 = 200 ms		// Timer divider = 128
		#define	TIMER_DIV128_VALUE_200ms		65536-37500			//37500*128/24000000 = 200 ms		// Timer divider = 128
		#define TIMER_DIV256_VALUE_500ms		65536-46875			//46875*256/24000000 = 500 ms 	// Timer divider = 256
		#define	TIMER_DIV512_VALUE_1s				65536-46875			//46875*512/24000000 = 1 s.  		// Timer Divider = 512
#endif
//-------------------- Timer0 function define --------------------
#define		TIMER1_MODE0_ENABLE		TMOD&=0x0F
#define		TIMER1_MODE1_ENABLE		TMOD&=0x0F;TMOD|=0x10
#define		TIMER1_MODE2_ENABLE		TMOD&=0x0F;TMOD|=0x20
#define		TIMER1_MODE3_ENABLE		TMOD&=0x0F;TMOD|=0x3F
//-------------------- Timer1 function define --------------------
#define		TIMER0_MODE0_ENABLE		TMOD&=0xF0
#define		TIMER0_MODE1_ENABLE		TMOD&=0xF0;TMOD|=0x01
#define		TIMER0_MODE2_ENABLE		TMOD&=0xF0;TMOD|=0x02
#define		TIMER0_MODE3_ENABLE		TMOD&=0xF0;TMOD|=0xF3
//-------------------- Timer2 function define --------------------
#define 	TIMER2_DIV_4			T2MOD|=0x10;T2MOD&=0x9F
#define 	TIMER2_DIV_16			T2MOD|=0x20;T2MOD&=0xAF
#define 	TIMER2_DIV_32			T2MOD|=0x30;T2MOD&=0xBF
#define 	TIMER2_DIV_64			T2MOD|=0x40;T2MOD&=0xCF
#define		TIMER2_DIV_128		T2MOD|=0x50;T2MOD&=0xDF
#define 	TIMER2_DIV_256		T2MOD|=0x60;T2MOD&=0xEF
#define 	TIMER2_DIV_512		T2MOD|=0x70
#define 	TIMER2_Auto_Reload_Delay_Mode				T2CON&=~SET_BIT0;T2MOD|=SET_BIT7;T2MOD|=SET_BIT3
#define 	TIMER2_Auto_Reload_Capture_Mode			T2CON&=~SET_BIT0;T2MOD|=SET_BIT7
#define		TIMER2_Compare_Capture_Mode					T2CON|=SET_BIT0;T2MOD&=~SET_BIT7;T2MOD|=SET_BIT2
//-------------------- Timer2 Capture define --------------------
//--- Falling Edge -----
#define IC0_P12_CAP0_FallingEdge_Capture		CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xCF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0
#define	IC1_P11_CAP0_FallingEdge_Capture		CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xCF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x01;
#define	IC2_P10_CAP0_FallingEdge_Capture		CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xCF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x02;
#define	IC3_P00_CAP0_FallingEdge_Capture		CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xCF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x03;
#define	IC3_P04_CAP0_FallingEdge_Capture		CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xCF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x04;
#define	IC4_P01_CAP0_FallingEdge_Capture		CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xCF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x05;
#define	IC5_P03_CAP0_FallingEdge_Capture		CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xCF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x06;
#define	IC6_P05_CAP0_FallingEdge_Capture		CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xCF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x07;
#define	IC7_P15_CAP0_FallingEdge_Capture		CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xCF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x08;

#define IC0_P12_CAP1_FallingEdge_Capture		CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF3;CAPCON2|=SET_BIT5;CAPCON3&=0x0F
#define	IC1_P11_CAP1_FallingEdge_Capture		CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF3;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x10;
#define	IC2_P10_CAP1_FallingEdge_Capture		CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF3;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x20;
#define	IC3_P00_CAP1_FallingEdge_Capture		CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF3;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x30;
#define	IC3_P04_CAP1_FallingEdge_Capture		CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF3;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x40;
#define	IC4_P01_CAP1_FallingEdge_Capture		CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF3;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x50;
#define	IC5_P03_CAP1_FallingEdge_Capture		CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF3;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x60;
#define	IC6_P05_CAP1_FallingEdge_Capture		CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF3;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x70;
#define	IC7_P15_CAP1_FallingEdge_Capture		CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF3;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x80;

#define IC0_P12_CAP2_FallingEdge_Capture		CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFC;CAPCON2|=SET_BIT6;CAPCON4&=0xF0
#define	IC1_P11_CAP2_FallingEdge_Capture		CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFC;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x10;
#define	IC2_P10_CAP2_FallingEdge_Capture		CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFC;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x20;
#define	IC3_P00_CAP2_FallingEdge_Capture		CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFC;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x30;
#define	IC3_P04_CAP2_FallingEdge_Capture		CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFC;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x40;
#define	IC4_P01_CAP2_FallingEdge_Capture		CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFC;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x50;
#define	IC5_P03_CAP2_FallingEdge_Capture		CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFC;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x60;
#define	IC6_P05_CAP2_FallingEdge_Capture		CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFC;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x70;
#define	IC7_P15_CAP2_FallingEdge_Capture		CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFC;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x80;

//----- Rising edge ----
#define IC0_P12_CAP0_RisingEdge_Capture			CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xDF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0
#define	IC1_P11_CAP0_RisingEdge_Capture			CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xDF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x01;
#define	IC2_P10_CAP0_RisingEdge_Capture			CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xDF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x02;
#define	IC3_P00_CAP0_RisingEdge_Capture			CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xDF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x03;
#define	IC3_P04_CAP0_RisingEdge_Capture			CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xDF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x04;
#define	IC4_P01_CAP0_RisingEdge_Capture			CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xDF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x05;
#define	IC5_P03_CAP0_RisingEdge_Capture			CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xDF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x06;
#define	IC6_P05_CAP0_RisingEdge_Capture			CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xDF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x07;
#define	IC7_P15_CAP0_RisingEdge_Capture			CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xDF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x08;

#define IC0_P12_CAP1_RisingEdge_Capture			CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF7;CAPCON2|=SET_BIT5;CAPCON3&=0x0F
#define	IC1_P11_CAP1_RisingEdge_Capture			CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF7;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x10;
#define	IC2_P10_CAP1_RisingEdge_Capture			CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF7;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x20;
#define	IC3_P00_CAP1_RisingEdge_Capture			CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF7;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x30;
#define	IC3_P04_CAP1_RisingEdge_Capture			CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF7;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x40;
#define	IC4_P01_CAP1_RisingEdge_Capture			CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF7;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x50;
#define	IC5_P03_CAP1_RisingEdge_Capture			CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF7;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x60;
#define	IC6_P05_CAP1_RisingEdge_Capture			CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF7;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x70;
#define	IC7_P15_CAP1_RisingEdge_Capture			CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xF7;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x80;

#define IC0_P12_CAP3_RisingEdge_Capture			CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFD;CAPCON2|=SET_BIT6;CAPCON4&=0xF0
#define	IC1_P11_CAP3_RisingEdge_Capture			CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFD;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x01;
#define	IC2_P10_CAP3_RisingEdge_Capture			CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFD;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x02;
#define	IC3_P00_CAP3_RisingEdge_Capture			CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFD;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x03;
#define	IC3_P04_CAP3_RisingEdge_Capture			CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFD;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x04;
#define	IC4_P01_CAP3_RisingEdge_Capture			CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFD;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x05;
#define	IC5_P03_CAP3_RisingEdge_Capture			CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFD;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x06;
#define	IC6_P05_CAP3_RisingEdge_Capture			CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFD;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x07;
#define	IC7_P15_CAP3_RisingEdge_Capture			CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFD;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x08;

//-----BOTH  edge ----
#define IC0_P12_CAP0_BothEdge_Capture				CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xBF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0
#define	IC1_P11_CAP0_BothEdge_Capture				CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xBF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x01;
#define	IC2_P10_CAP0_BothEdge_Capture				CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xBF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x02;
#define	IC3_P00_CAP0_BothEdge_Capture				CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xBF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x03;
#define	IC3_P04_CAP0_BothEdge_Capture				CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xBF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x04;
#define	IC4_P01_CAP0_BothEdge_Capture				CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xBF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x05;
#define	IC5_P03_CAP0_BothEdge_Capture				CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xBF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x06;
#define	IC6_P05_CAP0_BothEdge_Capture				CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xBF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x07;
#define	IC7_P15_CAP0_BothEdge_Capture				CAPCON0|=SET_BIT4;CAPCON1|=0x30;CAPCON1&=0xBF;CAPCON2|=SET_BIT4;CAPCON3&=0xF0;CAPCON3|=0x08;

#define IC0_P12_CAP1_BothEdge_Capture				CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xEF;CAPCON2|=SET_BIT5;CAPCON3&=0x0F
#define	IC1_P11_CAP1_BothEdge_Capture				CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xEF;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x10;
#define	IC2_P10_CAP1_BothEdge_Capture				CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xEF;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x20;
#define	IC3_P00_CAP1_BothEdge_Capture				CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xEF;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x30;
#define	IC3_P04_CAP1_BothEdge_Capture				CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xEF;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x40;
#define	IC4_P01_CAP1_BothEdge_Capture				CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xEF;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x50;
#define	IC5_P03_CAP1_BothEdge_Capture				CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xEF;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x60;
#define	IC6_P05_CAP1_BothEdge_Capture				CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xEF;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x70;
#define	IC7_P15_CAP1_BothEdge_Capture				CAPCON0|=SET_BIT5;CAPCON1|=0x0C;CAPCON1&=0xEF;CAPCON2|=SET_BIT5;CAPCON3&=0x0F;CAPCON3|=0x80;

#define IC0_P12_CAP3_BothEdge_Capture				CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFB;CAPCON2|=SET_BIT6;CAPCON4&=0xF0
#define	IC1_P11_CAP3_BothEdge_Capture				CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFB;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x01;
#define	IC2_P10_CAP3_BothEdge_Capture				CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFB;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x02;
#define	IC3_P00_CAP3_BothEdge_Capture				CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFB;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x03;
#define	IC3_P04_CAP3_BothEdge_Capture				CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFB;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x04;
#define	IC4_P01_CAP3_BothEdge_Capture				CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFB;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x05;
#define	IC5_P03_CAP3_BothEdge_Capture				CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFB;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x06;
#define	IC6_P05_CAP3_BothEdge_Capture				CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFB;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x07;
#define	IC7_P15_CAP3_BothEdge_Capture				CAPCON0|=SET_BIT6;CAPCON1|=0x03;CAPCON1&=0xFB;CAPCON2|=SET_BIT6;CAPCON4&=0xF0;CAPCON4|=0x08;

#define TIMER2_IC2_DISABLE									CAPCON0&=~SET_BIT6			 
#define TIMER2_IC1_DISABLE									CAPCON0&=~SET_BIT5			
#define TIMER2_IC0_DISABLE									CAPCON0&=~SET_BIT4	

/*****************************************************************************************
* For PWM setting 
*****************************************************************************************/
//--------- PMW clock source select define ---------------------
#define		PWM_CLOCK_FSYS					CKCON&=0xBF
#define		PWM_CLOCK_TIMER1				CKCON|=0x40
//--------- PWM clock devide define ----------------------------
#define		PWM_CLOCK_DIV_2					PWMCON1|=0x01;PWMCON1&=0xF9
#define		PWM_CLOCK_DIV_4					PWMCON1|=0x02;PWMCON1&=0xFA
#define		PWM_CLOCK_DIV_8					PWMCON1|=0x03;PWMCON1&=0xFB
#define		PWM_CLOCK_DIV_16				PWMCON1|=0x04;PWMCON1&=0xFC
#define		PWM_CLOCK_DIV_32				PWMCON1|=0x05;PWMCON1&=0xFD
#define		PWM_CLOCK_DIV_64				PWMCON1|=0x06;PWMCON1&=0xFE
#define		PWM_CLOCK_DIV_128				PWMCON1|=0x07
//--------- PWM I/O select define ------------------------------
#define		PWM5_P15_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x20;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.5 as PWM5 output enable
#define		PWM5_P03_OUTPUT_ENABLE		PIOCON0|=0x20																										//P0.3 as PWM5
#define		PWM4_P01_OUTPUT_ENABLE		PIOCON0|=0x10																										//P0.1 as PWM4 output enable
#define		PWM3_P04_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x08;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P0.4 as PWM3 output enable
#define		PWM3_P00_OUTPUT_ENABLE		PIOCON0|=0x08																										//P0.0 as PWM3 
#define		PWM2_P05_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x04;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.0 as PWM2 output enable
#define		PWM2_P10_OUTPUT_ENABLE		PIOCON0|=0x04																										//P1.0 as PWM2
#define		PWM1_P14_OUTPUT_ENABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1|=0x02;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.4 as PWM1 output enable
#define		PWM1_P11_OUTPUT_ENABLE		PIOCON0|=0x02																										//P1.1 as PWM1 
#define		PWM0_P12_OUTPUT_ENABLE		PIOCON0|=0x01																										//P1.2 as PWM0 output enable
#define 	ALL_PWM_OUTPUT_ENABLE			PIOCON0=0xFF;PIOCON1=0xFF
#define		PWM5_P15_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xDF;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.5 as PWM5 output disable
#define		PWM5_P03_OUTPUT_DISABLE		PIOCON0&=0xDF																										//P0.3 as PWM5
#define		PWM4_P01_OUTPUT_DISABLE		PIOCON0&=0xEF																										//P0.1 as PWM4 output disable
#define		PWM3_P04_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xF7;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P0.4 as PWM3 output disable
#define		PWM3_P00_OUTPUT_DISABLE		PIOCON0&=0xF7																										//P0.0 as PWM3 
#define		PWM2_P05_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xFB;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.0 as PWM2 output disable
#define		PWM2_P10_OUTPUT_DISABLE		PIOCON0&=0xFB																										//P1.0 as PWM2
#define		PWM1_P14_OUTPUT_DISABLE		BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;PIOCON1&=0xFD;TA=0xAA;TA=0x55;SFRS&=0xFE;EA=BIT_TMP				//P1.4 as PWM1 output disable
#define		PWM1_P11_OUTPUT_DISABLE		PIOCON0&=0xFD																										//P1.1 as PWM1 
#define		PWM0_P12_OUTPUT_DISABLE		PIOCON0&=0xFE																										//P1.2 as PWM0 output disable
#define 	ALL_PWM_OUTPUT_DISABLE		PIOCON0=0x00;PIOCON1=0x00
//--------- PWM I/O Polarity Control ---------------------------
#define		PWM5_OUTPUT_INVERSE			PNP|=0x20				
#define		PWM4_OUTPUT_INVERSE			PNP|=0x10				
#define		PWM3_OUTPUT_INVERSE			PNP|=0x08				
#define		PWM2_OUTPUT_INVERSE			PNP|=0x04				
#define		PWM1_OUTPUT_INVERSE			PNP|=0x02				
#define		PWM0_OUTPUT_INVERSE			PNP|=0x01				
#define		PWM_OUTPUT_ALL_INVERSE	PNP=0xFF
#define		PWM5_OUTPUT_NORMAL			PNP&=0xDF				
#define		PWM4_OUTPUT_NORMAL			PNP&=0xEF				
#define		PWM3_OUTPUT_NORMAL			PNP&=0xF7				
#define		PWM2_OUTPUT_NORMAL			PNP&=0xFB				
#define		PWM1_OUTPUT_NORMAL			PNP&=0xFD				
#define		PWM0_OUTPUT_NORMAL			PNP&=0xFE				
#define		PWM_OUTPUT_ALL_NORMAL		PNP=0x00
//--------- PWM type define ------------------------------------
#define		PWM_EDGE_TYPE						PWMCON1&=~SET_BIT4
#define		PWM_CENTER_TYPE					PWMCON1|=SET_BIT4
//--------- PWM mode define ------------------------------------
#define		PWM_IMDEPENDENT_MODE		PWMCON1&=0x3F//独立输出模式
#define		PWM_COMPLEMENTARY_MODE	PWMCON1|=0x40;PWMCON1&=0x7F//互补模式
#define		PWM_SYNCHRONIZED_MODE		PWMCON1|=0x80;PWMCON1&=0xBF//同步模式
#define 	PWM_GP_MODE_ENABLE			PWMCON1|=0x20//群组模式使能
#define		PWM_GP_MODE_DISABLE			PWMCON1&=0xDF//群组模式失能
//--------- PMW interrupt setting ------------------------------
#define		PWM_FALLING_INT					BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xCF;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_RISING_INT					BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC|=0x10;PWMCON0&=0xDF;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_CENTRAL_POINT_INT		BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC|=0x20;PWMCON0&=0xEF;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_PERIOD_END_INT			BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC|=0x30;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
//--------- PWM interrupt pin select ---------------------------
#define		PWM_INT_PWM0						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_INT_PWM1						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;PWMINTC|=0x01;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_INT_PWM2						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;PWMINTC|=0x02;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_INT_PWM3						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;PWMINTC|=0x03;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_INT_PWM4						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;PWMINTC|=0x04;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
#define		PWM_INT_PWM5						BIT_TMP=EA;TA=0xAA;TA=0x55;SFRS=0x01;PWMINTC&=0xF8;PWMINTC|=0x05;TA=0xAA;TA=0x55;SFRS=0x00;EA=BIT_TMP
//--------- PWM Dead time setting ------------------------------
#define 	PWM45_DEADTIME_ENABLE			BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x04;EA=BIT_TMP
#define 	PWM34_DEADTIME_ENABLE			BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x02;EA=BIT_TMP
#define 	PWM01_DEADTIME_ENABLE			BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x01;EA=BIT_TMP

/*****************************************************************************************
* For ADC INIT setting 
*****************************************************************************************/
#define Enable_ADC_AIN0			ADCCON0&=0xF0;P17_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT0;ADCCON1|=SET_BIT0									//P17
#define Enable_ADC_AIN1			ADCCON0&=0xF0;ADCCON0|=0x01;P30_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT1;ADCCON1|=SET_BIT0		//P30
#define Enable_ADC_AIN2			ADCCON0&=0xF0;ADCCON0|=0x02;P07_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT2;ADCCON1|=SET_BIT0		//P07
#define Enable_ADC_AIN3			ADCCON0&=0xF0;ADCCON0|=0x03;P06_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT3;ADCCON1|=SET_BIT0		//P06
#define Enable_ADC_AIN4			ADCCON0&=0xF0;ADCCON0|=0x04;P05_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT4;ADCCON1|=SET_BIT0		//P05
#define Enable_ADC_AIN5			ADCCON0&=0xF0;ADCCON0|=0x05;P04_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT5;ADCCON1|=SET_BIT0		//P04
#define Enable_ADC_AIN6			ADCCON0&=0xF0;ADCCON0|=0x06;P03_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT6;ADCCON1|=SET_BIT0		//P03
#define Enable_ADC_AIN7			ADCCON0&=0xF0;ADCCON0|=0x07;P11_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT7;ADCCON1|=SET_BIT0		//P11
#define Enable_ADC_BandGap	ADCCON0|=SET_BIT3;ADCCON0&=0xF8;ADCCON1|=SET_BIT0																							//Band-gap 1.22V

#define PWM0_FALLINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM2_FALLINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0|=SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM4_FALLINGEDGE_TRIG_ADC		ADCCON0|=SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM0_RISINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
#define PWM2_RISINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0|=SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
#define PWM4_RISINGEDGE_TRIG_ADC		ADCCON0|=SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
#define PWM0_CENTRAL_TRIG_ADC				ADCCON0&=~SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM2_CENTRAL_TRIG_ADC				ADCCON0&=~SET_BIT5;ADCCON0|=SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM4_CENTRAL_TRIG_ADC				ADCCON0|=SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
#define PWM0_END_TRIG_ADC						ADCCON0&=~SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
#define PWM2_END_TRIG_ADC						ADCCON0&=~SET_BIT5;ADCCON0|=SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
#define PWM4_END_TRIG_ADC						ADCCON0|=SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1|=SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1

#define P04_FALLINGEDGE_TRIG_ADC		ADCCON0|=0x30;ADCCON1&=0xF3;ADCCON1|=SET_BIT1;ADCCON1&=~SET_BIT6
#define P13_FALLINGEDGE_TRIG_ADC		ADCCON0|=0x30;ADCCON1&=0xF3;ADCCON1|=SET_BIT1;ADCCON1|=SET_BIT6
#define P04_RISINGEDGE_TRIG_ADC			ADCCON0|=0x30;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1;ADCCON1&=~SET_BIT6
#define P13_RISINGEDGE_TRIG_ADC			ADCCON0|=0x30;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1;ADCCON1|=SET_BIT6





                            


                            
               












