/*******************************************************************************
* File Name: FanController_FW_PWM1_PM.c
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

#include "FanController_FW_PWM1.h"

static FanController_FW_PWM1_BACKUP_STRUCT FanController_FW_PWM1_backup;


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SaveConfig
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
void FanController_FW_PWM1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_Sleep
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
void FanController_FW_PWM1_Sleep(void)
{
    if(0u != (FanController_FW_PWM1_BLOCK_CONTROL_REG & FanController_FW_PWM1_MASK))
    {
        FanController_FW_PWM1_backup.enableState = 1u;
    }
    else
    {
        FanController_FW_PWM1_backup.enableState = 0u;
    }

    FanController_FW_PWM1_Stop();
    FanController_FW_PWM1_SaveConfig();
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_RestoreConfig
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
void FanController_FW_PWM1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_Wakeup
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
void FanController_FW_PWM1_Wakeup(void)
{
    FanController_FW_PWM1_RestoreConfig();

    if(0u != FanController_FW_PWM1_backup.enableState)
    {
        FanController_FW_PWM1_Enable();
    }
}


/* [] END OF FILE */
