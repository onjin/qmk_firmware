#pragma once

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
#define ONJIN_ALTERNATIVES_BASE_QWERTY \
    KC_ESC,  KC_1,             KC_2,    KC_3,    KC_4,    KC_5,    _______,\
    KC_TAB,  KC_Q,             KC_W,    KC_E,    KC_R,    KC_T,    _______,\
    KC_GRV,  LGUI_T(KC_A),     LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,\
    KC_LEAD, LT(BUTTON, KC_Z),             ALGR_T(KC_X),    KC_C,    HYPR_T(KC_V),    MEH_T(KC_B),    KC_MEH,\
    SH_MON,  SH_MON,           KC_LEAD, KC_LGUI,LT(MEDIA, KC_ESC),\
    KC_NO,   KC_INSERT,\
                                KC_HOME,\
    LT(NAV, KC_SPC), LT(MOUSE, KC_BSPC), KC_END,\
    TO(GAME),KC_6,    KC_7,    KC_8,    KC_9,           KC_0,           KC_EQUAL,\
    TO(COLE),KC_Y,    KC_U,    KC_I,    KC_O,           KC_P,           KC_BSLASH,\
                KC_H,    RSFT_T(KC_J),     RCTL_T(KC_K),   LALT_T(KC_L),   LGUI_T(KC_SCOLON), KC_QUOTE,\
    TO(WORK),KC_N,    KC_M,             KC_COMM,        ALGR_T(KC_DOT), LT(BUTTON, KC_SLASH), KC_LEAD,\
                        LT(SYMB, KC_TAB),         MO(NUMP),        KC_LEAD,        SH_MON,   SH_MON,\
    KC_DEL, KC_LOCK,\
    KC_PGUP,\
    KC_PGDOWN, LT(SYM,KC_ENT), LT(NUM, KC_SPC)

