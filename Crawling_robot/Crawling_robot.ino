/******************************************************************
  AUTOR: PETR KYNČL
  VERZE: 8.00
  DATUM: 3.12.2020
  POPIS: Crawling_robot
  VIDEO: 
*****************************************************************/

#include <Wire.h>
#include <servo_PCA9685.h>
#include "melody.h"
#define MAX_SERVOS  16
servo_PCA9685 servo = servo_PCA9685();

uint8_t servonum = 0;

byte i1L1 = 0;
byte i2L1 = 0;
byte i3L1 = 0;
byte i4L1 = 0;
byte i5L1 = 0;
byte i6L1 = 0;
byte i7L1 = 0;
byte i8L1 = 0;

byte i1L2 = 0;
byte i2L2 = 0;
byte i3L2 = 0;
byte i4L2 = 0;
byte i5L2 = 0;
byte i6L2 = 0;
byte i7L2 = 0;
byte i8L2 = 0;

byte i1L3 = 0;
byte i2L3 = 0;
byte i3L3 = 0;
byte i4L3 = 0;
byte i5L3 = 0;
byte i6L3 = 0;

byte i1L4 = 0;
byte i2L4 = 0;
byte i3L4 = 0;
byte i4L4 = 0;
byte i5L4 = 0;
byte i6L4 = 0;

byte buzzer = 3;
byte led_pinH = 4;
byte led_pinS = 5;

byte speedV = 10;
char DATAin = 0;
byte m = 0;
byte l1status = 1;
byte l2status = 1;
byte l3status = 1;
byte l4status = 1;
bool STAND = LOW;
bool STOP = LOW;

bool conn = LOW;

unsigned long prevCon = 0;

short meGA = 1;
short count = 1;
bool dan = LOW;
unsigned long prev = 0;

unsigned long prevS = 0;

bool Do = LOW;

bool Meg = LOW;

bool attW = LOW;

bool star = HIGH;

bool attO = LOW;

bool attP = LOW;

bool fowa = LOW;
bool fow = LOW;

bool back = LOW;
bool bac = LOW;

unsigned long TimeNow = 0;
unsigned long TimePrev = 0;

void setup() {

  Serial.begin(9600);

  servo.begin();

  pinMode (led_pinH, OUTPUT);
  pinMode (led_pinS, OUTPUT);

  legsSit();

  delay(200);

  digitalWrite(led_pinH, LOW);
  digitalWrite(led_pinS, LOW);

  robotOn();

  digitalWrite(led_pinH, HIGH);
  digitalWrite(led_pinS, HIGH);
}

void loop() {

  serialRead();
  control();
}

void moveForward(void) {
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Move Forward
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  while (m == 1) {

    Serial.println("FORWARD");
    //moveLeg1Up(); / moveLeg1Left(); / moveLeg1Right(); / moveLeg1Down(); / moveLeg1LeftBack(); / moveLeg1RightBack(); / moveLeg1Reset();
    //moveLeg2Up(); / moveLeg2Left(); / moveLeg2Right(); / moveLeg2Down(); / moveLeg2LeftBack(); / moveLeg2RightBack(); / moveLeg2Reset();
    //moveLeg3Up(); / moveLeg3Left(); / moveLeg3Right(); / moveLeg3Down(); / moveLeg3LeftBack(); / moveLeg3RightBack(); / moveLeg3Reset();
    //moveLeg4Up(); / moveLeg4Left(); / moveLeg4Right(); / moveLeg4Down(); / moveLeg4LeftBack(); / moveLeg4RightBack(); / moveLeg4Reset();
    if (l1status == 1) {

      i5L4 = 30;
      i5L1 = 30;
      moveLeg1Up();
      moveLeg4Up();
      moveLeg1Left();
      moveLeg4Left();
      moveLeg1Down();
      moveLeg4Down();

      if (i3L1 == 10) {
        l1status = 2;
      }
      Serial.println("1");
    }
    else if (l1status == 2) {

      moveLeg1LeftBack();
      moveLeg4LeftBack();
      moveLeg2Left();
      moveLeg3Left();

      if (i2L3 >= 30) {
        serialRead();

        if (m == 5) {
          fowa = HIGH;
          m = 1;
          l1status = 7;
        }
        else if (m == 7) {
          fow = HIGH;
          m = 1;
          l1status = 7;
        }
        else if (m == 1) {
          l1status = 3;
        }
      }
      Serial.println("2");
    }
    else if (l1status == 3) {

      i2L2 = 30;
      i2L3 = 30;
      moveLeg1Reset();
      moveLeg4Reset();
      moveLeg2Up();
      moveLeg3Up();
      moveLeg2LeftRight();
      moveLeg3LeftRight();
      moveLeg2Down();
      moveLeg3Down();

      if (i3L2 == 10) {
        l1status = 4;
        moveLeg2Reset();
        moveLeg3Reset();
      }
      Serial.println("3");
    }
    else if (l1status == 4) {

      i2L2 = 30;
      i2L3 = 30;
      moveLeg1Right();
      moveLeg4Right();
      moveLeg2RightBack();
      moveLeg3RightBack();

      if (i2L1 > 30) {
        serialRead();

        if (m == 5) {
          fowa = HIGH;
          m = 1;
          l1status = 6;
        }
        else if (m == 7) {
          fow = HIGH;
          m = 1;
          l1status = 6;
        }
        else if (m == 1) {
          l1status = 5;
        }
      }
      Serial.println("4");
    }
    else if (l1status == 5) {

      i2L1 = 30;
      i2L4 = 30;
      moveLeg2Reset();
      moveLeg3Reset();
      moveLeg1Up();
      moveLeg4Up();
      moveLeg1RightLeft();
      moveLeg4RightLeft();
      moveLeg1Down();
      moveLeg4Down();

      if (i3L1 == 10) {
        l1status = 2;
        moveLeg1Reset();
        moveLeg4Reset();
        i2L1 = 30;
        i2L4 = 30;
      }
      Serial.println("5");
    }
    else if (l1status == 6) {

      i2L1 = 30;
      i2L4 = 30;
      moveLeg2Reset();
      moveLeg3Reset();
      moveLeg1Up();
      moveLeg4Up();
      moveLeg1RightBack();
      moveLeg4RightBack();
      moveLeg1Down();
      moveLeg4Down();

      if (i3L1 == 10) {
        l1status = 8;
        moveLeg1Reset();
        moveLeg4Reset();
      }
      Serial.println("6");
    }
    else if (l1status == 7) {

      i2L2 = 30;
      i2L3 = 30;
      moveLeg1Reset();
      moveLeg4Reset();
      moveLeg2Up();
      moveLeg3Up();
      moveLeg2LeftBack();
      moveLeg3LeftBack();
      moveLeg2Down();
      moveLeg3Down();

      if (i3L2 == 10) {
        l1status = 8;
        moveLeg2Reset();
        moveLeg3Reset();
      }
      Serial.println("7");
    }
    else if (l1status == 8) {

      l1status = 1;
      legsStay();
      legsReset();
      serialRead();
      Stop();

      if (fowa == HIGH) {
        fowa = LOW;
        m = 5;
      }
      if (fow == HIGH) {
        fow == LOW;
        m = 7;
      }
      Serial.println("8");
    }
    delay(speedV);
  }
}

