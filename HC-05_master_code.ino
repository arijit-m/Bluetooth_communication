/* For Arduino_2(only master HC05)
    Connect HC05 only with Arduino_2
    Pin 10,11 Arduino_2 -> Pin 8,9 Arduino_1
    Put serial monitor 9600
    HC05=HC-05_arijit_ (master)
    Pass=2003
*/
#include <SoftwareSerial.h>
SoftwareSerial BTserial(0,1);
#define Pin0 10       
#define Pin1 11
int tPeriod=1000;     //as mentioned in milisecond

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);
  pinMode(Pin0,INPUT);      //taking state reading of pins of Arduino_1
  pinMode(Pin1,INPUT);
}

int v1;
int v2;

void loop() {
  v1=digitalRead(Pin0);     //state of Pin0
  v2=digitalRead(Pin1);     //state of Pin1
  if(v1==1 && v2==0){
      Serial.println(0);    //while 1kHz
  }else if(v1==0 && v2==1){
      Serial.println(1);    //while 2kHz
  }else if(v1==0 && v2==0){    
  }                           //print nothing

  BTserial.print(Serial.read());      //sending to slave HC05(HC-05_B)

  delay(tPeriod);
}