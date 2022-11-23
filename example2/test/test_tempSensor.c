#ifdef TEST

#include "unity.h"
#include "mock_i2c.h"
#include "tempSensor.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void
test_whenTempRegisterReadsMinValue_thenTheTempIsTheMinValue(void)
{
uint8_t tempRegisterAddress = 0x03;
float expectedTemperature = -100.0f;
float tolerance = 0.1f;
//When
i2c_readRegister_ExpectAndReturn(tempRegisterAddress, 0x0);
//Then
float actualTemperature = tempSensor_getTemperature();
TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature,
actualTemperature);
}

void test_whenTempRegisterReadsMaxValue_thenTheTempIsTheMaxValue(void)
{
uint8_t tempRegisterAddress = 0x03;
float expectedTemperature = 104.6f;
float tolerance = 0.1f;
//When
i2c_readRegister_ExpectAndReturn(tempRegisterAddress, 0x3ff);
//Then
float actualTemperature = tempSensor_getTemperature();
TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature,
actualTemperature);
}

#endif // TEST
