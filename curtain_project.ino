
#include "Stepper.h"
#include "IRremote.h"

/*----- Variables, Pins -----*/
int receiver = 13; // Signal Pin of IR receiver to Arduino Digital Pin 6

IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'

const int stepPin = 11;
const int dirPin = 12;
const int enablePin = 10;

boolean onTime = false;  //a variable that we will use to determine if we want to activate the curtain based on a time
boolean opened = false;  //keep track if we are open or closed


// Setup Function
// Description: turns 
void setup() {
  // put your setup code here, to run once:
  irrecv.enableIRIn(); // Start the receiver
  
  pinMode(enablePin, OUTPUT);  // We set the enable pin to be an output
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(enablePin, HIGH);  // set enable pin high to disable the driver.
  digitalWrite(stepPin, LOW);  //set step pin low i.e. off
}

void loop() {
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    switch(results.value)

    {

      case 0xFFA857: // VOL+ button pressed
                      openCurtain();
                      delay(100); 
                      break;

      case 0xFF629D: // VOL- button pressed
                      closeCurtain();
                      delay(100); 
                      break;
                
    }
    
      irrecv.resume(); // receive the next value
                 digitalWrite(8, LOW);
                 digitalWrite(9, LOW);
                 digitalWrite(10, LOW);
                 digitalWrite(11, LOW);       
  }  
  // Place code to read time and check if it's alarm day + alarm time to open, or sunset+x to close.
}

void openCurtain(){
  if (opened == false) {
    digitalWrite(enablePin, LOW);
    delayMicroseconds(2);
    digitalWrite(dirPin, LOW);
    for(int i=0; i<=100*165; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(700);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2);
    }
    digitalWrite(enablePin, HIGH);
    delayMicroseconds(2);
    opened = true;
  }
   
}

void closeCurtain(){
  if (opened == true) {
    digitalWrite(enablePin, LOW);
    delayMicroseconds(2);
    digitalWrite(dirPin, HIGH);
    for(int i=0; i<=100*165; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(700);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2);
    }
    digitalWrite(enablePin, HIGH);
    delayMicroseconds(2);
    opened = false;
  }
}
