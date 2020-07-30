void write_string( int colour, const char *string );
static void putpixel(unsigned char* screen, int x,int y, int color);
static void putpixel_32b(unsigned char* screen, int x,int y, int color);
void kernel_main(void){
	
    const char *str= "Hello";

	const char g='k';

    volatile char *vidptr = (volatile char*)0xb8000;
    unsigned int i = 0;
    unsigned int j = 0;

    while(j < 80 * 25 ) {
        vidptr[j+1] = ' ';
        vidptr[j] = 0x07;         
        j = j + 2;
    }

    j = 0;
	//write_string( 0x07, "Hello" );
	putpixel(0xA0000, 1,1, )
    return;
}
void write_string( int colour, const char *string )
{
    volatile char *video = (volatile char*)0xB8000;
    while( *string != 0 )
    {
		*video++ = colour;
        *video++ = ';';
        
    }
	video = (volatile char*)0xB8000;
	*video = 0x07;
	video[1] = 'p';
}
/* only valid for 800x600x16M */
static void putpixel(unsigned char* screen, int x,int y, int color) {
    unsigned where = x*3 + y*2400;
    screen[where] = color & 255;              // BLUE
    screen[where + 1] = (color >> 8) & 255;   // GREEN
    screen[where + 2] = (color >> 16) & 255;  // RED
}
 
/* only valid for 800x600x32bpp */
static void putpixel_32b(unsigned char* screen, int x,int y, int color) {
    unsigned where = x*4 + y*3200;
    screen[where] = color & 255;              // BLUE
    screen[where + 1] = (color >> 8) & 255;   // GREEN
    screen[where + 2] = (color >> 16) & 255;  // RED
}