void moveBackword(void) {
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Move Backward
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  while (m == 2) {

    Serial.println("BACKWARD");
    //moveLeg1Up(); / moveLeg1Left(); / moveLeg1Right(); / moveLeg1Down(); / moveLeg1LeftBack(); / moveLeg1RightBack(); / moveLeg1Reset();
    //moveLeg2Up(); / moveLeg2Left(); / moveLeg2Right(); / moveLeg2Down(); / moveLeg2LeftBack(); / moveLeg2RightBack(); / moveLeg2Reset();
    //moveLeg3Up(); / moveLeg3Left(); / moveLeg3Right(); / moveLeg3Down(); / moveLeg3LeftBack(); / moveLeg3RightBack(); / moveLeg3Reset();
    //moveLeg4Up(); / moveLeg4Left(); / moveLeg4Right(); / moveLeg4Down(); / moveLeg4LeftBack(); / moveLeg4RightBack(); / moveLeg4Reset();
    if (l2status == 1) {

      i5L2 = 30;
      i5L3 = 30;
      moveLeg2Up();
      moveLeg3Up();
      moveLeg2Left();
      moveLeg3Left();
      moveLeg2Down();
      moveLeg3Down();

      if (i3L3 == 10) {
        l2status = 2;
      }
      Serial.println("1");
    }
    else if (l2status == 2) {

      moveLeg2LeftBack();
      moveLeg3LeftBack();
      moveLeg1Left();
      moveLeg4Left();

      if (i2L4 >= 30) {
        serialRead();

        if (m == 5) {
          back = HIGH;
          m = 2;
          l2status = 7;
        }
        else if (m == 7) {
          bac = HIGH;
          m = 2;
          l2status = 7;
        }
        else if (m == 2) {
          l2status = 3;
        }
      }
      Serial.println("2");
    }
    else if (l2status == 3) {

      i2L1 = 30;
      i2L4 = 30;
      moveLeg2Reset();
      moveLeg3Reset();
      moveLeg1Up();
      moveLeg4Up();
      moveLeg1LeftRight();
      moveLeg4LeftRight();
      moveLeg1Down();
      moveLeg4Down();

      if (i3L4 == 10) {
        l2status = 4;
        moveLeg1Reset();
        moveLeg4Reset();
      }
      Serial.println("3");
    }
    else if (l2status == 4) {

      i2L1 = 30;
      i2L4 = 30;
      moveLeg1RightBack();
      moveLeg4RightBack();
      moveLeg2Right();
      moveLeg3Right();

      if (i2L3 > 30) {
        serialRead();

        if (m == 5) {
          back = HIGH;
          m = 2;
          l2status = 6;
        }
        else if (m == 7) {
          bac = HIGH;
          m = 2;
          l2status = 6;
        }
        else if (m == 2) {
          l2status = 5;
        }
      }
      Serial.println("4");
    }
    else if (l2status == 5) {

      i2L2 = 30;
      i2L3 = 30;
      moveLeg1Reset();
      moveLeg4Reset();
      moveLeg2Up();
      moveLeg3Up();
      moveLeg2RightLeft();
      moveLeg3RightLeft();
      moveLeg2Down();
      moveLeg3Down();

      if (i3L3 == 10) {
        l2status = 2;
        moveLeg2Reset();
        moveLeg3Reset();
        i2L2 = 30;
        i2L3 = 30;
      }
      Serial.println("5");
    }
    else if (l2status == 6) {

      i2L2 = 30;
      i2L3 = 30;
      moveLeg1Reset();
      moveLeg4Reset();
      moveLeg2Up();
      moveLeg3Up();
      moveLeg2RightBack();
      moveLeg3RightBack();
      moveLeg2Down();
      moveLeg3Down();

      if (i3L3 == 10) {
        l2status = 8;
        moveLeg2Reset();
        moveLeg3Reset();
      }
      Serial.println("6");
    }
    else if (l2status == 7) {

      i2L1 = 30;
      i2L4 = 30;
      moveLeg2Reset();
      moveLeg3Reset();
      moveLeg1Up();
      moveLeg4Up();
      moveLeg1LeftBack();
      moveLeg4LeftBack();
      moveLeg1Down();
      moveLeg4Down();

      if (i3L1 == 10) {
        l2status = 8;
        moveLeg1Reset();
        moveLeg4Reset();
      }
      Serial.println("7");
    }
    else if (l2status == 8) {

      l2status = 1;
      legsStay();
      legsReset();
      serialRead();
      Stop();

      if (back == HIGH) {
        back = LOW;
        m = 5;
      }
      if (bac == HIGH) {
        bac == LOW;
        m = 7;
      }
      Serial.println("8");
    }
    delay(speedV);
  }
}

