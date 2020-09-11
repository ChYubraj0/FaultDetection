#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
const int currentSensorChannel=A1;
const int voltageSensorChannel=A0; 
const int CSsensitivity=100;
double currentRMS=0;
const float rConst=11.00;// r4/(r1+r4)
const float tConst =19.17;// vsec*(lprim/lsec)^(1/2)
double voltAtDivider=0;
double voltAtSec=0;
double voltAtPrim=0;
void setup(){
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("VoltageRMS=");
  lcd.setCursor(0,1);
  lcd.print("CurrentRMS=");
}
void loop(){
  lcd.setCursor(12,0);
  voltAtDivider=getVolt(voltageSensorChannel)*0.707;
  voltAtSec=rConst*voltAtDivider;
  voltAtPrim=tConst*voltAtSec;
  lcd.print(voltAtPrim);
  lcd.setCursor(12,1);
  currentRMS=getVolt(currentSensorChannel)*0.707*1000/(2*CSsensitivity);
  lcd.print(currentRMS);
  
}
float getVolt(int channelName){
  float result;
  int readValue;             //C:\\Users\\dell\\AppData\\Local\\Temp\\arduino_build_944092/VoltageCurrentRMSmeasurement.ino.hex
  int maxValue = 0;        
  int minValue = 1024;         
  uint32_t start_time = millis();
  while((millis()-start_time) < 250){
    readValue = analogRead(channelName);
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
