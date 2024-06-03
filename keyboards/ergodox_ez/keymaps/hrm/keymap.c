#include "keycodes.h"
#include QMK_KEYBOARD_H

#include <lib/achordion/achordion.h>
// Layers
enum layers {
	BASE_L,  // Default
	ALT_L,   // Alternative Layout
	PAD_L,   // Keypad
	SYM_L,   // Symbols
	NAV_L,   // Navigation
	MED_L,   // Media
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

// Tap Dance keycods
enum td_keycodes {
	TD_ALT_ASTR,   // Hold = Alt    , Tap = '*'
	TD_ALT_TILDE,  // Hold = Alt    , Tap = '~'
	TD_ALT_DQUO,   // Hold = Alt    , Tap = '"'
	TD_CTL_LPRN,   // Hold = Ctrl   , Tap = '('
	TD_CTL_DOLLAR, // Hold = Ctrl   , Tap = '$'
	TD_GUI_COLN,   // Hold = Super  , Tap = ':'
	TD_GUI_RPRN,   // Hold = Super  , Tap = ')'
};

// // Keyboard Zones
// enum kb_zones {
// 	ZN_LP,      // Left  Palm
// 	ZN_LT,      // Left  Thumb
// 	ZN_RP,      // Right Palm
// 	ZN_RH,      // Right Thumb
// };

typedef struct {
	uint16_t tap;
	uint16_t hold;
	uint16_t held;
} td_tap_hold_t;

// const enum kb_zones keyboard_zones[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_ergodox_pretty(
// 		ZN_LP, ZN_LP, ZN_LP, ZN_LP, ZN_LP, ZN_LP,           ZN_LP,                              XXXXXXX,  KC_6,       KC_7,               KC_8,           KC_9,                   KC_0,               KC_MINUS,
// 		ZN_LP, ZN_LP, ZN_LP, ZN_LP, ZN_LP,               ZN_LP,           ZN_LP,                                    KC_WH_U,    KC_Y,       KC_U,               KC_I,           KC_O,                   KC_P,               KC_DOUBLE_QUOTE,
// 		ZN_LP, ZN_LP, ZN_LP, ZN_LP, ZN_LP,        ZN_LP,                                                                   KC_H,       GUI_T(KC_J),        CTL_T(KC_K),    SFT_T(KC_L),            ALT_T(KC_SCLN),     KC_QUOTE,
// 		ZN_LP, ZN_LP, ZN_LP, ZN_LP, ZN_LP,               ZN_LP,           ZN_LP,                                     KC_WH_D,    KC_N,       KC_M,               XXXXXXX,        KC_DOT,                 KC_SLASH,           KC_COMMA,
// 		ZN_LP, ZN_LP, ZN_LP, ZN_LP, ZN_LP,                                                                                               KC_DOWN,            KC_UP,          KC_LEFT_ALT,            KC_RIGHT_SHIFT,     KC_RIGHT_CTRL,
// 		                                                                                                                        KC_PSCR,    TG(MED_L),          TG(PAD_L),  TG(NAV_L),
// 		                                                                                                                                    KC_SLEP,            KC_DELETE,
// 		                                                                                            LT(PAD_L,KC_SPC),     GUI_T(KC_TAB),   LT(NAV_L,KC_ESC),    CW_TOGG,    RCTL_T(KC_BACKSPACE),    LT(SYM_L,KC_ENTER)
// 		);

// clang-format off
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
		KC_EQUAL,           KC_1,               KC_2,               KC_3,               KC_4,               KC_5,           KC_CALCULATOR,                              TO(ALT_L),  KC_6,       KC_7,               KC_8,           KC_9,                   KC_0,               KC_MINUS,
		XXXXXXX,            XXXXXXX,            KC_W,               KC_E,               KC_R,               KC_T,           KC_HOME,                                    KC_WH_U,    KC_Y,       KC_U,               KC_I,           KC_O,                   KC_P,               KC_BACKSLASH,
		KC_Q,               ALT_T(KC_A),        SFT_T(KC_S),        CTL_T(KC_D),        GUI_T(KC_F),        KC_G,                                                                   KC_H,       GUI_T(KC_J),        CTL_T(KC_K),    SFT_T(KC_L),            ALT_T(KC_SCLN),     KC_Z,
		LSFT_T(KC_Z),       XXXXXXX,            KC_X,               KC_C,               KC_V,               KC_B,           KC_END,                                     KC_WH_D,    KC_N,       KC_M,               KC_P,           KC_DOT,                 KC_SLASH,           RSFT_T(KC_COMMA),
		KC_LEFT_CTRL,       KC_LEFT_ALT,        KC_GRAVE,           KC_LEFT,            KC_RIGHT,                                                                                               KC_DOWN,            KC_UP,          KC_LEFT_ALT,            KC_RIGHT_SHIFT,     KC_RIGHT_CTRL,
		                                                                                                                        KC_PSCR,    TG(MED_L),          TG(PAD_L),  TG(NAV_L),
		                                                                                                                                    KC_SLEP,            KC_DELETE,
		                                                                                            LT(PAD_L,KC_SPC),     GUI_T(KC_TAB),   LT(NAV_L,KC_ESC),    CW_TOGG,    RCTL_T(KC_BACKSPACE),    LT(SYM_L,KC_ENTER)
	),

	//------------------------------------------------------------------------------------------------------------------------------------- Alt Layout ----------------------------------------------------------------------------------------------------------------------------
	[ALT_L] = LAYOUT_ergodox_pretty(
		KC_EQUAL,           KC_1,               KC_2,               KC_3,               KC_4,               KC_5,           KC_CALCULATOR,                              TO(BASE_L), KC_6,       KC_7,               KC_8,           KC_9,                   KC_0,               KC_MINUS,
		XXXXXXX,            XXXXXXX,            KC_C,               KC_O,               KC_U,               KC_MINUS,       KC_HOME,                                    KC_WH_U,    KC_X,       KC_R,               KC_N,           KC_D,                   XXXXXXX,            KC_BACKSLASH,
		KC_Q,               ALT_T(KC_V),        SFT_T(KC_I),        CTL_T(KC_A),        GUI_T(KC_E),        KC_DOT,                                                                 KC_H,       GUI_T(KC_L),        CTL_T(KC_S),    SFT_T(KC_T),            ALT_T(KC_M),        KC_Z,
		LSFT_T(KC_Z),       KC_B,               KC_Y,               KC_J,               KC_K,               KC_SEMICOLON,   KC_END,                                     KC_WH_D,    KC_SLASH,   KC_F,               KC_P,           KC_G,                   KC_W,               RSFT_T(KC_COMMA),
		KC_LEFT_CTRL,       KC_LEFT_ALT,        KC_GRAVE,           KC_LEFT,            KC_RIGHT,                                                                                               KC_DOWN,            KC_UP,          KC_LEFT_ALT,            KC_RIGHT_SHIFT,     KC_RIGHT_CTRL,
		                                                                                                                        KC_PSCR,   TG(MED_L),           TG(PAD_L),  TG(NAV_L),
		                                                                                                                                   KC_SLEP,             KC_DELETE,
		                                                                                            LT(PAD_L,KC_SPC),     GUI_T(KC_TAB),   LT(NAV_L,KC_ESC),    CW_TOGG,    RCTL_T(KC_BACKSPACE),    LT(SYM_L,KC_ENTER)
	),

	//------------------------------------------------------------------------------------------------------------------------------------- Keypad --------------------------------------------------------------------------------------------------------------------------------
	[PAD_L] = LAYOUT_ergodox_pretty(
		KC_F12,             KC_F1,              KC_F2,              KC_F3,              KC_F4,              KC_F5,          _______,                                    _______,    KC_F6,      KC_F7,              KC_F8,              KC_F9,              KC_F10,             KC_F11,
		_______,            XXXXXXX,            KC_CUT,             KC_COPY,            KC_PASTE,           XXXXXXX,        XXXXXXX,                                    _______,    KC_MINUS,   KC_7,               KC_8,               KC_9,               KC_BACKSLASH,       KC_COMMA,
		TO(BASE_L),         KC_LEFT_ALT,        SFT_T(KC_LEFT),     CTL_T(KC_UP),       GUI_T(KC_DOWN),     KC_RIGHT,                                                               KC_EQUAL,   GUI_T(KC_4),        CTL_T(KC_5),        SFT_T(KC_6),        TD(TD_ALT_ASTR),    KC_ENTER,
		_______,            XXXXXXX,            KC_CUT,             KC_COPY,            KC_PASTE,           KC_COMMA,       XXXXXXX,                                    _______,    KC_PLUS,    KC_1,               KC_2,               KC_3,               KC_DOT,             KC_TAB,
		_______,            _______,            _______,            _______,            _______,                                                                                                _______,            _______,            _______,            _______,            _______,
		                                                                                                                        _______,    _______,            _______,    _______,
		                                                                                                                                    _______,            _______,
		                                                                                                _______,                _______,    _______,            KC_SPACE,   _______,    KC_0
	),

	//------------------------------------------------------------------------------------------------------------------------------------- Symbols -------------------------------------------------------------------------------------------------------------------------------
	[SYM_L] = LAYOUT_ergodox_pretty(
		KC_PLUS,            KC_EXCLAIM,         KC_AT,              KC_HASH,            KC_DOLLAR,          KC_PERCENT,     _______,                                    _______,    KC_CIRC,    KC_AMPERSAND,       KC_ASTERISK,        KC_LEFT_PAREN,      KC_RIGHT_PAREN,     _______,
		_______,            XXXXXXX,            KC_EXCLAIM,         KC_LCBR,            KC_RCBR,            KC_PERCENT,     XXXXXXX,                                    XXXXXXX,    KC_AMPR,    KC_LT,              KC_GT,              KC_PLUS,            XXXXXXX,            _______,
		_______,            TD(TD_ALT_DQUO),    KC_QUOTE,           TD(TD_CTL_LPRN),    TD(TD_GUI_RPRN),    KC_TILDE,                                                               KC_BSLS,    TD(TD_GUI_COLN),    CTL_T(KC_COMMA),    KC_DOLLAR,          KC_LEFT_ALT,        XXXXXXX,
		_______,            KC_SPACE,           KC_QUESTION,        KC_LEFT_BRACKET,    KC_RIGHT_BRACKET,   KC_CIRC,        XXXXXXX,                                    XXXXXXX,    KC_AT,      KC_PIPE,            KC_GRAVE,           KC_BACKSPACE,       _______,            _______,
		_______,            _______,            _______,            _______,            _______,                                                                                                _______,            _______,            _______,            _______,            _______,
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
// clang-format on

static bool on_thumb_cluster(keypos_t pos) {
#ifdef SPLIT_KEYBOARD
	return pos.col == MATRIX_COLS - 1;
#else
	return (MATRIX_ROWS < MATRIX_COLS) ? pos.row == MATRIX_ROWS - 1
                                           : pos.col == MATRIX_COLS - 1;
#endif
}

bool opposite_clusters(const keyrecord_t* tap_hold_record, const keyrecord_t* other_record)
{
	return on_thumb_cluster(tap_hold_record->event.key) !=
		on_thumb_cluster(other_record->event.key);
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
		uint16_t other_keycode,    keyrecord_t* other_record)
{
	return achordion_opposite_hands(tap_hold_record, other_record) ||
		opposite_clusters(tap_hold_record, other_record);
}

void matrix_scan_user(void)
{
	achordion_task();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	tap_dance_action_t *action;

	if (!process_achordion(keycode, record)) {
		return false;
	}

	switch (keycode) {
	case QK_TAP_DANCE...QK_TAP_DANCE_MAX:
		action = &tap_dance_actions[TD_INDEX(keycode)];
		if (!record->event.pressed && action->state.count &&
		    !action->state.finished) {
			td_tap_hold_t *tap_hold =
				(td_tap_hold_t *)action->user_data;
			tap_code16(tap_hold->tap);
		}
		return true;
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
			rgblight_sethsv(0, 255, 255);
		}
		return false;
	case HSV_2:
		if (record->event.pressed) {
			rgblight_mode(1);
			rgblight_sethsv(43, 255, 255);
		}
		return false;
	case HSV_3:
		if (record->event.pressed) {
			rgblight_mode(1);
			rgblight_sethsv(86, 255, 255);
		}
		return false;
	case HSV_4:
		if (record->event.pressed) {
			rgblight_mode(1);
			rgblight_sethsv(129, 255, 255);
		}
		return false;
	case HSV_5:
		if (record->event.pressed) {
			rgblight_mode(1);
			rgblight_sethsv(172, 255, 255);
		}
		return false;
	}
	return true;
}

