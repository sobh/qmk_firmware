/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 270

#define USB_SUSPEND_WAKEUP_DELAY 0
#define AUTO_SHIFT_TIMEOUT 220
#define FIRMWARE_VERSION u8"Qlx0z/lgQ4w"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define HCS(report) host_consumer_send(record->event.pressed ? report : 0); return false

#define RGB_MATRIX_STARTUP_SPD 60

