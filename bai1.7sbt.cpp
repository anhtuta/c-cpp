#include<stdio.h>
#include<conio.h>
#include<math.h>
#define sai_so 1e-7

int main() {
	float a,m,n; //tinh can bac 2 cua a,sai s? < 1*10^-7
	do{
		printf("nhap a= "); 
		scanf("%f",&a);
		if(a<=0) printf("nhap sai cmn roi. ngu vl!");
	} while(a<=0);

	m=a;
	do {
		n=m;
		m=((m*m+a)/(2*m));
	} while(fabs(n-m)>sai_so);

	printf("can bac 2 cua %f la %f",a,m);
	}

