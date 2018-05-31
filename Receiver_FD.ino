// RECEIVER BOARD 
int Level1 = 11;        //INITIALISING RED LED PIN
int Level2 = 12;        //INITIALISING YELLOW LED PIN
int Level3 = 13;        //INITIALISING GREEN LED PIN
//int Level4 = 10;        //INITIALISING RED LED PIN
//int Level5 = 11;        //INITIALISING YELLOW LED PIN
//int Level6 = 12;        //INITIALISING GREEN LED PIN

int BUZZER = 8;      //INITIALISING BUZZER PIN
int pinA = 0;
int pinB = 1;
int pinC = 2;
int pinD = 3;
int pinE = 4;
int pinF = 5;
int pinG = 6;
int D1 = 7;
int D2 = 8;
int D3 = 9;
int D4 = 10;
char receive;                            //INITIALISING A MODE VARIABLE TO STORE MODE DATA COMING FROM TRANSMITTER
 
void setup()                          //SETTING UP/DECLARING OF ARDUINO PINS, EITHER OUTPUT OR INPUT AND SERIAL MONITORS
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);


  
  pinMode(Level1, OUTPUT);              //DECLARE RED LED PIN AS OUTPUT PIN
  pinMode(Level2, OUTPUT);              //DECLARE YELLOW LED PIN AS OUTPUT PIN
  pinMode(Level3, OUTPUT);              //DECLARE GREEN LED PIN AS OUTPUT PIN
//  pinMode(Level4, OUTPUT); 
//  pinMode(Level5, OUTPUT);              //DECLARE GREEN LED PIN AS OUTPUT PIN
//  pinMode(Level6, OUTPUT); 
  Serial.begin(9600);                 //INITIALISE SERIAL MONITOR OF RECEIVER BOARD TO TRANSMIT CODE TO THE BOARD  
  Serial1.begin(9600);
  while (!Serial1);//DECLARE BUZZER PIN AS OUTPUT PIN
}

void loop()                           //STARTING ARDUINO LOOP
{                                     //LOOP STARTS

  while(Serial1.available())           //CHECKS IF THERE IS ANY VALUE FROM THE ZIGBEE CHANNEL
  {
    receive = Serial1.read();              //READS THE ZIGBEE CHANNEL VALUE AND STORES THEM IN THE "Mode" VARIABLE
  digitalWrite(D4, HIGH);
   if(receive=='1')                    //IF ZIGBEE CHANNEL IS READ AS 'R'
      {                               //REGULAR MODE STARTS
        //YELLOW LED IS OFF
      digitalWrite(Level1, HIGH);
      digitalWrite(Level2, LOW); 
      digitalWrite(Level3, LOW); 
        delay(100);
        digitalWrite(Level1, LOW);

      }                               //REGULAR MODE ENDS
      
      else if(receive=='2')                    //IF ZIGBEE CHANNEL IS READ AS 'R'
      {                               //REGULAR MODE STARTS
        //YELLOW LED IS OFF
      digitalWrite(Level1, LOW);
      digitalWrite(Level2, HIGH); 
      digitalWrite(Level3, LOW); 

      }                

      else if(receive=='3')                    //IF ZIGBEE CHANNEL IS READ AS 'R'
      {                               //REGULAR MODE STARTS
        //YELLOW LED IS OFF
      digitalWrite(Level1, LOW);
      digitalWrite(Level2, LOW); 
      digitalWrite(Level3, HIGH); 
            delay(50);
      digitalWrite(Level3, LOW); 


      }                

    if(receive=='8')                    //IF ZIGBEE CHANNEL IS READ AS 'R'
      {   
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
  //0
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(300);               // wait for a second
  
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
  //1
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(300);               // wait for a second
  
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW); 
  //2
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(300);               // wait for a second

  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH); 
  //3
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);     
  delay(300);               // wait for a second 
  digitalWrite(pinC, HIGH);  
  digitalWrite(pinE, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);       
      }
  }
}
//MAIN LOOP ENDS


