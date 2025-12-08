#pragma once

#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    _MAIN = 0,
    _SYM,
    _NAV,
    _NUM,
};

// Custom keycodes for sticky layers
enum custom_keycodes {
    OS_SYM = SAFE_RANGE,
    OS_NAV,
};

// Mod aliases using QMK's built-in one-shot mods
#define OS_SHFT OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)
