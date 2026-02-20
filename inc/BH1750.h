#ifndef BH1750_H_
#define BH1750_H_

#include <stdint.h>

#define  BH1750_CMD_power_down              0x00
#define  BH1750_CMD_power_up                0x01
#define  BH1750_CMD_reset                   0x07
#define  BH1750_CMD_cont_H_res_mode1        0x10
#define  BH1750_CMD_cont_H_res_mode2        0x11
#define  BH1750_CMD_cont_L_res_mode         0x13
#define  BH1750_CMD_one_time_H_res_mode1    0x20
#define  BH1750_CMD_one_time_H_res_mode2    0x21
#define  BH1750_CMD_one_time_L_res_mode     0x23
#define	 BH1750_I2CADDR_W					0xB8
#define  BH1750_I2CADDR_R					0xB9

extern uint16_t Intensity;
extern uint8_t error_code_Lux;
extern uint32_t BH1750_timeStamp;

void lux_init(void);

void lux_pull(void);

#endif /* BH1750_H_ */


