/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* COL1 */
#define COL1__0__INTTYPE CYREG_PICU3_INTTYPE1
#define COL1__0__MASK 0x02u
#define COL1__0__PC CYREG_PRT3_PC1
#define COL1__0__PORT 3u
#define COL1__0__SHIFT 1u
#define COL1__AG CYREG_PRT3_AG
#define COL1__AMUX CYREG_PRT3_AMUX
#define COL1__BIE CYREG_PRT3_BIE
#define COL1__BIT_MASK CYREG_PRT3_BIT_MASK
#define COL1__BYP CYREG_PRT3_BYP
#define COL1__CTL CYREG_PRT3_CTL
#define COL1__DM0 CYREG_PRT3_DM0
#define COL1__DM1 CYREG_PRT3_DM1
#define COL1__DM2 CYREG_PRT3_DM2
#define COL1__DR CYREG_PRT3_DR
#define COL1__INP_DIS CYREG_PRT3_INP_DIS
#define COL1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define COL1__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define COL1__LCD_EN CYREG_PRT3_LCD_EN
#define COL1__MASK 0x02u
#define COL1__PORT 3u
#define COL1__PRT CYREG_PRT3_PRT
#define COL1__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define COL1__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define COL1__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define COL1__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define COL1__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define COL1__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define COL1__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define COL1__PS CYREG_PRT3_PS
#define COL1__SHIFT 1u
#define COL1__SLW CYREG_PRT3_SLW

/* COL2 */
#define COL2__0__INTTYPE CYREG_PICU3_INTTYPE3
#define COL2__0__MASK 0x08u
#define COL2__0__PC CYREG_PRT3_PC3
#define COL2__0__PORT 3u
#define COL2__0__SHIFT 3u
#define COL2__AG CYREG_PRT3_AG
#define COL2__AMUX CYREG_PRT3_AMUX
#define COL2__BIE CYREG_PRT3_BIE
#define COL2__BIT_MASK CYREG_PRT3_BIT_MASK
#define COL2__BYP CYREG_PRT3_BYP
#define COL2__CTL CYREG_PRT3_CTL
#define COL2__DM0 CYREG_PRT3_DM0
#define COL2__DM1 CYREG_PRT3_DM1
#define COL2__DM2 CYREG_PRT3_DM2
#define COL2__DR CYREG_PRT3_DR
#define COL2__INP_DIS CYREG_PRT3_INP_DIS
#define COL2__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define COL2__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define COL2__LCD_EN CYREG_PRT3_LCD_EN
#define COL2__MASK 0x08u
#define COL2__PORT 3u
#define COL2__PRT CYREG_PRT3_PRT
#define COL2__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define COL2__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define COL2__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define COL2__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define COL2__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define COL2__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define COL2__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define COL2__PS CYREG_PRT3_PS
#define COL2__SHIFT 3u
#define COL2__SLW CYREG_PRT3_SLW

/* COL3 */
#define COL3__0__INTTYPE CYREG_PICU3_INTTYPE4
#define COL3__0__MASK 0x10u
#define COL3__0__PC CYREG_PRT3_PC4
#define COL3__0__PORT 3u
#define COL3__0__SHIFT 4u
#define COL3__AG CYREG_PRT3_AG
#define COL3__AMUX CYREG_PRT3_AMUX
#define COL3__BIE CYREG_PRT3_BIE
#define COL3__BIT_MASK CYREG_PRT3_BIT_MASK
#define COL3__BYP CYREG_PRT3_BYP
#define COL3__CTL CYREG_PRT3_CTL
#define COL3__DM0 CYREG_PRT3_DM0
#define COL3__DM1 CYREG_PRT3_DM1
#define COL3__DM2 CYREG_PRT3_DM2
#define COL3__DR CYREG_PRT3_DR
#define COL3__INP_DIS CYREG_PRT3_INP_DIS
#define COL3__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define COL3__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define COL3__LCD_EN CYREG_PRT3_LCD_EN
#define COL3__MASK 0x10u
#define COL3__PORT 3u
#define COL3__PRT CYREG_PRT3_PRT
#define COL3__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define COL3__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define COL3__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define COL3__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define COL3__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define COL3__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define COL3__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define COL3__PS CYREG_PRT3_PS
#define COL3__SHIFT 4u
#define COL3__SLW CYREG_PRT3_SLW

