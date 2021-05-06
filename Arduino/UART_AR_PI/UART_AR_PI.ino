#include <SoftwareSerial.h>

#define RXP 2
#define TXP 3

SoftwareSerial Serial_PI(RXP, TXP);

void setup() {
  Serial.begin(9600);
  Serial.println("===== UART Ard-Pi =====");

  Serial_PI.begin(9600);
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
