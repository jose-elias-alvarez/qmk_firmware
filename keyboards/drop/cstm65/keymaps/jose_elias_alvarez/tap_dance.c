#include "tap_dance.h"
#include "process_tap_dance.h"

static void dance_grv_triple(tap_dance_state_t *state, void *user_data) {
    SEND_STRING(state->count >= 2 ? "```" : "`");
    reset_tap_dance(state);
}

static void dance_tab_switch(tap_dance_state_t *state, void *user_data) {
    tap_code16(state->count >= 2 ? LALT(KC_TAB) : KC_TAB);
    reset_tap_dance(state);
}

static void dance_lalt_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        tap_code16(LAG(KC_SPC));
    } else {
        register_code(KC_LALT);
    }
}

static void dance_lalt_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count < 2) {
        unregister_code(KC_LALT);
    }
}

typedef struct {
    uint16_t tap;
    uint16_t hold;
    bool     hold_registered;
} tap_dance_tap_hold_t;

static void dance_num_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *config = (tap_dance_tap_hold_t *)user_data;
    config->hold_registered      = false;

    if (state->count == 1 && state->pressed && !state->interrupted) {
        register_code16(config->hold);
        config->hold_registered = true;
        return;
    }

    for (uint8_t i = 0; i < state->count; i++) {
        tap_code16(config->tap);
    }
}

static void dance_num_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *config = (tap_dance_tap_hold_t *)user_data;
    if (config->hold_registered) {
        unregister_code16(config->hold);
    }
}

static tap_dance_tap_hold_t num_tap_hold_configs[] = {
    {KC_1, KC_F1, false}, {KC_2, KC_F2, false}, {KC_3, KC_F3, false}, {KC_4, KC_F4, false}, {KC_5, KC_F5, false}, {KC_6, KC_F6, false}, {KC_7, KC_F7, false}, {KC_8, KC_F8, false}, {KC_9, KC_F9, false}, {KC_0, KC_F10, false}, {KC_MINS, KC_F11, false}, {KC_EQL, KC_F12, false},
};

tap_dance_action_t tap_dance_actions[TAP_DANCE_LEN] = {
    [TD_GRV_TRIPLE]    = ACTION_TAP_DANCE_FN(dance_grv_triple),
    [TD_TAB_SWITCH]    = ACTION_TAP_DANCE_FN(dance_tab_switch),
    [TD_LALT_LAUNCHER] = ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE(NULL, NULL, dance_lalt_finished, dance_lalt_reset),
    [TD_NUM_1]         = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[0]},
    [TD_NUM_2]         = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[1]},
    [TD_NUM_3]         = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[2]},
    [TD_NUM_4]         = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[3]},
    [TD_NUM_5]         = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[4]},
    [TD_NUM_6]         = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[5]},
    [TD_NUM_7]         = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[6]},
    [TD_NUM_8]         = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[7]},
    [TD_NUM_9]         = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[8]},
    [TD_NUM_0]         = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[9]},
    [TD_NUM_MINS]      = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[10]},
    [TD_NUM_EQL]       = {.fn = {NULL, dance_num_finished, dance_num_reset, NULL}, .user_data = &num_tap_hold_configs[11]},
};
