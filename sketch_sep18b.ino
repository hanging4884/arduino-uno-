#define trigPin 4

#define echoPin 3

 

int in1=7;

int in2=8;

int as=0;

 

 #include <DHT.h>

#include "SPI.h"

#include "Phpoc.h"

#include "ThingSpeak.h"

PhpocServer server(80);

 

#define APIKEY "UIFR0ZYOD8ICCQPW"   

unsigned long myChannelNumber=577861;

 

PhpocClient client;

 

 

long duration, distance;

 

void setup(){

  

  Serial.begin(9600);

  pinMode(in1,OUTPUT);

  pinMode(in2,OUTPUT);

    pinMode(trigPin, OUTPUT); 

    pinMode(echoPin, INPUT);

    delay(1000);

 while(!Serial);    

  Phpoc.begin(PF_LOG_SPI | PF_LOG_NET | PF_LOG_APP);

  Serial.print("WebSocket server address : ");

  Serial.println(Phpoc.localIP());  

  ThingSpeak.begin(client);

  

}

 

void loop(){

    digitalWrite(trigPin, HIGH);

    delay(10);

    digitalWrite(trigPin, LOW);

 

    duration = pulseIn(echoPin, HIGH);

    distance = (duration/2) / 29.1;

 


  char data=Serial.read();

 Serial.println(distance);

  

      ThingSpeak.setField(1,distance);

      ThingSpeak.writeFields(myChannelNumber, APIKEY);

  
 

if(distance < 10)

{

  digitalWrite(in1, HIGH);

  digitalWrite(in2, LOW);

}



else

{

    digitalWrite(in1, LOW);

    digitalWrite(in2, LOW);

  

}


 

 delay(300);

}