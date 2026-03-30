typedef unsigned short uint16_t;

/* to write : a function that loops through __bss_start and  end as
 * start and stopping point, walking through memory and zeroing it out.*/

extern char __bss_start;
extern char __bss_end;

uint16_t* vga_buffer= (uint16_t*) 0xB8000;

void  bsszero(){
  
     char *S = &__bss_start;
     for (; S < &__bss_end; S++)
        *S = 0;

}

void write(char *str){
    int row= 0;
    int col= 0;
    int index;
  /* while loop as long as it doesn't hit a nullbyte or vga limit */  
    while (*str != '\0' && row < 25){
        index = row * 80 + col;
        vga_buffer[index] = (0x07 << 8) | *str;
            str ++;      
            col++;
 /*making a newline for every 80 char hit */    
         if (col == 80){
            ++row;
            col = 0;
         }
        if (row == 25){
      
            for(int i = 0 ; i < 2000 ; i++){
                vga_buffer[i] = (0x07 << 8) | ' ' ;
            }
       
         col = 0;
         row = 0;
    }
}
}   

void kernel_main(){
    bsszero();   
    write("Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!");    
   
}

