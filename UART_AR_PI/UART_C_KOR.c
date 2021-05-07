#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

char device[] = "/dev/ttyACM0"; 	// 라즈베리파이에 연결된 아두이노 포트 -> device변수에 저장
int fd;					// file descriptor 역할
unsigned long baud = 9600;		// 통신속도 9600 BPS로 설정
unsigned long time = 0;			// time 변수 초기화 (Line 62 ~ 65)

// 44행 & 46행에서 사용할 time = millis()위해 unsigned long형식을 지정
// millis() 함수는 HW의 동작이 시작된 후로 경과된 시간을 1000분의 1초(millisecond)로 표현

// 데이터 범위
// < C / C++ >
// int 	: -2,147,483,648 ~ 2,147,483,647
// long : -2,147,483,648 ~ 2,147,483,647
// unsinged int : 0 ~ 4,294,967,295
// unsigned long : 0 ~ 4,294,967,295

// < Arduino >
// int 	: -32768 ~ 32767
// long : -2,147,483,648 ~ 2,147,483,647
// unsigned int : 0 ~ 65535
// unsigned long : 0 ~ 4,294,967,295

// 아두이노기준
// unsigend long 형식이 최대 범위로 약 50일동안 사용가능!
// 그런 이유로 time 변수의 형식을 unsigned long형식으로 지정

void setup();
void loop();

int main()
{
	setup();
	while(1) loop();
	return 0;
}

void setup()
{
	printf("===== Raspberry Pi started! =====\n\n");
	
	if( (fd = serialOpen(device, baud)) < 0 )                                   		// 연결된 시리얼 장치를 열고, device초기화 & 통신속도를 9600 BPS로 설정
	{
		fprintf(stderr, "Unable to open serial device : %s\n", strerror(errno));  	// strerror : 오류번호를 설명하는 문자열을 가리키는 포인터를 반환
		exit(1);								 								                                  // errno : system_call에서 오류의 원인을 나타내는 상수값을 저장
	}
	if(wiringPiSetup() == -1)                                                   		// GPIO를 wiringPi모드로 설정 (wiringPi 시스템을 초기화 + wiringPi 핀 할당)
	{
		fprintf(stdout, "Unable to start wiringPi : %s\n", strerror(errno));
		exit(1);
	}
}

void loop()
{
	if( millis() - time >= 3000)	      			// millis() : 현재시간을 지정하는 함수
	{							// if (millis() - time >= 3000) -> 3초마다 실행되도록 조건 설정
		time = millis();			        // time변수에 현재 시간을 지정
	}
	
	if( serialDataAvail(fd) )			      	// fd(연결된 시리얼 장치)가 읽을 수 있는 문자로 변환
	{
		char newChar = serialGetchar(fd);		// fd(연결된 시리얼 장치)의 문자를 newchar에 저장 (출력!)
		printf("%c", newChar);
		fflush(stdout);					// 출력 버퍼안에 있는 데이터를 출력장치에 전송하고 출력 버퍼 비우기
	}
}
