#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 20

/*
sinh xau nhi phan do dai n thu k ma ko co m so 0 dung lien nhau
VD: 6 4 2: sinh xau nhi phan do dai = 6, vi tri cua xau: 4 va ko co 2 so 0 lien tiep
*/
using namespace std;

int a[MAX+1];
int n, vitriIn, m, cnt=0;		//vitriIn co vai tro la k trong comment o tren

void clearData() {
	for(int i=0; i<=n; i++) {
		a[i] = -1;
	}
}

void printSolution() {
	for(int i=1; i<=n; i++) {
		cout<<a[i];
	}
	cout << endl;
}

bool thuocTapUCV(int i, int k) {	//kiem tra so i co thuoc tap UCV Sk hay ko
	if(k < m || k == 1) return true;
	for(int j=(k-m+1); j<k; j++) {	//truong hop nay k = 0
		if(a[j]!=0) return true;
	}
	return false;
}

void permutationList(int k) {
	for(int i=0; i<=1; i++) {
		if(thuocTapUCV(i, k)) {
			a[k] = i;
			if(k==n) {
				cnt++;
				//cout << "count = " << count << endl;
				//if(cnt == vitriIn)
					printSolution();
			}
			else permutationList(k+1);
		}
	}
}

int main() {
	cin >> n;
	cin >> vitriIn;
	cin >> m;
	clearData();
	permutationList(1);
}

//
