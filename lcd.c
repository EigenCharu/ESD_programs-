#include "lpc213x.h"
#include <stdint.h>


#define RS (1<<0)
#define RW (1<<1)
#define EN (1<<2)


void delay(uint16_t j){
  
  uint16_t i, x;
  for(i=0; i<j; i++){
    for(x=0; x<600; x++);
  }
}

void lcd_en(){
  
  IOSET0=EN;
  delay(1);
  IOCLR0=EN;
  delay(1);
}

void lcd_cmd(unsigned char cmd){
  
  IO0CLR=RW|RS;
  IO0CLR=(0xff<<4);
  IOSET0=(cmd<<4);
  lcd_en();
  delay(2); 
}

void lcd_data(unsigned char data){
  
  IO0CLR=RW;
  IO0SET=RS;
  IO0CLR=(0xff<<4);
  IO0SET=(data<<4);
  lcd_en();
  delay(2);
  
}

void lcd_str(char *str){
  while(*str){
    lcd_data(*str++);
  }
} 

void lcd_cur_pos(int row, int col){
  
  if(row==0)
    lcd_cmd(0x80 + col);
  else
    lcd_cmd(0xC0 + col);
}

void lcd_init() {
  delay(10);
  
  lcd_cmd(0x38);
  lcd_cmd(0x06);
  lcd_cmd(0x0E);
  lcd_cmd(0x01);
  delay(2);
}

void lpc_init(){
  
  PINSEL0=0x00000000;
  IO0DIR|=RS|RW|EN|(0xff<<4);
}

int main(){
  
  lpc_init();
  lcd_init();
  
  lcd_cur_pos(0, 0);
  lcd_str("Hello World");
  
  lcd_cur_pos(1, 0);
  lcd_str("LPC2148");
  
  while(1);
}



