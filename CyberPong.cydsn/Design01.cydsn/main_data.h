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

uint32_t signals_per_time_unit;
uint32_t period_per_window;
uint32_t indx;
uint32_t period_per_spin;

uint32_t current_rpm;
char uart_rpm_buff[4];
char uart_per_buff[4];
/* [] END OF FILE */
