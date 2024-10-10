#include QMK_KEYBOARD_H

const uint16_t PROGMEM bootloader_combo[] = {KC_BTN4, KC_BTN2, COMBO_END};

combo_t key_combos[] = {
    COMBO(bootloader_combo, QK_BOOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clockwise starting from upper left
    [0] = LAYOUT(KC_BTN4, KC_BTN5, KC_BTN3, DRAG_SCROLL, KC_BTN1, KC_BTN2),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // keep default handling
        case DRAG_SCROLL:
            return true;
        default:
            if (is_drag_scroll) {
                is_drag_scroll = false;
                return false;
            }
    }
    return true;
}
