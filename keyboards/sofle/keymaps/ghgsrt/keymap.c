#include QMK_KEYBOARD_H
#include "keymap_dvorak_programmer.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _DVORAK,
	_NAV,
	_NAV_SHIFT,
	_NUM,
	_SHIFT,
	_NUM_SHIFT,
	_QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   ;  |   ,  |   .  |   p  |   y  |                    |   f  |   g  |   c  |   r  |   l  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtrl |   a  |   o  |   e  |   u  |   i  |-------.    ,-------|   d  |   h  |   t  |   n  |   s  |Enter |
 * |------+------+------+------+------+------|  	 |    |       |------+------+------+------+------+------|
 * | LAlt |   '  |   q  |   j  |   k  |   x  |-------|    |-------|   b  |   m  |   w  |   v  |   z  | NAV  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LWIN | CAPS |	   |LShift| /  NUM   /      \Space \  |RShift|  	| 	   | 	  |
 *            |      |      |      |      |/       /         \      \|      |      |      |      |
 *            `----------------------------------'           '----------------------------------'
 */

[_DVORAK] = LAYOUT(
  KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_DEL,
  KC_TAB, KC_SCLN, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                    KC_F,       KC_G,    KC_C,    KC_R,    KC_L,  KC_BSPC,
  KC_LCTL,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                    KC_D,       KC_H,    KC_T,    KC_N,    KC_S,   KC_ENT,
  KC_LALT, KC_QUOT,   KC_Q,    KC_J,    KC_K,    KC_X, XXXXXXX,  XXXXXXX, KC_B,       KC_M,    KC_W,    KC_V,    KC_Z, MO(_NAV),
             KC_LGUI, KC_CAPS, XXXXXXX, MO(_SHIFT), MO(_NUM),      KC_SPC, MO(_SHIFT), XXXXXXX, XXXXXXX, XXXXXXX
),
/* SHIFT_DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | PASS |      |      |      |      |      |                    |      |      |      |      |      | PASS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | STAB |   :  |   <  |   >  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  | PASS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PASS |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  | PASS |
 * |------+------+------+------+------+------|  	 |    |       |------+------+------+------+------+------|
 * | PASS |   "  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  | SNAV |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | PASS | PASS |	   | PASS | / SNUM  /       \ PASS \  | PASS |  	| 	   | 	  |
 *            |      |      |      |      |/       /         \      \|      |      |      |      |
 *            `----------------------------------'           '----------------------------------'
 */

[_SHIFT] = LAYOUT(
  _______,      _______,    _______,   _______, _______, _______,                    _______, _______, _______, _______, _______,        _______,
  S(KC_TAB), S(KC_SCLN), S(KC_COMM), S(KC_DOT), S(KC_P), S(KC_Y),                    S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L),        _______,
  _______,      S(KC_A),    S(KC_O),   S(KC_E), S(KC_U), S(KC_I),                    S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S),        _______,
  _______,   S(KC_QUOT),    S(KC_Q),   S(KC_J), S(KC_K), S(KC_X), _______,  _______, S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z), MO(_NAV_SHIFT),
                     _______, _______, _______, _______, MO(_NUM_SHIFT),      _______, _______, _______, _______, _______
),
/* NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |      |      |      |      |      |                    |      |      | 	   | 	  |      | PASS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PASS |      |   @  |   -  |   *  |      |                    |      |   +  |   /  |   #  |      | PASS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PASS |   !  |   [  |   {  |   (  |   &  |-------.    ,-------|   |  |   )  | 	}  |   ]  |   =  | PASS |
 * |------+------+------+------+------+------| PASS  |    | PASS  |------+------+------+------+------+------|
 * | PASS |      |      |      |      |      |-------|    |-------|      | 	    | 	   | 	  |      | NAV  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | PASS | PASS | PASS | SNUM | / PASS  /       \ PASS \  |	SNUM | PASS | PASS | PASS |
 *            |      |      |      |      |/       /         \      \|      |      |      |      |
 *            `----------------------------------'           '----------------------------------'
 */
  [_NUM] = LAYOUT(
  KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
  _______, XXXXXXX,   KC_AT, KC_MINS, KC_ASTR, XXXXXXX,                    XXXXXXX, KC_PLUS, KC_SLSH, KC_HASH, XXXXXXX,  _______,
  _______, KC_EXLM, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,                    KC_PIPE, KC_RPRN, KC_RCBR, KC_RBRC,  KC_EQL,  _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(_NAV),
           _______, _______, _______, MO(_NUM_SHIFT), _______,      _______, MO(_NUM_SHIFT), _______, _______, _______
  ),
