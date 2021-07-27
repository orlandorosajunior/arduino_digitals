#include <Wire.h>

#include <MAX30100.h>

#include <SHCSR04.h>

#define LDR 6
#define reflet 7
#define infra 8
#define incl 9
#define LED1 30
#define LED2 29
#define LED3 32
#define LED4 33



MAX30100 pulsacao;
void setup() 
  // put your setup code here, to run once:
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
Serial.begin(115200);
Wire.begin();
pulsacao.begin(pw1600,i50,sr100);
  

}
//variaveis globais

SHCSR04 sensor5;
bool sensor1,sensor2,sensor3,sensor4;
bool saida1,saida2,saida3,saida4;
int analogico1;
float tensao1,percentual1;
int analogico2;
float tensao2,percentual2;
float ultrassonico;

void loop() {
  // put your main code here, to run repeatedly:
  
  analogico1 = analogRead(A0);
  //Serial.println(analogico1);

   analogico2 = analogRead(A1);
 // Serial.println(analogico2);

  ultrassonico = sensor5.read(4,5);

  pulsacao.readSensor();
  Serial.println(pulsacao.IR);
  
  sensor1 = digitalRead(LDR);
 //Serial.println(sensor1);
 
  sensor2 = digitalRead(reflet);
//Serial.println(sensor2);

 
  sensor3 = digitalRead(infra);
 //Serial.println(sensor3);

 
  sensor4 = digitalRead(incl);
 //Serial.println(sensor4);

  //tensao1 = 5 * analogico1 / 1023;
  tensao1 = 0.00488*analogico1;
  tensao2 = 0.00488*analogico2;
  percentual1 = (1 - analogico1/1023.0)*100;
  percentual2 = (1 - analogico2/1023.0)*100;
  
 // Serial.print(" Luminosidade % ");
 //Serial.print(" Som ");
// Serial.println(percentual2);
//Serial.println(ultrassonico);
// Serial.println(" V ");
  //Serial.print(" Nível de Tensão ");
  //Serial.print(tensao1);
 // Serial.println(percentual1);
 // Serial.print(" V ");
//  Serial.println(" Sensacional ");
//   conv7seg(40,41,42,43,percentual2);
  
  
   if((sensor1||sensor2)&&(sensor3||sensor4)) //(a+b).(c+d)
{   
  saida1=1;
}
 else
 {
  saida1=0;
 }
  

    if((sensor1||sensor2||sensor3||sensor4)) //a+b+c+d
    {
      saida2=1;
    }
 else 
 { 
  saida2=0;
  
 }

 if(!(sensor1||sensor2)||!(sensor3||sensor4)) //saida 3
 {
  saida3=1;
 }
 else
 {
  saida3=0;
 }
 
    if((sensor1&&sensor2&&sensor3&&sensor4)) //saida 4  
    {
      saida4=1;
    }
 else 
 { 
  saida4=0;
 }
 
 digitalWrite(LED1,saida1);
    //Serial.println(saida1);
    
 digitalWrite(LED2,saida2);
    //Serial.println(saida2);
    
 digitalWrite(LED3,saida3);
    //Serial.println(saida3);

 digitalWrite(LED4,saida4);
    //Serial.println(saida4);





 
}
