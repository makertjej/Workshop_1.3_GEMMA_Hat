#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

//Pin mappings. Change mappings to match your physical layout
#define PIN0 0 //Signal to neopixel rings
#define PIN1 1 //First reed switch, controls gameplay
#define PIN2 2 //Second reed switch, controls rotation speed

char col1=random(3);
char col2=col1+3;

/*MORE DIFFICULT VERSION
static char round1[16] = {col1, col1, col1, col1, col1, col1, col1, col1, col2, col2, col2, col2, col2, col2, col2, col2}; //first circle
static char round2[16] = {col1, col1, col2, col2, col2, col1, col1, col1, col1, col1, col1, col1, col1, col2, col2, col2}; //upper part of second circle
static char round3[12] = {col1, col1, col1, col1, col1, col1, col1, col2, col2, col2, col2, col2}; //third circle
static char round4[8] =  {col1, col1, col1, col1, col1, col1, col1, col1}; //lower part of second circle*/

/*REAL VERSION
static char round1[16] = {col1, col1, col1, col1, col1, col1, col1, col1, col2, col2, col2, col1, col2, col2, col2, col2}; //first circle
static char round2[16] = {col1, col1, col2, col2, col2, col1, col1, col1, col1, col1, col1, col1, col1, col2, col2, col2}; //upper part of second circle
static char round3[12] = {col1, col1, col1, col1, col1, col1, col1, col2, col1, col1, col1, col2}; //third circle
static char round4[8] = {col1, col1, col1, col1, col1, col1, col1, col1}; //lower part of second circle*/

//DEBUG VERSION
static char round1[16] = {col1, col1, col1, col1, col1, col1, col1, col1, col1, col1, col1, col1, col1, col1, col1, col1}; //first circle
static char round2[16] = {col1, col1, col2, col2, col2, col1, col1, col1, col1, col1, col1, col1, col1, col2, col2, col2}; //upper part of second circle
static char round3[12] = {col1, col1, col1, col1, col1, col1, col1, col2, col1, col1, col1, col1}; //third circle
static char round4[8] = {col1, col1, col1, col1, col1, col1, col1, col1}; //lower part of second circle

uint8_t lightup();
void step1();
void step2();
void initcols();

char tempcol;
static uint8_t level=1;

