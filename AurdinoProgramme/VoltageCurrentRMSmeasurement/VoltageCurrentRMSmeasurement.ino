#include<LiquidCrystal.h>
#include"ACmeter.h"
LiquidCrystal lcd(8,9,10,11,12,13);
const int CS_channel=A1;
const int VS_channel=A0; 
const int CS_sensitivity=100.0;
double sensed_rms;
double amps_rms;
const float r_const=2.00;// r4/(r1+r4)
const float t_const =19.17;// vsec*(lprim/lsec)^(1/2)
double volt_at_divider;
double volt_at_sec;
double volt_at_prim;
float error;
void setup(){
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("VoltageRMS=");
  lcd.setCursor(0,1);
  lcd.print("CurrentRMS=");
}
void loop(){
  AcMeter a;
  AcMeter b;
  lcd.setCursor(12,0);
  volt_at_divider=a.getRMS(VS_channel);
  volt_at_sec=r_const*volt_at_divider;
  volt_at_prim=t_const*volt_at_sec;
  lcd.print(volt_at_prim);
  lcd.setCursor(12,1);
  sensed_rms=b.getRMS(CS_channel)*1000.0/CS_sensitivity;
  amps_rms=sensed_rms/2.0;
  lcd.print(amps_rms);  
  
}
