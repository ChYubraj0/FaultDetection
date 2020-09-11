#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
const int analogChannel = A0;
const float rConst=11.00;// r4/(r1+r4)
const float tConst =19.17;// vsec*(lprim/lsec)^(1/2)
int ADCvalue=0;
double voltAtDivider=0;
double voltAtSec=0;
double voltAtPrim=0;
void setup(){
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("VoltageRMS=");
}
void loop(){
  lcd.setCursor(12,0);
  voltAtDivider=getVoltAtR1()*0.707;
  voltAtSec=rConst*voltAtDivider;
  voltAtPrim=tConst*voltAtSec;
  lcd.print(voltAtPrim);
}
float getVoltAtR1(){
  float result;
  int readValue;             //C:\\Users\\dell\\AppData\\Local\\Temp\\arduino_build_282795/VoltageMeasurementSketch.ino.hex
  int maxValue = 0;        
  int minValue = 1024;         
  uint32_t start_time = millis();
  while((millis()-start_time) < 250){
    readValue = analogRead(analogChannel);
    if (readValue > maxValue){
      maxValue = readValue;
    }
    if (readValue < minValue){
      minValue = readValue;
    }
  }
  result = ((maxValue - minValue) * 5.0)/1024.0;
  return result;
  }
