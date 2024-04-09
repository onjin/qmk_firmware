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
    [NAV]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_NAV),
    [MOUSE]  = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_MOUSE),
    [MEDIA]  = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_MEDIA),
    [NUM]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_NUM),
    [SYM]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_SYM),
    [FUN]    = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_FUN),
    [BUTTON] = U_MACRO_VA_ARGS(LAYOUT_mini, ONJIN_LAYER_BUTTON)
};

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
                register_code(KC_LSFT);
                tap_code(KC_INS);
                unregister_code(KC_LSFT);
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
        case SHRUG:
          if (record->event.pressed) {
            send_unicode_string("¯\\_(ツ)_/¯");
          }
          return false;
          break;
    }
    return true;
}




void matrix_init_user(void) {
    // set_unicode_input_mode(UC_LNX);
}

void matrix_scan_user(void) {
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
    }
};

// Declare a boolean variable to keep track of whether any sequence
// will have been matched.
bool did_leader_succeed;

void leader_end_user(void) {
#   ifdef RGBLIGHT_ENABLE
    rgblight_setrgb_range(5, 100, 199, 10, 15);
#   endif

    did_leader_succeed = false;

    if (leader_sequence_one_key(KC_F)) {
        // Leader, f => Types the below string
        SEND_STRING("$(fzf)");
    } else {
        did_leader_succeed = false;
    }

#   ifdef RGBLIGHT_ENABLE
    if (did_leader_succeed) {
        rgblight_setrgb_range(100, 255, 100, 10, 15);
    } else {
        rgblight_setrgb_range(255, 100, 100, 10, 15);

    }
    rgblight_setrgb_range(200, 200, 255, 10, 15);
#   endif
}


layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(state)) {
        // case MEDIA:
        // case SYM:
        //     ergodox_right_led_1_on();
        //     break;
        // case NAV:
        // case NUM:
        //     ergodox_right_led_2_on();
        //     break;
        // case MOUSE:
        // case FUN:
        //     ergodox_right_led_3_on();
        //     break;
        case GAME:
            ergodox_right_led_1_on();
            break;
        case COLE:
            ergodox_right_led_2_on();
            break;
        case WORK:
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

