#include<stdio.h>
#include<iostream>
#include<time.h>
#include <stdlib.h>

using namespace std;

#define MAX 1000000
float a[MAX];
int n;

void swap(float &a, float &b) {
	float temp = a;
	a = b;
	b = temp;
}

void input() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
	}
}

int partition(int L, int R, int pivotIndex) {
	int i;
	float pivot = a[pivotIndex];
	int storeIndex = L;
	swap(a[pivotIndex], a[R]);
	
	//dich chuyen cac phan tu nho hon pivot ve phia ben trai cua day
	for(i=L; i<R; i++) {
		if(a[i] < pivot) {
			//dich chuyen a[i] ve ddaauf dayx
			swap(a[storeIndex], a[i]);
			storeIndex++;
		}
	}
	swap(a[R], a[storeIndex]);	//dat phan tu chot ve dung vi tri (put pivot into its right position)
	return storeIndex;
}

void quick_sort(int L, int R) {
	if(L < R) {
		int pivotIndex = partition(L, R, (L+R)/2);
		quick_sort(L, pivotIndex-1);
		quick_sort(pivotIndex+1, R);
	}
}

void displayResult() {
	int i;
	for(i=0; i<n; i++) {
		printf("%.2f ", a[i]);
	}
}

int main() {
	input();
	quick_sort(0, n-1);
	displayResult();
	return 0;
}
