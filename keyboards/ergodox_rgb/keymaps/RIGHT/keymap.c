//RIGHT
#include "ergodox_rgb.h"

//Layer definitions
#define QWERTY 0
#define FUNCTION 1
#define COLEMAK 2
#define MEDIAMOUSE 3

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {10, 5, 2};
uint8_t oldlayer = 255;			//0-255 var for layer switching 
uint8_t apa102_brightness = 1;	//Initial brightness variable


enum my_keycodes {				//Custom keycodes
  KC_BRDW = SAFE_RANGE,			//Keys for brightness
  KC_BRUP 
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BLANK KEYMAP (copy to add another layer, KEEP this as a reference to the key matrix)
Right                 +-----+-----+-----+-----+-----+-----+-----+
Layer [X]			  | k02 | k03 | k04 | k05 | k06 | k07 | k08 |
Colour GREEN		  +-----+-----+-----+-----+-----+-----+-----+
					  | k12 | k13 | k14 | k15 | k16 | k17 | k18 |
+-----+-----+         |     |-----+-----+-----+-----+-----|-----|
| k30 | k31 |         |-----| k23 | k24 | k25 | k26 | k27 | k28 |
+-----+-----+-----+   |     |-----+-----+-----+-----+-----|-----|
| k40 |     |     |   | k32 | k33 | k34 | k35 | k36 | k37 | k38 |
|-----| k42 | k43 |   +-----+-----+-----+-----+-----+-----+-----+
| k41 |     |     |				  | k44 | k45 | k46 | k47 | k48 |
+-----+-----+-----+               +-----+-----+-----+-----+-----+

	[X]KEYMAP(
	
								KC_k02, 	KC_k03, 	KC_k04, 	KC_k05, 	KC_k06, 	KC_k07, 	KC_k08, 
								KC_k12, 	KC_k13, 	KC_k14, 	KC_k15, 	KC_k16, 	KC_k17, 	KC_k18,
											KC_k23, 	KC_k24, 	KC_k25, 	KC_k26, 	KC_k27, 	KC_k28,
		KC_k30, 	KC_k31, 	KC_k32, 	KC_k33, 	KC_k34, 	KC_k35, 	KC_k36, 	KC_k37, 	KC_k38,
		KC_k40, 	KC_k41, 	KC_k42, 	KC_k43, 	KC_k44, 	KC_k45, 	KC_k46, 	KC_k47, 	KC_k48),
*/



/*
Right                 +-----+-----+-----+-----+-----+-----+-----+
Layer [0] QWERTY	  |     |  6  |  7  |  8  |  9  |  0  |  \  |
Colour	RED			  +-----+-----+-----+-----+-----+-----+-----+
					  | _   |  Y  |  U  |  I  |  O  |  P  |     |
+-----+-----+         |  -  |-----+-----+-----+-----+-----|-----|
|     |     |         |-----|  H  |  J  |  K  |  L  |  ;  |  '  |
+-----+-----+-----+   | +   |-----+-----+-----+-----+-----|-----|
|     |     |     |   |  =  |  N  |  M  |  ,  |  .  |  /  |SHIFT|
|-----| ENT | ESC |   +-----+-----+-----+-----+-----+-----+-----+
| [1] |     |     |				  |  ←  |  ↑  |  ↓  |  →  |     |
+-----+-----+-----+               +-----+-----+-----+-----+-----+
*/
	[0]KEYMAP(
	
								KC_NO, 		KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_BSLS, 
								KC_MINS, 	KC_Y, 		KC_U, 		KC_I, 		KC_O, 		KC_P, 		KC_NO, 
											KC_H, 		KC_J, 		KC_K, 		KC_L, 		KC_SCLN,	KC_QUOT, 
		KC_NO, 		KC_NO,		KC_EQL, 	KC_N, 		KC_M, 		KC_COMM, 	KC_DOT,		KC_SLSH, 	KC_RSFT, 
		KC_NO, 		TO(1), 		KC_ESC, 	KC_ENT, 	KC_LEFT, 	KC_UP, 		KC_DOWN, 	KC_RIGHT, 	KC_NO),
/*
Right                 +-----+-----+-----+-----+-----+-----+-----+
Layer [1] FUNCTION    | F7  | F8  | F9  | F10 | F11 | F12 | Prt |
Colour BLUE			  +-----+-----+-----+-----+-----+-----+-----+
					  |     | INS | Home| P UP|     |     |     |
+-----+-----+         |     |-----+-----+-----+-----+-----|-----|
|     |     |         |-----| DEL | END |P DWN|  ↑  |     |     |
+-----+-----+-----+   |     |-----+-----+-----+-----+-----|-----|
| [0] |     |     |   |     |     |     |  ←  |  ↓  |  →  |     |
|-----| ENT | ESC |   +-----+-----+-----+-----+-----+-----+-----+
| [2] |     |     |				  |     |     |     |     |     |
+-----+-----+-----+               +-----+-----+-----+-----+-----+
*/
	[1]KEYMAP(
	
								KC_F7, 		KC_F8, 		KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_PSCR, 
								KC_NO, 		KC_INS, 	KC_HOME,	KC_PGUP, 	KC_NO, 		KC_NO, 		KC_NO, 
											KC_DEL, 	KC_END, 	KC_PGDN,	KC_UP, 		KC_NO, 		KC_NO, 
		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_LEFT, 	KC_DOWN,	KC_RIGHT, 	KC_NO, 
		TO(0), 		TO(2), 		KC_ENT, 	KC_ESC, 	KC_NO,	 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO),
/*
Right                 +-----+-----+-----+-----+-----+-----+-----+
Layer[2]Colemak MOD DH|     |  6  |  7  |  8  |  9  |  0  |  \  | 
Colour	GREEN		  +-----+-----+-----+-----+-----+-----+-----+
					  | _   |  J  |  L  |  U  |  Y  |  ;  |     |
+-----+-----+         |  -  |-----+-----+-----+-----+-----|-----|
|     |     |         |-----|  H  |  N  |  E  |  I  |  O  |  '  |
+-----+-----+-----+   | +   |-----+-----+-----+-----+-----|-----|
| [1] |     |     |   |  =  |  K  |  M  |  ,  |  .  |  /  |SHIFT|
|-----| ENT | ESC |   +-----+-----+-----+-----+-----+-----+-----+
| [3] |     |     |				  |  ←  |  ↑  |  ↓  |  →  |     |
+-----+-----+-----+               +-----+-----+-----+-----+-----+
*/
	[2]KEYMAP(
	
								KC_NO, 		KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_BSLS, 
								KC_MINS, 	KC_J, 		KC_L, 		KC_U, 		KC_Y, 		KC_SCLN,	KC_NO, 
											KC_H, 		KC_N, 		KC_E, 		KC_I, 		KC_O,		KC_QUOT, 
		KC_NO, 		KC_NO, 		KC_EQL, 	KC_K, 		KC_M, 		KC_COMM, 	KC_DOT,		KC_SLSH, 	KC_RSFT,
		TO(1), 		TO(3), 		KC_ESC, 	KC_ENT, 	KC_LEFT, 	KC_UP, 		KC_DOWN, 	KC_RIGHT, 	KC_NO),


/*
Right                 +-----+-----+-----+-----+-----+-----+-----+
Layer [3] MOUSE		  |     |(RGB)|     |     |     |     |     |
Colour	ORANGE		  +-----+-----+-----+-----+-----+-----+-----+
					  | BRT | TOG |     |     |  ↑  |     |     |
+-----+-----+         | UP  |-----+-----+-----+-----+-----|-----|
|     |     |         |-----| MOD |SOLID|  ←  |  ↓  |  →  |     |
+-----+-----+-----+   | BRT |-----+-----+-----+-----+-----|-----|
| [2] | Left|Right|   | DWN |HUE+ |HUE- |     |     |     |     |
|-----|Mouse|Mouse|   +-----+-----+-----+-----+-----+-----+-----+
| [0] |Click|Click|				  |     |     |     |     |     |
+-----+-----+-----+               +-----+-----+-----+-----+-----+
*/
	[3]KEYMAP(
	
								KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 
								KC_BRUP, 	RGB_TOG, 	KC_NO, 		KC_NO, 		KC_MS_UP, 	KC_NO, 		KC_NO, 
											RGB_MOD,	RGB_M_P,	KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,KC_NO, 
		KC_NO, 		KC_NO, 		KC_BRDW, 	RGB_HUD, 	RGB_HUI, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 
		TO(2), 		TO(0), 		KC_MS_BTN1, KC_MS_BTN2, KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO),

};

