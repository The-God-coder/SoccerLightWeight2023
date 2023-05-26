#include <Arduino.h>
#include <string>
#include <Adafruit_I2CDevice.h>
#include <MCP3XXX.h>
#include <math.h>
#include <trig.h>

class BallSensor {
	public:
        BallSensor();
        int *GetValues();
        double *GetCosValues();
        double * GetSinValues();
    private:
        MCP3008 adc1;
        MCP3008 adc2;
        MCP3008 adc3;
        int sensorOrder[24] = {13,14,15,16,1,2,3,4,5,6,7,8,17,18,19,20,21,22,23,24,9,10,11,12};
        double* COS_IR;
        double* SIN_IR;
         int *irval;

};