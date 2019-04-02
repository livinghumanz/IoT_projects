


/*
 * 
 * GSM            arduino
 * rx **************10
 * tx **************09
 * gnd**************gnd
 *
 */
 
 #include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);//tx,rx

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  Serial.print("insideif");
  if (Serial.available()>0)
  
   switch('s')
  {
    case 's':
    Serial.print("inside case");
      mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918667846184\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("HEI mr,THIS IS FROM GSM");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
      break;



      
    case 'r':
      mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
      delay(1000);
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}
