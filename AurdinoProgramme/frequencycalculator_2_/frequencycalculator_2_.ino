#include <LiquidCrystal.h>
const byte interrupt_pin=2;
volatile byte state=RISING;
volatile uint32_t pulse_time;
volatile uint32_t first_pulse;
volatile uint32_t second_pulse;
volatile long int count=0;
double timeperiod;
LiquidCrystal lcd(8,9,10,11,12,13);
void setup() {
  lcd.begin(20,4);
  pinMode(interrupt_pin,INPUT);
  lcd.setCursor(1,0);
  lcd.print("Frequency:");
  attachInterrupt(digitalPinToInterrupt(interrupt_pin),fCalculate,state); 
   
}
void loop() {
   
   delay(500);
   noInterrupts();
   lcd.setCursor(1,1);
   timeperiod=(second_pulse-first_pulse)*1E-6;
   lcd.print(1/timeperiod);
   count=0;
   interrupts();
   
}
void fCalculate(void){
  pulse_time=micros();
  count=count+1;
  pulse();
  
}
void pulse(void){
  if (count==1){
    first_pulse=pulse_time;
    lcd.setCursor(1,2);
    lcd.print(first_pulse);
   }
  else if (count==2){
    second_pulse=pulse_time;
    lcd.setCursor(1,3);
    lcd.print(second_pulse);
   }
  }
