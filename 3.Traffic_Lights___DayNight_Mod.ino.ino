#define ECHOPIN 3 //Defining the pin for the Ultrasonic input
#define TRIGPIN 2 //Defining the pin for the Ultrasonic output

int sensorPin = A0;            
unsigned int sensorValue = 0; 

int redLED = 5; //declaring red LEd pin number
int yellowLED = 6;//declaring yellow LEd pin number
int greenLED = 7; //declaring green LEd pin number
int buzzer = 8; // declaring buzzer pin number

int redWait = 2000;//milliseconds
int yellowWait = 1000;//milliseconds
int greenWait = 2000;//milliseconds
int lumi_Threshold = 500; //cm
int sonic_Threshold = 10;

void setup() { //Initializations
pinMode(redLED, OUTPUT);
pinMode(yellowLED, OUTPUT);
pinMode(greenLED, OUTPUT);
pinMode(redLED, OUTPUT);
pinMode(ECHOPIN, INPUT);
pinMode(TRIGPIN, OUTPUT);
 // attachInterrupt(digitalPinToInterrupt(redLED), ultraSonic, FALLING);
//attachInterrupt(0, ultraSonic, RISING);
Serial.begin(115200); //Initialzing Serial communication port and its rate
}

void redLED_On(){
  Serial.print("Red LED on for (millisecs): ");
  Serial.println(redWait);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);
}
void yellowLED_On(){
  Serial.print("Yellow LED on for (millisecs): ");
  Serial.println(yellowWait);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
}

void greenLED_On(){
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

void redLight(){
  for (int x = 0; x < 200*0.8; x++){ // multiply by 0.8 for callibration to real clock
    LDR();
  redLED_On();
  delay(10);
  }
}
void yellowLight(){
  for (int x = 0; x < 100*0.8; x++){
    LDR();
  yellowLED_On();
  delay(10);
  }
}
void greenLight(){
  for (int x = 0; x < 200*0.8; x++){
  LDR();
  greenLED_On();
  delay(10);
  }
}
void loop(){
  redLight();
  yellowLight();
  greenLight();
  yellowLight();
}
