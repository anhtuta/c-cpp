#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

/*
Tìm trọng lượng của dãy con lớn nhất
*/
int n;
int *a;

void input() {
	cin >> n;
	a = (int*)malloc(sizeof(int)*(n+1));
	int temp;
	for (int i = 1; i <= n; ++i)
	{
		cin >> temp;
		a[i] = temp;
	}
}

int maxSub_DP() {
	int max = a[1];
	int mEH = a[1];
	for (int i = 2; i <= n; ++i)
	{
		if(mEH > 0) mEH = mEH + a[i];
		else mEH = a[i];

		if(mEH > max) max = mEH;
	}

	return max;
}

int main() {
	freopen("subseq.txt", "r", stdin);
	input();
	cout << maxSub_DP();
}