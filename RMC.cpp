/*
  RMC.h - Library for NASA Robotic Mining Competition Outreach
  Created by Evangeline Minet for Florida Tech, November 27, 2018.
  Released into the public domain.
  https://github.com/NASA-RMC-at-FloridaTech/Arduino-Outreach-Robot
*/

#include "Arduino.h"
#include <Servo.h>
#include "RMC.h"

Robot::Robot()
{
	Serial.begin(9600);
	Serial.print("Hi there! I'm a Robot!");
	pinMode(LED_BUILTIN, OUTPUT);
}

void Robot::Claw(int pin)
{
	pinMode(pin, OUTPUT);
	pin_claw = pin;
	clawServo.attach(pin);
}

void Robot::RightWheel(int p1, int p2)
{
	pinMode(p1, OUTPUT);
	pinMode(p2, OUTPUT);
	pin_rMotor[0] = p1;
	pin_rMotor[1] = p2;
}

void Robot::LeftWheel(int p1, int p2)
{
	pinMode(p1, OUTPUT);
	pinMode(p2, OUTPUT);
	pin_lMotor[0] = p1;
	pin_lMotor[1] = p2;
}

void Robot::Bumper(int pin)
{
	pinMode(pin, INPUT_PULLUP);
	pin_bumperRight = pin;
	pin_bumperLeft = pin;
}

void Robot::RightBumper(int pin)
{
	pinMode(pin, INPUT_PULLUP);
	pin_bumperRight = pin;
}

void Robot::LeftBumper(int pin)
{
	pinMode(pin, INPUT_PULLUP);
	pin_bumperLeft = pin;
}

void Robot::Buzzer(int pin)
{
	pinMode(pin, OUTPUT);
	pin_buzzer = pin;
}

void Robot::GoStraight(int ms)
{
	digitalWrite(pin_lMotor[1], LOW);
	digitalWrite(pin_rMotor[1], LOW);
	analogWrite(pin_lMotor[0], moveSpeed);
	analogWrite(pin_rMotor[0], moveSpeed);
	delay(ms);
}

void Robot::GoBackwards(int ms)
{
	digitalWrite(pin_lMotor[0], LOW);
	digitalWrite(pin_rMotor[0], LOW);
	analogWrite(pin_lMotor[1], moveSpeed);
	analogWrite(pin_rMotor[1], moveSpeed);
	delay(ms);
}

void Robot::Step()
{
	digitalWrite(pin_lMotor[1], LOW);
	digitalWrite(pin_rMotor[1], LOW);
	analogWrite(pin_lMotor[0], moveSpeed);
	analogWrite(pin_rMotor[0], moveSpeed);
	delay(stepDuration);
}

void Robot::Steps(int steps)
{
	for (int i=0; i <= steps; i++)
	{
		digitalWrite(pin_lMotor[1], LOW);
		digitalWrite(pin_rMotor[1], LOW);
		analogWrite(pin_lMotor[0], moveSpeed);
		analogWrite(pin_rMotor[0], moveSpeed);
		delay(stepDuration);
	}
}

void Robot::TurnLeft(int ms)
{
	digitalWrite(pin_lMotor[1], LOW);
	digitalWrite(pin_rMotor[0], LOW);
	analogWrite(pin_lMotor[0], moveSpeed);
	analogWrite(pin_rMotor[1], moveSpeed);
	delay(ms);
}

void Robot::TurnLeft()
{
	digitalWrite(pin_lMotor[1], LOW);
	digitalWrite(pin_rMotor[0], LOW);
	analogWrite(pin_lMotor[0], moveSpeed);
	analogWrite(pin_rMotor[1], moveSpeed);
	delay(turnDuration);
}

void Robot::TurnRight(int ms)
{
	digitalWrite(pin_lMotor[0], LOW);
	digitalWrite(pin_rMotor[1], LOW);
	analogWrite(pin_lMotor[1], moveSpeed);
	analogWrite(pin_rMotor[0], moveSpeed);
	delay(ms);
}

void Robot::TurnRight()
{
	digitalWrite(pin_lMotor[0], LOW);
	digitalWrite(pin_rMotor[1], LOW);
	analogWrite(pin_lMotor[1], moveSpeed);
	analogWrite(pin_rMotor[0], moveSpeed);
	delay(turnDuration);
}

void Robot::Blink()
{
	digitalWrite(LED_BUILTIN, HIGH);
	delay(100);
	digitalWrite(LED_BUILTIN, LOW);
	delay(100);
}

void Robot::Honk(int ms)
{
	digitalWrite(pin_buzzer, HIGH);
	delay(ms);
	digitalWrite(pin_buzzer, LOW);
	delay(100);
}

void Robot::HonkNote(int freq)
{
	analogWrite(pin_buzzer, freq);
	delay(100);
	digitalWrite(pin_buzzer, LOW);
	delay(100);
}

void Robot::HonkNote(int freq, int ms)
{
	analogWrite(pin_buzzer, freq);
	delay(ms);
	digitalWrite(pin_buzzer, LOW);
	delay(100);
}

void Robot::PlayMelody()
{

}

bool Robot::BumpedIntoSomething()
{
	if(digitalRead(pin_bumperRight) == LOW || digitalRead(pin_bumperLeft) == LOW)
	{
		return false;
	} else {
		return true;
	}
}

bool Robot::BumpedIntoRight()
{
	if(digitalRead(pin_bumperRight) == LOW)
	{
		return false;
	} else {
		return true;
	}
}

bool Robot::BumpedIntoLeft()
{
	if(digitalRead(pin_bumperLeft) == LOW)
	{
		return false;
	} else {
		return true;
	}
}

void Robot::SetSpeed(int spd)
{
	moveSpeed = spd;
}

void Robot::SetStepDuration(int ms)
{
	stepDuration = ms;
}

void Robot::SetTurnDuration(int ms)
{
	turnDuration = ms;
}
