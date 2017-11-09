#include<stdio.h>
#include<conio.h>
#include<math.h>

int ktraSNT(int n) //neu n là so nguyên tô thì hàm này tra vê kq = 1
{
	int a;
	int k=1;
	
	a=sqrt(n);
	for(int i=2;i<=a;i++) {
		if((n%i)==0) {
			k--;
			break;
		}
	}
	return k;
}
int main()
{
	int n,i;
	printf("nhap so n= ");
	scanf("%d",&n);
	printf("các sô nguyên tô < %d là:\n",n);
	for(i=2;i<n;i++)  {
		if(ktraSNT(i)==1) {
			printf("%d \n",i);
		}
	}
}
