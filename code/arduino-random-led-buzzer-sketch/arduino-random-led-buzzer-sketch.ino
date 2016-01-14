long randNumber;
long delayvalue = 100;
int pin_tone = 8; //Buzzer has to be a PWM pin.

int x = 0;
int y = 18;

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(pin_tone, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pin_tone);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  long r = myRandomNumber(x, y);
  Serial.print("R:");
  Serial.println(r);
  delay(delayvalue);
}

int myRandomNumber(int x, int y) {
  // print a random number from 0 to 299
  //randNumber = random(300);
  //Serial.println(randNumber);

  // print a random number from 0 to 17
  return random(0, 18);
}

// On Stop, Flash.
void blinkmylight(int light){}