/***1* Base layer (COLEMAK DH)
 ***1*
 ***1* ,--------------------------------------------------.           ,--------------------------------------------------.
 ***1* | Esc    |   1  |   2  |   3  |   4  |   5  |      |           | GAME |   6  |   7  |   8  |   9  |   0  |   =    |
 ***1* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 ***1* | Tab    |   Q  |   W  |   F  |   P  |   B  |      |           | BASE |   J  |   L  |   U  |   Y  |   ;  |   \    |
 ***1* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 ***1* |   `    |MEDI/A|Alt/R |Ctr/S |Shf/T |   G  |------|           |------|   M  |Shf/N |Ctr/E |Alt/I |MEDI/O|   '    |
 ***1* |--------+------+------+------+------+------|      |           | WORK |------+------+------+------+------+--------|
 ***1* | LSft   |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   /  | RSft   |
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
#define ONJIN_ALTERNATIVES_BASE_COLEMAK_DH \
    _______, _______,          _______,         _______,        _______,        _______, _______,\
    _______, KC_Q,             KC_W,            KC_F,           KC_P,           KC_B,    _______,\
    _______, LT(MEDI, KC_A),   LALT_T(KC_R),    LCTL_T(KC_S),   LSFT_T(KC_T),   KC_G,\
    _______, KC_Z,             ALGR_T(KC_X),    KC_C,           KC_D,           KC_V,    _______,\
    _______, _______,          _______,         _______,        _______,\
    _______,  _______,\
                               _______,\
    _______,  _______, _______,\
    _______, _______, _______,          _______,        _______,        _______,          _______,\
    TO(BASE),KC_J,    KC_L,             KC_U,           KC_Y,           KC_SCLN,          _______,\
             KC_M,    RSFT_T(KC_N),     RCTL_T(KC_E),   LALT_T(KC_I),   LT(MEDI, KC_O),   _______,\
    _______, KC_K,    KC_H,             KC_COMM,        ALGR_T(KC_DOT), KC_SLASH,         _______,\
                      _______,          _______,        _______,        _______,          _______,\
    _______, _______,\
    _______,\
    _______, _______, _______

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
#define ONJIN_ALTERNATIVES_BASE_WORKMAN \
    _______, _______,          _______,         _______,        _______,        _______, _______,\
    _______, KC_Q,             KC_D,            KC_R,           KC_W,           KC_B,    _______,\
    _______, LT(MEDI, KC_A),   LALT_T(KC_S),    LCTL_T(KC_H),   LSFT_T(KC_T),   KC_G,\
    _______, KC_Z,             ALGR_T(KC_X),    KC_M,           KC_C,           KC_V,    _______,\
    _______, _______,          _______,         _______,        _______,\
    _______,  _______,\
                               _______,\
    _______,  _______, _______,\
    _______, _______, _______,          _______,        _______,        _______,          _______,\
    _______, KC_J,    KC_F,             KC_U,           KC_P,           KC_SCLN,          _______,\
             KC_Y,    RSFT_T(KC_N),     RCTL_T(KC_E),   LALT_T(KC_O),   LT(MEDI, KC_L),   _______,\
    TO(BASE),KC_K,    KC_L,             KC_COMM,        ALGR_T(KC_DOT), KC_SLASH,         _______,\
                      _______,          _______,        _______,        _______,          _______,\
    _______, _______,\
    _______,\
    _______, _______, _______

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
#define ONJIN_ALTERNATIVES_GAME \
    _______, _______,          _______, _______, _______, _______, _______,\
    _______, _______,          _______, _______, _______, _______, _______,\
    _______, KC_A,             KC_S,    KC_D,    KC_F,    _______,\
    KC_LSFT, _______,          KC_X,    _______, KC_V,    KC_B,    _______,\
    KC_LCTL, _______,          _______, _______, _______,\
    KC_NO,   KC_INSERT,\
                               KC_HOME,\
    KC_SPC, KC_BSPC, KC_END,\
    TO(BASE),_______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______,\
             _______, KC_J,    KC_K,    KC_L,    _______, _______,\
    _______, _______, _______, _______, KC_DOT,  _______, KC_RSFT,\
                      _______, _______, _______, _______, KC_RCTL,\
    KC_DEL, KC_LOCK,\
    KC_PGUP,\
    KC_PGDOWN, KC_ENT, KC_SPC


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
#define ONJIN_ALTERNATIVES_SYMBOLS \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
    KC_NO,   KC_HASH, KC_CIRC, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO,\
    KC_NO,   KC_AMPR, KC_DLR,  KC_LPRN, KC_RPRN, KC_PIPE,\
    KC_NO,   KC_PERC, KC_AT,   KC_LCBR, KC_RCBR, KC_EXLM, KC_NO,\
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
    KC_NO,   KC_NO,\
                      KC_NO,\
    KC_NO,   KC_NO,   KC_NO,\
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
    KC_NO,   KC_PSLS, KC_EXLM, KC_UNDS, KC_EQUAL,KC_PAST, KC_NO,\
             KC_TILD, KC_MINS, KC_LT,   KC_GT,   KC_COLN, KC_DQUO,\
    KC_NO,   KC_NO,   KC_PLUS, KC_COMM, KC_DOT,  KC_GRAVE,KC_NO,\
                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
    KC_NO,   KC_NO,\
                      KC_NO,\
    KC_NO,   KC_NO,   KC_NO


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
#define ONJIN_ALTERNATIVES_NUMPAD \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,\
    SHFT_INS,KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_NO,\
    KC_COMM, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,\
    KC_CAPS, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_NO,\
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
    KC_NO,   KC_NO,\
                      VRSN,\
    _______, _______, KC_ENT,\
    KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,\
    KC_NO,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_F12,\
             KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NO,\
    KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_NO,\
                      KC_NO,   KC_NO,   KC_P0,   KC_NO,   KC_NO,\
    KC_NO,   KC_NO,\
                      KC_NO,\
    KC_NO,   KC_PENT, KC_NO

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
#define ONJIN_ALTERNATIVES_MEDIA \
    KC_NO,   KC_TOG,  KC_MOD,  KC_HUI,  KC_SAI,  KC_VAI,  KC_NO,\
    KC_RST,  KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,\
    KC_NO,   KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,\
    KC_NO,   KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,   KC_NO,\
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN1,\
    KC_NO,   KC_NO,\
                      KC_NO,\
    KC_BTN3, KC_BTN2, KC_NO,\
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
    KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_NO,\
             KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO,   KC_NO,\
    KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,   KC_NO,\
                      KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,\
    KC_NO,   KC_NO,\
    KC_NO,\
    KC_NO,   KC_MSTP, KC_MPLY

/***0* Base layer (Qwerty)
***0*
***0* ,--------------------------------------------------.           ,--------------------------------------------------.
***0* |        |      |      |      |      |      |      |           | GAME |      |      |      |      |      |        |
***0* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
***0* |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
***0* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
***0* |        |Gui/A |Alt/S |Ctr/D |Shf/F |   G  |------|           |------|   H  |Shf/J |Ctr/K |Alt/L |Gui/; |        |
***0* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
***0* |        |   Z  |AltG/X|   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |AltG/.|   /  |        |
***0* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
***0*   |      |      |      |      |MED/Es|                                       |FUN/Ta|      |      |      |      |
***0*   `----------------------------------'                                       `----------------------------------'
***0*                                        ,-------------.       ,-------------.
***0*                                        |      |      |       |      |      |
***0*                                 ,------|------|------|       |------+------+------.
***0*                                 | NAV/ | MOUS/|      |       |      | SYMB/|NUMB/ |
***0*                                 | Space| BkSp |------|       |------| Enter|Space |
***0*                                 |      |      |      |       |      |      |      |
***0*                                 `--------------------'       `--------------------'
***0*/
#define ONJIN_ALTERNATIVES_BASE36_QWERTY \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),   \
LT(BUTTON, KC_Z),  ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(BUTTON, KC_SLSH), \
U_NP,              U_NP,              LT(MEDIA, KC_ESC), LT(NAV, KC_SPC),   LT(MOUSE, KC_BSPC),LT(SYM, KC_ENT),   LT(NUM, KC_SPC),   LT(FUN, KC_TAB),   U_NP,              U_NP


