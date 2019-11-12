//MQ135 Co2 감지 5V -> OCC  // GND -> GND // A0 -> A0
#include <MQ135.h> 


/*

Library Repository : https://github.com/ckalpha/MQ135

Author : Damrongwit Nusuk

Email : jack@racksync.com

Website : http://www.racksync.com

*/



#include "MQ135.h"

#define ANALOGPIN A0    //  Define Analog PIN on Arduino Board

#define RZERO 206.85    //  Define RZERO Calibration Value

MQ135 gasSensor = MQ135(ANALOGPIN);



void setup() {

  pinMode(9, OUTPUT);
  
  Serial.begin(9600);

  float rzero = gasSensor.getRZero();

  delay(3000);

  Serial.print("MQ135 RZERO Calibration Value : ");

  Serial.println(rzero);

}



void loop() {

  float ppm = gasSensor.getPPM();

  delay(1000);

  digitalWrite(13,HIGH);

  Serial.print("CO2 ppm value : ");

  Serial.println(ppm);



  if(ppm>5.0){
     digitalWrite(9, HIGH);
    delay(1000);
    Serial.println("too much CO2");
  }
  if(ppm>2.0)
  {
    digitalWrite(9,HIGH);
    delay(100);
    digitalWrite(9,LOW);
    delay(100);
    digitalWrite(9,HIGH);
    delay(100);
    digitalWrite(9,LOW);
    delay(100);
    digitalWrite(9,HIGH);
    delay(100);
    digitalWrite(9,LOW);

  }
  else{
    digitalWrite(9,LOW);
  }
 
}
