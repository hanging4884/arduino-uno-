#include "DHT.h"
#define dhtpin 2
#define dhttype DHT11
DHT dht(dhtpin, dhttype);
int LED=8;
void setup() {
 Serial.begin(9600);
 pinMode(LED, OUTPUT);
 dht.begin();
}

void loop() {
  float t=dht.readTemperature();
  float h=dht.readHumidity();


  Serial.print("Temperature is ");
  Serial.print(t);
  Serial.println(" C");
  Serial.print("humdity is ");
  Serial.print(h);
  Serial.println(" %");
  delay(1000);
  if(h>70){
    digitalWrite(LED, HIGH);
    delay(1000);
    }else{
    digitalWrite(LED, LOW);
      delay(1000);
    }
}
