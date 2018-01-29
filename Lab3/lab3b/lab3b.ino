int sensorPin = A0;            
unsigned int sensorValue = 0;  
int ledTest = 4;
void setup()
{
  pinMode(ledTest, OUTPUT);
  Serial.begin(9600);        
}

void loop()
{
  sensorValue = analogRead(sensorPin);     
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(500);
  if(sensorValue<30)
  {
    for(int i = 0; i <5; i++)
    {
      digitalWrite(ledTest, HIGH);
      delay(150);
      digitalWrite(ledTest, LOW);
      delay(150);
    }
  }
}
