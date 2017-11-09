/*
Sinh hoan vi thu k cua 1 tap n phan tu
VD: 
Input: n=3, k=2
Output:
1,3,2
*/
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 10000
#define INF 1000000000

int a[MAX+1];
int n;

using namespace std;

void output() {
	for(int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
	freopen("permu.txt", "r", stdin);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for(int j = n-1; j > 0; j--) {
		//tim tu phai qua trai so dau tien thoa man a[j] < a[j+1]
		if(a[j] < a[j+1]) {
			//tim ak la so nho nhat > aj trong cac so o ben phai aj
			int k = n;
			while(a[j] > a[k]) k--;		//
			
			//doi cho aj va ak
			swap(a[j], a[k]);
			
			//lat nguoc doan tu a[j+1] den a[n]
			int r = n, s = j + 1;
			while(r > s) {
				swap(a[r], a[s]);
				r--;
				s++;
			}
			break;
		}
	}
	
	output();
}
