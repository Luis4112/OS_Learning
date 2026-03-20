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

    int i = 0;
    while (*str != '\0'){
        vga_buffer[i] = (0x07 << 8) | *str;
            str ++;      
            i++;
           
    }
}
    

void kernel_main(){
    bsszero();   
    write("Hello World!");    
   
}

