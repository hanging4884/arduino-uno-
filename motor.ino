void setup() {
    pinMode(9, OUTPUT); //좌회전
    pinMode(8, OUTPUT); //우회전

}



void loop() {

  

 

  digitalWrite(9, HIGH);       

  digitalWrite(8, LOW);

  delay(2000);            
  
  digitalWrite(8, HIGH);       

  digitalWrite(9, LOW);

  delay(2000);                     
 

} 