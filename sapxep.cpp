//thuat toan sap xep noi bot

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main() {
	int n,i,temp2,a[100];
	
	printf("nhap so cac so: ");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		printf("a[%d] = ",i);
		scanf("%d",&temp2);
		a[i] = temp2;
	}
	
	int k=0,max=0,imax=0;
	for(k=n-1; k>0; k--)  {
		max = -1;
		
		//tim max trong cac so tu a[i] den a[k]
		for(i=0;i<=k;i++)  {
			if (max < a[i])  {
				max = a[i];
				imax = i;
			}
			
		}
		//swap(&a[k],&a[imax]) : doi cho giua gia tri max va phan tu cuoi cung cua day
	  	a[imax] = a[k];
		a[k] = max;
	}
	
	printf("\nDay sau khi sap xep la:\n");
	for(int j=0;j<n;j++)  printf("%5d",a[j]);
	getch();
}


