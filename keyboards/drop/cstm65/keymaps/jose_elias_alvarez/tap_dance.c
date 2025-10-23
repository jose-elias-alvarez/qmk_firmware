#include "tap_dance.h"

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

tap_dance_action_t tap_dance_actions[TAP_DANCE_LEN] = {
    [TD_GRV]       = ACTION_TAP_DANCE_FN(dance_grv),
    [TD_RALT_HYPR] = ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE(NULL, NULL, dance_ralt_finished, dance_ralt_reset),
};
