#ifndef ACMETER_H
#define ACMETER_H

class AcMeter
{
  double result;
  int readValue;             
  int maxValue = 0;        
  int minValue = 1024; 
  public:
  
  double getPeak(int channelName);
  double getRMS(int channelName);
  
};

double AcMeter::getPeak(int channelName){
    uint32_t start_time = millis();
    while((millis()-start_time) < 250){
      readValue = analogRead(channelName);
      if (readValue > maxValue){
        maxValue = readValue;
      }
      if (readValue < minValue){
        minValue = readValue;
      }
    }
    result = ((maxValue - minValue) * 5.0)/1024.0;
    return result;
}
double AcMeter::getRMS(int channelName){
    
    return(getPeak(channelName)*0.707);
    
}

#endif
