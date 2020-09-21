#include <LiquidCrystal.h>
#include"PF_meter.h"
const byte xor_pin=3;
const byte frequency=50;
PfMeter p;
LiquidCrystal lcd(8,9,10,11,12,13);
void setup() {
 
  lcd.begin(20,4);
  pinMode(xor_pin,INPUT);
  lcd.setCursor(1,0);
  lcd.print("Time Delay:");
  lcd.setCursor(1,1);
  lcd.print("Power Factor:");
  lcd.setCursor(1,2);
  lcd.print("Phase Angle:" );
   
}
void loop() {
   lcd.setCursor(13,0);
   lcd.print(p.getTimeDelay(xor_pin));//
   lcd.setCursor(13,2);
   lcd.print(p.getPhaseAngle(xor_pin,frequency));
   lcd.setCursor(14,1);
   lcd.print(p.getPf(xor_pin,frequency));
   delay(250);
  }
