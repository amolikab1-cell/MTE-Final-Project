#include <Servo.h>

// Create Servo objects
Servo arm;
Servo gripperAssembly;
Servo gripper;

// Define pins
const int ARM = 6;
const int GRIPPER_MOVER = 5;
const int GRIPPER_PIN = 9;

void setup() {
  Serial.begin(9600);

  arm.attach(ARM);
  gripperAssembly.attach(GRIPPER_MOVER);
  gripper.attach(GRIPPER_PIN);

  // Set safe initial positions
  arm.write(90);
  gripperAssembly.write(90);
  gripper.write(0);
  delay(500); // Allow servos to reach positions
}

void loop() {
  if (Serial.available()) {
    String line = Serial.readStringUntil('\n');
    line.trim();

    int sep = line.indexOf(':');
    if (sep > 0) {
      String name = line.substring(0, sep);
      int angle = line.substring(sep + 1).toInt();
      angle = constrain(angle, 0, 180); // Ensure safe angles

      if (name.equalsIgnoreCase("arm")) {
        arm.write(angle);
      } 
      else if (name.equalsIgnoreCase("gripper_assembly")) {
        gripperAssembly.write(angle);
      } 
      else if (name.equalsIgnoreCase("gripper")) {
        gripper.write(angle);
      }



      delay(15); 
    }
  }
}
