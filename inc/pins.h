// Define microcontroller type (assuming PIC24 family based on the configuration)

// I2C configuration (using I2C1 - no S_I2C2 defined)

// LEDs
#define TRIS_Led1	                _TRISA0
#define PORT_Led1 	                _A0
#define LAT_Led1 	                _LATA0
#define ODC_Led1	                _ODA0
#define PIN_Led1 	                _RA0
#define CN_Led1		                2
#define ADC_value_Led1              Buffer_entradas[0] 
#define HAL_SetAnalog_Led1()        {_PCFG0=0;\
                                        adc_addAnalogChannel(0);}


#define TRIS_Led2	_TRISA3
#define LAT_Led2 	_LATA3
#define ODC_Led2	_ODA3
#define PIN_Led2 	_RA3
#define CN_Led2		29
#define TRIS_Led3	_TRISA2
#define LAT_Led3 	_LATA2
#define ODC_Led3	_ODA2
#define PIN_Led3 	_RA2
#define CN_Led3		30

// RS485 communication
#define TRIS_RS485_TX	_TRISB4
#define LAT_RS485_TX 	_LATB4
#define ODC_RS485_TX	_ODB4
#define PIN_RS485_TX 	_RB4
#define RPOUT_RS485_TX	RPOR2bits.RP4R
#define RPIN_RS485_TX	4
#define CN_RS485_TX		1
#define TRIS_RS485_RX	                _TRISB5
#define PIN_RS485_RX 	                _RB5
#define Lat_RS485_RX 	                _LATB5
#define ODC_RS485_RX	                _ODB5
#define RPOUT_RS485_RX		            RPOR2bits.RP5R
#define RPIN_RS485_RX		            5
#define CN_RS485_RX		                27

// Click board interface pin definitions

// Crystal slave mode definition
#define CRYS_Slave

// Board name definition
#define TRIS_BH1750_RST	                _TRISB13
#define PORT_BH1750_RST 	                _RB13
#define LAT_BH1750_RST 	                _LATB13
#define ODC_BH1750_RST	                _ODB13
#define PIN_BH1750_RST 	                _RB13
#define RPOUT_BH1750_RST		            RPOR6bits.RP13R
#define RPIN_BH1750_RST		            13
#define CN_BH1750_RST		                13
#define ADC_value_BH1750_RST              Buffer_entradas[11] 
#define HAL_SetAnalog_BH1750_RST()        {_PCFG11=0;\
                                        adc_addAnalogChannel(11);}

