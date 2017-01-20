#include <FastLED.h>
#include <NeoPixelEffects.h>
#include <Button.h>

#define DATA_PIN 6
#define NUM_LEDS 542
#define AMPS 8000
Button button(52);
uint8_t max_bright = 64;

//CRGBArray<NUM_LEDS> leds;
struct CRGB leds[NUM_LEDS];
unsigned long previousMillis;

//definitions for lionel_warp
uint8_t    numdots =   4;                                     // Number of dots in use.
uint8_t   faderate =   2;                                     // How long should the trails be. Very low value = longer trails.
uint8_t     hueinc =  16;                                     // Incremental change in hue between each dot.
uint8_t    thishue =   0;                                     // Starting hue.
uint8_t     curhue =   0;                                     // The current hue
uint8_t    thissat = 255;                                     // Saturation of the colour.
uint8_t thisbright = 255;                                     // How bright should the LED/display be.
uint8_t   basebeat =   5;                                     // Higher = faster movement.

// definitions for drake drop
uint16_t bpm = 5;
CRGBPalette16 currentPalette;
CRGBPalette16 targetPalette;
uint8_t maxChanges = 24;
TBlendType    currentBlending;

// definitions for ripple
uint8_t colour;                                               // Ripple colour is randomized.
uint32_t center = 0;                                               // Center of the current ripple.
int step = -1;                                                // -1 is the initializing step.
uint8_t myfade = 255;                                         // Starting brightness.
#define maxsteps 16                                           // Case statement wouldn't allow a variable.
uint8_t bgcol = 0;                                            // Background colour rotates.
int thisdelay = 10;                                           // Standard delay value.
// Background colour rotates.


void setup() {
  FastLED.delay(1000);
  pinMode(13, OUTPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  randomSeed(analogRead(0));
//  Serial.begin(9600);
  FastLED.clear();

  FastLED.setBrightness(max_bright);
  set_max_power_in_volts_and_milliamps(5, AMPS);
  button.begin();

}
void loop() {

  for (int i = 0; i < NUM_LEDS; i++) {
    //    int wait = 2 ;
    int randr = random(0, (25 * max_bright));
    int randg = random(0, (25 * max_bright));
    int randb = random(0, (25 * max_bright));
    int randi = random(1, NUM_LEDS);
    setPixel(randi, randr, randg, randb);
    show_at_max_brightness_for_power();

    //    FastLED.delay(100);
    setPixel(i, 0, 0, 0);
    show_at_max_brightness_for_power();

    //    FastLED.delay(wait);


    if (button.pressed()) { //button.isPressed()
      ringring();
      telephone1(24000);
      telephone2(23500);
      telephone3(19000);
      pleasehangup(6000);
      operator_song(34000);
      stevie_wonder_warp(52500);
      Lionel_Ritchie(54000);
      Adele_Hello(70500);
      Blonde_Drop(26000);
      Kim_Possible(34500);
      selfie(77000);
      hotline_bling(21500);
      bling_drop(32500);
      call_me_maybe(75000);


      FastLED.clear();
      show_at_max_brightness_for_power();
    }
  }

}


void setPixel(int Pixel, byte red, byte green, byte blue) {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
#endif
}

void FadeBy(uint32_t time) {
  uint32_t now = millis();
  while ((millis() - now) < time) {
    fadeToBlackBy(leds, NUM_LEDS, 16);
    show_at_max_brightness_for_power();
  }
  FastLED.clear();
}
void colorWipe(uint8_t r, uint8_t g, uint8_t b, uint8_t wait) {
  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    setPixel(i, r, g, b);
    FastLED.show();
    FastLED.delay(wait);
  }
}


void ringring() {
  FastLED.clear();
  int ringing = 0;
  uint32_t now = millis();
  while ((millis() - now) < 7000) {
    uint32_t secondHand = ((millis() - now));
    if (secondHand < 2000) {
      ringing = 1;
    } else if (secondHand < 3800) {
      ringing = 0;
    } else if (secondHand < 5300) {
      ringing = 1;
    } else if (secondHand < 7000) {
      ringing = 0;
    }
    if (ringing > 0) {
      FastLED.showColor(CRGB::White);
      show_at_max_brightness_for_power();
      FastLED.delay(10);
      FastLED.showColor(CRGB::Black);
      show_at_max_brightness_for_power();
      FastLED.delay(10);
    }
  }
}

void telephone1(uint32_t timer) {
  uint32_t now = millis();
  Effect effectType = RAINBOWWAVE;
  int rangeStart = 159;  // old value 161
  int rangeEnd = 378;  // old value 380
  unsigned long delay_ms = 0;
  CRGB grey = 0xFF0000;
  NeoPixelEffects effect = NeoPixelEffects(leds, effectType, rangeStart, rangeEnd, 1, delay_ms, grey, true, true);
  while ((millis() - now) < timer) {
    effect.update();
    show_at_max_brightness_for_power();
  }
}

