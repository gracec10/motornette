#include <ESP32Servo.h>

//data received from serial port
char val;

//servos
Servo LLServo;
Servo RLServo;
Servo LAServo;
Servo RAServo;  

void setup() {
  Serial.begin(115200);

  //pins
  LLServo.attach(13);
  RLServo.attach(12);
  LAServo.attach(15);
  RAServo.attach(14);

  //initial positioning
  LLServo.write(0);  
  RLServo.write(0);
  LAServo.write(0);
  RAServo.write(0);
}

void loop(){
  if (Serial.available()) {
    val = Serial.read();
  }
  
//left arm
  if (val == '1'){
    LAServo.write(180);
    delay(500);
    LAServo.write(0);
    delay(300);
  }

//right arm
  if (val == '2'){
    RAServo.write(180);
    delay(500);
    RAServo.write(0);
    delay(300);
  }

//right leg
  if (val == '3'){
    RLServo.write(180);
    delay(500);
    RLServo.write(0);
    delay(300);
  }

//left leg
  if (val == '4'){
    LLServo.write(180);  
    delay(500);
    LLServo.write(0);
    delay(300);
  }

//stop
  if (val == '0'){
    LLServo.write(0);  
    RLServo.write(0);
    LAServo.write(0);
    RAServo.write(0);
  }
}
