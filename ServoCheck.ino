#include <Servo.h>
int inches = 0;

int cm = 0;
int pos = 0;

Servo servo_10;
Servo servo_11;
Servo servo_6;
Servo servo_5;

void RunServo()
{
  for (pos = 0; pos <= 180; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_10.write(pos);
    servo_11.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_10.write(pos);
    servo_11.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
}
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}


void setup()
{
  Serial.begin(9600);
  servo_10.attach(10, 500, 2500);
  servo_11.attach(11, 500, 2500);
  servo_6.attach(6, 500, 2500);
  servo_5.attach(5, 500, 2500);
}
void loop()
{
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(8, 8);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  if(cm>50)
  {
    //RunServo();
  }
  delay(100); // Wait for 100 millisecond(s)
}