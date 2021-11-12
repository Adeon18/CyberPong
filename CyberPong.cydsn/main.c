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
#include <stdio.h>
#include "main_data.h"


// For now this is not used Anywhere. TODO
CY_ISR( ISR_Compare_Handler )
{
    signals_per_time_unit = Counter_ReadCounter();
    

    PWM_ClearInterrupt(PWM_INTR_MASK_TC);
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Start Everything Up */
    PWM_Start();
    PWM_Motor_Start();
    Counter_Start();
    UART_Start();
  
    // Initialize some variables
    signals_per_time_unit = 0;
    uint32_t pwm_signal = 0;
    char buff[10];
    for(;;)
    {   
        pwm_signal = PWM_ReadCounter();
        //sprintf(buff, "%u", pwm_signal);
        //UART_UartPutChar('\n');
        //UART_UartPutChar('\r');
        //UART_UartPutString(buff);
        
        // BIG KOSTIL, should be changed to interrupts ASAP.
        if (pwm_signal == 498) {
            signals_per_time_unit = Counter_ReadCounter();
            
            // Convert signal to RPM
            signals_per_time_unit = (20 * signals_per_time_unit);
            
            // Put RMP into buffer and send it to UART
            sprintf(buff, "%u", signals_per_time_unit);
            UART_UartPutChar('\n');
            UART_UartPutChar('\r');
            UART_UartPutString(buff);
        }
    }
}

/* [] END OF FILE */
