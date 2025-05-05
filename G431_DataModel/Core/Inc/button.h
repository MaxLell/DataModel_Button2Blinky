#pragma once

#include "common_types.h"
#include "design_by_contract.h"
#include "custom_assert.h"

#define BTN_ID (0xA223U)

class Button
{
private:
    bool wasPressedFlag = false;
    DataModel<bool, 1> &dataModelReference;

public:
    Button(DataModel<bool, 1> &dataModel) : dataModelReference(dataModel) {};
    ~Button() {};

    void isCurrentlyPressed()
    {
        wasPressedFlag = true;
        dataModelReference.setValue(wasPressedFlag);
        wasPressedFlag = false;
    };
};
