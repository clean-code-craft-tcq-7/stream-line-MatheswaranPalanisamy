#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "test_BMS_sender.h"
#include "BMS_Sender.h"
#include "BMS_Helper.h"
#include "BMS_SenderOperations.h"

void testBMSOperations()
{
    char *argumetValues[2] = {"testExe", "-t"};
    char **arguments = argumetValues;

    assert(getOperation(0, arguments) == NULL);
    assert(getOperation(1, arguments) == NULL);
    assert(getOperation(3, arguments) == NULL);

    char *argumetValues1[2] = {"testExe", "-p"};
    arguments = argumetValues1;
    assert(getOperation(2, arguments) == NULL);

    char *argumetValues2[2] = {"testExe", "-t"};
    arguments = argumetValues2;
    assert(getOperation(2, arguments) == test_BMS_Sender);

    char *argumetValues3[2] = {"testExe", "-h"};
    arguments = argumetValues3;
    assert(getOperation(2, arguments) == printHelpDocument);

    char *argumetValues4[2] = {"testExe", "-r"};
    arguments = argumetValues4;
    assert(getOperation(2, arguments) == streamBmsSensorData);

    char *argumetValues5[2] = {"testExe", ""};
    arguments = argumetValues5;
    assert(getOperation(2, arguments) == NULL);

    char *argumetValues6[2] = {"testExe", "*t"};
    arguments = argumetValues6;
    assert(getOperation(2, arguments) == NULL);

    char *argumetValues7[2] = {"testExe", "~h"};
    arguments = argumetValues7;
    assert(getOperation(2, arguments) == NULL);

    char *argumetValues8[2] = {"testExe", ".r"};
    arguments = argumetValues8;
    assert(getOperation(2, arguments) == NULL);
}
