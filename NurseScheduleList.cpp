/*
liet ke xau nhi phan co do dai = n thoa man:
- ko coos >= 2 soos 0 ddwngs canhj nhau	(nghiax laf taats car cacs soos 0 ko dc dwngs canhj nhau)
- soos cacs soos 1 ddwngs canhj nhau TMDK: >= k1 vaf <= k2
*/
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 20

using namespace std;

int a[MAX+1];
int n, k1, k2;

void clearData() {
	for(int i=0; i<=n; i++) {
		a[i] = -1;
	}
}

void printSolution() {
	for(int i=1; i<=n; i++) {
		cout<<a[i];
	}
	cout << endl;
}

void TRY2(int k) {
	int start = 0, end = 1;
	if(k > 1) {
		if(a[k-1] == 0) start = 1;
		int count = 0;
		int m = k-1;
		while(a[m--]) count++;
		if(count < k1) start = 1;
		else if(count == k2) end = 0;
	}
	
	for(int i=start; i<=end; i++) {
		a[k] = i;
		if(k==n) {
			if(a[n] == 1) {
				int count=0;
				int m = n;
				while(a[m--]) count++;
				if(count < k1) continue;
			}
			printSolution();
		} else TRY2(k+1);
	}
}
int main() {
	cin >> n;
	cin >> k1;
	cin >> k2;
	clearData();
	TRY2(1);
}

