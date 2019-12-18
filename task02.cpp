/*
Decode the task02.dat file and find out the birth dates of John Doe and Sam Sepiol.

format: N records of 6 bytes:
  byte 1-2: birth date yyyyyyyd ddddmmmm (year of birth LSB - 1900)
  byte 3-6: height (float LSB)

separator 0xFF (after N records)
name1|name2|...|nameN|
*/
#define byte unsigned char
#include <stdio.h>
#include <cstring>
byte flipbits7(byte in){
	unsigned char result = 0;
	for(int i = 0; i < 7; i++){
		bool mybit = in & (0b1 << i);
		result |=  mybit<<(6-i);
	}
	return result;
}
byte flipbits(byte in){
	unsigned char result = 0;
	for(int i = 0; i < 8; i++){
		bool mybit = in & (0b1 << i);
		result |=  mybit<<(7-i);
	}
	return result;
}
float toFloat(unsigned int x){
	
	float result;
	memcpy(&result,&x, sizeof(x));
    return result;
}

unsigned int reversebits(unsigned int myNum){
	unsigned int result = 0;
	for(int i = 0; i < 24; i++){
		bool mybit = myNum & (0b1 << i);
		result |=  mybit<<(23-i);
	}
	return result;
}

//funkce pro debugovani abych vedel jaky je binarni tvar
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char mbyte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            mbyte = (b[i] >> j) & 1;
            printf("%u", mbyte);
        }
    }
    puts("");
}
int main()
{
	FILE *fp;
	byte buff[20];
	
	fp = fopen("task02.dat","rb");
	fread(buff, sizeof(buff), 1, fp);
	
	
	
	int m = buff[1] & 0b1111;
	int d = buff[1]>>4 | ((buff[0] & 0b1)<<4);
	int y = flipbits7(buff[0] >> 1) + 1900;
	unsigned int heightt = 0;
	for (int i = 3; i >=0; i--){
		unsigned int mybyte = buff[i + 8]<<8*i;
		heightt |= mybyte;
		
	}
	float myheight = toFloat(heightt);
	
	printf("%d.%d.%d Height: %f \n",d,m,y,myheight);
}
