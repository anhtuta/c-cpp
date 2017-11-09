//combination
/*
Tinh to hop chap SIZE cua n phan tu, in ra kq tai vi tri thu m
*/
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 20

int *a;
int n, m, p;
int count = 0;
int soLanDuyet = 0;
bool isPrint = false;
using namespace std;

void clearData() {
	for(int i = 0; i <= n; i++) {
		*(a+i) = 0;
	}
}

void printSolution() {
    isPrint = true;
	for(int i=1; i<=p; i++) {
		cout<<a[i]<<" ";
	}
	cout << endl;
}

void combination(int k) {
	if(isPrint) return;
	for(int i = a[k-1]+1; i<= n-p+k; i++) {
		soLanDuyet++;
		a[k] = i;
		if(k == p) {
			count++;
			if(count == m) {
				printSolution();
			}
		} else {
			combination(k+1);
		}
	}
}


int main() {
	//freopen("combine.txt", "r", stdin);
	cin >> n;
	cin >> p;
	cin >> m;
	a = (int *) malloc(sizeof(int)*(n+1));
	clearData();
	combination(1);
	//cout << "\nsoLanDuyet = " << soLanDuyet;
	if(isPrint == false) cout << "-1";
}