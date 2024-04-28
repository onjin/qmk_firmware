/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#pragma once
#define LEADER_TIMEOUT 800 // leader key sequence timeout in millis
#define ORYX_CONFIGURATOR

#undef  DEBOUNCE
#define DEBOUNCE 25

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX


// non-KC_ keycodes
#define KC_TOG RGB_TOG
#define KC_MOD RGB_MOD
#define KC_HUI RGB_HUI
#define KC_SAI RGB_SAI
#define KC_VAI RGB_VAI


// default but important
#undef TAPPING_TERM
#define TAPPING_TERM 200

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD

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


#define LAYOUT_mini(\
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39\
)\
LAYOUT_ergodox_pretty(\
___, ___, ___, ___, ___, ___, ___,      ___, ___, ___, ___, ___, ___, ___,\
___, K00, K01, K02, K03, K04, ___,      ___, K05, K06, K07, K08, K09, ___,\
___, K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, ___,\
___, K20, K21, K22, K23, K24, ___,      ___, K25, K26, K27, K28, K29, ___,\
___, ___, ___, ___, K32,                          K37, ___, ___, ___, ___,\
                         ___, ___,      ___, ___,\
                              ___,      ___,\
                    K33, K34, ___,      ___, K35, K36\
)
