
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 20

int a[MAX+1];
int n, SIZE;
int viTriInKq = 0;
int cnt= 0;
bool isPrint = false;
using namespace std;

bool thuocTapUCV(int i, int k) {	//kiem tra so i co thuoc tap UCV Sk hay ko
	for(int j=1; j<k; j++) {
		if(a[j] == i) return false;
	}
	return true;
}

void printSolution() {
	isPrint = true;
	for(int i=1; i<=n; i++) {
		cout<<a[i] << " ";
	}
	cout << endl;
}

void permutation(int k) {
	if(isPrint) return;
	for(int i=1; i<=n; i++) {
		if(thuocTapUCV(i, k)) {
			a[k] = i;
			if(k==n) {
				cnt++;
				if(cnt == viTriInKq) printSolution();
			} else {
				permutation(k+1);
			}
		}
	}
}


int main() {
	cin >> n;
	cin >> viTriInKq;
	permutation(1);
	if(isPrint == false) cout << "-1";
}