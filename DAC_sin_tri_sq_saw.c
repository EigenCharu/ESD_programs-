#include "lpc213x.h"
#include <stdint.h>

void  delay(int j){
  
  int i, x;
  for(i=0; i<j; i++){
    for(x=0; x<600; x++);
  }
  
}


void trig_wave(){
  
  volatile unsigned int i;
  
  for(i=0; i<1024; i++){
    
    DACR=i<<6;
  }
  for(i=1023; i>0; i--){
    
    DACR=i<<6;
}
}

void saw_th_wave(){
  
  volatile unsigned int i;
  
  for(i=0; i<1024; i++){
    
    DACR=i<<6;
  }
}


void sq_wave(){
  
  while(1){
    
    DACR=(1023<<6);
    delay(10);
    DACR=(0<<6);
    delay(10);
}
}

void sin_wave(){
  
  unsigned int sintable[64]={512,562,611,660,707,753,796,836,
873,907,937,963,984,1001,1013,1021,
1023,1021,1013,1001,984,963,937,907,
873,836,796,753,707,660,611,562,
512,461,412,363,316,270,227,187,
150,116,86,60,39,22,10,2,
0,2,10,22,39,60,86,116,
150,187,227,270,316,363,412,461};

volatile unsigned int i;
for(i=0; i<64; i++){
  DACR=(sintable[i]<<6);
  delay(1);
}
}

void lpc_init(){
  
  PINSEL1=0x00080000;
  IO0DIR=0xFFFFFFFF;
}

int main(){
  
  lpc_init();
  while(1){
    //trig_wave();
    //sq_wave();
    //sin_wave();
    saw_th_wave();
  }
}