#define ONJIN_ALTERNATIVES_NAV_VI \
RESET,             U_NA,              U_NA,              U_NA,              U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           KC_CAPS,           \
U_NA,              KC_ALGR,           U_NA,              U_NA,              U_NA,              KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            KC_INS,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define ONJIN_ALTERNATIVES_MOUSE_VI \
RESET,             U_NA,              U_NA,              U_NA,              U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           U_NU,              \
U_NA,              KC_ALGR,           U_NA,              U_NA,              U_NA,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN1,           KC_BTN3,           KC_BTN2,           U_NP,              U_NP

#define ONJIN_ALTERNATIVES_MEDIA_VI \
RESET,             U_NA,              U_NA,              U_NA,              U_NA,              RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           OUT_AUTO,          \
U_NA,              KC_ALGR,           U_NA,              U_NA,              U_NA,              U_NU,              U_NU,              U_NU,              U_NU,              U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

#define ONJIN_ALTERNATIVES_NUM \
KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           U_NA,              U_NA,              U_NA,              U_NA,              RESET,             \
KC_QUOT,           KC_4,              KC_5,              KC_6,              KC_EQL,            U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           U_NA,              U_NA,              U_NA,              KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define ONJIN_ALTERNATIVES_SYM \
KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           U_NA,              U_NA,              U_NA,              U_NA,              RESET,             \
KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           U_NA,              U_NA,              U_NA,              KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_LPRN,           KC_RPRN,           KC_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define ONJIN_ALTERNATIVES_FUN \
KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              U_NA,              U_NA,              U_NA,              RESET,             \
KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SLCK,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              U_NA,              U_NA,              KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP


#define ONJIN_ALTERNATIVES_BUTTON \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_NO,             KC_NO,             KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NP,              U_NP,              KC_BTN2,           KC_BTN3,           KC_BTN1,           KC_BTN1,           KC_BTN3,           KC_BTN2,           U_NP,              U_NP

