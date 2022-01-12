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

int8 print_speed = 0;
int8 read_motor_speeds = 0;
uint16_t current_desired_speed;


void print_all_speed() {
    
    for (int i = 1; i < MOTOR_COUNT + 1; i++) {
        current_rpm = FanController_GetActualSpeed(i);
        sprintf(uart_rpm_buff, "%u", current_rpm / 2);
        UART_UartPutString(uart_rpm_buff);
        UART_UartPutChar(' ');
        
        current_rpm = FanController_GetDesiredSpeed(i);
        sprintf(uart_rpm_buff, "%u", current_rpm / 2);
        UART_UartPutString(uart_rpm_buff);
        UART_UartPutChar(' ');
    }
    UART_UartPutChar('\n');
    UART_UartPutChar('\r');
}

void write_motor_speed() {
    // Write the speed of all motors
    for (int i = 0; i < MOTOR_COUNT; i++) {
        if (motor_speeds[i] > 2 * MIN_RPM && motor_speeds[i] < 2 * MAX_RPM) {
            FanController_SetDesiredSpeed(i+1, motor_speeds[i]);
        } else {
            continue;
        }
    }
}


CY_ISR(Timer_Isr_Handler) {
    current_desired_speed = FanController_GetDesiredSpeed(1);
    
    if (current_desired_speed == 3000) {
        FanController_SetDesiredSpeed(1, 4000);
    } else if (current_desired_speed == 4000) {
        FanController_SetDesiredSpeed(1, 3000);
    }
    //Timer_ChangeSpeed_ClearInterrupt(Timer_ChangeSpeed_INTR_MASK_TC);

}


CY_ISR(Ouput_Speed_Isr_handler) {
    
    if (print_speed) {
        current_rpm = FanController_GetActualSpeed(1);
        sprintf(uart_rpm_buff, "%u", current_rpm);
        UART_UartPutString(uart_rpm_buff);
        UART_UartPutChar(' ');
        
        current_rpm = FanController_GetDesiredSpeed(1);
        sprintf(uart_rpm_buff, "%u", current_rpm);
        UART_UartPutString(uart_rpm_buff);
        UART_UartPutChar('\n');
        UART_UartPutChar('\r');
    }
    //Timer_OutputSpeed_ClearInterrupt(Timer_ChangeSpeed_INTR_MASK_TC);
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    // Initialize some variables
    current_rpm = 0;
    

    /* Start Everything Up */
    FanController_Start();
    UART_Start();
    //Timer_ChangeSpeed_Start();
    //Timer_OutputSpeed_Start();
    // ISR_Timer_StartEx(Timer_Isr_Handler);
    //ISR_OutSpeed_StartEx(Ouput_Speed_Isr_handler);

    char ch;
    int16 speed_buf = 0;
    int8 speed_idx = 0;
    for(;;)
    {   
        ch = UART_UartGetChar();
        if(ch == 'p'){print_speed = 0;}
        else if(ch == 's'){print_speed = 1;}
        else if (ch == ' ') {
            motor_speeds[speed_idx] = speed_buf * 2;
            speed_idx++;
            speed_buf = 0;
        }
        //else if(ch == '\r' && speed_buf > 2000 && speed_buf < 4350){
            // FanController_SetDesiredSpeed(1, speed_buf);
         //   speed_buf = 0;
         //   UART_UartPutChar('\n');
        //}
        else if(ch == '\r'){
            if (speed_idx == MOTOR_COUNT - 1) {
                motor_speeds[speed_idx] = speed_buf * 2;
            }
            write_motor_speed();
            speed_buf = 0;
            speed_idx = 0;
            UART_UartPutChar('\n');
        }
        else if(ch < 58 && ch > 47){
            speed_buf *= 10;
            speed_buf += ch - '0';
        }
        if(print_speed){
            print_all_speed(); 
        }
        else{
            UART_UartPutChar(ch);
        }
       

    }
}

/* [] END OF FILE */
