/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _GHERKIN_DVORAK,
  _RAISE,
  _LOWER,
  _GHELOW,
  _GHE3,
  _PLOVER,
  _ADJUST,
  _SPGHEDOV,
  _SPGHE1,
  _SPGHE2,
  _SPGHE3
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  GHERKIN_DVORAK,
  RAISE,
  LOWER,
  GHELOW,
  GHE3,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  SPGHEDOV,
  SPGHE1,
  SPGHE2,
  SPGHE3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | GUI  | Alt  | Lower|Space |  Shift      |Raise | Lower| Pg Up|Pg Dn | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_ESC,  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_LSFT, KC_LSFT, RAISE,   LOWER,   KC_PGUP, KC_PGDN, KC_RCTL}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | GUI  | Alt  | Lower|Space |  Shift      |Raise | Lower| Pg Up|Pg Dn | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_ESC,  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_LSFT, KC_LSFT, RAISE,   LOWER,   KC_PGUP, KC_PGDN, KC_RCTL}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | GUI  | Alt  | Lower|Space |  Shift      |Raise | Lower| Pg Up|Pg Dn | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT },
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT},
  {KC_ESC,  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_LSFT, KC_LSFT, RAISE,   LOWER, KC_PGUP, KC_PGDN,   KC_RCTL}
},

/* Gherkin Dvorak
 * ,----------------------------------------------------------------------------------------------.
 * |      |tab     |space/alt| ent/ctrl|   P  |   Y  |   F  |   G   |   C  |   R  |L/raise |      |
 * |------+--------+---------+---------+------+-------------+-------+------+------+--------+------|
 * |      |A       |   O     |   E     |   U  |   I  |   D  |   H   |   T  |   N  |S/ghelow|      |
 * |------+--------+---------+---------+------+------|------+-------+------+------+--------+------|
 * |      |esc/sft |   Q/gui |    J    |   K  |   X  |   B  |   M   |   W  |   V  |Z/ghe3  |      |
 * |------+--------+---------+---------+------+------+------+-------+------+------+--------+------|
 * |      |        |         |         |      |      |      |       |      |      |        |      |
 * `----------------------------------------------------------------------------------------------'
 */
[_GHERKIN_DVORAK] = {
  {KC_NO, KC_TAB,     ALT_T(KC_SPC),CTL_T(KC_ENT), KC_P,   KC_Y, KC_F,    KC_G,   KC_C,   KC_R,   LT(4,KC_L),KC_NO},
  {KC_NO, KC_A,                KC_O,KC_E,          KC_U,   KC_I, KC_D,    KC_H,   KC_T,   KC_N,   LT(6,KC_S),KC_NO},
  {KC_NO, SFT_T(KC_ESC),GUI_T(KC_Q),KC_J,          KC_K,   KC_X, KC_B,    KC_M,   KC_W,   KC_V,   LT(7,KC_Z),KC_NO},
  {KC_NO, KC_NO,              KC_NO,KC_NO,         KC_NO,  KC_NO,KC_NO,   KC_NO, KC_NO,  KC_NO,        KC_NO,KC_NO}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  $   |  _   |  \   |   #  |   @  |  {   |  }   |  1   |  2   |  3   |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  +   |  -   |  *   |  /   |  =   |  (   |  )   |  4   |  5   |  6   |  0   | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ^   |  &   |  |   |  ?   |  !   |  [   |  ]   |  7   |  8   |  9   |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ~   |   %  |  `   | Lower|Space |  Shift      |Raise | Lower|Pg Up |Pg Dn | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_DLR,  KC_UNDS, KC_BSLS, KC_HASH,    KC_AT,   KC_LCBR, KC_RCBR, KC_1,    KC_2,    KC_3, _______, KC_DEL},
  {KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH,    KC_EQL,  KC_LPRN, KC_RPRN, KC_4,    KC_5,    KC_6, KC_0,   KC_ENT},
  {KC_CIRC, KC_AMPR, KC_PIPE, KC_QUESTION,KC_EXLM, KC_LBRC, KC_RBRC, KC_7,    KC_8,    KC_9, _______,KC_RSFT},
  {KC_TILD, KC_PERC, KC_GRV,  LOWER,      KC_SPC,  KC_LSFT, KC_LSFT, RAISE,   LOWER,KC_PGUP, KC_PGDN,KC_RCTL}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   F10|  F1  |  F2  |  F3  | MUTE |BL_TOG|Pg Up | UP   | Pg Dn|      | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   F11|  F4  |  F5  |  F6  | Vol+ |BL_INC| LEFT | DOWN |RIGHT |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   F12|  F7  |  F8  |  F9  | Vol- |BL_DEC|Home  |insert|  End |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | GUI  | Alt  | Lower|Space |  Shift      |Raise | Lower| Pg Up|Pg Dn | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TAB,  KC_F10,  KC_F1,   KC_F2,   KC_F3,  KC_MUTE,  BL_TOGG, KC_PGUP, KC_UP,  KC_PGDN,_______,  KC_DEL},
  {KC_CAPS, KC_F11,  KC_F4,   KC_F5,   KC_F6,  KC_VOLU,  BL_INC,  KC_LEFT, KC_DOWN,KC_RGHT,_______,  KC_ENT },
  {KC_LSFT, KC_F12,  KC_F7,   KC_F8,   KC_F9,  KC_VOLD,  BL_DEC,  KC_HOME, KC_INS, KC_END, _______,  KC_RSFT},
  {KC_ESC,  KC_LGUI, KC_LALT, LOWER,   KC_SPC, KC_LSFT,  KC_LSFT, RAISE,   LOWER, KC_PGUP, KC_PGDN, KC_RCTL}
},

