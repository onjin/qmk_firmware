#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "version.h"

// Define layer names
#define L_BASE 0
#define L_COLE 1
#define L_SYMB 2
#define L_MEDI 3
#define L_EMOT 4
#define L_MIRR 5


// macros
#define M_VERSION           M(0)


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,

};

// http://configure.ergodox-ez.com/keyboard_layouts/qmabvw/edit
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Base layer ((idea))
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  6   |           |      |   7  |   8  |   9  |   0  |   -  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   `    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/L3 |   '    |
 * |--------+------+------+------+------+------|  L6  |           |  L6  |------+------+------+------+------+--------|
 * | LSft   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RSft   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  L5  | Lead | Meta | Alt  |                                       | AltGr| Down | lead |  L5  |  L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Esc |  Ins |       |  Del | Lock |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space| BkSp |------|       |------| Enter|Space |
 *                                 |      |      |  End |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [L_BASE] = LAYOUT_ergodox(
      // left hand
      KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, TO(L_COLE),
      KC_GRAVE, KC_A, KC_S, KC_D, KC_F, KC_G,
      KC_LSHIFT, CTL_T(KC_Z), KC_X, KC_C, KC_V, KC_B, ALL_T(KC_NO),
      KC_LCTL, MO(L_MIRR), KC_LEAD, KC_LGUI, KC_LALT,
      // left thumb
      KC_ESCAPE, KC_INSERT, KC_HOME, KC_SPC, KC_BSPC, KC_END,

      // right hand
      KC_TRNS,      KC_7,   KC_8,   KC_9,   KC_0,   KC_MINUS,   KC_EQUAL,
      TO(L_SYMB),   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,       KC_BSLASH,
      KC_H,         KC_J,   KC_K,   KC_L,   LT(L_MEDI,  KC_SCOLON), KC_QUOTE,
      MEH_T(KC_NO), KC_N, KC_M, KC_COMMA, KC_DOT, CTL_T(KC_SLASH), KC_RSHIFT,
      KC_RALT, MO(L_EMOT), KC_LEAD, MO(L_MIRR), MO(L_SYMB),
      // right thumb
      KC_DELETE, KC_LOCK, KC_PGUP, KC_PGDOWN, KC_ENT, KC_SPC
    ),

  // colemak
  [L_COLE] = LAYOUT_ergodox(KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_TAB,KC_Q,KC_W,KC_F,KC_P,KC_G,TO(L_MEDI),KC_GRAVE,KC_A,KC_R,KC_S,KC_T,KC_D,KC_LSHIFT,CTL_T(KC_Z),KC_X,KC_C,KC_V,KC_B,ALL_T(KC_NO),KC_LCTL,MO(L_MIRR),KC_LALT,KC_LGUI,KC_RALT,KC_ESCAPE,KC_INSERT,KC_HOME,KC_SPACE,KC_BSPACE,KC_END,KC_TRANSPARENT,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_EQUAL,TO(0),KC_J,KC_L,KC_U,KC_Y,KC_SCOLON,KC_BSLASH,KC_H,KC_N,KC_E,KC_I,KC_O,KC_QUOTE,MEH_T(KC_NO),KC_K,KC_M,KC_COMMA,KC_DOT,CTL_T(KC_SLASH),KC_RSHIFT,KC_RALT,MO(L_EMOT),KC_TRANSPARENT,MO(L_MIRR),MO(L_SYMB),KC_DELETE,KC_ESCAPE,KC_PGUP,KC_PGDOWN,KC_TAB,KC_ENTER),

  // symbols
  [L_SYMB] = LAYOUT_ergodox(
      KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,
      KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LBRACKET,KC_RBRACKET,KC_PIPE,TO(0),
      KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRAVE,KC_TRANSPARENT,
      KC_PERC,KC_CIRC,KC_LCBR,KC_RCBR,KC_TILD,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RGB_MOD,KC_TRANSPARENT,KC_TRANSPARENT,RGB_VAD,RGB_VAI,KC_TRANSPARENT,KC_TRANSPARENT,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,TO(L_MEDI),KC_UP,KC_7,KC_8,KC_9,KC_ASTR,KC_F12,KC_DOWN,KC_4,KC_5,KC_6,KC_PLUS,KC_TRANSPARENT,KC_SYSTEM_POWER,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_0,KC_EQUAL,KC_TRANSPARENT,RGB_TOG,RGB_SLD,KC_TRANSPARENT,KC_TRANSPARENT,RGB_HUD,RGB_HUI),

  // media
  [L_MEDI] = LAYOUT_ergodox(
      KC_TRANSPARENT,KC_ACL0,KC_ACL1,KC_ACL2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      MU_TOG,KC_TRANSPARENT,KC_MS_WH_UP,KC_MS_UP,KC_MS_WH_DOWN,KC_TRANSPARENT,TO(L_SYMB),
      MU_MOD,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,TO(L_COLE),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_WWW_BACK),

  // emotes
  [L_EMOT] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_COLN,KC_RPRN,KC_LPRN,KC_SLASH,KC_P,KC_D,KC_TRANSPARENT,KC_SCOLON,KC_RPRN,KC_LPRN,KC_SLASH,KC_P,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_D,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  // qwerty mirror
  [L_MIRR] = LAYOUT_ergodox(
      // left hand
      KC_EQUAL,KC_MINUS,KC_0,KC_9,KC_8,KC_7,KC_TRANSPARENT,
      KC_BSLASH,KC_P,KC_O,KC_I,KC_U,KC_Y,KC_TRANSPARENT,
      KC_QUOTE,KC_SCOLON,KC_L,KC_K,KC_J,KC_H,
      KC_LSHIFT,KC_SLASH,KC_DOT,KC_COMMA,KC_M,KC_N,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      // left thumb
      KC_LOCK,KC_DELETE,KC_PGUP,KC_SPACE,KC_ENTER,KC_PGDOWN,

      // right hand
      KC_6,KC_5,KC_4,KC_3,KC_2,KC_1,KC_ESCAPE,
      KC_TRANSPARENT, KC_T,KC_R,KC_E,KC_W,KC_Q,KC_TAB,
      KC_G,KC_F,KC_D,KC_S,KC_A,KC_GRAVE,
      KC_TRANSPARENT,KC_B,KC_V,KC_C,KC_X,KC_Z,KC_LSHIFT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      // right thumb
      KC_INSERT,KC_ESCAPE,KC_HOME,KC_END,KC_BSPACE,KC_SPACE),
};

enum next_key_down_up {
    NK_DOWN_UP,
    NK_DOWN,
    NK_UP // a bit of a hack, this works as long as NK_UP < KC_A
};

void send_keystrokes(uint8_t key, ...)
{
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

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
          if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
          }
          break;
        case 71:
          if (record->event.pressed) {
              SEND_STRING("import pdb; pdb.set_trace()");
          }
          break;
        case 72:
          if (record->event.pressed) {
              SEND_STRING("import ipdb; ipdb.set_trace()");
          }
          break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_J, KC_K) {
            send_keystrokes(KC_ESCAPE, KC_NO);
        }
        SEQ_TWO_KEYS(KC_G, KC_G) {
            SEND_STRING("git checkout master && git pull && git fetch -p && git branch --merged");
        }
        SEQ_TWO_KEYS(KC_G, KC_A) {
            SEND_STRING("git add .");
        }
        SEQ_TWO_KEYS(KC_G, KC_D) {
            SEND_STRING("git diff");
        }
        SEQ_THREE_KEYS(KC_G, KC_D, KC_S) {
            SEND_STRING("git diff --staged");
        }
        SEQ_TWO_KEYS(KC_G, KC_L) {
            SEND_STRING("git log");
        }
        SEQ_THREE_KEYS(KC_G, KC_L, KC_O) {
            SEND_STRING("git log --oneline");
        }
        SEQ_TWO_KEYS(KC_G, KC_F) {
            SEND_STRING("git fetch");
        }
        SEQ_TWO_KEYS(KC_G, KC_O) {
            SEND_STRING("git checkout");
        }
        SEQ_TWO_KEYS(KC_G, KC_P) {
            SEND_STRING("git pull");
        }
        SEQ_TWO_KEYS(KC_G, KC_S) {
            SEND_STRING("git status");
        }
        SEQ_TWO_KEYS(KC_G, KC_C) {
            SEND_STRING("git commit -m ''");
            send_keystrokes(KC_LEFT, KC_NO);
        }
        SEQ_THREE_KEYS(KC_G, KC_C, KC_A) {
            SEND_STRING("git commit --amend");
        }

        SEQ_TWO_KEYS(KC_E, KC_E) {
            SEND_STRING("cd /opt/app_emoney/application; source ../venv_emoney/bin/activate\n");
        }
        SEQ_TWO_KEYS(KC_E, KC_S) {
            SEND_STRING("cd /opt/app_emoney/application; source ../venv_emoney/bin/activate\n./website/manage.py shell\n");
        }
      }

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
