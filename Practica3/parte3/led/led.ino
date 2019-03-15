#include <SoftwareSerial.h>

int rx = 10;
int tx = 11;
int led = 13;

SoftwareSerial xbee_serial(rx,tx);

int baud_rate = 9600;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baud_rate);
  xbee_serial.begin(baud_rate);
  while(xbee_serial.available()<=0)
  {
    
  }
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(xbee_serial.available()>0)
  {
    Serial.write(xbee_serial.read());
    digitalWrite(led, HIGH);
  }
  while(Serial.available()>0)
  {
    xbee_serial.write(Serial.read());
    digitalWrite(led, LOW);
  }
}
