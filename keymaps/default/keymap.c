/* Copyright 2019 Takuma Niihara
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

#include QMK_KEYBOARD_H
#include "keymap_jp.h"

enum layers {
	_QWERTY = 0,	   // default
	_JP_QWERTY,		   // JP OS default
	_JP_SHIFT_QWERTY,  // JP Shift
	_LOWER,			   // number
	_JP_LOWER,		   // JP number
	_RAISE,			   // symbol
	_JP_RAISE,		   // JP symbol
	_VIM,			   // vim
	_OS,			   // OS keys
	_OS_SHIFT,		   // OS+Shift
	_ADJUST,		   // adjust
	_JP_ADJUST,		   // JP adjust
};

enum keycodes {
	LOWER = SAFE_RANGE,
	RAISE,
	JPLOWER,
	JPRAISE,
	QWERTY,
	JPQWERTY,
	ALT_TAB,
	ALT_TAB_SFT,
	RGBRST,
};

static bool is_alt_tab_active = false; //ALT+TAB常態かどうかのフラグ
static bool lower_pressed = false; //LOWERが押されたかのフラグ
static bool raise_pressed = false; //RAISEが押されたかのフラグ

#define JPSFT MO(_JP_SHIFT_QWERTY)
#define VIM MO(_VIM)
#define OS MO(_OS)
#define OS_SFT MO(_OS_SHIFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | VIM  | WIN  | ALT  | OS   |v/En  |Space |Shift |^/Ja  |      |      |      |Enter |
 * `-----------------------------------------------------------------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS, \
  KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
  VIM    ,       KC_LGUI, KC_LALT, OS,      LOWER,   KC_SPC,  KC_LSFT, RAISE,   XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT \
),

//JP配列のキーの場合
[_JP_QWERTY] = LAYOUT( \
  KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CTL_T(KC_ESC),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    JP_SCLN, JP_MINS, \
  JPSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_QUOT, \
  VIM,          KC_LGUI, KC_LALT, OS,      JPLOWER, KC_SPC,  JPSFT,  JPRAISE, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT  \
),
[_JP_SHIFT_QWERTY] = LAYOUT( \
  _______, S(KC_Q),    S(KC_W),    S(KC_E),    S(KC_R),    S(KC_T),    S(KC_Y),   S(KC_U),    S(KC_I),    S(KC_O),   S(KC_P),    _______, \
  _______, S(KC_A),    S(KC_S),    S(KC_D),    S(KC_F),    S(KC_G),    S(KC_H),   S(KC_J),    S(KC_K),    S(KC_L),   JP_COLN,    JP_UNDS, \
  _______, S(KC_Z),    S(KC_X),    S(KC_C),    S(KC_V),    S(KC_B),    S(KC_N),   S(KC_M),    S(KC_COMM), S(KC_DOT), S(KC_SLSH), JP_DQT, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

// ==============================================================================================

/* LOWER 数字
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | x    |   4  |   5  |   6  |   +  |  *   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | x    |   1  |   2  |   3  |   /  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |<<v>> |      |   0  |      |   0  |   .  |Enter |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, _______, _______, _______, _______, _______,  XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PPLS, KC_PAST, \
  _______, _______, _______, _______, _______, _______,  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PSLS, KC_PMNS, \
  _______, _______, _______, _______, _______, _______,  KC_0,    _______, KC_0,    KC_DOT,  KC_PENT, KC_ENT \
),
[_JP_LOWER] = LAYOUT( \
  KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, _______, _______, _______, _______, _______,  XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PPLS, KC_PAST, \
  _______, _______, _______, _______, _______, _______,  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PSLS, KC_PMNS, \
  _______, _______, _______, _______, _______, _______,  KC_0,    _______, KC_0,    KC_DOT,  KC_PENT, KC_ENT \
),

// ==============================================================================================

/* RAISE 記号
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |      |      |  _   |  -   |      |      |  =   |  +   |  {   |  }   |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  `   |  !   |  @   |  #   |  $   |   %  |  ^   |  &   |  *   |  (   |  )   |  \   | 
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |  [   |  ]   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |<<^>> |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_TILD, _______, _______, KC_UNDS, KC_MINS, _______, _______, KC_EQL,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
   KC_GRV, KC_EXLM, KC_AT  , KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
[_JP_RAISE] = LAYOUT( \
  JP_TILD, _______, _______, JP_UNDS, JP_MINS, _______, _______, JP_EQL,  JP_PLUS, JP_LCBR, JP_RCBR, JP_PIPE,\
  JP_GRV,  JP_EXLM, JP_AT  , JP_HASH, JP_DLR,  JP_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, JP_LBRC, JP_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

// ==============================================================================================

/* VIM
 * ,-----------------------------------------------------------------------------------.
 * |      |      |Word  | END  |      |      | Yank | PGUP | INST | HOME |Paste | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      | PGDN |      |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |BWord |      |      |      |      |Find/ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | <<V>>|      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_VIM] = LAYOUT( \
  _______, _______, C(KC_RGHT), KC_END,  _______, _______,    C(KC_C), KC_PGUP, KC_INS,  KC_HOME, C(KC_V), KC_DEL, \
  _______, _______, _______,    KC_PGDN, _______, _______,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, _______, _______,    _______, _______, C(KC_LEFT), _______, _______, _______, _______, C(KC_F), _______ , \
  _______, _______, _______,    _______, _______, _______,    _______, _______, _______, _______, _______, _______ \
),

// ==============================================================================================

/* WINDOWS OS 
 * ,-----------------------------------------------------------------------------------.
 * |      |ALT+F4|      |FBrows|      |      |      |      |      |      |CLIPB |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Enter | Cut  | Copy |Paste |      |      | ^TAB |S^TAB |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |<<SF>>|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |<<OS>>|      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 * WINDOWS OS SHIFT 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |<<SF>>|      |      |ALT+F4|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |<<OS>>|      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/**
 * awesome wmやxmonadみたいなようなことをやりたい．ひとまずwindowsだけ
 * 実装したいもの
 * - ウィンドウの選択 CTRL+TAB
 * - ウィンドウの移動 Alt+Space -> M , Win + arrow
 * - 仮想デスクトップの移動 windows + ctrl + arrow
 * - ウィンドウの削除 Alt + F4
 * - ファイルブラウザの起動 Win + e
 * - クリップボード Win + v
 * - TODO: 左手のデリートキーやエンターキーがほしい
 */