/* ROW0 */
#define ROW0__0__INTTYPE CYREG_PICU3_INTTYPE5
#define ROW0__0__MASK 0x20u
#define ROW0__0__PC CYREG_PRT3_PC5
#define ROW0__0__PORT 3u
#define ROW0__0__SHIFT 5u
#define ROW0__AG CYREG_PRT3_AG
#define ROW0__AMUX CYREG_PRT3_AMUX
#define ROW0__BIE CYREG_PRT3_BIE
#define ROW0__BIT_MASK CYREG_PRT3_BIT_MASK
#define ROW0__BYP CYREG_PRT3_BYP
#define ROW0__CTL CYREG_PRT3_CTL
#define ROW0__DM0 CYREG_PRT3_DM0
#define ROW0__DM1 CYREG_PRT3_DM1
#define ROW0__DM2 CYREG_PRT3_DM2
#define ROW0__DR CYREG_PRT3_DR
#define ROW0__INP_DIS CYREG_PRT3_INP_DIS
#define ROW0__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define ROW0__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define ROW0__LCD_EN CYREG_PRT3_LCD_EN
#define ROW0__MASK 0x20u
#define ROW0__PORT 3u
#define ROW0__PRT CYREG_PRT3_PRT
#define ROW0__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define ROW0__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define ROW0__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define ROW0__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define ROW0__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define ROW0__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define ROW0__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define ROW0__PS CYREG_PRT3_PS
#define ROW0__SHIFT 5u
#define ROW0__SLW CYREG_PRT3_SLW

/* ROW1 */
#define ROW1__0__INTTYPE CYREG_PICU3_INTTYPE6
#define ROW1__0__MASK 0x40u
#define ROW1__0__PC CYREG_PRT3_PC6
#define ROW1__0__PORT 3u
#define ROW1__0__SHIFT 6u
#define ROW1__AG CYREG_PRT3_AG
#define ROW1__AMUX CYREG_PRT3_AMUX
#define ROW1__BIE CYREG_PRT3_BIE
#define ROW1__BIT_MASK CYREG_PRT3_BIT_MASK
#define ROW1__BYP CYREG_PRT3_BYP
#define ROW1__CTL CYREG_PRT3_CTL
#define ROW1__DM0 CYREG_PRT3_DM0
#define ROW1__DM1 CYREG_PRT3_DM1
#define ROW1__DM2 CYREG_PRT3_DM2
#define ROW1__DR CYREG_PRT3_DR
#define ROW1__INP_DIS CYREG_PRT3_INP_DIS
#define ROW1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define ROW1__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define ROW1__LCD_EN CYREG_PRT3_LCD_EN
#define ROW1__MASK 0x40u
#define ROW1__PORT 3u
#define ROW1__PRT CYREG_PRT3_PRT
#define ROW1__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define ROW1__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define ROW1__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define ROW1__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define ROW1__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define ROW1__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define ROW1__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define ROW1__PS CYREG_PRT3_PS
#define ROW1__SHIFT 6u
#define ROW1__SLW CYREG_PRT3_SLW