void td_tap_hold_finished(tap_dance_state_t *state, void *user_data)
{
	td_tap_hold_t *tap_hold = (td_tap_hold_t *)user_data;

	if (state->pressed) {
		if (state->count == 1
#ifndef PERMISSIVE_HOLD
		    && !state->interrupted
#endif
		) {
			register_code16(tap_hold->hold);
			tap_hold->held = tap_hold->hold;
		} else {
			register_code16(tap_hold->tap);
			tap_hold->held = tap_hold->tap;
		}
	}
}

void td_tap_hold_reset(tap_dance_state_t *state, void *user_data)
{
	td_tap_hold_t *tap_hold = (td_tap_hold_t *)user_data;

	if (tap_hold->held != KC_NO) {
		unregister_code16(tap_hold->held);
		tap_hold->held = KC_NO;
	}
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                             \
	{                                                                \
		.fn = { NULL, td_tap_hold_finished, td_tap_hold_reset }, \
		.user_data = (void *)&((td_tap_hold_t){ tap, hold, 0 }), \
	}

tap_dance_action_t tap_dance_actions[] = {
	[TD_ALT_ASTR]   = ACTION_TAP_DANCE_TAP_HOLD(KC_ASTERISK,     KC_LEFT_ALT),
	[TD_ALT_DQUO]   = ACTION_TAP_DANCE_TAP_HOLD(KC_DOUBLE_QUOTE, KC_LEFT_ALT),
	[TD_ALT_TILDE]  = ACTION_TAP_DANCE_TAP_HOLD(KC_TILDE,        KC_LEFT_ALT),
	[TD_CTL_LPRN]   = ACTION_TAP_DANCE_TAP_HOLD(KC_LEFT_PAREN,   KC_LEFT_CTRL),
	[TD_CTL_DOLLAR] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOLLAR,       KC_LEFT_CTRL),
	[TD_GUI_COLN]   = ACTION_TAP_DANCE_TAP_HOLD(KC_COLON,        KC_LEFT_GUI),
	[TD_GUI_RPRN]   = ACTION_TAP_DANCE_TAP_HOLD(KC_RIGHT_PAREN,  KC_LEFT_GUI),
};

