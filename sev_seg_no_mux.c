#include "lpc213x.h"
#include <stdint.h>

unsigned char a[]={0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x7, 0x7f, 0x6f};
void delay(uint16_t j){
  
  uint16_t i, x;
  for(i=0; i<j; i++){
    for(x=0; x<6000; x++);
  }
}

void lpc_init(){
  
  PINSEL0=0x00000000;
  PINSEL2=0x00000000;
  IODIR0= 0xffff;
  IODIR1= 0xffff0000;
 
  
}


void seven_seg_counting(){
  
 volatile unsigned int i,j,k,l;

  for(i=0; i<10;i++){
    IOSET0=a[i];
    for(j=0;j<10;j++){
      IOSET0=(a[j]<<8);
      for(k=0;k<10;k++){
        IOSET1=(a[k]<<16);
        for(l=0;l<10;l++){
          IOSET1=(a[l]<<24);
          delay(100);
          IOCLR1=(a[l]<<24);
        }
        IOCLR1=(a[k]<<16);
        
      }
      IOCLR0=(a[j]<<8);
      
      
    }
    IOCLR0=a[i];
  }
}

int main() {
  
  lpc_init();
  while(1){
    seven_seg_counting();}
}

  
  
  
