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

#include "TN40.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

/*
void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}

bool led_update_kb(led_t led_state) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	return led_update_user(led_state);
}
*/


// LEDマトリクスの設定
//
// LEFT
// COLS
// 0  1  2  3  4  5    ROWS
// 05 06 07 08 09 10   0
//      04    01
// 16 15 14 13 12 11   1
// 
// 17 18 19 20 21 22   2
//      03    02
// 28 27 26 25 24 23   3
//
// RIGHT
// COLS
// 0  1  2  3  4  5    ROWS
// 33 34 35 36 37 38   0
//      32    29
// 44 43 42 41 40 39   1
// 
// 45 46 47 48 49 50   2
//      31    30
// 56 55 54 53 52 51   3
//
// x = cols, y = rows (x,y)
#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {{// Key Matrix to LED Index
									{ 4,  5,  6,  7,  8,  9}, //
									{15, 14, 13, 12, 11, 10}, //
									{16, 17, 18, 19, 20, 21}, //
									{27, 26, 25, 24, 23, 22}, //
									{32, 33, 34, 35, 36, 37}, //
									{43, 42, 41, 40, 39, 38}, //
									{44, 45, 46, 47, 48, 49}, //
									{55, 54, 53, 52, 51, 50}},//
								   {// LED Index to Physical Position
									{ 30, 10},{ 30, 53},{ 70, 53},{ 70, 10}, // 0~3
									{ 100,   0},{ 80,  0},{ 60,  0},{ 40,  0},{ 20,  0},{ 0,  0}, // 4~9
									{ 0, 21},{ 20, 21},{ 40, 21},{ 60, 21},{ 80, 21},{ 100,   21}, // 15~10
									{ 100, 43},{ 80, 43},{ 60, 43},{ 40, 43},{ 20, 43},{ 0, 43}, // 16~21
									{   0, 64},{ 20, 64},{ 40, 64},{ 60, 64},{ 80, 64},{  100,  64}, // 27~22
									{ 150, 10},{ 150, 53},{ 190, 53},{ 190, 10}, // 28~31 
									{ 224,  0},{ 200,  0},{ 180,  0},{ 160,  0},{ 140,  0},{ 120,  0}, // 32~37
									{ 120, 21},{ 140, 21},{ 160, 21},{ 180, 21},{ 200, 21},{ 224, 21}, // 43~38
									{ 224, 43},{ 200, 43},{ 180, 43},{ 160, 43},{ 140, 43},{ 120, 43}, // 44~49
									{ 120, 64},{ 140, 64},{ 160, 64},{ 180, 64},{ 200, 64},{ 224, 64}}, // 55~50
								   {// LED Index to Flag
									2, 2, 2, 2, //
									4, 4, 4, 4, 4, 4, //
									4, 4, 4, 4, 4, 4, //
									4, 4, 4, 4, 4, 4, //
									4, 4, 4, 4, 4, 4, //
									2, 2, 2, 2, //
									4, 4, 4, 4, 4, 4, //
									4, 4, 4, 4, 4, 4, //
									4, 4, 4, 4, 4, 4, //
									4, 4, 4, 4, 4, 4 //
									}};
#endif
