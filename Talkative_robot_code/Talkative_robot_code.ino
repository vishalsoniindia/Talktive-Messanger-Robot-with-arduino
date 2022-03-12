/**
 * Text To Speech synthesis library
 * Copyright (c) 2008 Clive Webster.  All rights reserved.
 *
 * Nov. 29th 2009 - Modified to work with Arduino by Gabriel Petrut:
 * The Text To Speech library uses Timer1 to generate the PWM
 * output on digital pin 10. The output signal needs to be fed
 * to an RC filter then through an amplifier to the speaker.
 * http://www.tehnorama.ro/minieric-modulul-de-control-si-sinteza-vocala/
 *
 * Modified to allow use of different PWM pins by Stephen Crane.
 */
#include <TTS.h>
#include <SoftwareSerial.h>

// Media pins
#define PWM 10
#define LED 13

SoftwareSerial mySerial(5, 6); // RX, TX

TTS text2speech(PWM);  // default is digital pin 10

void setup() { 
  pinMode(LED, OUTPUT); 
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.setTimeout(10);
  text2speech.setPitch(10);
  text2speech.sayText("hello i am your, roboat"); 
}

void loop() {
  while(mySerial.available()>0){
  String str = mySerial.readString();
  int str_len = str.length() + 1;
  char char_array[str_len];
  text2speech.setPitch(10);
  str.toCharArray(char_array, str_len);
  text2speech.sayText(char_array); 
  Serial.print(str);
  delay(1000);
  }
  }

 
