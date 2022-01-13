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

uint32_t current_rpm;


char uart_rpm_buff[4];
int16_t motor_speeds[4];
/* [] END OF FILE */
