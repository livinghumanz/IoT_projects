int pos=7;
int neg=8;
char state;
void setup()
{
  pinMode(pos,OUTPUT);
  pinMode(neg,OUTPUT);
  Serial.begin(9600);
  Serial.print("began");
}

void loop()
{
  if(Serial.available()>0){
    Serial.print("iam in");
    state=Serial.read();
  }
  Serial.print(state);
  if(state=='1'){
  Serial.println("start movement");
  digitalWrite(pos,HIGH);
  digitalWrite(neg,LOW);
  delay(700);
  }
  else if(state=='0'){
  /*Serial.println("reverse");
  digitalWrite(neg,HIGH);
  digitalWrite(pos,LOW);
  delay(1000);*/
  Serial.println("stop");
  digitalWrite(pos,LOW);
  digitalWrite(neg,LOW);
  delay(1000);
  }
}
