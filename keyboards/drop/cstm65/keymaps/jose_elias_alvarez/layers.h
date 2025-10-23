#pragma once

enum layers {
    _BASE,
    _GAME,
    _NAV,
    _FN,
};

#define FN MO(_FN)
#define NAV LT(_NAV, KC_SPC)
