#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clockwise starting from upper left
    [0] = LAYOUT(KC_BTN4, KC_BTN5, DRAG_SCROLL, KC_BTN2, KC_BTN1, KC_BTN3)};
