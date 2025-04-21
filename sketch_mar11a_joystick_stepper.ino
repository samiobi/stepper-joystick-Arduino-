
#include <Stepper.h>

const int stepsPerRevolution = 500;  //     عدد الدرجات في الدورة الواحدة

Stepper myStepper(stepsPerRevolution, 2, 3); // ربط المنافذ

void setup() {

  Serial.begin(9600); //تشغيل خاصية السريل 
}

void loop() {

 int sensorValue = analogRead(A0);

 if (sensorValue > 600){
  int s  = map(sensorValue, 600, 1023, 100, 500);  
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  myStepper.setSpeed(s);
  
  
 }
 if (sensorValue < 400){
 int s  = map(sensorValue, 400, 0, 100, 500);
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  myStepper.setSpeed(s);
}
else {
   Serial.println("no rotation");
  
}
}
