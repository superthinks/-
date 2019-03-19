#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int trig = 8;
int echo = 9;


void setup() {
  lcd.begin();
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}

void loop() {
  digitalWrite(trig,LOW);
  digitalWrite(echo,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  unsigned long duration = pulseIn(echo, HIGH);
  float distance = duration/29.0 /2.0;
  Serial.print(distance);
  
  lcd.setCursor(5,0);
  lcd.print(distance,2);
  lcd.setCursor(9,0);
  lcd.print("cm");
delay(1);

  if (distance > 100) {
   lcd.setCursor(5,0);
   lcd.print("error");
   lcd.setCursor(10.,0);
   lcd.print("...");


  }
delay(1);

 

}
