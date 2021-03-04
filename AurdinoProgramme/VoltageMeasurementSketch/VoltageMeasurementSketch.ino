#include<LiquidCrystal.h>
#include"ACmeter.h"
LiquidCrystal lcd(8,9,10,11,12,13);
const int analog_channel = A0;
const float r_const=2.00;// r1/(r1+r2)
const float t_const =19.17;// vsec*(lprim/lsec)^(1/2)
double volt_at_divider=0;
double volt_at_sec=0;
double volt_at_prim=0;
double measured_value;
double error;
void setup(){
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("VoltageRMS=");
}

void loop(){
  AcMeter a;
  lcd.setCursor(12,0);
  volt_at_divider=(a.getRMS(analog_channel));
  volt_at_sec=r_const*volt_at_divider;
  measured_value=t_const*volt_at_sec ;
  volt_at_prim=measured_value;
  lcd.print(volt_at_prim);
}
