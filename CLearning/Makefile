all: myos.iso


boot.o:boot.asm
	nasm -f elf32 boot.asm -o boot.o
kernel.o:kernel.c
	i686-elf-gcc -ffreestanding -c kernel.c -o kernel.o

kernel.bin:boot.o kernel.o
	i686-elf-ld -T link.ld -o kernel.bin boot.o kernel.o
myos.iso:kernel.bin
	cp kernel.bin iso/boot/
	grub-mkrescue -o myos.iso iso/
qemu:myos.iso
	qemu-system-i386 -cdrom myos.iso

clean: 
	rm -f boot.o kernel.o kernel.bin myos.iso