void matrix_init_user(void) {
	
	rgblight_setrgb(255, 0, 0);
	
}

void matrix_scan_user(void) {
		 
	uint8_t layer = biton32(layer_state);
	
	if (layer != oldlayer){								//This ensures this code only runs when a layer is changed
		
		switch (layer){
			case QWERTY:								//Sets the colour of QWERTY when that layer is called
			rgblight_setrgb(255, 0, 0);					//This codes calls the colour for the layer
			
			break;
			case FUNCTION:								//Sets the colour of FUNCTION when that layer is called
			rgblight_setrgb(0, 0, 255);
			
			break;
			case COLEMAK:								//Sets the colour of COLEMAK when that layer is called
			rgblight_setrgb(0, 255, 0);
		    
			break;
			case MEDIAMOUSE:							//Sets the colour of MEDIA when that layer is called
			rgblight_setrgb(255, 100, 0);
			
			break;
			default:									//Sets the default colour, this might show upon booting
			rgblight_setrgb(255, 255, 255);
			
			break;
		}
		oldlayer = layer;
				
	}
	
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 
 switch (keycode) {
    case KC_BRUP:
      if (record->event.pressed) {
        apa102_brightness++;						// Add brightness when key is pressed
		rgblight_setrgb(255, 100, 0);				// Sets leds to layer colour where the key press is being called from
      } else {										// this is needed to update the brightness so you can see what you're changing
        
      }
      return false; 								// Skip all further processing of this key
    case KC_BRDW:
      if (record->event.pressed) {
       apa102_brightness--;							// Subtract brightness when key is pressed
	   rgblight_setrgb(255, 100, 0);				// Same as above
      } else {
        
      }
      return false; 								// Skip all further processing of this key
    
    default:
      return true; 									// Process all other keycodes normally
  }
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}