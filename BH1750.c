#include "inc/BH1750.h"
#include "inc/gpio.h"
#include "inc/I2C1.h"
#include "inc/systemTimer.h"
#include <libpic30.h>

uint16_t Intensity = 0;
uint8_t error_code_Lux = 0;
uint32_t BH1750_getSystemMilis() = 0;

void lux_init()
{
	__delay_ms(10);
	HAL_GPIO_PinCfg(BH1750_RST, GPIO_OUTPUT);
	HAL_GPIO_PinSet(BH1750_RST, GPIO_HIGH);
	HAL_GPIO_PinSet(BH1750_RST, GPIO_LOW);
	__delay_ms(2);
	HAL_GPIO_PinSet(BH1750_RST, GPIO_HIGH);
	__delay_ms(5);
	Init_Master_I2C1(400, 0);
	__delay_ms(10);
	Start_I2C1();
	Write_I2C1(BH1750_I2CADDR_W);
	if (I2C1STATbits.ACKSTAT)
	{
		error_code_Lux = 1;
	}
	Write_I2C1(BH1750_CMD_power_up);
	if (I2C1STATbits.ACKSTAT)
	{
		error_code_Lux = 2;
	}
	Stop_I2C1();
	Start_I2C1();
	Write_I2C1(BH1750_I2CADDR_W);
	if (I2C1STATbits.ACKSTAT)
	{
		error_code_Lux = 1;
	}
	Write_I2C1(BH1750_CMD_one_time_H_res_mode1);
	if (I2C1STATbits.ACKSTAT)
	{
		error_code_Lux = 3;
	}
	Stop_I2C1();
	BH1750_getSystemMilis() = getSystemMilis();
}

void lux_pull(void)
{
	uint32_t temp;
	if (BH1750_getSystemMilis() + 200 <= getSystemMilis())
	{
		Start_I2C1();
		Write_I2C1(BH1750_I2CADDR_R);
		if (I2C1STATbits.ACKSTAT)
		{
			error_code_Lux = 4;
		}
		temp = Read_I2C1(0);
		temp <<= 8;
		temp |= Read_I2C1(1);
		Stop_I2C1();

		Intensity = (temp * 54613) >> 16;

		Start_I2C1();
		Write_I2C1(BH1750_I2CADDR_W);
		if (I2C1STATbits.ACKSTAT)
		{
			error_code_Lux = 1;
		}
		Write_I2C1(BH1750_CMD_power_up);
		if (I2C1STATbits.ACKSTAT)
		{
			error_code_Lux = 2;
		}
		Stop_I2C1();

		Start_I2C1();
		Write_I2C1(BH1750_I2CADDR_W);
		if (I2C1STATbits.ACKSTAT)
		{
			error_code_Lux = 1;
		}
		Write_I2C1(BH1750_CMD_one_time_H_res_mode1);
		if (I2C1STATbits.ACKSTAT)
		{
			error_code_Lux = 3;
		}
		Stop_I2C1();

		BH1750_getSystemMilis() = getSystemMilis();
	}
}

