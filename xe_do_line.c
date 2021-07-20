#include <16f877a.h>
#include <def_877a.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)

#define DIR_LEFT  RC0
#define  EN_LEFT  RC1
#define DIR_RIGHT RC3
#define  EN_RIGHT RC2

#define ON    pin_a0
#define OFF   pin_a1

#define O1    pin_a0
#define O2   pin_a1

#define SENSOR PORTD

/////////////////////////////////////////////////////////////////////////////
//********************************* Button  ************************////////
void Button_O1()
{
   if(input(ON)==0)            status=1;
}

void Button_O2()
{
   if(input(OFF)==0)            status=0;
}

void Button_on()
{
   if(input(ON)==0)           output_high(pin_d0);
}

void Button_off()
{
   if(input(OFF)==0)             output_low(pin_d0);      
}
//////////////////////////////////////////////////////////////////////////
/////////////////////////////////  ////////////////////////////////////////
void motor_left_forward()
{
    DIR_LEFT=1; 
    EN_LEFT=1;
}

void motor_left_reverse()
{
    DIR_LEFT=0; 
    EN_LEFT=1; 
}

void motor_left_stop()
{
    EN_LEFT=0; 
}

void motor_right_forward()
{
    DIR_RIGHT=1;
    EN_RIGHT=1; 
}

void motor_right_reverse()
{
DIR_RIGHT=0;
EN_RIGHT=1; 
}
void motor_right_stop()
{
EN_RIGHT=0;
}

void forward()
{
motor_left_forward();
motor_right_forward();
}

void reverse()
{
motor_left_reverse();
motor_right_reverse();
}

void stop()
{
motor_left_stop();
motor_right_stop();
}

void turn_left()
{
motor_left_forward();
motor_right_reverse(); 
}

void turn_right()
{
motor_left_reverse(); 
motor_right_forward();
}

void main ()
{
TRISA=0x00;
TRISC=0x00;
TRISD=0x00; 
PORTC=0x00; 
while(1)
{
//!  Button_O1();
//!  Button_O2();
//!  if(status==1)
//!  {
//!  // ON;
//!  }
//!  else{
//!  // OFF;
  Button_on();
  Button_off();
}
switch (SENSOR)
{

case 0b0110: forward(); break;
case 0b0011: turn_left(); break;
case 0b0001: turn_left(); break;
case 0b1100: turn_right(); break;
case 0b1000: turn_right(); break;
}
}

