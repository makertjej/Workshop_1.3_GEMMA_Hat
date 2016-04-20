// MAKERTJEJ.se
// Workshop 1.3: Digibling Game- Gemma's Hat
//
// Extra program #2:
// Lights up pixels one by one, in order from 0 to 51, to 
// help visualize the position numbering.
//

#include <Adafruit_NeoPixel.h>

#define PIN0 0 //Neopixels are on Gemma pin D0
uint8_t delayint = 400; //Pause between lighting up each pixel

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

  strip.setBrightness(10); // 1/10 brightness to save battery, and your eyes!
  
}

void loop() {
    
    // show R-G-B colors starting at pixel address 0 and incrementing around
    for (uint8_t j=0; j < 52; j++) {
      
      strip.setPixelColor(j, 0xff0000); //set pixel to red
      j++;
      strip.show();
      delay(delayint);
      
      strip.setPixelColor(j, 0x00ff00); //set pixel to green
      j++;
      strip.show();
      delay(delayint);
      
      strip.setPixelColor(j, 0x0000ff); //set pixel to blue
      strip.show();
      delay(delayint);
    
    }
    
    // turn off all pixels and start over
    for (uint8_t j=0; j < 52; j++) {
      strip.setPixelColor(j, 0); //turn pixel off
    }
    strip.show();
    delay(delayint);
    
}
