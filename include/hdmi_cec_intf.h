#ifndef __HDMI_CEC_INTF_H__
#define __HDMI_CEC_INTF_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CEC Opcode */

#define CEC_MESSAGE_BODY_MAX_LENGTH 0x10
/* CEC 2.0 */
/**"Feature Abort" Used as a response to indicate that the device does not
 * support the requested message type, or that it cannot execute it at the
 * present time. */
#define CEC_OPCODE_FEATURE_ABORT 0X00

/**"Abort Message" This message is reserved for testing purposes.*/
#define CEC_OPCODE_ABORT_MESSAGE 0XFF

/* One Touch Play Feature*/
/**"Active Source" Used by a new source to indicate that it has started to
 * transmit a stream OR used in response to a "Request Active Source"*/
#define CEC_OPCODE_ACTIVE_SOURCE 0X82

/**"Image View On" Sent by a source device to the TV whenever it enters the
 * active state (alternatively it may send "Text View On").*/
#define CEC_OPCODE_IMAGE_VIEW_ON 0X04

/**"Text View On" As "Image View On", but should also remove any text, menus and
 * PIP windows from the TV's display.*/
#define CEC_OPCODE_TEXT_VIEW_ON 0X0D

/* Routing Control Feature*/
/**"Inactive Source" Used by the currently active source to inform the TV that
 * it has no video to be presented to the user, or is going into standby as the
 * result of a local user command on the device. */
#define CEC_OPCODE_INACTIVE_SOURCE 0X9D

/**"Request Active Source" Used by a new device to discover the status of the
 * system.*/
#define CEC_OPCODE_REQUEST_ACTIVE_SOURCE 0X85

/**"Routing Change" Sent by a CEC Switch when it is manually switched to inform
 * all other devices on the network that the active route below the switch has
 * changed. */
#define CEC_OPCODE_ROUTING_CHANGE 0X80

/**"Routing Information" Sent by a CEC Switch to indicate the active route below
 * the switch.*/
#define CEC_OPCODE_ROUTING_INFORMATION 0X81

/**"Set Stream Path" Used by the TV to request a streaming path from the
 * specified physical address.*/
#define CEC_OPCODE_SET_STREAM_PATH 0X86

/* Standby Feature*/

/**"Standby" Switches one or all devices into standby mode. Can be used as a
 * broadcast message or be addressed to a specific device.See section CEC 13.3
 * for important notes on the use of this message */
#define CEC_OPCODE_STANDBY 0X36

/* One Touch Record Feature*/

/**"Record Off" Requests a device to stop a recording. */
#define CEC_OPCODE_RECORD_OFF 0X0B

/**"Record On" Attempt to record the specified source. */
#define CEC_OPCODE_RECORD_ON 0X09

/**"Record Status" Used by a Recording Device to inform the initiator of the
 * message "Record On" about its status. */
#define CEC_OPCODE_RECORD_STATUS 0X0A

/**"Record TV Screen" Request by the Recording Device to record the presently
 * displayed source. */
#define CEC_OPCODE_RECORD_TV_SCREEN 0X0F

/* Timer Programming Feature*/

/**"Clear Analogue Timer" Used to clear an Analogue timer block of a device. */
#define CEC_OPCODE_CLEAR_ANALOGUE_TIMER 0X33
/**"Clear Digital Timer" Used to clear a Digital timer block of a device. */
#define CEC_OPCODE_CLEAR_DIGITAL_TIMER 0X99
/**"Clear External Timer" Used to clear an External timer block of a device. */
#define CEC_OPCODE_CLEAR_EXTERNAL_TIMER 0XA1
/**"Set Analogue Timer" Used to set a single timer block on an Analogue
 * Recording Device. */
#define CEC_OPCODE_SET_ANALOGUE_TIMER 0X34
/**"Set Digital Timer" Used to set a single timer block on a Digital Recording
 * Device. */
#define CEC_OPCODE_SET_DIGITAL_TIMER 0X97
/**"Set External Timer" Used to set a single timer block to record from an
 * external device. */
