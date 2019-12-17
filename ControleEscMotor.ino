//Programa: Controle de motor brushless
//Autor : Arduino e Cia

#include <Servo.h>

Servo MotorTeste;

int pino_pot = A5; //Pino do potenciometro
int pino_motor = 10; //Pino de controle do motor
int valor;

void setup()
{
  Serial.begin(9600);
  MotorTeste.attach(pino_motor);
  Serial.println("Aguardando 5 segundos....");
  //delay(5000);
}

void loop()
{
  valor = analogRead(pino_pot); //Le o valor do potenciometro
  valor = map(valor, 0, 1023, 0, 179); //Converte o valor 0,1023 para uma faixa entre 0 e 179
  Serial.print("Potenciometro: "); //Mostra o valor no serial monitor
  Serial.println(valor);
  MotorTeste.write(valor); //Envia o valor para o motor
}
