#include <LiquidCrystal.h>
int incomingVoltagePin=A1;
int adcValue=0;
double voltageReading=0;
float sensorError=2500;
int sensorSensitivity=100;
double rmsCurrentReading=0;
LiquidCrystal lcd(8,9,10,11,12,13);
void setup() {
  lcd.begin(20,4);
  pinMode(incomingVoltagePin,INPUT);
  lcd.setCursor(1,0);
  lcd.print("RMS Current:");
   
}
void loop() {
  int maxpoint=0;
  int temp=0;
  while(maxpoint<analogRead(incomingVoltagePin)){
    if(temp=analogRead(incomingVoltagePin),maxpoint<temp){
        maxpoint=temp;
      }
  }    
  adcValue=float(maxpoint);
  voltageReading=(5000.00*adcValue)/1024.0;
  voltageReading=voltageReading-sensorError;
  rmsCurrentReading=(voltageReading/ sensorSensitivity)*0.707;
  lcd.setCursor(13,0);
  lcd.print(rmsCurrentReading);
  
  delay(50);
}//C:\\Users\\dell\\AppData\\Local\\Temp\\arduino_build_97013/ACcurrentSensorSketch.ino.hex
