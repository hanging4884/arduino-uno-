
 

int in1=7;

int in2=5;

int as=0;

 

 

 

byte speed =255;

 

 

 

void setup(){

  

  Serial.begin(9600);

  pinMode(in1,OUTPUT);

  pinMode(in2,OUTPUT);

 

 

  

}

 

void loop(){

 

if(Serial.available())

{ 

  char data=Serial.read();

 

 

if(data == '1')

{

  Serial.write("a");

  digitalWrite(in1, HIGH);

  digitalWrite(in2, LOW);

}

else if(data == '2')

{

  Serial.write("b");

  digitalWrite(in1, LOW);

  digitalWrite(in2, HIGH);

}

else

{
  Serial.write("x");
    digitalWrite(in1, LOW);

    digitalWrite(in2, LOW);

  

}

}

 

 

}

 

 

 

 

 

 



