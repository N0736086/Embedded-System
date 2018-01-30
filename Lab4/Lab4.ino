/*
                A
             ________
            |        |
         F  |        |  B
            |   G    |
            |________|
            |        |
            |        |  C
        E   |        |
            |________|            
                D

*/
// pin assignments
/* 
specify pins on the 7-seg display that for your Arduino
example you can connect the A segment of the display to the pin 2 on the Arduino.
*/

int counter=0;




void setup() {
  // put your setup code here, to initialize all the pins 
  pinMode(counter, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);

}

void Seg2Zero()
  {
         digitalWrite(3, HIGH); //high  voltage 
         //digitalWrite(1, LOW); //high  voltage 
        ///digitalWrite(2, LOW); //high  voltage 
        // digitalWrite(3, LOW); //high  voltage 

          digitalWrite(7, LOW); //gournf
         digitalWrite(8, LOW); //gournf
         digitalWrite(9, LOW);
         digitalWrite(10, LOW);
         digitalWrite(11, LOW);
         digitalWrite(12, LOW);
         digitalWrite(13, HIGH);
       // delay(500);
  }
void Seg1Zero()
  {
         digitalWrite(4, HIGH); //high  voltage 
         //digitalWrite(1, LOW); //high  voltage 
        ///digitalWrite(2, LOW); //high  voltage 
        // digitalWrite(3, LOW); //high  voltage 

          digitalWrite(7, LOW); //gournf
         digitalWrite(8, LOW); //gournf
         digitalWrite(9, LOW);
         digitalWrite(10, LOW);
         digitalWrite(11, LOW);
         digitalWrite(12, LOW);
         digitalWrite(13, HIGH);
        //delay(500);
  }
void Seg1One()
  {
         digitalWrite(4, HIGH); //high  voltage 
         //digitalWrite(1, LOW); //high  voltage 
        //digitalWrite(2, LOW); //high  voltage 
         //digitalWrite(3, LOW); //high  voltage 

          digitalWrite(7, HIGH); //gournf
         digitalWrite(8, LOW); //gournf
         digitalWrite(9, LOW);
         digitalWrite(10, HIGH);
         digitalWrite(11, HIGH);
         digitalWrite(12, HIGH);
         digitalWrite(13, HIGH);
        delay(500);
  }
