/* Name: main.c
 * Author: Insoo Kim
 * License: MIT License
 * Ref: https://jawher.me/using-xcode-avr-c/
 * Created: Dec 27, 2024
 * Upated:
 */

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void initIO(void) {
    // Set Data Direction Register B w/Data Direction Bit
    //DDRB |= _BV(DDB5); // Set LED as an output
    DDRB |= (1 << DDB5); // Save effect as above
}

int main(void) {
	initIO();
    
	while (1) {
        // set i < 5 for blinking like every third sec
        // set i < 20 for blinking like every sec
        for(char i = 0; i < 20; i++){
            _delay_ms(30);  /* max is 262.14 ms / F_CPU in MHz */
        }
        //PORTB ^=(1 << PORTB5);    /* toggle the LED */
        PORTB ^= _BV(PORTB5);       // Save effect as above
	}
	return 0; // never reached
}
