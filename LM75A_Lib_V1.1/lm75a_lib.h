/*******************************************************************************
|==============================================================================|
|   @author LIEK SOFTWARE TEAM                                                 |
|           Gorkem Aktas                                                       |
|           Fatih Yilmaz                                                       |
|           Emir Danisman                                                      |
|           Ozgur Karaaslan                                                    |
|           Berke Tezgocen                                                     |
|   @date 9 January 2021                                                       |
|   @documentedDate 28 March 2021                                              |
|   @version 1.2                                                               |
|   @brief  lm75a library                                                      |
|==============================================================================|
*******************************************************************************/
#include "stm32f10x.h"
#include "stm32f10x_i2c.h"
#include <stdio.h>

/* ── Configuration register bits ─────────────────────────────────────────── */

#define LM75A_REG_TEMP      0x00
#define LM75A_REG_CONF      0x01
#define LM75A_REG_THYST     0x02
#define LM75A_REG_TOS       0x03

#define LM75A_CONF_SHUTDOWN  (1 << 0)   /* 1 = shutdown mode              */
#define LM75A_CONF_OS_POL    (1 << 2)   /* 0 = active-low, 1 = active-high*/
#define LM75A_CONF_OS_COMP   (0 << 1)   /* comparator mode (default)      */
#define LM75A_CONF_OS_INT    (1 << 1)   /* interrupt mode                 */
#define LM75A_CONF_FQ_1      (0 << 3)   /* fault queue = 1 (default)      */
#define LM75A_CONF_FQ_2      (1 << 3)   /* fault queue = 2                */
#define LM75A_CONF_FQ_4      (2 << 3)   /* fault queue = 4                */
#define LM75A_CONF_FQ_6      (3 << 3)   /* fault queue = 6                */

/* ── Core functions ──────────────────────────────────────────────────────── */

void Lm75a_Config(uint8_t a0, uint8_t a1, uint8_t a2);
float get_temperature_c(void);
float get_temperature_f(void);
void i2c_readData(void);
void Lm75a_Delay(uint64_t time);

/* ── Extended functions (v1.2) ───────────────────────────────────────────── */

void Lm75a_WriteRegister(uint8_t reg, uint8_t value);
uint8_t Lm75a_ReadConfig(void);
void Lm75a_SetShutdown(uint8_t enable);
void Lm75a_SetAlarmThresholds(float t_os, float t_hyst);
float Lm75a_ReadTos(void);
float Lm75a_ReadThyst(void);
