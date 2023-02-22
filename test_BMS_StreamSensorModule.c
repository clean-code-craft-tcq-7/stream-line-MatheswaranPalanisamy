#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "BMS_Config.h"
#include "BMS_StreamSensorData.h"
#include "test_BMS_Mock.h"

void testGetSensorValue()
{
    assert(fabs(getSensorReading(CHARGE_RATE_SENSOR, 0) - 0.1) < 0.01);
    assert(fabs(getSensorReading(CHARGE_RATE_SENSOR, 2) - 0.6) < 0.01);
    assert(fabs(getSensorReading(CHARGE_RATE_SENSOR, 5) - 0.7) < 0.01);
    assert(fabs(getSensorReading(CHARGE_RATE_SENSOR, 20) - 0) < 0.01);
    assert(fabs(getSensorReading(CHARGE_RATE_SENSOR, 45) - 0.7) < 0.01);
    assert(fabs(getSensorReading(CHARGE_RATE_SENSOR, 49) - 0.3) < 0.01);
    assert(fabs(getSensorReading(TEMPERATURE_SENSOR, 0) - 17.1) < 0.01);
    assert(fabs(getSensorReading(TEMPERATURE_SENSOR, 7) - 9) < 0.01);
    assert(fabs(getSensorReading(TEMPERATURE_SENSOR, 13) - 35) < 0.01);
    assert(fabs(getSensorReading(TEMPERATURE_SENSOR, 25) - 29.5) < 0.01);
    assert(fabs(getSensorReading(TEMPERATURE_SENSOR, 36) - 15.3) < 0.01);
    assert(fabs(getSensorReading(TEMPERATURE_SENSOR, 47) - 16) < 0.01);
    assert(fabs(getSensorReading(TEMPERATURE_SENSOR, 49) - 37.7) < 0.01);
}

void testStreamHeader()
{
    memset(testArray, 0, 1000);
    testCount = 0;

    streamHeader(mockIoOperation);
    assert(testCount == 24);
    assert(strcmp(testArray, "ChargeRate, Temperature\n") == 0);
}

void testStreamSensorValues()
{
    memset(testArray, 0, 1000);
    testCount = 0;

    streamSensorValues(mockIoOperation);
    assert(testCount == 597);
    assert(strcmp(testArray, "0.10, 17.10\n0.30, 32.50\n0.60, 26.00\n0.90, 49.10\n0.20, 22.20\n0.70, 27.40\n0.10, 31.70\n0.90, 9.00\n0.20, 12.10\n0.20, 32.40\n0.10, 21.00\n0.30, 13.20\n0.60, 26.10\n0.50, 35.00\n0.20, 27.00\n0.70, 24.80\n0.50, 15.00\n0.90, 19.70\n0.10, 31.00\n0.20, 12.00\n0.00, 20.90\n0.30, 13.00\n0.60, 26.30\n0.90, 39.00\n0.20, 22.00\n0.90, 29.50\n0.30, 23.60\n0.50, 15.20\n0.10, 1.90\n0.20, 12.20\n0.10, 21.00\n0.30, 33.40\n0.90, 19.00\n0.90, 39.00\n0.40, 14.00\n0.70, 17.50\n0.50, 15.30\n0.90, 29.00\n0.10, 17.80\n0.20, 21.00\n0.10, 12.20\n0.30, 34.40\n0.70, 27.80\n0.90, 19.00\n0.20, 28.00\n0.70, 17.50\n0.30, 3.30\n0.60, 16.00\n0.40, 34.80\n0.30, 37.70\n") == 0);
}

void testStreamSensorDataModule()
{
    testGetSensorValue();
    testStreamHeader();
    testStreamSensorValues();
}
