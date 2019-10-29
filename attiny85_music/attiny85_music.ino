/*
 * By tientn:
 * Pin3 connect to a button with GND line
 * Pin1 connect to Piezo Buzzer
 */
const int buttonPin = 3;
#define INT_PIN PB3
int Speaker = PB1;

byte count = 0;
boolean flgPlayMusic = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(buttonPin, INPUT_PULLUP);   // Set our interrupt pin as input with a pullup to keep it stable
  digitalWrite(buttonPin, HIGH);
  
  pinMode(Speaker, OUTPUT); //SPK
  
  cli();                            // Disable interrupts during setup
  GIMSK |= _BV(PCIE);                     // Enable Pin Change Interrupts
  PCMSK |= _BV(PCINT3);                   // Use PB3 as interrupt pin 
  ADCSRA &= ~_BV(ADEN);                   // ADC off
  sei();                            //last line of setup - enable interrupts after setup

}

// the loop routine runs over and over again forever:
void loop() {

  if (flgPlayMusic == 1) {
    playTuneLaCucaracha();
    flgPlayMusic = 0; //once only
  }

}

/* TinyTone for ATtiny85 */

// Notes
const int Note_C = 239;
const int Note_CS = 225;
const int Note_D = 213;
const int Note_DS = 201;
const int Note_E = 190;
const int Note_F = 179;
const int Note_FS = 169;
const int Note_G = 159;
const int Note_GS = 150;
const int Note_A = 142;
const int Note_AS = 134;
const int Note_B = 127;
const int Note_S = 255;

void TinyTone(unsigned char divisor, unsigned char octave, unsigned long duration)
{
  TCCR1 = 0x90 | (8-octave); // for 1MHz clock
  // TCCR1 = 0x90 | (11-octave); // for 8MHz clock
  OCR1C = divisor-1;         // set the OCR
  delay(duration);
  TCCR1 = 0x90;              // stop the counter
}

// Play a scale
void playTune(void)
{
 TinyTone(Note_C, 4, 500);
 TinyTone(Note_D, 4, 500);
 TinyTone(Note_E, 4, 500);
 TinyTone(Note_F, 4, 500);
 TinyTone(Note_G, 4, 500);
 TinyTone(Note_A, 4, 500);
 TinyTone(Note_B, 4, 500);
 TinyTone(Note_C, 5, 500);
}

void playTuneLaCucaracha(void)
{
  TinyTone(Note_C, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_C, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_C, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_F, 4, 600);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_A, 4, 600);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_C, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_C, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_C, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_F, 4, 600);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_A, 4, 800);
  TinyTone(Note_S, 1, 20);
  TinyTone(Note_F, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_F, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_E, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_E, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_D, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_D, 4, 200);
  TinyTone(Note_S, 1, 10);
  TinyTone(Note_C, 4, 1000);
}

void testPlayTone()
{
  count++;
  if(count < 5)
  {
    tone(Speaker,1471);
    delay(10);
    tone(Speaker,1575);
    delay(5);
  }
  else
  {
    tone(Speaker,1470);
    delay(10);
    tone(Speaker,1575);
    delay(5);
    if(count > 10)
    {
      count = 0;
    }
  }
}

ISR(PCINT0_vect)
{
  if( digitalRead(INT_PIN) == HIGH ) {
    if (flgPlayMusic == 0) {
      flgPlayMusic = 1;
    }
    else {
      flgPlayMusic = 0;
    }
  }
  //don't call blocking function like playTune in interrupt
}
