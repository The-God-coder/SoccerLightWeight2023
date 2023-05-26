#include <ballSensor.h>
// #include <trig.h>
#include <cmath>

class BallAngle {

    public: 
        BallAngle();
        void Process();
        double ballAngle;
        double highestValue;
        double robotAngle;
        void Intake();
        bool capture = false;
        int kickState = 1;
        void kickButton();
        bool ballpresent = false;
        int realhighestVal;
          int xbeeHighVal;
        void CalculateRobotAngle(int goalAngle);
        const int numSensors = 24;   // Number of IR sensors in the array
        const int sensorThreshold = 500;   // Minimum IR intensity value for a valid reading
        const int maxSensorValue = 800;   // Maximum IR intensity value for a valid reading
        const double sensorSpacing = 15.0;   // Spacing between IR sensors, in degrees
        double sensorX[24];
        double sensorY[24];
        double addedX;
        double addedY;


    private:
        BallSensor ballSensor;
        int *sensorValues;
        int multiplier;
         
        
};