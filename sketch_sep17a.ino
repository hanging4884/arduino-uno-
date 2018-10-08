void setup() {
Serial.begin(9600);
}
int cnt= 0;
byte bbb;
String msg= "";
String myString;
void loop() {
while (Serial.available())
{
char myChar= (char)Serial.read();
myString+= myChar;
delay(05);
}
if (!myString.equals(""))
{
Serial.println("Input Value : " + myString);
myString= "";
}
cnt= Serial.read();
bbb= byte(cnt++);
msg= String(bbb);
delay(3000);
}
