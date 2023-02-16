#include <stdio.h>
#include "BMS_Config.h"
#include "BMS_StreamSensorData.h"
#include "BMS_Sender.h"
#include "BMS_IO.h"

bmsIoFuncPtr bmsIoFunc = printToConsole;

void setStreamIoFunc(bmsIoFuncPtr funcPtr)
{
    bmsIoFunc = funcPtr;
}

void streamBmsSensorData()
{
    // printHeader
    streamHeader(bmsIoFunc);
    // printSensorValue
    streamSensorValues(bmsIoFunc);
}
