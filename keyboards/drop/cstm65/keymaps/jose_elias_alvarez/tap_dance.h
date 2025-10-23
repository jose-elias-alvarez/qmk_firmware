#pragma once

#include QMK_KEYBOARD_H

enum tap_dance_ids {
    TD_GRV,
    TD_RALT_HYPR,
    TAP_DANCE_LEN,
};

#define GRV TD(TD_GRV)
#define RALT_HYPR TD(TD_RALT_HYPR)

extern tap_dance_action_t tap_dance_actions[TAP_DANCE_LEN];