void Seg1Two()
  {
         digitalWrite(4, HIGH); //high  voltage 
         //digitalWrite(1, LOW); //high  voltage 
        //digitalWrite(2, LOW); //high  voltage 
         //digitalWrite(3, LOW); //high  voltage 

          digitalWrite(7, LOW); //gournf
         digitalWrite(8, LOW); //gournf
         digitalWrite(9, HIGH);
         digitalWrite(10, LOW);
         digitalWrite(11, LOW);
         digitalWrite(12, HIGH);
         digitalWrite(13, LOW);
        delay(500);
  }

  void Seg1Three()
  {
         digitalWrite(4, HIGH); //high  voltage 
         //digitalWrite(1, LOW); //high  voltage 
        //digitalWrite(2, LOW); //high  voltage 
         //digitalWrite(3, LOW); //high  voltage 

          digitalWrite(7, LOW); //gournf
         digitalWrite(8, LOW); //gournf
         digitalWrite(9, LOW);
         digitalWrite(10, LOW);
         digitalWrite(11, HIGH);
         digitalWrite(12, HIGH);
         digitalWrite(13, LOW);
        delay(500);
  }

 void Seg1Four()
  {
         digitalWrite(4, HIGH); //high  voltage 
        // digitalWrite(1, LOW); //high  voltage 
       // digitalWrite(2, LOW); //high  voltage 
       //  digitalWrite(3, LOW); //high  voltage 

          digitalWrite(7, HIGH); //gournf
         digitalWrite(8, LOW); //gournf
         digitalWrite(9, LOW);
         digitalWrite(10, HIGH);
         digitalWrite(11, HIGH);
         digitalWrite(12, LOW);
         digitalWrite(13, LOW);
        delay(500);
  }
 void Seg1Five()
  {
         digitalWrite(4, HIGH); //high  voltage 
        // digitalWrite(1, LOW); //high  voltage 
        //digitalWrite(2, LOW); //high  voltage 
        // digitalWrite(3, LOW); //high  voltage 

          digitalWrite(7, LOW); //gournf
         digitalWrite(8, HIGH); //gournf
         digitalWrite(9, LOW);
         digitalWrite(10, LOW);
         digitalWrite(11, HIGH);
         digitalWrite(12, LOW);
         digitalWrite(13, LOW);
        delay(500);
  }
  void Seg1Six()
  {
         digitalWrite(4, HIGH); //high  voltage 
        // digitalWrite(1, LOW); //high  voltage 
       // digitalWrite(2, LOW); //high  voltage 
         //digitalWrite(3, LOW); //high  voltage 

          digitalWrite(7, LOW); //gournf
         digitalWrite(8, HIGH); //gournf
         digitalWrite(9, LOW);
         digitalWrite(10, LOW);
         digitalWrite(11, LOW);
         digitalWrite(12, LOW);
         digitalWrite(13, LOW);
        delay(500);
  }
  void Seg1Seven()
  {
         digitalWrite(4, HIGH); //high  voltage 
         //digitalWrite(1, LOW); //high  voltage 
       // digitalWrite(2, LOW); //high  voltage 
        // digitalWrite(3, LOW); //high  voltage 

          digitalWrite(7, LOW); //gournf
         digitalWrite(8, LOW); //gournf
         digitalWrite(9, LOW);
         digitalWrite(10, HIGH);
         digitalWrite(11, HIGH);
         digitalWrite(12, HIGH);
         digitalWrite(13, HIGH);
        delay(500);
  }

  void Seg1Eight()
  {
         digitalWrite(4, HIGH); //high  voltage 
         //digitalWrite(1, LOW); //high  voltage 
        //digitalWrite(2, LOW); //high  voltage 
         //digitalWrite(3, LOW); //high  voltage 

          digitalWrite(7, LOW); //gournf
         digitalWrite(8, LOW); //gournf
         digitalWrite(9, LOW);
         digitalWrite(10, LOW);
         digitalWrite(11, LOW);
         digitalWrite(12, LOW);
         digitalWrite(13, LOW);
        delay(500);
  }

  void Seg1Nine()
  {
         digitalWrite(4, HIGH); //high  voltage 
         //digitalWrite(1, LOW); //high  voltage 
       // digitalWrite(2, LOW); //high  voltage 
        // digitalWrite(3, LOW); //high  voltage 

          digitalWrite(7, LOW); //gournf
         digitalWrite(8, LOW); //gournf
         digitalWrite(9, LOW);
         digitalWrite(10, LOW);
         digitalWrite(11, HIGH);
         digitalWrite(12, LOW);
         digitalWrite(13, LOW);
        delay(500);
  }
  
void loop() {

   if(counter == 0){
   
      Seg1Zero();   
     
    }
   if(counter == 1)
    {
        //   Seg2Zero();
           Seg1One();

    }

    if (counter ==2){
    Seg1Two();
    }
    if (counter ==3){
    Seg1Three();
    }

   if (counter ==4){
    Seg1Four();
    }
 if (counter ==5){
    Seg1Five();
    }
  if (counter ==6){
    Seg1Six();
    }
  if (counter ==7){
    Seg1Seven();
    }
   if (counter ==8){
    Seg1Eight();
    }
    if (counter ==9){
    Seg1Nine();
    }
   
  //case 1: light the correct segments when you One (1)
  
          
  //case 9: light the correct segments when you One (9)    
        

  delay(1000);
  counter++;

   
  // count from 0 to 9
  if(counter==10)
    counter=0;


}

