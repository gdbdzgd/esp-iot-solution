/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://chibios-gfx.com/license.html
 */

#ifndef _ILI9488_H_
#define _ILI9488_H_

#define LCD_VERTICAL_MAX                480
#define LCD_HORIZONTAL_MAX              320

#define ILI9488_DEVICE_CODE_READ_REG    0x00
#define ILI9488_SOFT_RESET_REG          0x01
#define ILI9488_IDENTINFO_R_REG         0x04
#define ILI9488_STATUS_R_REG            0x09
#define ILI9488_POWERMODE_R_REG         0x0A
#define ILI9488_MADCTL_R_REG            0x0B
#define ILI9488_PIXFORMAT_R_REG         0x0C
#define ILI9488_IMGFORMAT_R_REG         0x0D
#define ILI9488_SIGMODE_R_REG           0x0E
#define ILI9488_SD_RESULT_R_REG         0x0F
#define ILI9488_SLEEP_ENTER_REG         0x10
#define ILI9488_SLEEP_OUT_REG           0x11
#define ILI9488_PARTIALMODE_REG         0x12
#define ILI9488_NORDISPMODE_REG         0x13
#define ILI9488_INVERSIONOFF_REG        0x20
#define ILI9488_INVERSIONON_REG         0x21
#define ILI9488_GAMMASET_REG            0x26
#define ILI9488_DISPLAYOFF_REG          0x28
#define ILI9488_DISPLAYON_REG           0x29
#define ILI9488_COLADDRSET_REG          0x2A
#define ILI9488_PAGEADDRSET_REG         0x2B
#define ILI9488_MEMORYWRITE_REG         0x2C
#define ILI9488_COLORSET_REG            0x2D
#define ILI9488_MEMORYREAD_REG          0x2E
#define ILI9488_PARTIALAREA_REG         0x30
#define ILI9488_VERTSCROLL_REG          0x33
#define ILI9488_TEAREFFECTLINEOFF_REG   0x34
#define ILI9488_TEAREFFECTLINEON_REG    0x35
#define ILI9488_MEMACCESS_REG           0x36
#define ILI9488_VERSCRSRART_REG         0x37
#define ILI9488_IDLEMODEOFF_REG         0x38
#define ILI9488_IDLEMODEON_REG          0x39
#define ILI9488_PIXFORMATSET_REG        0x3A
#define ILI9488_WRITEMEMCONTINUE_REG    0x3C
#define ILI9488_READMEMCONTINUE_REG     0x3E
#define ILI9488_SETTEATSCAN_REG         0x44
#define ILI9488_GETSCANLINE_REG         0x45
#define ILI9488_WRITEBRIGHT_REG         0x51
#define ILI9488_READBRIGHT_REG          0x52
#define ILI9488_WRITECTRL_REG           0x53
#define ILI9488_READCTRL_REG            0x54
#define ILI9488_WRITECABC_REG           0x55
#define ILI9488_READCABC_REG            0x56
#define ILI9488_WRITECABCMB_REG         0x5E
#define ILI9488_READCABCMB_REG          0x5F
#define ILI9488_RGB_ISCTL_REG           0xB0
#define ILI9488_FRAMECTL_NOR_REG        0xB1
#define ILI9488_FRAMECTL_IDLE_REG       0xB2
#define ILI9488_FRAMECTL_PARTIAL_REG    0xB3
#define ILI9488_INVERCTL_REG            0xB4
#define ILI9488_BLANKPORCTL_REG         0xB5
#define ILI9488_FUNCTONCTL_REG          0xB6
#define ILI9488_ENTRYMODE_REG           0xB7
#define ILI9488_BLIGHTCTL1_REG          0xB8
#define ILI9488_BLIGHTCTL2_REG          0xB9
#define ILI9488_BLIGHTCTL3_REG          0xBA
#define ILI9488_BLIGHTCTL4_REG          0xBB
#define ILI9488_BLIGHTCTL5_REG          0xBC
#define ILI9488_BLIGHTCTL7_REG          0xBE
#define ILI9488_BLIGHTCTL8_REG          0xBF
#define ILI9488_POWERCTL1_REG           0xC0
#define ILI9488_POWERCTL2_REG           0xC1
#define ILI9488_VCOMCTL1_REG            0xC5
#define ILI9488_VCOMCTL2_REG            0xC7
#define ILI9488_POWERCTLA_REG           0xCB
#define ILI9488_POWERCTLB_REG           0xCF
#define ILI9488_NVMEMWRITE_REG          0xD0
#define ILI9488_NVMEMPROTECTKEY_REG     0xD1
#define ILI9488_NVMEMSTATUS_REG         0xD2
#define ILI9488_READID4_REG             0xD3
#define ILI9488_READID1_REG             0xDA
#define ILI9488_READID2_REG             0xDB
#define ILI9488_READID3_REG             0xDC
#define ILI9488_POSGAMMACORRECTION_REG  0xE0
#define ILI9488_NEGGAMMACORRECTION_REG  0xE1
#define ILI9488_DIGGAMCTL1_REG          0xE2
#define ILI9488_DIGGAMCTL2_REG          0xE3
#define ILI9488_DIVTIMCTL_A_REG         0xE8
#define ILI9488_DIVTIMCTL_B_REG         0xEA
#define ILI9488_POWONSEQCTL_REG         0xED
#define ILI9488_ENABLE_3G_REG           0xF2
#define ILI9488_INTERFCTL_REG           0xF6
#define ILI9488_PUMPRATIOCTL_REG        0xF7

#endif /* _ILI9488_H_ */