void set_mod_leds(void)
{
	uint8_t mod_state = get_mods();
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();

	if (mod_state & MOD_MASK_CTRL) {
		ergodox_right_led_1_on();
	}
	if (mod_state & MOD_MASK_SHIFT) {
		ergodox_right_led_2_on();
	}
	if (mod_state & MOD_MASK_GUI) {
		ergodox_right_led_3_on();
	}
}

uint8_t layer_state_set_user(uint8_t state)
{
	uint8_t layer = biton(state);
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
	switch (layer) {
	case SYM_L:
		ergodox_right_led_1_on();
		break;
	case PAD_L:
		ergodox_right_led_2_on();
		break;
	case NAV_L:
		ergodox_right_led_3_on();
		break;
	case MED_L:
		ergodox_right_led_1_on();
		ergodox_right_led_2_on();
		break;
	// case ALT_L:
	// 	ergodox_right_led_1_on();
	// 	ergodox_right_led_3_on();
	// 	break;
	// case 6:
	// 	ergodox_right_led_2_on();
	// 	ergodox_right_led_3_on();
	// 	break;
	// case 7:
	// 	ergodox_right_led_1_on();
	// 	ergodox_right_led_2_on();
	// 	ergodox_right_led_3_on();
	// 	break;
	default:
		break;
	}
	return state;
};
