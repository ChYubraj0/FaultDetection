int adcGenerator();
int faultDistance(int);
const int analog_channel = A0;
int adcValue,readValue;
int r,y,b;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //calculation for r fault:
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  adcValue=adcGenerator();
  Serial.println("");
  Serial.print(adcValue);
  Serial.print("   ");
  r=faultDistance(adcValue);
  Serial.print(r);
  Serial.print("   ");
  delay(1000);

  //calculation for y fault
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  adcValue=adcGenerator();
  Serial.print(adcValue);
  Serial.print("   ");
  r=faultDistance(adcValue);
  Serial.print(y);
  Serial.print("   ");
  delay(1000);

  //calculation for b fault
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  adcValue=adcGenerator();
  Serial.print(adcValue);
  Serial.print("   ");
  b=faultDistance(adcValue);
  Serial.print(b);
  Serial.print("   ");
  delay(1000);

  //CLASSIFYING TYPE OF FAULT
  char buffer[19];
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
  Serial.println(buffer);
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
