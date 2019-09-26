#include <Servo.h>

Servo servo;
int angulo = 0;

void setup() {
  
  servo.attach(2);
  servo.write(0);
  Serial.begin(9600);

}

void loop() {

  angulo = map(analogRead(A0), 0, 1023, 0, 180);
//  angulo = constrain(angulo, 0, 180);
  Serial.println(angulo);
  servo.write(angulo);
  delay(25);
  
}
