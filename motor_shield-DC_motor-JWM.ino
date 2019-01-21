  // Johnny McCown - Think Schematics - Remote Antenna Tuner Project
  // Start date: 5 Jan 2019, Last updated on 21 Jan 19
  // I am trying to make a antenna tunner using drive motors from an Roomba
  // Motors will be driven by Adafruit Motor Shield v2, that I had laying around
  // https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/using-dc-motors
  // https://www.youtube.com/watch?v=BIq-sIvN080
  //https://www.instructables.com/id/Hall-Effect-Sensors-1-Position-Control/

    
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

//Interrup pins on Uno is 2 & 3, Mega, 2,3,18,19,20,21...just saying
#define cap1HallSensorPin 2 //interrupt pin for hall effect sensor

volatile int cap1Count[] = {0};  //might need to change 0 to null, used for current positon //kep in mind that int is limited to +/- 32,768


//this is use for stacking the motor shilds using I2C
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

//this is defining the motor's name and its port
Adafruit_DCMotor *cap1 = AFMS.getMotor(1);
//Adafruit_DCMotor *inductor = AFMS.getMotor(2);
//Adafruit_DCMotor *cap2 = AFMS.getMotor(3);

bool clockwise = false;
bool counterclockwise = false;

void setup() {
  Serial.begin(9600);  //set up Serial library at 9600 bps

  Serial.println("Remote Antenna Tunner Serial Comm Activated");

  //tells the adafruit motor shild to startup
  AFMS.begin();

  pinMode(cap1HallSensorPin, INPUT);
  digitalWrite(cap1HallSensorPin, LOW);//set hall low to start for rising edge

  attachInterrupt(0, location, RISING); //enable the hall effect interupts
}


void location() {  //code from example, need to update
  //Serial.println("Update 1");
  if (clockwise == true) cap1Count[0]++; //if moving forwards, add counts
  else if (counterclockwise == true) cap1Count[0]--; //if moving back, subtract counts
}//end speed0
  


void loop() {
  // put your main code here, to run repeatedly:

  //speed is 0 for stop and 255 for max, 8bit system
  cap1->setSpeed(150);

  clockwise = true;
  counterclockwise = false;
  
  Serial.println("Capacitor 1 is moving clockwise");
  Serial.println("Counts"), Serial.println(cap1Count[0]);
  //options are FORWARD, BACKWARD, or RELEASE.
  cap1->run(FORWARD);
  delay(500);
  cap1->run(RELEASE);
  delay(3000);

  //speed is 0 for stop and 255 for max
  //inductor->setSpeed(150);

  //options are FORWARD, BACKWARD, or RELEASE.
  //inductor->run(FORWARD);
  //inductor->run(RELEASE);
  //delay(3000);
}
