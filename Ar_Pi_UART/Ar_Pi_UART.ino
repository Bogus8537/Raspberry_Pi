#include <SoftwareSerial.h>

#define TXP 2
#define RXP 3

SoftwareSerial Serial_PI(TXP, RXP);

void setup() {
  Serial.begin(9600);
  Serial.println("===== UART Ard-Pi =====");

  Serial_F.begin(9600);
}

void loop() {
  
  // Receive the Pi's Data and give it to PC connected with Arduino UNO!
  if(Serial_PI.available())
  {
    Serial.write(Serial_PI.read());
  }

  // Receive the Arduino UNO's Data and give it to Pi!
  if(Serial.available())
  {
    char data = Serial.read();
    Serial.println(data);
    Serial_PI.write(data);
  }

}
