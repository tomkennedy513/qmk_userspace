#include "tomkennedy513.h"

// Layer states
typedef enum {
    LAYER_OFF,        // Layer inactive
    LAYER_HELD,       // Layer key is being held, no other key pressed yet
    LAYER_HELD_USED,  // Layer key is being held, another key was pressed
    LAYER_STICKY,     // Layer was tapped, waiting for a key press
    LAYER_STICKY_USED,// Layer is sticky and a key was pressed, waiting for release
} layer_mode_t;

static layer_mode_t sym_mode = LAYER_OFF;
static layer_mode_t nav_mode = LAYER_OFF;

// Timeout tracking
static uint16_t sym_timer = 0;
static uint16_t nav_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Handle custom sticky layer keys
    switch (keycode) {
        case OS_SYM:
            if (record->event.pressed) {
                layer_on(_SYM);
                sym_mode = LAYER_HELD;
            } else {
                if (sym_mode == LAYER_HELD) {
                    // Tapped without using - make sticky and start timeout
                    sym_mode = LAYER_STICKY;
                    sym_timer = timer_read();  // Only start timer when becoming sticky
                } else {
                    // Was held+used or sticky+used - turn off
                    sym_mode = LAYER_OFF;
                    layer_off(_SYM);
                }
            }
            return false;

        case OS_NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
                nav_mode = LAYER_HELD;
            } else {
                if (nav_mode == LAYER_HELD) {
                    // Tapped without using - make sticky and start timeout
                    nav_mode = LAYER_STICKY;
                    nav_timer = timer_read();  // Only start timer when becoming sticky
                } else {
                    // Was held+used or sticky+used - turn off
                    nav_mode = LAYER_OFF;
                    layer_off(_NAV);
                }
            }
            return false;
    }

    // For non-layer keys (including OSMs)
    if (keycode != OS_SYM && keycode != OS_NAV) {
        if (record->event.pressed) {
            // Mark held layers as "used"
            if (sym_mode == LAYER_HELD) sym_mode = LAYER_HELD_USED;
            if (nav_mode == LAYER_HELD) nav_mode = LAYER_HELD_USED;
            // Mark sticky layers as "used" - ready to deactivate on release
            if (sym_mode == LAYER_STICKY) sym_mode = LAYER_STICKY_USED;
            if (nav_mode == LAYER_STICKY) nav_mode = LAYER_STICKY_USED;
        } else {
            // On release, clear if we pressed a key while sticky
            if (sym_mode == LAYER_STICKY_USED) {
                sym_mode = LAYER_OFF;
                layer_off(_SYM);
            }
            if (nav_mode == LAYER_STICKY_USED) {
                nav_mode = LAYER_OFF;
                layer_off(_NAV);
            }
        }
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}

// Matrix scan function to check for timeouts
void matrix_scan_user(void) {
    // Check SYM layer timeout
    if (sym_mode == LAYER_STICKY || sym_mode == LAYER_STICKY_USED) {
        if (timer_elapsed(sym_timer) > ONESHOT_LAYER_TIMEOUT) {
            sym_mode = LAYER_OFF;
            layer_off(_SYM);
        }
    }
    
    // Check NAV layer timeout
    if (nav_mode == LAYER_STICKY || nav_mode == LAYER_STICKY_USED) {
        if (timer_elapsed(nav_timer) > ONESHOT_LAYER_TIMEOUT) {
            nav_mode = LAYER_OFF;
            layer_off(_NAV);
        }
    }
}
