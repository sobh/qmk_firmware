#include "keycodes.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "version.h"

// Layers
enum layers {
    BASE_L, // Default
    NUM_L,  // Numbers & Symbols
    SYM_L,  // Symbols
    FUN_L,  // Functions (F1 - F24)
    NAV_L,  // Navigation
    MED_L,  // Media
};

enum custom_keycodes {
    RGB_SLD = SAFE_RANGE,
    HSV_0,
    HSV_2,
    HSV_3,
    HSV_4,
    HSV_5,
    MAC_LOCK,
};

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Calc |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |    '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Alt |   `  | Left | Right|                                       | Down |  Up  |   [  |   ]  | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //------------------------------------------------------------------------------------------------------------------------------------- Base ----------------------------------------------------------------------------------------------------------------------------------
    [BASE_L] = LAYOUT_ergodox_pretty(
        KC_EQUAL,           KC_1,               KC_2,               KC_3,               KC_4,               KC_5,           KC_CALCULATOR,                              _______,    KC_6,       KC_7,               KC_8,           KC_9,                   KC_0,               KC_MINUS,
        LT(MED_L,KC_TAB),   KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,           KC_PGUP,                                    KC_HOME,    KC_Y,       KC_U,               KC_I,           KC_O,                   KC_P,               KC_BSLS,
        LT(NAV_L,KC_ESC),   LALT_T(KC_A),       LGUI_T(KC_S),       LCTL_T(KC_D),       LSFT_T(KC_F),       KC_G,                                                                   KC_H,       RSFT_T(KC_J),       RCTL_T(KC_K),   RGUI_T(KC_L),           LALT_T(KC_SCLN),    KC_QUOTE,
        SC_LSPO,            KC_Z,               KC_X,               KC_C,               KC_V,               KC_B,           KC_PGDN,                                    KC_END,     KC_N,       KC_M,               KC_COMMA,       KC_DOT,                 KC_SLASH,           SC_RSPC,
        KC_LCTL,            KC_LALT,            KC_GRAVE,           KC_LEFT,            KC_RIGHT,                                                                                               KC_DOWN,            KC_UP,          KC_LBRC,                KC_RBRC,            KC_RIGHT_CTRL,
                                                                                                                            KC_PSCR,    TG(FUN_L),          TG(NUM_L),  TG(NAV_L),
                                                                                                                                        KC_F11,                         KC_DELETE,
                                                                                                LT(NUM_L,KC_SPC),    LGUI_T(KC_TAB),    KC_ESC,             CW_TOGG,    RGUI_T(KC_BSPC),    LT(SYM_L,KC_ENTER)
    ),

    //------------------------------------------------------------------------------------------------------------------------------------- Numbers -------------------------------------------------------------------------------------------------------------------------------
    [NUM_L] = LAYOUT_ergodox_pretty(
        KC_F12,             KC_F1,              KC_F2,              KC_F3,              KC_F4,              KC_F5,          _______,                                    _______,    KC_F6,      KC_F7,              KC_F8,              KC_F9,              KC_F10,             KC_F11,
        _______,            KC_LABK,            KC_RABK,            KC_LCBR,            KC_RCBR,            XXXXXXX,        _______,                                    _______,    KC_MINUS,   KC_7,               KC_8,               KC_9,               KC_MINUS,           _______,
        TO(BASE_L),         LALT_T(KC_TILD),    LGUI_T(KC_DOLLAR),  LCTL_T(KC_GRAVE),   LSFT_T(KC_MINUS),   KC_PIPE,                                                                KC_EQUAL,   KC_4,               KC_5,               KC_6,               KC_ASTR,            KC_ENTER,
        _______,            KC_LPRN,            KC_RPRN,            KC_LBRC,            KC_RBRC,            KC_BSLS,        _______,                                    _______,    KC_PLUS,    KC_1,               KC_2,               KC_3,               _______,            KC_TAB,
        _______,            _______,            _______,            _______,            _______,                                                                                                _______,            _______,            KC_DOT,             _______,            _______,
                                                                                                                            _______,    _______,            _______,    _______,
                                                                                                                                        _______,            _______,
                                                                                                    _______,                _______,    _______,            _______,    _______,    KC_0
    ),

    //------------------------------------------------------------------------------------------------------------------------------------- Symbols -------------------------------------------------------------------------------------------------------------------------------
    [SYM_L] = LAYOUT_ergodox_pretty(
         KC_F12,            KC_F1,              KC_F2,              KC_F3,              KC_F4,              KC_F5,          _______,                                    _______,    KC_F6,      KC_F7,              KC_F8,              KC_F9,              KC_F10,             KC_F11,
        _______,            XXXXXXX,            KC_TILDE,           KC_LCBR,            KC_RCBR,            XXXXXXX,        XXXXXXX,                                    XXXXXXX,    KC_CIRC,    KC_LT,              KC_GT,              KC_GRAVE,           XXXXXXX,            _______,
        TO(BASE_L),         LALT_T(KC_ASTR),    LGUI_T(KC_DOLLAR),  LCTL_T(KC_EQUAL),   LSFT_T(KC_COMMA),   KC_PERC,                                                                KC_AMPR,    RSFT_T(KC_COLON),   RCTL_T(KC_QUOT),    RGUI_T(KC_DQT),     LALT_T(KC_SCLN),    _______,
        _______,            KC_PLUS,            KC_HASH,            KC_LBRC,            KC_RBRC,            KC_AT,          XXXXXXX,                                    XXXXXXX,    KC_QUES,    KC_LPRN,            KC_RPRN,            KC_EXLM,            KC_PIPE,            _______,
        _______,            _______,            _______,            _______,            _______,                                                                                                _______,            _______,            _______,            _______,            _______,
                                                                                                                            _______,    _______,            _______,    _______,
                                                                                                                                        _______,            _______,
                                                                                                            KC_SLSH,        KC_BSLS,    _______,            _______,    _______,        _______
    ),

    //------------------------------------------------------------------------------------------------------------------------------------- Function ------------------------------------------------------------------------------------------------------------------------------
    [FUN_L] = LAYOUT_ergodox_pretty(
        _______,            _______,            _______,            _______,            _______,            _______,        _______,                                    _______,   _______,     _______,            _______,            _______,            _______,            _______,
        _______,            XXXXXXX,            KC_F19,             KC_F16,             KC_F17,             KC_F22,         _______,                                    _______,   KC_F24,      KC_F7,              KC_F8,              KC_F9,              XXXXXXX,            _______,
        TO(BASE_L),         KC_F20,             LGUI_T(KC_F16),     LCTL_T(KC_F15),     LSFT_T(KC_F14),     KC_F22,                                                                KC_F23,      LSFT_T(KC_F4),      RCTL_T(KC_F5),      RGUI_T(KC_F6),      KC_F10,             _______,
        _______,            XXXXXXX,            KC_F13,             KC_F12,             KC_F11,             XXXXXXX,        _______,                                    _______,   XXXXXXX,     KC_F1,              KC_F2,              KC_F3,              XXXXXXX,            _______,
        _______,            _______,            _______,            _______,            _______,                                                                                                _______,            _______,            _______,            _______,            _______,
                                                                                                                            _______,    _______,            _______,    _______,
                                                                                                                                        _______,            _______,
                                                                                                            _______,        _______,    _______,            _______,    _______,        _______
    ),

    //------------------------------------------------------------------------------------------------------------------------------------- Navigation ----------------------------------------------------------------------------------------------------------------------------
    [NAV_L] = LAYOUT_ergodox_pretty(
        _______,            _______,            _______,            _______,            KC_END,             _______,        _______,                                    _______,    KC_HOME,    _______,            _______,            _______,            _______,            _______,
        _______,            _______,            LCTL(KC_RIGHT),     _______,            _______,            _______,        _______,                                    _______,    _______,    KC_PGDN,            KC_PGUP,            _______,            _______,            _______,
        _______,            _______,            _______,            KC_DEL,             _______,            _______,                                                                KC_LEFT,    KC_DOWN,            KC_UP,              KC_RGHT,            _______,            _______,
        _______,            _______,            _______,            _______,            _______,            LCTL(KC_LEFT),  _______,                                    _______,    _______,    KC_END,             KC_HOME,            _______,            _______,            _______,
        _______,            _______,            _______,            _______,            _______,                                                                                                _______,            _______,            _______,            _______,            _______,
                                                                                                                            _______,    _______,            _______,    _______,
                                                                                                                                        _______,            _______,
                                                                                                            _______,        _______,    _______,            _______,    _______,        _______
),

    //-------------------------------------------------------------------------------------------------------------------------------------- Media --------------------------------------------------------------------------------------------------------------------------------
    [MED_L] = LAYOUT_ergodox_pretty(
        _______,            HSV_0,              HSV_2,              HSV_3,              HSV_4,              HSV_5,          _______,                                    _______,    _______,    _______,            _______,            _______,            _______,            MAC_LOCK,
        _______,            _______,            _______,            RGB_SPD,            RGB_SPI,            RGB_SLD,        _______,                                    _______,    _______,    KC_BRID,            KC_BRIU,            _______,            _______,            KC_SLEP,
        TO(BASE_L),         _______,            LED_LEVEL,          RGB_VAD,            RGB_VAI,            RGB_TOG,                                                                KC_MPLY,    KC_VOLD,            KC_VOLU,            KC_MUTE,            _______,            KC_WAKE,
        _______,            _______,            TOGGLE_LAYER_COLOR, RGB_HUD,            RGB_HUI,            RGB_MOD,        _______,                                    _______,    KC_MSTP,    KC_MPRV,            KC_MNXT,            _______,            _______,            KC_PWR,
        _______,            _______,            _______,            RGB_SAD,            RGB_SAI,                                                                                                _______,            _______,            _______,            _______,            _______,
                                                                                                                            _______,    _______,            _______,    _______,
                                                                                                                                        _______,            _______,
                                                                                                            KC_MYCM,        KC_WSCH,    _______,            _______,    KC_WHOM,    KC_CALC
    ),
};





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAC_LOCK:
            HCS(0x19E);

        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case HSV_0:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(0,255,255);
            }
            return false;
        case HSV_2:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(43,255,255);
            }
            return false;
        case HSV_3:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(86,255,255);
            }
            return false;
        case HSV_4:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(129,255,255);
            }
            return false;
        case HSV_5:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(172,255,255);
            }
            return false;
    }
    return true;
}

uint8_t layer_state_set_user(uint8_t state) {
    uint8_t layer = biton(state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
    return state;
};
