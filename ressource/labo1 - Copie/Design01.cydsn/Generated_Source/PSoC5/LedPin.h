/*******************************************************************************
* File Name: LedPin.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LedPin_H) /* Pins LedPin_H */
#define CY_PINS_LedPin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LedPin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LedPin__PORT == 15 && ((LedPin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LedPin_Write(uint8 value);
void    LedPin_SetDriveMode(uint8 mode);
uint8   LedPin_ReadDataReg(void);
uint8   LedPin_Read(void);
void    LedPin_SetInterruptMode(uint16 position, uint16 mode);
uint8   LedPin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LedPin_SetDriveMode() function.
     *  @{
     */
        #define LedPin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LedPin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LedPin_DM_RES_UP          PIN_DM_RES_UP
        #define LedPin_DM_RES_DWN         PIN_DM_RES_DWN
        #define LedPin_DM_OD_LO           PIN_DM_OD_LO
        #define LedPin_DM_OD_HI           PIN_DM_OD_HI
        #define LedPin_DM_STRONG          PIN_DM_STRONG
        #define LedPin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LedPin_MASK               LedPin__MASK
#define LedPin_SHIFT              LedPin__SHIFT
#define LedPin_WIDTH              1u

/* Interrupt constants */
#if defined(LedPin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LedPin_SetInterruptMode() function.
     *  @{
     */
        #define LedPin_INTR_NONE      (uint16)(0x0000u)
        #define LedPin_INTR_RISING    (uint16)(0x0001u)
        #define LedPin_INTR_FALLING   (uint16)(0x0002u)
        #define LedPin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LedPin_INTR_MASK      (0x01u) 
#endif /* (LedPin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LedPin_PS                     (* (reg8 *) LedPin__PS)
/* Data Register */
#define LedPin_DR                     (* (reg8 *) LedPin__DR)
/* Port Number */
#define LedPin_PRT_NUM                (* (reg8 *) LedPin__PRT) 
/* Connect to Analog Globals */                                                  
#define LedPin_AG                     (* (reg8 *) LedPin__AG)                       
/* Analog MUX bux enable */
#define LedPin_AMUX                   (* (reg8 *) LedPin__AMUX) 
/* Bidirectional Enable */                                                        
#define LedPin_BIE                    (* (reg8 *) LedPin__BIE)
/* Bit-mask for Aliased Register Access */
#define LedPin_BIT_MASK               (* (reg8 *) LedPin__BIT_MASK)
/* Bypass Enable */
#define LedPin_BYP                    (* (reg8 *) LedPin__BYP)
/* Port wide control signals */                                                   
#define LedPin_CTL                    (* (reg8 *) LedPin__CTL)
/* Drive Modes */
#define LedPin_DM0                    (* (reg8 *) LedPin__DM0) 
#define LedPin_DM1                    (* (reg8 *) LedPin__DM1)
#define LedPin_DM2                    (* (reg8 *) LedPin__DM2) 
/* Input Buffer Disable Override */
#define LedPin_INP_DIS                (* (reg8 *) LedPin__INP_DIS)
/* LCD Common or Segment Drive */
#define LedPin_LCD_COM_SEG            (* (reg8 *) LedPin__LCD_COM_SEG)
/* Enable Segment LCD */
#define LedPin_LCD_EN                 (* (reg8 *) LedPin__LCD_EN)
/* Slew Rate Control */
#define LedPin_SLW                    (* (reg8 *) LedPin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LedPin_PRTDSI__CAPS_SEL       (* (reg8 *) LedPin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LedPin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LedPin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LedPin_PRTDSI__OE_SEL0        (* (reg8 *) LedPin__PRTDSI__OE_SEL0) 
#define LedPin_PRTDSI__OE_SEL1        (* (reg8 *) LedPin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LedPin_PRTDSI__OUT_SEL0       (* (reg8 *) LedPin__PRTDSI__OUT_SEL0) 
#define LedPin_PRTDSI__OUT_SEL1       (* (reg8 *) LedPin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LedPin_PRTDSI__SYNC_OUT       (* (reg8 *) LedPin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LedPin__SIO_CFG)
    #define LedPin_SIO_HYST_EN        (* (reg8 *) LedPin__SIO_HYST_EN)
    #define LedPin_SIO_REG_HIFREQ     (* (reg8 *) LedPin__SIO_REG_HIFREQ)
    #define LedPin_SIO_CFG            (* (reg8 *) LedPin__SIO_CFG)
    #define LedPin_SIO_DIFF           (* (reg8 *) LedPin__SIO_DIFF)
#endif /* (LedPin__SIO_CFG) */

/* Interrupt Registers */
#if defined(LedPin__INTSTAT)
    #define LedPin_INTSTAT            (* (reg8 *) LedPin__INTSTAT)
    #define LedPin_SNAP               (* (reg8 *) LedPin__SNAP)
    
	#define LedPin_0_INTTYPE_REG 		(* (reg8 *) LedPin__0__INTTYPE)
#endif /* (LedPin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LedPin_H */


/* [] END OF FILE */
