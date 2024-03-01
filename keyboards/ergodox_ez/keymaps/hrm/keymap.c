#include QMK_KEYBOARD_H
#include "version.h"

// Layers
enum layers {
    BASE_L, // Default
    PAD_L,  // Keypad
    SYM_L,  // Symbols
    NAV_L,  // Navigation
    MED_L,  // Media
    ALT_L,  // Alt-Layout
    // NUM_L,  // Numbers & Function
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
 * | Del    |   Q  |   W  |   E  |   R  |   T  | Home |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
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
        _______,            KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,           KC_HOME,                                    KC_WH_U,    KC_Y,       KC_U,               KC_I,           KC_O,                   KC_P,               KC_BACKSLASH,
        _______,            ALT_T(KC_A),        SFT_T(KC_S),        CTL_T(KC_D),        GUI_T(KC_F),        KC_G,                                                                   KC_H,       GUI_T(KC_J),        CTL_T(KC_K),    SFT_T(KC_L),            ALT_T(KC_SCLN),     KC_QUOTE,
        _______,            KC_Z,               KC_X,               KC_C,               KC_V,               KC_B,           KC_END,                                     KC_WH_D,    KC_N,       KC_M,               KC_COMMA,       KC_DOT,                 KC_SLASH,           _______,
        KC_LEFT_CTRL,       KC_LEFT_SHIFT,      XXXXXXX,            KC_LEFT,            KC_RIGHT,                                                                                               KC_DOWN,            KC_UP,          XXXXXXX,               KC_RIGHT_SHIFT,     KC_RIGHT_CTRL,
                                                                                                                            KC_PSCR,    TG(MED_L),          TG(PAD_L),  TG(NAV_L),
                                                                                                                                        KC_F11,             KC_DELETE,
                                                                                                LT(PAD_L,KC_SPC),     GUI_T(KC_TAB),    KC_ESCAPE,           CW_TOGG,    CTL_T(KC_BACKSPACE),    LT(SYM_L,KC_ENTER)
    ),

    //------------------------------------------------------------------------------------------------------------------------------------- Keypad --------------------------------------------------------------------------------------------------------------------------------
    [PAD_L] = LAYOUT_ergodox_pretty(
        KC_F12,             KC_F1,              KC_F2,              KC_F3,              KC_F4,              KC_F5,          _______,                                    _______,    KC_F6,      KC_F7,              KC_F8,              KC_F9,              KC_F10,             KC_F11,
        _______,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,        XXXXXXX,                                    _______,    KC_MINUS,   KC_7,               KC_8,               KC_9,               KC_MINUS,           _______,
        TO(BASE_L),         KC_LEFT_ALT,        KC_LEFT_SHIFT,        KC_LEFT_CTRL,       KC_LEFT_GUI,      XXXXXXX,                                                                KC_EQUAL,   KC_4,               KC_5,               KC_6,               KC_ASTR,            KC_ENTER,
        _______,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,        XXXXXXX,                                    _______,    KC_PLUS,    KC_1,               KC_2,               KC_3,               KC_BSLS,            KC_TAB,
        _______,            _______,            _______,            _______,            _______,                                                                                                _______,            _______,            KC_DOT,             _______,            _______,
                                                                                                                            _______,    _______,            _______,    _______,
                                                                                                                                        _______,            _______,
                                                                                                    _______,                _______,    _______,            _______,    _______,    KC_0
    ),

    //------------------------------------------------------------------------------------------------------------------------------------- Alternative Layout---------------------------------------------------------------------------------------------------------------------
    [ALT_L] = LAYOUT_ergodox_pretty(
        KC_EQUAL,           KC_1,               KC_2,               KC_3,               KC_4,               KC_5,           KC_CALCULATOR,                              _______,    KC_6,       KC_7,               KC_8,           KC_9,                   KC_0,               KC_MINUS,
        _______,            KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,           KC_HOME,                                    KC_WH_U,    KC_Y,       KC_U,               KC_I,           KC_O,                   KC_P,               KC_BACKSLASH,
        _______,            ALT_T(KC_A),        SFT_T(KC_S),        CTL_T(KC_D),        GUI_T(KC_F),        KC_G,                                                                   KC_H,       GUI_T(KC_J),        CTL_T(KC_K),    SFT_T(KC_L),            ALT_T(KC_SCLN),     KC_QUOTE,
        _______,            KC_Z,               KC_X,               KC_C,               KC_V,               KC_B,           KC_END,                                     KC_WH_D,    KC_N,       KC_M,               KC_COMMA,       KC_DOT,                 KC_SLASH,           _______,
        KC_LEFT_CTRL,       KC_LEFT_SHIFT,      KC_LEFT,            KC_RIGHT,           KC_LGUI,                                                                                                KC_RIGHT_CTRL,      KC_DOWN,        KC_UP,                  KC_RIGHT_SHIFT,     KC_RIGHT_CTRL,
                                                                                                                            KC_PSCR,    TG(MED_L),          TG(PAD_L),  TG(NAV_L),
                                                                                                                                        _______,             KC_DELETE,
                                                                                                    LT(PAD_L,KC_SPC),       KC_TAB,     KC_ESCAPE,          CW_TOGG,    KC_BSPC,    LT(SYM_L,KC_ENTER)
    ),

    //------------------------------------------------------------------------------------------------------------------------------------- Symbols -------------------------------------------------------------------------------------------------------------------------------
    [SYM_L] = LAYOUT_ergodox_pretty(
         KC_EQUAL,          KC_EXCLAIM,         KC_AT,              KC_HASH,            KC_DOLLAR,          KC_PERCENT,     _______,                                    _______,    KC_CIRC,    KC_AMPERSAND,       KC_ASTERISK,        KC_LEFT_PAREN,      KC_RIGHT_PAREN,     _______,
        _______,            XXXXXXX,            KC_EXCLAIM,         KC_LCBR,            KC_RCBR,            XXXXXXX,        XXXXXXX,                                    XXXXXXX,    XXXXXXX,    KC_LT,              KC_GT,              KC_QUESTION,        XXXXXXX,            _______,
        _______,            KC_GRAVE,           KC_TILD,            KC_LEFT_PAREN,      KC_RIGHT_PAREN,     KC_PERCENT,                                                             KC_CIRC,    KC_COLON,           KC_COMMA,           KC_QUOTE,           KC_DOUBLE_QUOTE,    _______,
        _______,            XXXXXXX,            KC_PLUS,            KC_LEFT_BRACKET,    KC_RIGHT_BRACKET,   XXXXXXX,        XXXXXXX,                                    XXXXXXX,    XXXXXXX,    KC_PIPE,            KC_BACKSLASH,       _______,            _______,            _______,
        _______,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,                                                                                                _______,            _______,            _______,            _______,            _______,
                                                                                                                            _______,    _______,            _______,    _______,
                                                                                                                                        _______,            _______,
                                                                                                            KC_UNDERSCORE,  KC_EQUAL,   _______,            _______,    _______,        _______
    ),

    //------------------------------------------------------------------------------------------------------------------------------------- Navigation ----------------------------------------------------------------------------------------------------------------------------
    [NAV_L] = LAYOUT_ergodox_pretty(
        _______,            _______,            _______,            _______,            KC_END,             _______,        _______,                                    _______,    _______,    _______,            _______,            _______,            _______,            _______,
        _______,            _______,            _______,            _______,            _______,            _______,        _______,                                    _______,    KC_HOME,    KC_PGDN,            KC_PGUP,            KC_END,             _______,            _______,
        _______,            _______,            C(KC_X),            C(KC_C),            RCS(KC_V),          _______,                                                                KC_LEFT,    KC_DOWN,            KC_UP,              KC_RGHT,            _______,            _______,
        _______,            _______,            _______,            _______,            _______,            _______,        _______,                                    _______,    KC_WH_L,    KC_WH_D,            KC_WH_U,            KC_WH_R,            _______,            _______,
        _______,            _______,            _______,            _______,            _______,                                                                                                _______,            _______,            _______,            _______,            _______,
                                                                                                                            _______,    _______,            _______,    _______,
                                                                                                                                        _______,            _______,
                                                                                                            _______,        _______,    _______,            _______,    _______,        _______
),

    //-------------------------------------------------------------------------------------------------------------------------------------- Media --------------------------------------------------------------------------------------------------------------------------------
    [MED_L] = LAYOUT_ergodox_pretty(
        _______,            HSV_0,              HSV_2,              HSV_3,              HSV_4,              HSV_5,          _______,                                    _______,    _______,    _______,            _______,            _______,            _______,            MAC_LOCK,
        TO(BASE_L),         _______,            _______,            RGB_SPD,            RGB_SPI,            RGB_SLD,        _______,                                    _______,    _______,    KC_BRID,            KC_BRIU,            _______,            _______,            KC_SLEP,
        _______,            _______,            LED_LEVEL,          RGB_VAD,            RGB_VAI,            RGB_TOG,                                                                KC_MPLY,    KC_VOLD,            KC_VOLU,            KC_MUTE,            _______,            KC_WAKE,
        _______,            _______,            TOGGLE_LAYER_COLOR, RGB_HUD,            RGB_HUI,            RGB_MOD,        _______,                                    _______,    KC_MSTP,    KC_MPRV,            KC_MNXT,            _______,            _______,            KC_PWR,
        _______,            _______,            _______,            RGB_SAD,            RGB_SAI,                                                                                                _______,            _______,            _______,            _______,            _______,
                                                                                                                            _______,    _______,            _______,    _______,
                                                                                                                                        _______,            _______,
                                                                                                            KC_MYCM,        KC_WSCH,    _______,            _______,    KC_WHOM,    KC_CALC
    ),

};


//
//     //------------------------------------------------------------------------------------------------------------------------------------- Numbers & Function --------------------------------------------------------------------------------------------------------------------
//     [NUM_L] = LAYOUT_ergodox_pretty(
//         _______,            _______,            _______,            _______,            _______,            _______,        _______,                                    _______,    _______,    _______,            _______,            _______,            _______,            _______,
//         _______,            _______,            _______,            _______,            _______,            _______,        _______,                                    _______,    _______,    _______,            _______,            _______,            _______,            _______,
//         _______,            _______,            _______,            _______,            _______,            _______,                                                                _______,    _______,            _______,            _______,            _______,            _______,
//         _______,            _______,            _______,            _______,            _______,            _______,        _______,                                    _______,    _______,    _______,            _______,            _______,            _______,            _______,
//         _______,            _______,            _______,            _______,            _______,                                                                                                _______,            _______,            _______,            _______,            _______,
//                                                                                                                             _______,    _______,            _______,    _______,
//                                                                                                                                         _______,            _______,
//                                                                                                             _______,        _______,    _______,            _______,    _______,        _______
// ),



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
