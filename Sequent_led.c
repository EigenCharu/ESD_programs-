
//sequential order LEDs

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

void serial_blink(uint16_t i) {
  uint16_t x=0;
  while(i) {
    
    IOSET0|=(1<<(16+x));
    delay(20);
    IOCLR0|=(1<<(16+x));
    i--;
    x++;
    delay(20);
  }
}

int main() {
  
  lpc_init();
  while(1) {
    
    serial_blink(3);
  }
  
  return 0;
}




