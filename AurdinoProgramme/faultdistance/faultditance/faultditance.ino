#include <LiquidCrystal.h>
int adcGenerator();
int faultDistance(int);

LiquidCrystal lcd(8,9,10,11,12,13);
const int analog_channel = A0;
int adcValue,readValue;
int r,y,b;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  lcd.begin(20,4);
  lcd.print("FAULT LOCATION AND CLASSIFICATION");
  delay(5000);
  lcd.clear();
}

void loop() {
  //calculation for r fault:
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  adcValue=adcGenerator();
  lcd.setCursor(0,0);
  lcd.print("      ");
  lcd.setCursor(0,0);
  lcd.print(adcValue);
  lcd.setCursor(0,1);
  r=faultDistance(adcValue);
  lcd.print(r);
  delay(1000);

  //calculation for y fault
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  adcValue=adcGenerator();
  lcd.setCursor(4,0);
  lcd.print("      ");
  lcd.setCursor(4,0);
  lcd.print(adcValue);
  lcd.setCursor(4,1);
  y=faultDistance(adcValue);
  lcd.print(y);
  delay(1000);

  //calculation for b fault
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  adcValue=adcGenerator();
  lcd.setCursor(8,0);
  lcd.print("      ");
  lcd.setCursor(8,0);
  lcd.print(adcValue);
  lcd.setCursor(8,1);
  b=faultDistance(adcValue);
  lcd.print(b);
  delay(1000);

  //CLASSIFYING TYPE OF FAULT
  char buffer[19];
  lcd.setCursor(0,2);
  if(r==0 && y==0 && b==0){
    sprintf(buffer,"NO FAULT          ");
  }
  //TRIPLE LINE TO GROUND FAULT
  else if(r==y && y==b){
    sprintf(buffer,"RYB-G fault at %d KM", r);
  }
  //SINGLE LINE TO GROUND FAULT
  else if(r>=2 && y==0 && b==0){
    sprintf(buffer,"R-G fault at %d KM",r);
   }  
  else if(r==0 && y>=2 && b==0){
    sprintf(buffer,"Y-G fault at %d KM",y);
   }
  else if(r==0 && y==0 && b>=2){
    sprintf(buffer,"B-G fault at %d KM",b);
   }
   //DOUBLE LINE TO GROUND FAULT
  else if(r==y && b==0 && r>=2){
    sprintf(buffer,"RY-G fault at %d KM",r);
   }
  else if(r==0 && y==b && y>=2 ){
    sprintf(buffer,"YB-G fault at %d KM",y);
   }
  else if(r==b && y==0 && b>=2){
    sprintf(buffer,"RB-G fault at %d KM",b);
   }
  lcd.print(buffer);
  }

  
int adcGenerator(){
  int maxValue = 0;        
  int minValue = 1023;
  uint32_t start_time = millis();
  while((millis()-start_time) < 250){
      readValue = analogRead(analog_channel);
      if (readValue > maxValue){
        maxValue = readValue;
      }
      if (readValue < minValue){
        minValue = readValue;
      }
    }
    return(maxValue-minValue);
  }

int faultDistance(int adcValue){
   if (adcValue==0){
      return 0;
      }
    else if (adcValue>=400 && adcValue<=450){
      return 2;
      }
    else if (adcValue>=200 && adcValue<=300){
      return 4;
      }
    else if (adcValue>=150 && adcValue<=199){
      return 6;
      }
    else if (adcValue>=100 && adcValue<=150){
      return 8;
      }
}
