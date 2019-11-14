/*
 * By tientn:
 * Pin3 connect to a button with GND line
 * Pin1 connect to Piezo Buzzer
 * https://github.com/nickgammon/SendOnlySoftwareSerial
 */
#include <SendOnlySoftwareSerial.h>

const int buttonPin = 3;
#define INT_PIN PB3

int Speaker = PB1;
byte count = 0;
boolean flgPlayMusic = 0;

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

void playTuneVuonCayCuaBa(void) {
  //1/16 = 100
  //1 = 1600
  //1/8 = 200
  //1/4 = 400
  

  //Ma trong 
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_B, 3, 200); 
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_D, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_G, 2, 400);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_A, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 400);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 200); //Con ba trong
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_D, 2, 200); 
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_E, 2, 400); //Cay xu xi
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_C, 2, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_C, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 200);
      TinyTone(Note_S, 1, 7);
  
  //cai gai buoi
  TinyTone(Note_B, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 100); //connect with 
  TinyTone(Note_B, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 400);
  TinyTone(Note_S, 1, 123);
  
  //trai sau rieng
  TinyTone(Note_D, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_A, 3, 400);
      TinyTone(Note_S, 1, 7);
  //Nhua hot dieu
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 3, 400);
  TinyTone(Note_S, 1, 123);
  
  //Cay dua cao
  TinyTone(Note_C, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_C, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_D, 3, 400);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 3, 200);
  TinyTone(Note_S, 1, 123);
  
  //Cay ba trong
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 100);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_G, 2, 200);
  TinyTone(Note_S, 1, 123);
  
  //Mua
  TinyTone(Note_A, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_D, 2, 200); //connect to 
  TinyTone(Note_E, 2, 400);
      TinyTone(Note_S, 1, 7);
  //Than san sui
  TinyTone(Note_D, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_C, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_C, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_D, 2, 400);
      TinyTone(Note_S, 1, 7);
  //canh gai goc
  TinyTone(Note_G, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 200);
  TinyTone(Note_S, 1, 123);
  TinyTone(Note_A, 3, 200); //connect 
  TinyTone(Note_B, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_G, 2, 200); //connect 
  TinyTone(Note_D, 3, 200);
  TinyTone(Note_S, 1, 123);
  
  //Buoi sau rieng
  TinyTone(Note_A, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_C, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_A, 3, 200); //connect 
  TinyTone(Note_B, 3, 400);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 100);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_E, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_E, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_A, 2, 200);
      TinyTone(Note_S, 1, 7);
  //Vuon cua ba
  TinyTone(Note_A, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_C, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 100);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_E, 2, 400);
      TinyTone(Note_S, 1, 7);
  //Ma trai nao
  TinyTone(Note_D, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_B, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 2, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_F, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_F, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_F, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 200);
  TinyTone(Note_S, 1, 123);
  
  TinyTone(Note_G, 2, 400);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_G, 2, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 200);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_A, 3, 100);
      TinyTone(Note_S, 1, 7);
  TinyTone(Note_D, 3, 100);

}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(buttonPin, INPUT_PULLUP);   // Set our interrupt pin as input with a pullup to keep it stable
  digitalWrite(buttonPin, HIGH); //set it to high to ensure it will go low on push
  
  pinMode(Speaker, OUTPUT); //SPK
  
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

  if (flgPlayMusic == 1) {
    //digitalWrite(LED_PIN, HIGH);

    //send out a byte
    unsigned char iRndNum = 4;
    mySerial.print(iRndNum);

    flgPlayMusic = 0;
    playTuneVuonCayCuaBa();

  }
  else {
    //digitalWrite(LED_PIN, LOW);
  }

}

ISR(PCINT0_vect)
{
  if( digitalRead(INT_PIN) == HIGH ) {
    delay(10); //clear noise
    //if still pushed
    if( digitalRead(INT_PIN) == HIGH ) {
      if (flgPlayMusic == 0) {
        flgPlayMusic = 1;
      }
      else {
        flgPlayMusic = 0;
      }
    }   
  }

}
