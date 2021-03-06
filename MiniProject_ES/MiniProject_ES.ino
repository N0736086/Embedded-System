#define ECHOPIN 3 //Defining the pin for the Ultrasonic input
#define TRIGPIN 2 //Defining the pin for the Ultrasonic output

char modeChoice='r';
int sensorPin = A0;            
unsigned int sensorValue = 0; 

int redLED = 5; //declaring red LEd pin number
int yellowLED = 6;//declaring yellow LEd pin number
int greenLED = 7; //declaring green LEd pin number
int buzzer = 8; // declaring buzzer pin number

int redWait = 2000;//milliseconds
int yellowWait = 1000;//milliseconds
int greenWait = 2000;//milliseconds
int flash_Time = 100; //milliseconds
int sonic_Threshold = 10; //cm
int lumi_Threshold = 500; //cm

float dist_Tracker = 0;

void setup() { //Initializations
pinMode(redLED, OUTPUT);
pinMode(yellowLED, OUTPUT);
pinMode(greenLED, OUTPUT);
pinMode(redLED, OUTPUT);
pinMode(ECHOPIN, INPUT);
pinMode(TRIGPIN, OUTPUT);
pinMode (buzzer, OUTPUT);
 // attachInterrupt(digitalPinToInterrupt(redLED), ultraSonic, FALLING);
//attachInterrupt(0, ultraSonic, RISING);
//inputString.reserve(200);
Serial.begin(115200); //Initialzing Serial communication port and its rate
}

void redLED_On(){
  noTone(buzzer);
  Serial.print("Red LED on for (millisecs): ");
  Serial.println(redWait);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);
}
void yellowLED_On(){
  noTone(buzzer);
  Serial.print("Yellow LED on for (millisecs): ");
  Serial.println(yellowWait);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
}

void greenLED_On(){
  noTone(buzzer);
  Serial.print("Green LED on for (millisecs): ");
  Serial.println(greenWait);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
}

void ultraSonic2(){
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW); 
 float sonic_Distance = pulseIn(ECHOPIN, HIGH)/58; // return 0 if no high pulse in 1sec
 Serial.print(sonic_Distance);
 Serial.println(" cm");
if (sonic_Distance < sonic_Threshold){
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    //delay(50);
    }
 else {
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  
  }
}

void LDR(){
  sensorValue = analogRead(sensorPin);     
  Serial.println(sensorValue);
while(sensorValue<lumi_Threshold){
  ultraSonic2();
  sensorValue = analogRead(sensorPin);     
  delay(50);
}
}


void yellowBlinkbuz(){
  for (int i =0; i < 10; i++){
    tone(buzzer, 1000, 1000);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    delay(flash_Time);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    delay(flash_Time);
  }
}

int counter1 = 0;
int counter2 = 0;

void ultraSonic(){
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW); 
 float sonic_Distance = pulseIn(ECHOPIN, HIGH)/58; // return 0 if no high pulse in 1sec
 Serial.print(sonic_Distance);
 Serial.println("cm");

while (sonic_Distance < sonic_Threshold){
    //if(counter1 != counter2){
    yellowBlinkbuz();
    counter1 = 0;
    counter2 =0;
    digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW); 
 float sonic_Distance = pulseIn(ECHOPIN, HIGH)/58; // return 0 if no high pulse in 1sec
    //}
    counter2++;
    if(sonic_Distance>=sonic_Threshold){
      break;
}
}
counter1++;
}
void redLight(){
  for (int x = 0; x < 200*0.8; x++){ // multiply by 0.8 for callibration to real clock
    ultraSonic();
   // LDR();
  redLED_On();
  delay(10);
  }
}
void yellowLight(){
  for (int x = 0; x < 100*0.8; x++){
    ultraSonic();
   // LDR();
  yellowLED_On();
  delay(10);
  }
}
void greenLight(){
  for (int x = 0; x < 200*0.8; x++){
  ultraSonic();
 // LDR();
  greenLED_On();
  delay(10);
  }
}

void redLight2(){
  for (int x = 0; x < 200*0.8; x++){ // multiply by 0.8 for callibration to real clock
    //ultraSonic();
    LDR();
  redLED_On();
  delay(10);
  }
}
void yellowLight2(){
  for (int x = 0; x < 100*0.8; x++){
    //ultraSonic();
    LDR();
  yellowLED_On();
  delay(10);
  }
}
void greenLight2(){
  for (int x = 0; x < 200*0.8; x++){
 // ultraSonic();
  LDR();
  greenLED_On();
  delay(10);
  }
}

void redLight3(){
  for (int x = 0; x < 200*0.8; x++){ // multiply by 0.8 for callibration to real clock
    ultraSonic();
    LDR();
  redLED_On();
  delay(10);
  }
}
void yellowLight3(){
  for (int x = 0; x < 100*0.8; x++){
    ultraSonic();
    LDR();
  yellowLED_On();
  delay(10);
  }
}
void greenLight3(){
  for (int x = 0; x < 200*0.8; x++){
  ultraSonic();
  LDR();
  greenLED_On();
  delay(10);
  }
}

void regularMode(){
  redLED_On();
      delay(2000);
      yellowLED_On();
      delay(1000);
      greenLED_On();
      delay(2000);
      yellowLED_On();
      delay(1000);
}

void pedestrianMode(){
  redLight();
  yellowLight();
  greenLight();
  yellowLight();
  
}

void dayNightMode(){
   digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW); 
 float dist = pulseIn(ECHOPIN, HIGH)/58; // return 0 if no high pulse in 1sec
  if (dist>=10.0)
    redLED_On();
  else
    greenLED_On();
  
}

void compoundMode(){
  redLight3();
  yellowLight3();
  greenLight3();
  yellowLight3();
  
}

void loop(){
  //compoundMode();
  while (Serial.available())
     modeChoice=Serial.read();
    switch(modeChoice)
    {
      case 'r':
      regularMode();
      break;

      case 'p':
      pedestrianMode();
      break;

      case 'm':
      dayNightMode();
      break;
      
      default:
      regularMode();
      break;
  /*redLight();
  yellowLight();
  greenLight();
  yellowLight();*/
  }
}

