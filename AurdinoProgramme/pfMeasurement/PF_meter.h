#ifndef PFMETER_H
#define PFMETER_H

class PfMeter
{  
  uint32_t time_delay;        
  uint32_t time_delay_max = 0;   
  float phase_angle;
  float pf;     

  public:
  

  float getTimeDelay(int channel_name);
  float getPhaseAngle(int channel_name,int frequency);
  float getPf(int channel_name,int frequency);
};

float PfMeter::getTimeDelay(int channel_name){
   
   int i=0;
   while(i<5){
    time_delay=pulseIn(channel_name,HIGH,0);
    if (time_delay>time_delay_max){
      time_delay_max=time_delay;
    }
    i++;
   }
   float tdm=time_delay_max/1000.00;
   time_delay_max=0;
   return tdm;//Return value in millisecond
}
float PfMeter::getPhaseAngle(int channel_name,int frequency){
   phase_angle=getTimeDelay(channel_name)*frequency*360.00*1E-3;
   return(phase_angle);
}
float PfMeter::getPf(int channel_name,int frequency){
   pf=cos(getPhaseAngle(channel_name,frequency)*0.0175);//conversion of degree to radian
   if(phase_angle<=90){
    return(-pf);
   }
   else{
    return(pf);
   }
}


#endif
