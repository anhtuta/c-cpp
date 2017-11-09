//combination
/*
Tinh to hop chap SIZE cua n phan tu, in ra kq tai vi tri thu m
*/
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 20

int a[MAX+1];
int n, m, SIZE;
int count = 0;
int soLanDuyet = 0;

using namespace std;

bool thuocTapUCV(int i, int k) {	//kiem tra so i co thuoc tap UCV Sk hay ko
	for(int j=1; j<k; j++) {
		if(a[j] >= i) return false;
	}
	return true;
}

void printSolution() {
	for(int i=1; i<=SIZE; i++) {
		cout<<a[i]<<" ";
	}
	cout << endl;
}

void combination(int k) {
	for(int i=1; i<=n; i++) {
		if(thuocTapUCV(i, k)) {
			soLanDuyet++;
			a[k] = i;
			if(k==SIZE) {
				count++;
				if(count == m) {
					printSolution();
				}
			} else {
				combination(k+1);
			}
		}
	}
}


int main() {
	freopen("combine.txt", "r", stdin);
	cin >> n;
	cin >> SIZE;
	cin >> m;
	combination(1);
	cout << "\nsoLanDuyet = " << soLanDuyet;
}
