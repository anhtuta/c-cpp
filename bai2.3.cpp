#include<stdio.h>
#include<conio.h>

//in ra bang ma ASCII
int main()
{
	int i;
	printf("Decimal  Hex  Octan  ASCII\n");
	for(i=0;i<256;i++) {
		printf("%-9d%-5x%-7o%-5c",i,i,i,i);
		printf("\n");
	}
}

