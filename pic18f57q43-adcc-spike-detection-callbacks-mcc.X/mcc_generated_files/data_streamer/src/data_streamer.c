/**
 * DATASTREAMER Generated Driver API Source File.
 *
 * @file data_streamer.c
 *
 * @ingroup datastreamer
 *
 * @brief This file contains the implementation for the Data Streamer driver APIs.
 *
 * @version Data Streamer Driver Version 1.2.1
 */
 /*
� [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include "../data_streamer.h"

struct DATA_STREAMER_STRUCT DataStreamer;
struct PACKAGE_STRUCT DATA_STREAMER_PACKAGE;

void DataStreamer_Initialize(void)
{
    DataStreamer_PackageSet(&DataStreamer, sizeof (DataStreamer));
}

void DataStreamer_FrameSend(void * package, size_t length)
{
    /* cppcheck-suppress misra-c2012-11.5 */
    char * dp = package;
    DataStreamer_VariableWrite(DATA_STREAMER_START_BYTE);
    size_t counter = length;
    while (counter > 0U)
    {
        DataStreamer_VariableWrite(*dp++);
        counter--;
    }
    DataStreamer_VariableWrite(DATA_STREAMER_END_BYTE);
    while (DataStreamer_IsTxDone() == false)
    {
    }
};

void DataStreamer_PackageSet(void * customStructHandler, size_t customlength)
{
    DATA_STREAMER_PACKAGE.varStruct = customStructHandler;
    DATA_STREAMER_PACKAGE.length = customlength;
};
