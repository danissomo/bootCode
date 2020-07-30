OUTPUT_FORMAT(elf32-i386)
ENTRY(start)

SECTIONS {
    . =1M;

    .boot :
    {
        /* в начале оставим заголовк мультизагрузки */
        *(.multiboot_header)
    }
    .rodata : { *(.rodata) }
    .data : { *(.data) }
    .text : { 
        
        *(.text)
        }
    
    
    .bss : { *(.bss) }
    
}