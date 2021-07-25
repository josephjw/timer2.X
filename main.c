
/* 
 * File:   main.c
 * Author: joestalin
 *
 * Created on July 14, 2021, 12:36 PM
 */
//
//#include <stdio.h>
//#include <stdlib.h>
//
///*
// * 
// */
//int main(int argc, char** argv) {
//
//    return (EXIT_SUCCESS);
//}

#include<pic.h>
__CONFIG(0X2CE4);
#define _XTAL_FREQ 4000000

int i=0,count=0;

void timer(int a){
    T2CON=0x31;
//    TOUTPS0=1;
    
//    T2CON=0x31;
//TMR2IF
    do{
    if(TMR2IF==1){
        count++;
    }
    TMR2IF=0;
    }while(count!=244*a);
    count=0;
}

void main()
{
PORTC=0X00;
TRISC=0X01;
PORTA=0X00;
TRISA=0X00;
PORTB=0X00;
TRISB=0X00;
ANSEL=0X00;
ANSELH=0X00;
while(1)
{

PORTB=0Xff;
PORTB=0X01;
timer(1);
PORTB=0X02;
timer(1);
PORTB=0X04;
timer(1);
PORTB=0X02;
timer(1);
}
}