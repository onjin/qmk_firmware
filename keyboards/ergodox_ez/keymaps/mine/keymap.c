#include QMK_KEYBOARD_H
#include "version.h"

// Define layer names
enum layers { BASE, GAME, COLE, WORK, SYMB, NUMP, MEDI, MIRR};

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here
    EPRM,
    VRSN,
    RGB_SLD,

};

// http://configure.ergodox-ez.com/keyboard_layouts/qmabvw/edit
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base layer (Qwerty)
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           | GAME |   6  |   7  |   8  |   9  |   0  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           | COLE |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |   `    |MEDI/A|Alt/S |Ctr/D |Shf/F |   G  |------|           |------|   H  |Shf/J |Ctr/K |Alt/L |MEDI/;|   '    |
     * |--------+------+------+------+------+------|      |           | WORK |------+------+------+------+------+--------|
     * | LSft   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RSft   |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Ctrl | MIRR | Lead | LGui | Alt/E|                                       | AltGr| RGui | Lead | MIRR | SYMB |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |  Ins |       |  Del | Lock |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | Home |       | PgUp |      |NUMP/ |
     *                                 | Space| BkSp |------|       |------| Enter|Space |
     *                                 |      |      |  End |       | PgDn |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [BASE] = LAYOUT_ergodox(
        // left hand 7/7/6/7/5
        // ____  _______           _______  _______  _______  _______  _______
        KC_ESC,  KC_1,             KC_2,    KC_3,    KC_4,    KC_5,    _______,
        KC_TAB,  KC_Q,             KC_W,    KC_E,    KC_R,    KC_T,    KC_HYPR,
        KC_GRV,  LT(MEDI, KC_A),   LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,
        KC_LSFT, KC_Z,             ALGR_T(KC_X),    KC_C,    KC_V,    KC_B,    KC_MEH,
        KC_LCTL, MO(MIRR),         KC_LEAD, KC_LGUI, LALT_T(KC_ESC),

        KC_NO,   KC_INSERT,
                                   KC_HOME,
        KC_SPC, KC_BSPC, KC_END,

        // right hand
        // ____  _______  _______  _______  _______         _______         _______
        TO(GAME),KC_6,    KC_7,    KC_8,    KC_9,           KC_0,           KC_EQUAL,
        TO(COLE),KC_Y,    KC_U,    KC_I,    KC_O,           KC_P,           KC_BSLASH,
                 KC_H,    RSFT_T(KC_J),     RCTL_T(KC_K),   LALT_T(KC_L),   LT(MEDI, KC_SCOLON), KC_QUOTE,
        TO(WORK),KC_N,    KC_M,             KC_COMM,        ALGR_T(KC_DOT), KC_SLASH, KC_RSHIFT,
                          MO(SYMB),         KC_RGUI,        KC_LEAD,        MO(MIRR), MO(NUMP),

        // right thumb
        KC_DEL, KC_LOCK,
        KC_PGUP,
        KC_PGDOWN, KC_ENT, LT(NUMP, KC_SPC)
    ),

    /* Base layer (COLEMAK)
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           | GAME |   6  |   7  |   8  |   9  |   0  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   F  |   P  |   G  |      |           | BASE |   J  |   L  |   U  |   Y  |   ;  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |   `    |MEDI/A|Alt/R |Ctr/S |Shf/T |   D  |------|           |------|   H  |Shf/N |Ctr/E |Alt/I |MEDI/O|   '    |
     * |--------+------+------+------+------+------|      |           | WORK |------+------+------+------+------+--------|
     * | LSft   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | RSft   |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Ctrl | MIRR | Lead | LGui | Alt/E|                                       | AltGr| RGui | Lead | MIRR | SYMB |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |  Ins |       |  Del | Lock |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | Home |       | PgUp |      |      |
     *                                 | Space| BkSp |------|       |------| Enter|Space |
     *                                 |      |      |  End |       | PgDn |      |      |
     *                                 `--------------------'       `--------------------'
     */
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
    /* Base layer (WORKMAN)
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           | GAME |   6  |   7  |   8  |   9  |   0  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   F  |   P  |   G  |      |           | COLE |   J  |   L  |   U  |   Y  |   ;  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |   `    |MEDI/A|Alt/R |Ctr/S |Shf/T |   D  |------|           |------|   H  |Shf/N |Ctr/E |Alt/I |MEDI/O|   '    |
     * |--------+------+------+------+------+------|      |           | BASE |------+------+------+------+------+--------|
     * | LSft   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | RSft   |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Ctrl | MIRR | Lead | LGui | Alt/E|                                       | AltGr| RGui | Lead | MIRR | SYMB |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |  Ins |       |  Del | Lock |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | Home |       | PgUp |      |      |
     *                                 | Space| BkSp |------|       |------| Enter|Space |
     *                                 |      |      |  End |       | PgDn |      |      |
     *                                 `--------------------'       `--------------------'
     */
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
    /* Game layer (Qwerty) - less modifiers
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           | BASE |   6  |   7  |   8  |   9  |   0  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           | COLE |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |   `    |   A  |   W  |   E  |   F  |   G  |------|           |------|   H  |   J  |   K  |   O  |MEDI/;|   '    |
     * |--------+------+------+------+------+------|      |           | WORK |------+------+------+------+------+--------|
     * | LSft   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RSft   |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Ctrl | MIRR | Lead | LGui | Alt/E|                                       | AltGr| RGui | Lead | MIRR | SYMB |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |  Ins |       |  Del | Lock |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | Home |       | PgUp |      |      |
     *                                 | Space| BkSp |------|       |------| Enter|Space |
     *                                 |      |      |  End |       | PgDn |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [GAME] = LAYOUT_ergodox(
        // left hand 7/7/6/7/5
        // ____  _______           _______  _______  _______  _______  _______
        _______, _______,          _______, _______, _______, _______, _______,
        _______, _______,          _______, _______, _______, _______, _______,
        _______, KC_A,             KC_S,    KC_D,    KC_F,    _______,
        _______, _______,          KC_X,    _______, _______, _______, _______,
        _______, _______,          _______, _______, _______,

        KC_NO,   KC_INSERT,
                                   KC_HOME,
        KC_SPC, KC_BSPC, KC_END,

        // right hand
        // ____  _______  _______  _______  _______  _______  _______
        TO(BASE),_______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                 _______, KC_J,    KC_K,    KC_L,    _______, _______,
        _______, _______, _______, _______, KC_DOT,  _______, _______,
                          _______, _______, _______, _______, _______,

        // right thumb
        KC_DEL, KC_LOCK,
        KC_PGUP,
        KC_PGDOWN, KC_ENT, KC_SPC
    ),


    /* Symbols layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |   #  |   ^  |   [  |   ]  |   \  |      |           |      |   /  |   !  |   _  |   =  |   *  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |   &  |   $  |   (  |   )  |   |  |------|           |------|   ~  |   -  |   <  |   >  |   :  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |   %  |   @  |   {  |   }  |   !  |      |           |      |      |   +  |   ,  |   .  |   `  |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |   ~  |  `   |                                       | XXX  |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |   -  |   _  |------|       |------| Enter|  ,   |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [SYMB] = LAYOUT_ergodox(
        // left hand 7/7/6/7/5
        // ____  _______  _______  _______  _______  _______  _______
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_HASH, KC_CIRC, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO,
        KC_NO,   KC_AMPR, KC_DLR,  KC_LPRN, KC_RPRN, KC_PIPE,
        KC_NO,   KC_PERC, KC_AT,   KC_LCBR, KC_RCBR, KC_EXLM, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_TILD, KC_GRAVE,
        // left thumb
        KC_NO,   KC_NO,
                          KC_NO,
        KC_MINS, KC_UNDS, KC_NO,

        // right hand 7/7/6/7/5
        // ____  _______  _______  _______  _______  _______  _______
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_PSLS, KC_EXLM, KC_UNDS, KC_EQUAL,KC_PAST, KC_NO,
                 KC_TILD, KC_MINS, KC_LT,   KC_GT,   KC_COLN, KC_NO,
        KC_NO,   KC_NO,   KC_PLUS, KC_COMM, KC_DOT,  KC_GRAVE,KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

        // right thumb
        KC_NO,   KC_NO,
                          KC_NO,
        KC_NO,   KC_PENT, KC_PDOT
    ),


    /* Numpad layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | ESC    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |   /  |   7  |   8  |   9  |   *  |      |           |      |   /  |   7  |   8  |   9  |   *  |  F12   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |    ,   |   -  |   4  |   5  |   6  |   +  |------|           |------|   -  |   4  |   5  |   6  |   +  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |   0  |   1  |   2  |   3  |   =  |      |           |      |   0  |   1  |   2  |   3  |   =  |  CAPS  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      | XXX  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------| Enter| XXX  |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [NUMP] = LAYOUT_ergodox(
        // left hand 7/7/6/7/5
        // ____  _______  _______  _______  _______  _______  _______
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,
        KC_NO,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_NO,
        KC_COMM, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_NO,   KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        // left thumb
        KC_NO,   KC_NO,
                          KC_NO,
        KC_NO,   KC_NO,   KC_NO,

        // right hand 7/7/6/7/5
        // ____  _______  _______  _______  _______  _______  _______
        KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_NO,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_F12,
                 KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NO,
        KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_CAPS,
                          KC_NO,   KC_NO,   KC_P0,   KC_NO,   KC_NO,

        // right thumb
        KC_NO,   KC_NO,
                          KC_NO,
        KC_NO,   KC_PENT, KC_NO
    ),

    /* Media layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |L/TOG |L/MOD |L/HUI |L/SAI |L/VAI |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Reset  |      |Whl/L |Whl/D |Whl/U |Whl/R |      |           |      |Home  |PageDn|PageUp| End  | Ins  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |Mou/L |Mou/D |Mou/U |Mou/R |------|           |------| Left | Down | Up   | Right| XXX  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |MAcl0 |MAcl1 | MAcl2|      |      |           |      |      |MePrev|VolDwn|VolUp |MeNext|        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      | Btn1 |                                       | Mute |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      | A2DP | Play |
     *                                 | Btn3 | Btn2 |------|       |------|   /  |  /   |
     *                                 |      |      |      |       |      | HFS  | Stop |
     *                                 `--------------------'       `--------------------'
     */
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

    // Qwerty mirror - should be migrated to native qmk mirror feature to support all layers
    [MIRR] = LAYOUT_ergodox(
        // left hand
        KC_EQUAL, KC_MINUS, KC_0, KC_9, KC_8, KC_7, KC_TRANSPARENT, KC_BSLASH, KC_P, KC_O, KC_I, KC_U, KC_Y, KC_TRANSPARENT, KC_QUOTE, KC_SCOLON, KC_L, KC_K, KC_J, KC_H, KC_LSHIFT, KC_SLASH, KC_DOT, KC_COMMA, KC_M, KC_N, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        // left thumb
        KC_LOCK, KC_DELETE, KC_PGUP, KC_SPACE, KC_ENTER, KC_PGDOWN,

        // right hand
        KC_6, KC_5, KC_4, KC_3, KC_2, KC_1, KC_ESCAPE, KC_TRANSPARENT, KC_T, KC_R, KC_E, KC_W, KC_Q, KC_TAB, KC_G, KC_F, KC_D, KC_S, KC_A, KC_GRAVE, KC_TRANSPARENT, KC_B, KC_V, KC_C, KC_X, KC_Z, KC_LSHIFT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        // right thumb
        KC_INSERT, KC_ESCAPE, KC_HOME, KC_END, KC_BSPACE, KC_SPACE),


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
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        #ifdef RGBLIGHT_ENABLE
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
            break;
        # endif
    }
    return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

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


        // projects
        SEQ_TWO_KEYS(KC_S, KC_S) { SEND_STRING("cd /home/onjin/Workspace/p/cint/src/points2shop/\n"); }
        SEQ_TWO_KEYS(KC_S, KC_L) { SEND_STRING("cd /home/onjin/Workspace/p/cint/src/points2shop/\nssh lxc.p2ssolo\n"); }
        SEQ_TWO_KEYS(KC_N, KC_N) { SEND_STRING("cd /home/onjin/Workspace/p/hint/szpital/niezgodnosci\n"); }

        // fzf
        SEQ_ONE_KEY(KC_F) { SEND_STRING("$(fzf)"); }

        // qmk
        SEQ_ONE_KEY(KC_Q) { SEND_STRING("qmk compile && qmk flash\n"); }

    }

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
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
        case MIRR:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case SYMB:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case NUMP:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
            break;
    }

    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
    }
};

