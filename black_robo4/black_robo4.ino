#include<Servo.h>

Servo sr1, sr2, sr3, sl1, sl2, sl3;

int st = 90, asl1 = 90, asr1 = 90, asl3 = 90, asr3 = 90;
int panja = 25;
int as3 = 50;
void setup() {
  // put your setup code here, to run once:
  sr1.attach(2);
  sr2.attach(3);
  sr3.attach(4);
  sl1.attach(5);
  sl2.attach(6);
  sl3.attach(7);
  Serial.begin(9600);
  initia();
  Serial.println("Setup done");
//  moveForward();
}

void loop() {
    moveForward();
}

void initia()
{
  sr1.write(90);
  delay(1000);
  sr2.write(90);
  delay(1000);
  sr3.write(90);
  delay(1000);
  sl1.write(90);
  delay(1000);
  sl2.write(90);
  delay(1000);
  sl3.write(90);
  delay(1000);

  //ready state
  for (int i = 0; i <= 10; i++)
  {
    asl1--;
    asr1++;
    sl1.write(asl1);
    delay(20);
    sr1.write(asr1);
    delay(20);
  }
  asl3 += 25;
  asr3 += 25;
  sl3.write(asl3);
  delay(300);
  sr3.write(asr3);
  delay(300);

  sr2.write(st + 20);
  delay(300);
  sl2.write(st - 20);
  delay(300);

  //move
  for (int i = 0; i <= panja; i++)
  {
    asl1++;
    asr1--;
    sr1.write(asr1);
    delay(5);
    sl1.write(asl1);
    delay(5);
  }
  //    moving
  for (int i = 1; i < as3+10; i++)
  {
    asl3--;
    sl3.write(asl3);
    delay(5);
    sl2.write(st - 20 + i);
    delay(5);
  }
  for (int i = 1; i < as3+10; i++)
  {
    asr3--;
    sr3.write(asr3);
    delay(5);
    sr2.write(st + 20 - i);
    delay(5);
  }
}


void moveForward()
{
  //on left leg
  for (int i = 0; i <= panja+20; i++)
  {
    asl1--;
    asr1++;
    sr1.write(asr1);
    delay(5);
    sl1.write(asl1);
    delay(5);
  }
  for (int i = 1; i < as3+20; i++)
  {
    asr3++;
    sr3.write(asr3);
    delay(5);
    sr2.write(st - 30 + i);
    delay(5);
  }
  for (int i = 1; i < as3+20; i++)
  {
    asl3++;
    sl3.write(asl3);
    delay(5);
    sl2.write(st + 30 - i);
    delay(5);
  }

  //on right leg
  for (int i = 0; i <= panja+20; i++)
  {
    asl1++;
    asr1--;
    sr1.write(asr1);
    delay(5);
    sl1.write(asl1);
    delay(5);
  }
  for (int i = 1; i < as3+20; i++)
  {
    asl3--;
    sl3.write(asl3);
    delay(5);
    sl2.write(st - 30 + i);
    delay(5);
  }
  for (int i = 1; i < as3+20; i++)
  {
    asr3--;
    sr3.write(asr3);
    delay(5);
    sr2.write(st + 30 - i);
    delay(5);
  }
}