[_OS] = LAYOUT( \
  G(KC_TAB),_______, _______, G(KC_E), _______, _______, _______,       _______,    _______,  _______,       G(KC_V), _______, \
  _______,  KC_ENT , C(KC_X), C(KC_C), C(KC_V), _______, G(C(KC_LEFT)), ALT_TAB_SFT,ALT_TAB,  G(C(KC_RIGHT)),_______, _______, \
  OS_SFT ,  _______, _______, _______, _______, _______, _______,       _______,    _______,  _______,       _______, _______, \
  _______,  _______, _______, _______, _______, _______, _______,       _______,    _______,  _______,       _______, _______ \
),

[_OS_SHIFT] = LAYOUT( \
  _______, _______, _______, _______,  _______, _______, _______,    _______,    _______,  _______,     _______, _______, \
  _______, _______, _______, _______,  _______, _______, G(KC_LEFT), G(KC_DOWN), G(KC_UP), G(KC_RIGHT), _______, _______, \
  _______, _______, _______, A(KC_F4), _______, _______, _______,    _______,    _______,  _______,     _______, _______, \
  _______, _______, _______, _______,  _______, _______, _______,    _______,    _______,  _______,     _______, _______ \
),
// ==============================================================================================

/* ADJUST
 * ,-----------------------------------------------------------------------------------.
 * |PrtSc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | LED  | LED  | LED  | LED  |      |RGBRST|x     |  F4  |  F5  |  F6  |x     | F12  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LED  | LED  | LED  | LED  |      |      |x     |  F1  |  F2  |  F3  |x     |x     |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LED  | LED  | LED  | LED  |<<v>> |ENGOS |JPNOS |<<^>> |      | MREC |MRECS |MPLAY |     
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT( \
  KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, RGBRST,  XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_F12, \
  RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, _______, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX , \
  _______, _______, _______, _______, _______, _______, JPQWERTY, _______, _______,DM_REC1, DM_RSTP, DM_PLY1 \
),
[_JP_ADJUST] = LAYOUT( \
  KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, RGBRST,  XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_F12, \
  RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, _______, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX , \
  _______, _______, _______, _______, _______, QWERTY,  _______, _______, _______, DM_REC1, DM_RSTP, DM_PLY1 \
)
};

//コピペ用
/*
[_HOGE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX \
),
*/