void moveRight(void) {
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Move Right
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  while (m == 3) {

    Serial.println("RIGHT");
    //moveLeg1Up(); / moveLeg1Left(); / moveLeg1Right(); / moveLeg1Down(); / moveLeg1LeftBack(); / moveLeg1RightBack(); / moveLeg1Reset();
    //moveLeg2Up(); / moveLeg2Left(); / moveLeg2Right(); / moveLeg2Down(); / moveLeg2LeftBack(); / moveLeg2RightBack(); / moveLeg2Reset();
    //moveLeg3Up(); / moveLeg3Left(); / moveLeg3Right(); / moveLeg3Down(); / moveLeg3LeftBack(); / moveLeg3RightBack(); / moveLeg3Reset();
    //moveLeg4Up(); / moveLeg4Left(); / moveLeg4Right(); / moveLeg4Down(); / moveLeg4LeftBack(); / moveLeg4RightBack(); / moveLeg4Reset();

    if (l3status == 1) {

      i5L1 = 30;
      i5L4 = 30;
      moveLeg1Up();
      moveLeg4Up();
      moveLeg1Right();
      moveLeg4Left();
      moveLeg1Down();
      moveLeg4Down();

      if (i3L1 == 10) {
        l3status = 2;
      }
      Serial.println("1");
    }
    else if (l3status == 2) {

      i5L2 = 30;
      i5L3 = 30;
      moveLeg3Up();
      moveLeg2Up();
      moveLeg3Left();
      moveLeg2Right();
      moveLeg3Down();
      moveLeg2Down();

      if (i3L3 == 10) {
        l3status = 3;
      }
      Serial.println("2");
    }
    else if (l3status == 3) {

      moveLeg1RightBack();
      moveLeg4LeftBack();
      moveLeg3LeftBack();
      moveLeg2RightBack();

      if (i4L2 >= 30) {
        l3status = 1;
        moveLeg1Reset();
        moveLeg2Reset();
        moveLeg3Reset();
        moveLeg4Reset();
        legsStay();
        legsReset();
        serialRead();
        Stop();
      }
      Serial.println("3");
    }
    delay(speedV);
  }
}

void moveLeft(void) {
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Move Left
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  while (m == 4) {

    Serial.println("LEFT");
    //moveLeg1Up(); / moveLeg1Left(); / moveLeg1Right(); / moveLeg1Down(); / moveLeg1LeftBack(); / moveLeg1RightBack(); / moveLeg1Reset();
    //moveLeg2Up(); / moveLeg2Left(); / moveLeg2Right(); / moveLeg2Down(); / moveLeg2LeftBack(); / moveLeg2RightBack(); / moveLeg2Reset();
    //moveLeg3Up(); / moveLeg3Left(); / moveLeg3Right(); / moveLeg3Down(); / moveLeg3LeftBack(); / moveLeg3RightBack(); / moveLeg3Reset();
    //moveLeg4Up(); / moveLeg4Left(); / moveLeg4Right(); / moveLeg4Down(); / moveLeg4LeftBack(); / moveLeg4RightBack(); / moveLeg4Reset();

    if (l4status == 1) {

      i5L4 = 30;
      i5L1 = 30;
      moveLeg1Up();
      moveLeg4Up();
      moveLeg1Left();
      moveLeg4Right();
      moveLeg1Down();
      moveLeg4Down();

      if (i3L1 == 10) {
        l4status = 2;
      }
      Serial.println("1");
    }
    else if (l4status == 2) {

      i5L2 = 30;
      i5L3 = 30;
      moveLeg3Up();
      moveLeg2Up();
      moveLeg3Right();
      moveLeg2Left();
      moveLeg3Down();
      moveLeg2Down();

      if (i3L3 == 10) {
        l4status = 3;
      }
      Serial.println("2");
    }
    else if (l4status == 3) {

      moveLeg1LeftBack();
      moveLeg4RightBack();
      moveLeg3RightBack();
      moveLeg2LeftBack();

      if (i4L2 >= 30) {
        l4status = 1;
        moveLeg1Reset();
        moveLeg2Reset();
        moveLeg3Reset();
        moveLeg4Reset();
        legsStay();
        legsReset();
        serialRead();
        Stop();
      }
      Serial.println("3");
    }
    delay(speedV);
  }
}

void legsStop(void) {
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Move LegStop
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  legsStay();
  legsReset();
  STOP = LOW;
  Serial.println("STOP");
}

void waving (void) {
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Move Waving
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  while (m == 6) {

    Serial.println("WAVING");

    if (i1L2 <= 10) {

      servo.moveServo(3, 180 + i1L2 * 4); //220
      servo.moveServo(4, 120 + i1L2 * 10); //220

      i1L2++;
      Serial.println("1");
    }
    if (i2L2 <= 30) {

      servo.moveServo(5, 100 - i2L2 * 0.7); //79

      i2L2++;
      Serial.println("2");
    }
    if (i2L2 >= 30 && i3L2 <= 10) {

      servo.moveServo(3, 220 - i3L2 * 12); //100
      servo.moveServo(5, 79 - i3L2 * 3); //49

      i3L2++;
      Serial.println("3");
    }
    if (i3L2 >= 10 && i4L2 <= 10) {

      servo.moveServo(3, 100 + i4L2 * 8); //180
      servo.moveServo(5, 49 + i4L2 * 3); //79

      i4L2++;
      Serial.println("4");
    }
    if (i4L2 >= 10 && i5L2 <= 10) {

      servo.moveServo(3, 180 - i5L2 * 8); //100
      servo.moveServo(5, 79 - i5L2 * 3); //49

      i5L2++;
      Serial.println("5");
    }
    if (i5L2 >= 10 && i6L2 <= 10) {

      servo.moveServo(3, 100 + i6L2 * 12); //220
      servo.moveServo(5, 49 + i6L2 * 3); //79

      i6L2++;
      Serial.println("6");
    }
    if (i6L2 >= 10 && i7L2 <= 30) {

      servo.moveServo(5, 79 + i7L2 * 0.7); //100

      i7L2++;
      Serial.println("7");
    }
    if (i7L2 >= 30 && i8L2 <= 10) {

      servo.moveServo(3, 220 - i8L2 * 4); //180
      servo.moveServo(4, 220 - i8L2 * 12); //120

      i8L2++;
      Serial.println("8");
    }
    if (i8L2 >= 10) {
      i1L2 = 0;
      i2L2 = 0;
      i3L2 = 0;
      i4L2 = 0;
      i5L2 = 0;
      i6L2 = 0;
      i7L2 = 0;
      i8L2 = 0;
      serialRead();
      legsStay();
      legsReset();
      m = 5;
      Stop();
      STOP = LOW;
    }
    delay(40);
  }
}

