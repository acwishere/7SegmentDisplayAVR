// AVR 7 SEGMENT DISPLAY EXAMPLE (COMMON ANODE) //


#ifndef F_CPU
#define F_CPU 16000000UL
#endif


#include <avr/io.h>
#include <util/delay.h>
#include "libraries/7Segment1DigitDisplay.c"
#include "libraries/7Segment4DigitDisplay.c"


int main(void){

//MANUALLY SET PINS AS OUTPUT.

//Segment Pins (for both 1 digit and 4 digit display)	
DDRB |= 1 << PINB1; // DP
DDRD |= 1 << PIND2; // SEGMENT A
DDRD |= 1 << PIND3; // SEGMENT B
DDRD |= 1 << PIND4; // SEGMENT C
DDRD |= 1 << PIND5; // SEGMENT D
DDRD |= 1 << PIND6; // SEGMENT E
DDRD |= 1 << PIND7; // SEGMENT F
DDRB |= 1 << PINB0; // SEGMENT G






//Digit Pins (required for 4 digit display)
DDRC |= 1 << PINC0; //D1
DDRC |= 1 << PINC1; //D2
DDRC |= 1 << PINC2; //D3
DDRC |= 1 << PINC3; //D4


//1 DIGIT PIN VARIATION
//--------------------

//SegDisp_1D_initSegmentPins(PINB1, PIND2, PIND3, PIND4, PIND5, PIND6, PIND7, PINB0);

//SegDisp_1D_initSegmentPorts(&PORTB,&PORTD,&PORTD,&PORTD,&PORTD,&PORTD,&PORTD,&PORTB);

//SegDisp_1D_setAllPinsToOutput();

//SegDisp_1D_testDisplay();

//4 DIGIT PIN VARIATION
//---------------------

//INITIALIZED IN THE ORDER "DP, A, B, C, D, E, F, G"
SegDisp_4D_initSegmentPins(PINB1, PIND2, PIND3, PIND4, PIND5, PIND6, PIND7, PINB0);

//INITIALIZED IN THE ORDER "D1, D2, D3, D4"
SegDisp_4D_initDigitPins(PINC0, PINC1, PINC2, PINC3);

//MATCH UP PORTS INITIALIZED IN THE ORDER "DP, A, B, C, D, E, F, G"
SegDisp_4D_initSegmentPorts(&PORTB,&PORTD,&PORTD,&PORTD,&PORTD,&PORTD,&PORTD,&PORTB);

//MATCH UP PORTS INITIALIZED IN THE ORDER "D1, D2, D3, D4"
SegDisp_4D_initDigitPorts(&PORTC, &PORTC, &PORTC, &PORTC);

//TESTING FUNCTION RUNS THROUGH ALL CHARACTERS, LETTERS AND NUMBERS. DISPLAYS ~ F I N . ~  WHEN FINISHED.
SegDisp_4D_testDisplay();

while(1){

//FOR 4 DIGIT DISPLAY, WRITE TO DISPLAY METHOD  MUST HAVE 4 ARGUMENTS FOR EACH DIGIT. BLANK CAN BE USED TO HAVE EMPTY SPACE. REFER TO LIBRARY FILE FOR THE PROPER DEFINES FOR CERTAIN LETTERS, NUMBERS, AND CHARACTERS.

//EX.

//LETTER_A = DISPLAYS AN "A"
//BLANK = DISPLAYS EMPTY
//NUM_1 = DISPLAYS NUMBER 1
//DP = DISPLAYS ONLY DECIMAL POINTS
//ALL_SEGMENTS = DISPLAYS ALL SEGMENTS

SegDisp_4D_writeToDisplay(NUM_1, NUM_2, NUM_3, NUM_4);

//SegDisp_1D_writeToDisplay(LETTER_A);

	

}








}
