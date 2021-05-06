# This code was written for UART Communication between Raspberry Pi and Arduino UNO.
# This program can input any characters through terminal in Pi.
# It transfers to Arduino and can check it in Arduino Serial Monitor.

import serial

# Change the port "/dev/ttyACM0" to your Port and Baud.
pi = serial.Serial("/dev/ttyACM0", 9600)

while True:
    if pi.readable():
        s = input()
        pi.write(s.encode())
