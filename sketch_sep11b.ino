int buzzer = 8;
void setup() 
{
  pinMode(buzzer, OUTPUT);
}

void loop() 
{
    digitalWrite(buzzer, HIGH); // Buzzer on
    delay(50);

    digitalWrite(buzzer, LOW); // Buzzer off
    delay(100);
}
