#include <LiquidCrystal.h>
int incomingVoltagePin=A0;
int adcValue=0;
double voltageReading=0;
float sensorError=2500;
int sensorSensitivity=100;
double currentReading=0;
LiquidCrystal lcd(8,9,10,11,12,13);
void setup() {
  lcd.begin(20,4);
  pinMode(incomingVoltagePin,INPUT);
  lcd.setCursor(1,0);
  lcd.print("Current=");
}
void loop() {
  adcValue=analogRead(incomingVoltagePin);
  voltageReading=(5000.00*adcValue)/1024.0;
  voltageReading=voltageReading-sensorError;
  currentReading=voltageReading/ sensorSensitivity;
  lcd.setCursor(9,0);
  lcd.print(currentReading);
  lcd.print("A");
  delay(0.5);
}
//C:\\Users\\dell\\AppData\\Local\\Temp\\arduino_build_554204/DCcurrentSensorProgramme.ino.elf
