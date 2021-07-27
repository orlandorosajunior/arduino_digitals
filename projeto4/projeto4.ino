 #define chave1 10 
 #define chave2 11 
 #define LED 30 
#define LED1 31
#define LED2 32
#define LED3 33
 void setup()  
 { 
      pinMode(chave1,INPUT); 
 
    pinMode(chave2,INPUT); 
    pinMode(LED,OUTPUT); 
 } 
 
 
 bool e(bool i1, bool i2); //cabeçalho da função 
 bool ou(bool i1, bool i2); //cabeçalho da função 
 bool naoe(bool i1, bool i2); //cabeçalho da função 
 bool naoou(bool i1, bool i2); //cabeçalho da função 
 
 
 void loop()  
 { 
   bool e1, e2, s1,s2,s3,s4; 
 
 
   e1 = digitalRead(chave1); 
   e2 = digitalRead(chave2); 
   
   s1 = e(e1,e2);
   s2 = ou(e1,e2);
   s3 = naoe(e1,e2);
   s4 = naoou(e1,e2); 
   
   digitalWrite(LED,s1);   
   digitalWrite(LED1,s2);  
   digitalWrite(LED2,s3);
   digitalWrite(LED3,s4);
 }
 
     bool e(bool i1, bool i2) 
 { 
   bool o1; 
   //logica E 
   if(i1 && i2 == 1) 
     o1 = 1; 
   else 
     o1 = 0;   
   return o1; 
 } 
 
 
 bool ou(bool i1, bool i2) 
 { 
   bool o1; 
   //logica E 
   if(i1 || i2 == 1) 
    o1 = 1; 
   else 
     o1 = 0;   
   return o1; 
 } 
 
 
 bool naoe(bool i1, bool i2) 
 { 
   bool o1; 
   //logica E 
   if(!(i1 && i2) == 1) 
     o1 = 1; 
   else 
     o1 = 0;   
   return o1; 
 } 
 
 
 bool naoou(bool i1, bool i2) 
 { 
   bool o1; 
   //logica E 
   if(!(i1 || i2) == 1) 
     o1 = 1; 
   else 
     o1 = 0;   
   return o1; 
 } 
