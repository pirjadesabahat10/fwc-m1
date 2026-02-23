#include <Arduino.h>

// 7474 outputs (inputs to Arduino)
int W, X, Y, Z;

// 7447 inputs (outputs from Arduino)
int A, B, C, D;

// Function to send BCD to 7447
void disp_7447(int d, int c, int b, int a)
{
  digitalWrite(2, a); // LSB
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d); // MSB
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  // 7447 output pins
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // 7474 input pins
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);

  // Read 7474 outputs
  W = digitalRead(6); // LSB
  X = digitalRead(7);
  Y = digitalRead(8);
  Z = digitalRead(9); // MSB

  A = !W;
  B = (W && !X && !Z) || (!W && X);
  C = (W && X && !Y) || (!X && Y) || (!W && Y);
  D = (W && X && Y) || (!W && Z);

  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  
  disp_7447(D, C, B, A);
}
