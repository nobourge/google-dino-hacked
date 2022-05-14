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

#include "keypad.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    Timer_Start();

    int counter = 0;
    
    VDAC8_1_Init();
    VDAC8_1_Enable();
    
    for(;;)
    {
        /* Place your application code here. */
        int overFlow = 0x80 & Timer_ReadStatusRegister ();
        
        if (overFlow) {
            counter++;
            VDAC8_1_SetValue((counter % 100) * 2);
    
        }
        
        
    }
}

/* [] END OF FILE */
