/*
  Arduino Uno Ultrasonic Musical Keyboard
  Version 2.1
  By: 1487Quantum (https://github.com/1487quantum)
*/
#include <U8x8lib.h>

//Pins
#define SPPIN 8         //Speaker
#define USPIN 9         //Ultrasound

//Display
#define WD 128
#define HG 64

//Tone
#define ITVL  5         //Interval between each note (cm)
#define T_LEN 13        //Number of notes available

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

bool idle = 1;          //When notes are not playing

//Tones
int notes[] = {
  262, //NOTE_C4
  277, //NOTE_CS4
  294, //NOTE_D4
  311, //NOTE_DS4
  330, //NOTE_E4
  349, //NOTE_F4
  370, //NOTE_FS4
  392, //NOTE_G4
  415, //NOTE_GS4
  440, //NOTE_A4
  466, //NOTE_AS4
  494, //NOTE_B4
  523  //NOTE_C5
};
char* names[] = { " C", " C#", " D", " D#", " E", " F", " F#", " G", " G#", " A", " A#", " B" , " C5"};

//Ultrasound
long duration, dist;

//Logo
void logo() {
  u8x8.print("1487QUANTUM");
}

//Startup screen
void splash() {
  //Display
  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setCursor(3, 2);
  u8x8.print("USM Keyboard");
  u8x8.inverse();
  u8x8.setCursor(6, 4);
  u8x8.print("V2.1");
  u8x8.noInverse();
  u8x8.setCursor(6, 6);

  delay(4000);
  u8x8.clearDisplay();
  //u8x8.setFlipMode(1);
}

void setup() {
  //Speaker->8, Ultrasound->9
  DDRD |= 0b11111110; // set digital  1,2- 7 to output
  DDRB = 0b00111111; // set digital  8-13 to output

  //For Maker Uno: Turn off all onboard LEDS
  PORTD &= 0;
  PORTB &= 0;

  splash();
}

//Display
void draw(void) {
  //Font list: https://github.com/olikraus/u8g2/wiki/fntlist8x8

  //Display notes/dist
  //Draw str
  char bufN[16];   //Note
  char bufI[16];  //ID
  sprintf (bufN, "%s ", (dist > 9 && dist <= T_LEN * ITVL) ? names[(dist - 10) / ITVL ] : "._.");
  sprintf (bufI, "DIST: %dCM ", dist);
  u8x8.setFont(u8x8_font_saikyosansbold8_u);
  u8x8.draw2x2String(5, 2, bufN);
  u8x8.setFont(u8x8_font_victoriabold8_u );

  if (idle) {
    u8x8.setFont(u8x8_font_pxplusibmcga_u );
    u8x8.setCursor(3, 7);
    logo();
  } else {
    u8x8.drawString(3, 7, bufI);
  }
  delay(100);
}

void loop()
{
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(USPIN, OUTPUT);
  digitalWrite(USPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(USPIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(USPIN, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(USPIN, INPUT);
  duration = pulseIn(USPIN, HIGH);

  // convert the time into a distance
  dist = microsecondsToCentimeters(duration);

  if (dist > 9 && dist < T_LEN * ITVL) {
    tone(SPPIN, notes[(dist - 10) / ITVL], 500);
    idle = 0;
  } else {
    noTone(SPPIN);
    idle = 1;
  }
  draw();
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
