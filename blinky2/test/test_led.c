#include "unity.h"
#include "led.h"

#include "mock_gpio.h"
#include "inc/hw_memmap.h"

void setUp(void)
{
    printf("begin setup\n");
}

void tearDown(void)
{
    printf("begin tearDown\n");
}

void test_when_the_led_is_turned_on_then_port_f_pin_2_is_set(void)
{
	// Expect PORTF pin 2 to be set.
	GPIOPinWrite_Expect(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);

	// Call the function under test.
	TEST_ASSERT_EQUAL_INT(0,led_turn_on());
}

void test_led1(void)
{
    TEST_ASSERT_EQUAL_INT(0,0);
}

void test_led2(void)
{
    TEST_ASSERT_EQUAL_INT(0,0);
}

// int led_test_main(void)
// {
//     UNITY_BEGIN();
//     // RUN_TEST(test_when_the_led_is_turned_on_then_port_f_pin_2_is_set);
//     RUN_TEST(test_led1);
//     RUN_TEST(test_led2);
//     return UNITY_END();
// }


// #if !defined(TEST_ON_TARGET)
// int main(void)
// {
//     return led_test_main();
// }
// #endif