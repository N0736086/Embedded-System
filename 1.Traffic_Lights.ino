int redLED = 5;
int yellowLED = 6;
int greenLED = 7;

int redWait = 2000;
int yellowWait = 1000;
int greenWait = 2000;
void setup() {
pinMode(redLED, OUTPUT);
pinMode(yellowLED, OUTPUT);
pinMode(greenLED, OUTPUT);
pinMode(redLED, OUTPUT);

Serial.begin(9600);
}

void redLED_On(){
  Serial.print("Red LED on for (millisecs): ");
  Serial.println(redWait);
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  delay(redWait);
}
void yellowLED_On(){
  Serial.print("Yellow LED on for (millisecs): ");
  Serial.println(yellowWait);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  delay(yellowWait);
}

void greenLED_On(){
  Serial.print("Green LED on for (millisecs): ");
  Serial.println(greenWait);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(greenWait);
}
void loop() {
 redLED_On();
 yellowLED_On();
 greenLED_On();
 yellowLED_On();
}
