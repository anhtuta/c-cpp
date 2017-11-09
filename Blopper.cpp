#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

int testcase;
int N, S;

int main() {
	freopen("blopper.txt", "r", stdin);
	cin >> testcase;
	while(testcase--) {
		cin >> N >> S;
		int sum = N*(N+1)/2;
		if((sum - S) % 2 == 0) {
			int c = (sum - S)/2;
			for(int i = N; i >= 1; i--) {
				if(c >= i) c = c - i;
			}
			if(N > 1) {
				if(c == 0) cout << "1" << endl;
				else cout << "0" << endl;
			}
		} else cout << "0" << endl;
	}
}