// LOWER, RAISEの両方がONのときに3つ目のレイヤ(ADJUST)をONにする

uint32_t layer_state_set_user(uint32_t state)
{
	state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
	state = update_tri_layer_state(state, _JP_LOWER, _JP_RAISE, _JP_ADJUST);
	return state;
}

//新しいユーザマクロいずれこっちに移行したい
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode) {
		// レイヤー切り替えのマクロ（長押でレイヤー切り替え．タップで言語入力切り替え）
		case LOWER:	 //タップで英語入力(F13とALTと~のタップ)，ホルドでLOWER
			if (record->event.pressed) {
				lower_pressed = true;
				layer_on(_LOWER);
			}else{
				layer_off(_LOWER);
				if (lower_pressed) {
					SEND_STRING(SS_TAP(X_F13));
					SEND_STRING(SS_DOWN(X_LALT));
					SEND_STRING(SS_DOWN(X_GRV));
					SEND_STRING(SS_UP(X_LALT));
					SEND_STRING(SS_UP(X_GRV));
				}
				lower_pressed = false;
			}
			return false;
			break;
		case RAISE:	 // タップで日本語入力(F13のタップ)，ホルドでRAISE
			if (record->event.pressed) {
				raise_pressed = true;
				layer_on(_RAISE);
			} else {
				layer_off(_RAISE);
				if (raise_pressed) {
					SEND_STRING(SS_TAP(X_F13));
				}
				raise_pressed = false;
			}
			return false;
			break;
		case JPLOWER:	 //日本語キーOSでのタップで英語入力(無変換キーとLANG2)，ホルドでLOWER
			if (record->event.pressed) {
				lower_pressed = true;
				layer_on(_JP_LOWER);
			}else{
				layer_off(_JP_LOWER);
				if (lower_pressed) {
					/* 無変換キーはこちらだが，自分の環境では英語配列の方法が良かったので，，，
					SEND_STRING(SS_TAP(X_MHEN));
					SEND_STRING(SS_TAP(X_LANG2));
					*/
					SEND_STRING(SS_TAP(X_F13));
					SEND_STRING(SS_DOWN(X_LALT));
					SEND_STRING(SS_DOWN(X_GRV));
					SEND_STRING(SS_UP(X_LALT));
					SEND_STRING(SS_UP(X_GRV));
				}
				lower_pressed = false;
			}
			return false;
			break;
		case JPRAISE:	 // 日本語キーOSでのタップで日本語入力(変換キーとLANG1)，ホルドでRAISE
			if (record->event.pressed) {
				raise_pressed = true;
				layer_on(_JP_RAISE);
			} else {
				layer_off(_JP_RAISE);
				if (raise_pressed) {
					/* 変換キーはこちらだが，自分の環境では英語配列の方法が良かったので，，，
					SEND_STRING(SS_TAP(X_HENK));
					SEND_STRING(SS_TAP(X_LANG1));
					*/
					SEND_STRING(SS_TAP(X_F13));
				}
				raise_pressed = false;
			}
			return false;
			break;
		// デフォルトのキー配列の設定マクロ
		case QWERTY: //英語配列OSモード
			if (record->event.pressed) {
				set_single_persistent_default_layer(_QWERTY);
				SEND_STRING("ENGLISH OS MODE");
				raise_pressed = false;
				lower_pressed = false;
			}
			return false;
			break;
		case JPQWERTY: //日本語配列OSモード
			if (record->event.pressed) {
				set_single_persistent_default_layer(_JP_QWERTY);
				SEND_STRING("JAPANESE OS MODE");
				raise_pressed = false;
				lower_pressed = false;
			}
			return false;
			break;
		// デフォルトキー配列マクロの設定ここまで
		// ここからALT_TABのマクロ
		case ALT_TAB:
			if (is_alt_tab_active) {
				if (record->event.pressed) {
					SEND_STRING(SS_TAP(X_TAB));
				}
			} else {
				is_alt_tab_active = true;
				if (record->event.pressed) {
					SEND_STRING(SS_DOWN(X_LALT));
					SEND_STRING(SS_TAP(X_TAB));
				}
			}
			return false;
			break;
		case ALT_TAB_SFT:
			if (is_alt_tab_active) {
				if (record->event.pressed) {
					SEND_STRING(SS_DOWN(X_LSFT));
					SEND_STRING(SS_DOWN(X_TAB));
					SEND_STRING(SS_UP(X_TAB));
					SEND_STRING(SS_UP(X_LSFT));
				}
			} else {
				is_alt_tab_active = true;
				if (record->event.pressed) {
					SEND_STRING(SS_DOWN(X_LALT));
					SEND_STRING(SS_DOWN(X_LSFT));
					SEND_STRING(SS_DOWN(X_TAB));
					SEND_STRING(SS_UP(X_TAB));
					SEND_STRING(SS_UP(X_LSFT));
				}
			}
			return false;
			break;
		case OS:
			if (is_alt_tab_active) {
				if (record->event.pressed) {
				} else {
					is_alt_tab_active = false;
					SEND_STRING(SS_UP(X_LALT));
				}
			}
			break;
			// ここまでALT_TABのマクロ
		case RGBRST: { //RGBマトリクスのEEPROMの設定の初期化
			if (record->event.pressed){
#ifdef RGB_MATRIX_ENABLE
				eeconfig_update_rgb_matrix_default();
#endif
			}
		}
			return false;
		default:
			if (record->event.pressed) {
				// LOWER,RAISEのフラグのリセット
				lower_pressed = false;
				raise_pressed = false;
			}
			break;
	}
	return true;
}

