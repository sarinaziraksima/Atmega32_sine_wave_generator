/*
 * A.c
 *
 * Created: 5/2/2024 1:11:52 PM
 * Author : Apple
 */ 

//itoa(val3,val3_c,10);
//dtostrf(result_f, 3, 3, result_c);

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD-routines.h"


char frequency_c[16];
char duty_cycle_c[16];


int data[]={1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
//float calculate;

int i=1;//252

float frequency = 5000;


float duty_cycle = 0.6;

//int on_frequency = duty_cycle*frequency;

//int counting_frequency = (F_CPU/frequency) - counting_frequency_ov*256;

//int counting_duty_ov = (F_CPU/on_frequency*256);
//int counting_duty = (F_CPU/on_frequency) - counting_duty_ov*256;



//int frequencys[]={10, 100, 2000, 4000, 5000, 5500};//6

//float duty_cycles[]={0.1, 0.2, 0.3, 0.5, 0.8, 0.9} ;//








int ov_off_constant;
int ov_on_constant;
int tcnt_off_constant;
int tcnt_on_constant;
int ov_off;
int ov_on;
int tick_on_off;

int counter_dc=1;
int counter_f=1;


ISR(TIMER1_OVF_vect){
	
	
	
	
			
			TCNT1=-100;
			
			
			if (data[i]==1){PORTC = 0b00000001;}else{PORTC = 0b00000000;}
			
			
			
			
		
	
	
	
		
			
			
	
		i++;

	
	if (i==168){i=1;}
	
	
	
}


int main(void)
{
	DDRA = 0x00;
	DDRD = 0xff;
	DDRC = 0xff;
	//initial vals
	
	
	
	
	tcnt_off_constant = (int)(F_CPU/((1/(1-duty_cycle))*frequency))+44;
	tcnt_on_constant = (int)(F_CPU/((1/duty_cycle)*frequency))+44;
	
	ov_off_constant=0;
	ov_on_constant=0;

	ov_off = 0;
	ov_on = 0;
	tick_on_off = 0;
	
	
	
	DDRC = 0xff;
	
	
	//we start a timer0 for frequency
	
	//TCCR1A = 0;//1 prescaler
	TCCR1B = (1<<CS10);//1 prescaler
	TIMSK = (1<<TOIE1);//timer i
	
	
	PORTC = 1;
	
	
	TCNT1L = -100;
	//ADCSRA = (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2)|(1<<ADIE)|(1<<ADSC)|(1<<ADEN);
	//val = ADC-0.95;
	//frequency=val*1000;
	lcd_init();
	sei();
    
    while (1) 
    {
		
		
		
		
		
		
	
		
		
		
		
    }
}

