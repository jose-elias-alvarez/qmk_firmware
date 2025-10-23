#include QMK_KEYBOARD_H

#include "combos.h"

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_LEN] = {
    [DF_ENTER]  = COMBO(df_combo, KC_ENT),
    [JK_ESCAPE] = COMBO(jk_combo, KC_ESC),
};
