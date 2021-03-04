const byte xor_pin=3;
const byte frequency=50;
volatile uint32_t time_delay;
volatile uint32_t time_delay_max=0;
float cos_phi;
float phase_angle;
void setup() {
  Serial.begin(9600);
  pinMode(xor_pin,INPUT);
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
   Serial.println(time_delay_max/1000.00);//printing in millisecond
   Serial.print("  ");
   Serial.print(phase_angle);
   Serial.print("  ");
   if(phase_angle<=90){
    Serial.print(-cos_phi);
   }
   else{
    Serial.print(cos_phi);
   }
   time_delay_max=0;
   delay(250);
  
}
