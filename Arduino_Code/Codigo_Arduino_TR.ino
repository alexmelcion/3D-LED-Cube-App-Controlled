#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial blue(12,11);

int pinLatch=9;
int pinClock=10;
int pinData=8;
int c1=3;
int c2=4;
int c3=5;
int c4=6;
int c5=7;

String readString;

void setup()
{
  Serial.begin(9600);
  blue.begin(9600); 
  pinMode(pinLatch,OUTPUT);
  pinMode(pinClock,OUTPUT);
  pinMode(pinData,OUTPUT);
  pinMode(c1,OUTPUT);
  pinMode(c2,OUTPUT);
  pinMode(c3,OUTPUT);
  pinMode(c4,OUTPUT);
  pinMode(c5,OUTPUT);
  
}

void loop(){
  while (blue.available()){
    delay(3);
    char c = blue.read();
    readString += c;
  }
  if (readString.length() >0) 
  {
    Serial.println(readString);
  }
  if (readString.substring(0,4) == "cubo"){
    ledLibre();
  }
  else if (readString == "apagado"){
    fullblack();
  }
  else if (readString == "encendido"){
    full();
  }
  else if (readString == "animcubo"){
    while (blue.available()==0){
      cubo();
    }
  }
  else if (readString == "aristas"){
    while (blue.available()==0){
      aristas();
    }
  }
  else if (readString == "capas1"){
    while (blue.available()==0){
      capas1();
    }
  }
  else if (readString == "capas2"){
    while (blue.available()==0){
      capas2();
    }
  }
  else if (readString == "cruz"){
    while (blue.available()==0){
      cruz();
    }
  }
  else if (readString == "random1"){
    while (blue.available()==0){
      random1();
    }
  }
  else if (readString == "random2"){
    while (blue.available()==0){
      random2();
    }
  }
  readString="";
}
