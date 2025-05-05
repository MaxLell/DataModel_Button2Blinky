#pragma once
#include "common_types.h"
#include "design_by_contract.h"

#define PLACEHOLDER (0xA5A5A5A5U)

struct dataModelCb_t {
    void (*callback)(void);
    u32 moduleId;
};


template <typename T, u32 nofMaxModules>
class DataModel
{
private:
    void notifyAttachedModules();
    
    T data;
    dataModelCb_t attachedModules[nofMaxModules];
    u32 nofAttachedModules;

public:
    DataModel();
    ~DataModel();

    void setValue(T value);
    T getValue();

    void attach(dataModelCb_t& inputCb);
    void detach(u32 moduleId);
};

template <typename T, u32 nofMaxModules>
DataModel<T, nofMaxModules>::DataModel(/* args */)
{
    PRECONDITION(nofMaxModules > 0);

    for (u32 i = 0; i < nofMaxModules; i++) {
        attachedModules[i].callback = nullptr;
        attachedModules[i].moduleId = PLACEHOLDER;
    }
    nofAttachedModules = 0;
}

template <typename T, u32 nofMaxModules>
DataModel<T, nofMaxModules>::~DataModel()
{
}

template <typename T, u32 nofMaxModules>
void DataModel<T, nofMaxModules>::setValue(T inputValue) {
    PRECONDITION(nofAttachedModules > 0);

    // Set the value
    data = inputValue;

    // Notify all attached modules
    notifyAttachedModules();

    POSTCONDITION(data == inputValue);
}

template <typename T, u32 nofMaxModules>
T DataModel<T, nofMaxModules>::getValue() {
    
}

template <typename T, u32 nofMaxModules>
void DataModel<T, nofMaxModules>::attach(dataModelCb_t& inputCb) {
    PRECONDITION(inputCb.callback != nullptr);
    PRECONDITION(inputCb.moduleId != PLACEHOLDER);

    u32 beforeCount = nofAttachedModules;

    bool wasFound = false;
    for (u32 i = 0; i < nofMaxModules; i++) {
        if (attachedModules[i].moduleId == PLACEHOLDER) {
            attachedModules[i].moduleId = inputCb.moduleId;
            attachedModules[i].callback = inputCb.callback;

            nofAttachedModules++;
            wasFound = true;

            break;
        }
    }

    u32 afterCount = nofAttachedModules;

    POSTCONDITION(wasFound == true);
    POSTCONDITION(nofAttachedModules <= nofMaxModules);
    POSTCONDITION(beforeCount + 1 == afterCount);
}

template <typename T, u32 nofMaxModules>
void DataModel<T, nofMaxModules>::detach(u32 inputModuleId) {
    PRECONDITION(inputModuleId != PLACEHOLDER);
    u32 beforeCount = nofAttachedModules;

    bool wasFound = false;
    for (u32 i = 0; i < nofMaxModules; i++) {
        if (attachedModules[i].moduleId == inputModuleId) {
            attachedModules[i].moduleId = PLACEHOLDER;
            attachedModules[i].callback = nullptr;

            nofAttachedModules--;
            wasFound = true;

            break;
        }
    }

    u32 afterCount = nofAttachedModules;

    POSTCONDITION(wasFound == true);
    POSTCONDITION(nofAttachedModules <= nofMaxModules);
    POSTCONDITION(beforeCount - 1 == afterCount);
}

template <typename T, u32 nofMaxModules>
void DataModel<T, nofMaxModules>::notifyAttachedModules() {
    PRECONDITION(nofAttachedModules > 0);
    PRECONDITION(attachedModules[0].callback != nullptr);

    bool wasFound = false;
    for (u32 i = 0; i < nofMaxModules; i++) {
        if (attachedModules[i].callback != nullptr) {
            attachedModules[i].callback();
            wasFound = true;
        }
    }
    POSTCONDITION(wasFound == true);
}
