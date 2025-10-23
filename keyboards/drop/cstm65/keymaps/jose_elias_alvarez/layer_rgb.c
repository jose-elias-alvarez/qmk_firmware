#include QMK_KEYBOARD_H

#include "layer_rgb.h"

void keyboard_post_init_user(void) {
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
            break;
        default:
            break;
    }

    return state;
}
