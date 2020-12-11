void robotOn(void) {
  for (int i = 800; i <= 1200; i += 100) {

    tone(buzzer, i, 100);
    delay(100);
  }
  noTone(buzzer);
  delay(100);
}
void preConnect(void) {
  tone(buzzer, 500, 250);
  delay(250);
  tone(buzzer, 900, 150);
  delay(150);
  noTone(buzzer);
}
void robotDisconnect(void) {
  delay(100);
  tone(buzzer, 1100, 100);
  delay(100);
  tone(buzzer, 350, 200);
  delay(200);
  noTone(buzzer);
  delay(100);
}
void robotConnect(void) {
  delay(100);
  tone(buzzer, 1400, 100);
  delay(100);
  tone(buzzer, 600, 150);
  delay(150);
  noTone(buzzer);
  delay(100);
}
void megalov(void) {

  if (count == meGA && millis() >= megaPul[count - 1] + prev) {

    tone(buzzer, megaNote[count - 1], megaPul[count - 1]);

    if (Meg == LOW) {
      Meg = HIGH;

    } else {

      Meg = LOW;
    }
    prev = millis();
    Serial.println(count);

    if (count == 168) {
      count = 1;
      meGA = 1;

    } else {

      count++;
      meGA++;
    }
  }
}
void doomM(void) {

  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    if (Do == LOW) {
      digitalWrite(led_pinH, LOW);
      Do = HIGH;

    } else if (Do == HIGH) {
      digitalWrite(led_pinH, HIGH);
      Do = LOW;
    }

    divider = pgm_read_word_near(melody + thisNote + 1);
    if (divider > 0) {
      noteDuration = (wholenote) / divider;

    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }

    tone(buzzer, pgm_read_word_near(melody + thisNote), noteDuration * 0.9);

    delay(noteDuration);

    noTone(buzzer);

    serialRead();
    Stop();

    if (m == 5 || m == 7) {

      if (m == 7) {
        attP = HIGH;
      }
      m = 0;
      break;
    }
  }
  digitalWrite(led_pinH, HIGH);
  Do = LOW;
}
void starWars(void) {

  for (int i = 0; i <= 73; i++) {

    if (Do == LOW) {
      digitalWrite(led_pinH, LOW);
      Do = HIGH;

    } else if (Do == HIGH) {
      digitalWrite(led_pinH, HIGH);
      Do = LOW;
    }
    tone(buzzer, starNote[i], starPul[i]);
    delay(starPul[i]);

    serialRead();
    Stop();

    if (m == 5 || m == 7) {

      if (m == 7) {
        attP = HIGH;
        m = 0;
      }
      break;
    }
    noTone(buzzer);
  }
  digitalWrite(led_pinH, HIGH);
  Do = LOW;
}