//ここからOLED関連の設定
#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void render_status(void)
{
	// レイヤー情報の表示
	oled_write_P(PSTR("Layer: "), false);
	switch (get_highest_layer(layer_state)) {
		case _QWERTY:
		case _JP_QWERTY:
		case _JP_SHIFT_QWERTY:
			oled_write_P(PSTR("QWERTY\n"), false);
			break;
		case _LOWER:
		case _JP_LOWER:
			oled_write_P(PSTR("LOWER\n"), false);
			break;
		case _RAISE:
		case _JP_RAISE:
			oled_write_P(PSTR("RAISE\n"), false);
			break;
		case _VIM:
			oled_write_P(PSTR("VIM\n"), false);
			break;
		case _OS:
		case _OS_SHIFT:
			oled_write_P(PSTR("OS\n"), false);
			break;
		case _ADJUST:
		case _JP_ADJUST:
			oled_write_P(PSTR("ADJUST\n"), false);
			break;
		default:
			// 未知のレイヤーの場合
			oled_write_ln_P(PSTR("Undefined"), false);
	}
	oled_write_P(PSTR("\nThis is TN40 keyboard\n"), false);
}

void oled_task_user(void)
{
	if (is_keyboard_master()) {
		render_status();  // OLED: 現在のレイヤー情報の表示
	} else {
		render_logo();// OLED:ロゴの表示
	}
}
#endif
