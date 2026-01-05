/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3_ex2(
KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_NO, KC_NO, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_SENT,
KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
  ),

    [1] = LAYOUT_split_3x6_3_ex2(
KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_BSPC,
KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO,
KC_LSFT,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_NO,
KC_LGUI, _______,  KC_SPC,     KC_0,   KC_DOT, KC_ENT
  ),

    [2] = LAYOUT_split_3x6_3_ex2(
KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC,
KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
  ),

    [3] = LAYOUT_split_3x6_3_ex2(
QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
RM_NEXT, RM_HUED, RM_SATD, RM_VALD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
KC_LGUI, _______,  KC_SPC, KC_ENT, _______, KC_RALT
  )
};


// keymap.c

// define combo names
enum combos {
    COMBO_LCTL,
    COMBO_LGUI,
    COMBO_LALT,
    // more here...

    // nifty trick to auto-specify how many combos you have
    COMBO_LENGTH
};

// nifty trick continued
uint16_t COMBO_LEN = COMBO_LENGTH;

// define keys that make up combos
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM fa_combo[] = {KC_F, KC_A, COMBO_END};
// more here...

// mp combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_LCTL] = COMBO(fd_combo, OS_LCTL),
    [COMBO_LGUI] = COMBO(fs_combo, OS_LGUI),
    [COMBO_LALT] = COMBO(fa_combo, OS_LALT),
    // more here...
};
