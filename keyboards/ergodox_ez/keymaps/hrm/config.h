/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

//---- ZSA Oryx ----------------------------------------------------------------
// #define ORYX_CONFIGURATOR
// #define FIRMWARE_VERSION u8"OooD3/EbGz6"
#define RGB_MATRIX_STARTUP_SPD 60

//---- QMK ---------------------------------------------------------------------
#undef TAPPING_TERM
#define TAPPING_TERM 220

#define PERMISSIVE_HOLD

//---- Achordion ---------------------------------------------------------------
#define ACHORDION_STREAK

//---- USB ---------------------------------------------------------------------
#define USB_SUSPEND_WAKEUP_DELAY 0
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define HCS(report) host_consumer_send(record->event.pressed ? report : 0); return false