#define CEC_OPCODE_SET_EXTERNAL_TIMER 0XA2
/**"Set Timer Program Title" Used to set the name of a program associated with a
 * timer block. Sent directly after sending a "Set Analogue Timer" or "Set
 * Digital Timer" message. The name is then associated with that timer block. */
#define CEC_OPCODE_SET_TIMER_PROGRAM_TITLE 0X67
/**"Timer Cleared Status" Used to give the status of a "Clear Analogue Timer",
 * "Clear Digital Timer" or "Clear External Timer" message. */

#define CEC_OPCODE_TIMER_CLEARED_STATUS 0X43
/**"Timer Status" Used to send timer status to the initiator of a "Set Timer"
 * message. */
#define CEC_OPCODE_TIMER_STATUS 0X35

/* System Information Feature*/

/**"CEC Version" Used to indicate the supported CEC version, Specification which
 * was used to design the device, in response to a <GetCEC Version> */
#define CEC_OPCODE_CEC_VERSION 0X9E

/**"Get CEC Version" Specification which was used to design the device,
 * inresponse to a <Get CEC Version> */
#define CEC_OPCODE_GET_CEC_VERSION 0X9F

/**"Give Physical Address" A request to a device to return its physical address.
 */
#define CEC_OPCODE_GIVE_PHYSICAL_ADDRESS 0X83

/**"Get Menu Language" Sent by a device capable of character generation (for OSD
 * and Menus) to a TV in order to discover the currently selected Menu language
 * on the TV.*/
#define CEC_OPCODE_GET_MENU_LANGUAGE 0X91

/**"Report Physical Address" Used to inform all other devices of the mapping
 * between physical and logical address of the initiator.*/
#define CEC_OPCODE_REPORT_PHYSICAL_ADDRESS 0X84

/**"Set Menu Language" Used by a TV or another device to indicate the menu
 * language. */
#define CEC_OPCODE_SET_MENU_LANGUAGE 0X32

/**"Report Features" Used by a device to announce its version, features and
 * device type(s) */
#define CEC_OPCODE_REPORT_FEATURES 0XA6

/**"Give Features" Used by a device to request another device’s features. */
#define CEC_OPCODE_GIVE_FEATURES 0XA5

/*  Deck Control Feature*/

/**"Deck Control" Used to control a device's media functions. */
#define CEC_OPCODE_DECK_CONTROL 0X42

/**"Deck Status" Used to provide a deck's status to the initiator of the "Give
 * Deck Status" message. */
#define CEC_OPCODE_DECK_STATUS 0X1B
/**"Give Deck Status" Used to request the status of a device, regardless of
 * whether or not it is the current active source. */
#define CEC_OPCODE_GIVE_DECK_STATUS 0X1A
/**"Play" Used to control the playback behaviour of a source device. */
#define CEC_OPCODE_PLAY 0X41

/* Tuner Control Feature*/

/**"Give Tuner Device Status" Used to request the status of a tuner device. */
#define CEC_OPCODE_GIVE_TUNER_DEVICE_STATUS 0X08
/**"Select Analogue Service" Directly selects an Analogue TV service */
#define CEC_OPCODE_SELECT_ANALOGUE_SERVICE 0X92
/**"Select Digital Service" Directly selects a Digital TV, Radio or Data
 * Broadcast Service */

#define CEC_OPCODE_SELECT_DIGITAL_SERVICE 0X93
/**"Tuner Device Status" Use by a tuner device to provide its status to the
 * initiator of the "Give Tuner Device Status" message. */

#define CEC_OPCODE_TUNER_DEVICE_STATUS 0X07
/**"Tuner Step Decrement" Used to tune to next lowest service in a tuner's
 * service list. Can be used for PIP. */

#define CEC_OPCODE_TUNER_STEP_DECREMENT 0X06
/**"Tuner Step Increment" Used to tune to next highest service in a tuner's
 * service list. Can be used for PIP. */

#define CEC_OPCODE_TUNER_STEP_INCREMENT 0X05

/* Vendor Specific Command*/

/**"Device Vendor ID" Reports the vendor ID of this device. */

