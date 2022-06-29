//slave
#include<Wire.h>
int sec = 0;
int minutes = 0;
int hours = 0;
int secon = 4000;
int secon2 = 8000;
int state;
int Floor;
int t;

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
  if(Serial.available()>0){
    t = Serial.read();
    Serial.println(t);
    }
 
  if (t == 1 || t == 4) {
    if (t == 1) {
      state = 1;
      Floor = t;
    }
    if (t == 4) {
      state = 2;
      Floor = t;
    }
    secon--;
    if (secon > 0) {
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
    }
    displaySegment(state);
    if (secon == 0 ) {
      secon = 4000;
      t = 0;
    }
  }
  else if (t == 2) {
      if(secon2>4000){
        state=1;
        }
      else if(secon2>0){
        state=2;
        }
      }
      Floor = t;
    secon2--;
    if (secon2 > 0) {
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
    }
    displaySegment(state);
    if (secon2 == 0 ) {
      secon2 = 8000;
      t = 0;
    }
  
  else if (t == 3 || t == 6) {
    if (t == 3) {
      state = 2;
      Floor = t;
    }
    if (t == 6) {
      state = 3;
      Floor = t;
    }
    secon--;
    if (secon > 0) {
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
    }
    displaySegment(state);
    if (secon == 0 ) {
      secon = 4000;
      t = 0;
    }
  }
  else if (t == 5) {
    if(secon2>4000){
      state = 3;
      }
    else if(secon2>0){
      state = 2;
      }
    Floor = t;
    secon2--;
    if (secon2 > 0) {
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
    }
    displaySegment(state);
    if (secon2 == 0 ) {
      secon2 = 8000;
      t = 0;
    }
  }
  else{
    
    }
  
  
  if (t == 0) {
    if (Floor == 1) {
      state = 2;
      displaySegment(state);
    }
    if (Floor == 4) {
      state = 3;
      displaySegment(state);
    }
    if(Floor == 2){
      state = 3;
      displaySegment(state);
    }
    if(Floor == 3){
      state = 1;
      displaySegment(state);
    }
    if(Floor == 6){
      state = 2;
      displaySegment(state);
    }
    if(Floor == 5){
      state = 1;
      displaySegment(state);
    }
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
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 1:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 2:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 3:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 4:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 5:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 6:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;
    case 7:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;
    case 8:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 9:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, LOW);
      break;
  }
  digitalWrite(6, LOW);
}
