int led1 = 7;
int led2 = 6;

int key1 = 13;
int key2 = 12;

int key1_status=LOW;
int key2_status=LOW;

void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(key1, INPUT);
  pinMode(key2, INPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  if( digitalRead(key1) == HIGH  && key1_status==LOW)
  {
    digitalWrite(led1, HIGH);
    key1_status=HIGH;
  }
  else if(digitalRead(key1) ==HIGH && key1_status==HIGH)
  {
     digitalWrite(led1, LOW);
     key1_status=LOW;
  }
  if( digitalRead(key2) == HIGH && key2_status == LOW)
  {
      digitalWrite(led2, HIGH);
      key2_status = HIGH;
  }
  else if(digitalRead(key2) == HIGH && key2_status==HIGH)
  {
     digitalWrite(led2, LOW);
     key2_status = LOW;
  }
  delay(100);
}