/* ROW2 */
#define ROW2__0__INTTYPE CYREG_PICU3_INTTYPE7
#define ROW2__0__MASK 0x80u
#define ROW2__0__PC CYREG_PRT3_PC7
#define ROW2__0__PORT 3u
#define ROW2__0__SHIFT 7u
#define ROW2__AG CYREG_PRT3_AG
#define ROW2__AMUX CYREG_PRT3_AMUX
#define ROW2__BIE CYREG_PRT3_BIE
#define ROW2__BIT_MASK CYREG_PRT3_BIT_MASK
#define ROW2__BYP CYREG_PRT3_BYP
#define ROW2__CTL CYREG_PRT3_CTL
#define ROW2__DM0 CYREG_PRT3_DM0
#define ROW2__DM1 CYREG_PRT3_DM1
#define ROW2__DM2 CYREG_PRT3_DM2
#define ROW2__DR CYREG_PRT3_DR
#define ROW2__INP_DIS CYREG_PRT3_INP_DIS
#define ROW2__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define ROW2__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define ROW2__LCD_EN CYREG_PRT3_LCD_EN
#define ROW2__MASK 0x80u
#define ROW2__PORT 3u
#define ROW2__PRT CYREG_PRT3_PRT
#define ROW2__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define ROW2__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define ROW2__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define ROW2__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define ROW2__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define ROW2__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define ROW2__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define ROW2__PS CYREG_PRT3_PS
#define ROW2__SHIFT 7u
#define ROW2__SLW CYREG_PRT3_SLW

/* ROW3 */
#define ROW3__0__INTTYPE CYREG_PICU15_INTTYPE0
#define ROW3__0__MASK 0x01u
#define ROW3__0__PC CYREG_IO_PC_PRT15_PC0
#define ROW3__0__PORT 15u
#define ROW3__0__SHIFT 0u
#define ROW3__AG CYREG_PRT15_AG
#define ROW3__AMUX CYREG_PRT15_AMUX
#define ROW3__BIE CYREG_PRT15_BIE
#define ROW3__BIT_MASK CYREG_PRT15_BIT_MASK
#define ROW3__BYP CYREG_PRT15_BYP
#define ROW3__CTL CYREG_PRT15_CTL
#define ROW3__DM0 CYREG_PRT15_DM0
#define ROW3__DM1 CYREG_PRT15_DM1
#define ROW3__DM2 CYREG_PRT15_DM2
#define ROW3__DR CYREG_PRT15_DR
#define ROW3__INP_DIS CYREG_PRT15_INP_DIS
#define ROW3__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define ROW3__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define ROW3__LCD_EN CYREG_PRT15_LCD_EN
#define ROW3__MASK 0x01u
#define ROW3__PORT 15u
#define ROW3__PRT CYREG_PRT15_PRT
#define ROW3__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define ROW3__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define ROW3__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define ROW3__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define ROW3__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define ROW3__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define ROW3__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define ROW3__PS CYREG_PRT15_PS
#define ROW3__SHIFT 0u
#define ROW3__SLW CYREG_PRT15_SLW

/* BtnPin */
#define BtnPin__0__INTTYPE CYREG_PICU12_INTTYPE5
#define BtnPin__0__MASK 0x20u
#define BtnPin__0__PC CYREG_PRT12_PC5
#define BtnPin__0__PORT 12u
#define BtnPin__0__SHIFT 5u
#define BtnPin__AG CYREG_PRT12_AG
#define BtnPin__BIE CYREG_PRT12_BIE
#define BtnPin__BIT_MASK CYREG_PRT12_BIT_MASK
#define BtnPin__BYP CYREG_PRT12_BYP
#define BtnPin__DM0 CYREG_PRT12_DM0
#define BtnPin__DM1 CYREG_PRT12_DM1
#define BtnPin__DM2 CYREG_PRT12_DM2
#define BtnPin__DR CYREG_PRT12_DR
#define BtnPin__INP_DIS CYREG_PRT12_INP_DIS
#define BtnPin__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define BtnPin__MASK 0x20u
#define BtnPin__PORT 12u
#define BtnPin__PRT CYREG_PRT12_PRT
#define BtnPin__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define BtnPin__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define BtnPin__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define BtnPin__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define BtnPin__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define BtnPin__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define BtnPin__PS CYREG_PRT12_PS
#define BtnPin__SHIFT 5u
#define BtnPin__SIO_CFG CYREG_PRT12_SIO_CFG
#define BtnPin__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define BtnPin__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define BtnPin__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define BtnPin__SLW CYREG_PRT12_SLW

