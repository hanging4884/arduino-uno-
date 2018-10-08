int led1 = 8;
int led2 = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
  /*digitalWrite(led1,HIGH);
  delay(390);
  digitalWrite(led2,HIGH);
  delay(100);
  digitalWrite(led1,LOW);
  delay(390);
  digitalWrite(led2,LOW);
  delay(100);*/
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  delay(500);
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  delay(500);
  
  // put your main code here, to run repeatedly:

}
