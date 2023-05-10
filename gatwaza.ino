#include <Servo.h>

const int trigPin = 3;          // Ultrasonic sensor trig pin
const int echoPin = 4;          // Ultrasonic sensor echo pin
const int servoPin = 5;         // Servo motor pin

long duration;                  // Ultrasonic sensor variables
int distance;

Servo myServo;                  // Servo motor object

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);     // Set Ultrasonic sensor trig pin as output
  pinMode(echoPin, INPUT);      // Set Ultrasonic sensor echo pin as input
  myServo.attach(servoPin);     // Attach servo motor to servo pin
  myServo.write(0);             // Move servo motor to starting position
}

void loop() { 
  
  digitalWrite(trigPin, LOW);             // Set trig pin to low
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);            // Set trig pin to high
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);             // Set trig pin to low
  duration = pulseIn(echoPin, HIGH);      // Measure echo pin pulse duration
  distance = duration * 0.034 / 2;        // Calculate distance from pulse duration
  
  if (distance < 9) {                    // If distance is less than 10 cm
    myServo.write(0);                       // Stop servo motor
      delay(5000);
       myServo.write(90);                      // Wait 1 second
    delay(3000);


     Serial.print("distance\n");
    Serial.print(distance);
  }
 else {
 myServo.write(90);
 } 
 }
