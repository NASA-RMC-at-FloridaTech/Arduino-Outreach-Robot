#include <RMC.h>

Robot ROB;

void setup() {
  ROB.Claw(10);
  ROB.Bumper(9);
  ROB.RightWheel(1,2,3,4);
  ROB.LeftWheel(5,6,7,8);
}

void loop() {
  if(ROB.BumpedIntoSomething())
  {
    ROB.TurnRight();
  } else {
    ROB.Step();
  }
}
