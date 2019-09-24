/***************************************************
 Simple AVR sketch to blink an LED (or similar)
 connected to PB2 (Arduino pin D2)
 Note that the compiled sketch is significantly
 smaller than the original Arduino blink sketch.
 A detailed explanation about debugging, port and
 pin definitions can be watched here:
 https://www.youtube.com/watch?v=plJf0r7IcWc
***************************************************/ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{       

  /************************************************ 
   A few different ways to set a pin as output and 
   ignore the rest of the pins. Pick your favorite!
  *************************************************/

//  DDRB |= 0x1F;     // XXXXXXXX | 00011111 = XXX11111
//  DDRB |= 0x0F;     // XXXXXXXX | 00011111 = XXXX1111
//  DDRB |= 0x02;     // XXXXXXXX | 00011111 = XXXxxxx1     onboard LED is at 0b00000010
DDRB = 0b00001111;  
// pinMode(5,INPUT_PULLUP);
// pinMode(6,INPUT_PULLUP);

  // Infinite loop
  while(1)
  {
//int buttonState = digitalRead(5); //read the input pin
 if (digitalRead(4))  up();
 else down();


  }
    
  return 0;
}



void up()
{
        PORTB = 0b00010001;
_delay_ms(12);
        PORTB = 0b00010011;
_delay_ms(12);
        PORTB = 0b00010010;
_delay_ms(12);
        PORTB = 0b00010110;
_delay_ms(12);
        PORTB = 0b00010100;
_delay_ms(12);
        PORTB = 0b00011100;
_delay_ms(12);
        PORTB = 0b00011000;
_delay_ms(12);
        PORTB = 0b00010000;
_delay_ms(12);
}

void down()
{
        PORTB = 0b00010000;
_delay_ms(12);
        PORTB = 0b00011000;
_delay_ms(12);
        PORTB = 0b00011100;
_delay_ms(12);
        PORTB = 0b00011100;
_delay_ms(12);
        PORTB = 0b00011110;
_delay_ms(12);
        PORTB = 0b00010010;
_delay_ms(12);
        PORTB = 0b00010011;
_delay_ms(12);
        PORTB = 0b00010001;
_delay_ms(12);
}

 // DDRB |= 0x04;     // XXXXXXXX | 00000100 = XXXXX1XX
  //DDRB |= _BV(PB2);  // Set PB1 as output, ignore the rest
  //DDRB |= (1 << PB2); // Shift the number '1' left 'PB1' times (PB1 = 2)



  /************************************************ 
   A few different ways to set a pin as input and 
   ignore the rest of the pins.
  *************************************************/
  //DDRB &= ~0x04; //00000100 -> 11111011 & XXXXXXXX = XXXXX0XX
  //DDRB &= ~_BV(PB2); 
  //DDRB &= ~(1 << PB2);

  /*********************************************** 
     A few different ways to set a pin high and 
     ignore the rest of the pins. 
    ************************************************/
    //PORTB |= 0x0E;  // XXXXXXXX | 00000100 = XXXXX1XX
    //PORTB |= _BV(PB2);
    //PORTB |= (1 << PB2);

    /*********************************************** 
     A few different ways to set a pin low and 
     ignore the rest of the pins.
    ************************************************/
    //PORTB &= ~0x04;  // 00000100 -> 11111001 & XXXXXXXX = XXXXX0XX
    //PORTB &= ~_BV(PB2);
    //PORTB &= ~(1 << PB2);

/************************************************ 
  Here are two custom functions to set a pin 
  high or low. The "port pointer" is well
  explained in the video linked in the header,
  and the pointer is basically there to make sure
  it's the actual port and not it's value you're
  passing to the function.
*************************************************/

//// Function to set a pin HIGH
//void SetPinHigh(volatile byte *port, byte pin)
//{
//  *port |= (1 << pin); // The number '1' are shifted left 'pin' times
//  //*port |= _BV(pin); // Alternative method
//}

//// Function to set pin LOW
//void SetPinLow(volatile byte *port, byte pin)
//{
//  *port &= ~(1 << pin); // The number '1' are shifted left 'pin' times
//  //*port &= ~_BV(pin); // Alternative method
//}
