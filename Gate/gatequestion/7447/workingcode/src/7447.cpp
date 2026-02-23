#include<Arduino.h>
int A = 2;
int B = 3;
int C = 4;
int D = 5;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}

void loop() {

  for(int i = 0; i <= 9; i++) {

    if(i != 1 && i != 4) {   

      digitalWrite(A, i % 2);
      digitalWrite(B, (i / 2) % 2);
      digitalWrite(C, (i / 4) % 2);
      digitalWrite(D, (i / 8) % 2);

      delay(1500);
    }
  }
}

