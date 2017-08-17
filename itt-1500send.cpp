/*
Usage: ./codesend address unit state [pin] [repeats] [periodusec] 

		* @param address	Address of this transmitter [0..2^26-1] Duplicate the address of your hardware, or choose a random number.
		* @param unit		[0..2] Number of transmitter button
		* @param state		1=On | 2=Off
		* @param pin		Output pin on RaspberryPi to which the transmitter is connected
		* @param repeats	[0..8] The 2log-Number of times the signal is repeated. The actual number of repeats will be 2^repeats. 2 would be bare minimum, 4 seems robust, 8 is maximum (and overkill).
		* @param periodusec	Duration of one period, in microseconds. One bit takes 8 periods (but only 4 for 'dim' signal).
*/

#include "itt-1500lib.h"
#include <stdlib.h>
#include <stdio.h>
     

int main(int argc, char *argv[]) {
    
	// Getting default values
		int address = 0;
		int unit = 0;
		int state = 0;
		int pin = 0;
		int repeats = 3;
		int periodusec = 260;

    // If no command line argument is given, print the help text
    if (argc <= 4) {
        printf("Usage: %s address state [pin] [repeats] [periodusec]\n", argv[0]);
        printf("address\t- Address of the transmitter [0..2^26-1]\n");
        printf("state\t- 1=On | 2=Off\n");
        printf("pin\t- Output pin on RaspberryPi to which the transmitter is connected\n");
		printf("repeats\t- [0..8] The 2log-Number of times the signal is repeated. The actual number of repeats will be 2^repeats. 2 would be bare minimum, 4 seems robust, 8 is maximum (and overkill).\n");
		printf("periodusec\t- Duration of one period, in microseconds. One bit takes 8 periods\n");
        return -1;
    }

    // Change protocol and pulse length accroding to parameters
    int address = atoi(argv[1]);
    int unit = atoi(argv[2]);
    int state = atoi(argv[3]);
    if (argc >= 5) pin = atoi(argv[4]);
    if (argc >= 6) repeats = atoi(argv[5]);
    if (argc >= 7) periodusec = atoi(argv[6]);
	
    if (state == 0) bool switchstate = false;
    if (state == 1) bool switchstate = true;
    
    if (wiringPiSetup () == -1) return 1;
    printf("sending code[%i]\n", code);
	
	NewRemoteTransmitter transmitter(address, pin, peridusec, repeats);
	transmitter.sendUnit(unit, switchstate);
	
	
    return 0;

}
