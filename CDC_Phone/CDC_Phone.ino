#define FASTLED_INTERNAL 1
#include "FastLED.h"
#ifdef __AVR__
#include <avr/power.h>
#endif

#define DATA_PIN   6
#define NUM_LEDS   144
uint8_t fade = 96;
uint16_t randcount = 15;
int toggle = 0;

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
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  FastLED.clear();
  testpattern(startup);

  int number = random(0, 11);
  int startled = buttons[number][0];
  int stopled = buttons[number][1];

  leds(startled, stopled) = CRGB::White;
  FastLED.show();
  FastLED.delay(500);
  leds(startled, stopled) = CRGB::Black;
  FastLED.show();
  FastLED.delay(300);
  if (count > randcount) {
    if (toggle > 1) {
      blinkall(2,700,400);
    } else {
      jenny_fade();
    }
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
  blinkAndFade(9);
}


void testpattern(int start) {
  if (start > 0) {
    return;
  }
  startup++;
  blinkall(5,100,200);
  for (int number = 0; number < 12;) {
    int startled = buttons[number][0];
    int stopled = buttons[number][1];
    if (number == 0 || number == 10 || number == 11) {
      leds(startled, stopled) = CRGB::White;
      FastLED.show();
      FastLED.delay(1000);
      leds(startled, stopled) = CRGB::Black;
      FastLED.show();
      FastLED.delay(200);
    } else {
      for (int i = 0; i < number; i++) {
        leds(startled, stopled) = CRGB::White;
        FastLED.show();
        FastLED.delay(300);
        leds(startled, stopled) = CRGB::Black;
        FastLED.show();
        FastLED.delay(100);
      }
    }
    number++;
  }
}

void blinkAndFade(int currLed) {
  int startled = buttons[currLed][0];
  int stopled = buttons[currLed][1];

  leds(startled, stopled) = CRGB::White;
  FastLED.show();
  FastLED.delay(200);
  fadeToBlackBy(leds, NUM_LEDS, fade);
  FastLED.show();
  toggle++;
}

void blinkall(int count,uint16_t ontime, uint16_t offtime) {
  for (int i = 0; i < count; i++) {
    fill_solid(leds, NUM_LEDS, CRGB::White);
    FastLED.delay(ontime);
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.delay(offtime);
  }
  toggle=0;
}

