#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAX 10001

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

void subseq() {
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum = 0;
		for(int j = i; j > 0; j--) {
			sum += a[j];
			if(sum <= m) soDapAn++;
			else break;
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("subseq.txt", "r", stdin);
	input();
	subseq();
	cout << soDapAn;
	return 0;
}
