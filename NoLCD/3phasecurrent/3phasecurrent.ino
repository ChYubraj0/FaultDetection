#include "ACmeter.h"
const int sensor_1 = A0;
const int sensor_2 = A1;
const int sensor_3 = A2;
int mv_per_amp = 100;
double sensed_rms;
double amps_rms;
void setup() {
  Serial.begin(9600);
  Serial.print("Current= ");

}

void loop() {
  AcMeter a;
  sensed_rms = (a.getRMS(sensor_1) * 1000)/(mv_per_amp);
  amps_rms=sensed_rms/2;
  Serial.println(amps_rms);
 
  sensed_rms = (a.getRMS(sensor_2) * 1000)/(mv_per_amp);
  amps_rms=sensed_rms/2;
  Serial.print("     ");
  Serial.print(amps_rms);

  ensed_rms = (a.getRMS(sensor_3) * 1000)/(mv_per_amp);
  amps_rms=sensed_rms/2;
  Serial.print("     ");
  Serial.print(amps_rms);
  }
