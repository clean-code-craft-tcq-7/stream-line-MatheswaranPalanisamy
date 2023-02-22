#include <stdio.h>
#include <string.h>

typedef void (*bmsIoFuncPtr)(char *, int);

void streamBmsSensorData();
void setStreamIoFunc(bmsIoFuncPtr funcPtr);
