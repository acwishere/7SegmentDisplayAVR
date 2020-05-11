// 7-SEGMENT 4-DIGIT LED DISPLAY LIBRARY (for common anode display)//


// DEFINES
// -----------------------

// BYTE VALUES ARE READ LEFT TO RIGHT. 1 OUTPUTS A HIGH SIGNAL TO A SEGMENT, 0 OUTPUTS LOW. 
// A, B, C, D, E, F, G, DP 

//UPPERCASE LETTERS


#define LETTER_A 0b11101110
#define LETTER_C 0b10011100
#define LETTER_E 0b10011110
#define LETTER_F 0b10001110
#define LETTER_H 0b01101110
#define LETTER_L 0b00011100
#define LETTER_I 0b00001100
#define LETTER_O 0b11111100
#define LETTER_P 0b11001110
#define LETTER_S 0b10110110
#define LETTER_G 0b10111110
#define LETTER_J 0b01111000
#define LETTER_U 0b01111100

//LOWERCASE LETTERS

#define LETTER_b 0b00111110
#define LETTER_c 0b00011010
#define LETTER_d 0b01111010
#define LETTER_h 0b00101110
#define LETTER_n 0b00101010
#define LETTER_o 0b00111010
#define LETTER_r 0b00001010
#define LETTER_u 0b00111000
#define LETTER_y 0b01110110
//NUMBERS

#define NUM_0 0b11111100 
#define NUM_1 0b01100000
#define NUM_2 0b11011010
#define NUM_3 0b11110010
#define NUM_4 0b01100110
#define NUM_5 0b10110110
#define NUM_6 0b10111110
#define NUM_7 0b11100000
#define NUM_8 0b11111110
#define NUM_9 0b11110110

//SPECIAL

#define BLANK 0b00000000
#define DP 0b00000001
#define VERTICAL_LINES 0b01101100
#define HORIZONTAL_LINES 0b10010010
#define TOP_LINE 0b10000000
#define MIDDLE_LINE 0b00000010
#define BOTTOM_LINE 0b00010000
#define TOP_VERTICAL_LINES 0b01000100
#define BOTTOM_VERTICAL_LINES 0b00101000
#define LEFT_VERTICAL_LINES 0b00001100
#define RIGHT_VERTICAL_LINES 0b01100000
#define TOP_BOTTOM_LINES 0b10010000
#define TOP_MIDDLE_LINES 0b10000010
#define MIDDLE_BOTTOM_LINES 0b00010010
#define ALL_SEGMENTS 0b11111111



//DELAY TIME
#define DELAY_TIME 5 

//END OF DEFINES
//---------------------------

//PIN SETUP AND INITIALIZATION
//----------------------------


int segDispA;
int segDispB;
int segDispC; 
int segDispD;
int segDispE;
int segDispF;
int segDispG;
int segDispD1;
int segDispD2; 
int segDispD3;
int segDispD4;  
int segDispDP; 

// Arrays to hold pin values
int segmentPins[8];
int digitPins[4];
volatile uint8_t *segmentPorts[8];
volatile uint8_t *digitPorts[4];

// Function you must call to initialize the four digit pins.
void SegDisp_4D_initDigitPins(int D1, int D2, int D3, int D4){

digitPins[0] = D1;
digitPins[1] = D2;
digitPins[2] = D3;
digitPins[3] = D4;


}

// Function you must call to initialize the segment pins.
void SegDisp_4D_initSegmentPins(int dp, int A, int B, int C, int D, int E, int F, int G){

segmentPins[0] = dp;
segmentPins[1] = G;
segmentPins[2] = F;
segmentPins[3] = E;
segmentPins[4] = D;
segmentPins[5] = C;
segmentPins[6] = B;
segmentPins[7] = A;


}

//Function you must call matching up the ports with the segment pins. This is necessary in case of a situation where some I/O pins are on different ports of your chip.
void SegDisp_4D_initSegmentPorts(volatile uint8_t *portDp, volatile uint8_t *portA, volatile uint8_t *portB, volatile uint8_t *portC, volatile uint8_t *portD, volatile uint8_t *portE, volatile uint8_t *portF, volatile uint8_t *portG){


segmentPorts[0] = portDp;	
segmentPorts[1] = portG;	
segmentPorts[2] = portF;	
segmentPorts[3] = portE;	
segmentPorts[4] = portD;	
segmentPorts[5] = portC;	
segmentPorts[6] = portB;	
segmentPorts[7] = portA;	

}

