/*
  RMC.h - Library for NASA Robotic Mining Competition Outreach
  Created by Evangeline Minet for Florida Tech, November 27, 2018.
  Released into the public domain.
  https://github.com/NASA-RMC-at-FloridaTech/Arduino-Outreach-Robot
*/

#ifndef RMC_h
#define RMC_h

#include "Arduino.h"
#include <Servo.h>
#include <Stepper.h>

class Robot
{
  public:
    Robot();
	void Claw(int pin);
	void RightWheel(int p1, int p2, int p3, int p4);
	void LeftWheel(int p1, int p2, int p3, int p4);
	void Bumper(int pin);
    void Turn(int ang);
	void TurnLeft();
	void TurnRight();
	void Mine();
	void Unload();
	void Step();
	void Step(int _steps);
	void Blink();
	void Honk();
	int Capacity;
	int totalMined;
	bool BumpedIntoSomething();
  private:
    int _load;
	int _clawPin;
	const int stepSpeed = 200;
	Servo _servo;
	int _lMotorPins[4];
	int _rMotorPins[4];
	int _bumperPin;
};

#endif