#include <avr/io.h>
#include <util/delay.h>
#include "DIO.h"
#include "ADC.h"
#include "UART.h"

int main(){
  init();
  int value;//defining variable to hold the value of adc readchannel
  unsigned char buffer[4];//holds 4 values
  while(1)
  {
 
    LED();//call function for the LED
    value = Adc_ReadChannel(3);//making value carry the value of the adc register
   itoa(value,buffer,10);//function to convert number into string
   Uart_SendString(buffer);//calling function from uart file
   Uart_SendString("\n");//function to start from a new line

  }
}

void init(){

    LED();
    Uart_Init();
}


void LED(void){//function to light up the LED
float volt;
  Dio_SetPinDirection('D',3,1);//DDRD pin 3 output
 
  Dio_SetPinDirection('C',3,0);//DDRC pin 3 inputs

  Adc_Init();//intializing adc 

  volt = Adc_ReadChannel(3);//making volt carry the adc register value

 
  if(volt>700){//function to make the LED liht up when button is pressed 
    

    
    Dio_SetPortDirection('D',3,1);//Port D Pin 3 activation when button pressed 
   
   
  
    

  }
    else
    Dio_SetPortDirection('D',3,0);//Port D Pin 3 deactivation when button switched 

    
 
}

  