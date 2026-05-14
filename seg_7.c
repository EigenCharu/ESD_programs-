#include "lpc213x.h"
#include <stdint.h>

void delay(uint16_t j){
  
  uint16_t i, x;
  for(i=0; i<j; i++){
    for(x=0; x<6000; x++);
  }
}

void lpc_init(){
  
  PINSEL0=0x00000000;
  IODIR0= 0xffffffff;
  
}

void seven_seg(){
  
  int i;
  unsigned int a[]={0x3f,0x6,0x5b,0x4f,0x66,0x6d,0x7d,0x7,0x7f,0x6f};
  for(i=0; i<10; i++){
    IO0SET=(a[i]<<8);
    delay(10);
    IO0CLR=(a[i]<<8);
  }
}
int main(){
  
  lpc_init();
  while(1){
    seven_seg();
  }
}

