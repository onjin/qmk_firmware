#include QMK_KEYBOARD_H
#include "version.h"

#include "config_onjin.h"

// Define layer names
enum layers { ONJIN_LAYER_NAMES };

// http://configure.ergodox-ez.com/keyboard_layouts/qmabvw/edit
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] =  U_MACRO_VA_ARGS(LAYOUT_ergodox, ONJIN_ALTERNATIVES_BASE_QWERTY),
    [COLE] =  U_MACRO_VA_ARGS(LAYOUT_ergodox, ONJIN_ALTERNATIVES_BASE_COLEMAK_DH),
    [WORK] =  U_MACRO_VA_ARGS(LAYOUT_ergodox, ONJIN_ALTERNATIVES_BASE_WORKMAN),
    [GAME] =  U_MACRO_VA_ARGS(LAYOUT_ergodox, ONJIN_ALTERNATIVES_GAME),
    [SYMB] =  U_MACRO_VA_ARGS(LAYOUT_ergodox, ONJIN_ALTERNATIVES_SYMBOLS),
    [NUMP] =  U_MACRO_VA_ARGS(LAYOUT_ergodox, ONJIN_ALTERNATIVES_NUMPAD),
    [MEDI] =  U_MACRO_VA_ARGS(LAYOUT_ergodox, ONJIN_ALTERNATIVES_MEDIA),
    [NAV]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_NAV),
    [MOUSE]  = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_MOUSE),
    [MEDIA]  = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_MEDIA),
    [NUM]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_NUM),
    [SYM]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_SYM),
    [FUN]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_FUN),
    [BUTTON] = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_BUTTON)
};
/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE]   = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_BASE),
    [NAV]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_NAV),
    [MOUSE]  = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_MOUSE),
    [MEDIA]  = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_MEDIA),
    [NUM]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_NUM),
    [SYM]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_SYM),
    [FUN]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_FUN),
    [BUTTON] = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_BUTTON)
};
*/

void send_keystrokes(uint8_t key, ...) {
    va_list vl;
    va_start(vl, key);
    enum next_key_down_up nkdu = NK_DOWN_UP;
    while (key != KC_NO) {
        if (key < KC_A) {
            nkdu = key;
        } else {
            switch (nkdu) {
                case NK_DOWN_UP:
                    register_code(key);
                case NK_UP:
                    unregister_code(key);
                    break;
                case NK_DOWN:
                    register_code(key);
            }
            nkdu = NK_DOWN_UP;
        }
        key = va_arg(vl, int);
    }
    va_end(vl);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // shift+insert under single key / vim :)
        case SHFT_INS:
            if (record->event.pressed) {
                register_code(KC_LSHIFT);
                tap_code(KC_INS);
                unregister_code(KC_LSHIFT);
            }
            return false;
            break;
        // print versions
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
    }
    return true;
}

LEADER_EXTERNS();


// Declare a boolean variable to keep track of whether any sequence
// will have been matched.
bool did_leader_succeed;

void matrix_init_user(void) {
    // set_unicode_input_mode(UC_LNX);
}

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        did_leader_succeed = leading = false;

        // enter at left side
        SEQ_ONE_KEY(KC_BSPC) { tap_code(KC_ENT); }

        // jk
        SEQ_TWO_KEYS(KC_J, KC_K) { send_keystrokes(KC_ESCAPE, KC_NO); }
        SEQ_TWO_KEYS(KC_G, KC_G) { SEND_STRING("git checkout master && git pull && git fetch -p && git branch --merged"); }
        SEQ_TWO_KEYS(KC_G, KC_A) { SEND_STRING("git add ."); }
        SEQ_TWO_KEYS(KC_G, KC_D) { SEND_STRING("git diff"); }
        SEQ_THREE_KEYS(KC_G, KC_D, KC_S) { SEND_STRING("git diff --staged"); }
        SEQ_TWO_KEYS(KC_G, KC_L) { SEND_STRING("git log"); }
        SEQ_THREE_KEYS(KC_G, KC_L, KC_O) { SEND_STRING("git log --oneline"); }
        SEQ_TWO_KEYS(KC_G, KC_F) { SEND_STRING("git fetch"); }
        SEQ_TWO_KEYS(KC_G, KC_O) { SEND_STRING("git checkout"); }
        SEQ_TWO_KEYS(KC_G, KC_P) { SEND_STRING("git pull"); }
        SEQ_TWO_KEYS(KC_G, KC_S) { SEND_STRING("git status"); }
        SEQ_TWO_KEYS(KC_G, KC_C) {
            SEND_STRING("git commit -m ''");
            send_keystrokes(KC_LEFT, KC_NO);
        }
        SEQ_THREE_KEYS(KC_G, KC_C, KC_A) { SEND_STRING("git commit --amend"); }

        // fzf
        SEQ_ONE_KEY(KC_F) { SEND_STRING("$(fzf)"); }

        // qmk
        SEQ_ONE_KEY(KC_Q) { SEND_STRING("qmk compile && qmk flash\n"); }


        // Call leader_end at the end of the function, instead of at
        // the start. This way, we're sure we have set did_leader_succeed.
        leader_end();


    }


    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
    }
};


void leader_start() {
#   ifdef RGBLIGHT_ENABLE
    rgblight_setrgb_range(5, 100, 199, 10, 15);
#   endif
};

void leader_end() {
#   ifdef RGBLIGHT_ENABLE
    if (did_leader_succeed) {
        rgblight_setrgb_range(100, 255, 100, 10, 15);
    } else {
        rgblight_setrgb_range(255, 100, 100, 10, 15);

    }
    rgblight_setrgb_range(200, 200, 255, 10, 15);
#   endif
};


layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(state)) {
        case MEDIA:
        case SYM:
            ergodox_right_led_1_on();
            break;
        case NAV:
        case NUM:
            ergodox_right_led_2_on();
            break;
        case MOUSE:
        case FUN:
            ergodox_right_led_3_on();
            break;
        case GAME:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case COLE:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case SYMB:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            ergodox_board_led_off();
            ergodox_right_led_1_off();
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            break;
    }
  return state;
}

