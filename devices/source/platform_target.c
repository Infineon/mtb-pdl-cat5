/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#include <wiced_platform.h>

#define cr_pad_fcn_ctl_adr2                  0x8fa30090
#define cr_pad_config_adr5                   0x8fa3007c
#define cr_pad_fcn_ctl_adr3                  0x8fa301a8
#define cr_pad_config_adr8                   0x8fa30110

#define REG32(address) (*(volatile uint32_t*)(address))

void wiced_platform_target_puart_init(void)
{
#ifdef PLATFORM_PUART_FROM_HCI_UART
    /* Select PUART function for the BT_UART_TXD pin. */
    REG32(cr_pad_fcn_ctl_adr2) &= ~(0x0000f000);
    REG32(cr_pad_fcn_ctl_adr2) |= 0x00005000;
    REG32(cr_pad_config_adr5) &= ~(0xff000000);
    REG32(cr_pad_config_adr5) |= 0x08000000;
#else
    /* Configure BT_I2S_CLK to UART2_TXD for testing */
    REG32(cr_pad_fcn_ctl_adr3) &= ~(0x0000F000);
    REG32(cr_pad_fcn_ctl_adr3) |= 0x0000B000;
    REG32(cr_pad_config_adr8) &= ~(0xFF000000);
    REG32(cr_pad_config_adr8) |= 0x08000000;
#endif
}
