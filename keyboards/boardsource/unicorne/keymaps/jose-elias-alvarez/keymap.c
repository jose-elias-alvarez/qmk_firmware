#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum layers {
    _BASE, //
    _NAV,
    _SYS,
    _NUM,
    _SYM,
    _FN,
};

// custom keys
enum custom_keycodes {
    TRI_GRV = SAFE_RANGE, //
    COPY,
    CUT,
    PASTE,
    ARROW,
};

#define OS_LSFT OSM(MOD_LSFT)

// layers
#define NAV_TAB LT(_NAV, KC_TAB)
#define SYS_BSL LT(_SYS, KC_BSLS)
#define SYM_BS LT(_SYM, KC_BSPC)
#define NUM_SP LT(_NUM, KC_SPC)
#define FN MO(_FN)

// home row mods
#define MOD_A MT(MOD_LALT, KC_A)
#define MOD_S MT(MOD_LCTL, KC_S)
#define MOD_D MT(MOD_LSFT, KC_D)
#define MOD_F MT(MOD_LGUI, KC_F)

#define MOD_J MT(MOD_RGUI, KC_J)
#define MOD_K MT(MOD_RSFT, KC_K)
#define MOD_L MT(MOD_RCTL, KC_L)
#define MOD_SC MT(MOD_RALT, KC_SCLN)

// combos
const uint16_t PROGMEM df_combo[]     = {MOD_D, MOD_F, COMBO_END};
const uint16_t PROGMEM jk_combo[]     = {MOD_J, MOD_K, COMBO_END};
const uint16_t PROGMEM comdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(df_combo, KC_ENT),
    COMBO(jk_combo, KC_ESC),
    COMBO(comdot_combo, ARROW),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_MINS, MOD_A,   MOD_S,   MOD_D,   MOD_F,   KC_G,       KC_H,    MOD_J,   MOD_K,   MOD_L,   MOD_SC,  KC_QUOT,
        CW_TOGG, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
                                   SYS_BSL, OS_LSFT, NAV_TAB,    SYM_BS,  NUM_SP,  FN
        ),
    [_NAV] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, CUT,     COPY,    PASTE,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
        ),
    [_SYS] = LAYOUT_split_3x6_3(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
        ),
    [_SYM] = LAYOUT_split_3x6_3(
        TRI_GRV, XXXXXXX, KC_AMPR, KC_ASTR, KC_LPRN, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, KC_LPRN, KC_RPRN,    XXXXXXX, XXXXXXX, XXXXXXX
        ),
    [_NUM] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PLUS,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_EQL,     XXXXXXX, KC_RGUI, KC_RSFT, KC_RCTL, KC_RALT, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_MINS,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, KC_0,    KC_0,       XXXXXXX, XXXXXXX, XXXXXXX
        ),
    [_FN] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, KC_F7,  KC_F8,   KC_F9,    KC_F12,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_F4,  KC_F5,   KC_F6,    KC_F11,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_F1,  KC_F2,   KC_F3,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                  XXXXXXX, KC_F10,   KC_F10,     XXXXXXX, XXXXXXX, XXXXXXX
        ),
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_TAB:
            return 115;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case TRI_GRV:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            break;
        case COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("c"));
            }
            break;
        case CUT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("x"));
            }
            break;
        case PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("v"));
            }
            break;
        case ARROW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
    }
    return true;
};

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    switch (tap_hold_keycode) {
        case MOD_A:
        case MOD_S:
        case MOD_D:
        case MOD_F:
        case MOD_J:
        case MOD_K:
        case MOD_L:
        case MOD_SC:
            return achordion_opposite_hands(tap_hold_record, other_record);
    }
    return true;
}

void keyboard_post_init_user() {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
}
