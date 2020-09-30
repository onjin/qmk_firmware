#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

#define LEADER_TIMEOUT 800 // leader key sequence timeout in millis
#define ORYX_CONFIGURATOR

#endif

#undef  DEBOUNCE
#define DEBOUNCE 25

// Define layer names
enum layers { BASE, GAME, COLE, SYMB, MEDI, MIRR};

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
