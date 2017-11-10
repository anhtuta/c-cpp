#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 100000

using namespace std;

int n, L1, L2;
long long a[MAX];
long long s[MAX];

int max(long long a, long long b) {
	return a>b?a:b;
}

int main() {
	freopen("MAXSUBSEQ.txt", "r", stdin);
	cin >> n >> L1 >> L2;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	if(n == 1) {
		cout << a[1];
		return 0;
	}
	
	s[0] = -1;
	s[1] = a[1];
	long long maxSub = s[1];
	
	for(int i = 2; i <= n; i++) {
		
	}
	
	cout << maxSub;
}
