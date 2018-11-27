/*
  RMC.h - Library for NASA Robotic Mining Competition Outreach
  Created by Evangeline Minet for Florida Tech, November 27, 2018.
  Released into the public domain.
  https://github.com/NASA-RMC-at-FloridaTech/Arduino-Outreach-Robot
*/

#include "Arduino.h"
#include <Servo.h>
#include <Stepper.h>
#include "RMC.h"

Robot::Robot()
{

}

void Robot::Claw(int pin)
{
	pinMode(pin, OUTPUT);
	_clawPin = pin;
	_servo.attach(pin);
}

void Robot::RightWheel(int p1, int p2, int p3, int p4)
{
	pinMode(p1, OUTPUT);
	pinMode(p2, OUTPUT);
	pinMode(p3, OUTPUT);
	pinMode(p4, OUTPUT);
	_rMotorPins[0] = p1;
	_rMotorPins[1] = p2;
	_rMotorPins[2] = p3;
	_rMotorPins[3] = p4;
	Stepper _rMotor(stepSpeed, p1, p2, p3, p4);
}

void Robot::LeftWheel(int p1, int p2, int p3, int p4)
{
	pinMode(p1, OUTPUT);
	pinMode(p2, OUTPUT);
	pinMode(p3, OUTPUT);
	pinMode(p4, OUTPUT);
	_lMotorPins[0] = p1;
	_lMotorPins[1] = p2;
	_lMotorPins[2] = p3;
	_lMotorPins[3] = p4;
	Stepper _lMotor(stepSpeed, p1, p2, p3, p4);
}

void Robot::Bumper(int pin)
{
	pinMode(pin, INPUT);
	_bumperPin = pin;
}

bool Robot::BumpedIntoSomething()
{
	if(digitalRead(_bumperPin) == LOW)
	{
		return false;
	} else {
		return true;
	}
}

void Robot::TurnRight()
{
	
}

void Robot::TurnLeft()
{
	
}

void Robot::Step(int steps)
{
	
}

void Robot::Step()
{
	
}
