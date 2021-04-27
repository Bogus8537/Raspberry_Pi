/*
 * This code was written for controlling 2 LEDS in RaspberryPi.
 * It used the "wiringPi.h" for using GPIO (Line 9).
 *
 * Don't forget to input "-lwiringPi" when you compile and make object code (gcc -o LED_Pi LED_Pi.c -lwiringPi).
*/

#include <stdio.h>
#include <wiringPi.h>

#define LED1 4 // Physical 16 == wPi_4 == BCM_GPIO_23
#define LED2 5 // Physical 18 == wPi_5 == BCM_GPIO_24

int main()
{
	if(wiringPiSetup() == -1)
	{
		return 1;
	}

	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);

	while(1)
	{
		digitalWrite(LED1, 1);
		digitalWrite(LED2, 0);
		printf("LED1 ON!\n");
		printf("LED2 OFF!\n\n");
		delay(1000);

		digitalWrite(LED1, 0);
		digitalWrite(LED2, 1);
		printf("LED1 OFF!\n");
		printf("LED2 ON!\n\n");
		delay(1000);
	}
	return 0;
}

