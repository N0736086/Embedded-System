#include <stdio.h>
#define ECHOPIN 3
#define TRIGPIN 2
int led7 = 7;
int Blink_Counter = 0;
int Loop_Counter =0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(led7, OUTPUT);
  
}
//double wait_time = delay(100);

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW); 
 float distance = 0.0168918918918919*pulseIn(ECHOPIN, HIGH); // return 0 if no high pulse in 1sec
 Serial.print(distance);
 Serial.println("cm");
 delay(200);
  if(distance <10)
  {
    for (int i = 0; i < 5; i++)
    {
    digitalWrite(led7,HIGH); //1
    delay(100);
    digitalWrite(led7,LOW); //1
    delay(100);  
    Blink_Counter = i+1;
    }
    Loop_Counter ++;
    Serial.print("Led7 blinked ");
    Serial.print(Blink_Counter);
    Serial.print(" times ");
    Serial.print("for the ");
    Serial.print(Loop_Counter);
    if(Loop_Counter == 1)
    {
      Serial.print("st"); 
    }
    else if(Loop_Counter ==2)
    {
      Serial.print("nd");
    }
    else if(Loop_Counter ==3)
    {
      Serial.print("rd");
    }
    else 
    {
      Serial.print("th");  
    }
    Serial.print(" time\n");
  }
}
