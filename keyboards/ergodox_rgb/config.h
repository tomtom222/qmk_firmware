/*
Copyright 2017 Thomas Loch

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

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xBEEF
#define DEVICE_VER      0x0001
#define MANUFACTURER    LochEngineering
#define PRODUCT         Ergodox_RGB
#define DESCRIPTION     Ergodox with individual rgb backlighting

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 9

/* key matrix pins */
#define MATRIX_ROW_PINS { F0, F1, F4, F5, F6 }
#define MATRIX_COL_PINS { B6, B7, D0, D1, D2, D3, D4, D5, D7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW



/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

#define QMK_ESC_OUTPUT D7 // usually COL
#define QMK_ESC_INPUT F0 // usually ROW
//#define QMK_LED C6

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define APA102					//Defines the type of led used
 
 


#define RGBLIGHT_ANIMATIONS		//Enables rgbligt animations
#define RGB_DI_PIN F7			// Needed for rgblight to work, empty pin used
#define RGBLED_NUM 38			//Number of leds		
//#define apa102_lednumber 38	//Number of APA102 leds



#endif