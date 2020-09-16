#include<LiquidCrystal.h>
#include "ACmeter.h"
LiquidCrystal LCD(8,9,10,11,12,13);
const int sensor_in = A0;
int mv_per_amp = 100;
double sensed_rms;
double amps_rms;
void setup(){

  LCD.begin(20,4);
  LCD.setCursor(0,0);
  LCD.print("current=");
}
void loop(){
  AcMeter a;
  sensed_rms = (a.getRMS(sensor_in) * 1000)/(mv_per_amp);
  amps_rms=sensed_rms/2;
  LCD.setCursor(9,0);
  LCD.print(amps_rms);
  LCD.print("Amp");
  
}
