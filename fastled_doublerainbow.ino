#include <FastLED.h>

FASTLED_USING_NAMESPACE

#define DATA_PIN    5
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    2
#define BRIGHTPOT   0
#define SPEEDPOT    1 

uint8_t brightness = 200;
uint8_t potbright  = 200;
int     del        = 40;
uint8_t gHue       = 0; 

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(brightness);
}

void loop() {  
  potbright = analogRead(BRIGHTPOT) >> 2;
  del = analogRead(SPEEDPOT) >> 2;
  
  if (potbright != brightness) {
    brightness = potbright;
    FastLED.setBrightness(potbright);
  }
    
  leds[0] = CHSV(gHue, 255, 255);
  leds[1] = CHSV(gHue+16, 255, 255);
  
  FastLED.show();  

  delay(del);
  gHue++;
}
