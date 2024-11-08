#ifndef _XLCD_SDCARD
#define _XLCD_SDCARD

#include "FS.h"
#include "SD.h"
#include <ArduinoJson.h>
#include <Arduino.h>

bool xtouch_sdcard_setup()
{
    if (!SD.begin())
    {
        Serial.println("[CYD][SD] Card Mount Failed");
        return false;
    }

    uint8_t cardType = SD.cardType();

    if (cardType == CARD_NONE)
    {
        Serial.println("[CYD][SD] No SD card attached");
        return false;
    }

    Serial.print("CYD][SD] SD Card Type: ");

    if (cardType == CARD_MMC)
    {
        Serial.println("[CYD][SD] MMC");
    }
    else if (cardType == CARD_SD)
    {
        Serial.println("[CYD][SD] SDSC");
    }
    else if (cardType == CARD_SDHC)
    {
        Serial.println("[CYD][SD] SDHC");
    }
    else
    {
        Serial.println("[CYD][SD] UNKNOWN");
    }

    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("[CYD][SD] SD Card Size: %lluMB\n", cardSize);
    xtouch_filesystem_mkdir(SD, cyd_paths_root);

    return true;
}

#endif