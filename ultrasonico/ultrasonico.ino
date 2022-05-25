#include <Ultrasonic.h>

#define pino_trigger 4
#define pino_echo 5

Ultrasonic ultrasonic(pino_trigger,pino_echo);



void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");

}

void loop() {
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.println("Distancia em cm: ");
  Serial.println(cmMsec);
  delay(1000);

}
