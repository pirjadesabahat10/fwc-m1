#include <Arduino.h>

// 7447 BCD input pins
#define PIN_A 2   // LSB
#define PIN_B 3
#define PIN_C 4
#define PIN_D 5   // MSB

// Send BCD to 7447
void displayBCD(int num)
{
  digitalWrite(PIN_A, num & 1);
  digitalWrite(PIN_B, (num >> 1) & 1);
  digitalWrite(PIN_C, (num >> 2) & 1);
  digitalWrite(PIN_D, (num >> 3) & 1);
}

void setup()
{
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
}

void loop()
{
  for (int i = 0; i <= 9; i++)
  {
    displayBCD(i);
    delay(1000);  // 1 second delay
  }
}