/* LedPin */
#define LedPin__0__INTTYPE CYREG_PICU0_INTTYPE0
#define LedPin__0__MASK 0x01u
#define LedPin__0__PC CYREG_PRT0_PC0
#define LedPin__0__PORT 0u
#define LedPin__0__SHIFT 0u
#define LedPin__AG CYREG_PRT0_AG
#define LedPin__AMUX CYREG_PRT0_AMUX
#define LedPin__BIE CYREG_PRT0_BIE
#define LedPin__BIT_MASK CYREG_PRT0_BIT_MASK
#define LedPin__BYP CYREG_PRT0_BYP
#define LedPin__CTL CYREG_PRT0_CTL
#define LedPin__DM0 CYREG_PRT0_DM0
#define LedPin__DM1 CYREG_PRT0_DM1
#define LedPin__DM2 CYREG_PRT0_DM2
#define LedPin__DR CYREG_PRT0_DR
#define LedPin__INP_DIS CYREG_PRT0_INP_DIS
#define LedPin__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define LedPin__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define LedPin__LCD_EN CYREG_PRT0_LCD_EN
#define LedPin__MASK 0x01u
#define LedPin__PORT 0u
#define LedPin__PRT CYREG_PRT0_PRT
#define LedPin__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define LedPin__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define LedPin__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define LedPin__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define LedPin__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define LedPin__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define LedPin__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define LedPin__PS CYREG_PRT0_PS
#define LedPin__SHIFT 0u
#define LedPin__SLW CYREG_PRT0_SLW

