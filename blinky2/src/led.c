#include "led.h"

#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"

int led_turn_on(void)
{
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
  return 0;
}

int led_turn_off(void)
{
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
  return 0;
}
