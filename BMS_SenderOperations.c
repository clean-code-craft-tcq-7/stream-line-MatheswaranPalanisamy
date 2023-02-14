#include <stdio.h>
#include <string.h>

#include "test_BMS_sender.h"
#include "BMS_Sender.h"
#include "BMS_Helper.h"
#include "BMS_SenderOperations.h"

const BMS_Operations BMS_OperationConfig[BMS_MAX_OPERATIONS] = 
{
    { 'r', streamBmsSensorData},
    { 't', test_BMS_Sender },
    { 'h', printHelpDocument}
};

static int checkArgumentCount(int argc)
{
    if(argc == 2)
    {
        return 1;
    }

    return 0;
}

static operation checkOperation(char *argv)
{
    int index = 0;
    char argument = argv[1];

    for(;index < BMS_MAX_OPERATIONS; index++)
    {
        if(argument == BMS_OperationConfig[index].argument)
        {
            return BMS_OperationConfig[index].bmsOperation;
        }
    }

    return NULL;
}

operation getOperation(int argc, char **argv)
{
    if(checkArgumentCount(argc))
    {
        return checkOperation(argv[1]);
    }

    return NULL;
}
