#include<Arduino.h>
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  digitalWrite(a, LOW);   
  digitalWrite(b, LOW);   
  digitalWrite(c, LOW);   
  digitalWrite(d, LOW);   
  digitalWrite(g, LOW);   
  digitalWrite(e, HIGH);  
  digitalWrite(f, HIGH);  
}
