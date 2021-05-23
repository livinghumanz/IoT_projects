//master : +ADDR:FCA8:9A:DF2
//Slave : +ADDR:18:E4:400006


/*long peaklim=1980
int vs =9; // vibration sensor
 
void setup(){
//  pinMode(led, OUTPUT);
  pinMode(vs, INPUT); 
  Serial.begin(9600); 
 
}
void loop(){
  long measurement =vibration();
  Serial.println(measurement);
 
}
 
long vibration(){
  long measurement=pulseIn (vs, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}
*/
int ByteReceived;
int button = 2;
void setup()   /****** SETUP: RUNS ONCE *****/
{
  Serial.begin(9600);  
  pinMode(button,INPUT);
  digitalWrite(button,HIGH);
}
//--(end setup )---

void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
/* if (Serial.available() > 0)
  {
    ByteReceived = Serial.read();
    Serial.print("you pressed");
    Serial.print(ByteReceived);      
    Serial.println(char(ByteReceived));   
    delay(1000);

  }*/
   
  if(digitalRead(button)==HIGH)
    Serial.write("0");
  else
    Serial.write("1");
    delay(2000);
  /*if(bs==HIGH)
    Serial.write("1");
  else
    Serial.write("0");*/
}
