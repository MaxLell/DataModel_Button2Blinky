#pragma once

#include "main.h"
#include "stm32g4xx_nucleo.h"

#include "datamodel.h"

#define LED_ID 0x0001

class BlinkyLed
{
private:
public:
    BlinkyLed(DataModel<bool, 1> &btnEvent)
    {
        dataModelCb_t cb;
        cb.moduleId = LED_ID;
        cb.callback = []()
        {
            BSP_LED_Toggle(LED2);
            HAL_Delay(100);
        };
        btnEvent.attach(cb);
    }
    ~BlinkyLed() {};
};