/* NUM_SHIFT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   ~  |      |      |      |      |      |                    |      |      | 	   | 	  |      | PASS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PASS |      |   ^  |   _  |   %  |      |                    |      |   ?  |   \  |   $  |      | PASS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PASS |   1  |   2  |   3  |   4  |  5   |-------.    ,-------|   6  |   7  |   8  |   9  |   0  | PASS |
 * |------+------+------+------+------+------| PASS  |    | PASS  |------+------+------+------+------+------|
 * | PASS |      |      |      |      |      |-------|    |-------|      | 	    | 	   | 	  |      | SNAV |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | PASS | PASS | PASS | PASS | / PASS  /       \ PASS \  |	PASS | PASS | PASS | PASS |
 *            |      |      |      |      |/       /         \      \|      |      |      |      |
 *            `----------------------------------'           '----------------------------------'
 */
  [_NUM_SHIFT] = LAYOUT(
  S(KC_GRV), XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,        _______,
  _______,   XXXXXXX, S(KC_6), S(KC_MINS), S(KC_5), XXXXXXX,                    XXXXXXX, S(KC_SLSH),    KC_BSLS, S(KC_3), XXXXXXX,        _______,
  _______,      KC_1,    KC_2,       KC_3,    KC_4,    KC_5,                    KC_6,          KC_7,       KC_8,    KC_9,    KC_0,        _______,
  _______,   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, _______,  _______, XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, MO(_NAV_SHIFT),
                       _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
  ),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | PASS |      |      |      |      |      |                    |      |      |      |      |      | PASS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PASS |      |  UP  |      |      |      |                    |      |      |      |      |	     | PASS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PASS | LEFT | DOWN |RIGHT | PLAY |      |-------.    ,-------|      |      | 	   | 	  |      | PASS |
 * |------+------+------+------+------+------| PASS  |    | PASS  |------+------+------+------+------+------|
 * | PASS | VOLD | VOLU | MUTE |      |      |-------|    |-------|      | 	    | 	   | 	  |      | PASS |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | PASS | PASS | PASS | SNAV | / PASS  /       \ PASS \  |	SNAV | PASS | PASS | PASS |
 *            |      |      |      |      |/       /         \      \|      |      |      |      |
 *            `----------------------------------'           '----------------------------------'
 */
  [_NAV] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX,   KC_UP, XXXXXXX,  XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MPLY, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_VOLD, KC_VOLU,  KC_MUTE, XXXXXXX, XXXXXXX, _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            _______, _______, _______, MO(_NAV_SHIFT), _______,      _______, MO(_NAV_SHIFT), _______, _______, _______
  ),
/* NAV_SHIFT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | PASS |      |      |      |      |      |                    |      |      |      |      |      | PASS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PASS |      |  UP  |      |      |      |                    |      |      |      |      |	     | PASS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PASS | LEFT | DOWN |RIGHT | PLAY |      |-------.    ,-------|      |      | 	   | 	  |      | PASS |
 * |------+------+------+------+------+------| PASS  |    | PASS  |------+------+------+------+------+------|
 * | PASS | VOLD | VOLU | MUTE |      |      |-------|    |-------|      | 	    | 	   | 	  |      | PASS |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | PASS | PASS | PASS | PASS | / PASS  /       \ PASS \  |	PASS | PASS | PASS | PASS |
 *            |      |      |      |      |/       /         \      \|      |      |      |      |
 *            `----------------------------------'           '----------------------------------'
 */
  [_NAV_SHIFT] = LAYOUT(
  _______,    XXXXXXX,    XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______,    XXXXXXX,   S(KC_UP),     XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, S(KC_LEFT), S(KC_DOWN), S(KC_RIGHT), KC_MPLY, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______,    KC_VOLD,    KC_VOLU,     KC_MUTE, XXXXXXX, XXXXXXX, _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                            _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
  )
// /* NAV
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |      |      |      |      |      |      |-------.    ,-------|      |      | 	   | 	  |      |      |
//  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
//  * |      |      |      |      |      |      |-------|    |-------|      | 	    | 	   | 	  |      |      |
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            |      |      |      |      | /       /       \      \  |	 	 | 	    |	   |	  |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
//   [_NAV] = LAYOUT(
//   XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   QK_BOOT  , XXXXXXX,KC_QWERTY,KC_COLEMAK,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
//   XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
//                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
//   )
// /*
//  * COLEMAK
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
//  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
//  * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */

// [_COLEMAK] = LAYOUT(
//   KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
//   KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
//   KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
//   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,      XXXXXXX,KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
//                  KC_LGUI,KC_LALT,KC_LCTL,MO(_LOWER), KC_ENT,        KC_SPC,  MO(_RAISE), KC_RCTL, KC_RALT, KC_RGUI
// ),
// /* LOWER
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
//  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
//  * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
// [_LOWER] = LAYOUT(
//   _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
//   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
//   _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
//   _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
//                        _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
// ),
// /* RAISE
//  * ,----------------------------------------.                    ,-----------------------------------------.
//  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
//  * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
//  * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
// [_RAISE] = LAYOUT(
//   _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
//   _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE, KC_BSPC,
//   _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
//   _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
//                          _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
// ),
// /* ADJUST
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
//  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
//  * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
//   [_ADJUST] = LAYOUT(
//   XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   QK_BOOT  , XXXXXXX,KC_QWERTY,KC_COLEMAK,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
//   XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
//                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
//   )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case KC_QWERTY:
//             if (record->event.pressed) {
//                 set_single_persistent_default_layer(_QWERTY);
//             }
//             return false;
//         case KC_COLEMAK:
//             if (record->event.pressed) {
//                 set_single_persistent_default_layer(_COLEMAK);
//             }
//             return false;
//         case KC_PRVWD:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 }
//             }
//             break;
//         case KC_NXTWD:
//              if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 }
//             }
//             break;
//         case KC_LSTRT:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                      //CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_code(KC_HOME);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_code(KC_HOME);
//                 }
//             }
//             break;
//         case KC_LEND:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     //CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_code(KC_END);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_code(KC_END);
//                 }
//             }
//             break;
//         case KC_DLINE:
//             if (record->event.pressed) {
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_BSPC);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_BSPC);
//             }
//             break;
//         case KC_COPY:
//             if (record->event.pressed) {
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_C);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_C);
//             }
//             return false;
//         case KC_PASTE:
//             if (record->event.pressed) {
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_V);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_V);
//             }
//             return false;
//         case KC_CUT:
//             if (record->event.pressed) {
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_X);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_X);
//             }
//             return false;
//             break;
//         case KC_UNDO:
//             if (record->event.pressed) {
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_Z);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_Z);
//             }
//             return false;
//     }
//     return true;
// }

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
