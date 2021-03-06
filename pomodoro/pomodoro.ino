/**************/
/*  POMODORO  */
/**************/

/** @freddyiniguez **/
#include "pitches.h"

/**
 * Variables section
 */
int pomodoro = 2;
int long_break = 4;
int short_break = 7;
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
};

int noteDurations[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12
};


/**
 * Method: setup()
 * Runs once at boot.
 */
void setup() {
  pinMode(pomodoro, OUTPUT);
  pinMode(long_break, OUTPUT);
  pinMode(short_break, OUTPUT);
}


/**
 * Method: loop()
 * Runs everytime.
 */
void loop() {
  digitalWrite(pomodoro, HIGH);
  digitalWrite(long_break, HIGH);
  digitalWrite(short_break, HIGH);

  // Pomodoro STARTS
  tone_alarm();
  colorful_signal();
  digitalWrite(pomodoro, HIGH);
  delay(1500000);
  
  // Short break STARTS
  tone_alarm();
  colorful_signal();
  digitalWrite(short_break, HIGH);
  delay(300000);
}


/**
 * Method: tone_alarm()
 * This method is used to play a tone for timers
 */
void tone_alarm() {
  for (int thisNote = 0; thisNote < 16; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(12, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(12);
  }
}


/**
 * Method: colorful_signal()
 * This method is ised to turn ON and OFF LEDs for timers
 */
void colorful_signal() {
  digitalWrite(pomodoro, LOW);
  digitalWrite(long_break, LOW);
  digitalWrite(short_break, LOW);
  
  digitalWrite(pomodoro, HIGH);
  delay(500);
  digitalWrite(long_break, HIGH);
  delay(500);
  digitalWrite(short_break, HIGH);
  delay(500);

  digitalWrite(pomodoro, LOW);
  digitalWrite(long_break, LOW);
  digitalWrite(short_break, LOW);

  digitalWrite(pomodoro, HIGH);
  delay(500);
  digitalWrite(long_break, HIGH);
  delay(500);
  digitalWrite(short_break, HIGH);
  delay(500);

  digitalWrite(pomodoro, LOW);
  digitalWrite(long_break, LOW);
  digitalWrite(short_break, LOW);
}