#define CEC_OPCODE_DEVICE_VENDOR_ID 0X87
/**"Give Device Vendor ID" Requests the Vendor ID from a device. */

#define CEC_OPCODE_GIVE_DEVICE_VENDOR_ID 0X8C
/**"Vendor Command" Allows vendor specific commands to be sent between two
 * devices. */

#define CEC_OPCODE_VENDOR_COMMAND 0X89
/**"Vendor Command With ID" Allows vendor specific commands to be sent between
 * two devices or broadcast. */

#define CEC_OPCODE_VENDOR_COMMAND_WITH_ID 0XA0
/**"Vendor Remote Button Down" Indicates that a remote control button has been
 * depressed. */

#define CEC_OPCODE_VENDOR_REMOTE_BUTTON_DOWN 0X8A
/**"Vendor Remote Button Up" Indicates that a remote control button (the last
 * button pressed indicated by the Vendor Remote Button Down message) has been
 * released. */
#define CEC_OPCODE_VENDOR_REMOTE_BUTTON_UP 0X8B

/* OSD Display Feature*/

/**"Set OSD String" Used to send a text message to output on a TV. */
#define CEC_OPCODE_SET_OSD_STRING 0X64

/**"Give OSD Name" Used to request the preferred OSD name of a device for use in
 * menus associated with that device. */
#define CEC_OPCODE_GIVE_OSD_NAME 0X46

/**"Set OSD Name" Used to set the preferred OSD name of a device for use in
 * menus associated with that device. */
#define CEC_OPCODE_SET_OSD_NAME 0X47

/* Device Menu Control Feature*/

/**"Menu Request" A request from the TV for a device to show/remove a menu or to
 * query if a device is currently showing a menu. */

#define CEC_OPCODE_MENU_REQUEST 0X8D
/**"Menu Status" Used to indicate to the TV that the device is showing/has
 * removed a menu and requests the remote control keys to be passed though. */
#define CEC_OPCODE_MENU_STATUS 0X8E

/* Power Status Feature*/

/**"Give Device Power Status" Used to determine the current power status of a
 * target device */
#define CEC_OPCODE_GIVE_DEVICE_POWER_STATUS 0X8F
/**"Report Power Status" Used to inform a requesting device of the current power
 * status */
#define CEC_OPCODE_REPORT_POWER_STATUS 0X90

/* System Audio Control Feature*/

/**"Give Audio Status" Requests an amplifier to send its volume and mute status
 */
#define CEC_OPCODE_GIVE_AUDIO_STATUS 0X71
/**"Give System Audio Mode Status" Requests the status of the System Audio Mode
 */
#define CEC_OPCODE_GIVE_SYSTEM_AUDIO_MODE_STATUS 0x7D
/**"Report Audio Status" Reports an amplifier's volume and mute status */
#define CEC_OPCODE_REPORT_AUDIO_STATUS 0X7A

/**"Report Short Audio Descriptor" Report Audio Capability */
#define CEC_OPCODE_REPORT_SHORT_AUDIO_DESCRIPTOR 0XA3

/**"Request short Audio Descriptor" Request Audio Capability */
#define CEC_OPCODE_REQUEST_SHORT_AUDIO_DESCRIPTOR 0XA4

/**"Set System Audio Mode" Turns the System Audio Mode On or Off. */
#define CEC_OPCODE_SET_SYSTEM_AUDIO_MODE 0X72
/**"System Audio Mode Request" A device implementing System Audio Control and
 * which has volume control RC buttons (eg TV or STB) requests to use System
 * Audio Mode to the amplifier */
#define CEC_OPCODE_SYSTEM_AUDIO_MODE_REQUEST 0X70
/**"System Audio Mode Status" Reports the current status of the System Audio
 * Mode */
#define CEC_OPCODE_SYSTEM_AUDIO_MODE_STATUS 0X7E

/**"User Control Pressed" Used to indicate that the user pressed a remote
 * control button or switched from one remote control button to another. */
#define CEC_OPCODE_USER_CONTROL_PRESSED 0X44

/**"User Control Released" Indicates that user released a remote control button
 * (the last one indicated by the "User Control Pressed" message) */
