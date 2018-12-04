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

class Robot
{
  public:
    Robot();
		void Claw(int pin);
		void RightWheel(int p1, int p2);
		void LeftWheel(int p1, int p2);
		void Bumper(int pin);
		void LeftBumper(int pin);
		void RightBumper(int pin);
		void Buzzer(int pin);
		void GoStraight (int ms);
		void GoBackwards (int ms);
		void Step();
		void Steps(int steps);
		void TurnLeft(int ms);
		void TurnRight(int ms);
		void TurnLeft();
		void TurnRight();
		void Blink();
		void Honk(int ms);
		void HonkNote(int freq);
		void HonkNote(int freq, int ms);
		void PlayMelody();
		bool BumpedIntoSomething();
		bool BumpedIntoRight();
		bool BumpedIntoLeft();
		void SetSpeed(int spd);
		void SetStepDuration(int ms);
		void SetTurnDuration(int ms);
  private:
		int moveSpeed = 1023;
		int stepDuration = 100;
		int turnDuration = 250;
		int pin_claw;
		int pin_lMotor[2];
		int pin_rMotor[2];
		int pin_bumperRight;
		int pin_bumperLeft;
		int pin_buzzer;
		Servo clawServo;
};

#endif