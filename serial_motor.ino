const int AIA = 3; 
const int AIB = 4; 
const int BIA = 5; 
const int BIB = 6; 
byte speed = 255; 
int cnt = 0; 
byte bbb; 
String myString;
void forward() 
{
  analogWrite(AIA, 0); 
analogWrite(AIB, speed);
analogWrite(BIA, 0); 
analogWrite(BIB, speed); 
  
}
void backward() 
{ 
  analogWrite(AIA, speed); 
  analogWrite(AIB, 0); 
  analogWrite(BIA, speed); 
  analogWrite(BIB, 0); 
  
} void setup() 
{
  pinMode(AIA, OUTPUT); 
  pinMode(AIB, OUTPUT); 
  pinMode(BIA, OUTPUT); 
  pinMode(BIB, OUTPUT); 
  Serial.begin(9600); }
void loop()
{ 
  while (Serial.available())
  {
    char myChar = (char)Serial.read();
    myString += myChar;
    delay(05); 
    
  } 
  if (!myString.equals(""))
  { 
    Serial.println("Input Value : " + myString);
    int ccc = myString.toInt();
    speed = (byte)ccc; myString = "";
    } 
    forward(); 
    delay(2000);
    backward(); 
    delay(2000); }