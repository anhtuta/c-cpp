#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>

int main()
{
	int n,i,dem;
	dem=0;
	printf("nhap so n= "); scanf("%d",&n);
	int a[100];
	int b[100];
	a[0]=n%10; b[0]=n;
	
	printf("a0,b0= %d %d\n",a[0],b[0]);
	for(i=1;i<n;i++) {
		b[i] = (b[i-1])/10; printf("%d\n",b[i]);
		a[i] = (b[i])%10;
		if(b[i]<10) {
			a[i] = b[i];
			dem=i;
			break;
		}
	}
	
	for(i=dem;i>=0;i--)  printf("%d",&a[i]);
}
