#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 1005
#define MOD 10000000007

using namespace std;

int n,k1,k2;
int s0[MAX] = {};
int s1[MAX] = {};

int main() {
	cin >> n >> k1 >> k2;
	s0[0] = s0[1] = 1;
	for(int i = k1; i <= n; i++) {
		s0[i] = s1[i-1];
		for(int j = k1; j <= min(i, k2); j++) {
			s1[i] = (s1[i] + s0[i-j]) % MOD;
		}
	}
	cout << (s0[n] + s1[n]) % MOD;
	
}
