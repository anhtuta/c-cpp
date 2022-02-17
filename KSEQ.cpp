#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 1000000
#define INF 99999999

using namespace std;
int n,k;
int *a;

// cách này chỉ đc 50/100đ, chạy quá time

void input() {
	cin >> n >> k;
	a = (int*)malloc(sizeof(int)*(n+1));
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];	
	}
}

int kseq() {
	int maxK = 0;
	for (int i = k; i <= n; ++i) {
		int sum = 0;
		for (int j = i; j > (i - k); j--)
		{
			sum += a[j];
		}
		if(sum > maxK) maxK = sum;
	}

	return maxK;
}

int main(int argc, char const *argv[])
{	
	freopen("kseq.txt", "r", stdin);
	input();
	cout << kseq();
	return 0;
}