/* Gherkin Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  '   |   ,  |   .  |  #   |  {   |  }   |Pg Up | UP   | Pg Dn| Home |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  -   |  *   |  /   |  =   |  (   |  )   | LEFT | DOWN |RIGHT |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ;   |  |   |  ?   |  !   |  [   |  ]   | BSPC | DEL  |insert| End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GHELOW] = {
  {KC_NO,  KC_QUOT, KC_COMM, KC_DOT,     KC_HASH, KC_LCBR, KC_RCBR,  KC_PGUP, KC_UP,  KC_PGDN,KC_HOME,KC_NO},
  {KC_NO,  KC_MINS, KC_ASTR, KC_SLSH,    KC_EQL,  KC_LPRN, KC_RPRN,  KC_LEFT, KC_DOWN,KC_RGHT,_______,KC_NO},
  {KC_NO,  KC_SCLN, KC_PIPE, KC_QUESTION,KC_EXLM, KC_LBRC, KC_RBRC,  KC_BSPC, KC_DEL, KC_INS, KC_END, KC_NO},
  {KC_NO,  KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO}
},

/* Gherkin 3
 * ,-----------------------------------------------------------------------------------.
 * |      |  "   |   <  |  >   | \    | MUTE |   F10|  F1  |  F2  |  F3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  _   |  +   |  ^   |  $   | Vol+ |   F11|  F4  |  F5  |  F6  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  :   |  ~   |   %  |  `   | Vol- |   F12|  F7  |  F8  |  F9  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GHE3] = {
  {KC_NO,  KC_DQT, KC_LT,   KC_GT,   KC_BSLS,KC_MUTE,  KC_F10,  KC_F1,   KC_F2,   KC_F3,_______,KC_NO},
  {KC_NO, KC_UNDS, KC_PLUS, KC_CIRC, KC_DLR, KC_VOLU,  KC_F11,  KC_F4,   KC_F5,   KC_F6,_______,KC_NO},
  {KC_NO, KC_COLN, KC_TILD, KC_PERC, KC_GRV, KC_VOLD,  KC_F12,  KC_F7,   KC_F8,   KC_F9,_______,KC_NO},
  {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,  KC_NO,KC_NO}
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-------------------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |              |      |  Del |
 * |------+------+------+------+------+-------------+------+------+--------------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak        |Plover|      |
 * |------+------+------+------+------+------|------+------+------+--------------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |GHERKIN_DVORAK|      |      |
 * |------+------+------+------+------+------+------+------+------+--------------+------+------|
 * |      |      |      |      |      |             |      |      | SPGHEDOV     |      |      |
 * `-------------------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, SPGHEDOV, GHERKIN_DVORAK, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


/* Split Gherkin Dvorak
 * ,----------------------------------------------------------------------------------------------.
 * |        |         |         |      |      |Raise | Lower|      |       |      |      |        |
 * |--------+---------+---------+------+------+------+------+------+-------+------+------+--------|
 * |tab     |space/alt| ent/ctrl|   P  |   Y  |      |      |   F  |   G   |   C  |   R  |L/SPGHE1|
 * |--------+---------+---------+------+------+------+------+------+-------+------+------+--------|
 * |A       |   O     |   E     |   U  |   I  |      |      |   D  |   H   |   T  |   N  |S/SPGHE2|
 * |--------+---------+---------+------+------+------+------+------+-------+------+------+--------|
 * |esc/sft |   Q/gui |    J    |   K  |   X  |      |      |   B  |   M   |   W  |   V  |Z/SPGHE3|
 * `----------------------------------------------------------------------------------------------'
 */
[_SPGHEDOV] = {
  {KC_NO,              KC_NO,KC_NO,         KC_NO,  KC_NO,RAISE,LOWER, KC_NO,   KC_NO, KC_NO,  KC_NO,        KC_NO},
  {KC_TAB,     ALT_T(KC_SPC),CTL_T(KC_ENT), KC_P,   KC_Y, KC_NO,KC_NO, KC_F,    KC_G,   KC_C,   KC_R,   LT(11,KC_L)},
  {KC_A,                KC_O,KC_E,          KC_U,   KC_I, KC_NO,KC_NO, KC_D,    KC_H,   KC_T,   KC_N,   LT(12,KC_S)},
  {SFT_T(KC_ESC),GUI_T(KC_Q),KC_J,          KC_K,   KC_X, KC_NO,KC_NO, KC_B,    KC_M,   KC_W,   KC_V,   LT(13,KC_Z)}
},

