#include <Servo.h>

Servo myservo; 
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('/');
    Serial.println(command);
    if (command.endsWith("Rem da mo")){
      myservo.write(90);
    }
    if (command.endsWith("Rem da dong")) {
      myservo.write(0);
    }
  }
}