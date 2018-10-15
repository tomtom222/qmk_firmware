#ifndef ERGODOX_RGB_H
#define ERGODOX_RGB_H

#include "quantum.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define KEYMAP( \
	          K02, K03, K04, K05, K06, K07, K08, \
	          K12, K13, K14, K15, K16, K17, K18, \
	               K23, K24, K25, K26, K27, K28, \
	K30, K31, K32, K33, K34, K35, K36, K37, K38, \
	K40, K41, K42, K43, K44, K45, K46, K47, K48  \
) { \
	{ KC_NO, KC_NO, K02,   K03,   K04,   K05,   K06,   K07,   K08 }, \
	{ KC_NO, KC_NO, K12, K13,   K14,   K15,   K16,   K17,   K18 }, \
	{ KC_NO, KC_NO, KC_NO,   K23,   K24,   K25,   K26,   K27,   K28 }, \
	{ K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38 }, \
	{ K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47,   K48 }  \
}

#define SPI_SS                      PB0
#define SPI_SS_PORT                 PORTB
#define SPI_SS_PIN                  PINB
#define SPI_SS_DDR                  DDRB

#define SPI_MOSI                    PB2
#define SPI_MOSI_PORT               PORTB
#define SPI_MOSI_PIN                PINB
#define SPI_MOSI_DDR                DDRB

#define SPI_SCK                     PB1
#define SPI_SCK_PORT                PORTB
#define SPI_SCK_PIN                 PINB
#define SPI_SCK_DDR                 DDRB

//struct cBGR { uint8_t b; uint8_t g; uint8_t r; };
//void apa102_setleds(struct cBGR *ledarray, uint16_t number_of_leds,uint8_t brightness);
extern uint8_t apa102_brightness;

void apa102_setleds(LED_TYPE *ledarray, uint16_t number_of_leds);

//void apa102_setrgball(uint8_t r, uint8_t g, uint8_t b, uint8_t brightness);



#endif

