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



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    // Initialize some variables
    current_rpm = 0;
    

    /* Start Everything Up */
    FanController_Start();
    UART_Start();

    char ch;
    int8 print_speed = 0;
    int16 speed_buf = 0;
    for(;;)
    {   
        ch = UART_UartGetChar();
        if(ch == 'p'){print_speed = 0;}
        else if(ch == 's'){print_speed = 1;}
        else if(ch == '\r' && speed_buf > 2000 && speed_buf < 4800){
            FanController_SetDesiredSpeed(1, speed_buf);
            speed_buf = 0;
            UART_UartPutChar('\n');
        }
        else if(ch == '\r'){
            speed_buf = 0;
            UART_UartPutChar('\n');
        }
        else if(ch < 58 && ch > 47){
            speed_buf *= 10;
            speed_buf += ch - '0';
        }
        if(print_speed){
            current_rpm = FanController_GetActualSpeed(1);
            sprintf(uart_rpm_buff, "%u", current_rpm);
            UART_UartPutChar('\n');
            UART_UartPutChar('\r');
            UART_UartPutString(uart_rpm_buff);
            
            current_rpm = FanController_GetDesiredSpeed(1);
            sprintf(uart_rpm_buff, "%u", current_rpm);
            UART_UartPutChar('\n');
            UART_UartPutChar('\r');
            UART_UartPutString(uart_rpm_buff);
        }
        else{
            UART_UartPutChar(ch);
        }
       

    }
}

/* [] END OF FILE */
