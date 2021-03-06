#include QMK_KEYBOARD_H
#include "version.h"

// Define layer names
enum layers { BASE, GAME, COLE, WORK, SYMB, NUMP, MEDI};

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here
    SHFT_INS,
    VRSN,

};

// http://configure.ergodox-ez.com/keyboard_layouts/qmabvw/edit
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /***0* Base layer (Qwerty)
     ***0*
     ***0* ,--------------------------------------------------.           ,--------------------------------------------------.
     ***0* | Esc    |   1  |   2  |   3  |   4  |   5  |      |           | GAME |   6  |   7  |   8  |   9  |   0  |   =    |
     ***0* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     ***0* | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           | COLE |   Y  |   U  |   I  |   O  |   P  |   \    |
     ***0* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     ***0* |   `    |MEDI/A|Alt/S |Ctr/D |Shf/F |   G  |------|           |------|   H  |Shf/J |Ctr/K |Alt/L |MEDI/;|   '    |
     ***0* |--------+------+------+------+------+------|      |           | WORK |------+------+------+------+------+--------|
     ***0* | Lead   |   Z  |AltG/X|   C  |Hypr/V|Meh/B |      |           |      |   N  |   M  |   ,  |AltG/.|   /  | Lead   |
     ***0* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     ***0*   | Swap | Swap | Lead | LGui |Alt/Es|                                       | SYMB | RGui | Lead | Swap | Swap |
     ***0*   `----------------------------------'                                       `----------------------------------'
     ***0*                                        ,-------------.       ,-------------.
     ***0*                                        |      |  Ins |       |  Del | Lock |
     ***0*                                 ,------|------|------|       |------+------+------.
     ***0*                                 |Shift/|      | Home |       | PgUp |      |NUMP/ |
     ***0*                                 | Space| BkSp |------|       |------| Enter|Space |
     ***0*                                 |      |      |  End |       | PgDn |      |      |
     ***0*                                 `--------------------'       `--------------------'
     ***0*/
    [BASE] = LAYOUT_ergodox(
        // left hand 7/7/6/7/5
        // ____  _______           _______  _______  _______  _______  _______
        KC_ESC,  KC_1,             KC_2,    KC_3,    KC_4,    KC_5,    _______,
        KC_TAB,  KC_Q,             KC_W,    KC_E,    KC_R,    KC_T,    KC_HYPR,
        KC_GRV,  LT(MEDI, KC_A),   LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,
        KC_LEAD, KC_Z,             ALGR_T(KC_X),    KC_C,    HYPR_T(KC_V),    MEH_T(KC_B),    KC_MEH,
        SH_MON,  SH_MON,           KC_LEAD, KC_LGUI, LALT_T(KC_ESC),

        KC_NO,   KC_INSERT,
                                   KC_HOME,
        LSFT_T(KC_SPC), KC_BSPC, KC_END,

        // right hand
        // ____  _______  _______  _______  _______         _______         _______
        TO(GAME),KC_6,    KC_7,    KC_8,    KC_9,           KC_0,           KC_EQUAL,
        TO(COLE),KC_Y,    KC_U,    KC_I,    KC_O,           KC_P,           KC_BSLASH,
                 KC_H,    RSFT_T(KC_J),     RCTL_T(KC_K),   LALT_T(KC_L),   LT(MEDI, KC_SCOLON), KC_QUOTE,
        TO(WORK),KC_N,    KC_M,             KC_COMM,        ALGR_T(KC_DOT), KC_SLASH, KC_LEAD,
                          MO(SYMB),         KC_RGUI,        KC_LEAD,        SH_MON,   SH_MON,

        // right thumb
        KC_DEL, KC_LOCK,
        KC_PGUP,
        KC_PGDOWN, KC_ENT, LT(NUMP, KC_SPC)
    ),

    /***1* Base layer (COLEMAK)
     ***1*
     ***1* ,--------------------------------------------------.           ,--------------------------------------------------.
     ***1* | Esc    |   1  |   2  |   3  |   4  |   5  |      |           | GAME |   6  |   7  |   8  |   9  |   0  |   =    |
     ***1* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     ***1* | Tab    |   Q  |   W  |   F  |   P  |   G  |      |           | BASE |   J  |   L  |   U  |   Y  |   ;  |   \    |
     ***1* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     ***1* |   `    |MEDI/A|Alt/R |Ctr/S |Shf/T |   D  |------|           |------|   H  |Shf/N |Ctr/E |Alt/I |MEDI/O|   '    |
     ***1* |--------+------+------+------+------+------|      |           | WORK |------+------+------+------+------+--------|
     ***1* | LSft   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | RSft   |
     ***1* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     ***1*   | Ctrl | Swap | Lead | LGui | Alt/E|                                       | AltGr| RGui | Lead | Swap | SYMB |
     ***1*   `----------------------------------'                                       `----------------------------------'
     ***1*                                        ,-------------.       ,-------------.
     ***1*                                        |      |  Ins |       |  Del | Lock |
     ***1*                                 ,------|------|------|       |------+------+------.
     ***1*                                 |      |      | Home |       | PgUp |      |      |
     ***1*                                 | Space| BkSp |------|       |------| Enter|Space |
     ***1*                                 |      |      |  End |       | PgDn |      |      |
     ***1*                                 `--------------------'       `--------------------'
     ***1*/
    [COLE] = LAYOUT_ergodox(
        // left hand 7/7/6/7/5
        // ____  _______           _______          _______         _______         _______  _______
        _______, _______,          _______,         _______,        _______,        _______, _______,
        _______, KC_Q,             KC_W,            KC_F,           KC_P,           KC_G,    _______,
        _______, LT(MEDI, KC_A),   LALT_T(KC_R),    LCTL_T(KC_S),   LSFT_T(KC_T),   KC_D,
        _______, KC_Z,             ALGR_T(KC_X),    KC_C,           KC_V,           KC_B,    _______,
        _______, _______,          _______,         _______,        _______,

        // left thumb
        _______,  _______,
                                   _______,
        _______,  _______, _______,

        // right hand
        // ____  _______  _______           _______         _______         _______           _______
        _______, _______, _______,          _______,        _______,        _______,          _______,
        TO(BASE),KC_J,    KC_L,             KC_U,           KC_Y,           KC_SCLN,          _______,
                 KC_H,    RSFT_T(KC_N),     RCTL_T(KC_E),   LALT_T(KC_I),   LT(MEDI, KC_O),   _______,
        _______, KC_K,    KC_M,             KC_COMM,        ALGR_T(KC_DOT), KC_SLASH,         _______,
                          _______,          _______,        _______,        _______,          _______,

        // right thumb
        _______, _______,
        _______,
        _______, _______, _______
    ),
    /***2* Base layer (WORKMAN)
     ***2*
     ***2* ,--------------------------------------------------.           ,--------------------------------------------------.
     ***2* | Esc    |   1  |   2  |   3  |   4  |   5  |      |           | GAME |   6  |   7  |   8  |   9  |   0  |   =    |
     ***2* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     ***2* | Tab    |   Q  |   W  |   F  |   P  |   G  |      |           | COLE |   J  |   L  |   U  |   Y  |   ;  |   \    |
     ***2* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     ***2* |   `    |MEDI/A|Alt/R |Ctr/S |Shf/T |   D  |------|           |------|   H  |Shf/N |Ctr/E |Alt/I |MEDI/O|   '    |
     ***2* |--------+------+------+------+------+------|      |           | BASE |------+------+------+------+------+--------|
     ***2* | LSft   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | RSft   |
     ***2* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     ***2*   | Ctrl | Swap | Lead | LGui | Alt/E|                                       | AltGr| RGui | Lead | Swap | SYMB |
     ***2*   `----------------------------------'                                       `----------------------------------'
     ***2*                                        ,-------------.       ,-------------.
     ***2*                                        |      |  Ins |       |  Del | Lock |
     ***2*                                 ,------|------|------|       |------+------+------.
     ***2*                                 |      |      | Home |       | PgUp |      |      |
     ***2*                                 | Space| BkSp |------|       |------| Enter|Space |
     ***2*                                 |      |      |  End |       | PgDn |      |      |
     ***2*                                 `--------------------'       `--------------------'
     ***2*/
    [WORK] = LAYOUT_ergodox(
        // left hand 7/7/6/7/5
        // ____  _______           _______          _______         _______         _______  _______
        _______, _______,          _______,         _______,        _______,        _______, _______,
        _______, KC_Q,             KC_D,            KC_R,           KC_W,           KC_B,    _______,
        _______, LT(MEDI, KC_A),   LALT_T(KC_S),    LCTL_T(KC_H),   LSFT_T(KC_T),   KC_G,
        _______, KC_Z,             ALGR_T(KC_X),    KC_M,           KC_C,           KC_V,    _______,
        _______, _______,          _______,         _______,        _______,

        // left thumb
        _______,  _______,
                                   _______,
        _______,  _______, _______,

        // right hand
        // ____  _______  _______           _______         _______         _______           _______
        _______, _______, _______,          _______,        _______,        _______,          _______,
        _______, KC_J,    KC_F,             KC_U,           KC_P,           KC_SCLN,          _______,
                 KC_Y,    RSFT_T(KC_N),     RCTL_T(KC_E),   LALT_T(KC_O),   LT(MEDI, KC_L),   _______,
        TO(BASE),KC_K,    KC_L,             KC_COMM,        ALGR_T(KC_DOT), KC_SLASH,         _______,
                          _______,          _______,        _______,        _______,          _______,

        // right thumb
        _______, _______,
        _______,
        _______, _______, _______
    ),
    /***3* Game layer (Qwerty) - less modifiers
     ***3*
     ***3* ,--------------------------------------------------.           ,--------------------------------------------------.
     ***3* | Esc    |   1  |   2  |   3  |   4  |   5  |      |           | BASE |   6  |   7  |   8  |   9  |   0  |   =    |
     ***3* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     ***3* | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           | COLE |   Y  |   U  |   I  |   O  |   P  |   \    |
     ***3* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     ***3* |   `    |   A  |   W  |   E  |   F  |   G  |------|           |------|   H  |   J  |   K  |   O  |MEDI/;|   '    |
     ***3* |--------+------+------+------+------+------|      |           | WORK |------+------+------+------+------+--------|
     ***3* | LSft   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RSft   |
     ***3* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     ***3*   | Ctrl | Swap | Lead | LGui | Alt/E|                                       | AltGr| RGui | Lead | Swap | SYMB |
     ***3*   `----------------------------------'                                       `----------------------------------'
     ***3*                                        ,-------------.       ,-------------.
     ***3*                                        |      |  Ins |       |  Del | Lock |
     ***3*                                 ,------|------|------|       |------+------+------.
     ***3*                                 |      |      | Home |       | PgUp |      |      |
     ***3*                                 | Space| BkSp |------|       |------| Enter|Space |
     ***3*                                 |      |      |  End |       | PgDn |      |      |
     ***3*                                 `--------------------'       `--------------------'
     ***3*/
    [GAME] = LAYOUT_ergodox(
        // left hand 7/7/6/7/5
        // ____  _______           _______  _______  _______  _______  _______
        _______, _______,          _______, _______, _______, _______, _______,
        _______, _______,          _______, _______, _______, _______, _______,
        _______, KC_A,             KC_S,    KC_D,    KC_F,    _______,
        KC_LSFT, _______,          KC_X,    _______, KC_V,    KC_B,    _______,
        KC_LCTL, _______,          _______, _______, _______,

        KC_NO,   KC_INSERT,
                                   KC_HOME,
        KC_SPC, KC_BSPC, KC_END,

        // right hand
        // ____  _______  _______  _______  _______  _______  _______
        TO(BASE),_______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                 _______, KC_J,    KC_K,    KC_L,    _______, _______,
        _______, _______, _______, _______, KC_DOT,  _______, KC_RSFT,
                          _______, _______, _______, _______, KC_RCTL,

        // right thumb
        KC_DEL, KC_LOCK,
        KC_PGUP,
        KC_PGDOWN, KC_ENT, KC_SPC
    ),


    /***4* Symbols layer
     ***4*
     ***4* ,--------------------------------------------------.           ,--------------------------------------------------.
     ***4* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     ***4* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     ***4* |        |   #  |   ^  |   [  |   ]  |   \  |      |           |      |   /  |   !  |   _  |   =  |   *  |        |
     ***4* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     ***4* |        |   &  |   $  |   (  |   )  |   |  |------|           |------|   ~  |   -  |   <  |   >  |   :  |   "    |
     ***4* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     ***4* |        |   %  |   @  |   {  |   }  |   !  |      |           |      |      |   +  |   ,  |   .  |   `  |        |
     ***4* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     ***4*   |      |      |      |      |      |                                       | XXX  |      |      |      |      |
     ***4*   `----------------------------------'                                       `----------------------------------'
     ***4*                                        ,-------------.       ,-------------.
     ***4*                                        |      |      |       |      |      |
     ***4*                                 ,------|------|------|       |------+------+------.
     ***4*                                 |      |      |      |       |      |      |      |
     ***4*                                 |      |      |------|       |------|      |      |
     ***4*                                 |      |      |      |       |      |      |      |
     ***4*                                 `--------------------'       `--------------------'
     ***4*/
    [SYMB] = LAYOUT_ergodox(
        // left hand 7/7/6/7/5
        // ____  _______  _______  _______  _______  _______  _______
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_HASH, KC_CIRC, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO,
        KC_NO,   KC_AMPR, KC_DLR,  KC_LPRN, KC_RPRN, KC_PIPE,
        KC_NO,   KC_PERC, KC_AT,   KC_LCBR, KC_RCBR, KC_EXLM, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        // left thumb
        KC_NO,   KC_NO,
                          KC_NO,
        KC_NO,   KC_NO,   KC_NO,

        // right hand 7/7/6/7/5
        // ____  _______  _______  _______  _______  _______  _______
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_PSLS, KC_EXLM, KC_UNDS, KC_EQUAL,KC_PAST, KC_NO,
                 KC_TILD, KC_MINS, KC_LT,   KC_GT,   KC_COLN, KC_DQUO,
        KC_NO,   KC_NO,   KC_PLUS, KC_COMM, KC_DOT,  KC_GRAVE,KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

        // right thumb
        KC_NO,   KC_NO,
                          KC_NO,
        KC_NO,   KC_NO,   KC_NO
    ),


    /***5* Numpad layer
     ***5*
     ***5* ,--------------------------------------------------.           ,--------------------------------------------------.
     ***5* | ESC    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
     ***5* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     ***5* |Shift+In|   /  |   7  |   8  |   9  |   *  |      |           |      |   /  |   7  |   8  |   9  |   *  |  F12   |
     ***5* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     ***5* |    ,   |   -  |   4  |   5  |   6  |   +  |------|           |------|   -  |   4  |   5  |   6  |   +  |        |
     ***5* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     ***5* | CAPS   |   0  |   1  |   2  |   3  |   =  |      |           |      |   0  |   1  |   2  |   3  |   =  |        |
     ***5* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     ***5*   |      |      |      |      |      |                                       |      |      |      |      | XXX  |
     ***5*   `----------------------------------'                                       `----------------------------------'
     ***5*                                        ,-------------.       ,-------------.
     ***5*                                        |      |      |       |      |      |
     ***5*                                 ,------|------|------|       |------+------+------.
     ***5*                                 |      |      |      |       |      |      |      |
     ***5*                                 |      |      |------|       |------| Enter| XXX  |
     ***5*                                 |      |      |Enter |       |      |      |      |
     ***5*                                 `--------------------'       `--------------------'
     ***5*/
    [NUMP] = LAYOUT_ergodox(
        // left hand 7/7/6/7/5
        // ____  _______  _______  _______  _______  _______  _______
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,
        SHFT_INS,KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_NO,
        KC_COMM, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_CAPS, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        // left thumb
        KC_NO,   KC_NO,
                          VRSN,
        _______, _______, KC_ENT,

        // right hand 7/7/6/7/5
        // ____  _______  _______  _______  _______  _______  _______
        KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_NO,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_F12,
                 KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NO,
        KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_NO,
                          KC_NO,   KC_NO,   KC_P0,   KC_NO,   KC_NO,

        // right thumb
        KC_NO,   KC_NO,
                          KC_NO,
        KC_NO,   KC_PENT, KC_NO
    ),

    /***6* Media layer
     ***6*
     ***6* ,--------------------------------------------------.           ,--------------------------------------------------.
     ***6* |        |L/TOG |L/MOD |L/HUI |L/SAI |L/VAI |      |           |      |      |      |      |      |      |        |
     ***6* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     ***6* | Reset  |      |Whl/L |Whl/D |Whl/U |Whl/R |      |           |      |Home  |PageDn|PageUp| End  | Ins  |        |
     ***6* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     ***6* |        | XXX  |Mou/L |Mou/D |Mou/U |Mou/R |------|           |------| Left | Down | Up   | Right| XXX  |        |
     ***6* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     ***6* |        |      |MAcl0 |MAcl1 | MAcl2|      |      |           |      |MePrev|VolDwn|VolUp |MeNext|      |        |
     ***6* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     ***6*   |      |      |      |      | Btn1 |                                       | Mute |      |      |      |      |
     ***6*   `----------------------------------'                                       `----------------------------------'
     ***6*                                        ,-------------.       ,-------------.
     ***6*                                        |      |      |       |      |      |
     ***6*                                 ,------|------|------|       |------+------+------.
     ***6*                                 |      |      |      |       |      | A2DP | Play |
     ***6*                                 | Btn3 | Btn2 |------|       |------|   /  |  /   |
     ***6*                                 |      |      |      |       |      | HFS  | Stop |
     ***6*                                 `--------------------'       `--------------------'
     ***6*/
    [MEDI] = LAYOUT_ergodox(
        // left hand 7/7/6/7/5
        // ____  _______  _______  _______  _______  _______  _______
        KC_NO,   KC_TOG,  KC_MOD,  KC_HUI,  KC_SAI,  KC_VAI,  KC_NO,
        KC_RST,  KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
        KC_NO,   KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        KC_NO,   KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN1,
        // left thumb
        KC_NO,   KC_NO,
                          KC_NO,
        KC_BTN3, KC_BTN2, KC_NO,

        // right hand
        // ____  _______  _______  _______  _______  _______  _______
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_NO,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO,   KC_NO,
        KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,   KC_NO,
                          KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        // right thumb
        KC_NO,   KC_NO,
        KC_NO,
        KC_NO,   KC_MSTP, KC_MPLY
    ),

};
enum next_key_down_up {
    NK_DOWN_UP,
    NK_DOWN,
    NK_UP  // a bit of a hack, this works as long as NK_UP < KC_A
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

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case 0:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
        case COLE:
            ergodox_right_led_1_on();
            break;
        case WORK:
            ergodox_right_led_2_on();
            break;
        case GAME:
            ergodox_right_led_3_on();
            break;
        case MEDI:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case SYMB:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case NUMP:
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

