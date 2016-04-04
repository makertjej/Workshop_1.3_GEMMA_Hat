#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN0 0
#define PIN1 1
#define PIN2 2

char off = 0xff0000; //off

char blue = 0x0000ff; //blue
char orange = 0xff9900; //orange
char green = 0x00ff00; //green

//DEBUG VERSION
static char round1[16] = {blue, off, off, off, off, off, off, off, off, off, off, off, off, off, off, orange}; //first circle
static char round2[16] = {orange, off, off, off, off, off, off, off, off, off, off, off, off, off, off, green}; //upper part of second circle
static char round3[12] = {green, off, off, off, off, off, off, off, off, off, off, orange}; //third circle
static char round4[8] = {orange, off, off, off, off, off, off, blue}; //lower part of second circle

void lightup();

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(52, PIN2, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
//{}

void setup() {

  strip.begin();
  strip.show(); // Initialize all pixels to default

  strip.setBrightness(30); // 1/3 brightness to save battery

  lightup();
}

void loop() {

  void lightup();
}


void lightup() {
  
  for (uint8_t i=0; i<16; i++) {
    strip.setPixelColor(15-i, round1[i]);
  }

  for(uint8_t i=0; i<16; i++) {
    strip.setPixelColor(i+20, round2[i]);
  }

  for(uint8_t i=0; i<12; i++) {
    strip.setPixelColor(i+40, round3[i]);
  }

  for(uint8_t i=0; i<4; i++) {
    strip.setPixelColor(i+36, round4[i]);
  }

  for(uint8_t i=0; i<4; i++) {
    strip.setPixelColor(i+16, round4[i+4]);
  }

  strip.show();
}





