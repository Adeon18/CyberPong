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


CY_ISR( ISR_Per_Handler )
{
            
     
        period_per_spin += period_per_window;
        indx += 1;
    
        sprintf(uart_per_buff, "%u", period_per_window);
        UART_UartPutChar('\n');
        UART_UartPutChar('\r');
        UART_UartPutString(uart_per_buff);
        indx = 0;
        period_per_spin = 0;
    Perioud_Counter_ClearInterrupt(Perioud_Counter_INTR_MASK_CC_MATCH);
}



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    // Initialize some variables
    signals_per_time_unit = 0;
    period_per_window = 0;
    current_rpm = 0;
    indx = 0;
    

    /* Start Everything Up */
    UART_Start();
    Perioud_Counter_Start();
    ISR_Per_StartEx(ISR_Per_Handler);
    PWM_Start();
    
   
    
    for(;;)
    {   
        
        //current_rpm = FanController_GetActualSpeed(1);
        //sprintf(uart_per_buff, "%u", current_rpm);
        //UART_UartPutChar('\n');
        //UART_UartPutChar('\r');
        //UART_UartPutString(uart_per_buff);
        
        //current_rpm = FanController_GetDesiredSpeed(1);
        //sprintf(uart_per_buff, "%u", current_rpm);
        //UART_UartPutChar('\n');
        //UART_UartPutChar('\r');
        //UART_UartPutString(uart_per_buff);
        period_per_window = Perioud_Counter_ReadCounter();

    }
}

/* [] END OF FILE */
