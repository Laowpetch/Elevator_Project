//master
#include <NewPing.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#define ONE_WIRE_BUS A0 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors1(&oneWire);

#define TWO_WIRE_BUS A1 
OneWire twoWire(TWO_WIRE_BUS);
DallasTemperature sensors2(&twoWire);

#define THREE_WIRE_BUS A2 
OneWire threeWire(THREE_WIRE_BUS);
DallasTemperature sensors3(&threeWire);
int SW1to3 = 12;

int Trig1to2 = 11;
int Echo1to2 = 10;

int Trig2to3 = 9;
int Echo2to3 = 8;

int Trig2to1 = 7;
int Echo2to1 = 6;

int SW3to1 = 3;

int Trig3to2 = 5;
int Echo3to2 = 4;

int temp1 = A0;
int temp2 = A1;
int temp3 = A2;
int s = 3; //elevator at 1st floor
int  t, v = 0;


NewPing sonar1to2(Trig1to2, Echo1to2, 200);
NewPing sonar2to3(Trig2to3, Echo2to3, 200);
NewPing sonar2to1(Trig2to1, Echo2to1, 200);
NewPing sonar3to2(Trig3to2, Echo3to2, 200);

void setup() {
  pinMode(SW1to3, INPUT_PULLUP);
  pinMode(SW3to1, INPUT_PULLUP);
  sensors1.begin();
  sensors2.begin();
  sensors3.begin();
  Serial.begin(9600);
}
void loop() {

  int dis1to2 = sonar1to2.ping_cm();
  int dis2to3 = sonar2to3.ping_cm();
  int dis2to1 = sonar2to1.ping_cm();
  int dis3to2 = sonar3to2.ping_cm();


  if ((s == 3 || s == 5)) {
    //elevator at 1st floor
    if (dis1to2 < 3) {
      t = 1; //1goto 2;
    }
    else if (digitalRead(SW1to3) == 0) {
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
    else if (digitalRead(SW3to1) == 0) {
      t = 2; //1goto 3;
      v = 5; //3goto 1;
    }
    else if (dis3to2 < 3) {
      t = 2; //1goto 3;
      v = 6; //3goto 2;
    }
    else {
    }
  }
  else if ((s == 1 || s == 6)) {
    if (dis1to2 < 3) {
      t = 3; //2goto 1;
      v = 1; //1goto 2;
    }
    else if (digitalRead(SW1to3) == 0) {
      t = 3; //2goto 1;
      v = 2; //1goto 3;
    }
    else if (dis2to1 < 3) {
      t = 3; //2goto 1;
    }
    else if (dis2to3 < 3) {
      t = 4; //2goto 3;
    }
    else if (digitalRead(SW3to1) == 0) {
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
    else if (digitalRead(SW1to3) == 0) {
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
    else if (digitalRead(SW3to1) == 0) {
      t = 5; //3goto 1;
    }
    else if (dis3to2 < 3) {
      t = 6; //3goto 2;
    }
  }


  
   //send t to slave
  sensors1.requestTemperatures();
  sensors2.requestTemperatures();
  sensors3.requestTemperatures();
  if(sensors1.getTempCByIndex(0)>59||sensors2.getTempCByIndex(0)||sensors3.getTempCByIndex(0)){
    t=0;
    v=0;
    }
  Serial.println(t);
  if (t == 1 || t == 6 || t == 3 || t == 4) {
    delay(85000);
  }
  else if (t == 2 || t == 5) {
    delay(165000);
  }
   //********************input floor number**************************
  if (t != 0) {
    s = t;
    t = 0;
  }
  if (v != 0) {
    t = v;
    v = 0;
      //send t to slave
    Serial.println(t);
    if (t == 1 || t == 6 || t == 3 || t == 4) {
      delay(85000);
    }
    else if (t == 2 || t == 5) {
      delay(165000);
    }
    //*****************************************************

    //**********************reset***************************
    s = t;
    t = 0;
    v = 0;
    //******************************************************/
  }
}