#define CEC_OPCODE_USER_CONTROL_RELEASED 0X45

/* Audio Rate Control Feature*/

/**"Set Audio Rate" Used to control audio rate from Source Device. */
#define CEC_OPCODE_SET_AUDIO_RATE 0X9A

/* Audio Return Channel Control Feature */
/**"Initiate ARC" Used by an ARC Rx device to activate the ARC functionality in
 * an ARC Tx device */
#define CEC_OPCODE_INITIATE_ARC 0XC0

/**"Report ARC Initiated" Used by an ARC Tx device to indicate that its ARC
 * functionality has been activated. */
#define CEC_OPCODE_REPORT_ARC_INITIATED 0XC1

/**"Report ARC Terminated" Used by an ARC Tx device to indicate that its ARC
 * functionality has been deactivated. */
#define CEC_OPCODE_REPORT_ARC_TERMINATED 0XC2

/**"Request ARC Initiation" Used by an ARC Tx device to request an ARC Rx device
 * to activate the ARC functionality in the ARC Tx device */
#define CEC_OPCODE_REQUEST_ARC_INITIATION 0XC3

/**"Request ARC Termination" Used by an ARC Tx device to request an ARC Rx
 * device to deactivate the ARC functionality in the ARC Tx device. */
#define CEC_OPCODE_REQUEST_ARC_TERMINATION 0XC4

/**"Terminate ARC " Used by an ARC Tx device to deactivate the ARC functionality
 * in an ARC Tx device. */
#define CEC_OPCODE_TERMINATE_ARC 0XC5

/* Dynamic Auto Lipsync feature*/
/**"Request Current Latency " Used by Amplifier (or other device) to request
 * current latency. */
#define CEC_OPCODE_REQUEST_CURRENT_LATENCY 0XA7
/**"Report Current Latency" Used by TV (or other Initiator) to report updates of
 * latency. */
#define CEC_OPCODE_REPORT_CURRENT_LATENCY 0XA8

/**POLL message have no opcode, So, we just use this value */
#define CEC_OPCODE_POLLING_MESSAGE 0XFE

typedef enum {
  HDMI_CEC_ADDR_TV = 0,
  HDMI_CEC_ADDR_RECORDER_1 = 1,
  HDMI_CEC_ADDR_RECORDER_2 = 2,
  HDMI_CEC_ADDR_TUNER_1 = 3,
  HDMI_CEC_ADDR_PLAYBACK_1 = 4,
  HDMI_CEC_ADDR_AUDIO_SYSTEM = 5,
  HDMI_CEC_ADDR_TUNER_2 = 6,
  HDMI_CEC_ADDR_TUNER_3 = 7,
  HDMI_CEC_ADDR_PLAYBACK_2 = 8,
  HDMI_CEC_ADDR_RECORDER_3 = 9,
  HDMI_CEC_ADDR_TUNER_4 = 10,
  HDMI_CEC_ADDR_PLAYBACK_3 = 11,
  HDMI_CEC_ADDR_RESERVED_1 = 12,
  HDMI_CEC_ADDR_RESERVED_2 = 13,
  HDMI_CEC_ADDR_FREE_USE = 14,
  HDMI_CEC_ADDR_UNREGISTERED = 15,
  HDMI_CEC_ADDR_BROADCAST = 15
} hdmi_cec_logical_address_t;

