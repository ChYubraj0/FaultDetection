#include "ACmeter.h"
const int sensor_in = A0;
int mv_per_amp = 100;
double sensed_rms;
double amps_rms;
void setup() {
  Serial.begin(9600);
  Serial.print("Current= ");

}

void loop() {
  AcMeter a;
  sensed_rms = (a.getRMS(sensor_in) * 1000)/(mv_per_amp);
  amps_rms=sensed_rms/2;
  Serial.println(amps_rms);
  Serial.print(" Amp");
}
