#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#define MAX 4001

using namespace std;

int n,m;
int a[MAX][MAX]={};

void input() {
	cin >> n >> m;
	int u,v;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		a[u][v] = 1;
		a[v][u] = 1;
	}
}

int entity() {
	int numberOf3Entity = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(a[i][j] == 1) {
				for (int k = 1; k <= n; ++k) {
					if(a[j][k] == 1 && a[k][i] == 1) {
						numberOf3Entity++;
						cout << i<<", "<<j<<", "<<k<<endl;
					}
				}
			}
		}
	}

	return numberOf3Entity/6;
}

int main(int argc, char const *argv[])
{
	freopen("entity.txt", "r", stdin);
	input();
	cout << entity();
	return 0;
}