/**CNcomment: HDMI_CEC CEC 用户接口操作指令，请参考HDMI 1.4a协议 */
typedef enum {
  HDMI_CEC_UICMD_SELECT = 0x00,
  HDMI_CEC_UICMD_UP = 0x01,
  HDMI_CEC_UICMD_DOWN = 0x02,
  HDMI_CEC_UICMD_LEFT = 0x03,
  HDMI_CEC_UICMD_RIGHT = 0x04,
  HDMI_CEC_UICMD_RIGHT_UP = 0x05,
  HDMI_CEC_UICMD_RIGHT_DOWN = 0x06,
  HDMI_CEC_UICMD_LEFT_UP = 0x07,
  HDMI_CEC_UICMD_LEFT_DOWN = 0x08,
  HDMI_CEC_UICMD_ROOT_MENU = 0x09,
  HDMI_CEC_UICMD_SETUP_MENU = 0x0A,
  HDMI_CEC_UICMD_CONTENTS_MENU = 0x0B,
  HDMI_CEC_UICMD_FAVORITE_MENU = 0x0C,
  HDMI_CEC_UICMD_EXIT = 0x0D,
  HDMI_CEC_UICMD_MEDIA_TOP_MENU = 0x10,
  HDMI_CEC_UICMD_MEDIA_CONTEXT_SENSITIV_MENU = 0x11,
  HDMI_CEC_UICMD_NUMBER_ENTRY_MODE = 0x1D,
  HDMI_CEC_UICMD_NUMBER_11 = 0x1E,
  HDMI_CEC_UICMD_NUMBER_12 = 0x1F,
  HDMI_CEC_UICMD_NUM_0 = 0x20,
  HDMI_CEC_UICMD_NUM_1 = 0x21,
  HDMI_CEC_UICMD_NUM_2 = 0x22,
  HDMI_CEC_UICMD_NUM_3 = 0x23,
  HDMI_CEC_UICMD_NUM_4 = 0x24,
  HDMI_CEC_UICMD_NUM_5 = 0x25,
  HDMI_CEC_UICMD_NUM_6 = 0x26,
  HDMI_CEC_UICMD_NUM_7 = 0x27,
  HDMI_CEC_UICMD_NUM_8 = 0x28,
  HDMI_CEC_UICMD_NUM_9 = 0x29,
  HDMI_CEC_UICMD_DOT = 0x2A,
  HDMI_CEC_UICMD_ENTER = 0x2B,
  HDMI_CEC_UICMD_CLEAR = 0x2C,
  HDMI_CEC_UICMD_NEXT_FAVORITE = 0x2F,
  HDMI_CEC_UICMD_CHANNEL_UP = 0x30,
  HDMI_CEC_UICMD_CHANNEL_DOWN = 0x31,
  HDMI_CEC_UICMD_PREVIOUS_CHANNEL = 0x32,
  HDMI_CEC_UICMD_SOUND_SELECT = 0x33,
  HDMI_CEC_UICMD_INPUT_SELECT = 0x34,
  HDMI_CEC_UICMD_DISPLAY_INFORMATION = 0x35,
  HDMI_CEC_UICMD_HELP = 0x36,
  HDMI_CEC_UICMD_PAGE_UP = 0x37,
  HDMI_CEC_UICMD_PAGE_DOWN = 0x38,
  HDMI_CEC_UICMD_POWER = 0x40,
  HDMI_CEC_UICMD_VOLUME_UP = 0x41,
  HDMI_CEC_UICMD_VOLUME_DOWN = 0x42,
  HDMI_CEC_UICMD_MUTE = 0x43,
  HDMI_CEC_UICMD_PLAY = 0x44,
  HDMI_CEC_UICMD_STOP = 0x45,
  HDMI_CEC_UICMD_PAUSE = 0x46,
  HDMI_CEC_UICMD_RECORD = 0x47,
  HDMI_CEC_UICMD_REWIND = 0x48,
  HDMI_CEC_UICMD_FAST_FORWARD = 0x49,
  HDMI_CEC_UICMD_EJECT = 0x4A,
  HDMI_CEC_UICMD_FORWARD = 0x4B,
  HDMI_CEC_UICMD_BACKWARD = 0x4C,
  HDMI_CEC_UICMD_STOP_RECORD = 0x4D,
  HDMI_CEC_UICMD_PAUSE_RECORD = 0x4E,
  HDMI_CEC_UICMD_ANGLE = 0x50,
  HDMI_CEC_UICMD_SUBPICTURE = 0x51,
  HDMI_CEC_UICMD_VIDEO_ON_DEMAND = 0x52,
  HDMI_CEC_UICMD_ELECTRONIC_PROGRAM_GUIDE = 0x53,
  HDMI_CEC_UICMD_TIMER_PROGRAMMING = 0x54,
  HDMI_CEC_UICMD_INITIAL_CONFIGURATION = 0x55,
  HDMI_CEC_UICMD_SELECT_BROADCAST_TYPE = 0x56,
  HDMI_CEC_UICMD_SELECT_SOUND_PRESENTATION = 0x57,
  HDMI_CEC_UICMD_AUDIO_DESCRIPTION = 0x58,
  HDMI_CEC_UICMD_INTERNET = 0x59,
  HDMI_CEC_UICMD_3D_MODE = 0x5A,
  HDMI_CEC_UICMD_PLAY_FUNCTION = 0x60,
  HDMI_CEC_UICMD_PAUSE_PLAY_FUNCTION = 0x61,
  HDMI_CEC_UICMD_RECORD_FUNCTION = 0x62,
  HDMI_CEC_UICMD_PAUSE_RECORD_FUNCTION = 0x63,
  HDMI_CEC_UICMD_STOP_FUNCTION = 0x64,
  HDMI_CEC_UICMD_MUTE_FUNCTION = 0x65,
  HDMI_CEC_UICMD_RESTORE_VOLUME_FUNCTION = 0x66,
  HDMI_CEC_UICMD_TUNE_FUNCTION = 0x67,
  HDMI_CEC_UICMD_SELECT_MEDIA_FUNCTION = 0x68,
  HDMI_CEC_UICMD_SELECT_AV_INPUT_FUNCTION = 0x69,
  HDMI_CEC_UICMD_SELECT_AUDIO_INPUT_FUNCTION = 0x6A,
  HDMI_CEC_UICMD_POWER_TOGGLE_FUNCTION = 0x6B,
  HDMI_CEC_UICMD_POWER_OFF_FUNCTION = 0x6C,
  HDMI_CEC_UICMD_POWER_ON_FUNCTION = 0x6D,
  HDMI_CEC_UICMD_F1_BLUE = 0x71,
  HDMI_CEC_UICMD_F2_RED = 0x72,
  HDMI_CEC_UICMD_F3_GREEN = 0x73,
  HDMI_CEC_UICMD_F4_YELLOW = 0x74,
  HDMI_CEC_UICMD_F5 = 0x75,
  HDMI_CEC_UICMD_DATA = 0x76,
} hdmi_cec_uicmd_t;

