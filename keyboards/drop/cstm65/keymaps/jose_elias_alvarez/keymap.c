// vim: nowrap
#include "action_layer.h"
#include "keycodes.h"
#include "process_tap_dance.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include "rgb_matrix.h"
#include QMK_KEYBOARD_H

enum custom_keycodes { TOGGLE = SAFE_RANGE };

#define OS_LSFT OSM(MOD_LSFT)
#define CTL_ESC MT(MOD_LCTL, KC_ESC)

enum layers {
    _BASE,
    _GAME,
    _NAV,
    _FN,
};

#define FN MO(_FN)
#define NAV LT(_NAV, KC_SPC)

#define BASE_RGB RGB_MATRIX_TYPING_HEATMAP
#define GAME_RGB RGB_MATRIX_DIGITAL_RAIN

const uint16_t PROGMEM df_combo[]   = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[]   = {KC_J, KC_K, COMBO_END};
combo_t                key_combos[] = {
    COMBO(df_combo, KC_ENT),
    COMBO(jk_combo, KC_ESC),
};

enum {
    TD_GRV,
    TD_RALT_HYPR,
};

static void dance_grv(tap_dance_state_t *state, void *user_data) {
    SEND_STRING(state->count >= 2 ? "```" : "`");
    reset_tap_dance(state);
}

static void dance_ralt_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        tap_code16(HYPR(KC_SPC));
    } else {
        register_code(KC_RALT);
    }
}
static void dance_ralt_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count < 2) {
        unregister_code(KC_RALT);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_GRV]       = ACTION_TAP_DANCE_FN(dance_grv),
    [TD_RALT_HYPR] = ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE(NULL, NULL, dance_ralt_finished, dance_ralt_reset),
};

#define GRV TD(TD_GRV)
#define RALT_HYPR TD(TD_RALT_HYPR)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_65_ansi_blocker(
        GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, CW_TOGG,          KC_UP,   KC_PGDN,
        KC_CAPS, KC_LALT, KC_LGUI,                            NAV,                                FN,      RALT_HYPR, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_GAME] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             FN,      KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_NAV] =   LAYOUT_65_ansi_blocker(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,          XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_FN] =   LAYOUT_65_ansi_blocker(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  QK_BOOT, TOGGLE,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,          XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TOGGLE:
            if (record->event.pressed) {
                layer_invert(_GAME);
            }
            return false;
        default:
            return true;
    }
}

void keyboard_post_init_user() {
    rgb_matrix_mode_noeeprom(BASE_RGB);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _GAME:
            rgb_matrix_mode_noeeprom(GAME_RGB);
            combo_disable();
            break;
        case _BASE:
            rgb_matrix_mode_noeeprom(BASE_RGB);
            combo_enable();
    }
    return state;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_ESC:
            return true;
        default:
            return false;
    }
}
