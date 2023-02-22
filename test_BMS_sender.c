
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "BMS_Config.h"
#include "BMS_IO.h"
#include "BMS_Sender.h"

#include "test_BMS_StreamSensorModule.h"
#include "test_BMS_Operations.h"
#include "test_BMS_Mock.h"

void testSenderModule()
{
    memset(testArray, 0, 1000);
    testCount = 0;

    setStreamIoFunc(mockIoOperation);
    streamBmsSensorData();
    assert(testCount == 621);
    assert(strcmp(testArray, "ChargeRate, Temperature\n0.10, 17.10\n0.30, 32.50\n0.60, 26.00\n0.90, 49.10\n0.20, 22.20\n0.70, 27.40\n0.10, 31.70\n0.90, 9.00\n0.20, 12.10\n0.20, 32.40\n0.10, 21.00\n0.30, 13.20\n0.60, 26.10\n0.50, 35.00\n0.20, 27.00\n0.70, 24.80\n0.50, 15.00\n0.90, 19.70\n0.10, 31.00\n0.20, 12.00\n0.00, 20.90\n0.30, 13.00\n0.60, 26.30\n0.90, 39.00\n0.20, 22.00\n0.90, 29.50\n0.30, 23.60\n0.50, 15.20\n0.10, 1.90\n0.20, 12.20\n0.10, 21.00\n0.30, 33.40\n0.90, 19.00\n0.90, 39.00\n0.40, 14.00\n0.70, 17.50\n0.50, 15.30\n0.90, 29.00\n0.10, 17.80\n0.20, 21.00\n0.10, 12.20\n0.30, 34.40\n0.70, 27.80\n0.90, 19.00\n0.20, 28.00\n0.70, 17.50\n0.30, 3.30\n0.60, 16.00\n0.40, 34.80\n0.30, 37.70\n") == 0);

    // Tear down the test setup by roll back to the default IO operation
    setStreamIoFunc(printToConsole);
}

void test_BMS_Sender()
{
    printf("Running test cases for BMS sensor stream sender module...\n");
    testBMSOperations();
    testSenderModule();
    testStreamSensorDataModule();
    printf("All tests are successful\n");

}