enum {
    DEVICE_TYPE_TV = 0,
    DEVICE_TYPE_PLAYBCK = 4,
    DEVICE_TYPE_AUDIOSYSTEM = 5,
};

/**HDMI CEC Raw Data struct,please reference  HDMI specification 1.4a*/
/**CNcomment: HDMI CEC原始数据结构体，请参考HDMI 1.4a协议 */
typedef struct hdmi_cec_rawdata
{
	  /**<CEC raw data lengh*//**<cec 有效参数个数 */
    short length;
     /**<CEC raw data*//**<CEC 参数结构体 */
    unsigned char body[CEC_MESSAGE_BODY_MAX_LENGTH];
}hdmi_cec_rawdata_t;

/**HDMI CEC operand command,please reference  HDMI specification 1.4a*/
/**CNcomment: HDMI CEC 操作指令，请参考HDMI 1.4a协议 */
typedef union hiUNF_CEC_Operand_t
{
    hdmi_cec_rawdata_t               raw_data;   /**<CEC raw date*//**<CNcomment:CEC 原始命令 */
    hdmi_cec_uicmd_t                 ui_opcode;  /**<CEC user interface command*//**<CNcomment:CEC用户自定义操作 */
}hdmi_cec_operand_t;

typedef struct {
  /* logical address of sender */
  hdmi_cec_logical_address_t initiator;

  /* logical address of receiver */
  hdmi_cec_logical_address_t destination;

  /* opration code */
  short opcode;

  /* operand */
  hdmi_cec_operand_t operand;
} hdmi_cec_message_t;

enum cec_app_event_type {           // value of data:
  CEC_APP_SOURCE_CHANGED = 1,       // 0: source deactivate, 1: source activate
  CEC_TV_POWER_CHANGED = 2,         // 0: tv power on, 1: tv power off, 2:tv powering on, 3: tv powering off.
  CEC_APP_ARC_CONNECT = 3,          // 0: ARC device disconnect, 1: ARC device ready to use
  CEC_APP_ARC_VOLUME = 4,           // 0: mute, 0~100 normal, -1 invalid
  CEC_APP_EVENT_MAX
};

