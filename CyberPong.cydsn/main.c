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
            
            
    // Convert signal to RPM
    current_rpm = (2 * signals_per_time_unit);
    
    // Put RMP into buffer and send it to UART
    sprintf(uart_rpm_buff, "%u", current_rpm);
    UART_UartPutChar('\n');
    UART_UartPutChar('\r');
    UART_UartPutString(uart_rpm_buff);
    
    PWM_ClearInterrupt(PWM_INTR_MASK_TC);
}

CY_ISR( ISR_Per_Handler )
{
            
     
    if(indx < 4){
    // Put RMP into buffer and send it to UART
    period_per_spin += period_per_window;
    indx += 1;
    
    }
    else if (indx >= 4){
        sprintf(uart_per_buff, "%u", period_per_spin);
    UART_UartPutChar('\n');
    UART_UartPutChar('\r');
    UART_UartPutString(uart_per_buff);
    indx = 0;
    period_per_spin = 0;
    }
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
    period_per_spin = 0;
    // I2C variables
    uint16 motor_speed_pwm = 0;
    uint8 i2c_buff[1];
    i2c_buff[0] = 0;
    

    /* Start Everything Up */
    PWM_Start();
    PWM_Motor_Start();
    Counter_Start();
    UART_Start();
    I2C_Start();
    Perioud_Counter_Start();
    ISR_Compare_StartEx(ISR_Compare_Handler);
    
    I2C_EzI2CSetBuffer1(1, 1, i2c_buff);
    ISR_Per_StartEx(ISR_Per_Handler);
    
    for(;;)
    {   
        // Manage I2C Input
        if (motor_speed_pwm != i2c_buff[0]) {
            // This if statement only exists since we use drivers that cannot handle slow speeds.
            // Remove this check only if you want to BURN down the driver or have a better one.
            motor_speed_pwm = i2c_buff[0];
            if (motor_speed_pwm > 100) {
                PWM_Motor_WriteCompare(motor_speed_pwm);
            }   
        }
        signals_per_time_unit = Counter_ReadCounter();
        period_per_window = Perioud_Counter_ReadCounter();
    }
}

/* [] END OF FILE */
