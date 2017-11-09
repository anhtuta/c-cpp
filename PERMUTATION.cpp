//combination
/*
Liet ke hoan vi cua 1 tap n phan tu
VD: 
Input: n=3
Output:
(1,2,3), (1,3,2), ..., {3,2,1)
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
		if(a[j] == i) return false;
	}
	return true;
}

void printSolution() {
	for(int i=1; i<=n; i++) {
		cout<<a[i] << " ";
	}
	cout << endl;
}

void permutation(int k) {
	for(int i=1; i<=n; i++) {
		if(thuocTapUCV(i, k)) {
			a[k] = i;
			if(k==n) {
				printSolution();
			} else {
				permutation(k+1);
			}
		}
	}
}


int main() {
	cin >> n;
	permutation(1);
}