//Function you must call matching up ports with digit pin values.
void SegDisp_4D_initDigitPorts(volatile uint8_t *digitPort1, volatile uint8_t *digitPort2, volatile uint8_t *digitPort3, volatile uint8_t *digitPort4){

digitPorts[0] = digitPort1;
digitPorts[1] = digitPort2;
digitPorts[2] = digitPort3;
digitPorts[3] = digitPort4;



}
//END OF PIN/PORT SETUP AND INITILIZATION
//----------------------------------

//HELPER FUNCTIONS
//----------------------------------


//Arrays below  hold uint8_t values of all possible display options. These arrays are mostly used for the testing function.


const uint8_t SegDisp_4D_special[15] = {DP, VERTICAL_LINES, HORIZONTAL_LINES, TOP_LINE, MIDDLE_LINE, BOTTOM_LINE, TOP_VERTICAL_LINES, BOTTOM_VERTICAL_LINES, LEFT_VERTICAL_LINES, RIGHT_VERTICAL_LINES, TOP_BOTTOM_LINES, TOP_MIDDLE_LINES, MIDDLE_BOTTOM_LINES, ALL_SEGMENTS};
 
const uint8_t SegDisp_4D_numbers[10] = {NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9};

const uint8_t SegDisp_4D_letters[22] = {LETTER_A, LETTER_C, LETTER_E, LETTER_F,LETTER_H, LETTER_L, LETTER_I, LETTER_O, LETTER_P, LETTER_S, LETTER_G, LETTER_J, LETTER_U, LETTER_b, LETTER_c, LETTER_d, LETTER_h, LETTER_n, LETTER_o, LETTER_r, LETTER_u, LETTER_y};

void SegDisp_4D_clearSegmentPins(){

for (int i = 0; i < 8; i++) {
	
	*(segmentPorts[i]) &= ~(1 << segmentPins[i]);
}
};



void SegDisp_4D_enableAllDigitPins(){

for (int i = 0; i<4; i++) {
	
	*(digitPorts[i]) &= ~(1<< digitPins[i]);		
	
}

}

void SegDisp_4D_disableAllDigitPins(){

for (int i = 0; i<4; i++) {
	
	*(digitPorts[i]) |= (1<< digitPins[i]);		
	
}

}





//END OF HELPER FUNCTIONS
//----------------------------

//MAIN WRITE FUNCTION
//----------------------------

void SegDisp_4D_writeToDisplay(uint8_t first, uint8_t second, uint8_t third, uint8_t fourth){

// moving inputted letter/number uint8_t values to an array to be used in loop.	
const uint8_t charactersToDisplay[4] = {first, second, third, fourth};
	
		
for(int i = 0; i<4; i++) {

// clears segment pins "buffer"  before writing new character or number to the digit pin.
SegDisp_4D_clearSegmentPins();       

// enables the digit pin to be written to, set low for common anode display. 
*(digitPorts[i]) &= ~(1 << digitPins[i]);

// writes the correct segment pins according to letter or number inputted.
for(int j = 0; j<8; j++)
	{	
	
	// using bitwise operation to check for 1 or 0 for letter or number you call, and sets the segment pin high or low accordingly.
	*(segmentPorts[j]) |= ((charactersToDisplay[i] >> j) & 1) << segmentPins[j];	
	
	}

// _delay_ms is crucial to have display output show clearly.
_delay_ms(DELAY_TIME);

// disables digit pin so next digit pin can be activated. 
*(digitPorts[i]) |= (1 << digitPins[i]);

}
		

} 

//END OF MAIN WRITE FUNCTION
//---------------------------


//TESTING FUNCTION
//--------------------------
//Testing function runs through all letters, numbers and special characters to ensure that the display is working correctly.

void SegDisp_4D_testDisplay(){


	SegDisp_4D_enableAllDigitPins();

	
	
	for (int i = 0; i < 10; i++){
		_delay_ms(100);
		SegDisp_4D_writeToDisplay(SegDisp_4D_numbers[i], SegDisp_4D_numbers[i], SegDisp_4D_numbers[i], SegDisp_4D_numbers[i]);

	}

	for (int i  = 0; i< 22; i++){

		_delay_ms(100);
		SegDisp_4D_writeToDisplay(SegDisp_4D_letters[i], SegDisp_4D_letters[i], SegDisp_4D_letters[i], SegDisp_4D_letters[i]);
			

	}


	for (int i = 0; i <15; i++) {

		_delay_ms(100);
		SegDisp_4D_writeToDisplay(SegDisp_4D_special[i], SegDisp_4D_special[i], SegDisp_4D_special[i], SegDisp_4D_special[i]);


	}

	for (int i = 0; i<50; i++) {

		_delay_ms(100);
		SegDisp_4D_writeToDisplay(LETTER_F, LETTER_I, LETTER_n, DP);	



	}
}

//END OF TESTING FUNCTION
//--------------------------

