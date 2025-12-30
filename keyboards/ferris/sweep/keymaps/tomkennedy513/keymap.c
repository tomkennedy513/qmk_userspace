#include QMK_KEYBOARD_H
#include "tomkennedy513.h"

const uint16_t PROGMEM cmd_combo[]  = {OS_SHFT, OS_SYM, COMBO_END};
combo_t                key_combos[] = {
    COMBO(cmd_combo, KC_LGUI),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Main Layer
     * ┌───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │REP│
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │   │ H │ J │ K │ L │ P │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │   │ N │ M │ , │ . │ ' │
     * └───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┘
     *             ┌───┬───┐   ┌───┬───┐
     *             │SFT│SYM│   │NAV│SPC│
     *             └───┴───┘   └───┴───┘
     */
    [_MAIN] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    QK_REP,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_P,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
                                   OS_SHFT, OS_SYM,     OS_NAV,  KC_SPC
    ),

    /*
     * Symbol Layer
     * ┌───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┐
     * │ ! │ @ │ # │ $ │ [ │   │ ] │ & │ ? │ | │ \ │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ ` │ / │ _ │ - │ ( │   │ ) │GUI│ALT│CTL│SFT│
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ * │ + │ = │ : │ { │   │ } │ % │ ^ │ ~ │ ; │
     * └───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┘
     */
    [_SYM] = LAYOUT_split_3x5_2(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LBRC,    KC_RBRC, KC_AMPR, KC_QUES, KC_PIPE, KC_BSLS,
        KC_GRV,  KC_SLSH, KC_UNDS, KC_MINS, KC_LPRN,    KC_RPRN, OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT,
        KC_ASTR, KC_PLUS, KC_EQL,  KC_COLN, KC_LCBR,    KC_RCBR, KC_PERC, KC_CIRC, KC_TILD, KC_SCLN,
                                   KC_LSFT, _______,    _______, _______
    ),

    /*
     * Nav Layer
     * ┌───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │HOM│PGD│PGU│END│DEL│
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │SFT│CTL│ALT│GUI│   │   │ ← │ ↓ │ ↑ │ → │BSP│
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │PTB│TAB│ESC│NTB│ENT│
     * └───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┘
     */
    [_NAV] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    RCS(KC_TAB), KC_PGDN, KC_PGUP, C(KC_TAB), KC_DEL,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  XXXXXXX,    KC_LEFT,     KC_DOWN, KC_UP,   KC_RGHT,   KC_BSPC,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_HOME,     KC_TAB,  KC_ESC,  KC_END ,   KC_ENT,
                                   _______, _______,    _______, _______
    ),

    /*
     * Number Layer (activated when SYM + NAV)
     * ┌───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │   │ 6 │ 7 │ 8 │ 9 │ 0 │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │SFT│CTL│ALT│GUI│F11│   │F12│GUI│ALT│CTL│SFT│
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │F1 │F2 │F3 │F4 │F5 │   │F6 │F7 │F8 │F9 │F10│
     * └───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┘
     */
    [_NUM] = LAYOUT_split_3x5_2(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  KC_F11,     KC_F12,  OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
                                   _______, _______,    _______, _______
    ),
};
// clang-format on
