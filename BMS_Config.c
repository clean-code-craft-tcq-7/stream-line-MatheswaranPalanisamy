#include "sensorData.h"
#include "BMS_Config.h"

float *BMS_SensorDataBuffer[MAX_SENSORS_SUPPORTED] = {ChargeRateSensorData, temperatureSensorData};
char *BMS_SensorNames[MAX_SENSORS_SUPPORTED] = {"ChargeRate", "Temperature"};
