#include "ACmeter.h"
const int sensor_in = A0;
const int sensor_in1 = A1;
const int sensor_in2 = A2;
int mv_per_amp0 = 185;  
int mv_per_amp1 = 185;
int mv_per_amp2 = 185;
double sensed_rms;
double sensed_rms1;
double sensed_rms2;
double i0;
double i1;
double i2;

int f=0,d=0,e=0;
const byte interrupt_pin=2;
volatile byte state=RISING;
volatile uint32_t pulse_time;
volatile uint32_t first_pulse;
volatile uint32_t second_pulse;
volatile long int count=0;
double timeperiod;
double g;
void fCalculate(void);
void setup() {
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);

Serial.begin(9600);
pinMode(interrupt_pin,INPUT);
attachInterrupt(digitalPinToInterrupt(interrupt_pin),fCalculate,state); 


}

void loop() {
  

  delay(1000);
  noInterrupts();
  timeperiod=(second_pulse-first_pulse)*pow(10,-6);
  g=1/timeperiod;
  Serial.println(' ');
  Serial.print(g);
  Serial.print("    ");
  count=0;
  interrupts();

  
  AcMeter a;
  sensed_rms = (a.getRMS(sensor_in) * 1000)/(mv_per_amp0);
  i0=sensed_rms/2;
  Serial.print("Amp0  ");
  Serial.print(i0);
  Serial.print("   ");
  delay(100);
  
  AcMeter b;
  sensed_rms1 = (b.getRMS(sensor_in1) * 1000)/(mv_per_amp1);
  i1=sensed_rms1/2;
  Serial.print("Amp1  ");
  Serial.print(i1);
  Serial.print("   ");
  delay(100);
  
  AcMeter c;
  sensed_rms2 = (c.getRMS(sensor_in2) * 1000)/(mv_per_amp2);
  i2=sensed_rms2/2;
  i2=i2-0.07;
  Serial.print("Amp2  ");
  Serial.print(i2);
  Serial.println("   ");
  
  if(g>=49.4 && g<=50.6){
    Serial.print("BalaNCED");
  }
  else if(g>50.6){
      if(abs(i0-i1)<=0.1 && abs(i2-i1)<=0.1 && abs(i0-i2)<=0.1){Serial.print("BalaNCED");}
      else if(i0 < i1 && i0 < i2){
        Serial.print("Amp0 is smaller");
         f++;
        if(f==1){
          digitalWrite(3,HIGH);
          digitalWrite(4,LOW);
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);
          delay(200);
        }
        else if (f==2){
          digitalWrite(3,LOW);
          digitalWrite(4,HIGH);
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);
          delay(200);
       }
       else if (f==3){
          digitalWrite(3,HIGH);
          digitalWrite(4,HIGH);
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);
          delay(200);
       }
      }
      else if(i1 < i0 && i1 < i2){Serial.print("Amp1 is smaller");
      d=d++;
      if(d==1){
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        delay(200);
        }
       else if (d==2){
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        delay(200);
       }
       else if (d==3){
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        delay(200);
       }
      }
      else if(i2 < i1 && i2 < i0){Serial.print("Amp2 is smaller");
      e=e++;
      if(e==1){
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        digitalWrite(8,LOW);
        delay(200);
        }
       else if (e==2){
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);
        digitalWrite(8,HIGH);
        delay(200);
       }
       else if (e==3){
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        digitalWrite(8,HIGH);
        delay(200);
       }
      }
 
      
  }
  else if(g<49.4){
    if(i0>i1 &&  i0>i2){
      Serial.print("Amp0 is larger");
      x++;
      if(x==1){
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        delay(200);
        }
      else if (x==2){
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        delay(200);
       }
       }
          if(i1>i0 &&  i1>i2){
      Serial.print("Amp1 is larger");
      y++;
      if(y==1){
          digitalWrite(3,LOW);
          digitalWrite(4,LOW);
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);
          delay(200);
        }
        else if (y==2){
          digitalWrite(3,LOW);
          digitalWrite(4,LOW);
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);
          delay(200);
       }
       }
           if(i2>i1 &&  i2>i0){
      Serial.print("Amp2 is larger");
      z++;
      if(z==1){
          digitalWrite(3,LOW);
          digitalWrite(4,LOW);
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);
          delay(200);
        }
        else if (z==2){
          digitalWrite(3,LOW);
          digitalWrite(4,LOW);
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
          digitalWrite(8,LOW);
          delay(200);
       }

      }
      
  }
}

void fCalculate(void){
  pulse_time=micros();
  count=count+1;
  pulse();
  
}
void pulse(void){
  if (count==1){
    first_pulse=pulse_time;
  
   }
  else if (count==2){
    second_pulse=pulse_time;
   }
  }
