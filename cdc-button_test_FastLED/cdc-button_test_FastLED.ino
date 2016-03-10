#include <FastLED.h>
#include <NeoPixelEffects.h>
#include <Button.h>

#define DATA_PIN 6
#define NUM_LEDS 542
#define AMPS 8000
Button button = Button(52, PULLUP);
uint8_t max_bright = 64;  

//CRGBArray<NUM_LEDS> leds;
struct CRGB leds[NUM_LEDS];
unsigned long previousMillis; 


void setup() {
  FastLED.delay(1000);
  pinMode(13, OUTPUT);
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  randomSeed(analogRead(0));
  Serial.begin(9600);
  FastLED.clear();

  FastLED.setBrightness(max_bright);
  set_max_power_in_volts_and_milliamps(5, AMPS);
  
  }
void loop() {

  for (int i = 0; i < NUM_LEDS; i++) {
    int randr = random(0, (25 * max_bright));
    int randg = random(0, (25 * max_bright));
    int randb = random(0, (25 * max_bright));
    int randi = random(1, NUM_LEDS);
    setPixel(randi, randr, randg, randb);
    show_at_max_brightness_for_power();

    setPixel(i,0,0,0);
    show_at_max_brightness_for_power();
 
    
    if (button.uniquePress()) { //button.isPressed()
      ringring();
      telephone3();
      
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


void ringring() {
  FastLED.clear();
  int ringing=0;
  uint32_t now = millis();
  while ((millis() - now) < 7000) {
    uint32_t secondHand = ((millis()-now));
    if (secondHand < 2000) {
      ringing=1;
    } else if (secondHand < 3800) {      
      ringing=0;
    } else if (secondHand < 5300) {
      ringing=1;
    } else if (secondHand <7000) {
      ringing=0;
    }
    if (ringing>0) {
      FastLED.showColor(CRGB::White); 
      show_at_max_brightness_for_power(); 
      FastLED.delay(10); 
      FastLED.showColor(CRGB::Black); 
      show_at_max_brightness_for_power(); 
      FastLED.delay(10);
    }   
  }
}



void telephone3() {
  uint32_t now = millis();
  Effect effectType = RAINBOWWAVE;
  int rangeStart = 0;
  int rangeEnd = NUM_LEDS-1;
  unsigned long delay_ms = 0;
  CRGB grey = 0xFF0000;
  NeoPixelEffects effect = NeoPixelEffects(leds, effectType, rangeStart, rangeEnd, 1, delay_ms, grey, true, true);
   while ((millis() - now) < 20500) {
    effect.update();
    show_at_max_brightness_for_power(); 
  }
}