//dark blue, light turqoise, green, orange, redbrown, pink
uint32_t myColors[] = {0x0000ff, 0x00ffff, 0x00ff00, 0xff9900, 0xff3300, 0xff0099};

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(52, PIN0, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
//{}

void setup() {
  pinMode(PIN1, INPUT);
  pinMode(PIN2, INPUT);
  digitalWrite(PIN1, HIGH);    // Activate internal pullup resistor
  digitalWrite(PIN2, HIGH);    // Activate internal pullup resistor

  strip.begin();
  strip.show(); // Initialize all pixels to default

  strip.setBrightness(30); // 1/3 brightness to save battery

  initcols();
}

void loop() {

    uint8_t s=lightup();
    
    if (s==24) {
      levelup();
    }
    
    else if(digitalRead(PIN1)) {
      step1();
    }
    
    else {
      step2();
    }
}


uint8_t lightup() {

  uint8_t count=0;

  tempcol = round2[0];
  
  for (uint8_t i=0; i<16; i++) {
    strip.setPixelColor(15-i, myColors[round1[i]]);
  }

  for(uint8_t i=0; i<16; i++) {
    strip.setPixelColor(i+20, myColors[round2[i]]);
    if (round2[i]==tempcol) {
      count++;
    }
  }

  for(uint8_t i=0; i<12; i++) {
    strip.setPixelColor(i+40, myColors[round3[i]]);
  }

  for(uint8_t i=0; i<4; i++) {
    strip.setPixelColor(i+36, myColors[round4[i]]);
    if (round4[i]==tempcol) {
      count++;
    }
  }

  for(uint8_t i=0; i<4; i++) {
    strip.setPixelColor(i+16, myColors[round4[i+4]]);
    if (round4[i+4]==tempcol) {
      count++;
    }
  }

  strip.show();
  if(!digitalRead(PIN2)) {
    delay(200);
  }  
  else {
    delay(800);
  } 
  for (uint8_t i=0; i<52; i++) {
    strip.setPixelColor(i, 0);
  }
  strip.show();

  return count;

}
    
void step1() {
// 16, 16, 12, 8

  uint8_t to_round1 = round1[0];
  uint8_t to_round2 = round4[7];
  uint8_t to_round3 = round3[0];
  uint8_t to_round4 = round2[15];

  // switch round1 towars beginning from beginning
  for(uint8_t i=0; i<16; i++) {
    round1[i] = round1[i+1];
  }
  round1[15] = to_round1;

  // switch round2 towards end from end
  for(uint8_t i=15; i>0; i--) {
    round2[i] = round2[i-1];
  }
  round2[0] = to_round2;

  // switch round3 towards beginning from beginning
  for(uint8_t i=0; i<12; i++) {
    round3[i] = round3[i+1];
  }
  round3[11] = to_round3;
  
  // switch round4 towards end from end
  for(uint8_t i=7; i>0; i--) {
    round4[i] = round4[i-1];
  }
  round4[0] = to_round4;

}
void step2() {
// 16, 16, 12, 8

  uint8_t to_round1 = round4[7];
  uint8_t to_round2 = round1[0];
  uint8_t to_round3 = round2[15];
  uint8_t to_round4 = round3[0];

// switch round1 towards beginning from beginning
  for(uint8_t i=0; i<16; i++) {
    round1[i] = round1[i+1];
  }
  round1[15] = to_round1;
  // switch round2 towards end from end
  for(uint8_t i=15; i>0; i--) {
    round2[i] = round2[i-1];
  }
  round2[0] = to_round2;

  // switch round3 towards beginning from beginning
  for(uint8_t i=0; i<12; i++) {
    round3[i] = round3[i+1];
  }
  round3[11] = to_round3;
  
  // switch round4 towards end from end
  for(uint8_t i=7; i>0; i--) {
    round4[i] = round4[i-1];
  }
  round4[0] = to_round4;
  
}

void levelup() {
  for(uint8_t k=0; k< 10; k++) {

    for (uint8_t j=0; j<52; j++) {
      strip.setPixelColor(j, 0xffffff);
    }
    strip.show();
    delay(100);
    for (uint8_t j=0; j<52; j++) {
      strip.setPixelColor(j, 0);
    }
    strip.show();
    delay(100);
  }
    level++;
    initcols();

}
void initcols() {

  char col1;
  char col2;
  
  switch (level) {
    case 1:
      col1=0;
      col2=3;
    break;

    case 2:
      col1=1;
      col2=4;
    break;

    case 3:
      col1=2;
      col2=5;
    break;

    case 4: 
      col1=0;
      col2=5;
      break;
      
    default:
      col1=0;
      col2=5;
    break;
  }

  //INITIALIZE ALL TO COL1
  for(uint8_t i=0; i<16; i++) {
      round1[i]=col1;
  }
  for(uint8_t i=0; i<16; i++) {
      round2[i]=col1;
  }
  for(uint8_t i=0; i<12; i++) {
      round3[i]=col1;
  }
  for(uint8_t i=0; i<8; i++) {
      round4[i]=col1;
  }

  switch (level) {
    case 1: //DEBUG MODE
    
    //FIRST CIRCLE

    //UPPER PART OF SECOND CIRCLE
    round2[2] = col2;
    round2[3] = col2;
    round2[4] = col2;
    round2[13] = col2;
    round2[14] = col2;
    round2[15] = col2;
    
    //THIRD CIRCLE

    //LOWER PART OF SECOND CIRCLE

    break;

    case 2: //NORMAL
    //FIRST CIRCLE
    round1[9] = col2;
    round1[10] = col2;
    round1[11] = col2;
    round1[13] = col2;
    round1[14] = col2;
    round1[15] = col2;

    //UPPER PART OF SECOND CIRCLE
    round2[2] = col2;
    round2[3] = col2;
    round2[4] = col2;
    round2[13] = col2;
    round2[14] = col2;
    round2[15] = col2;

    //THIRD CIRCLE
    round3[7] = col2;
    round3[11] = col2;
  
    //LOWER PART OF SECOND CIRCLE

    break;

    case 3: // MORE DIFFICULT
    //FIRST CIRCLE
    round1[8] = col2;
    round1[9] = col2;
    round1[10] = col2;
    round1[11] = col2;
    round1[12] = col2;
    round1[13] = col2;
    round1[14] = col2;
    round1[15] = col2;

    //UPPER PART OF SECOND CIRCLE
    round2[2] = col2;
    round2[3] = col2;
    round2[4] = col2;
    round2[13] = col2;
    round2[14] = col2;
    round2[15] = col2;

    //THIRD CIRCLE
    round3[7] = col2;
    round3[8] = col2;
    round3[9] = col2;
    round3[10] = col2;
    round3[11] = col2;

    break;

    case 4: // MOST DIFFICULTEST EVER
    //FIRST CIRCLE
    round1[8] = col2;
    round1[9] = col2;
    round1[10] = col2;
    round1[11] = col2;
    round1[12] = col2;
    round1[13] = col2;
    round1[14] = col2;
    round1[15] = col2;

    //UPPER PART OF SECOND CIRCLE
    round2[2] = col2;
    round2[3] = col2;
    round2[4] = col2;
    round2[13] = col2;
    round2[14] = col2;
    round2[15] = col2;

    //THIRD CIRCLE
    round3[7] = col2;
    round3[8] = col2;
    round3[9] = col2;
    round3[10] = col2;
    round3[11] = col2;

    //LOWER PART OF SECOND CIRCLE
    round4[2] = col2;

    break;
    
    default:
        //FIRST CIRCLE

    //UPPER PART OF SECOND CIRCLE
    round2[2] = col2;
    round2[3] = col2;
    round2[4] = col2;
    round2[13] = col2;
    round2[14] = col2;
    round2[15] = col2;
    
    //THIRD CIRCLE

    //LOWER PART OF SECOND CIRCLE
    break;
 }
  

}



