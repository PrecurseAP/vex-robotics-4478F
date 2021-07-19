#include "vex.h"
#include "util.h"
#include "pathing.h"
#include "odometry.h"
#include "ppc.h"
#include "ui.h"
#include "graphing.h"
#include "vector"

using namespace vex;

//REMINDER THAT YOU CANNOT USE ARGUMENTS WITHIN A THREAD

competition Competition;

Point p1 = Point( 0 , 0 );
Point p2 = Point( 5 , 0 );
Point p3 = Point( 5 , 5 );
Point p4 = Point( 0 , 5 );

Path mainPath(p1, p2, p3, p4, 20); 

//this is where you would initialize events

void pre_auton(void) {
  vexcodeInit();

  float x = 0.0;
  float temp = 0;

  thread graphThread = thread(makeGraph);
  
  while(1) {
    temp+=0.1;
    graphVariable = sin(temp);
    wait(200, msec);
  }

  renderScreen(); //draw the field on the screen once.
  Brain.Screen.pressed(touchScreenLogic); //callback so that the drawing and logic code is only executed when the screen is touched. (this saves tons of resources as opposed to a loop)
}

void autonomous(void) {

}

void usercontrol(void) {
  while (1) {
    wait(20, msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
