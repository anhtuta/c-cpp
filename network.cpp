#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<algorithm>
#define MAX 10000

using namespace std;

int n, k, m;
int a[MAX][MAX];

void input() {
	cin >> n >> k >> m;
	int x,y,z;
	for(int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		a[x][y] = z;
		a[y][x] = z;
	}
}

void output() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	freopen("network.txt", "r", stdin);
	input();
	output();
}
