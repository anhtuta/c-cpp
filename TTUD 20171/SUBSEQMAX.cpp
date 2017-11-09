#include<stdio.h>
#include<iostream>

using namespace std;

int n;
int a[1000000];
	
int maxSub_DP() {
	int smax = a[0];
	int mEH = a[0];
	int imax = 0;
	int i;
	
	for (i = 1; i < n; i++) {
		if(mEH + a[i] > a[i]) mEH = mEH + a[i];
		else mEH = a[i];
		
		if(mEH > smax) {
			smax = mEH;
			imax = i;
		}
	}
	
	return smax;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int kq = maxSub_DP();
	cout << kq;
}