#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 100000

using namespace std;

int n, L1, L2;
long long a[MAX];
long long s[MAX];
long long res = 0;		//result

int max(long long a, long long b) {
	return a>b?a:b;
}

void input() {
	cin >> n >> L1 >> L2;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i];
		res = max(res, a[i]);
	}
}

long long process() {
	for(int t = L1 + 1; t <= n; t++) {
		for(int j = t - L1; j >= t - L2 && j > 0; j--) {
			s[t] = max(s[t], a[t] + s[j]);
		}
		res = max(res, s[t]);
	}
	return res;
}

int main() {
	freopen("gold.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	input();
	cout << process();
}
