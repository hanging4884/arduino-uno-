#define trigPin 2
#define echoPin 3
#include "SPI.h"
#include "Phpoc.h"

PhpocServer server(80);
PhpocEmail email;
PhpocClient client = server.available();

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  Serial.begin (9600);
  while(!Serial); 
  Phpoc.begin(PF_LOG_SPI | PF_LOG_NET | PF_LOG_APP);
  //Phpoc.begin();

  server.beginWebSocket("remote_push");

  Serial.print("WebSocket server address : ");
  Serial.println(Phpoc.localIP());  

    Serial.println("Sending email to server directly");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long distance=pulseIn(echoPin, HIGH)/58.2;
  Serial.println(distance);
  
  delay(1000);
   // wait for a new client:
  PhpocClient client = server.available();

 

      if(distance>=200){
          email.setFrom("email", "YCH");
  email.setTo("email", "YCH");
  email.setSubject("Mail from PHPoC Shield for Arduino");

      }

  if(email.send() > 0) {
    Serial.println("Email send ok");}
else   
  {
    Serial.println("Email send failed");

  }
}
  
