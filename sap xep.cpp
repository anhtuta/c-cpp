#include<stdio.h>

void nhapds(int *d, int N)  {
	for (int i=0;i<N;i++)  {
	   printf("phan tu thu %d = ",i+1);
	   int temp; 
	   scanf("%d",&temp); 
	   d[i] = temp; 
	}
}

void inds(int *d, int n)  {
	for (int i=0;i<n;i++)
	   printf("%5d", d[i]);
	 printf("\n");
}

 int main() { 
    int a[100];
    int N; 
    printf("nhap N= "); scanf("%d",&N) ;
    nhapds(a,N);
    printf("day so ban vua nhap la:\n");
    inds(a,N);
 
   }
