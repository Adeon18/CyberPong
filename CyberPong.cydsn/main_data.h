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
#define MIN_RPM 1000

#define LOWER_NUM_BORDER 47
#define HIGHER_NUM_BORDER 58

#define PRINT_DATA_DELAY 3
#define SERVE_DELAY 250     // Serve delay in miliseconds

// Defines whether the speed is printed during manual control
int8_t print_speed_flag;
// Defines whether the speed is controlled manually within UART or automatically.
int8_t manual_control_flag;

char uart_rpm_buff[4];

int16_t speed_configs[4][4] = {{4000, 0, 4000, 4000},   // Left Spin
                               {0, 4000, 4000, 4000},   // Right Spin
                               {4000, 4000, 0, 4000},   // BackWards Spin
                               {4000, 4000, 4000, 0}};  // TopSpin
int16_t conf_size = 4;
int8_t conf_iterator = 0;

/* [] END OF FILE */
