#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int pos0 = 102;
int pos180 = 512;

void setup() {
  Serial.begin(9600);
  Serial.println("GPIO test!");
  pwm.begin();
  pwm.setPWMFreq(50);

  delay(3000);
  initial_position();
  delay(3000);

//  moveForward();
}

void loop() 
{
  moveForward();
}
void setServo(int servo, int angle) 
{
  int duty;
//  duty = map(angle, 0, 180, pos0, pos180); //(angle, minAgl, maxAgl, min_Given_Angle, max_Given_Angle)

  duty = map(angle, 0, 180, pos0, pos180); 
  
  pwm.setPWM(servo, 0, duty); // (pin,0,duty)...^
}

//initalizing...

void initial_position() 
{
  //left
  setServo(0, 95);
  setServo(1, 50);
  setServo(2, 55);
  setServo(3, 115);
  setServo(4, 95);

  //right
  setServo(5, 95);
  setServo(6, 135);
  setServo(7, 10);
  setServo(8, 70);
  setServo(9, 90);
}

void moveForward()
{
  //on the left 
  for(int i=85; i<=110 ;i++)
  {
    setServo(0, i);
    delay(10);  
  }
  setServo(5, 103);
  delay(250);
  delay(2000);
  //on the right 
  for(int i=103; i>= 78;i--)
  {
    setServo(5, i);
    delay(10);  
  }
  setServo(0, 87);
  delay(250);

  delay(2000);
}
