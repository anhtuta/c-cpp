#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define MAX 31
using namespace std;

int testcase;
int n, b;
long long *a;
long long s;
int soDapAn;
long long MODU = 10*10*10*10*10*10*10*10*10 + 7;

void input() {
	cin >> n >> b;
	a = (long long*)malloc(sizeof(long long)*(n+1));
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
}

void backtrack(int k) {
	for (int i = 0; i < 2; ++i) {	//i=0 là phép cộng, i=1 là phép trừ
		if(i == 0) {
			s = s + a[k+1];
		} else {
			s = s - a[k+1];
		}
		if(k == n-1) {
			if(s == b) {
				soDapAn++;
				if(soDapAn > MODU) soDapAn = soDapAn%MODU;
			}
		} else {
			backtrack(k+1);
		}

		// quay lui
		if(i == 0) {
			s = s - a[k+1];
		} else {
			s = s + a[k+1];
		}
	}
}

int main() {
	freopen("expr.txt", "r", stdin);
	input();
	s = a[1];
	soDapAn = 0;
	backtrack(1);	//backtrack từ 1 -> (n-1), mỗi lần backtrack(i) sẽ đặt dấu vào sau a[i]
	cout << soDapAn;
}
