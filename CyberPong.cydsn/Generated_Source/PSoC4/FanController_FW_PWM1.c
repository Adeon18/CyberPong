/*******************************************************************************
* File Name: FanController_FW_PWM1.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the FanController_FW_PWM1
*  component
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

uint8 FanController_FW_PWM1_initVar = 0u;


/*******************************************************************************
* Function Name: FanController_FW_PWM1_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default FanController_FW_PWM1 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (FanController_FW_PWM1__QUAD == FanController_FW_PWM1_CONFIG)
        FanController_FW_PWM1_CONTROL_REG = FanController_FW_PWM1_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        FanController_FW_PWM1_TRIG_CONTROL1_REG  = FanController_FW_PWM1_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        FanController_FW_PWM1_SetInterruptMode(FanController_FW_PWM1_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        FanController_FW_PWM1_SetCounterMode(FanController_FW_PWM1_COUNT_DOWN);
        FanController_FW_PWM1_WritePeriod(FanController_FW_PWM1_QUAD_PERIOD_INIT_VALUE);
        FanController_FW_PWM1_WriteCounter(FanController_FW_PWM1_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (FanController_FW_PWM1__QUAD == FanController_FW_PWM1_CONFIG) */

    #if (FanController_FW_PWM1__TIMER == FanController_FW_PWM1_CONFIG)
        FanController_FW_PWM1_CONTROL_REG = FanController_FW_PWM1_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        FanController_FW_PWM1_TRIG_CONTROL1_REG  = FanController_FW_PWM1_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        FanController_FW_PWM1_SetInterruptMode(FanController_FW_PWM1_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        FanController_FW_PWM1_WritePeriod(FanController_FW_PWM1_TC_PERIOD_VALUE );

        #if (FanController_FW_PWM1__COMPARE == FanController_FW_PWM1_TC_COMP_CAP_MODE)
            FanController_FW_PWM1_WriteCompare(FanController_FW_PWM1_TC_COMPARE_VALUE);

            #if (1u == FanController_FW_PWM1_TC_COMPARE_SWAP)
                FanController_FW_PWM1_SetCompareSwap(1u);
                FanController_FW_PWM1_WriteCompareBuf(FanController_FW_PWM1_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == FanController_FW_PWM1_TC_COMPARE_SWAP) */
        #endif  /* (FanController_FW_PWM1__COMPARE == FanController_FW_PWM1_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (FanController_FW_PWM1_CY_TCPWM_V2 && FanController_FW_PWM1_TIMER_UPDOWN_CNT_USED && !FanController_FW_PWM1_CY_TCPWM_4000)
            FanController_FW_PWM1_WriteCounter(1u);
        #elif(FanController_FW_PWM1__COUNT_DOWN == FanController_FW_PWM1_TC_COUNTER_MODE)
            FanController_FW_PWM1_WriteCounter(FanController_FW_PWM1_TC_PERIOD_VALUE);
        #else
            FanController_FW_PWM1_WriteCounter(0u);
        #endif /* (FanController_FW_PWM1_CY_TCPWM_V2 && FanController_FW_PWM1_TIMER_UPDOWN_CNT_USED && !FanController_FW_PWM1_CY_TCPWM_4000) */
    #endif  /* (FanController_FW_PWM1__TIMER == FanController_FW_PWM1_CONFIG) */

    #if (FanController_FW_PWM1__PWM_SEL == FanController_FW_PWM1_CONFIG)
        FanController_FW_PWM1_CONTROL_REG = FanController_FW_PWM1_CTRL_PWM_BASE_CONFIG;

        #if (FanController_FW_PWM1__PWM_PR == FanController_FW_PWM1_PWM_MODE)
            FanController_FW_PWM1_CONTROL_REG |= FanController_FW_PWM1_CTRL_PWM_RUN_MODE;
            FanController_FW_PWM1_WriteCounter(FanController_FW_PWM1_PWM_PR_INIT_VALUE);
        #else
            FanController_FW_PWM1_CONTROL_REG |= FanController_FW_PWM1_CTRL_PWM_ALIGN | FanController_FW_PWM1_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (FanController_FW_PWM1_CY_TCPWM_V2 && FanController_FW_PWM1_PWM_UPDOWN_CNT_USED && !FanController_FW_PWM1_CY_TCPWM_4000)
                FanController_FW_PWM1_WriteCounter(1u);
            #elif (FanController_FW_PWM1__RIGHT == FanController_FW_PWM1_PWM_ALIGN)
                FanController_FW_PWM1_WriteCounter(FanController_FW_PWM1_PWM_PERIOD_VALUE);
            #else 
                FanController_FW_PWM1_WriteCounter(0u);
            #endif  /* (FanController_FW_PWM1_CY_TCPWM_V2 && FanController_FW_PWM1_PWM_UPDOWN_CNT_USED && !FanController_FW_PWM1_CY_TCPWM_4000) */
        #endif  /* (FanController_FW_PWM1__PWM_PR == FanController_FW_PWM1_PWM_MODE) */

        #if (FanController_FW_PWM1__PWM_DT == FanController_FW_PWM1_PWM_MODE)
            FanController_FW_PWM1_CONTROL_REG |= FanController_FW_PWM1_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (FanController_FW_PWM1__PWM_DT == FanController_FW_PWM1_PWM_MODE) */

        #if (FanController_FW_PWM1__PWM == FanController_FW_PWM1_PWM_MODE)
            FanController_FW_PWM1_CONTROL_REG |= FanController_FW_PWM1_CTRL_PWM_PRESCALER;
        #endif  /* (FanController_FW_PWM1__PWM == FanController_FW_PWM1_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        FanController_FW_PWM1_TRIG_CONTROL1_REG  = FanController_FW_PWM1_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        FanController_FW_PWM1_SetInterruptMode(FanController_FW_PWM1_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (FanController_FW_PWM1__PWM_PR == FanController_FW_PWM1_PWM_MODE)
            FanController_FW_PWM1_TRIG_CONTROL2_REG =
                    (FanController_FW_PWM1_CC_MATCH_NO_CHANGE    |
                    FanController_FW_PWM1_OVERLOW_NO_CHANGE      |
                    FanController_FW_PWM1_UNDERFLOW_NO_CHANGE);
        #else
            #if (FanController_FW_PWM1__LEFT == FanController_FW_PWM1_PWM_ALIGN)
                FanController_FW_PWM1_TRIG_CONTROL2_REG = FanController_FW_PWM1_PWM_MODE_LEFT;
            #endif  /* ( FanController_FW_PWM1_PWM_LEFT == FanController_FW_PWM1_PWM_ALIGN) */

            #if (FanController_FW_PWM1__RIGHT == FanController_FW_PWM1_PWM_ALIGN)
                FanController_FW_PWM1_TRIG_CONTROL2_REG = FanController_FW_PWM1_PWM_MODE_RIGHT;
            #endif  /* ( FanController_FW_PWM1_PWM_RIGHT == FanController_FW_PWM1_PWM_ALIGN) */

            #if (FanController_FW_PWM1__CENTER == FanController_FW_PWM1_PWM_ALIGN)
                FanController_FW_PWM1_TRIG_CONTROL2_REG = FanController_FW_PWM1_PWM_MODE_CENTER;
            #endif  /* ( FanController_FW_PWM1_PWM_CENTER == FanController_FW_PWM1_PWM_ALIGN) */

            #if (FanController_FW_PWM1__ASYMMETRIC == FanController_FW_PWM1_PWM_ALIGN)
                FanController_FW_PWM1_TRIG_CONTROL2_REG = FanController_FW_PWM1_PWM_MODE_ASYM;
            #endif  /* (FanController_FW_PWM1__ASYMMETRIC == FanController_FW_PWM1_PWM_ALIGN) */
        #endif  /* (FanController_FW_PWM1__PWM_PR == FanController_FW_PWM1_PWM_MODE) */

        /* Set other values from customizer */
        FanController_FW_PWM1_WritePeriod(FanController_FW_PWM1_PWM_PERIOD_VALUE );
        FanController_FW_PWM1_WriteCompare(FanController_FW_PWM1_PWM_COMPARE_VALUE);

        #if (1u == FanController_FW_PWM1_PWM_COMPARE_SWAP)
            FanController_FW_PWM1_SetCompareSwap(1u);
            FanController_FW_PWM1_WriteCompareBuf(FanController_FW_PWM1_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == FanController_FW_PWM1_PWM_COMPARE_SWAP) */

        #if (1u == FanController_FW_PWM1_PWM_PERIOD_SWAP)
            FanController_FW_PWM1_SetPeriodSwap(1u);
            FanController_FW_PWM1_WritePeriodBuf(FanController_FW_PWM1_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == FanController_FW_PWM1_PWM_PERIOD_SWAP) */
    #endif  /* (FanController_FW_PWM1__PWM_SEL == FanController_FW_PWM1_CONFIG) */
    
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_Enable
********************************************************************************
*
* Summary:
*  Enables the FanController_FW_PWM1.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    FanController_FW_PWM1_BLOCK_CONTROL_REG |= FanController_FW_PWM1_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (FanController_FW_PWM1__PWM_SEL == FanController_FW_PWM1_CONFIG)
        #if (0u == FanController_FW_PWM1_PWM_START_SIGNAL_PRESENT)
            FanController_FW_PWM1_TriggerCommand(FanController_FW_PWM1_MASK, FanController_FW_PWM1_CMD_START);
        #endif /* (0u == FanController_FW_PWM1_PWM_START_SIGNAL_PRESENT) */
    #endif /* (FanController_FW_PWM1__PWM_SEL == FanController_FW_PWM1_CONFIG) */

    #if (FanController_FW_PWM1__TIMER == FanController_FW_PWM1_CONFIG)
        #if (0u == FanController_FW_PWM1_TC_START_SIGNAL_PRESENT)
            FanController_FW_PWM1_TriggerCommand(FanController_FW_PWM1_MASK, FanController_FW_PWM1_CMD_START);
        #endif /* (0u == FanController_FW_PWM1_TC_START_SIGNAL_PRESENT) */
    #endif /* (FanController_FW_PWM1__TIMER == FanController_FW_PWM1_CONFIG) */
    
    #if (FanController_FW_PWM1__QUAD == FanController_FW_PWM1_CONFIG)
        #if (0u != FanController_FW_PWM1_QUAD_AUTO_START)
            FanController_FW_PWM1_TriggerCommand(FanController_FW_PWM1_MASK, FanController_FW_PWM1_CMD_RELOAD);
        #endif /* (0u != FanController_FW_PWM1_QUAD_AUTO_START) */
    #endif  /* (FanController_FW_PWM1__QUAD == FanController_FW_PWM1_CONFIG) */
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_Start
********************************************************************************
*
* Summary:
*  Initializes the FanController_FW_PWM1 with default customizer
*  values when called the first time and enables the FanController_FW_PWM1.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  FanController_FW_PWM1_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time FanController_FW_PWM1_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the FanController_FW_PWM1_Start() routine.
*
*******************************************************************************/
void FanController_FW_PWM1_Start(void)
{
    if (0u == FanController_FW_PWM1_initVar)
    {
        FanController_FW_PWM1_Init();
        FanController_FW_PWM1_initVar = 1u;
    }

    FanController_FW_PWM1_Enable();
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_Stop
********************************************************************************
*
* Summary:
*  Disables the FanController_FW_PWM1.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_BLOCK_CONTROL_REG &= (uint32)~FanController_FW_PWM1_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the FanController_FW_PWM1. This function is used when
*  configured as a generic FanController_FW_PWM1 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the FanController_FW_PWM1 to operate in
*   Values:
*   - FanController_FW_PWM1_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - FanController_FW_PWM1_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - FanController_FW_PWM1_MODE_QUAD - Quadrature decoder
*         - FanController_FW_PWM1_MODE_PWM - PWM
*         - FanController_FW_PWM1_MODE_PWM_DT - PWM with dead time
*         - FanController_FW_PWM1_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_CONTROL_REG &= (uint32)~FanController_FW_PWM1_MODE_MASK;
    FanController_FW_PWM1_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - FanController_FW_PWM1_MODE_X1 - Counts on phi 1 rising
*         - FanController_FW_PWM1_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - FanController_FW_PWM1_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_CONTROL_REG &= (uint32)~FanController_FW_PWM1_QUAD_MODE_MASK;
    FanController_FW_PWM1_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - FanController_FW_PWM1_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - FanController_FW_PWM1_PRESCALE_DIVBY2    - Divide by 2
*         - FanController_FW_PWM1_PRESCALE_DIVBY4    - Divide by 4
*         - FanController_FW_PWM1_PRESCALE_DIVBY8    - Divide by 8
*         - FanController_FW_PWM1_PRESCALE_DIVBY16   - Divide by 16
*         - FanController_FW_PWM1_PRESCALE_DIVBY32   - Divide by 32
*         - FanController_FW_PWM1_PRESCALE_DIVBY64   - Divide by 64
*         - FanController_FW_PWM1_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_CONTROL_REG &= (uint32)~FanController_FW_PWM1_PRESCALER_MASK;
    FanController_FW_PWM1_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the FanController_FW_PWM1 runs
*  continuously or stops when terminal count is reached.  By default the
*  FanController_FW_PWM1 operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_CONTROL_REG &= (uint32)~FanController_FW_PWM1_ONESHOT_MASK;
    FanController_FW_PWM1_CONTROL_REG |= ((uint32)((oneShotEnable & FanController_FW_PWM1_1BIT_MASK) <<
                                                               FanController_FW_PWM1_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetPWMMode(uint32 modeMask)
{
    FanController_FW_PWM1_TRIG_CONTROL2_REG = (modeMask & FanController_FW_PWM1_6BIT_MASK);
}



/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_CONTROL_REG &= (uint32)~FanController_FW_PWM1_PWM_SYNC_KILL_MASK;
    FanController_FW_PWM1_CONTROL_REG |= ((uint32)((syncKillEnable & FanController_FW_PWM1_1BIT_MASK)  <<
                                               FanController_FW_PWM1_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_CONTROL_REG &= (uint32)~FanController_FW_PWM1_PWM_STOP_KILL_MASK;
    FanController_FW_PWM1_CONTROL_REG |= ((uint32)((stopOnKillEnable & FanController_FW_PWM1_1BIT_MASK)  <<
                                                         FanController_FW_PWM1_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_CONTROL_REG &= (uint32)~FanController_FW_PWM1_PRESCALER_MASK;
    FanController_FW_PWM1_CONTROL_REG |= ((uint32)((deadTime & FanController_FW_PWM1_8BIT_MASK) <<
                                                          FanController_FW_PWM1_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - FanController_FW_PWM1_INVERT_LINE   - Inverts the line output
*         - FanController_FW_PWM1_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_CONTROL_REG &= (uint32)~FanController_FW_PWM1_INV_OUT_MASK;
    FanController_FW_PWM1_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: FanController_FW_PWM1_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_WriteCounter(uint32 count)
{
    FanController_FW_PWM1_COUNTER_REG = (count & FanController_FW_PWM1_16BIT_MASK);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 FanController_FW_PWM1_ReadCounter(void)
{
    return (FanController_FW_PWM1_COUNTER_REG & FanController_FW_PWM1_16BIT_MASK);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - FanController_FW_PWM1_COUNT_UP       - Counts up
*     - FanController_FW_PWM1_COUNT_DOWN     - Counts down
*     - FanController_FW_PWM1_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - FanController_FW_PWM1_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_CONTROL_REG &= (uint32)~FanController_FW_PWM1_UPDOWN_MASK;
    FanController_FW_PWM1_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_WritePeriod(uint32 period)
{
    FanController_FW_PWM1_PERIOD_REG = (period & FanController_FW_PWM1_16BIT_MASK);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 FanController_FW_PWM1_ReadPeriod(void)
{
    return (FanController_FW_PWM1_PERIOD_REG & FanController_FW_PWM1_16BIT_MASK);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_CONTROL_REG &= (uint32)~FanController_FW_PWM1_RELOAD_CC_MASK;
    FanController_FW_PWM1_CONTROL_REG |= (swapEnable & FanController_FW_PWM1_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_WritePeriodBuf(uint32 periodBuf)
{
    FanController_FW_PWM1_PERIOD_BUF_REG = (periodBuf & FanController_FW_PWM1_16BIT_MASK);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 FanController_FW_PWM1_ReadPeriodBuf(void)
{
    return (FanController_FW_PWM1_PERIOD_BUF_REG & FanController_FW_PWM1_16BIT_MASK);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_CONTROL_REG &= (uint32)~FanController_FW_PWM1_RELOAD_PERIOD_MASK;
    FanController_FW_PWM1_CONTROL_REG |= ((uint32)((swapEnable & FanController_FW_PWM1_1BIT_MASK) <<
                                                            FanController_FW_PWM1_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void FanController_FW_PWM1_WriteCompare(uint32 compare)
{
    #if (FanController_FW_PWM1_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (FanController_FW_PWM1_CY_TCPWM_4000) */

    #if (FanController_FW_PWM1_CY_TCPWM_4000)
        currentMode = ((FanController_FW_PWM1_CONTROL_REG & FanController_FW_PWM1_UPDOWN_MASK) >> FanController_FW_PWM1_UPDOWN_SHIFT);

        if (((uint32)FanController_FW_PWM1__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)FanController_FW_PWM1__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (FanController_FW_PWM1_CY_TCPWM_4000) */
    
    FanController_FW_PWM1_COMP_CAP_REG = (compare & FanController_FW_PWM1_16BIT_MASK);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 FanController_FW_PWM1_ReadCompare(void)
{
    #if (FanController_FW_PWM1_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (FanController_FW_PWM1_CY_TCPWM_4000) */

    #if (FanController_FW_PWM1_CY_TCPWM_4000)
        currentMode = ((FanController_FW_PWM1_CONTROL_REG & FanController_FW_PWM1_UPDOWN_MASK) >> FanController_FW_PWM1_UPDOWN_SHIFT);
        
        regVal = FanController_FW_PWM1_COMP_CAP_REG;
        
        if (((uint32)FanController_FW_PWM1__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)FanController_FW_PWM1__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & FanController_FW_PWM1_16BIT_MASK);
    #else
        return (FanController_FW_PWM1_COMP_CAP_REG & FanController_FW_PWM1_16BIT_MASK);
    #endif /* (FanController_FW_PWM1_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void FanController_FW_PWM1_WriteCompareBuf(uint32 compareBuf)
{
    #if (FanController_FW_PWM1_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (FanController_FW_PWM1_CY_TCPWM_4000) */

    #if (FanController_FW_PWM1_CY_TCPWM_4000)
        currentMode = ((FanController_FW_PWM1_CONTROL_REG & FanController_FW_PWM1_UPDOWN_MASK) >> FanController_FW_PWM1_UPDOWN_SHIFT);

        if (((uint32)FanController_FW_PWM1__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)FanController_FW_PWM1__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (FanController_FW_PWM1_CY_TCPWM_4000) */
    
    FanController_FW_PWM1_COMP_CAP_BUF_REG = (compareBuf & FanController_FW_PWM1_16BIT_MASK);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 FanController_FW_PWM1_ReadCompareBuf(void)
{
    #if (FanController_FW_PWM1_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (FanController_FW_PWM1_CY_TCPWM_4000) */

    #if (FanController_FW_PWM1_CY_TCPWM_4000)
        currentMode = ((FanController_FW_PWM1_CONTROL_REG & FanController_FW_PWM1_UPDOWN_MASK) >> FanController_FW_PWM1_UPDOWN_SHIFT);

        regVal = FanController_FW_PWM1_COMP_CAP_BUF_REG;
        
        if (((uint32)FanController_FW_PWM1__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)FanController_FW_PWM1__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & FanController_FW_PWM1_16BIT_MASK);
    #else
        return (FanController_FW_PWM1_COMP_CAP_BUF_REG & FanController_FW_PWM1_16BIT_MASK);
    #endif /* (FanController_FW_PWM1_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 FanController_FW_PWM1_ReadCapture(void)
{
    return (FanController_FW_PWM1_COMP_CAP_REG & FanController_FW_PWM1_16BIT_MASK);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 FanController_FW_PWM1_ReadCaptureBuf(void)
{
    return (FanController_FW_PWM1_COMP_CAP_BUF_REG & FanController_FW_PWM1_16BIT_MASK);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - FanController_FW_PWM1_TRIG_LEVEL     - Level
*     - FanController_FW_PWM1_TRIG_RISING    - Rising edge
*     - FanController_FW_PWM1_TRIG_FALLING   - Falling edge
*     - FanController_FW_PWM1_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_TRIG_CONTROL1_REG &= (uint32)~FanController_FW_PWM1_CAPTURE_MASK;
    FanController_FW_PWM1_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - FanController_FW_PWM1_TRIG_LEVEL     - Level
*     - FanController_FW_PWM1_TRIG_RISING    - Rising edge
*     - FanController_FW_PWM1_TRIG_FALLING   - Falling edge
*     - FanController_FW_PWM1_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_TRIG_CONTROL1_REG &= (uint32)~FanController_FW_PWM1_RELOAD_MASK;
    FanController_FW_PWM1_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << FanController_FW_PWM1_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - FanController_FW_PWM1_TRIG_LEVEL     - Level
*     - FanController_FW_PWM1_TRIG_RISING    - Rising edge
*     - FanController_FW_PWM1_TRIG_FALLING   - Falling edge
*     - FanController_FW_PWM1_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_TRIG_CONTROL1_REG &= (uint32)~FanController_FW_PWM1_START_MASK;
    FanController_FW_PWM1_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << FanController_FW_PWM1_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - FanController_FW_PWM1_TRIG_LEVEL     - Level
*     - FanController_FW_PWM1_TRIG_RISING    - Rising edge
*     - FanController_FW_PWM1_TRIG_FALLING   - Falling edge
*     - FanController_FW_PWM1_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_TRIG_CONTROL1_REG &= (uint32)~FanController_FW_PWM1_STOP_MASK;
    FanController_FW_PWM1_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << FanController_FW_PWM1_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - FanController_FW_PWM1_TRIG_LEVEL     - Level
*     - FanController_FW_PWM1_TRIG_RISING    - Rising edge
*     - FanController_FW_PWM1_TRIG_FALLING   - Falling edge
*     - FanController_FW_PWM1_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_TRIG_CONTROL1_REG &= (uint32)~FanController_FW_PWM1_COUNT_MASK;
    FanController_FW_PWM1_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << FanController_FW_PWM1_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - FanController_FW_PWM1_CMD_CAPTURE    - Trigger Capture/Switch command
*     - FanController_FW_PWM1_CMD_RELOAD     - Trigger Reload/Index command
*     - FanController_FW_PWM1_CMD_STOP       - Trigger Stop/Kill command
*     - FanController_FW_PWM1_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    FanController_FW_PWM1_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the FanController_FW_PWM1.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - FanController_FW_PWM1_STATUS_DOWN    - Set if counting down
*     - FanController_FW_PWM1_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 FanController_FW_PWM1_ReadStatus(void)
{
    return ((FanController_FW_PWM1_STATUS_REG >> FanController_FW_PWM1_RUNNING_STATUS_SHIFT) |
            (FanController_FW_PWM1_STATUS_REG & FanController_FW_PWM1_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - FanController_FW_PWM1_INTR_MASK_TC       - Terminal count mask
*     - FanController_FW_PWM1_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetInterruptMode(uint32 interruptMask)
{
    FanController_FW_PWM1_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - FanController_FW_PWM1_INTR_MASK_TC       - Terminal count mask
*     - FanController_FW_PWM1_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 FanController_FW_PWM1_GetInterruptSourceMasked(void)
{
    return (FanController_FW_PWM1_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - FanController_FW_PWM1_INTR_MASK_TC       - Terminal count mask
*     - FanController_FW_PWM1_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 FanController_FW_PWM1_GetInterruptSource(void)
{
    return (FanController_FW_PWM1_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - FanController_FW_PWM1_INTR_MASK_TC       - Terminal count mask
*     - FanController_FW_PWM1_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_ClearInterrupt(uint32 interruptMask)
{
    FanController_FW_PWM1_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: FanController_FW_PWM1_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - FanController_FW_PWM1_INTR_MASK_TC       - Terminal count mask
*     - FanController_FW_PWM1_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void FanController_FW_PWM1_SetInterrupt(uint32 interruptMask)
{
    FanController_FW_PWM1_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
