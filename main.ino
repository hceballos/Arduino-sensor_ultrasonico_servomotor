#include <Servo.h>

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);

  return pulseIn(echoPin, HIGH);
}

Servo servo_8;

void setup()
{
  pinMode(13, OUTPUT);
  servo_8.attach(8);

  pinMode(12, OUTPUT);
}

void loop()
{
  if (0.01723 * readUltrasonicDistance(10, 10) < 100) {
    digitalWrite(13, HIGH);
    servo_8.write(90);
    digitalWrite(12, LOW);
  } else {
    digitalWrite(13, LOW);
    servo_8.write(0);
    digitalWrite(12, HIGH);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
