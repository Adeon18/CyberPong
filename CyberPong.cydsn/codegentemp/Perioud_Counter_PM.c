/*******************************************************************************
* File Name: Perioud_Counter_PM.c
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

#include "Perioud_Counter.h"

static Perioud_Counter_BACKUP_STRUCT Perioud_Counter_backup;


/*******************************************************************************
* Function Name: Perioud_Counter_SaveConfig
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
void Perioud_Counter_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Perioud_Counter_Sleep
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
void Perioud_Counter_Sleep(void)
{
    if(0u != (Perioud_Counter_BLOCK_CONTROL_REG & Perioud_Counter_MASK))
    {
        Perioud_Counter_backup.enableState = 1u;
    }
    else
    {
        Perioud_Counter_backup.enableState = 0u;
    }

    Perioud_Counter_Stop();
    Perioud_Counter_SaveConfig();
}


/*******************************************************************************
* Function Name: Perioud_Counter_RestoreConfig
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
void Perioud_Counter_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Perioud_Counter_Wakeup
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
void Perioud_Counter_Wakeup(void)
{
    Perioud_Counter_RestoreConfig();

    if(0u != Perioud_Counter_backup.enableState)
    {
        Perioud_Counter_Enable();
    }
}


/* [] END OF FILE */
