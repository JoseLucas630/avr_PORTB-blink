#include <avr/io.h>   //includes basic avr functions like DDRB and PORTB and etc...
#include <util/delay.h>   //include the delay function measured in miliseconds

#define F_CPU 16000000    //defines the atmega328p frequency as 16mhz (16 million hertz)
#define delaytime 20000   //defines the delay time at 20000 miliseconds bc my arduino is broken lol

void PORTT2 (void);
void PORTT3 (void);

int main (void)
{
    DDRB = (1 << PB2) | (1 << PB3);   /*sets the portb2 and portb3 as inputs using
                                       data direction register (DDRB)*/
    while(1)
    {
       PORTT2();                 //include the PORTT2 function. We can find it below
       PORTT3();                 //include the PORTT3 function. We can fint it below
    }
    return 0;
}

void PORTT2 (void)
{
    PORTB = PORTB | (1 << PB2);      //since ddr is set to B registers, we turn portb2 in a output
    _delay_ms(delaytime);            //applies the 20000ms delay time to the led
    PORTB = (0 << PB2);              //unset portb2 making it equals to 0
    _delay_ms(delaytime);            //wait again
   
}

void PORTT3 (void)                   //same shit as PORTT2 but setting and unsetting portb3 this time
{
    PORTB = PORTB | (1 << PB3); 
    _delay_ms(delaytime);
    PORTB = (0 << PB3);
    _delay_ms(delaytime);
}