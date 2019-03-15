#include <SoftwareSerial.h>

int rx = 10;
int tx = 11;
int leds[] = {6, 7, 8};
int cuantos = 3;
int c = 0;

SoftwareSerial xbee_serial(rx,tx);

int baud_rate = 9600;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baud_rate);
  xbee_serial.begin(baud_rate);
  pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(xbee_serial.available()>0)
  {
    Serial.write(xbee_serial.read());
    c++;
  }
  while(Serial.available()>0)
  {
    xbee_serial.write(Serial.read());
    c++;
  }
  if(c==3)
    c=0;
  if(c!=0)
  {
    digitalWrite(leds[c-1], HIGH);
    digitalWrite(leds[c%cuantos], LOW);
    digitalWrite(leds[(c+1)%cuantos], LOW);
  }
}

