#define trigPin1 A0
#define echoPin1 A1
 
long duration, distance;
 
char phone_no1[]="+9779825377955"; 
 
char phone_no[]="+9779800009000";
 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
 
void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.print("FLOOD DETECTION CONTROL ROOM..");
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) 
  {
    lcd.scrollDisplayLeft();
    delay(500);
  }
   
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
 
 
}
  
void loop() 
{
   
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration = pulseIn(echoPin1, HIGH);
distance = duration*0.034/2;
 
 
 
lcd.setCursor(0,0);
    
     lcd.print("WATER LEVEL:");
     lcd.print(distance);
     delay(500);
     lcd.clear();
     if( distance<=5)
     {
       
      SendMessage();
     }
     
}
 
void SendMessage()
{
Serial.println("AT+CMGF=1");
delay(2000);
Serial.print("AT+CSCA=\"");
Serial.print(phone_no);
Serial.write(0x22);
Serial.write(0x0D);   
Serial.write(0x0A);  
delay(3000);
Serial.print("AT+CMGS=\"");
Serial.print(phone_no1); 
Serial.write(0x22);
Serial.write(0x0D);  
Serial.write(0x0A); 
delay(3000);
Serial.print("water level is in danger level");
delay(500);
Serial.println(char(26));
}
