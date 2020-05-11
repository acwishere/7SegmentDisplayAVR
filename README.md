# 7SegmentDisplayAVR
7 Segment Display libraries and example code in AVR C. One library is for the 1-Digit variation display, 
the other is for the 4-Digit variation (both common anode). Includes a makefile. 

All defines for certain letters, characters and special characters are in the libraries themselves. For 
example, LETTER_A denotes the character "A". NUM_3 denotes the number 3. VERTICAL_LINES will display vertical lines on display. 

Using the writeToDisplay method for 1 Digit requires only one define macro argument.
Using the writeToDisplay method for 4 Digit requires foru define macro arguments.

Pins must be set for output manually. You must replace these values in segDispTest.c
Initialization methods are provided, 8 arguments for segment pins, 4 arguments for digit pins. 
You must also provide the corresponding ports in another initialization method from library. For example, pin DP is in PINB0, 
using &PORTB.

Segment pins are initialized in order (DP, A, B, C, D, E, F, G);
Digit pins are initialized in order (DIGIT PIN 1, DIGIT PIN 2, DIGIT PIN 3, DIGIT PIN 4).
The same goes for the ports.

STEPS TO GET STARTED (This is designed with linux terminal environment in mind.)

1. Install AVR-GCC toolchain.

2. Get this repository into your own directory.

3. Make sure in the makefile your own config is setup (mcu unit, programmer, device ports, etc.)

4. Make sure segDispTest.c contains your own configuration for ports and pins. Set pins to output manually and use initialization 
methods from the library for both the segment pins(digit pins if using 4-digit display) and the matching segment ports(digit ports if 
using 4-digit display). 

3. Typing "make" will make an example hex file called segDispTest.hex from segDispTest.c. 

4. Typing "make flash" will flash the program to your mcu.

5. Typing "make clean" will remove the hex file.
