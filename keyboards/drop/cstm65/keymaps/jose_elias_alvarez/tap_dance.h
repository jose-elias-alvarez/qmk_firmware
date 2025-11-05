#pragma once

#include QMK_KEYBOARD_H

enum tap_dance_ids {
    TD_CAPS,
    TD_NUM_1,
    TD_NUM_2,
    TD_NUM_3,
    TD_NUM_4,
    TD_NUM_5,
    TD_NUM_6,
    TD_NUM_7,
    TD_NUM_8,
    TD_NUM_9,
    TD_NUM_0,
    TD_NUM_MINS,
    TD_NUM_EQL,
    TAP_DANCE_LEN,
};

#define CAPS TD(TD_CAPS)
#define NUM_F1 TD(TD_NUM_1)
#define NUM_F2 TD(TD_NUM_2)
#define NUM_F3 TD(TD_NUM_3)
#define NUM_F4 TD(TD_NUM_4)
#define NUM_F5 TD(TD_NUM_5)
#define NUM_F6 TD(TD_NUM_6)
#define NUM_F7 TD(TD_NUM_7)
#define NUM_F8 TD(TD_NUM_8)
#define NUM_F9 TD(TD_NUM_9)
#define NUM_F10 TD(TD_NUM_0)
#define NUM_F11 TD(TD_NUM_MINS)
#define NUM_F12 TD(TD_NUM_EQL)

extern tap_dance_action_t tap_dance_actions[TAP_DANCE_LEN];
