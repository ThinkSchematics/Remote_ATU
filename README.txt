Title: Remote Antenna Tuning Unit
File Name: motor_shield-DC_motor-JWM
Date: 21 Jan 2119
Author: Johnny McCown
Website: www.thinkschematics.com
GetHub: https://github.com/ThinkSchematics
YouTube: https://www.youtube.com/user/ThinkSchematics
FaceBook: https://www.facebook.com/thinkschematics/

Copyright (c) 2019 Johnny McCown
License: License information can be found in the LICENSE.txt file which MUST accompany all versions of this code.
WARNING:
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Description:
This is the beginning of a Remote Antenna Tuning Unit.  I am using the drive motor froom a Roomba.  I was thinking stepper motors, but I couldn't find the data sheets for the motors that I have.  I also looked at some DC motors that I have, but they do not have encoders, so I can see how far the motor has turned my inductors or capacitors.  Then I realized I had an old Roomba that was given to me for parts.  As I searched the interwebs, I found some info about the motor (see the irobotweb link below).  It turns out that with every revolution of the well, there are roughly 508 ticks from the sensor (still haven’t tested this). 

This code is just me getting started, looking at other code on the internet and adapting it for my use.  You will see links to Adafruit about their Motor Shield v2 that I am using and to an Instructables that I found useful - give credit where credit is due.

Required Nonstandard Libraries:
Wire.h
Adafruit_MotorShield.h
Utility/Adafruit_MS_PWMServoDriver.h

Useful Links:
https://www.irobotweb.com/-/media/MainSite/PDFs/.../Create_2_Wheel_Hack.pdf
https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/using-dc-motors
https://www.instructables.com/id/Hall-Effect-Sensors-1-Position-Control/

Arduino Pinouts:
Hall Effect Sensor – Sense - D2 (used for interrupts on Arduino Uno)
Hall Effect Sensor – Power – 5v
Hall Effect Ground – GND

Motor Shield v2:
Motor – M1 Port
9v Batter – Motor Power Port (for testing)


