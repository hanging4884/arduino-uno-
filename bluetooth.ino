  #include <SoftwareSerial.h>
  #define LED_PIN 4
  #define BTtx 2
  #define BTtx 3
  
  
  SoftwareSerial BT (BTtx,BTtx);
  char data=0;
  
  
  void setup(){
    Bt.begin(9600);
    Serial.begin(9600);
    pinMode(LED_PIN,OUTPUT);
  }
  
  
  
  
  
  
  
  void loop()
    if(BT.available()>0){
      data= BT.read();    
    }
    if (data=='0'){
      digitalWrite(LED_PIN,LOW);
      Serial.println("LED_OFF");
    }
    if (data=='1'){
      digitalWrite(LED_PIN,HIGH);
      Serial.println("LED_ON");
    }
    data=0;
    }