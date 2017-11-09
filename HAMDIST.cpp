#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 10000
/*
T = so test case
n = chieu dai chuoi
h = khoang cach Hamming
Yeu cau: liet ke tat ca xau nhi phan do dai = n ma chi co h so chu so 1
*/
using namespace std;

int a[21];
int T, n, h;
int count;

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

void hamming(int k) {
	int start = 0, end = 1;
	if(count == h) end = 0;
	for(int j = start; j <= end; j++) {
		a[k] = j;
		if(a[k] == 1) count++;
		if(k == n) {
			if(count == h) printSolution();	
		} else hamming(k+1);
		if(a[k] == 1) count--;
	}
}

void hamming_optimize(int k) {
	int start = 0, end = 1;
	if(count == h) {
		start = end = 0;
	}
	if(count + (n-k+1) < h) {
		start = end = 1;
	}
	for(int j = start; j <= end; j++) {
		a[k] = j;
		if(a[k] == 1) count++;
		if(k == n) {
			if(count == h) printSolution();	
		} else {
			if(count + (n - k + 1) >= h) hamming_optimize(k+1);
		}
		if(a[k] == 1) count--;
	}
}

int main() {
	cin >> T;
	while(T!=0) {
		T--;
		cin >> n >> h;
		count = 0;
		hamming_optimize(1);
		cout << endl;
	}
}
