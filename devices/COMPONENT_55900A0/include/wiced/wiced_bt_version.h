/*
 * $ Copyright 2021-YEAR Cypress Semiconductor $
 */


#ifndef __WICED_BT_VERSION_H__
#define __WICED_BT_VERSION_H__


#define WICED_BTSTACK_VERSION_MAJOR    3      /**< Stack Major version */
#define WICED_BTSTACK_VERSION_MINOR    7      /**< Stack Minor version */
#define WICED_BTSTACK_VERSION_PATCH    0      /**< Stack Patch version */

/*Stack version macro for use in BTSDK*/
#define BTSTACK_VER   ( ((WICED_BTSTACK_VERSION_MAJOR & 0xff) << 24) | ((WICED_BTSTACK_VERSION_MINOR & 0xff) << 16) | (WICED_BTSTACK_VERSION_PATCH & 0xffff) )

#endif //__WICED_BT_VERSION_H__
