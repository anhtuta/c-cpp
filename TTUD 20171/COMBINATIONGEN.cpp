#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 10000

using namespace std;

int n,m;
int a[MAX];

void output() {
	for(int i = 1; i <= m; i++) {
		cout << a[i] << " ";
	}
}
int main() {
	//freopen("combination_gen.txt", "r", stdin);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	
	for(int i = m; i >= 1; i--) {
		int k = n - m + i;
		if(a[i] != k) {
			//int temp = a[i];	//thay ai = ai + 1;
			a[i] = a[i] + 1;
			//thay aj = ai + j - i, voi j=i+1, i+2,..., m
			if(i < m) {		//neu i la phan tu cuoi cung thi ko phai lam ntnay nua:
				for(int k = i+1; k<=m; k++) {
					a[k] = a[i] + k - i;
				}	
			}
			break;
		}
	}
	
	output();
}

