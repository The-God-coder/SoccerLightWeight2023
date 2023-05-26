#include <Arduino.h>
#include <string>
#include <Adafruit_I2CDevice.h>
#include <MCP3XXX.h>
#include <math.h>
#include <trig.h>
#ifndef LINESENSOR
#define LINESENSOR

class LineSensor {
	public:
        LineSensor();
        int *GetValues();
        int *LineAngle();
        int *lineValues;
        int *prevVal;
        int *angleLS;
        double coefficient;
        double *GetCosValues();
        double * GetSinValues();
       
    private:
    MCP3008 adc4;
    MCP3008 adc5;
    MCP3008 adc6;
        double* COS_IR;
        double* SIN_IR;
    
    int lineOrder[24] = {19,18,17,16,15,14,13,11,11,10,9,8,7,6,5,4,3,2,1,24,23,22,21,20};


};
#endif