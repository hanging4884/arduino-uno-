#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);



char cmd;

int Pin = 8;
int Buzz = 7;


void setup()

{

    Serial.begin(9600);

    delay(100);

    BTSerial.begin(9600);

    pinMode(Pin, OUTPUT);
    pinMode(Buzz, OUTPUT);

}


void loop()

{

    if(BTSerial.available())

    {

      cmd = BTSerial.read();

      Serial.print("Command = ");

      Serial.println(cmd);

    

    if(cmd == '1') {

        Serial.println("LED ON");

        digitalWrite(Pin, HIGH);

    }

    if(cmd == '0') {

        Serial.println("LED OFF");

        digitalWrite(Pin, LOW);

    } 
    if(cmd == '3') {

        Serial.println("Buzz ON");

        digitalWrite(Buzz, HIGH);

}
if(cmd == '2') {

        Serial.println("Buzz off");

        digitalWrite(Buzz, LOW);

}

}


}