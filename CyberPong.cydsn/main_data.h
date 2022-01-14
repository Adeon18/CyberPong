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

#include <stdint.h>

#define MOTOR_COUNT 4

#define MAX_RPM 4350
#define MIN_RPM 2000

#define LOWER_NUM_BORDER 47
#define HIGHER_NUM_BORDER 58

#define PRINT_DATA_DELAY 50

// Defines whether the speed is printed during manual control
int8_t print_speed_flag;
// Defines whether the speed is controlled manually within UART or automatically.
int8_t manual_control_flag;

char uart_rpm_buff[4];
int16_t motor_speeds[4];
/* [] END OF FILE */