typedef struct {
    enum cec_app_event_type event;
    int data;
} cec_app_event_t;

typedef struct {
    int port_id;
    int logical_address;
    int device_type;
    int vendor_id;
    int power_status;
    unsigned char osd_name[CEC_MESSAGE_BODY_MAX_LENGTH - 1];
    int osd_length;
} device_info_t;

typedef void (*hdmi_cec_callback)(hdmi_cec_message_t* cmd, void* pdata);

typedef void (*app_event_callback)(cec_app_event_t* event, void* pdata);

typedef struct {
    void (*onNewActiveSource)(int port, void* pdata);
    void (*onDeviceAdded)(device_info_t* device, void* pdata);
    void (*onDeviceRemoved)(device_info_t* device, void* pdata);
    void (*onDeviceUpdated)(device_info_t* device, void* pdata);

} routing_callback_t;

/* applicatin call libcec.so sequence:
* 1. get HDMI_CEC_Intf pointer from libcec.so
*  struct HDMI_CEC_Intf *intf = NULL;
*  get_device("CEC", &intf);
* 2. set one time setting before ->init
*  intf->enable_arc = FALSE;
* 3. init cec
*  intf->init(intf, "amlogic", DEVICE_TYPE_TV, TRUE, TRUE);
*  intf->setCallback(intf, hdmi_cec_callback, this);
*  intf->setAppCallback(intf, hdmi_cec_app_callback, this);
*  intf->setCecMenuLanguage(intf, iso639_2_to_int(menu_language.c_str()));
*  routing_callback_t rcb = {onNewActiveSource, onDeviceAdded, onDeviceRemoved, onDeviceUpdated};
*  intf->setRoutingCallback(intf, &rcb, this);
*/
struct HDMI_CEC_Intf {
  const char* name;
  int version;  // return the CEC version;
  size_t size;  // sizeof HDMI_CEC_Intf structure.
  int enable_arc;

  /**
  \brief initialize HDMI_CEC hardware
  \attention \n
  \param[in] struct HDMI_CEC_Intf*  HDMI_CEC_Intf pointer.
  \retval 0:success, others: failure.
  */
  int (*init)(struct HDMI_CEC_Intf* dev, const char* name, int deviceType, int enable, int otpEnabled);

  /**
  \brief  destroy HDMI_CEC.
  \attention \n
  \param[in] struct HDMI_CEC_Intf*  HDMI_CEC_Intf pointer.
  \retval 0:success, others: failure.
  */
  int (*destroy)(struct HDMI_CEC_Intf* dev);

  /**
  \brief  register HDMI_CEC callback functions.
  \attention \n
  \param[in] struct HDMI_CEC_Intf*  HDMI_CEC_Intf pointer.
  \param[in] const hdmi_cec_callback_t*  hdmi_cec_callback_t pointer.
  \retval 0:success, others: failure.
  */
  int (*setCallback)(struct HDMI_CEC_Intf* dev, hdmi_cec_callback cec_callback, void* pdata);

  int (*setAppCallback)(struct HDMI_CEC_Intf* dev, app_event_callback cec_callback, void* pdata);
  int (*isActive)(struct HDMI_CEC_Intf* dev);

  int (*setRoutingCallback)(struct HDMI_CEC_Intf* dev, routing_callback_t* routing_callback, void* pdata);

  /**
  \brief  set hdmi physical address.
  \attention \n
  \param[in] struct HDMI_CEC_Intf*  HDMI_CEC_Intf pointer.
  \param[in] int hdmi physical address.
  \retval 0:success, others: failure.
  */
  int (*addPhysicalAddress)(struct HDMI_CEC_Intf* dev, unsigned int addr);

