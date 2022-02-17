#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 1000000
#define INF 99999999

using namespace std;
int n,k;
int *a;

void input() {
	cin >> n >> k;
	a = (int*)malloc(sizeof(int)*(n+1));
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];	
	}
}

int kseq() {
	int maxK = 0;
	for (int i = 1; i <= k; ++i)
	{
		maxK += a[i];
	}

	int sum_prev = maxK;
	for (int i = k+1; i <= n; ++i)
	{
		int sum = sum_prev - a[i-k] + a[i];
		sum_prev = sum;
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