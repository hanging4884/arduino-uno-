/* arduino web server - remote control (push button) */

#include "SPI.h"
#include "Phpoc.h"

PhpocServer server(80);
PhpocEmail email;
PhpocClient client = server.available();

void setup() {
  Serial.begin(9600);
  while(!Serial)
    ;

  Phpoc.begin(PF_LOG_SPI | PF_LOG_NET | PF_LOG_APP);
  //Phpoc.begin();

  server.beginWebSocket("remote_push");

  Serial.print("WebSocket server address : ");
  Serial.println(Phpoc.localIP());  

    Serial.println("Sending email to server directly");

    // setup From/To/Subject
  
    
}



void loop() {
  // wait for a new client:
  PhpocClient client = server.available();

  if (client) {
    if (client.available() > 0) {
      // read the bytes incoming from the client:
      char thisChar = client.read();

      if(thisChar == 'A'){
         Serial.println("button A press");
          email.setFrom("gmlsl100wja@naver.com", "YCH");
  email.setTo("gmlsl100wja@naver.com", "YCH");
  email.setSubject("Mail from PHPoC Shield for Arduino");



  if(email.send() > 0)
    Serial.println("Email send ok");
  else
    Serial.println("Email send failed");

          email.println("A");
  email.endMessage();
  }
      if(thisChar == 'a')
         Serial.println("button a release");
          email.beginMessage();
          email.println("a");
  email.endMessage();
      if(thisChar == 'B')
         Serial.println("button B press");
          email.beginMessage();
          email.println("Hello, world!");
email.endMessage();
      if(thisChar == 'b')
         Serial.println("button b release");
          email.beginMessage();
          email.println("Hello, world!");
  email.endMessage();
      if(thisChar == 'C')
         Serial.println("button C press");
          email.beginMessage();
          email.println("Hello, world!");
  email.endMessage();
      if(thisChar == 'c')
         Serial.println("button c release");
          email.beginMessage();
          email.println("Hello, world!");
  email.endMessage();
    }
  }
}
