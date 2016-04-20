// MAKERTJEJ.se
// Workshop 1.3: Digibling Game- Gemma's Hat
//
// Extra program #3:
// Lights each 'table' in a different color.
//

#include <Adafruit_NeoPixel.h>

#define PIN0 0

uint32_t pink = 0; //pink
uint32_t blue = 1; //blue
uint32_t orange = 2; //orange
uint32_t green = 3; //green

//pink, blue, orange, green
uint32_t myColors[4] = {0xff0099, 0x000066, 0xff6600, 0x00ff00};

static char round1[16]; //first circle
static char round2[16]; //upper part of second circle
static char round3[12]; //third circle
static char round4[8]; //lower part of second circle

// Parameter 1 = number of pixels in strip (12 + 16 + 24 = 52)
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(52, PIN0, NEO_GRB + NEO_KHZ800);


void setup() {
  
  strip.begin();
  strip.show(); // Initialize all pixels to default

  strip.setBrightness(10); // 1/10 brightness to save battery

  lightup();
  
}

void loop() {
  
}


void lightup() {

  //Set one color per table
  for(uint8_t i=0; i<16; i++) {
      round1[i]=blue;
  }
  for(uint8_t i=0; i<16; i++) {
      round2[i]=orange;
  }
  for(uint8_t i=0; i<12; i++) {
      round3[i]=green;
  }
  for(uint8_t i=0; i<8; i++) {
      round4[i]=pink;
  }

  
  
  for (uint8_t i=0; i<16; i++) {
    strip.setPixelColor(15-i, myColors[round1[i]]);
  }

  for(uint8_t i=0; i<16; i++) {
    strip.setPixelColor(i+20, myColors[round2[i]]);
  }

  for(uint8_t i=0; i<12; i++) {
    strip.setPixelColor(i+40, myColors[round3[i]]);
  }

  for(uint8_t i=0; i<4; i++) {
    strip.setPixelColor(i+36, myColors[round4[i]]);
  }

  for(uint8_t i=0; i<4; i++) {
    strip.setPixelColor(i+16, myColors[round4[i+4]]);
  }

  strip.show();
}

