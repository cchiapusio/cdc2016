#define FASTLED_INTERNAL 1
#include "FastLED.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define DATA_PIN   6
#define NUM_LEDS   144
uint8_t fade = 96;
uint16_t randcount = 50;

CRGBArray<NUM_LEDS> leds;

int buttons[12][2] = {
  {120, 131} ,   // zero
  {0, 11} , // one
  {12, 23} , // two
  {24, 35} , // three
  {60, 71} ,   // four
  {48, 59} ,   // five
  {36, 47} ,  // six
  {72, 83} ,   // seven
  {84, 95} ,   // eight
  {96, 107} ,   // nine
  {132, 144} ,    // star
  {108, 119}     // pound
};


//    one ----- two ----- three ---
//                                |
//  - four ---- five ----- six ----
//  |
//  - seven --- eight --- nine ----
//                                |
//    star ----- zero --- pound ---
//


int startup = 0;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  FastLED.clear();
//  testpattern(startup);
  
  int number = random(0,11);
  int startled = buttons[number][0];
  int stopled = buttons[number][1];

  leds(startled,stopled) = CRGB::White;
  FastLED.show();    
  FastLED.delay(500);
  leds(startled,stopled) = CRGB::Black;
  FastLED.show();
  FastLED.delay(300);
  if (count > randcount) {
    jenny_fade();
    count = 0;
  }
  count++;
}

void jenny_fade() {
  blinkAndFade(8);
  blinkAndFade(6);
  blinkAndFade(7);
  blinkAndFade(5);
  blinkAndFade(3);
  blinkAndFade(0);
  blinkAndFade(9);
}


void testpattern(int start) {
  if (start>0) { return; }
  startup++;
  for(int number = 0; number < 12;) {
    int startled = buttons[number][0];
    int stopled = buttons[number][1];
    if (number==0 || number==10 || number==11) {
       leds(startled,stopled) = CRGB::White;
       FastLED.show();
       FastLED.delay(5000);
       leds(startled,stopled) = CRGB::Black;
       FastLED.show();
       FastLED.delay(500);
    } else {
      for(int i=0; i < number;i++) {
        leds(startled,stopled) = CRGB::White;
        FastLED.show();
        FastLED.delay(500);
        leds(startled,stopled) = CRGB::Black;
        FastLED.show();
        FastLED.delay(200);
      }
    }
    number++;
  }
}

void blinkAndFade(int currLed) {
  int startled = buttons[currLed][0];
  int stopled = buttons[currLed][1];

  leds(startled,stopled) = CRGB::White;
  FastLED.show();    
  FastLED.delay(500);
//  for (int fadeLed = startled; fadeLed < stopled;fadeLed++) {
//    leds(startled, stopled).fadeToBlackBy(64);
  fadeToBlackBy(leds, NUM_LEDS, fade);
    FastLED.show();
//  }
}

