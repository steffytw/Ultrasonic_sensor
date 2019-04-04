int trigpin = 9;
int echopin = 10;
int led1 = 7;
int led2 = 8;
int led3 = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  long duration,distance;
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance); 
  Serial.println("CM");
  delay(10);
  if((distance<15))                            //red
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    }
    else if(distance>100)                       //yellow
    {
    
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
      }
      else                                      //green
      {
        digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
        }
  

}
