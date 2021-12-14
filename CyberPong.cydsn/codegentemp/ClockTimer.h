/*******************************************************************************
* File Name: ClockTimer.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_ClockTimer_H)
#define CY_CLOCK_ClockTimer_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void ClockTimer_StartEx(uint32 alignClkDiv);
#define ClockTimer_Start() \
    ClockTimer_StartEx(ClockTimer__PA_DIV_ID)

#else

void ClockTimer_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void ClockTimer_Stop(void);

void ClockTimer_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 ClockTimer_GetDividerRegister(void);
uint8  ClockTimer_GetFractionalDividerRegister(void);

#define ClockTimer_Enable()                         ClockTimer_Start()
#define ClockTimer_Disable()                        ClockTimer_Stop()
#define ClockTimer_SetDividerRegister(clkDivider, reset)  \
    ClockTimer_SetFractionalDividerRegister((clkDivider), 0u)
#define ClockTimer_SetDivider(clkDivider)           ClockTimer_SetDividerRegister((clkDivider), 1u)
#define ClockTimer_SetDividerValue(clkDivider)      ClockTimer_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define ClockTimer_DIV_ID     ClockTimer__DIV_ID

#define ClockTimer_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define ClockTimer_CTRL_REG   (*(reg32 *)ClockTimer__CTRL_REGISTER)
#define ClockTimer_DIV_REG    (*(reg32 *)ClockTimer__DIV_REGISTER)

#define ClockTimer_CMD_DIV_SHIFT          (0u)
#define ClockTimer_CMD_PA_DIV_SHIFT       (8u)
#define ClockTimer_CMD_DISABLE_SHIFT      (30u)
#define ClockTimer_CMD_ENABLE_SHIFT       (31u)

#define ClockTimer_CMD_DISABLE_MASK       ((uint32)((uint32)1u << ClockTimer_CMD_DISABLE_SHIFT))
#define ClockTimer_CMD_ENABLE_MASK        ((uint32)((uint32)1u << ClockTimer_CMD_ENABLE_SHIFT))

#define ClockTimer_DIV_FRAC_MASK  (0x000000F8u)
#define ClockTimer_DIV_FRAC_SHIFT (3u)
#define ClockTimer_DIV_INT_MASK   (0xFFFFFF00u)
#define ClockTimer_DIV_INT_SHIFT  (8u)

#else 

#define ClockTimer_DIV_REG        (*(reg32 *)ClockTimer__REGISTER)
#define ClockTimer_ENABLE_REG     ClockTimer_DIV_REG
#define ClockTimer_DIV_FRAC_MASK  ClockTimer__FRAC_MASK
#define ClockTimer_DIV_FRAC_SHIFT (16u)
#define ClockTimer_DIV_INT_MASK   ClockTimer__DIVIDER_MASK
#define ClockTimer_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_ClockTimer_H) */

/* [] END OF FILE */
