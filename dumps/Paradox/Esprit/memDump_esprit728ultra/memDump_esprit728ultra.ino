#include <Wire.h>
#include <MyEEPROM.h>



void setup(){
  Wire.begin();
  Serial.begin(115200);
  
  Serial.println("Starting..."); 
  Serial.println(); 
}

void loop(){
  byte msg[3] = {0};
  msg[0]=0x46;

  MyEEPROM.write(0x03A, msg, 1);  
  delay(10);
  
  for (int i = 0; i < 2048; i++){
    if (i % 16 == 0) {
      Serial.println();
    }
    byte buffer[1] = {0};
    MyEEPROM.read(i, buffer, 1);

    if (i==58) {
      delay(30);
      MyEEPROM.write(0x058, msg, 1);  
      delay(30);
    }
   
    
    if (buffer[0] < 16) {
      Serial.print("0");
    }
    Serial.print(buffer[0], HEX);
    Serial.print(" ");

  }

  while(1) {}

}
