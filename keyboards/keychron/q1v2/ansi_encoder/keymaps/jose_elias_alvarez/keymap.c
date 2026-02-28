// vim: set nowrap:
#include "process_combo.h"
#include "rgb_matrix.h"
#include QMK_KEYBOARD_H

#define CTL_ESC MT(MOD_LCTL, KC_ESC)

enum layers {
    _BASE,
    _GAME,
    _NAV,
    _FN,
};
#define NAV LT(_NAV, KC_SPC)
#define FN MO(_FN)

#define BASE_RGB RGB_MATRIX_TYPING_HEATMAP
#define GAME_RGB RGB_MATRIX_DIGITAL_RAIN

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

enum combos { DF_ENTER, JK_ESCAPE, COMBO_LEN };
combo_t key_combos[COMBO_LEN] = {
    [DF_ENTER]  = COMBO(df_combo, KC_ENT),
    [JK_ESCAPE] = COMBO(jk_combo, KC_ESC),
};

static void dance_caps(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        SEND_STRING(SS_TAP(X_CAPS));
    } else {
        caps_word_toggle();
    }
    reset_tap_dance(state);
}

enum tap_dance_ids {
    TD_CAPS,
    TAP_DANCE_LEN,
};
tap_dance_action_t tap_dance_actions[TAP_DANCE_LEN] = {
    [TD_CAPS] = ACTION_TAP_DANCE_FN(dance_caps),
};

#define CAPS TD(TD_CAPS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        OS_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              CAPS,     KC_UP,
        KC_CAPS,  KC_LALT,  KC_LGUI,                                NAV,                                    KC_RALT,  FN,         KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_GAME] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_END,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RALT,  FN,         KC_RALT,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_NAV] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        KC_LCTL,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,              _______,            _______,
        KC_LSFT,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              KC_RSFT,  _______,
        _______,  KC_LALT,  KC_LGUI,                                _______,                                KC_RALT,  _______,    KC_RCTL,  _______,  _______,  _______),

    [_FN] = LAYOUT_ansi_82(
        _______,  KC_BRIU,  KC_BRID,  KC_MCTL,  KC_LPAD,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  QK_BOOT,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),
};
// clang-format on

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_GAME] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NAV]  = {ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [_FN]   = {ENCODER_CCW_CW(RM_VALD, RM_VALU)},
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    (void)record;
    switch (keycode) {
        case CTL_ESC:
            return true;
        default:
            return false;
    }
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        default_layer_set(1UL << (active ? _GAME : _BASE));
        return false;
    }
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            rgb_matrix_mode(BASE_RGB);
            combo_enable();
            break;
        case _GAME:
            rgb_matrix_mode(GAME_RGB);
            combo_disable();
            break;
        default:
            rgb_matrix_disable();
            combo_disable();
    }
    return state;
}
