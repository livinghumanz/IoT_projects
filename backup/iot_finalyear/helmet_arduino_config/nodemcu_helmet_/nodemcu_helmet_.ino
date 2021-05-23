
#include<FirebaseArduino.h>
#include <ESP8266WiFi.h>

// set finger print using host link in FirebaseHttpClient.h                         
#define FIREBASE_HOST "sample-8f1fd.firebaseio.com"                          // database URL 
#define FIREBASE_AUTH "mVeoMTLE2XbGrHhpiS2N9UfzRJSDBZExcEPKXzRl"             // secret key

#define WIFI_SSID "pi"                                           
#define WIFI_PASSWORD "abcdefgh"   
  

#define vib A0
  int val=0;

void setup() {
  pinMode(vib,INPUT);

  Serial.begin(9600);

  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);


  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase
delay(1000);
}

void loop() { 

  val=analogRead(vib);

// Firebase Error Handling ************************************************
  if (Firebase.failed())
  { delay(500);
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Serial.println(Firebase.error());
  Serial.println("Connection to fiebase failed. Reconnecting...");
  delay(500);
  }
  
 else { 
    Serial.println("Everything is ready!");
    delay(300); Serial.println("Everything is ready!");
    delay(300); Serial.println("Everything is ready! \n \n \n");
    delay(300);


    Firebase.setInt("/vibration2",val);
   Serial.println(val);
    delay(300); Serial.println("uploaded vibration val to firebase \n \n \n");

   
 }



  
}