  /**
  \brief send CEC message.
  \attention \n
  \param[in] struct HDMI_CEC_Intf*    HDMI_CEC_Intf pointer.
  \param[in] hdmi_cec_message_t*  cec message content pointer.
  \retval 0:success, others: failure.
  */
  int (*sendCecMessage)(struct HDMI_CEC_Intf* dev,
                        const hdmi_cec_message_t* message);

  int (*isCecSupportted)(struct HDMI_CEC_Intf* dev);
  int (*setCecEnable)(struct HDMI_CEC_Intf* dev, bool enable);
  /**
   * set whether one touch play function is enabled.
   */
  int (*oneTouchPlay)(struct HDMI_CEC_Intf* dev, bool enable);
  int (*getCecEnableStatus)(struct HDMI_CEC_Intf* dev);
  //ENG = (0x65 << 16) + (0x6e << 8) + 0x67,  //CEC639-2 English of cec
  int (*setCecMenuLanguage)(struct HDMI_CEC_Intf* dev, int lang);
  int (*getCecMenuLanguage)(struct HDMI_CEC_Intf* dev);
  int (*setCecStandby)(struct HDMI_CEC_Intf* dev, bool enable);
  int (*testCecInterface)(struct HDMI_CEC_Intf* dev);
  int (*doOneTouchPlay)(struct HDMI_CEC_Intf* dev);

  int (*portSelect)(struct HDMI_CEC_Intf* dev, int port);
  int (*sendKeyEvent)(struct HDMI_CEC_Intf* dev, int keycode, bool pressed);
  int (*setPowerStatus)(struct HDMI_CEC_Intf* dev, bool wake);
  int (*getDeviceList)(struct HDMI_CEC_Intf* dev, device_info_t* list[]);

  // return AVR current volume, or negtive error code
  int (*getARCVolume)(struct HDMI_CEC_Intf* dev);
  // enable/disable ARC
  int (*setARCEnable)(struct HDMI_CEC_Intf* dev, bool enable);
};

/**
\brief get HDMI_CEC control structure.
\attention \n
\param[in] char* HDMI_CEC module name.
\param[out] HDMI_CEC_Intf**  point to HDMI_CEC_Intf structure.
\retval 0:success, others: failure.
*/
typedef int (*get_device_cb)(const char* name, struct HDMI_CEC_Intf** intf);

// define the symbol name to exports
#define HDMI_CEC_GET_DEVICE_FUNC  hdmi_cec_get_device
#define HDMI_CEC_GET_DEVICE_NAME  "hdmi_cec_get_device"


#ifdef __HDMI_CEC_IMPL__
extern "C" int HDMI_CEC_GET_DEVICE_FUNC (const char* name, struct HDMI_CEC_Intf** intf);
#endif

#ifdef __cplusplus
}
#endif  // __cp

/////////////////////////////////////////////////
#ifdef __cplusplus
#ifndef __HDMI_CEC_IMPL__
#include <dlfcn.h>

class HDMICecIntf : public HDMI_CEC_Intf {
 public:
  ~HDMICecIntf() {
    HDMI_CEC_Intf::destroy(this);
  }

  static HDMICecIntf* GetInstance(const char* so_name, const char* name) {
    void* lib = dlopen(so_name, RTLD_LAZY);
    HDMICecIntf* intf = nullptr;
    get_device_cb get_dev = reinterpret_cast<get_device_cb>(dlsym(lib, HDMI_CEC_GET_DEVICE_NAME));
    get_dev(name, reinterpret_cast<HDMI_CEC_Intf**>(&intf));
    return intf;
  }

  int init(const char* name, int deviceType, int enable, int otpEnabled) {
    return HDMI_CEC_Intf::init(this, name, deviceType, enable, otpEnabled);
  }

  int destroy() {
    return HDMI_CEC_Intf::destroy(this);
  }

  int isCecSupportted() {
    return HDMI_CEC_Intf::isCecSupportted(this);
  }

  int setCallback(hdmi_cec_callback cb, void* pdata) {
    return HDMI_CEC_Intf::setCallback(this, cb, pdata);
  }

 private:
  HDMICecIntf() {}

};
#endif  // __HDMI_CEC_IMPL__
#endif  // __cplusplus

#endif
