//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
 
#include <Ultrasonic.h>
 
#define pino_trigger 4
#define pino_echo 5

Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  
}
 
void loop()
{
  
  int cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  //Distancia em cm
  Serial.print(cmMsec);
  delay(2000);
}
