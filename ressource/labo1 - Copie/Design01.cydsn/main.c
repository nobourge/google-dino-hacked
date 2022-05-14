/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "keypad.h"
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    //MyInst_Start();
    
    //LedPin_Start();
    
    uint8_t was_btn_pressed = 0;
    
    keypadInit ();
    keypadScan();
    
    
    LCD_Char_1_Init();
    
            
    LCD_Char_1_ClearDisplay();
    //LCD_Char_1_Position(0);
        
    

    for(;;)
    {
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_PrintNumber(keypadScan()-48);
        CyDelay(500);
        /*
        uint8_t is_btn_pressed = BtnPin_Read();
        if (is_btn_pressed && was_btn_pressed) {
            LedPin_Write(~LedPin_Read());
        
            CyDelay(250);
        }
        
        was_btn_pressed = is_btn_pressed;*/

        
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
