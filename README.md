# STM32F10x LM75A Temperature Sensor Library

A lightweight I2C driver library for the **NXP LM75A** digital temperature sensor, targeting **STM32F10x** series microcontrollers using the Standard Peripheral Library (SPL).

## Features

- Configurable I2C address via hardware address pins (A0, A1, A2) — supports all 8 possible addresses
- Temperature reading in both **Celsius** and **Fahrenheit**
- Built-in millisecond delay utility using SysTick
- Bare-metal I2C communication — no HAL/LL dependency, direct register-level control
- 9-bit resolution (0.5C steps) from the LM75A's 2-byte temperature register

## Hardware

| Pin | Connection |
|-----|-----------|
| SDA | PB7 (I2C1) |
| SCL | PB6 (I2C1) |
| A0/A1/A2 | VCC (1) or GND (0) |
| VCC | 3.3V |

```
STM32F103C8T6
    PB6 (SCL) ──────┐
    PB7 (SDA) ────┐ │
                  │ │
              ┌───┴─┴───┐
              │  LM75A   │
              │          │
              │ A0 A1 A2 │
              └──┬──┬──┬─┘
                GND/VCC
```

## Quick Start

```c
#include "lm75a_lib.h"

int main(void) {
    // A0=GND, A1=GND, A2=GND → address 0x90
    Lm75a_Config(0, 0, 0);

    while (1) {
        float temp_c = get_temperature_c();
        float temp_f = get_temperature_f();

        Lm75a_Delay(500); // 500ms delay
    }
}
```

## API

| Function | Description |
|----------|-------------|
| `Lm75a_Config(a0, a1, a2)` | Initialize I2C1 and set sensor address based on pin configuration |
| `get_temperature_c()` | Read temperature in Celsius (0.5C resolution) |
| `get_temperature_f()` | Read temperature in Fahrenheit |
| `Lm75a_Delay(ms)` | Blocking delay in milliseconds (SysTick-based) |

## Address Map

| A2 | A1 | A0 | I2C Address |
|----|----|----|------------|
| 0  | 0  | 0  | 0x90 |
| 0  | 0  | 1  | 0x92 |
| 0  | 1  | 0  | 0x94 |
| 0  | 1  | 1  | 0x96 |
| 1  | 0  | 0  | 0x98 |
| 1  | 0  | 1  | 0x9A |
| 1  | 1  | 0  | 0x9C |
| 1  | 1  | 1  | 0x9E |

## Project Structure

```
LM75A_Lib_V1.1/
    lm75a_lib.h    — Header with function prototypes
    lm75a_lib.c    — I2C init, temperature read, delay implementation
```

## Requirements

- STM32F10x Standard Peripheral Library
- ARM GCC or Keil MDK toolchain
- STM32F103C8T6 (Blue Pill) or compatible

## Authors

Developed at **ITU IEEE RAS Committee** by LIEK Software Team.

## License

MIT
