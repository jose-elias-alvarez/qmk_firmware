#include QMK_KEYBOARD_H

#include "hold_taps.h"

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    (void)record;

    switch (keycode) {
        case CTL_ESC:
            return true;
        default:
            return false;
    }
}