/* LCD_Char_1_LCDPort */
#define LCD_Char_1_LCDPort__0__INTTYPE CYREG_PICU2_INTTYPE0
#define LCD_Char_1_LCDPort__0__MASK 0x01u
#define LCD_Char_1_LCDPort__0__PC CYREG_PRT2_PC0
#define LCD_Char_1_LCDPort__0__PORT 2u
#define LCD_Char_1_LCDPort__0__SHIFT 0u
#define LCD_Char_1_LCDPort__1__INTTYPE CYREG_PICU2_INTTYPE1
#define LCD_Char_1_LCDPort__1__MASK 0x02u
#define LCD_Char_1_LCDPort__1__PC CYREG_PRT2_PC1
#define LCD_Char_1_LCDPort__1__PORT 2u
#define LCD_Char_1_LCDPort__1__SHIFT 1u
#define LCD_Char_1_LCDPort__2__INTTYPE CYREG_PICU2_INTTYPE2
#define LCD_Char_1_LCDPort__2__MASK 0x04u
#define LCD_Char_1_LCDPort__2__PC CYREG_PRT2_PC2
#define LCD_Char_1_LCDPort__2__PORT 2u
#define LCD_Char_1_LCDPort__2__SHIFT 2u
#define LCD_Char_1_LCDPort__3__INTTYPE CYREG_PICU2_INTTYPE3
#define LCD_Char_1_LCDPort__3__MASK 0x08u
#define LCD_Char_1_LCDPort__3__PC CYREG_PRT2_PC3
#define LCD_Char_1_LCDPort__3__PORT 2u
#define LCD_Char_1_LCDPort__3__SHIFT 3u
#define LCD_Char_1_LCDPort__4__INTTYPE CYREG_PICU2_INTTYPE4
#define LCD_Char_1_LCDPort__4__MASK 0x10u
#define LCD_Char_1_LCDPort__4__PC CYREG_PRT2_PC4
#define LCD_Char_1_LCDPort__4__PORT 2u
#define LCD_Char_1_LCDPort__4__SHIFT 4u
#define LCD_Char_1_LCDPort__5__INTTYPE CYREG_PICU2_INTTYPE5
#define LCD_Char_1_LCDPort__5__MASK 0x20u
#define LCD_Char_1_LCDPort__5__PC CYREG_PRT2_PC5
#define LCD_Char_1_LCDPort__5__PORT 2u
#define LCD_Char_1_LCDPort__5__SHIFT 5u
#define LCD_Char_1_LCDPort__6__INTTYPE CYREG_PICU2_INTTYPE6
#define LCD_Char_1_LCDPort__6__MASK 0x40u
#define LCD_Char_1_LCDPort__6__PC CYREG_PRT2_PC6
#define LCD_Char_1_LCDPort__6__PORT 2u
#define LCD_Char_1_LCDPort__6__SHIFT 6u
#define LCD_Char_1_LCDPort__AG CYREG_PRT2_AG
#define LCD_Char_1_LCDPort__AMUX CYREG_PRT2_AMUX
#define LCD_Char_1_LCDPort__BIE CYREG_PRT2_BIE
#define LCD_Char_1_LCDPort__BIT_MASK CYREG_PRT2_BIT_MASK
#define LCD_Char_1_LCDPort__BYP CYREG_PRT2_BYP
#define LCD_Char_1_LCDPort__CTL CYREG_PRT2_CTL
#define LCD_Char_1_LCDPort__DM0 CYREG_PRT2_DM0
#define LCD_Char_1_LCDPort__DM1 CYREG_PRT2_DM1
#define LCD_Char_1_LCDPort__DM2 CYREG_PRT2_DM2
#define LCD_Char_1_LCDPort__DR CYREG_PRT2_DR
#define LCD_Char_1_LCDPort__INP_DIS CYREG_PRT2_INP_DIS
#define LCD_Char_1_LCDPort__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define LCD_Char_1_LCDPort__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LCD_Char_1_LCDPort__LCD_EN CYREG_PRT2_LCD_EN
#define LCD_Char_1_LCDPort__MASK 0x7Fu
#define LCD_Char_1_LCDPort__PORT 2u
#define LCD_Char_1_LCDPort__PRT CYREG_PRT2_PRT
#define LCD_Char_1_LCDPort__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LCD_Char_1_LCDPort__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LCD_Char_1_LCDPort__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LCD_Char_1_LCDPort__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LCD_Char_1_LCDPort__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LCD_Char_1_LCDPort__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LCD_Char_1_LCDPort__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LCD_Char_1_LCDPort__PS CYREG_PRT2_PS
#define LCD_Char_1_LCDPort__SHIFT 0u
#define LCD_Char_1_LCDPort__SLW CYREG_PRT2_SLW

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "Design01"
#define CY_VERSION "PSoC Creator  4.4"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 26u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 26u
#define CYDEV_CHIP_MEMBER_4AA 25u
#define CYDEV_CHIP_MEMBER_4AB 30u
#define CYDEV_CHIP_MEMBER_4AC 14u
#define CYDEV_CHIP_MEMBER_4AD 15u
#define CYDEV_CHIP_MEMBER_4AE 16u
#define CYDEV_CHIP_MEMBER_4D 20u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 27u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 24u
#define CYDEV_CHIP_MEMBER_4I 32u
#define CYDEV_CHIP_MEMBER_4J 21u
#define CYDEV_CHIP_MEMBER_4K 22u
#define CYDEV_CHIP_MEMBER_4L 31u
#define CYDEV_CHIP_MEMBER_4M 29u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 28u
#define CYDEV_CHIP_MEMBER_4Q 17u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 23u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 18u
#define CYDEV_CHIP_MEMBER_4Z 19u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 33u
#define CYDEV_CHIP_MEMBER_FM3 37u
#define CYDEV_CHIP_MEMBER_FM4 38u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000000u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
