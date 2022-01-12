/*******************************************************************************
* File Name: FanController_FW_PWM4_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "FanController_FW_PWM4.h"

static FanController_FW_PWM4_BACKUP_STRUCT FanController_FW_PWM4_backup;


/*******************************************************************************
* Function Name: FanController_FW_PWM4_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM4_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: FanController_FW_PWM4_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM4_Sleep(void)
{
    if(0u != (FanController_FW_PWM4_BLOCK_CONTROL_REG & FanController_FW_PWM4_MASK))
    {
        FanController_FW_PWM4_backup.enableState = 1u;
    }
    else
    {
        FanController_FW_PWM4_backup.enableState = 0u;
    }

    FanController_FW_PWM4_Stop();
    FanController_FW_PWM4_SaveConfig();
}


/*******************************************************************************
* Function Name: FanController_FW_PWM4_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM4_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: FanController_FW_PWM4_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM4_Wakeup(void)
{
    FanController_FW_PWM4_RestoreConfig();

    if(0u != FanController_FW_PWM4_backup.enableState)
    {
        FanController_FW_PWM4_Enable();
    }
}


/* [] END OF FILE */
