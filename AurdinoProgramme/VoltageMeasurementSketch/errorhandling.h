#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H

class ErrorHandling{
  float e;
  public:
  float error(double x){
  
  if(x<=1){
    e=0.71;
  }
   else if(x<=2.12){
    e=1.39;
  }
   else if(x<=3.53){
    e=1.35;
  }
   else if(x<=7.07){
    e=2.7;
  }
   else if(x<=10.6){
    e=4.05;
  }
   else if(x<=14.1){
    e=4.64;
  }
  else if(x<=12.8){
    e=4.9;
  }
  else if(x<=28.39){
    e=6.91;
  }
  else if(x<=45.13){
    e=7.87;
  }
  else if(x<=62.18){
    e=8.62;
  }
  else if(x<=78.62){
    e=9.38;
  }
  else if(x<=96.09){
    e=9.91;
  }
  else if(x<=112.83){
    e=10.17;
  }
  else if(x<=129.58){
    e=11.42;
  }
  else if(x<=147.05){
    e=10.95;
  }
  else if(x<=164.52){
    e=11.48;
  }
  else if(x<=180.53){
    e=12.47;
  }
  else if(x<=198.73){
    e=12.27;
  }
  else if(x<=217.2){
    e=12.8;
  }
  return e;
}
};
#endif
