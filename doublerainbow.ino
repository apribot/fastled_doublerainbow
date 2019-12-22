#include <FastLED.h>

FASTLED_USING_NAMESPACE

#define DATA_PIN    5
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    2
CRGB leds[NUM_LEDS];

#define BRIGHTNESS  255

void setup() {
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

uint8_t gHue = 0; 

void loop()
{  
  leds[0] = CHSV(gHue, 255, 255);
  leds[1] = CHSV(gHue+16, 255, 255);
  
  FastLED.show();  

  delay(40);
  gHue++;
}