/* SPGHE1
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  "   |   <  |  >   |   @  |  {   |      |      |  }   |  1   |  2   |  3   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  -   |  *   |  /   |  =   |  (   |      |      |  )   |  4   |  5   |  6   |  0   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  :   |  |   |  ?   |  !   |  [   |             |  ]   |  7   |  8   |  9   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SPGHE1] = {
  {KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,  KC_NO,KC_NO, KC_NO,   KC_NO,  KC_NO,    KC_NO,KC_NO  },
  {KC_DQT,  KC_LT,   KC_GT,      KC_AT,   KC_LCBR,KC_NO,KC_NO, KC_RCBR, KC_1,    KC_2,    KC_3, _______},
  {KC_MINS, KC_ASTR, KC_SLSH,    KC_EQL,  KC_LPRN,KC_NO,KC_NO, KC_RPRN, KC_4,    KC_5,    KC_6, KC_0   },
  {KC_COLN, KC_PIPE, KC_QUESTION,KC_EXLM, KC_LBRC,KC_NO,KC_NO, KC_RBRC, KC_7,    KC_8,    KC_9, _______}
}, 

/* _SPGHE2
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  '   |   ,  |   .  |  #   |  {   |      |      |  }   |Pg Up | UP   | Pg Dn| Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  -   |  *   |  /   |  =   |  (   |      |      |  )   | LEFT | DOWN |RIGHT |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ;   |  |   |  ?   |  !   |  [   |      |      |  ]   | BSPC | DEL  |insert| End  |
 * `-----------------------------------------------------------------------------------'
 */
[_SPGHE2] = {
  { KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,    KC_NO,   KC_NO,  KC_NO,  KC_NO,  },
  { KC_QUOT, KC_COMM, KC_DOT,     KC_HASH, KC_LCBR, KC_NO, KC_NO, KC_RCBR,  KC_PGUP, KC_UP,  KC_PGDN,KC_HOME,},
  { KC_MINS, KC_ASTR, KC_SLSH,    KC_EQL,  KC_LPRN, KC_NO, KC_NO, KC_RPRN,  KC_LEFT, KC_DOWN,KC_RGHT,_______,},
  { KC_SCLN, KC_PIPE, KC_QUESTION,KC_EXLM, KC_LBRC, KC_NO, KC_NO, KC_RBRC,  KC_BSPC, KC_DEL, KC_INS, KC_END, }
},

/* _SPGHE3
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Caps|  ,   |  .   | \    | MUTE |      |      |   F10|  F1  |  F2  |  F3  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  _   |  +   |  ^   |  $   | Vol+ |      |      |   F11|  F4  |  F5  |  F6  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `   |  ~   |   %  |  &   | Vol- |      |      |   F12|  F7  |  F8  |  F9  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SPGHE3] = {
  {  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,KC_NO,KC_NO,     KC_NO,  KC_NO,   KC_NO,   KC_NO,  KC_NO},
  {KC_CAPS, KC_LT,   KC_GT,   KC_BSLS,KC_MUTE,KC_NO,KC_NO,    KC_F10,  KC_F1,   KC_F2,   KC_F3,_______},
  {KC_UNDS, KC_PLUS, KC_CIRC, KC_DLR, KC_VOLU,KC_NO,KC_NO,    KC_F11,  KC_F4,   KC_F5,   KC_F6,_______},
  {KC_GRV, KC_TILD, KC_PERC, KC_AMPR, KC_VOLD,KC_NO,KC_NO,    KC_F12,  KC_F7,   KC_F8,   KC_F9,_______}
}

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case GHERKIN_DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GHERKIN_DVORAK);
      }
      return false;
      break;
    case SPGHEDOV:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_SPGHEDOV);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case GHELOW:
      if (record->event.pressed) {
        layer_on(_GHELOW);
      } else {
        layer_off(_GHELOW);
      }
      return false;
      break;
    case GHE3:
      if (record->event.pressed) {
        layer_on(_GHE3);
      } else {
        layer_off(_GHE3);
      }
      return false;
      break;
    case SPGHE1:
      if (record->event.pressed) {
        layer_on(_SPGHE1);
      } else {
        layer_off(_SPGHE1);
      }
      return false;
      break;
    case SPGHE2:
      if (record->event.pressed) {
        layer_on(_SPGHE2);
      } else {
        layer_off(_SPGHE2);
      }
      return false;
      break;
    case SPGHE3:
      if (record->event.pressed) {
        layer_on(_SPGHE3);
      } else {
        layer_off(_SPGHE3);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
