#include <LiquidCrystal.h>
const byte xor_pin=3;
const byte frequency=50;
volatile uint32_t time_delay;
volatile uint32_t time_delay_max=0;
float cos_phi;
float phase_angle;
LiquidCrystal lcd(8,9,10,11,12,13);
void setup() {
  
  lcd.begin(20,4);
  pinMode(xor_pin,INPUT);
  lcd.setCursor(1,0);
  lcd.print("Time Delay:");
  lcd.setCursor(1,1);
  lcd.print("Cosphi:");
  lcd.setCursor(1,2);
  lcd.print("Phase Angle:" );
   
}
void loop() {
   
   int i=0;
   while(i<5){
    time_delay=pulseIn(xor_pin,HIGH,0);
    if (time_delay>time_delay_max){
      time_delay_max=time_delay;
    }
    i++;
   }
   phase_angle=time_delay_max*frequency*360.00*1E-6;
   cos_phi=cos(phase_angle*0.0175);//conversion of degree to radian
   lcd.setCursor(13,0);
   lcd.print(time_delay_max/1000.00);//printing in millisecond
   lcd.setCursor(13,2);
   lcd.print(phase_angle );
   lcd.setCursor(8,1);
   if(phase_angle<=90){
    lcd.print(-cos_phi);
   }
   else{
    lcd.print(cos_phi);
   }
   time_delay_max=0;
   delay(250);
  
}