void sit (void) {
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Move Sit
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  while (m == 7 || m == 13) {

    Serial.println ("SIT");

    if (i1L1 <= 100) {
      /*
        //Leg 1
        servo.moveServo(0, 10);
        servo.moveServo(1, 10);
        servo.moveServo(2, 190);

        //Leg 2
        servo.moveServo(3, 220);
        servo.moveServo(4, 220);
        servo.moveServo(5, 50);

        //Leg 3
        servo.moveServo(6, 220);
        servo.moveServo(7, 220);
        servo.moveServo(8, 50);

        //Leg 4
        servo.moveServo(9, 10);
        servo.moveServo(10, 20);
        servo.moveServo(11, 190);
      */

      servo.moveServo(0, 40 - i1L1 * 0.3); //10
      servo.moveServo(1, 120 - i1L1 * 1.1); //10

      servo.moveServo(3, 180 + i1L1 * 0.4); //220
      servo.moveServo(4, 120 + i1L1 * 1); //220

      servo.moveServo(6, 180 + i1L1 * 0.4); //220
      servo.moveServo(7, 110 + i1L1 * 1.1); //220

      servo.moveServo(9, 40 - i1L1 * 0.3); //10
      servo.moveServo(10, 140 - i1L1 * 1.2); //20

      i1L1++;
    }
    if (i1L1 >= 100 && i2L1 <= 100) {

      servo.moveServo(2, 140 + i2L1 * 0.5); //190

      servo.moveServo(5, 100 - i2L1 * 0.5); //50

      servo.moveServo(8, 100 - i2L1 * 0.5); //50

      servo.moveServo(11, 140 + i2L1 * 0.5); //190

      i2L1++;
    }
    if (i2L1 >= 100) {
      i1L1 = 0;
      i2L1 = 0;
      TimePrev = 0;
      legsSit();
      STAND = LOW;
      serialRead();
      m = 0;
      digitalWrite(led_pinH, HIGH);
      digitalWrite(led_pinS, HIGH);
      STOP = LOW;
    }
    delay(speedV);
  }
}

void stand (void) {
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Move Stand
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  while (m == 8) {

    Serial.println ("STAND");

    /*
      //Leg 1
      servo.moveServo(0, 30);
      servo.moveServo(1, 120);
      servo.moveServo(2, 140);

      //Leg 2
      servo.moveServo(3, 180);
      servo.moveServo(4, 120);
      servo.moveServo(5, 100);

      //Leg 3
      servo.moveServo(6, 190);
      servo.moveServo(7, 110);
      servo.moveServo(8, 100);

      //Leg 4
      servo.moveServo(9, 30);
      servo.moveServo(10, 140);
      servo.moveServo(11, 140);
    */

    if (i1L1 <= 100) {

      servo.moveServo(2, 190 - i1L1 * 0.5); //140

      servo.moveServo(5, 50 + i1L1 * 0.5); //100

      servo.moveServo(8, 50 + i1L1 * 0.5); //100

      servo.moveServo(11, 190 - i1L1 * 0.5); //140

      i1L1++;
    }
    if (i1L1 >= 100 && i2L1 <= 100) {

      servo.moveServo(0, 10 + i2L1 * 0.3); //40
      servo.moveServo(1, 10 + i2L1 * 1.1); //120

      servo.moveServo(3, 220 - i2L1 * 0.4); //180
      servo.moveServo(4, 220 - i2L1 * 1); //120

      servo.moveServo(6, 220 - i2L1 * 0.4); //180
      servo.moveServo(7, 220 - i2L1 * 1.1); //110

      servo.moveServo(9, 10 + i2L1 * 0.3); //40
      servo.moveServo(10, 20 + i2L1 * 1.2); //140

      i2L1++;
    }
    if (i2L1 >= 100) {
      i1L1 = 0;
      i2L1 = 0;
      TimePrev = millis();
      legsStay();
      STAND = HIGH;
      serialRead();
      m = 0;
      Stop();
      STOP = LOW;
    }
    delay(speedV);
  }
}

void Attack (void) {
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Move Attack
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  while (m == 9 || attW == HIGH) {

    Serial.println("ATTACK");

    /*
      //Leg 1
      servo.moveServo(0, 30); //10,80,200
      servo.moveServo(1, 120); //200,150,10
      servo.moveServo(2, 140); //140

      //Leg 2
      servo.moveServo(3, 180); //200,150,10
      servo.moveServo(4, 120); //10,80,200
      servo.moveServo(5, 100); //100

      //Leg 3
      servo.moveServo(6, 190); //200,150,10
      servo.moveServo(7, 110); //10,80,200
      servo.moveServo(8, 100); //100

      //Leg 4
      servo.moveServo(9, 30); //10,80,200
      servo.moveServo(10, 140); //200,150,10
      servo.moveServo(11, 140); //140
    */

    if (l1status == 1) {
      if (i1L1 <= 100) {

        servo.moveServo(2, 140 + i1L1 * 0.4); //180
        servo.moveServo(5, 100 - i1L1 * 0.5); //50
        servo.moveServo(8, 100 + i1L1 * 0.9); //190
        servo.moveServo(11, 140 - i1L1 * 0.9); //50

        Serial.println("1");

        i1L1++;
      }
      else if (i1L1 >= 100 && i2L1 <= 100) {

        servo.moveServo(0, 40 - i2L1 * 0.3); //10
        servo.moveServo(1, 120 - i2L1 * 1.1); //10

        servo.moveServo(3, 180 + i2L1 * 0.4); //220
        servo.moveServo(4, 120 + i2L1 * 1); //220

        Serial.println("2");

        i2L1++;

        if (i2L1 >= 100) {
          l1status = 2;
        }
      }
    }
    else if (l1status == 2) {

      do {

        Serial.println("ATT_SERIAL");

        attW = HIGH;
        m = 0;
        serialRead();
        Stop();

        if (m == 9) {
          i3L1 = 0;
          i4L1 = 0;
          i5L1 = 0;
          i6L1 = 0;
          l1status = 3;
        }
        else if (m == 5 || m == 7 || attP == HIGH) {

          if (m == 7 || attP == HIGH) {
            attO = HIGH;
            attP = LOW;
          }
          attW = LOW;
          m = 9;
          l1status = 4;
        }
        else if (m == 11 || m == 12) {
          control();
          m = 0;
        }
      } while (l1status == 2);
    }
    else if  (l1status == 3) {
      if (i3L1 <= 100) {

        servo.moveServo(0, 10 + i3L1 * 1.8); //190
        servo.moveServo(1, 10 + i3L1 * 1.1); //120

        Serial.println("3");

        i3L1++;
      }
      else if (i3L1 >= 100 && i4L1 <= 100) {

        servo.moveServo(0, 190 - i4L1 * 1.8); //10
        servo.moveServo(1, 120 - i4L1 * 1.1); //10

        Serial.println("4");

        i4L1++;
      }
      else if (i4L1 >= 100 && i5L1 <= 100) {

        servo.moveServo(3, 220 - i5L1 * 1.9); //30
        servo.moveServo(4, 220 - i5L1 * 1); //120

        Serial.println("5");

        i5L1++;
      }
      else if (i5L1 >= 100 && i6L1 <= 100) {

        servo.moveServo(3, 30 + i6L1 * 1.9); //220
        servo.moveServo(4, 120 + i6L1 * 1); //220

        Serial.println("6");

        i6L1++;

        if (i6L1 >= 100) {
          l1status = 2;
        }
      }
    }
    else if (l1status == 4) {
      if (i7L1 <= 100) {

        servo.moveServo(0, 10 + i7L1 * 0.3); //40
        servo.moveServo(1, 10 + i7L1 * 1.1); //120

        servo.moveServo(3, 220 - i7L1 * 0.4); //180
        servo.moveServo(4, 220 - i7L1 * 1); //120

        Serial.println("7");

        i7L1++;
      }
      else if (i7L1 >= 100 && i8L1 <= 100) {

        servo.moveServo(2, 180 - i8L1 * 0.4); //140
        servo.moveServo(5, 50 + i8L1 * 0.5); //100
        servo.moveServo(8, 190 - i8L1 * 0.9); //100
        servo.moveServo(11, 50 + i8L1 * 0.9); //140

        Serial.println("8");

        i8L1++;

        if (i8L1 >= 100) {
          l1status = 1;
          i1L1 = 0;
          i2L1 = 0;
          i3L1 = 0;
          i4L1 = 0;
          i5L1 = 0;
          i6L1 = 0;
          i7L1 = 0;
          i8L1 = 0;
          serialRead();
          legsStay();
          legsReset();
          m = 5;
          Stop();
          if (attO == HIGH) {
            m = 7;
            attO = LOW;
          }
        }
      }
    }
    delay(5);
  }
}

