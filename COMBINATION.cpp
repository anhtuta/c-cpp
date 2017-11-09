//combination
/*
Tim toor howpj cuar 1 dayx {1,...,n} theo thws twj twf ddieenr
VD: 
Input: n=5, SIZE=3
Output:
(1,2,3), (1,2,4), (1,2,5),...,(2,4,5), (3,4,5)
*/
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 20

int a[MAX+1];
int n, SIZE;

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
			a[k] = i;
			if(k==SIZE) {
				printSolution();
			} else {
				combination(k+1);
			}
		}
	}
}

void combination_anotherWay(int k) {
	int idx = k > 1 ? a[k-1]+1:1;
	for(int y=idx; y<=n-SIZE+k; y++) {
		a[k] = y;
		if(k==SIZE) printSolution();
		else combination_anotherWay(k+1);
	}
}

int main() {
	cin >> n;
	cin >> SIZE;
	//combination(1);
	combination_anotherWay(1);
}
