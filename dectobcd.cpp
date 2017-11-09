#include<stdio.h>
#include<conio.h>

void dectobcd(unsigned int a)
{
	if(a<=1) printf("%d",a);
	else {
		dectobcd(a/2);
		printf("%d",a%2);
	}
}

int main()
{
	dectobcd(13);
	}
	
