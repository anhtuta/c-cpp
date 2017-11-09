#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 20

using namespace std;

int a[MAX+1];
int n;

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
	if(a[k-1] == 0 && i==0) return false;
	return true;
}

bool thuocTapUCV3(int i, int k) {	//kiem tra so i co thuoc tap UCV Sk hay ko
	if(k<2) return true;
	if(a[k-2] == 0 && a[k-1] == 1 && i==0) return false;
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

///sinh xau nhi phan do dai n ma ko co 2 so 0 dung lien nhau
void permutationWithoutDouble0(int k) {
	for(int i=0; i<=1; i++) {
		if(thuocTapUCV(i, k)) {
			a[k] = i;
			if(k==n) printSolution();
			else permutationWithoutDouble0(k+1);
		}
	}
}

//kiem tra xem mang a, so cac chu so 1 co nhieu hon so cac chu so 0 hay ko
//neu so cac chu so 1 co nhieu hon so cac chu so 0 thi tong cua ca mang a se >= n/2, khi do return false;
bool checkDk3() {
	int s=0;
	for(int i=1; i<=n; i++) {
		s += a[i];
	}
	return s>n/2;
}

///sinh xau nhi phan do dai n TMDK:
// - ko chuwas 3 soos 010
// - soos chwx soos 0 < soos chwx soos 1
void permutation3(int k) {
	for(int i=0; i<=1; i++) {
		if(thuocTapUCV3(i, k)) {
			a[k] = i;
			if(k==n) {
				if(checkDk3() == true) printSolution();
			} else permutation3(k+1);
		}
	}
}

int main() {
	cin >> n;
	clearData();
	//permutation(1);
	permutation3(1);
}

//
