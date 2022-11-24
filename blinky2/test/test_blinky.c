#include "unity.h"
#include "led.h"
#include "blinky.h"

#include "mock_gpio.h"
#include "mock_sysctl.h"
#include "inc/hw_memmap.h"

void setUp(void)
{
    // printf("begin setup\n");
}

void tearDown(void)
{
    // printf("begin tearDown\n");
}

void test_main(void)
{
	// Expect PORTF pin 2 to be set.
	// GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
    // SysCtlPeripheralEnable

    SysCtlPeripheralEnable_Expect(SYSCTL_PERIPH_GPIOG);

    SysCtlPeripheralReady_ExpectAndReturn(SYSCTL_PERIPH_GPIOG,0);

    GPIOPinTypeGPIOOutput_Expect(GPIO_PORTG_BASE, GPIO_PIN_2);

    GPIOPinWrite_Ignore();
    GPIOPinWrite_Ignore();
	// Call the function under test.
	// TEST_ASSERT_EQUAL_INT(0,led_turn_on());
    TEST_ASSERT_EQUAL_INT(0,app_main());
    // TEST_ASSERT_EQUAL_INT(0,0);
}