void telephone2(uint32_t timer) {
  uint32_t now = millis();
  Effect effectType = RAINBOWWAVE;
  int rangeStart = 115;  // old value 115
  int rangeEnd = 422; // old value 426
  unsigned long delay_ms = 0;
  CRGB grey = 0xFF0000;
  NeoPixelEffects effect = NeoPixelEffects(leds, effectType, rangeStart, rangeEnd, 1, delay_ms, grey, true, true);
  while ((millis() - now) < timer) {
    effect.update();
    show_at_max_brightness_for_power();
  }
}

void telephone3(uint32_t timer) {
  uint32_t now = millis();
  Effect effectType = RAINBOWWAVE;
  int rangeStart = 0;
  int rangeEnd = NUM_LEDS - 1;
  unsigned long delay_ms = 0;
  CRGB grey = 0xFF0000;
  NeoPixelEffects effect = NeoPixelEffects(leds, effectType, rangeStart, rangeEnd, 1, delay_ms, grey, true, true);
  while ((millis() - now) < 19000) {
    effect.update();
    show_at_max_brightness_for_power();
  }
}


void pleasehangup(uint32_t timer) {
  uint32_t now = millis();
  Effect effectType = CHASE;
  int rangeStart = 0;
  int rangeEnd = NUM_LEDS - 1;
  unsigned long delay_ms = 50;
  CRGB grey = 0xFF0000;
  NeoPixelEffects effect = NeoPixelEffects(leds, effectType, rangeStart, rangeEnd, 1, delay_ms, grey, true, true);
  while ((millis() - now) < timer) {
    effect.update();
    show_at_max_brightness_for_power();
  }
}


void operator_song(uint32_t timer) {
  uint32_t now = millis();
  Effect effectType = SINEWAVE;
  int rangeStart = 0;
  int rangeEnd = NUM_LEDS - 1;
  unsigned long delay_ms = 50;
  CRGB grey = 0xFF0000;
  NeoPixelEffects effect = NeoPixelEffects(leds, effectType, rangeStart, rangeEnd, 1, delay_ms, grey, true, true);
  while ((millis() - now) < timer) {
    effect.update();
    show_at_max_brightness_for_power();
  }
}

void stevie_wonder_warp(uint32_t timer) {
  uint32_t now = millis();
  while ((millis() - now) < timer) {
    ChangeMe();

    curhue = thishue;                                           // Reset the hue values.
    fadeToBlackBy(leds, NUM_LEDS, faderate);
    for ( int i = 0; i < numdots; i++) {
      leds[beatsin16(basebeat + i + numdots, 0, NUM_LEDS)] += CHSV(curhue, thissat, thisbright); //beat16 is a FastLED 3.1 function
      curhue += hueinc;
    }
    show_at_max_brightness_for_power();
  }
}

void Lionel_Ritchie(uint32_t timer) {
  uint32_t now = millis();
  Effect effectType = SINEWAVE;
  int rangeStart = 0;
  int rangeEnd = NUM_LEDS - 1;
  unsigned long delay_ms = 25;
  CRGB grey = 0xFFF345;
  NeoPixelEffects effect = NeoPixelEffects(leds, effectType, rangeStart, rangeEnd, 1, delay_ms, grey, true, true);
  while ((millis() - now) < timer) {
    effect.update();
    show_at_max_brightness_for_power();
  }
}


void Adele_Hello(uint32_t timer) {
  uint32_t now = millis();
  Effect effectType = RAINBOWWAVE;
  int rangeStart = 0;
  int rangeEnd = NUM_LEDS - 1;
  unsigned long delay_ms = 0;
  CRGB grey = 0xFF0000;
  NeoPixelEffects effect = NeoPixelEffects(leds, effectType, rangeStart, rangeEnd, 1, delay_ms, grey, true, true);
  while ((millis() - now) < timer) {
    effect.update();
    show_at_max_brightness_for_power();
  }
}

void Blonde_Drop(uint32_t timer) {
  uint32_t now = millis();
  while ((millis() - now) < timer) {
    uint8_t starthue = beatsin8(20, 0, 255);
    uint8_t endhue = beatsin8(35, 0, 255);
    if (starthue < endhue) {
      fill_gradient(leds, NUM_LEDS, CHSV(starthue, 255, 255), CHSV(endhue, 255, 255), FORWARD_HUES); // If we don't have this, the colour fill will flip around
    } else {
      fill_gradient(leds, NUM_LEDS, CHSV(starthue, 255, 255), CHSV(endhue, 255, 255), BACKWARD_HUES);
    }
    show_at_max_brightness_for_power();
  }
} // Blonde_Drop()

void Kim_Possible(uint32_t timer) {
  uint32_t now = millis();
  Effect effectType = TRIWAVE;
  int rangeStart = 0;
  int rangeEnd = NUM_LEDS - 1;
  unsigned long delay_ms = 0;
  CRGB color_cyan = CRGB::Cyan;
  NeoPixelEffects effect = NeoPixelEffects(leds, effectType, rangeStart, rangeEnd, 1, 0, color_cyan, true, true);
  while ((millis() - now) < timer) {
    effect.update();
    show_at_max_brightness_for_power();
  }
}

