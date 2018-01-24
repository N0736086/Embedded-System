/*
  Serial Blink
  Turns on an LED  when the person enters 1 and off when 0 is entered.

  This is lab2a start-up code.
 */
 
// Pin 9 will be used for the long lead of the LED.
// Pin 8 will be uzed for the buzzer

int led = 9;
int led2 =10;
int buzzer = 8;

// this is the varable to hold the user serial input
char inVal; 

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode (buzzer, OUTPUT); 
  pinMode (1, OUTPUT); 
  pinMode (0, INPUT); 
  Serial.begin(115200); 
  
}

// the loop routine runs over and over again forever:
void loop() {
digitalRead(1); 
  digitalRead (0); 
  if (Serial.available()>0)
  {
    inVal=Serial.read();
    switch(inVal)
    {
      case '0':
        Serial.print("You entered 0 and all the LEDs will turn off\n");
        digitalWrite(led, LOW); 
        digitalWrite(led2, LOW);  
        break;
    // Stops the generation of a square wave triggered by tone(). Has no effect if no tone is being generated.
      case 'x':
    noTone (buzzer);    
     Serial.print("You entered x and Buzzer will turn off\n");
        break;
      case '1':
        digitalWrite(led, HIGH);
        Serial.print("You entered 1 and LED will turn on\n");
        break;
    /*Tone needs 2 arguments, but can take three
      1) Pin#
      2) Frequency - this is in hertz (cycles per second) which determines the pitch of the noise made
      3) Duration - how long teh tone plays
    */
     case 't':
    tone (buzzer, 1000,10000);
        Serial.print("You entered t and buzzer will turn on\n");
        break;
        case '2':
        digitalWrite(led2, HIGH);
        Serial.print("You entered 2 and LED2 will turn on\n");
        break;
        
      default:
        digitalWrite(led, LOW);
        digitalWrite(led2, LOW);
       
        
    }
  }

}
