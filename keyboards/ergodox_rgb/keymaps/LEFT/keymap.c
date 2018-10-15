//LEFT
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
+-----+-----+-----+-----+-----+-----+-----+		Left
| k08 | k07 | k06 | k05 | k04 | k03 | k02 |		Layer [X]
+-----+-----+-----+-----+-----+-----+-----+		Colour GREEN
| k18 | k17 | k16 | k15 | k14 | k13 | k12 |
+-----+-----+-----+-----+-----+-----|     |			+-----+-----+
| k28 | k27 | k26 | k25 | k24 | k23 |-----|			| k31 | k30 |
+-----+-----+-----+-----+-----+-----|     |	  +-----+-----+-----+
| k38 | k37 | k36 | k35 | k34 | k33 | k32 |   |     |     | k40 |
+-----+-----+-----+-----+-----+-----+-----+   | k43 | k42 |-----|
| k48 | k47 | k46 | k45 | k44 |				  |   	|     | k41 |			
+-----+-----+-----+-----+-----+				  +-----+-----+-----+

	[X]KEYMAP(
	//Keymap is reversed to match matrix
								KC_k02, 	KC_k03, 	KC_k04, 	KC_k05, 	KC_k06, 	KC_k07, 	KC_k08, 
								KC_k12, 	KC_k13, 	KC_k14, 	KC_k15, 	KC_k16, 	KC_k17, 	KC_k18,
											KC_k23, 	KC_k24, 	KC_k25, 	KC_k26, 	KC_k27, 	KC_k28,
		KC_k30, 	KC_k31, 	KC_k32, 	KC_k33, 	KC_k34, 	KC_k35, 	KC_k36, 	KC_k37, 	KC_k38,
		KC_k40, 	KC_k41, 	KC_k42, 	KC_k43, 	KC_k44, 	KC_k45, 	KC_k46, 	KC_k47, 	KC_k48),
*/



/*
+-----+-----+-----+-----+-----+-----+-----+		Left
|GRAVE|  1  |  2  |  3  |  4  |  5  | DEL |		Layer [0] QWERTY
+-----+-----+-----+-----+-----+-----+-----+		Colour RED
| TAB |  Q  |  W  |  E  |  R  |  T  | {   |
+-----+-----+-----+-----+-----+-----|  [  |			+-----+-----+
| CAP |  A  |  S  |  D  |  F  |  G  |-----|			|     |     |
+-----+-----+-----+-----+-----+-----| }   |	  +-----+-----+-----+
|SHIFT|  Z  |  X  |  C  |  V  |  B  |  ]  |   | Back|     |     |
+-----+-----+-----+-----+-----+-----+-----+   | SPC | SPC |-----|
| CTRL| WIN | ALT |     | MUTE|				  |   	|     | [1] |			
+-----+-----+-----+-----+-----+				  +-----+-----+-----+
*/
	[0]KEYMAP(
	//Keymap is reversed to match matrix
								KC_DEL, 	KC_5, 		KC_4, 		KC_3, 		KC_2, 		KC_1, 		KC_GESC, 
								KC_LBRC, 	KC_T, 		KC_R, 		KC_E, 		KC_W, 		KC_Q, 		KC_TAB, 
											KC_G, 		KC_F, 		KC_D, 		KC_S, 		KC_A, 		KC_CAPS, 				
		KC_MYCM, 	KC_CALC,	KC_RBRC, 	KC_B, 		KC_V, 		KC_C, 		KC_X, 		KC_Z, 		KC_LSFT, 
		KC_NO, 		TO(1), 		KC_BSPC, 	KC_SPC, 	KC_MUTE, 	KC_NO, 		KC_LALT, 	KC_LGUI, 	KC_LCTL),
/*
+-----+-----+-----+-----+-----+-----+-----+		Left
| ESC | F1  | F2  | F3  | F4  | F5  | F6  |		Layer [1] FUNCTION
+-----+-----+-----+-----+-----+-----+-----+		Colour BLUE
|     |  7  |  8  |  9  |  /  |     |     |
+-----+-----+-----+-----+-----+-----|     |			+-----+-----+
|     |  4  |  5  |  6  |  *  |     |-----|			|     |     |
+-----+-----+-----+-----+-----+-----|     |	  +-----+-----+-----+
|     |  1  |  2  |  3  |  -  |     |     |   | Back|     | [0] |
+-----+-----+-----+-----+-----+-----+-----+   | SPC | SPC |-----|
|     |     |  0  |  .  |  +  |				  |   	|     | [2] |			
+-----+-----+-----+-----+-----+				  +-----+-----+-----+
*/
	[1]KEYMAP(
	//Keymap is reversed to match matrix
								KC_F6, 		KC_F5, 		KC_F4, 		KC_F3, 		KC_F2, 		KC_F1, 		KC_ESC, 
								KC_NO, 		KC_NO, 		KC_SLSH, 	KC_9, 		KC_8, 		KC_7, 		KC_NO,  
											KC_NO, 		KC_ASTR, 	KC_6, 		KC_5, 		KC_4, 		KC_NO,  
		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_MINUS, 	KC_3, 		KC_2, 		KC_1, 		KC_NO, 
		TO(0), 		TO(2), 		KC_BSPC, 	KC_SPC, 	KC_PLUS, 	KC_DOT, 	KC_0, 		KC_NO, 		KC_NO),
