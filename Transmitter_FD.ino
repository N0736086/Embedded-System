#include <stdio.h> // Including the standard input/output library
#include <Servo.h> //Including the Servo motor library within involves PWM 
Servo myservo;  // create servo object to control a servo

#define ECHOPIN 3 //defining pin for the ultrasonic range finder echo pin
#define TRIGPIN 2 //defining pin for the ultrasonic range finder trigger pin 
int SERVO = 7; //declaration for right servo motor on pin 4

int buzzer = 9;

int SWITCH = 8;
void setup() 
{  
  pinMode(SWITCH, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(TRIGPIN, OUTPUT);           //DECLARE TRIGGERPIN AS OUTPUT PIN
  pinMode(ECHOPIN, INPUT);            //DECLARE ECHOPIN AS INPUT PIN
 // Serial.begin(9600);
  Serial1.begin(9600);  //BEGENING OF THE ZIGBEE CHANNEL
}
int Val;
void loop()
{
 //start front distance computing
 digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW); 
 float distance = pulseIn(ECHOPIN, HIGH)/58; // return 0 if no high pulse in 1sec
// Serial.print("Front Distance: ");
// Serial.print(distance);
// Serial.println("cm");
 delay(200);//end front distance

int value = analogRead(A0);

Val = digitalRead(SWITCH);
Serial.println(value);
 //Conditions start here 
   
if(distance >=0&&distance <=10)
{
  tone(buzzer, 100,500);
  Serial1.write('1'); // Water Level 1
  myservo.detach();
}

if(distance >10&&distance <=30)
{
  Serial1.write('2'); // Water Level 2
//  myservo.attach(SERVO);
}

//if(distance >16&&distance <=24)
//{
//  Serial1.write('3'); // Water Level 2
////  myservo.attach(SERVO);
//}
//if(distance >24&&distance <=32)
//{
//  Serial1.write('4'); // Water Level 2
////  myservo.attach(SERVO);
//}
//
//if(distance >32 && distance <=40)
//{
//  Serial1.write('5'); // Water Level 3
////  myservo.attach(SERVO);
//}

if(distance >30 )
{
  Serial1.write('3'); //Water Level 4
  myservo.attach(SERVO);
  myservo.write(45);
  tone(buzzer, 100,1000);
  delay(100);
}

//if(Val == 0)
//{
//    Serial1.write('7'); //Water Level 4
//
//}
else if(value <550)
 {
  Serial1.write('8'); //Water Level 4
}
}

 
 
