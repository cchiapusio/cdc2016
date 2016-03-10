#include <Adafruit_NeoPixel.h>
#include <Button.h>

#define RING_PIN 5
#define RING_LEDS 12
#define PIN 6
#define NUMLEDS 542
Button button = Button(52, PULLUP);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)
Adafruit_NeoPixel ring1 = Adafruit_NeoPixel(RING_LEDS, RING_PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)

int bright = 1;    //select 1 thru 10

void setup() {
  pinMode(13, OUTPUT);
  ring1.begin();
  strip.begin();
  ring1.show();
  strip.show(); // Initialize all pixels to 'off'
}
void loop() {
  
  for (int i = 0; i < strip.numPixels(); i++) {
    int wait = 2 ;
    int randr = random(0, (25 * bright));
    int randg = random(0, (25 * bright));
    int randb = random(0, (25 * bright));
    int randi = random(1, strip.numPixels());
    int randii = random(1, strip.numPixels());
    strip.setPixelColor(randi, randr, randg, randb);
    ring1.setPixelColor(randi, randr, randg, randb);
    //      strip.setPixelColor(i-1, strip.Color(r,g,(b-150)));
    //      strip.setPixelColor(i-2, strip.Color(r,g,(b-200)));
    //      strip.setPixelColor(i-3, strip.Color(r,g,(b-250))); // add more of these lines to make the trail longer
    strip.show();
    ring1.show();
    delay(100);
    strip.setPixelColor(i, strip.Color(0, 0, 0)); // make sure the i-number is the amount of the trail
    ring1.setPixelColor(i, strip.Color(0, 0, 0)); // make sure the i-number is the amount of the trail
    strip.show();
    ring1.show();
    delay(wait);
    if (button.uniquePress()) { //button.isPressed()
    strip.clear();
    strip.show();
    colorWipe(strip.Color(255, 0, 0), 5); // Red
    //colorWipe(strip.Color(0, 255, 0), 50); // Green
    //colorWipe(strip.Color(0, 0, 255), 50); // Blue
    strip.clear();
    strip.show();
  }
  }

}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

