// By Sam Canonaco
// Based on examples by Matthew Heironimus
//-----------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  
  2, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  true, true, true);  // No accelerator, brake, or steering

int LMB_PIN = 2;
int RMB_PIN = 3;

int LMB_LVALUE= 0;
int RMB_LVALUE= 0;

int LMB_APIN = A0;
int RMB_APIN = A1;
int STEERING_APIN=A2;

int LMB_AVALUE = 128;
int RMB_AVALUE = 128;
int STEERING_AVALUE = 128;

void setup() {
  // Initialize Button Pins
  pinMode(LMB_PIN, INPUT_PULLUP);
  pinMode(RMB_PIN, INPUT_PULLUP);
 
  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setAcceleratorRange(0,256);
  Joystick.setBrakeRange(0,256);
  Joystick.setSteeringRange(0,256);

}

void loop() {

  // Read digital pin values
\
  int state = !digitalRead(LMB_PIN);
  if (state != LMB_LVALUE)
  {
    Joystick.setButton(0, state);
    LMB_LVALUE = state;
  }

  state = !digitalRead(RMB_PIN);
   if (state != RMB_LVALUE)
  {
    Joystick.setButton(1, state);
    RMB_LVALUE = state;
  }

  //Read analog pin values
  //Need to adjust based on sensors
  LMB_AVALUE = analogRead(LMB_APIN)/4;
  RMB_AVALUE = analogRead(RMB_APIN)/4;
  STEERING_AVALUE = analogRead(STEERING_APIN)/4;

  Joystick.setAccelerator(LMB_AVALUE);
  Joystick.setBrake(RMB_AVALUE);
  Joystick.setSteering(STEERING_AVALUE);
  
  delay(10);
}

