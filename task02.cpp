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
byte flipbits7(byte in){
	unsigned char result = 0;
	for(int i = 0; i < 7; i++){
		bool mybit = in & (0b1 << i);
		result |=  mybit<<(6-i);
	}
	return result;
}

int main()
{
	FILE *fp;
	char buff[8];
	
	fp = fopen("task02.dat","rb");
	fread(buff, sizeof(buff), 1, fp);
	
	int m = buff[1] & 0b1111;
	int d = buff[1]>>4 | ((buff[0] &0b1)<<4);
	int y = flipbits7(buff[0] >> 1) + 1900;
	
	printf("%d.%d.%d",d,m,y);
	
	
	
}
