       //// 8 channel LED Flasher /////
//// www.elektronicsgarage1.blogspot.com ////
///*** Fayyaz Hussain ***///
///*** Date: 22 June, 2021 ***///

//*** Initializing variables ***//
#include <built_in.h>
sbit sqb at RB0_bit; // external button
int itr=0; // itteration
int x = 0; // for sequence count
int val=0x01; // pre-set value for top to bottom
int val1=0x80; // pre-set value for bottom to top

//*** main function body ***//
void main ()
{
TRISD=0x00;  // Port C as output
PORTD=0x00;  // Port C initial condition 0
TRISB=0xFF;
PORTB=0x00;

//*** Main while Loop for ever run ***//
while(1)
{ 
Delay_ms(30);
if (sqb == 1)
{x++; itr=0;PORTD=0x00;val=0x01;val1=0x80;}
Delay_ms(50);
if (x >= 5) {x=0;} // Sequenc loop end

//*** Top to battom ***//
if (x == 0)
{
Delay_ms(100);
PORTD = PORTD+val;
Delay_ms(100);
val = val<<1;
itr++;
}

//*** Bottom to Top ***//
if (x == 1)
{
Delay_ms(100);
PORTD = PORTD+val1;
Delay_ms(100);
val1 = val1>>1;
itr++;
}
if (itr>=8){itr=0;PORTD=0x00;val=0x01;val1=0x80;} // Reset the shift value

if (x == 2){PORTD=0xFF;Delay_ms(100);PORTD=0x00;} // Full Blink
if (x == 3){PORTD=0x55;Delay_ms(100);PORTD=0xAA;} // Even Odd blink
if (x == 4){PORTD=0x00;Delay_ms(100);} // All Off
}
}