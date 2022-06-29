//master
#include <NewPing.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
int Trig1to3 = 13;
int Echo1to3 = 12;

int Trig1to2 = 11;
int Echo1to2 = 10;

int Trig2to3 = 9;
int Echo2to3 = 8;

int Trig2to1 = 7;
int Echo2to1 = 6;

int Trig3to1 = 5;
int Echo3to1 = 4;

int Trig3to2 = 3;
int Echo3to2 = 2;

int temp1 = A0;
int temp2 = A1;
int temp3 = A2;
int s = 3; //elevator at 1st floor

NewPing sonar1to3(Trig1to3,Echo1to3,200);
NewPing sonar1to2(Trig1to2,Echo1to2,200);
NewPing sonar2to3(Trig2to3,Echo2to3,200);
NewPing sonar2to1(Trig2to1,Echo2to1,200);
NewPing sonar3to1(Trig3to1,Echo3to2,200);
NewPing sonar3to2(Trig3to2,Echo3to2,200);

void setup() {
  Serial.begin(9600);
}
void loop() {

  int dis1to3 = sonar1to3.ping_cm();
  int dis1to2 = sonar1to2.ping_cm();
  int dis2to3 = sonar2to3.ping_cm();
  int dis2to1 = sonar2to1.ping_cm();
  int dis3to1 = sonar3to1.ping_cm();
  int dis3to2 = sonar3to2.ping_cm();

  int  t, v;
  if ((s == 3 || s == 5)) {
    //elevator at 1st floor
    if (dis1to2 < 3) {
      t = 1; //1goto 2;
    }
    else if (dis1to3 < 3) {
      t = 2; //1goto 3;
    }
    else if (dis2to1 < 3) {
      t = 1; //1goto 2;
      v = 3; //2goto 1;
    }
    else if (dis2to3 < 3) {
      t = 1; //1goto 2;
      v = 4; //2goto 3;
    }
    else if (dis3to1 < 3) {
      t = 2; //1goto 3;
      v = 5; //3goto 1;
    }
    else if (dis3to2 < 3) {
      t = 2; //1goto 3;
      v = 6; //3goto 2;
    }
  }
  else if ((s == 1 || s == 6)) {
    if (dis1to2 < 11) {
      t = 3; //2goto 1;
      v = 1; //1goto 2;
    }
    else if (dis1to3 < 3) {
      t = 3; //2goto 1;
      v = 2; //1goto 3;
    }
    else if (dis2to1 < 3) {
      t = 3; //2goto 1;
    }
    else if (dis2to3 < 3) {
      t = 4; //2goto 3;
    }
    else if (dis3to1 < 3) {
      t = 4; //2goto 3;
      v = 5; //3goto 1;
    }
    else if (dis3to2 < 3) {
      t = 4; //2goto 3;
      v = 6; //3goto 2;
    }
  }
  else if ((s == 2 || s == 4)) {
    if (dis1to2 < 3) {
      t = 5; //3goto 1;
      v = 1; //1goto 2;
    }
    else if (dis1to3 < 3) {
      t = 5; //3goto 1;
      v = 2; //1goto 3;
    }
    else if (dis2to1 < 3) {
      t = 6; //3goto 2;
      v = 3; //2goto 1;
    }
    else if (dis2to3 < 3) {
      t = 6; //3goto 2;
      v = 4; //2goto 3;
    }
    else if (dis3to1 < 3) {
      t = 5; //3goto 1;
    }
    else if (dis3to2 < 3) {
      t = 6; //3goto 2;
    }
  }
   //send t to slave
  Serial.println(t);
  delay(85000);
  //********************input floor number**************************
  s = t;
  if (v != 0) {
    t = v;
    v = 0;
  //send t to slave
  Serial.println(t);
  delay(85000);
  //*****************************************************
  //**********************reset***************************
  s = t;
  t = 0;
  v = 0;
  //*****************************************************
  //******************************************************
  //******************************************************
}
}
