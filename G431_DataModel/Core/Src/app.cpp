#include "app.h"
#include "datamodel.h"
#include "button.h"
#include "blinky_led.h"
#include "stm32g4xx_nucleo.h"

DataModel<bool, 1> btnEvent;
Button btn(btnEvent);
BlinkyLed blinkyLed(btnEvent);

void main_app(void){
    // Init   
    

    // Loop
    for (;;){

    }
}

void BSP_PB_Callback(Button_TypeDef Button)
{
    // Check if the button is pressed
    if (Button == BUTTON_USER)
    {
        // Set the flag to indicate that the button was pressed
        btn.isCurrentlyPressed();
    }
}
