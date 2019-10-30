/*
 * By tientn:
 * Pin3 connect to a button with GND line
 * Pin1 connect to LED
 * https://github.com/nickgammon/SendOnlySoftwareSerial
 */
#include <SendOnlySoftwareSerial.h>

const int buttonPin = 3;
#define INT_PIN PB3
#define LED_PIN PB1

int Speaker = PB1;
byte count = 0;
boolean flgLEDOnMode = 0;

// While the processing code is common, the pins used are device specific
#if defined(__AVR_ATtiny84__) || defined(__AVR_ATtiny84A__)
  #define ledPin  4               // Toggle to turn connected Led on/off
  #define txPin   10              // Pin used for Serial transmit
#elif defined(__AVR_ATtiny85__)
  #define ledPin  1
  #define txPin   4
#else
  #error Only ATiny84 and ATtiny85 are Supported by this Project
#endif

// Create instance of the Software Serial class specifying which device
// pins are to be used for receive and transmit
SendOnlySoftwareSerial mySerial(txPin);

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

  delay(3000); 
  mySerial.begin(9600);       // Start serial processing      
  delay(2000);                // Give Serial class time to complete initialization.
                              // otherwise, 1st output likely missing or garbled
  //mySerial.txMode();    //before sending a message, switch to txMode
  //mySerial.rxMode();    //switch back to rxMode to wait for comms

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

    mySerial.println("My test");
    delay(1000);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
}
