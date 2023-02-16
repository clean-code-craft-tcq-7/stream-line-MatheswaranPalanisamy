#include <stdio.h>
#include <string.h>

char testArray[1000];
int testCount = 0;

void mockIoOperation(char *printStr, int count)
{
    memcpy(&testArray[testCount], printStr, count);
    testCount += count;
}
