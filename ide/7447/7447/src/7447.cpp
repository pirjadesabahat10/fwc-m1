#include <Arduino.h>

// Function to send BCD input to 7447
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(5, D); // MSB
  digitalWrite(4, C);
  digitalWrite(3, B);
  digitalWrite(2, A); // LSB
}

void setup()
{
  pinMode(2, OUTPUT);  // A
  pinMode(3, OUTPUT);  // B
  pinMode(4, OUTPUT);  // C
  pinMode(5, OUTPUT);  // D
}

void loop()
{
  // 0 to 9 BCD sequence
  disp_7447(0,0,0,0); // 0
  delay(1000);

  disp_7447(0,0,0,1); // 1
  delay(1000);

  disp_7447(0,0,1,0); // 2
  delay(1000);

  disp_7447(0,0,1,1); // 3
  delay(1000);

  disp_7447(0,1,0,0); // 4
  delay(1000);

  disp_7447(0,1,0,1); // 5
  delay(1000);

  disp_7447(0,1,1,0); // 6
  delay(1000);

  disp_7447(0,1,1,1); // 7
  delay(1000);

  disp_7447(1,0,0,0); // 8
  delay(1000);

  disp_7447(1,0,0,1); // 9
  delay(1000);
}
