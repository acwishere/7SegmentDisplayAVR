hex:
	avr-gcc -Os -DF_CPU=8000000 -mmcu=atmega328p -c segDispTest.c
	avr-gcc -DF_CPU=8000000 -mmcu=atmega328p -o segDispTest.elf segDispTest.o
	avr-objcopy -O ihex segDispTest.elf segDispTest.hex
	rm segDispTest.o
	rm segDispTest.elf



flash:
	avrdude -c arduino -p  m328p -P /dev/ttyACM0 -U flash:w:segDispTest.hex


clean:
	rm segDispTest.hex
