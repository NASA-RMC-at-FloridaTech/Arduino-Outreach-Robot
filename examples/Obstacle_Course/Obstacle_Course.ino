#include <RMC.h>

Robot Pathfinder;

void setup() {
  Pathfinder.RightBumper(8);
  Pathfinder.LeftBumper(12);
  Pathfinder.RightWheel(9,10);
  Pathfinder.LeftWheel(11,13);
}

void loop() {
  if(Pathfinder.BumpedIntoRight())
  {
    Pathfinder.GoBackwards(100);
    Pathfinder.TurnLeft();
  } else if(Pathfinder.BumpedIntoLeft())
  {
    Pathfinder.GoBackwards(100);
    Pathfinder.TurnRight();
  } else {
    Pathfinder.Step();
  }
}
