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
    
    // Initialize some variables
    signals_per_time_unit = 0;
    uint32_t pwm_signal = 0;
    uint32_t current_rpm = 0;
    char uart_rpm_buff[4];     // This is to print RMP through UART(uint32)
    uint8 uart_print_flag = 0;
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
    
    I2C_EzI2CSetBuffer1(1, 1, i2c_buff);
    
    
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
        
        // Manage RPM counting and UART output
        pwm_signal = PWM_ReadCounter();
        
        // BIG KOSTIL, should be changed to interrupts ASAP.
        if (pwm_signal == 4998 && uart_print_flag == 0) {
            signals_per_time_unit = Counter_ReadCounter();
            
            
            // Convert signal to RPM
            current_rpm = (2 * signals_per_time_unit);
            
            // Put RMP into buffer and send it to UART
            sprintf(uart_rpm_buff, "%u", current_rpm);
            UART_UartPutChar('\n');
            UART_UartPutChar('\r');
            UART_UartPutString(uart_rpm_buff);
            uart_print_flag = 1;
        } else if (pwm_signal == 1){
            uart_print_flag = 0;
        }
    }
}

/* [] END OF FILE */
