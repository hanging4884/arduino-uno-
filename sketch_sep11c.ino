int LED=3;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
  for(int i=255;i<256;i++){
    analogWrite(LED, i);
    Serial.println(i);
    delay(10);
  }
    for(int i=256; i>=0;i--){
    analogWrite(LED, i);
    Serial.println(i);
    delay(10);
    }
}
