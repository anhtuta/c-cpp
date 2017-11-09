#include<stdio.h>
#include<iostream>
#include<time.h>
#include <stdlib.h>
#include<math.h>

using namespace std;

float *a;
int n;
double shrink = 1.3;

void swap(float &x,float &b) {
	float temp = x;
	x = b;
	b = temp;
}

void input() {
	scanf("%d", &n);
	a = (float *) malloc(sizeof(float)*(n+1));
	for(int i = 0; i < n; i++) {
		//scanf("%f", &a[i]);
		scanf("%f", (a+i));
	}
}

void combSort () {
	int gap = n ;
	bool sorted = false ;
	while ((gap > 1) || (sorted == false)) {
		gap = floor ( gap / shrink );
		if (gap < 1) gap = 1;
		int i = 0;
		if (gap == 1) sorted = true;
		
		while (i + gap < n) {
			if (*(a+i) > *(a + i+ gap)) {
				swap (*(a+i), *(a + i+ gap));
				sorted = false ;
			}
			i++;
		}
	}
}

void displayResult() {
	int i;
	for(i=0; i<n; i++) {
		printf("%.2f ", *(a+i));
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	input();
	combSort();
	displayResult();
	
	return 0;
}