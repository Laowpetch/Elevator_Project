#include<Wire.h>
int sec = 0;
int minutes = 0;
int hours = 0;
int secon = 4000;
int secon2 = 8000;
int state;
int Floor;
int t;
int x;

int segmentA = A0;
int segmentB = A1;
int segmentC = A2;
int segmentD = 2;
int segmentE = 4;
int segmentF = 7;
int segmentG = 8;

byte Ar1 = 23, Ar2 = 39, Ar3 = 71, Ar4 = 135;

void displaySegment(int);
void setup() {
  Wire.begin(0x22);
  Wire.beginTransmission(0x22);
  Wire.endTransmission();
  Serial.begin(9600);

  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    x = Serial.read();
    if (x != 13 && x != 10) {
      t = x;
      Serial.println(t);
    }
  }
  if (t == 49 || t == 52) {
    if (t == 49) {
      state = 1;
      Floor = 1;
    }
    else {
      state = 2;
      Floor = 4;
    }
    //หมุนขึ้น 1 ชั้น
    for (secon = 4000; secon > 0; secon--) {
      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar1); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar2); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar3); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar4); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed
      displaySegment(state);
    }
    if (secon == 0 ) {
      t = 0;
    }
  }
  else if (t == 50) {
    state = 1;
    Floor = 2;
    for (secon2 = 8000; secon >= 0; secon--) {
      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar1); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar2); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar3); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar4); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed
      displaySegment(state);
    }
    if (secon2 == 0 ) {
      state = 3;
      t = 0;
    }
  }
  else if (t == 51 || t == 54) {
    if (t == 51) {
      state = 2;
      Floor = 3;
    }
    else {
      state = 3;
      Floor = 6;
    }
    for (secon = 4000; secon >= 0; secon--) {
      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar4); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar3); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar2); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar1); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed
      displaySegment(state);
    }
    if (secon == 0 ) {
      t = 0;
    }
  }
  else if (t == 53) {
    state = 3;
    Floor = 5;
    for (secon2 = 8000; secon2 >= 0; secon2--) {
      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar4); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar3); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar2); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Wire.beginTransmission(0x22); // transmit to device
      Wire.write(Ar1); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed
      displaySegment(state);
    }
    if (secon2 == 0 ) {
      t = 0;
    }
  }
  else {
    displaySegment(state);
  }

}
void displaySegment(int numberToDisplay)
{
  digitalWrite(6, HIGH);
  switch (numberToDisplay)
  {
    case 0:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, LOW);
      break;
    case 1:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 2:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;
    case 3:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;
  }
  digitalWrite(6, LOW);
}
