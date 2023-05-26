#include <Arduino.h>
// #include <ballSensor.h>
#include <ballAngle.h>
#include <lineSensor.h>
#include <calibration.h>
#include <compassSensor.h>
#include <lineAvoidance.h>
#include <motor.h>
// #include <calibration.h>

BallAngle ballAngle;
Motor motor;
CompassSensor compassSensor;
LineSensor lineSensor;
LineAvoidance lineAvoidance;
Calibration cal;
int initialOrientation = -1;

void setup()
{
  Serial.begin(9600); 
  pinMode(32, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  initialOrientation = compassSensor.getOrientation();
   
}

void runRobot() {
  ballAngle.Process();
  ballAngle.CalculateRobotAngle(-5);
  lineAvoidance.Process(ballAngle.ballpresent, cal.calVal, lineSensor.GetValues(), lineSensor.LineAngle(),0.7, lineSensor.GetCosValues(), lineSensor.GetSinValues());

  motor.Move(ballAngle.ballpresent, ballAngle.robotAngle, compassSensor.getOrientation(), -5 , lineAvoidance.lineFR, lineAvoidance.lineRR, lineAvoidance.lineRL, lineAvoidance.lineFL,lineAvoidance.projectionState,lineAvoidance.projectionAngle,false);


}

void loop()
{
  
  if(digitalRead(32) == LOW){
    Serial.println("calibration");
    cal.calibrate(lineSensor.GetValues());
  } 
  else if (digitalRead(31) == LOW) {
    runRobot();
    

  } else {

    Serial.println("Switch start to start");
  }
  // Angle.Process();
  
}

