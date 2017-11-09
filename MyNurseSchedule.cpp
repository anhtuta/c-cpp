/*
liet ke xau nhi phan co do dai = n thoa man:
- ko coos >= 2 soos 0 ddwngs canhj nhau
- soos cacs soos 1 ddwngs canhj nhau TMDK: >= k1 vaf <= k2
*/
//bai nay dung backtracking la xong!

#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 10000

using namespace std;

int a[MAX+1];
int n, k1, k2;
int count;

void printSolution() {
	for(int i=1; i<=n; i++) {
		cout<<a[i];
	}
	cout << endl;
}

void nurse(int k) {
	int start = 0, end = 1;
	if(k > 1) {
		if(a[k-1] == 0) {
			count = 0;
			start = 1;
		}
		else {
			if(count < k1) start = 1;
			else start = 0;
			if(count >= k2) {
				end = 0;
				count = 0;	
			}
			cout << "count = " << count << ". start = " << start << ", end = " << end << endl;
		}
	}
	
	for(int i = start; i <= end; i++) {
		a[k] = i;
		if(a[k] == 1) count++;
		else count = 0;
		if(k == n) {
			if(count >= k1) printSolution();
		} else {
			nurse(k+1);
		}
		if(a[k] == 1) count--;
	}
}

int main() {
	freopen("nurse.txt", "r", stdin);
	cin >> n >> k1 >> k2;
	count = 0;
	nurse(1);
}

/*

Input: 8 2 3

output:
01101110
01110110
01110111
11011011
11101110
*/
