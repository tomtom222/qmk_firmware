#include "ergodox_rgb.h"
#include <avr/interrupt.h>
#include <avr/io.h>


//struct cBGR led[apa102_lednumber];


/*
void apa102_setrgball(uint8_t r, uint8_t g, uint8_t b, uint8_t brightness){
	uint8_t i;
	for (i=0;i<apa102_lednumber;i++)
		{
			led[i].r=r;led[i].g=g;led[i].b=b;
		}
	apa102_setleds(led,apa102_lednumber,brightness);
	
}
*/	
//uint8_t apa102_brightness = 10

 void SPI_init(void) {
  SPI_SS_DDR |= (1 << SPI_SS);                        // set SS output 
  SPI_SS_PORT |= (1 << SPI_SS);       // start off not selected (high) 
  
  SPI_MOSI_DDR |= (1 << SPI_MOSI);                   // output on MOSI 
  SPI_SCK_DDR |= (1 << SPI_SCK);                      // output on SCK 

 
  SPCR |= (1 << SPR1);                // div 16, safer for breadboards 
  SPCR |= (1 << MSTR);                                  // clockmaster 
  SPCR |= (1 << SPE);                                        // enable 
}

void SPI_write(uint8_t byte) {
  SPDR = byte;                       // SPI starts sending immediately 
  loop_until_bit_is_set(SPSR, SPIF);                // wait until done 
                                // SPDR now contains the received byte 
}

void inline apa102_setleds(LED_TYPE *ledarray, uint16_t leds)
{
  uint16_t i;
  uint8_t *rawarray=(uint8_t*)ledarray;
  SPI_init();
  
  SPI_write(0x00);  // Start Frame 
  SPI_write(0x00);
  SPI_write(0x00);
  SPI_write(0x00);
 
  for (i=0; i<(leds+leds+leds); i+=3)
  {
    SPI_write(0xe0+apa102_brightness);  // Maximum global brightness
    SPI_write(rawarray[i+0]);
    SPI_write(rawarray[i+1]);
    SPI_write(rawarray[i+2]);
  }

  
  
  // End frame: 8+8*(leds >> 4) clock cycles    
  for (i=0; i<leds; i+=16)
  {
    SPI_write(0x00);  // 8 more clock cycles
  }
}
