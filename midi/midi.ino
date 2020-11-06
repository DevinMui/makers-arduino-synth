#include <SoftwareSerial.h>

SoftwareSerial midiSerial(8, 9); // RX, TX

byte noteOn = 144;
byte lick[] = {62, 64, 65, 67, 64, 60, 62};
int licksz = 7;
int index = 0;
int start = 0;

void setup(){
  Serial.begin(115200);
  midiSerial.begin(31250); 
  Serial.println("Serial has started");
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop(){
  if(midiSerial.available() > 2) {
    byte commandByte = midiSerial.read();
    byte noteByte = midiSerial.read();
    byte velocityByte = midiSerial.read();
    if(commandByte == noteOn){
      Serial.println(noteByte, HEX);
      if(index < licksz && noteByte == lick[index]){
        index++;
      } else if(noteByte == lick[0]){
        index = 1;
      } else if(index < licksz) index = 0;

      if(index == licksz){
        digitalWrite(13, HIGH);
        Serial.println("the licccc");
        index = 0;
        start = millis();
      }
    }
  }
  if(millis() - start > 5000){
    digitalWrite(13, LOW);
  }
}
