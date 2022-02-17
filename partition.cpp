#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 1000
#define INF 99999999
using namespace std;

int n;
int x[MAX];
int s;	//sum of all partitions
int T;	//testcase
int res;	//result: best result in dividing the big Disk into smaller partitions 

void input() {
	s = 0;
	res = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x[i];
		s += x[i];
	}
}

void output() {
	for (int i = 1; i < n; ++i)
	{
		cout << x[i] << " ";
	}
}

void partition() {
	for (int i = 1; i < n; ++i)
	{
		res += s;
		s -= x[i];
	}
}

int main() {
	freopen("partition.txt", "r", stdin);
	cin >> T;
	while(T--) {
		//cout << "T = " << T << endl;
		input();
		partition();
		cout << "res = " << res << endl;
	}
}
