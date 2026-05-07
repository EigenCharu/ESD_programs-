//Blinking LEDs

#include <lpc213x.h>
#include <stdint.h>


void lpc_init(){
  
  PINSEL1=0x00000000;
  IODIR0|=(1<<16)|(1<<17)|(1<<18);
  
}

void delay(uint16_t j){
  
  uint16_t i,x;
  for(i=0;i<j;i++)
    for(x=0;x<3000;x++);
      
}

void blink_led(){
  
  IOSET0|=(1<<16)|(1<<17)|(1<<18);
  delay(20);
  IOCLR0|=(1<<16)|(1<<17)|(1<<18);
  delay(20);
  
}
  
int main() {
  
  lpc_init();
  while(1) {
    blink_led();
  }
  
 
}

