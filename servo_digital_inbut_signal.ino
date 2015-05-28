
#include <Servo.h> 

// ---- button configration ----
const int buttonPin1 = 22; 
const int buttonPin2 = 24;
const int buttonPin3 = 26; 
const int buttonPin4 = 28;
const int buttonPin5 = 30;
const int buttonPin6 = 32;
const int buttonPin7 = 34;
const int buttonPin8 = 36;


int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;
int buttonState8 = 0;

//---- servo configration ----

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo 
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo 
Servo myservo5;  // create servo object to control a servo
Servo myservo6;  // create servo object to control a servo 
 
//----- throtel configration -----

int potpin = 0;  // analog pin used to connect the potentiometer
int val = 0 ;    // variable to read the value from the analog pin 
int valup = 0;
int valdwn = 0;
void setup() 
{ 
  // ---- button setup ----

   pinMode(buttonPin1, INPUT);
   pinMode(buttonPin2, INPUT);
   pinMode(buttonPin3, INPUT);
   pinMode(buttonPin4, INPUT);
   pinMode(buttonPin5, INPUT);
   pinMode(buttonPin6, INPUT);
   pinMode(buttonPin7, INPUT);
   pinMode(buttonPin8, INPUT);
   
   
  //---- servo setup ----
  
   myservo1.attach(2);  // attaches the servo on pin 9 to the servo object 
   myservo2.attach(3);  // attaches the servo on pin 9 to the servo object 
   myservo3.attach(4);  // attaches the servo on pin 9 to the servo object 
   myservo4.attach(5);  // attaches the servo on pin 9 to the servo object
   myservo5.attach(6);  // attaches the servo on pin 9 to the servo object 
   myservo6.attach(7); 
   Serial.begin(9600); 
} 
 
void loop() {

  //----- throtel loop -----


  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  valup = analogRead(potpin);  // reads the value of the potentiometer (value between 0 and 1023) 
  valdwn = analogRead(potpin);  // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 600, 0, 200);     // scale it to use it with the servo (value between 0 and 180)
  valup = map(valup, 0, 1023, 95, 150);     // scale it to use it with the servo (value between 0 and 180)
  valdwn = map(valdwn, 0, 1023, 95, 40);    // scale it to use it with the servo (value between 0 and 180)

 
 // ---- button loop ----

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  buttonState7 = digitalRead(buttonPin7);
  buttonState8 = digitalRead(buttonPin8);

// ---- conditions ----

/*Serial.println(val);
Serial.println(valup);
Serial.println(valdwn);
delay(1000);*/

/*
Serial.print(buttonState1);
Serial.print(buttonState2);
Serial.print(buttonState3);
Serial.print(buttonState4);
Serial.print(buttonState5);
Serial.print(buttonState6);
Serial.print(buttonState7);
Serial.print(buttonState8);
Serial.println(val);


delay(1000);
*/



if (buttonState1 == HIGH) { 
 
 myservo1.write(valup);
 myservo2.write(valup);  
 delay(15);    
 
                         } 
 else if (buttonState2 == HIGH) { 
  
 myservo1.write(valdwn);
 myservo2.write(valdwn);  
 delay(15);      

                                 }
                         
 else if (buttonState3 == HIGH ) { 

 myservo3.write(val);
 myservo4.write(val);  
 delay(15);    

                         } 
                         
 else if (buttonState4 == HIGH) { 
 
 myservo5.write(val);
 myservo6.write(val);  
 delay(15);      
                        }
else if (buttonState5 == HIGH) { 
 
 myservo4.write(val);
 myservo6.write(val);  
 delay(15);      
                        }  
  else if (buttonState6 == HIGH) { 
 
 myservo3.write(val);
 myservo5.write(val);  
 delay(15);      
                        } 
  else if (buttonState7 == HIGH) { 
 
 myservo4.write(val);
 myservo5.write(val);  
 delay(15);      
                        }  
   else if (buttonState8 == HIGH) { 
 
 myservo3.write(val);
 myservo6.write(val);  
 delay(15);      
                        }                      
                                 
 else {
 myservo1.write(94);
 myservo2.write(94);  
 myservo3.write(30);
 myservo4.write(30); 
 myservo5.write(30);
 myservo6.write(30);  
  delay(15);                           
        }
           }
