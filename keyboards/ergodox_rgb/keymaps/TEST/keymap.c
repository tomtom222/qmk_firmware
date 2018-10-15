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
  KC_BRUP, 
  KC_S1,
  KC_S2,
  KC_S3,
  KC_S4,
  KC_S5,
  KC_S6,
  KC_S7,
  KC_S8,
  KC_S9,
  KC_S10,
  KC_S11,
  KC_S12,
  KC_S13,
  KC_S14,
  KC_S15,
  KC_S16,
  KC_S17,
  KC_S18,
  KC_S19,
  KC_S20,
  KC_S21,
  KC_S22,
  KC_S23,
  KC_S24,
  KC_S25,
  KC_S26,
  KC_S27,
  KC_S28,
  KC_S29,
  KC_S30,
  KC_S31,
  KC_S32,
  KC_S33,
  KC_S34,
  KC_S35,
  KC_S36,
  KC_S37,
  KC_S38
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
Layer [0] TEST   	  |  S1 |  S2 |  S3 |  S4 |  S5 |  S6 |  S7 |
Colour	RED			  +-----+-----+-----+-----+-----+-----+-----+
					  |  S8 |  S9 | S10 | S11 | S12 | S13 | S14 |
+-----+-----+         |     |-----+-----+-----+-----+-----|-----|
| S21 | S22 |         |-----| S15 | S16 | S17 | S18 | S19 | S20 |
+-----+-----+-----+   | S23 |-----+-----+-----+-----+-----|-----|
| S30 |     |     |   |     | S24 | S25 | S26 | S27 | S28 | S29 |
|-----| S32 | S33 |   +-----+-----+-----+-----+-----+-----+-----+
| S31 |     |     |				  | S34 | S35 | S36 | S37 | S38 |
+-----+-----+-----+               +-----+-----+-----+-----+-----+
*/
	[0]KEYMAP(
	
								KC_S1, 		KC_S2, 		KC_S3, 		KC_S4, 		KC_S5, 		KC_S6, 		KC_S7, 
								KC_S8, 		KC_S9, 		KC_S10,		KC_S11, 	KC_S12, 	KC_S13,		KC_S14, 
											KC_S15,		KC_S16, 	KC_S17, 	KC_S18,		KC_S19, 	KC_S20, 
		KC_S21,		KC_S22,		KC_S23, 	KC_S24, 	KC_S25, 	KC_S26, 	KC_S27,		KC_S28, 	KC_S29, 
		KC_S30,     KC_S31, 	KC_S32, 	KC_S33, 	KC_S34, 	KC_S35, 	KC_S36, 	KC_S37, 	KC_S38),
};

void matrix_init_user(void) {
	
	rgblight_setrgb(255, 0, 0);
	
}

void matrix_scan_user(void) {
		 
	uint8_t layer = biton32(layer_state);
	
	if (layer != oldlayer){								//This ensures this code only runs when a layer is changed
		
		switch (layer){
			case QWERTY:								//Sets the colour of QWERTY when that layer is called
			rgblight_setrgb(255, 255, 255);					//This codes calls the colour for the layer
			
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
		rgblight_setrgb(255, 255, 255);				// Sets leds to layer colour where the key press is being called from
      } else {										// this is needed to update the brightness so you can see what you're changing
        
      }
      return false; 								// Skip all further processing of this key
    case KC_BRDW:
      if (record->event.pressed) {
       apa102_brightness--;							// Subtract brightness when key is pressed
	   rgblight_setrgb(255, 255, 255);				// Same as above
      } else {
        
      }
      return false; 								// Skip all further processing of this key
    
	

	case KC_S1: 
		if (record->event.pressed) {
			SEND_STRING("S1"); 
			return false;
		}

	case KC_S2: 
		if (record->event.pressed) {
			SEND_STRING("S2"); 
			return false;
		}
case KC_S3: if (record->event.pressed) {SEND_STRING("S3"); return false;}
case KC_S4: if (record->event.pressed) {SEND_STRING("S4"); return false;}
case KC_S5: if (record->event.pressed) {SEND_STRING("S5"); return false;}
case KC_S6: if (record->event.pressed) {SEND_STRING("S6"); return false;}
case KC_S7: if (record->event.pressed) {SEND_STRING("S7"); return false;}
case KC_S8: if (record->event.pressed) {SEND_STRING("S8"); return false;}
case KC_S9: if (record->event.pressed) {SEND_STRING("S9"); return false;}
case KC_S10: if (record->event.pressed) {SEND_STRING("S10"); return false;}
case KC_S11: if (record->event.pressed) {SEND_STRING("S11"); return false;}
case KC_S12: if (record->event.pressed) {SEND_STRING("S12"); return false;}
case KC_S13: if (record->event.pressed) {SEND_STRING("S13"); return false;}
case KC_S14: if (record->event.pressed) {SEND_STRING("S14"); return false;}
case KC_S15: if (record->event.pressed) {SEND_STRING("S15"); return false;}
case KC_S16: if (record->event.pressed) {SEND_STRING("S16"); return false;}
case KC_S17: if (record->event.pressed) {SEND_STRING("S17"); return false;}
case KC_S18: if (record->event.pressed) {SEND_STRING("S18"); return false;}
case KC_S19: if (record->event.pressed) {SEND_STRING("S19"); return false;}
case KC_S20: if (record->event.pressed) {SEND_STRING("S20"); return false;}
case KC_S21: if (record->event.pressed) {SEND_STRING("S21"); return false;}
case KC_S22: if (record->event.pressed) {SEND_STRING("S22"); return false;}
case KC_S23: if (record->event.pressed) {SEND_STRING("S23"); return false;}
case KC_S24: if (record->event.pressed) {SEND_STRING("S24"); return false;}
case KC_S25: if (record->event.pressed) {SEND_STRING("S25"); return false;}
case KC_S26: if (record->event.pressed) {SEND_STRING("S26"); return false;}
case KC_S27: if (record->event.pressed) {SEND_STRING("S27"); return false;}
case KC_S28: if (record->event.pressed) {SEND_STRING("S28"); return false;}
case KC_S29: if (record->event.pressed) {SEND_STRING("S29"); return false;}
case KC_S30: if (record->event.pressed) {SEND_STRING("S30"); return false;}
case KC_S31: if (record->event.pressed) {SEND_STRING("S31"); return false;}
case KC_S32: if (record->event.pressed) {SEND_STRING("S32"); return false;}
case KC_S33: if (record->event.pressed) {SEND_STRING("S33"); return false;}
case KC_S34: if (record->event.pressed) {SEND_STRING("S34"); return false;}
case KC_S35: if (record->event.pressed) {SEND_STRING("S35"); return false;}
case KC_S36: if (record->event.pressed) {SEND_STRING("S36"); return false;}
case KC_S37: if (record->event.pressed) {SEND_STRING("S37"); return false;}
case KC_S38: if (record->event.pressed) {SEND_STRING("S38"); return false;}


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