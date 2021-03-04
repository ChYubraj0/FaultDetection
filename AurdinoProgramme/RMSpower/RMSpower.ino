//the circuit diagram for this program is file named as "AC_current&voltage_measurement" in circuit folder
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
const int CS_channel=A1;
const int VS_channel=A0;
double RMSvoltage;
double RMScurrent; 
double RMSpower;
double inst_current1;
double inst_voltage1;
void setup() {
  lcd.begin(20,4);
    
  }

void loop() {
  double inst_voltage=0.00;
  double inst_current=0.00;

  float conv_const=5.00/1024.00;
  float j=0.00;
  uint32_t start_time = millis();
  while((millis()-start_time) < 2000){
    j=j+1.00;
    inst_current1=analogRead(CS_channel)-512.00;
    inst_current1=inst_current1*conv_const;
    inst_current1=inst_current1*inst_current1;
    inst_current=inst_current+inst_current1;    
    inst_voltage1=analogRead(VS_channel);
    inst_voltage1=inst_voltage1*conv_const;
    inst_voltage1=inst_voltage1*inst_voltage1;
    inst_voltage=inst_voltage1+ inst_voltage;
    }
    inst_current=inst_current/j;
    RMScurrent=sqrt(inst_current)*20.00;

   inst_voltage=inst_voltage/j;
   RMSvoltage=sqrt(inst_voltage)*2.00*20.00*1.35;//voltage_divider_const=2 and transformer_ratio=20.00 and callibration=1.35;

   RMSpower=RMSvoltage*RMScurrent;
   
   lcd.setCursor(0,0);
   lcd.print(RMSvoltage);
   lcd.print("    ");

   lcd.setCursor(0,1);
   lcd.print(RMScurrent);
   lcd.print("    ");
   
   lcd.setCursor(0,2);
   lcd.print(RMSpower);
   lcd.print("    ");

}
