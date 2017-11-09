#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

bool binary_Search(int a[], int lo, int hi, int x) {	//mang a phai duoc sap xep roi!
	//lo = lowIndex, hi = highIndex
	if(lo > hi) return false;
	int mid = (lo + hi)/2;
	if(a[mid] == x) return true;
	if(x < a[mid]) return binary_Search(a, lo, mid-1, x);
	else return binary_Search(a, mid+1, hi, x);
}

bool binarySearch_KhuDeQuy(int a[], int lo, int hi, int x) {
	while(hi >= lo) {
		int mid = (lo + hi)/2;
		if(a[mid] == x) return true;
		if(x < a[mid]) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	if(lo == hi && a[lo] == x) return true;
	return false;
}

int main() {
	int x [] = {1,3,4,5,7,11,12,14,17,21,33,34,37,45,67,68,88,89,98};
	cout << binary_Search(x, 0, 18, 89);
	cout << binarySearch_KhuDeQuy(x, 0, 18, 89);
}
