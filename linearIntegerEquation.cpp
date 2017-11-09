#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int n;//so phan tu
int x[MAX];
int miniSum[MAX]={};//x[k] la tong cua cac phan tu den vi tri k - 1
int totalSum;//tong
void printSol(){
	for(int i =1;i<=n;i++){
		cout<<x[i];
		
	}
	cout<<endl;
}

void TRY(int k){//k la vi tri phan tu dc xet
	if(k == 1) miniSum[1] = 0;
	int A = n - k;//gioi han de nhung phan tu tiep theo co gia tri it nhat la 1
	int min = (k == n)?totalSum - miniSum[k]:1;
	int max = (k == n)?totalSum - miniSum[k]:totalSum - miniSum[k]-(A); 
	for(int i = min;i<=max;i++){//i la so nguyen dc xet
		x[k] = i;
		//int temp = miniSum[k];
		miniSum[k+1] = miniSum[k] + i; 
		if(k == n) printSol();
		else TRY(k+1);
		miniSum[k+1] = miniSum[k] - i; 
	}
	
}
int main(){
	cin>>totalSum>>n;
	TRY(1);
	return 0;
}
