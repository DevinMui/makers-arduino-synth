byte sine[] = {127, 134, 142, 150, 158, 166, 173, 181, 188, 195, 201, 207, 213, 219, 224, 229, 234, 238, 241, 245, 247, 250, 251, 252, 253, 254, 253, 252, 251, 250, 247, 245, 241, 238, 234, 229, 224, 219, 213, 207, 201, 195, 188, 181, 173, 166, 158, 150, 142, 134, 127, 119, 111, 103, 95, 87, 80, 72, 65, 58, 52, 46, 40, 34, 29, 24, 19, 15, 12, 8, 6, 3, 2, 1, 0, 0, 0, 1, 2, 3, 6, 8, 12, 15, 19, 24, 29, 34, 40, 46, 52, 58, 65, 72, 80, 87, 95, 103, 111, 119,};

void square(int d) {
  PORTD = 255;
  delay(d);
  PORTD = 0;
  delay(d);
}

void sinewave() {
  for(int i=0;i<50;i++){
    PORTD = sine[i];  
  }  
}

void sawtooth() {
  for(int i=255;i>=0;i--){
    PORTD = i;
    delayMicroseconds(50);
//    Serial.println(analogRead(A0));
  }  
}

void setup(){
  Serial.begin(9600);
  //set digital pins 0-7 as outputs
  for (int i=0;i<8;i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  sawtooth();
}
