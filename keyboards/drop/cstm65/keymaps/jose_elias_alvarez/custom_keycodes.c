#include QMK_KEYBOARD_H

#include "custom_keycodes.h"
#include "layers.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_LAYR:
            if (record->event.pressed) {
                layer_invert(_GAME);
            }
            return false;
        default:
            return true;
    }
}
