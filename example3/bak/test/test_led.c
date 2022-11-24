#include "unity.h"
#include "led.h"

#include "mock_gpio.h"
#include "inc/hw_memmap.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_when_the_led_is_turned_on_then_port_f_pin_2_is_set(void)
{
	// Expect PORTF pin 2 to be set.
	GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);

	// Call the function under test.
	led_turn_on();
}

int led_test_main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_when_the_led_is_turned_on_then_port_f_pin_2_is_set);
    // RUN_TEST(test_function_process_event);
    return UNITY_END();
}


#if !defined(TEST_ON_TARGET)
int main(void)
{
    return led_test_main();
}
#endif