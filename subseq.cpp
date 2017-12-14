#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAX 10001

/*
Cho 2 số n,m
nhập n số nguyên a1->an
tìm số dãy con của a[i] sao cho tổng của dãy con <= m
VD: input:
5 5
2 3 4 1 5
output:
7

Có 7 dãy con TMĐK: tổng <= 5
*/
using namespace std;

int n,m;
int a[MAX];
int soDapAn = 0;

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
}

void output() {
	for (int i = 1; i <= n; ++i)
	{
		cout << a[i] << " ";
	}
}

int main() {
	freopen("subseq.txt", "r", stdin);
	input();
	for (int i = 1; i <= n; ++i)
	{
		int seh = a[i];		//seh = sum end here = tổng của dãy con mà kết thúc tại a[i]
		if(seh > m) continue;
		soDapAn++;
		for(int j = i-1; j > 0; j--) {
			// cout << "i = "<<i<<endl;
			seh += a[j];
			if(seh <= m) soDapAn++;
			else break;
		}

	}

	cout << soDapAn;
}