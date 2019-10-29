/*
 * By tientn:
 * Pin3 connect to a button with GND line
 * Pin1 connect to LED
 */
const int buttonPin = 3;
#define INT_PIN PB3
#define LED_PIN PB1

int Speaker = PB1;
byte count = 0;
boolean flgLEDOnMode = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(buttonPin, INPUT_PULLUP);   // Set our interrupt pin as input with a pullup to keep it stable
  digitalWrite(buttonPin, HIGH);
  
  pinMode(LED_PIN, OUTPUT); //LED on Model B
  
  cli();                            // Disable interrupts during setup
  GIMSK |= _BV(PCIE);                     // Enable Pin Change Interrupts
  PCMSK |= _BV(PCINT3);                   // Use PB3 as interrupt pin 
  ADCSRA &= ~_BV(ADEN);                   // ADC off
  sei();                            //last line of setup - enable interrupts after setup

}

// the loop routine runs over and over again forever:
void loop() {

}

ISR(PCINT0_vect)
{
  if( digitalRead(INT_PIN) == HIGH ) {
    if (flgLEDOnMode == 0) {
      flgLEDOnMode = 1;
    }
    else {
      flgLEDOnMode = 0;
    }
  }

  if (flgLEDOnMode == 1) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
}
