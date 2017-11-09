#include<stdio.h>
#include<stdlib.h>
#include <iostream>

#define MAX 100
using namespace std;

int L[MAX][MAX];

void clearData() {
	for(int i=0; i<MAX; i++) {
		for(int j=0; j<MAX; j++) {
			L[i][j] = -1;
		}
	}
}

//ham tinh to hop chap k cua n phan tu: C(n,k)
long comb(int k, int n) {
	if(k==n || k==0) L[k][n] = 1;
	else {
		if(L[k][n] < 0) L[k][n] = comb(k-1, n-1) + comb(k, n-1);	//Neu L[k][n] chua duoc tinh lan nao thi bay gio ta phai tinh no, neu L[k][n] duoc tinh roi thi chi viec return L[k][n];
	}
	return L[k][n];
}

int main() {
	clearData();
	cout << comb(3,7) << endl;
	cout << comb(13,17) << endl;
	
}
