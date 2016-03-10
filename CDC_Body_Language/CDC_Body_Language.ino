
/* white

  Originally By: Andrew Tuline

  Lots of plain white lights

*/

#define FASTLED_INTERNAL 1
#include "FastLED.h"                                          // FastLED library. Please use the latest development version.

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

// Fixed definitions cannot change on the fly.
#define LED_DT 6                                             // Data pin to connect to the strip.
#define COLOR_ORDER GRB                                       // It's GRB for WS2812 and BGR for APA102.
#define LED_TYPE NEOPIXEL                                       // Using APA102, WS2812, WS2801. Don't forget to change LEDS.addLeds.
#define NUM_LEDS 542                                       // Number of LED's.
#define AMPS 3000

// Global variables can be changed on the fly.
uint8_t max_bright = 192;                                      // Overall brightness definition. It can be changed on the fly.

struct CRGB leds[NUM_LEDS];                                   // Initialize our LED array.

void setup() {
  delay(1000);                                                // Power-up safety delay.

  LEDS.addLeds<LED_TYPE, LED_DT>(leds, NUM_LEDS);  // Use this for WS2812

  FastLED.setBrightness(max_bright);
  set_max_power_in_volts_and_milliamps(5, AMPS);               // FastLED Power management set at 5V, 500mA.
} // setup()


void loop () {                                                // Several different ways to fill the strand with a solid colour.
  fill_solid(leds, NUM_LEDS, CRGB::White);                    // Now, that's black!
  show_at_max_brightness_for_power();                         // Power managed display
} // loop()
