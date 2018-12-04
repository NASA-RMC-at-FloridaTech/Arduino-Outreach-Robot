#include <RMC.h>

Robot ROB;

void setup() {
  ROB.RightBumper(8);
  ROB.LeftBumper(12);
  ROB.RightWheel(9,10);
  ROB.LeftWheel(11,13);
}

void loop() {
  if(ROB.BumpedIntoRight() && ROB.BumpedIntoLeft())
  {
    ROB.GoStraight(10);
  } else if(ROB.BumpedIntoRight())
  {
    ROB.TurnRight(10);
  } else if(ROB.BumpedIntoLeft())
  {
    ROB.TurnLeft(10);
  }
}
