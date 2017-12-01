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
	freopen("gold.txt", "r", stdin);
	cin >> n >> L1 >> L2;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = 0;
	}
	
	if(n == 1) {
		cout << a[1];
		return 0;
	}
	
	s[0] = -1;
	s[1] = a[1];
	long long maxGold = s[1];
	
	for(int i = 2; i <= n; i++) {
		long long maxSu = 0;
		if(i-L1 > 0) {
			for(int j = max(1, i-L2); j <= i-L1; j++) {
				if(maxSu < s[j]) maxSu = s[j];
			}
		}
		
		s[i] = a[i] + maxSu;
		//cout << "s["<<i<<"] = "<<s[i]<<endl;
		if(maxGold < s[i]) maxGold = s[i];
	}
	
	cout << maxGold;
}