void selfie(uint32_t timer) {
  uint32_t now = millis();
  while ((millis() - now) < timer) {
    uint8_t beatA = beatsin8(5, 140, 255);                        // Starting hue
    uint8_t beatB = beatsin8(15, 25, 20);                        // Delta hue between LED's
    fill_rainbow(leds, NUM_LEDS, beatA, beatB);
    show_at_max_brightness_for_power();

  }
}

void hotline_bling(uint32_t timer) {
  uint32_t now = millis();
  while ((millis() - now) < timer) {
    EVERY_N_MILLISECONDS(10) {                           // FastLED based non-blocking delay to update/display the sequence.
      ripple();
    }
    show_at_max_brightness_for_power();
  }
}

void bling_drop(uint32_t timer) {
  uint32_t now = millis();
  uint16_t bpm = 5;
  while ((millis() - now) < timer) {

    uint8_t beatA = beatsin8(bpm, 0, 255);                        // Starting hue
    FillLEDsFromPaletteColors(beatA);
    show_at_max_brightness_for_power();                         // Power managed display.

    EVERY_N_MILLISECONDS(100) {                                // FastLED based timer to update/display the sequence every 5 seconds.
      nblendPaletteTowardPalette( currentPalette, targetPalette, maxChanges);
    }

    EVERY_N_MILLISECONDS(5000) {                                // FastLED based timer to update/display the sequence every 5 seconds.
      SetupRandomPalette();
    }
    bpm++;
    show_at_max_brightness_for_power();
  }
}

void call_me_maybe(uint32_t timer) {
  static uint8_t startIndex = 0;
  uint32_t now = millis();
  CRGB purple = CHSV( HUE_PURPLE, 255, 255);
  CRGB red  = CHSV( HUE_RED, 255, 255);
  CRGB black  = CRGB::Black;
  currentBlending = LINEARBLEND;
  currentPalette = CRGBPalette16(
                     red,  red, black, black,
                     purple, purple, black, black,
                     red, red, black, black,
                     purple, purple, black, black );

  while ((millis() - now) < timer) {
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);
    show_at_max_brightness_for_power();
  }

}

// Supporting Functions

void ChangeMe() {                                             // A time (rather than loop) based demo sequencer. This gives us full control over the length of each sequence.
  uint8_t secondHand = (millis() / 1000) % 30;                // IMPORTANT!!! Change '30' to a different value to change duration of the loop.
  static uint8_t lastSecond = 99;                             // Static variable, means it's only defined once. This is our 'debounce' variable.
  if (lastSecond != secondHand) {                             // Debounce to make sure we're not repeating an assignment.
    lastSecond = secondHand;
    switch (secondHand) {
      case  0: numdots = 1; basebeat = 20; hueinc = 16; faderate = 2; thishue = 0; break;                  // You can change values here, one at a time , or altogether.
      case 10: numdots = 4; basebeat = 10; hueinc = 16; faderate = 8; thishue = 128; break;
      case 20: numdots = 8; basebeat =  3; hueinc =  0; faderate = 8; thishue = random8(); break;         // Only gets called once, and not continuously for the next several seconds. Therefore, no rainbows.
      case 30: break;
    }
  }
} // ChangeMe()

void ripple() {
  for (uint32_t i = 0; i < NUM_LEDS; i++) leds[i] = CHSV(bgcol++, 255, 15);  // Rotate background colour.

  switch (step) {

    case -1:                                                          // Initialize ripple variables.
      center = random(NUM_LEDS);
      colour = random8();
      step = 0;
      break;

    case 0:
      leds[center] = CHSV(colour, 255, 255);                          // Display the first pixel of the ripple.
      step ++;
      break;

    case maxsteps:                                                    // At the end of the ripples.
      step = -1;
      break;

    default:                                                             // Middle of the ripples.
      leds[(center + step + NUM_LEDS) % NUM_LEDS] += CHSV(colour, 255, myfade / step * 2);   // Simple wrap from Marc Miller
      leds[(center - step + NUM_LEDS) % NUM_LEDS] += CHSV(colour, 255, myfade / step * 2);
      step ++;                                                         // Next step.
      break;
  } // switch step
} // ripple()


void FillLEDsFromPaletteColors(uint8_t colorIndex) {
  uint8_t beatB = beatsin8(20, 10, 20);                       // Delta hue between LED's
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(currentPalette, colorIndex, 255, currentBlending);
    colorIndex += beatB;
  }
} //FillLEDsFromPaletteColors()


void SetupRandomPalette() {
  targetPalette = CRGBPalette16(CHSV(random8(), 255, 32), CHSV(random8(), random8(64) + 192, 255), CHSV(random8(), 255, 32), CHSV(random8(), 255, 255));
} // SetupRandomPalette()

