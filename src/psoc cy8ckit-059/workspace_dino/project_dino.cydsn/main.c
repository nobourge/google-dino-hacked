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
#include "math.h"

//#include "keypad.h"


void MoveServoTo(int degrees) {
    PWM_1_Start();
    PWM_1_WriteCompare1(degrees / 9 + 13); //
    CyDelay(500);
    PWM_1_Stop();
}


void PressDownArrow() {
    MoveServoTo(0);
}


void PressUpArrow() {
    MoveServoTo(100);
}

void JumpDino(unsigned ms) {
    
    PressUpArrow();
    
    CyDelay(ms);
    
    PressDownArrow();
    CyDelay(ms);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    ADC_DelSig_1_Start();       
    LCD_Char_1_Init();
    
            
    LCD_Char_1_ClearDisplay();
    //LCD_Char_1_Position(0);
    PWM_1_Init();
    
      
    PWM_1_Start();
    

    for(;;)
    {
        //LCD_Char_1_PrintInt32(ADC_DelSig_1_Read32());
        //CyDelay(500);
        JumpDino(500);
        //if (ADC_DelSig_1_Read32() < 32000){
        //    JumpDino(500);
        //}
        CyDelay(100);
    }
    
}

/* [] END OF FILE */
