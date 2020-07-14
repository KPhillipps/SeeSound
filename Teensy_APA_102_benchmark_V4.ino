// perforance of FastLED.show() verses FastLED[1].showLeds()
//    FastLED.show()          1728 LEDs  11 FPS on Huzzah ESP32       158 on Teensy 4.0
//    FastLED[].showLeds();   1728 LEDs  56 FPS on Huzzzah esp32      158 on Teensy 4.0


#include "FastLED.h"

#define NUM_LEDS 133
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];
CRGB leds5[NUM_LEDS];
CRGB leds6[NUM_LEDS];

uint8_t gBrightness = 255;

int loops = 0;
unsigned long begining = millis();


void setup() {
  Serial.begin(115200);
  FastLED.addLeds<APA102, 13, 12, BGR>(leds1, NUM_LEDS);
  FastLED.addLeds<APA102, 18, 19, BGR>(leds2, NUM_LEDS);
  FastLED.addLeds<APA102, 17, 21, BGR>(leds3, NUM_LEDS);
  FastLED.addLeds<APA102, 32, 15, BGR>(leds4, NUM_LEDS);
  FastLED.addLeds<APA102, 33, 18, BGR>(leds5, NUM_LEDS);
  FastLED.addLeds<APA102, 32, 16, BGR>(leds6, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
}

void loop() {
    
    loops++;
    if ((millis() - begining ) >= 1000 ) {
      Serial.printf("FPS: %d\n", loops);
      begining = millis();
      loops = 0;
    }
    leds1[random(1,64)].setRGB(random(0,128), random(0,128),random(0,128));  // turn some random leds on
    leds2[random(1,64)].setRGB(random(0,128), random(0,128),random(0,128));  // turn some random leds on
    leds3[random(1,64)].setRGB(random(0,128), random(0,128),random(0,128));  // turn some random leds on
    leds4[random(1,64)].setRGB(random(0,128), random(0,128),random(0,128));  // turn some random leds on
    leds5[random(1,64)].setRGB(random(0,128), random(0,128),random(0,128));  // turn some random leds on
    leds6[random(1,64)].setRGB(random(0,128), random(0,128),random(0,128));  // turn some random leds on
     //FastLED.show();
     FastLED[0].showLeds();
     FastLED[1].showLeds();
     FastLED[2].showLeds();
     FastLED[3].showLeds();
     FastLED[4].showLeds();
     FastLED[5].showLeds();
for ( int i = 0; i <= NUM_LEDS/2; i++){  // set half of the leds off at random
    leds1[random(1,64)] = CRGB::Black;
  }
}
