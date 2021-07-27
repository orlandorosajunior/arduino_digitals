#include <Wire.h>
#include <MAX30100.h>
#include <SHCSR04.h> 

#define LDR 6
#define reflet 7
#define infra 8
#define incl 9
#define LED1 30
#define LED2 31
#define LED3 32
#define LED4 33

//void conv7seg(int d3, int d2, int d1, int d0,int valor);



MAX30100 pulsacao;
void setup() 
{
  pinMode(LDR,INPUT);
  pinMode(reflet,INPUT);
  pinMode(infra,INPUT);
  pinMode(incl,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(40,OUTPUT);
  pinMode(41,OUTPUT);
  pinMode(42,OUTPUT);
  pinMode(43,OUTPUT);
  Wire.begin();
  Serial.begin(9600);
  pulsacao.begin(pw1600, i50, sr100);
}
//variáveis globais

bool sensor1,sensor2,sensor3,sensor4;
bool saida1,saida2,saida3,saida4;
int analogico1,analogico2;
float tensao1,percentual1,tensao2,percentual2;
SHCSR04 sensor5;
float ultrassonico;

void loop() 
{
   analogico1 = analogRead(A0);
   analogico2 = analogRead(A1);
   ultrassonico = sensor5.read(4,5);
   //Serial.println(ultrassonico);
   pulsacao.readSensor();
   delay(10);
   Serial.println(pulsacao.IR);
  //Serial.println(analogico1);
   sensor1 = digitalRead(LDR); //leitura do pino do LDR
   //Serial.println(sensor1);
   sensor2 = digitalRead(reflet);
   //Serial.println(sensor2);
   sensor3 = digitalRead(infra);
   //Serial.println(sensor3);
   sensor4 = digitalRead(incl);
   //Serial.println(sensor4);

   //tensao1 = 5 * analogico1 / 1023;
   tensao1 = 0.00488 * analogico1;
   //Serial.print("Nível de tensão: ");
   //Serial.println(tensao1);
   percentual1 =(1 - analogico1/1023.0)*100;
   //Serial.print("Luminosidade em %: ");
   //Serial.println(percentual1);

   //tensao2 = 5 * analogico2 / 1023;
   tensao2 = 0.00488 * analogico2;
   //Serial.print("Nível de tensão: ");
   //Serial.println(tensao2);
   percentual2 =(1 - analogico2/1023.0)*100;
   //Serial.print("Ruído em %: ");
   //Serial.println(percentual2);
   
   conv7seg(40,41,42,43,(int)percentual1/10.0);
   if((sensor1 || sensor2) && (sensor3 || sensor4))
   {
      saida1 = 1;
   }
   else
   {
      saida1 = 0; 
   }
   if(sensor1 || sensor2 || sensor3 || sensor4) 
   {
      saida2 = 1;
   }
   else
   {  
      saida2 = 0;
   }
   if(!(sensor1 || sensor2)||!(sensor3 || sensor4))
   {
      saida3 = 1;
   }
   else
   {
      saida3 = 0;
   }
   if(sensor1&&sensor2 && sensor3 && sensor4)
   {
      saida4 = 1;
   }
   else
   {
      saida4 = 0;
   } 
   digitalWrite(LED1,saida1);
   digitalWrite(LED2,saida2);
   digitalWrite(LED3,saida3);
   digitalWrite(LED4,saida4);
}

void conv7seg(int d3, int d2, int d1, int d0,int valor)
{
  bool b3,b2,b1,b0;
  //Serial.println(valor);
  if(valor % 2 == 0)
    b0 = 0;
  
  else
    b0 = 1;
  valor -=2;
  if(valor % 4 == 0)
    b1 = 0;
  else
    b1 = 1;
  valor -=4;
  if(valor % 8 == 0)
    b2 = 0;
  else
    b2 = 1;
  valor -=8;
  if(valor % 16 == 0)
    b1 = 0;
  else
    b1 = 1;
  
  digitalWrite(d3,(bool)b3);
  digitalWrite(d2,(bool)b2);
  digitalWrite(d1,(bool)b1);
  digitalWrite(d0,(bool)b0);
 // Serial.print(digitalRead(d3));
 // Serial.print(digitalRead(d2));
 // Serial.print(digitalRead(d1));
 // Serial.println(digitalRead(d0));
}
