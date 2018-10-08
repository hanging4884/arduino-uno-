#define trigPin 8 
#define echoPin 7 
#define buzzPin 4
#define PIR 10
#define LED 6

long duration, distance;

void setup(){
   pinMode(PIR,INPUT);
   pinMode(LED,OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
 
  
  delay(1000);
  
  Serial.println("Radiar ready!!");
  delay(500);
  
}  
  void loop()
{
 
  
  
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  
  
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;
  
  Serial.print(distance);
  Serial.print("cm");
  
  if (distance<=20)
  {
    digitalWrite(buzzPin,HIGH);
    delay(500);
    digitalWrite(buzzPin,LOW);
    delay(500);
  }
  else{
    digitalWrite(buzzPin,HIGH);
    delay(250);
    digitalWrite(buzzPin,LOW);
    delay(250);
  }
}