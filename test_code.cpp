#include <Servo.h>

// Create Servo objects for each joint
Servo arm;
Servo gripperAssembly;
Servo gripper;

// Servo pins
const int ARM_PIN = 6;
const int ASSEMBLY_PIN = 5;
const int GRIPPER_PIN = 9;

// Servo test positions
int testPositions[] = {0, 45, 90, 135, 180};

void setup() {
  // Attach servos to pins
  arm.attach(ARM_PIN);
  gripperAssembly.attach(ASSEMBLY_PIN);
  gripper.attach(GRIPPER_PIN);

  // Set safe initial positions
  arm.write(90);
  gripperAssembly.write(90);
  gripper.write(0);
  delay(1000); // Allow servos to reach starting positions
}

void loop() {
  // Test arm servo
  for (int i = 0; i < 5; i++) {
    arm.write(testPositions[i]);
    delay(500);
  }
  
  // Test gripper assembly servo
  for (int i = 0; i < 5; i++) {
    gripperAssembly.write(testPositions[i]);
    delay(500);
  }
  
  // Test gripper servo
  for (int i = 0; i < 5; i++) {
    gripper.write(testPositions[i]);
    delay(500);
  }

  // Return to safe positions
  arm.write(90);
  gripperAssembly.write(90);
  gripper.write(0);
  delay(2000); // Pause before repeating the test
}
