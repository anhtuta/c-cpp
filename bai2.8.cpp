#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>

using namespace std;

int ktraSoHoanThien(int n)
{
	int s,i;
	s=0;
	for(i=1;i<n;i++) {
		if((n%i)==0) s+=i;
	}
	if(s==n) return 1; //kq=1 thi n là sô hoàn thiên
	else return 0;
}

int main()
{
	int n,i;
	int s=0;
	
	printf("nhap n= "); scanf("%d",&n);
	printf("các sô hoàn thien nho hon n là: \n");
	for(i=1;i<n;i++) {
		if(ktraSoHoanThien(i)==1)  {
			s++;
		    printf("%d\n",i);
     	}  
   }
   if(s==0) {
   	system("cls");
   	printf("ko có sô hoàn thiên nào ca!");
   }
}
