
#include <AFMotor.h>
#include <Servo.h>
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
int bluetoothTx = 0;
int bluetoothRx = 1;
Servo myservo1;
Servo myservo2;
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int pos=0;
int sensorPin = A2;
float sensorValue=0;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void setup() 
{
Serial.begin(9600);
bluetooth.begin(9600);
myservo1.attach(9);
myservo2.attach(10);
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);

pinMode(c, OUTPUT);        

pinMode(d, OUTPUT);
}

void loop() 
{  
 delay(10);
 while(Serial.available()) {
  command = "";  
  command = Serial.readString();  
  Serial.print(command);
}
  if(command == "*forward#")
{
    forward();
}
else if(command == "*backward#")
{
    backward();
}
else if(command == "*left#")
{
left();
}
else if(command == "*right#")
{
    right();
}
else if(command == "*stop#")
{
    Stop();
 }
else if(command == "*plow#")
{
plow();
}
else if(command == "*sense#")
{
sense();
}
else if(command == "*water#")
{
water();
}
else if(command == "*sow#")
{
sow();
}
{
  command = "";
}
void forward() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
  delay(1500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void backward() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
  delay(1500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void left() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);	
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
  delay(500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void right() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
  delay(500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void Stop() {
  motor1.run(RELEASEmotor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void plow(){
if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos2 = bluetooth.read();
    unsigned int realservo = (servopos2 *256) + servopos; 
    Serial.println(realservo); 

 if (realservo >=2000 && realservo <2180){
      int servo2 = realservo;
      servo2 = map(servo2,2000,2180,0,180);
      myservo2.write(servo2);
      Serial.println("servo 2 On");
      delay(10);
}
void sense(){
 if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos; 
    Serial.println(realservo); 
    
    if (realservo >= 1000 && realservo <1180){
    int servo1 = realservo;
    servo1 = map(servo1, 1000,1180,0,180);
    myservo1.write(servo1);
    Serial.println("servo 1 ON");
    delay(10);

    }
delay(500);
{
sensorValue = sensorValue + analogRead(SensorPin);
}
sensorValue = sensorValue/100.0;
Serial.println(sensorValue);
delay(30);
}
void sow(){
digitalwrite(a, HIGH);
if(Serial.available() > 0)                 
  {
    byte pwm = Serial.read();               
    analogWrite(a, pwm);                
    delay(50);
  }
}
void water(){
digitalwrite(b, HIGH);