/*
+-----+-----+-----+-----+-----+-----+-----+		Left
|GRAVE|  1  |  2  |  3  |  4  |  5  | DEL |		Layer [2] Colemak MOD DH
+-----+-----+-----+-----+-----+-----+-----+		Colour GREEN
| TAB |  Q  |  W  |  F  |  P  |  G  | {   |
+-----+-----+-----+-----+-----+-----|  [  |			+-----+-----+
| CAP |  A  |  R  |  S  |  T  |  D  |-----|			|     |     |
+-----+-----+-----+-----+-----+-----| }   |	  +-----+-----+-----+
|SHIFT|  Z  |  X  |  C  |  V  |  B  |  ]  |   | Back|     | [1] |
+-----+-----+-----+-----+-----+-----+-----+   | SPC | SPC |-----|
| CTRL| WIN | ALT | k45 | MUTE|				  |   	|     | [3] |			
+-----+-----+-----+-----+-----+				  +-----+-----+-----+
*/
	[2]KEYMAP(
	//Keymap is reversed to match matrix
								KC_DEL, 	KC_5, 		KC_4, 		KC_3, 		KC_2, 		KC_1, 		KC_GRV, 
								KC_LBRC, 	KC_G, 		KC_P, 		KC_F, 		KC_W, 		KC_Q, 		KC_TAB, 
											KC_D, 		KC_T, 		KC_S, 		KC_R, 		KC_A, 		KC_CAPS, 
		KC_NO, 		KC_NO, 		KC_RBRC, 	KC_B, 		KC_V, 		KC_C, 		KC_X, 		KC_Z, 		KC_LSFT, 
		TO(1), 		TO(3), 		KC_BSPC, 	KC_SPC, 	KC_MUTE, 	KC_NO, 		KC_LALT, 	KC_LGUI, 	KC_LCTL),

		
/*
+-----+-----+-----+-----+-----+-----+-----+		Left
|     |     |     |     |(RGB)|     |     |		Layer [3] MEDIA
+-----+-----+-----+-----+-----+-----+-----+		Colour ORANGE
|     | Stop| Play|     |     | TOG | BRT |
+-----+-----+-----+-----+-----+-----|  UP |			+-----+-----+
|     | RWD | FWD |     |SOLID| MOD |-----|			|     |     |
+-----+-----+-----+-----+-----+-----| BRT |	  +-----+-----+-----+
|     | Soft| Loud| Mute|HUE- |HUE+ | DWN |   |     |     | [2] |
+-----+-----+-----+-----+-----+-----+-----+   |     |     |-----|
|     |     |     |     |     |				  |   	|     | [0] |			
+-----+-----+-----+-----+-----+				  +-----+-----+-----+
*/
	[3]KEYMAP(
	//Keymap is reversed to match matrix
								KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 
								KC_BRUP,	RGB_TOG, 	KC_NO, 		KC_NO, 		KC_MPLY, 	KC_MSTP, 	KC_NO, 
											RGB_MOD,	RGB_M_P, 	KC_NO, 		KC_MNXT, 	KC_MPRV, 	KC_NO, 
		KC_NO, 		KC_NO, 		KC_BRDW,	RGB_HUD, 	RGB_HUI, 	KC_MUTE, 	KC_VOLU, 	KC_VOLD, 	KC_NO, 
		TO(2), 		TO(0), 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO),

};
	
void matrix_init_user(void) {
	
	rgblight_setrgb(255, 0, 0);							//Sets the colour to the first layer as the keyboard loads up
	
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

uint8_t layer = biton32(layer_state);

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		switch (layer){
			case QWERTY:
			rgblight_setrgb_at(255, 255, 255, 11);
			break;
			case COLEMAK:
			rgblight_setrgb_at(255, 255, 255, 11);
			break;
			default: 
			break;
		}
		
		
	} else {
		switch (layer){
			case QWERTY:
			rgblight_setrgb(255, 0, 0);
			break;
			case COLEMAK:
			rgblight_setrgb(0, 255, 0);
			break;
			default: 
			break;
		}
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