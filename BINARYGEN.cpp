#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 10000

using namespace std;

int a[MAX+1];
int n;
int xauInput;
int xauKq = 0;
bool isPrint = false;
bool isExist = false;

void clearData() {
	for(int i=0; i<=n; i++) {
		a[i] = -1;
	}
}

void printSolution() {
	if(isPrint) {
		for(int i=1; i<=n; i++) {
			cout<<a[i];
		}
		isPrint = false;
		isExist = true;
		return;
	}
	xauKq = 0;
	for(int i=1; i<=n; i++) {
		//cout<<a[i];
		xauKq = xauKq*10 + a[i];
	}
	if(xauKq == xauInput) {
		isPrint = true;
	}
}

bool thuocTapUCV(int i, int k) {	//kiem tra so i co thuoc tap UCV Sk hay ko
	if(a[k-1] == 0 && i==0) return false;
	return true;
}

///sinh xau nhi phan do dai n
void permutation(int k) {
	for(int i=0; i<=1; i++) {
		a[k] = i;
		if(k==n) printSolution();
		else permutation(k+1);
	}
}


int main() {
	cin >> n;
	cin >> xauInput;
	clearData();
	permutation(1);
	if(isExist==false) printf("-1");
}

