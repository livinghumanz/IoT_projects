
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 5);  //Rx,Tx

/*
 * Red: RA (Right Arm)
 * Yellow: LA (Left Arm)
 * Green: RL (Right Leg)
 * 
 */
//output(ecg)== A0

//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30;       
 
//the time when the sensor outputs a low impulse
long unsigned int lowIn;        
 
//the amount of milliseconds the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000; 
 
boolean lockLow = true;
boolean takeLowTime; 
 
int pirPin = 3;    //the digital pin connected to the PIR sensor's output
int PulseSensorPurplePin = A1;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN A!
int LED13 = 13;   //  The on-board Arduion LED
int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 646;            // Determine which Signal to "count as a beat", and which to ingore.
float temp;
int buz = 8;
String text;

void setup() {
// initialize the serial communication:
digitalWrite(buz,LOW);
mySerial.begin(9600);
pinMode(LED13,OUTPUT);
pinMode(buz,OUTPUT);
Serial.begin(4800);
pinMode(10, INPUT); // Setup for leads off detection LO +
pinMode(11, INPUT); // Setup for leads off detection LO -
lcd.init();
lcd.init();
lcd.backlight();
//lcd.print("hello");
pinMode(pirPin, INPUT);
//  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
 
  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
}

void loop() {

pir();

  Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value.
                                            // Assign this value to the "Signal" variable.

  temp=analogRead(A2);                       // temperature sensor
  // convert to deg cent
  temp=(temp*0.48828125)*(9/5)+32;
  lcd.setCursor(0,0);
  text=String(temp) + "*F";
  lcd.print(text);
  if(temp<50 || temp>95)
  {
    digitalWrite(buz,HIGH);
    delay(5);
    digitalWrite(buz,LOW);
    delay(5);
    digitalWrite(buz,HIGH);
    
  }
 
  Serial.print("pulse-->");
  Serial.print(Signal);                    // Send the Signal value to Serial Plotter.
  if(Signal > Threshold)
  {                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
     digitalWrite(LED13,HIGH);
   } 
   else 
   {
     digitalWrite(LED13,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.
   }

//   lc=(lc+1)%60;
  if((digitalRead(10) == 1)||(digitalRead(11) == 1))
  {
    
    Serial.println(0);
  }
  else
  {
    // send the value of analog input 0:
    //for ecg(9600)
    //Serial.begin(9600);
    Serial.print(" ");
    Serial.print("ECG-->");
    Serial.println(analogRead(A0));
   }
  //Wait for a bit to keep serial data from saturating
  delay(1);
  digitalWrite(buz,LOW);
}

 

void pir(){
 
     if(digitalRead(pirPin) == HIGH){
         //the led visualizes the sensors output pin state
       if(lockLow){ 
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;           
         lcd.setCursor(0,1);
       lcd.print("movement is present......");
       digitalWrite(LED13,HIGH);
       sendmessage("movement is present");
         delay(50);
         }        
         takeLowTime = true;
       }
 
     if(digitalRead(pirPin) == LOW){      
       //digitalWrite(ledPin, LOW);  //the led visualizes the sensors output pin state
 
       if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause,
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause){ 
           //makes sure this block of code is only executed again after
           //a new motion sequence has been detected
           lockLow = true;                       
           lcd.setCursor(0,1);
       lcd.print("movement ended......");
       digitalWrite(LED13,LOW);
       sendmessage("movement ended");
       
           delay(50);
           }
       }
  }
  void sendmessage(String message)
  {
    Serial.println("inside gsm");
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+919094577694\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println(message);// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
//      break;

  }
