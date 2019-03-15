#include <Wire.h>

int cw = 11; // 2A
int ccw = 12; // 1A

void setup() 
{
  pinMode(cw, OUTPUT);
  pinMode(ccw, OUTPUT);
  Wire.begin(50);
  Wire.onReceive(handle);
  Serial.begin(9600);
}

void loop() 
{
  delay(100);
}

void handle(int giro)
{
  int u = (int)Wire.read();
  switch(u)
  {
    case 0:
      digitalWrite(cw, LOW);
      digitalWrite(ccw, LOW);
      break;
    case 1:
      digitalWrite(cw, HIGH);
      digitalWrite(ccw, LOW);
      break;
    case 2:
      digitalWrite(cw, LOW);
      digitalWrite(ccw, HIGH);
      break;
    default:
      digitalWrite(cw, LOW);
      digitalWrite(ccw, LOW);
      break;
  }
}

