#include  <Adafruit_NeoPixel.h>

#define NUMLEDS 24
#define DATAPIN 6

Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUMLEDS, DATAPIN, NEO_GRB + NEO_KHZ800);


int newColor [NUMLEDS] = {16, 200, 24, 232, 32, 200, 56, 232, 200, 216,
                          0, 232, 24, 32, 136, 16, 240, 128, 48, 224,
                          0, 48, 40, 160
                         };
int currentColor [NUMLEDS] = {144, 16, 152, 16, 240, 96, 168, 8, 72, 88,
                              152, 48, 248, 0, 72, 232, 104, 8, 240, 80,
                              240, 0, 176, 48
                             };



void setup() {
  Serial.begin(9600);
  leds.begin();
  leds.setBrightness(64);
  leds.show();
}

void loop() {
  for (byte i = 0; i < NUMLEDS; i++) {
    if (currentColor[i] < newColor[i]) {
      currentColor[i] += 8;
    }
    leds.setPixelColor(i, currentColor[i], 0, 0);
    leds.show();
    //delay(1);
    if (currentColor[i] > newColor[i]) {
      currentColor[i] -= 8;
    }
    leds.setPixelColor(i, currentColor[i], 0, 0);
    leds.show();
    //delay(1);
   /* Serial.print(i);
    Serial.print("\t");
    Serial.print(currentColor[i]);
    Serial.print("\t");*/
    if (currentColor[i] == newColor[i]) {
      newColor[i] =(random(32) * 8);
    }
   // Serial.println(newColor[i]);
  }
}
