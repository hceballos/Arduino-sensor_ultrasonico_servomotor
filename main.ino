#include <Servo.h>

#define PIN_LED_RED 13
#define PIN_LED_GREEN 12
#define PIN_SERVO 8
#define PIN_ULTRASOUND_SENSOR 10
#define SENSOR_TIMEOUT 500

Servo servo;

long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT);

  digitalWrite(pin, LOW);
  delayMicroseconds(2);

  digitalWrite(pin, HIGH);
  delayMicroseconds(PIN_ULTRASOUND_SENSOR);

  digitalWrite(pin, LOW);

  pinMode(pin, INPUT);

  return pulseIn(pin, HIGH, SENSOR_TIMEOUT);
}

void setup()
{
  servo.attach(PIN_SERVO);

  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
}

void loop()
{
  if (readUltrasonicDistance(PIN_ULTRASOUND_SENSOR) > SENSOR_TIMEOUT * 0.9) {
    digitalWrite(PIN_LED_RED, HIGH);
    servo.write(90);
    digitalWrite(PIN_LED_GREEN, LOW);
  } else {
    digitalWrite(PIN_LED_RED, LOW);
    servo.write(0);
    digitalWrite(PIN_LED_GREEN, HIGH);
  }
  delay(10);
}
