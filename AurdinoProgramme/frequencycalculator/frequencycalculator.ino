#include <LiquidCrystal.h>
const byte interrupt_pin=2;
volatile byte state=RISING;
volatile long count;
LiquidCrystal lcd(8,9,10,11,12,13);
void setup() {
  lcd.begin(20,4);
  pinMode(interrupt_pin,INPUT);
  lcd.setCursor(1,0);
  lcd.print("Frequency:");
  attachInterrupt(digitalPinToInterrupt(interrupt_pin),fCalculate,state); 
   
}
void loop() {
   
   delay(200);
   noInterrupts();
   lcd.setCursor(1,1);
   lcd.print(count*5);
   count=0;
   interrupts();
}
void fCalculate(void){
 count=count+1; 
}
