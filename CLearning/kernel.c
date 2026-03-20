typedef unsigned short uint16_t;

/* to write : a function that loops through __bss_start and  end as
 * start and stopping point, walking through memory and zeroing it out.*/

extern char __bss_start;
extern char __bss_end;


void  bsszero(){
  
     char *S = &__bss_start;
     for (; S < &__bss_end; S++)
        *S = 0;

}

void kernel_main(){
    bsszero();
    uint16_t* vga_buffer = (uint16_t*) 0xB8000;
    vga_buffer[0] = (0x07 << 8) | 'H';   

    vga_buffer[1] = (0x07 << 8) | 'e';
    

}
