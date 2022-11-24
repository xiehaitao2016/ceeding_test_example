#pragma once
#include <stdint.h>
#include <stdbool.h>
extern void GPIOPinWrite(uint32_t baseaddr,uint32_t pin,uint32_t pin2);
extern void GPIOPinTypeGPIOOutput(uint32_t baseaddr,uint32_t pin);