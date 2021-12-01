/*******************************************************************************
* File Name: FanController_DataSend.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_FanController_DataSend_H)
#define CY_ISR_FanController_DataSend_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void FanController_DataSend_Start(void);
void FanController_DataSend_StartEx(cyisraddress address);
void FanController_DataSend_Stop(void);

CY_ISR_PROTO(FanController_DataSend_Interrupt);

void FanController_DataSend_SetVector(cyisraddress address);
cyisraddress FanController_DataSend_GetVector(void);

void FanController_DataSend_SetPriority(uint8 priority);
uint8 FanController_DataSend_GetPriority(void);

void FanController_DataSend_Enable(void);
uint8 FanController_DataSend_GetState(void);
void FanController_DataSend_Disable(void);

void FanController_DataSend_SetPending(void);
void FanController_DataSend_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the FanController_DataSend ISR. */
#define FanController_DataSend_INTC_VECTOR            ((reg32 *) FanController_DataSend__INTC_VECT)

/* Address of the FanController_DataSend ISR priority. */
#define FanController_DataSend_INTC_PRIOR             ((reg32 *) FanController_DataSend__INTC_PRIOR_REG)

/* Priority of the FanController_DataSend interrupt. */
#define FanController_DataSend_INTC_PRIOR_NUMBER      FanController_DataSend__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable FanController_DataSend interrupt. */
#define FanController_DataSend_INTC_SET_EN            ((reg32 *) FanController_DataSend__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the FanController_DataSend interrupt. */
#define FanController_DataSend_INTC_CLR_EN            ((reg32 *) FanController_DataSend__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the FanController_DataSend interrupt state to pending. */
#define FanController_DataSend_INTC_SET_PD            ((reg32 *) FanController_DataSend__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the FanController_DataSend interrupt. */
#define FanController_DataSend_INTC_CLR_PD            ((reg32 *) FanController_DataSend__INTC_CLR_PD_REG)



#endif /* CY_ISR_FanController_DataSend_H */


/* [] END OF FILE */
