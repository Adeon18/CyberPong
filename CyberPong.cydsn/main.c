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


int8 speed_idx;
int8 isr_triggered = 0;
int8 serving_enabled = 0;

int16_t motor_speeds[4];
int16 speed_buf;


void UART_print_string(char text[]) {
    // A utility function to print an array of characters with UART
    UART_UartPutChar('\n');
    UART_UartPutChar('\r');
    UART_UartPutString(text);
    UART_UartPutChar('\n');
    UART_UartPutChar('\r');
}


void print_all_speed() {
    /*
    Print all the speeds in a line through UART. Since we don't
    use dividers, we need to divide the speeds by 2
    */
    uint16_t current_rpm = 0;
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


void write_motor_speed(int16_t speeds[]) {
    // Write the speed of all motors(An option that limits the speed and the option to stop the motor)
    for (int i = 0; i < MOTOR_COUNT; i++) {
        if (speeds[i] > MIN_RPM && speeds[i] < MAX_RPM) {
            FanController_SetDesiredSpeed(i+1, 2*speeds[i]);
        } else if (speeds[i] == 0) {
            FanController_SetDesiredSpeed(i+1, 0);
        } else {
            continue;
        }
    }
}

void handle_UART_input(char inp_ch) {
    /* 
    Main input function.
    Responsible for setting modes and writing speeds.
    Operates with most of the global variables.
    */
    
    if (manual_control_flag) {
        if(inp_ch == 'p'){
            print_speed_flag = 0;
            UART_print_string("Set The Speeds:");
        }
        else if(inp_ch == 's'){
            print_speed_flag = 1;
        }
        else if(inp_ch == 'x') {
            UART_print_string("Enabled Serving:");
            serving_enabled = 1;
            Pin_Serve_Write(1);
        }
        else if (inp_ch == 'z') {
            UART_print_string("Disabled Serving:");
            serving_enabled = 0;
            Pin_Serve_Write(0);
        }
        else if (inp_ch == ' ') {
            motor_speeds[speed_idx] = speed_buf;
            speed_idx++;
            speed_buf = 0;
        }
        else if(inp_ch == '\r'){
            if (speed_idx == MOTOR_COUNT - 1) {
                motor_speeds[speed_idx] = speed_buf;
            }
            write_motor_speed(motor_speeds);
            speed_buf = 0;
            speed_idx = 0;
            UART_UartPutChar('\n');
        }
        else if(inp_ch < HIGHER_NUM_BORDER && inp_ch > LOWER_NUM_BORDER){
            speed_buf *= 10;
            speed_buf += inp_ch - '0';
        }
    }
}


CY_ISR (Ball_Trigger_Handler) {
    isr_triggered = 1;
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Start Everything Up */
    FanController_Start();
    UART_Start();
    ISR_Ball_Trigger_StartEx( Ball_Trigger_Handler );

    char ch;
    speed_buf = 0;
    speed_idx = 0;
    // By default we don't print any speed
    print_speed_flag = 0;
    // Manual control is enabled by default
    manual_control_flag = 1;
    
    for(;;)
    {   
        ch = UART_UartGetChar();
        if (ch == 'a') {
            // Automatically disable printing speed on automatic mode.
            manual_control_flag = 0;
            print_speed_flag = 0;
            UART_print_string("Automatic Control Activated:");
            UART_print_string("Enabled Serving:");
            serving_enabled = 1;
            Pin_Serve_Write(1);
        } else if (ch == 'm') {
            manual_control_flag = 1;
            UART_print_string("Manual Control Activated:");
        } else {
            handle_UART_input(ch);
        }

        if(print_speed_flag){
            CyDelay(PRINT_DATA_DELAY);
            print_all_speed(); 
        }
        else{
            UART_UartPutChar(ch);
        }
        
        if (isr_triggered) {
            Pin_Serve_Write(0);
            CyDelay(250);
            isr_triggered = 0;
            if (serving_enabled) {
                Pin_Serve_Write(1);
            }
            if (!manual_control_flag) {
                UART_print_string("New Config");
                print_all_speed(); 
                char debug[20];
                sprintf(debug, "%d %d %d %d", speed_configs[conf_iterator][0], speed_configs[conf_iterator][1], speed_configs[conf_iterator][2], speed_configs[conf_iterator][3]);
                UART_print_string(debug);
                //
                write_motor_speed(speed_configs[conf_iterator]);
                conf_iterator++;
                if (conf_iterator > conf_size - 1) {
                    conf_iterator = 0;
                }
            }
        }
    }
}

/* [] END OF FILE */
