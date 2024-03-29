import processing.serial.*;

Serial myPort;
String input;
char[] dance = {};

void setup() {
  // Use the Serial.list() printout to find the Serial location of your ESP32
  // Replace [11] in line 12 with the index that corresponds with your ESP32

  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[11], 115200);
}

void draw() {  
  if (myPort.available() > 0) {
    input = myPort.readString();
    println(input);
  }
}

void keyPressed() {
  //left arm
  if (keyCode == LEFT) {
    dance = append(dance, '1');
  }

  //right arm
  if (keyCode == RIGHT) {
    dance = append(dance, '2');
  }

  //left leg
  if (keyCode == UP) {
    dance = append(dance, '3');
  }

  //right leg
  if (keyCode == DOWN) {
    dance = append(dance, '4');
  }

  //end your dance
  if (keyCode == SHIFT) {
    dance = append(dance, '0');
    for (int i = 0; i < dance.length; i++) {
      print(dance[i]);
      myPort.write(dance[i]);
    }
  }
}
