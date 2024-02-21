/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

//---- ZSA Oryx ----------------------------------------------------------------
#define ORYX_CONFIGURATOR
#define RGB_MATRIX_STARTUP_SPD 60

//---- QMK ---------------------------------------------------------------------
#undef TAPPING_TERM
#define TAPPING_TERM 240

// #define PERMISSIVE_HOLD

//---- Sunaku ------------------------------------------------------------------
#define BILATERAL_COMBINATIONS
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4 /* GUI, Alt, Ctrl, Shift */
#define BILATERAL_COMBINATIONS_DELAY_MODS_THAT_MATCH MOD_MASK_GUI
#define BILATERAL_COMBINATIONS_DELAY_MATCHED_MODS_BY 120  /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER 80   /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_SAMESIDED_AFTER 3000 /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 160  /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_MODMASK (~MOD_MASK_SHIFT)


//---- USB ---------------------------------------------------------------------
#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"OooD3/yggpB"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define HCS(report) host_consumer_send(record->event.pressed ? report : 0); return false


