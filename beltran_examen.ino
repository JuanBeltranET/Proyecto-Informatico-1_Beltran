#include <Adafruit_LiquidCrystal.h>

#include <Adafruit_NeoPixel.h>


#define FLEX 6
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Adafruit_NeoPixel anillo(NUM_LEDS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  anillo.begin();
  pinMode(FLEX, OUTPUT);
}

void loop()
{
  Serial.print("Flex: ");
  Serial.print();
  
  Serial.print("Angulo: ");
  Serial.print("");

  Serial.print("Led: ");
  Serial.print("");

  Serial.print("Color: ");
  Serial.print();

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Angulo:");
  lcd.print();
  lcd.print(" Color:");
  lcd.print();
}