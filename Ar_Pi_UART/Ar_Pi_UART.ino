#include <SoftwareSerial.h>

#define TXP 2
#define RXP 3

SoftwareSerial Serial_F(TXP, RXP);

void setup() {
  Serial.begin(9600);
  Serial.println("===== UART Ard-Pi =====");

  Serial_F.begin(9600);
}

void loop() {
  if(Serial_F.available())
  {
    Serial.write(Serial_F.read());
  }

  if(Serial.available())
  {
    char data = Serial.read();
    Serial.println(data);
    Serial_F.write(data);
  }

}
