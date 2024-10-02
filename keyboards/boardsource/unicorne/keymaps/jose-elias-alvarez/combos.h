#include "keys.h"

const uint16_t PROGMEM df_combo[] = {MOD_D, MOD_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {MOD_J, MOD_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(df_combo, KC_ENT),
    COMBO(jk_combo, KC_ESC),
};
