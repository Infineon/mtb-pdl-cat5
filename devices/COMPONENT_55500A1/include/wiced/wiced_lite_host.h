#ifndef __WICED_LITE_HOST_H__
#define __WICED_LITE_HOST_H__

#include "wiced_result.h"

/*******************************************************************************
*                       Type Definitions
*******************************************************************************/
typedef enum {
    AUDIO_INSERT_AUDIO_INFO = 0,
    AUDIO_INSERT_FILL_FIFO,
    AUDIO_INSERT_SCO_INFO,
    AUDIO_INSERT_SCO_MIC,
    AUDIO_INSERT_SCO_SPK,
    AUDIO_INSERT_SCO_SPK_INSERTED_ZEROS,
} wiced_lite_host_event_t;

typedef struct {
    uint32_t event;
    void *data;
} wiced_lite_host_event_data_t;

/** Composite MXTDM types  */
//! Enumeration for the mxtdmPair parameter of mxtdmPair.
typedef enum
{
    MXTDM_PAIR_0 = 0,
    MXTDM_PAIR_1 = 1,
} wiced_tdm_composite_mxtdmPair_t;

//! Enumeration for the mode parameter of mode.
typedef enum
{
    MXTDM_MODE_TDM = 0,
    MXTDM_MODE_I2S = 1,
}wiced_vs_tdm_composite_mode_t ;

typedef enum
{
    MXTDM_BUS_SLAVE = 0,
    MXTDM_BUS_MASTER = 1,
}wiced_vs_tdm_composite_busRole_t ;

typedef struct wiced_bt_tdm_composite_setting
{
    //! Sets the composite MXTDM pair;
    wiced_tdm_composite_mxtdmPair_t           mxtdmPair;
    //! Sets the composite MXTDM totoal channel numbers; (2~8)
    uint8_t           chNumber;
    //! Sets the composite MXTDM mode;
    wiced_vs_tdm_composite_mode_t           mode;
    //! Sets the composite MXTDM bus role;
    wiced_vs_tdm_composite_busRole_t        busRole;
    //! Sets the composite MXTDM enable;
    uint8_t           enable;
    // Set enable A2DP composite MXTDM allocation
    uint8_t           a2dpEnable;
    //! Sets the A2DP left channel to dedicated MXTDM channel;
    uint8_t           a2dpLeftCh;
    //! Sets the A2DP right channel to dedicated MXTDM channel;
    uint8_t           a2dpRightCh;
} wiced_bt_tdm_composite_setting_t;

/*****************************************************************
* Function: wiced_lite_host_setEvent()
*
* Abstract: Call this function to send event to wiced_lite_host thread
*
* Input/Output:
*    event and data pointer
*
* Return:
*    None
*
* Side Effects:
*
*****************************************************************/
void wiced_lite_host_setEvent( UINT32 event, void *data );


/**
 *
 * This API is called to set the MXTDM composite mode
 *
 *
 * @param[in]       mxtdmPair         : set MXTDM_PAIR_0 or MXTDM_PAIR_1 as MXTDM composite
 * @param[in]       chNumber          : composite MXTDM totoal channel numbers; (2~8)
 * @param[in]       mode              : the composite MXTDM mode. MXTDM_MODE_TDM(0) or MXTDM_MODE_I2S(1)
*  @param[in]       busRole           : the MXTDM bus role . MXTDM_BUS_SLAVE(0) or MXTDM_BUS_MASTER(1)
 * @param[in]       enable            : Sets the composite MXTDM enable
 * @param[in]       a2dpEnable        : Set enable A2DP composite MXTDM allocation
 * @param[in]       a2dpLeftCh        : Sets the A2DP left channel to dedicated MXTDM channel
 * @param[in]       a2dpRightCh       : Sets the A2DP right channel to dedicated MXTDM channel
 *
 * @return          WICED_BT_SUCCESS if successful
 *
 */
wiced_result_t wiced_lite_host_set_compositeMxtdm(wiced_bt_tdm_composite_setting_t *inMxtdmParams);



#endif // __WICED_LITE_HOST_H__
