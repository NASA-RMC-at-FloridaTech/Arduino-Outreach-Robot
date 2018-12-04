#include <RMC.h>

Robot Robbie;

void setup() {
  Robbie.Bumper(8);
  Robbie.RightWheel(9,10);
  Robbie.LeftWheel(11,13);
}

void loop() {
  if(Robbie.BumpedIntoSomething())
  {
    Robbie.GoBackwards(100);
    Robbie.TurnRight();
  } else {
    Robbie.Step();
  }
}
