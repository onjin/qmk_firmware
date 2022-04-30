#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#define LEADER_TIMEOUT 800 // leader key sequence timeout in millis
#define ORYX_CONFIGURATOR

#endif

#undef  DEBOUNCE
#define DEBOUNCE 25

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


// default but important
#undef TAPPING_TERM
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
#define ___ KC_NO

#define LAYOUT_ergodox_tiny_16(           \
    L00,L01,L02,            R00,R01,R02,  \
    L03,L04,L05,L06,    R03,R04,R05,R06,  \
    L07,L08,                    R07,R08 ) \
                                          \
      /* matrix positions */              \
    {                                     \
    { ___, ___, ___, ___, ___, ___ },   \
    { ___, L00, L03, L07, ___, ___ },     \
    { ___, L01, L04, L08, ___, ___ },     \
    { ___, L02, L05, ___, ___, ___ },     \
    { ___, ___, L06, ___, ___, ___ },     \
    { ___, ___, ___, ___, ___, ___ },     \
    { ___, ___, ___, ___, ___, ___ },   \
                                          \
    { ___, ___, ___, ___, ___, ___ },   \
    { ___, ___, ___, ___, ___, ___ },     \
    { ___, ___, R03, ___, ___, ___ },     \
    { ___, R00, R04, ___, ___, ___ },     \
    { ___, R01, R05, R07, ___, ___ },     \
    { ___, R02, R06, R08, ___, ___ },     \
    { ___, ___, ___, ___, ___, ___ }    \
    }
