#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

#define LEADER_TIMEOUT 800 // leader key sequence timeout in millis
#define ORYX_CONFIGURATOR

#endif

#undef  DEBOUNCE
#define DEBOUNCE 25

// Define layer names
enum layers { L_BASE, L_SYMB, L_MEDI, BASE, NAVR, MOUR, MBO, MEDR, FUNL, NSL, NSSL  };

// macros
#define M_VERSION M(0)

#define KC_NP KC_NO // key is not present
#define KC_NA KC_NO // present but not available for use
#define KC_NU KC_NO // available but not used

// non-KC_ keycodes
#define KC_RST RESET
#define KC_TOG RGB_TOG
#define KC_MOD RGB_MOD
#define KC_HUI RGB_HUI
#define KC_SAI RGB_SAI
#define KC_VAI RGB_VAI

#define LAYOUT_miryoku(\
K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,\
N30,   N31,   K32,   K33,   K34,   K35,   K36,   K37,   N38,   N39\
)\
LAYOUT_ergodox_pretty( \
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
KC_NO, K00,   K01,   K02,   K03,   K04,   KC_NO, KC_NO, K05,   K06,   K07,   K08,   K09,   KC_NO, \
KC_NO, K10,   K11,   K12,   K13,   K14,                 K15,   K16,   K17,   K18,   K19,   KC_NO, \
KC_NO, K20,   K21,   K22,   K23,   K24,   KC_NO, KC_NO, K25,   K26,   K27,   K28,   K29,   KC_NO, \
KC_NO, KC_NO, KC_NO, KC_NO, K32,                               K37,   KC_NO, KC_NO, KC_NO, KC_NO, \
                                   KC_NO, KC_NO, KC_NO, KC_NO, \
                                          KC_NO, KC_NO, \
                            K33,   K34,   KC_NO, KC_NO, K35,   K36 \
)


#define MIRYOKU_ALPHAS_QWERTY
