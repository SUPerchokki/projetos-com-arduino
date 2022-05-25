// Biblioteca para utilizar o servo
#include <Servo.h>

//define o servo
Servo servo_2;

void setup()
{
  //colocar a porta analogica A0 como entrada
  pinMode(A0, INPUT);

  //dar começo ao Serial
  Serial.begin(9600);

  //definir o modo de attach do servo
  servo_2.attach(2, 500, 2500);

  //posição inicial
  servo_2.write(0);
}


//no loop ele verifica a intensidade de luz e assim que ela baixar de 600 o servo preciona a barrad de espaço
void loop()
{
  //printar o que o sensor esta vendo
  Serial.println(analogRead(A0));
  //verificação
  if (analogRead(A0) < 600) {
    //se o sensor identificar o cacto ele abaixa o servo por 150 milisegundos
    servo_2.write(60);
    delay(150); // Wait for 150 millisecond(s)
    
  } else {
    //se não identificar ele volta o servo a posição original
    servo_2.write(0);
    delay(50);
  }
}
