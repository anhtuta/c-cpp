#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 10000
/*
n = chieu dai chuoi
h = khoang cach Hamming
Yeu cau: liet ke tat ca xau nhi phan do dai = n ma chi co h so chu so 1
*/
using namespace std;

int a[21];
int n, h;
int count;	//dem so luong chu so 1 trong xau nhi phan
int soLanDuyet = 0;

void printSolution() {
	for(int i=1; i<=n; i++) {
		cout<<a[i];
	}
	cout << endl;
}

void hamming(int k) {
	int start = 0, end = 1;
	if(count == h) end = 0;
	if(count + (n-k) < h - 1) start = end = 1;
	
	for(int i = start; i <= end; i++) {
		soLanDuyet++;
		a[k] = i;
		if(a[k] == 1) count++;
		if(k == n) {
			if(count == h) printSolution();
		} else	hamming(k+1);
		if(a[k] == 1) count--;
	}
}


int main() {
	cin >> n >> h;
	count = 0;
	hamming(1);
	cout << "soLanDuyet = " << soLanDuyet;
}
