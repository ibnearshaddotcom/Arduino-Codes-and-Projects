#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(11, 12);
Servo flapperServo;
Servo fillerServo;

int in1 = 5;    // Motor 1 input pin 1
int in2 = 6;    // Motor 1 input pin 2
int in3 = 7;    // Motor 2 input pin 1
int in4 = 8;    // Motor 2 input pin 2
int ena = 9;    // Motor 1 enable pin
int enb = 10;   // Motor 2 enable pin

char core;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  Serial.begin(9600);
  BT.begin(9600);

  flapperServo.attach(3);  // Attach flapper servo to pin 3
  fillerServo.attach(11);  // Attach filler servo to pin 11
}

void loop() {
  if (BT.available()) {
    core = BT.read();

    if (core == 'F') {
      digitalWrite(in1, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in4, LOW);
      analogWrite(ena, 125);
      analogWrite(enb, 125);
    } else if (core == 'B') {
      digitalWrite(in1, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in4, HIGH);
      analogWrite(ena, 125);
      analogWrite(enb, 125);
    } else if (core == 'L') {
      digitalWrite(in1, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in4, LOW);
      analogWrite(ena, 125);
      analogWrite(enb, 125);
    } else if (core == 'R') {
      digitalWrite(in1, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in4, HIGH);
      analogWrite(ena, 125);
      analogWrite(enb, 125);
    } else if (core == 'G') {
      digitalWrite(in1, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in4, LOW);
      analogWrite(ena, 125);
      analogWrite(enb, 125);
    } else if (core == 'l') {
      digitalWrite(in1, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in4, LOW);
      analogWrite(ena, 125);
      analogWrite(enb, 125);
    } else if (core == 'H') {
      digitalWrite(in1, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(ena, 125);
      analogWrite(enb, 125);
    } else if (core == 'J') {
      digitalWrite(in1, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(ena, 125);
      analogWrite(enb, 125);
    } else if (core == 'S') {
      digitalWrite(in1, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in4, LOW);
      analogWrite(ena, 0);
      analogWrite(enb, 0);
    } else if (core == 'O') {
      fillerServo.write(50);
      delay(500);
      for (int i = 0; i < 30; i++) {
        fillerServo.write(i);
        delay(50);
      }
      fillerServo.write(0);
    }
  }
}
