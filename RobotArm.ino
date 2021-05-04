#include<Servo.h>
Servo servo1, servo2, servo3, servo4;
void setup() {
  Serial.begin(9600);
  servo1.attach(11);
  servo2.attach(10);
  servo3.attach(9);
  servo4.attach(6);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
}

void loop() {
  int vrx1 = analogRead(A1); // vrx1
  int vry1 = analogRead(A2); // vry1
  int vry2 = analogRead(A4); // vry2
  int vrx2 = analogRead(A3); // vrx2;

  int baseRot = map(vrx1, 0, 1023, 0, 180);
  int BottomJoint = map(vry1, 0, 1023, 90, 180); 
  int TopJoint = map(vry2, 0, 1023, 90, 180);
  int claw = map(vrx2, 0, 1023, 90, 180); ;

  servo1.write(baseRot);
  servo2.write(BottomJoint);
  servo3.write(TopJoint);
  servo4.write(claw);
}
