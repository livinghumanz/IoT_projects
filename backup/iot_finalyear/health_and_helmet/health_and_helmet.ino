
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
 
 #include <SoftwareSerial.h>
 int valert=0;
 int vib;
 char a='A';
 int pulsevalue;
 int maxpval=analogRead(A0)-310;
 int maxtval=analogRead(A1)-30;
 int temp;
SoftwareSerial mySerial(5, 6);  //Rx,Tx
void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(30000);
 
}


void loop()
{
  vib=analogRead(A2);
   if((vib<1021 ||vib>24) &&valert==0){
    lcd.setCursor(0,1);
  lcd.print("vibration="+String(vib));
    sendsms();
    
    valert=1;
    delay(30000);
  }
  temp=analogRead(A1)-30;
  pulsevalue=analogRead(A0)-310;
  if(pulsevalue>maxpval ||pulsevalue<50){
  lcd.clear();
  maxpval=pulsevalue;
  lcd.setCursor(0,0);
  lcd.print("pls="+String(maxpval));
  }
  if(temp>maxtval || temp<40){
  lcd.setCursor(9,0);
  maxtval=temp;
  lcd.print("tmp="+String(maxtval));
  }
 
  
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918667763072\"\r"); // Replace x with mobile number
     delay(1000);
     String message="pulsevalue="+String(maxpval)+"  temperature="+String(maxtval);
     mySerial.println(message);// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
//      break;



      
   // case 'r':
      mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
      delay(1000);
      break;

 // }
    }

if (mySerial.available()>0)
   Serial.write(mySerial.read());
}
void sendsms()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918667763072\"\r"); // Replace x with mobile number
     delay(1000);
     //String message="pulsevalue="+String(maxpval)+"  temperature="+String(maxtval);
     mySerial.println("accident @ 13* 2'.44.34");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
}