void Dance (void) {
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Move Dance
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  while (m == 10) {
    Serial.println("DANCE");

    if (dan == HIGH) {
      megalov();
      if (Meg == LOW) {
        digitalWrite(led_pinH, LOW);

      } else if (Meg == HIGH) {
        digitalWrite(led_pinH, HIGH);
      }
    } else {
      digitalWrite(led_pinH, HIGH);
      Meg == LOW;
      count = 1;
      meGA = 1;
    }

    /*
      //Leg 1
      servo.moveServo(0, 30);
      servo.moveServo(1, 120);
      servo.moveServo(2, 140);

      //Leg 2
      servo.moveServo(3, 180);
      servo.moveServo(4, 120);
      servo.moveServo(5, 100);

      //Leg 3
      servo.moveServo(6, 190);
      servo.moveServo(7, 110);
      servo.moveServo(8, 100);

      //Leg 4
      servo.moveServo(9, 30);
      servo.moveServo(10, 140);
      servo.moveServo(11, 140);
    */

    ////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////

    if (l1status == 1) {
      moveLeg1Up();
      moveLeg4Up();

      if (i1L1 >= 10 && i1L4 >= 10) {
        l1status = 2;
      }
      Serial.println("1");
    }
    else if (l1status == 2) {

      if (i2L1 <= 30 && i2L4 <= 30) {

        servo.moveServo(2, 140 + i2L1 * 2);//200
        servo.moveServo(11, 140 + i2L4 * 1.6);//188

        i2L1++;
        i2L4++;
      }
      if (i2L1 >= 30 && i2L4 >= 30) {
        l1status = 3;
      }
      Serial.println("2");
    }
    else if (l1status == 3) {
      i5L1 = 30;
      i5L4 = 30;
      moveLeg1Down();
      moveLeg4Down();

      if (i3L1 >= 10 && i3L4 >= 10) {
        l1status = 4;
      }
      Serial.println("3");
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    else if (l1status == 4) {
      moveLeg2Up();
      moveLeg3Up();

      if (i1L2 >= 10 && i1L3 >= 10) {
        l1status = 5;
      }
      Serial.println("4");
    }
    else if (l1status == 5) {

      if (i2L2 <= 30 && i2L3 <= 30) {

        servo.moveServo(5, 100 - i2L2 * 2);//40
        servo.moveServo(8, 100 - i2L3 * 2.3);//31

        i2L2++;
        i2L3++;
      }
      if (i2L2 >= 30 && i2L3 >= 30) {
        l1status = 6;
      }
      Serial.println("5");
    }
    else if (l1status == 6) {
      i5L2 = 30;
      i5L3 = 30;
      moveLeg2Down();
      moveLeg3Down();

      if (i3L2 >= 10 && i3L3 >= 10) {
        l1status = 7;
      }
      Serial.println("6");
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////
    else if (l1status == 7) {

      if (i1L1 <= 100) {

        servo.moveServo(0, 40 - i1L1 * 0.2); //20
        servo.moveServo(1, 120 - i1L1 * 0.3); //90

        servo.moveServo(3, 180 + i1L1 * 0.1); //190
        servo.moveServo(4, 120 + i1L1 * 0.4); //160

        servo.moveServo(6, 180 - i1L1 * 0.2); //160
        servo.moveServo(7, 110 - i1L1 * 0.4); //70

        servo.moveServo(9, 40 + i1L1 * 0.1); //50
        servo.moveServo(10, 140 + i1L1 * 0.4); //180

        i1L1 += 4;

        if (i1L1 >= 100) {
          l1status = 8;
          dan = HIGH;
        }
      }
    }
    else if (l1status == 8) {

      if (i2L1 <= 100) {

        servo.moveServo(0, 20 + i2L1 * 0.3); //50
        servo.moveServo(1, 90 + i2L1 * 0.8); //170

        servo.moveServo(3, 190 - i2L1 * 0.3); //160
        servo.moveServo(4, 160 - i2L1 * 0.9); //70

        servo.moveServo(6, 160 + i2L1 * 0.3); //190
        servo.moveServo(7, 70 + i2L1 * 0.9); //160

        servo.moveServo(9, 50 - i2L1 * 0.3); //20
        servo.moveServo(10, 180 - i2L1 * 0.9); //90

        i2L1 += 4;

        if (i2L1 >= 100) {
          l1status = 9;
        }
      }
    }
    else if (l1status == 9) {

      if (i3L1 <= 100) {

        servo.moveServo(0, 50 - i3L1 * 0.3); //20
        servo.moveServo(1, 170 - i3L1 * 0.8); //90

        servo.moveServo(3, 160 + i3L1 * 0.3); //190
        servo.moveServo(4, 70 + i3L1 * 0.9); //160

        servo.moveServo(6, 190 - i3L1 * 0.3); //160
        servo.moveServo(7, 160 - i3L1 * 0.9); //70

        servo.moveServo(9, 20 + i3L1 * 0.3); //50
        servo.moveServo(10, 90 + i3L1 * 0.9); //180

        i3L1 += 4;

        if (i3L1 >= 100) {
          l1status = 8;
          legsReset();
          serialRead();
          Stop();
          if (m != 10) {
            if (m == 7) {
              attO = HIGH;
            }
            m = 10;
            l1status = 10;
            dan = LOW;
          }
        }
      }
    }
    else if (l1status == 10) {

      if (i3L1 <= 100) {

        servo.moveServo(0, 20 + i3L1 * 0.2); //40
        servo.moveServo(1, 90 + i3L1 * 0.3); //120

        servo.moveServo(3, 190 - i3L1 * 0.1); //180
        servo.moveServo(4, 160 - i3L1 * 0.4); //120

        servo.moveServo(6, 160 + i3L1 * 0.2); //180
        servo.moveServo(7, 70 + i3L1 * 0.3); //110

        servo.moveServo(9, 50 - i3L1 * 0.1); //40
        servo.moveServo(10, 180 - i3L1 * 0.4); //140

        i3L1 += 4;

        if (i3L1 >= 100) {
          l1status = 11;
          legsReset();
        }
        Serial.println("0");
      }
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    if (l1status == 11) {
      moveLeg1Up();
      moveLeg4Up();

      if (i1L1 >= 10 && i1L4 >= 10) {
        l1status = 12;
      }
      Serial.println("1");
    }
    else if (l1status == 12) {

      if (i2L1 <= 30 && i2L4 <= 30) {

        servo.moveServo(2, 200 - i2L1 * 2);//140
        servo.moveServo(11, 188 - i2L4 * 1.6);//140

        i2L1++;
        i2L4++;
      }
      if (i2L1 >= 30 && i2L4 >= 30) {
        l1status = 13;
      }
      Serial.println("2");
    }
    else if (l1status == 13) {
      i5L1 = 30;
      i5L4 = 30;
      moveLeg1Down();
      moveLeg4Down();

      if (i3L1 >= 10 && i3L4 >= 10) {
        l1status = 14;
      }
      Serial.println("3");
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    else if (l1status == 14) {
      moveLeg2Up();
      moveLeg3Up();

      if (i1L2 >= 10 && i1L3 >= 10) {
        l1status = 15;
      }
      Serial.println("4");
    }
    else if (l1status == 15) {

      if (i2L2 <= 30 && i2L3 <= 30) {

        servo.moveServo(5, 40 + i2L2 * 2);//100
        servo.moveServo(8, 31 + i2L3 * 2.3);//100

        i2L2++;
        i2L3++;
      }
      if (i2L2 >= 30 && i2L3 >= 30) {
        l1status = 16;
      }
      Serial.println("5");
    }
    else if (l1status == 16) {
      i5L2 = 30;
      i5L3 = 30;
      moveLeg2Down();
      moveLeg3Down();

      if (i3L2 >= 10 && i3L3 >= 10) {
        l1status = 17;
      }
      Serial.println("6");
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    else if (l1status == 17) {
      l1status = 1;
      legsStay();
      legsReset();
      STOP = LOW;
      m = 5;
      Stop();
      Serial.println("7");
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////

    delay(30);
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//moveLeg1Up(); / moveLeg1Left(); / moveLeg1Right(); / moveLeg1Down(); / moveLeg1LeftBack(); / moveLeg1RightBack(); / moveLeg1Reset();

void moveLeg1Up (void) {
  if (i1L1 <= 10) {
    servo.moveServo(0, 40 - i1L1 * 3);//10
    servo.moveServo(1, 120 - i1L1 * 7);//50

    i1L1++;
  }
}
void moveLeg1Left (void) {
  if (i2L1 <= 30) {

    servo.moveServo(2, 140 + i2L1 * 2.6);//218

    i2L1++;
  }
}
void moveLeg1Right (void) {
  if (i2L1 <= 30) {

    servo.moveServo(2, 140 - i2L1 * 3);//50

    i2L1++;
  }
}
void moveLeg1Down (void) {
  if (i2L1 > 20 && i3L1 <= 10 && i5L1 > 20) {

    servo.moveServo(0, 10 + i3L1 * 3);//40
    servo.moveServo(1, 50 + i3L1 * 7);//120

    i3L1++;
  }
}
void moveLeg1LeftBack (void) {
  if (i2L1 >= 30 && i4L1 <= 30) {

    servo.moveServo(2, 218 - i4L1 * 2.6);//140

    i4L1++;
    i5L1++;
  }
}
void moveLeg1RightBack (void) {
  if (i2L1 >= 30 && i4L1 <= 30) {

    servo.moveServo(2, 50 + i4L1 * 3);//140

    i4L1++;
    i5L1++;
  }
}
/////////////////////////////////////////////////////////
void moveLeg1LeftRight (void) {
  if (i4L1 <= 30) {

    servo.moveServo(2, 218 - i4L1 * 5.6);//50

    i4L1++;
    i5L1++;
  }
}
void moveLeg1RightLeft (void) {
  if (i4L1 <= 30) {

    servo.moveServo(2, 50 + i4L1 * 5.6);//218

    i4L1++;
    i5L1++;
  }
}
/////////////////////////////////////////////////////////
void moveLeg1Reset (void) {
  if (i4L1 >= 30) {
    i1L1 = 0;
    i2L1 = 0;
    i3L1 = 0;
    i4L1 = 0;
    i5L1 = 0;
    i6L1 = 0;
    i7L1 = 0;
    i8L1 = 0;
  }
}
///////////////////////////////////////////////
/////////////////////////////////////////////
//moveLeg2Up(); / moveLeg2Left(); / moveLeg2Right(); / moveLeg2Down(); / moveLeg2LeftBack(); / moveLeg2RightBack(); / moveLeg2Reset();

void moveLeg2Up (void) {
  if (i1L2 <= 10) {

    servo.moveServo(3, 180 + i1L2 * 4); //220
    servo.moveServo(4, 120 + i1L2 * 7); //190

    i1L2++;
  }
}
void moveLeg2Left (void) {
  if (i2L2 <= 30) {

    servo.moveServo(5, 100 + i2L2 * 3); //190

    i2L2++;
  }
}
void moveLeg2Right (void) {
  if (i2L2 <= 30) {

    servo.moveServo(5, 100 - i2L2 * 2.6); //22

    i2L2++;
  }
}
void moveLeg2Down (void) {
  if (i2L2 > 20 && i3L2 <= 10 && i5L2 > 20) {

    servo.moveServo(3, 220 - i3L2 * 4); //180
    servo.moveServo(4, 190 - i3L2 * 7); //120

    i3L2++;
  }
}
void moveLeg2LeftBack (void) {
  if (i2L2 >= 30 && i4L2 <= 30) {

    servo.moveServo(5, 190 - i4L2 * 3); //100

    i4L2++;
    i5L2++;
  }
}
void moveLeg2RightBack (void) {
  if (i2L2 >= 30 && i4L2 <= 30) {

    servo.moveServo(5, 22 + i4L2 * 2.6); //100

    i4L2++;
    i5L2++;
  }
}
/////////////////////////////////////////////////////////
void moveLeg2LeftRight (void) {
  if (i4L2 <= 30) {

    servo.moveServo(5, 190 - i4L2 * 5.6); //22

    i4L2++;
    i5L2++;
  }
}
void moveLeg2RightLeft (void) {
  if (i4L2 <= 30) {

    servo.moveServo(5, 22 + i4L2 * 5.6); //190

    i4L2++;
    i5L2++;
  }
}
/////////////////////////////////////////////////////////
void moveLeg2Reset (void) {
  if (i4L2 >= 30) {
    i1L2 = 0;
    i2L2 = 0;
    i3L2 = 0;
    i4L2 = 0;
    i5L2 = 0;
    i6L2 = 0;
    i7L2 = 0;
    i8L2 = 0;
  }
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//moveLeg3Up(); / moveLeg3Left(); / moveLeg3Right(); / moveLeg3Down(); / moveLeg3LeftBack(); / moveLeg3RightBack(); / moveLeg3Reset();

void moveLeg3Up (void) {
  if (i1L3 <= 10) {

    servo.moveServo(6, 180 + i1L3 * 4); //220
    servo.moveServo(7, 110 + i1L3 * 8); //190

    i1L3++;
  }
}
void moveLeg3Left (void) {
  if (i2L3 <= 30) {

    servo.moveServo(8, 100 - i2L3 * 2.6); //22

    i2L3++;
  }
}
void moveLeg3Right (void) {
  if (i2L3 <= 30) {

    servo.moveServo(8, 100 + i2L3 * 3); //190

    i2L3++;
  }
}
void moveLeg3Down (void) {
  if (i2L3 > 20 & i3L3 <= 10 && i5L3 > 20) {

    servo.moveServo(6, 220 - i3L3 * 4); //180
    servo.moveServo(7, 190 - i3L3 * 8); //110

    i3L3++;
  }
}
void moveLeg3LeftBack (void) {
  if (i2L3 >= 30 && i4L3 <= 30) {

    servo.moveServo(8, 22 + i4L3 * 2.6); //100

    i4L3++;
    i5L3++;
  }
}
void moveLeg3RightBack (void) {
  if (i2L3 >= 30 && i4L3 <= 30) {

    servo.moveServo(8, 190 - i4L3 * 3); //100

    i4L3++;
    i5L3++;
  }
}
/////////////////////////////////////////////////////////
void moveLeg3LeftRight(void) {
  if (i4L3 <= 30) {

    servo.moveServo(8, 22 + i4L3 * 5.6); //190

    i4L3++;
    i5L3++;
  }
}
void moveLeg3RightLeft (void) {
  if (i4L3 <= 30) {

    servo.moveServo(8, 190 - i4L3 * 5.6); //22

    i4L3++;
    i5L3++;
  }
}
/////////////////////////////////////////////////////////
void moveLeg3Reset (void) {
  if (i4L3 >= 30) {
    i1L3 = 0;
    i2L3 = 0;
    i3L3 = 0;
    i4L3 = 0;
    i5L3 = 0;
    i6L3 = 0;
  }
}
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//moveLeg4Up(); / moveLeg4Left(); / moveLeg4Right(); / moveLeg4Down(); / moveLeg4LeftBack(); / moveLeg4RightBack(); / moveLeg4Reset();

void moveLeg4Up (void) {
  if (i1L4 <= 10) {

    servo.moveServo(9, 40 - i1L4 * 3); //10
    servo.moveServo(10, 140 - i1L4 * 9); //50
    i1L4++;
  }
}
void moveLeg4Left (void) {
  if (i2L4 <= 30) {

    servo.moveServo(11, 140 - i2L4 * 3); //50
    i2L4++;
  }
}
void moveLeg4Right (void) {
  if (i2L4 <= 30) {

    servo.moveServo(11, 140 + i2L4 * 2.6); //218
    i2L4++;
  }
}
void moveLeg4Down (void) {
  if (i2L4 > 20 && i3L4 <= 10 && i5L4 > 20) {

    servo.moveServo(9, 10 + i3L4 * 3); //40
    servo.moveServo(10, 50 + i3L4 * 9); //140
    i3L4++;
  }
}
void moveLeg4LeftBack (void) {
  if (i2L4 >= 30 && i4L4 <= 30 ) {

    servo.moveServo(11, 50 + i4L4 * 3); //140
    i4L4++;
    i5L4++;
  }
}
void moveLeg4RightBack (void) {
  if (i2L4 >= 30 && i4L4 <= 30 ) {

    servo.moveServo(11, 218 - i4L4 * 2.6); //140
    i4L4++;
    i5L4++;
  }
}
/////////////////////////////////////////////////////////
void moveLeg4LeftRight (void) {
  if (i4L4 <= 30 ) {

    servo.moveServo(11, 50 + i4L4 * 5.6); //218
    i4L4++;
    i5L4++;
  }
}
void moveLeg4RightLeft (void) {
  if (i4L4 <= 30 ) {

    servo.moveServo(11, 218 - i4L4 * 5.6); //50
    i4L4++;
    i5L4++;
  }
}
/////////////////////////////////////////////////////////
void moveLeg4Reset (void) {
  if (i4L4 >= 30) {
    i1L4 = 0;
    i2L4 = 0;
    i3L4 = 0;
    i4L4 = 0;
    i5L4 = 0;
    i6L4 = 0;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void legsReset(void) {

  i1L1 = 0;
  i2L1 = 0;
  i3L1 = 0;
  i4L1 = 0;
  i5L1 = 0;
  i6L1 = 0;
  i7L1 = 0;
  i8L1 = 0;

  i1L2 = 0;
  i2L2 = 0;
  i3L2 = 0;
  i4L2 = 0;
  i5L2 = 0;
  i6L2 = 0;
  i7L2 = 0;
  i8L2 = 0;

  i1L3 = 0;
  i2L3 = 0;
  i3L3 = 0;
  i4L3 = 0;
  i5L3 = 0;
  i6L3 = 0;

  i1L4 = 0;
  i2L4 = 0;
  i3L4 = 0;
  i4L4 = 0;
  i5L4 = 0;
  i6L4 = 0;
}
void legsStay(void) {

  //Leg 1
  servo.moveServo(0, 40);//30
  servo.moveServo(1, 120);
  servo.moveServo(2, 140);

  //Leg 2
  servo.moveServo(3, 180);
  servo.moveServo(4, 120);
  servo.moveServo(5, 100);

  //Leg 3
  servo.moveServo(6, 180);//190
  servo.moveServo(7, 110);
  servo.moveServo(8, 100);

  //Leg 4
  servo.moveServo(9, 40);//30
  servo.moveServo(10, 140);
  servo.moveServo(11, 140);
}
void legsSit (void) {

  //Leg 1
  servo.moveServo(0, 10);
  servo.moveServo(1, 10);
  servo.moveServo(2, 190);

  //Leg 2
  servo.moveServo(3, 220);
  servo.moveServo(4, 220);
  servo.moveServo(5, 50);

  //Leg 3
  servo.moveServo(6, 220);
  servo.moveServo(7, 220);
  servo.moveServo(8, 50);

  //Leg 4
  servo.moveServo(9, 10);
  servo.moveServo(10, 20);
  servo.moveServo(11, 190);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void serialRead(void) {

  Serial.println ("SERIAL");

  while (Serial.available() > 0) {

    DATAin = Serial.read();

    if (DATAin == 'W') {
      if (STOP == LOW) {
        m = 1;
        STOP = HIGH;
        Serial.print("W");
      }
    }
    else  if (DATAin == 'S') {
      if (STOP == LOW) {
        m = 2;
        STOP = HIGH;
        Serial.print("S");
      }
    }
    else if (DATAin == 'D') {
      if (STOP == LOW) {
        m = 3;
        STOP = HIGH;
        Serial.print("D");
      }
    }
    else if (DATAin == 'A') {
      if (STOP == LOW) {
        m = 4;
        STOP = HIGH;
        Serial.print("A");
      }
    }
    else if (DATAin == 'T') {
      m = 5;
    }
    else if (DATAin == 'L') {
      if (STOP == LOW) {
        m = 6;
        STOP = HIGH;
      }
    }
    else if (DATAin == 'P') {
      if (STOP == LOW) {
        m = 13;  //7
        STOP = HIGH;
      }
    }
    else if (DATAin == 'O') {
      if (STOP == LOW) {
        m = 8;
        STOP = HIGH;
      }
    }
    else if (DATAin == 'V') {
      digitalWrite(led_pinH, LOW);
    }
    else if (DATAin == 'v') {
      digitalWrite(led_pinH, HIGH);
    }
    else if (DATAin == 'Q') {
      if (STOP == LOW) {
        m = 9;
      }
    }
    else if (DATAin == 'H') {
      if (STOP == LOW) {
        m = 10;
        STOP = HIGH;
      }
    }
    else if (DATAin == 'M') {
      m = 11;
    }
    else if (DATAin == 'N') {
      m = 12;
    }
    else if (DATAin == 'X') {
      conn = HIGH;
      digitalWrite(led_pinH, LOW);
      robotConnect();
      digitalWrite(led_pinH, HIGH);
      DATAin = 0;
    }
    else if (DATAin == 'x') {
      conn = LOW;
      digitalWrite(led_pinH, LOW);
      robotDisconnect();
      digitalWrite(led_pinH, HIGH);
      m = 7;
      STOP = LOW;
    }
    legsReset();
  }
  if (attP == HIGH) {
    attP = LOW;
    m = 7;
  }
  if (TimePrev > 1) {
    Stop();
  }
}

void control(void) {

  Serial.println ("CONTROL");


  if (STAND == HIGH) {

    switch (m) {

      case 1:
        moveForward();
        break;

      case 2:
        moveBackword();
        break;

      case 3:
        moveRight();
        break;

      case 4:
        moveLeft();
        break;

      case 5:
        legsStop();
        break;

      case 6:
        waving();
        break;

      case 7:
      case 13:
        sit();
        break;

      case 9:
        Attack();
        break;

      case 10:
        Dance();
        break;

      case 11:
        doomM();
        break;

      case 12:
        starWars();
        break;

      default:
        m = 0;
        break;
    }
  }
  else if (STAND == LOW) {

    switch (m) {

      case 8:
        stand();
        break;

      default:
        m = 0;
        break;
    }
  }
  if (conn == LOW) {

    if (millis() >= 1000 + prevCon) {
      preConnect();
      prevCon = millis();
    }
  }
  if (attO == HIGH) {
    m = 7;
    attO = LOW;
  }
  DATAin = 0;
}
void Stop (void) {

  Serial.println ("STOP_TIME");

  if (STAND == HIGH) {

    TimeNow = millis();

    if (TimeNow >= 300000 + TimePrev) { //300 000
      digitalWrite(led_pinS, LOW);
    }
    if (TimeNow >= 360000 + TimePrev) {//360 000
      m = 7;
      STOP = LOW;
    }
  }
}
