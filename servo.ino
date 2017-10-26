#include<Servo.h>
Servo servo1;
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int frequency = 0;
int avarage = 25;
int r,g,b;
void setup() {
  servo1.attach(3);
  
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Frekans ölçeklendirme değerini% 20 olarak ayarlama
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  // Okunacak kırmızı filtrelenmiş fotodiyotların ayarlanması
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Çıkış frekansını okuma
  frequency = pulseIn(sensorOut, LOW);
  r = frequency;
  
 // Seri monitörde değeri yazdırma
  Serial.print("Kirmizi= ");// baskı adı
  Serial.print(frequency);// Kırmızı renk sıklığı yazdırma
  Serial.print("  ");
  delay(100);
  /*if(frequency>50 && frequency<200) {
    servo1.write(30);
  }*/

 // Okunacak yeşil filtrelenmiş fotodiyotları ayarlama
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
 // Çıkış frekansını okuma
  frequency = pulseIn(sensorOut, LOW);
  g = frequency;
  
  // Seri monitörde değeri yazdırma
  Serial.print("Yesil= ");// baskı adı
  Serial.print(frequency);// Yeşil renk sıklığı yazdırma
  Serial.print("  ");
  delay(100);
  /*if(frequency>100 && frequency<150) {
    servo1.write(60);
  }*/

 // Okunacak mavi filtrelenmiş fotodiyotları ayarlama
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Çıkış frekansını okuma
  frequency = pulseIn(sensorOut, LOW);
  b = frequency;
  
  // Seri monitörde değeri yazdırma
  Serial.print("Mavi= ");// baskı adı
  Serial.print(frequency);// Mavi renk sıklığı yazdırma
  Serial.println("  ");
  delay(100);
  /*if(frequency>70 && frequency<90) {
    servo1.write(90);
  }*/

  delay(500); //Çalışma Süresi

  if( ( r - avarage < 34 && r + avarage > 34 ) && ( g - avarage < 98 && g + avarage > 98 ) && ( b - avarage < 107 && b + avarage > 107) ){
     servo1.write(18);
     Serial.println("Turuncu");
  }

     else if( ( r - avarage < 42  && r + avarage > 42 ) && ( g - avarage < 153 && g + avarage > 153 ) && ( b - avarage < 122 && b + avarage > 122) ){
     servo1.write(105);    
     Serial.println("Kirmizi");
  }
  
     else if( ( r - avarage < 18 && r + avarage > 18 ) && ( g - avarage < 78 && g + avarage > 78 ) && ( b - avarage < 39 && b + avarage > 39) ){
     servo1.write(37);    
     Serial.println("Pembe");
  }
     else if( ( r - avarage <76  && r + avarage > 76 ) && ( g - avarage < 114 && g + avarage > 114) && ( b - avarage < 56 && b + avarage > 56) ){
     servo1.write(2);    
     Serial.println("Mor");
  }
  
    else if( ( r - avarage < 97 && r + avarage > 97 ) && ( g - avarage < 220 && g + avarage > 220 ) && ( b - avarage < 113 && b + avarage > 113) ){
     servo1.write(125);    
     Serial.println("Koyu Mor");
  }
  

    else if( ( r - avarage <104  && r + avarage > 104 ) && ( g - avarage < 54 && g + avarage > 54 ) && ( b - avarage < 34 && b + avarage > 34) ){
     servo1.write(138);    
     Serial.println("Mavi");
  }
   else if( ( r - avarage < 64 && r + avarage > 64 ) && ( g - avarage < 59 && g + avarage > 59 ) && ( b - avarage < 36 && b + avarage > 36) ){
     servo1.write(153);    
     Serial.println("Acik Mor");
  } 
  
    else if( ( r - avarage < 66 && r + avarage > 66 ) && ( g - avarage < 48 && g + avarage > 48 ) && ( b - avarage < 86 && b + avarage > 86) ){
     servo1.write(90);    
     Serial.println("Yesil");
  }
  
     else if( ( r - avarage <175  && r + avarage > 175 ) && ( g - avarage < 103 && g + avarage > 103 ) && ( b - avarage < 130 && b + avarage > 130) ){
     servo1.write(60);    
     Serial.println("Koyu Yesil");
 
     }
       else if( ( r - avarage <29  && r + avarage > 29 ) && ( g - avarage < 32 && g + avarage > 32 ) && ( b - avarage < 55 && b + avarage > 55) ){
     servo1.write(75);    
     Serial.println("Sari");
 
     }
   
  else{
     servo1.write(0);    
     Serial.println("Renk tespit edilemedi");   
  }
 
  
}
