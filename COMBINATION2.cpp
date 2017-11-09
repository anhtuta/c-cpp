//combination
/*
Tim toor howpj cuar 1 dayx {1,...,n} theo thws twj twf ddieenr
VD: 
Input: n=5, SIZE=3, viTriInKq = 2
Output:
(1,2,4)
*/
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 10000

int a[MAX+1];
int n, SIZE, viTriInKq, viTriIndex=0;
int voNghiem = -1;
bool coNghiem = false;

using namespace std;

void clearData() {
	for(int i=1; i<=SIZE; i++) {
		a[i] = 0;
	}
}

bool thuocTapUCV(int i, int k) {	//kiem tra so i co thuoc tap UCV Sk hay ko
	for(int j=1; j<k; j++) {
		if(a[j] >= i) return false;
	}	
}

void printSolution() {
	coNghiem = true;
	for(int i=1; i<=SIZE; i++) {
		printf("%d ", a[i]);
	}
}

void combination(int k) {
	for(int i=1; i<=n; i++) {
		if(thuocTapUCV(i, k)) {
			a[k] = i;
			if(k==SIZE) {
				viTriIndex++;
				if(viTriIndex == viTriInKq) {
					printSolution();
				}
			} else {
				combination(k+1);
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> SIZE;
	cin >> viTriInKq;
	combination(1);
	if(coNghiem == false) printf("-1");
}
