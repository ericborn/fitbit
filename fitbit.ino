//Includes the Arduino Stepper Library
#include <Stepper.h>

// Time library
#include <Wire.h>
#include <DS3231.h>

// Create clock object
RTClib myRTC;

// Defines the number of steps per rotation
const int stepsPerRevolution = 2800;

// define start and end time
const int startTime = 10;
const int endTime = 13;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

// function to check the current time and if between
void checkTime () {
  DateTime now = myRTC.now();
  //Serial.println(now.hour());
  if (now.hour() >= startTime && now.hour() < endTime) {
    Serial.println("Between 11 and 13");
    // Step one revolution in one direction:
    //Serial.println("clockwise");
    myStepper.step(stepsPerRevolution);
  }
  else {
    Serial.println("Not time");
    //delay(60000);
  }
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  myStepper.setSpeed(10);
}

void loop() {
  // run checkTime which activates the stepper if its in the time range
  checkTime();
}
