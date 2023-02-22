#define BMS_MAX_READING_PER_SENSOR      50

typedef enum
{
    CHARGE_RATE_SENSOR = 0,
    TEMPERATURE_SENSOR = 1,
    MAX_SENSORS_SUPPORTED = 2

}BMS_SensorTypes;

typedef struct
{
    float chargeRate;
    float temperature;

}sensorData;

extern float *BMS_SensorDataBuffer[MAX_SENSORS_SUPPORTED];
extern char *BMS_SensorNames[MAX_SENSORS_SUPPORTED];
