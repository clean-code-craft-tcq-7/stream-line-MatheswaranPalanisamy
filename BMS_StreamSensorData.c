#include <stdio.h>
#include "BMS_Config.h"
#include "BMS_StreamSensorData.h"

static int streamCsvSeperator(int index, char *buff)
{
    int count = 0;
    if(index < MAX_SENSORS_SUPPORTED - 1)
    {
        count = sprintf(buff, ", ");
    }

    return count;
}

void streamHeader(void ioFuncPtr(char *, int))
{
    int index = 0;
    char charBuff[50];
    int count = 0;

    for(;index < MAX_SENSORS_SUPPORTED; index++)
    {
        count += sprintf(&charBuff[count], "%s", BMS_SensorNames[index]);
        count += streamCsvSeperator(index, &charBuff[count]);
    }

    count += sprintf(&charBuff[count], "\n");
    ioFuncPtr(charBuff, count);

}

void streamSensorValues(void ioFuncPtr(char *, int))
{
    int readingIndex = 0, sensorIndex = 0;
    char charBuff[1000];
    int count = 0;

    for(;readingIndex < BMS_MAX_READING_PER_SENSOR; readingIndex++)
    {
        for(sensorIndex = 0; sensorIndex < MAX_SENSORS_SUPPORTED; sensorIndex++)
        {
            count += sprintf(&charBuff[count], "%0.2f", getSensorReading(sensorIndex, readingIndex));
            count += streamCsvSeperator(sensorIndex, &charBuff[count]);    
        }

        count += sprintf(&charBuff[count], "\n");
    }

    ioFuncPtr(charBuff, count);
}

float getSensorReading(int sensor, int readingIndex)
{
    float *sensorBuffer = BMS_SensorDataBuffer[sensor];

    return sensorBuffer[readingIndex];
}
