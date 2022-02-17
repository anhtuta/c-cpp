#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#define MAX 10005

using namespace std;

int n,m;
int visited[MAX]={};
int num[MAX]={};
int low[MAX]={};
int parent[MAX]={};
std::vector<int> ds[MAX];	// danh sách kề lưu data của đồ thị
std::vector<pair<int, int> > res;	//result: lưu các cạnh cầu
void input() {
	cin >> n >> m;
	int u,v;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		ds[u].push_back(v);
		ds[v].push_back(u);
	}
}

int min(int a, int b) {
	return a<b?a:b;
}
int cnt = 0;
void DFS(int u) {
	visited[u] = 1;		//u.color = gray
	num[u] = cnt++;
	low[u] = num[u];

	for(int i = 0; i < ds[u].size(); i++) {
		int v = ds[u][i];
		if(!visited[v]) {
			parent[v] = u;
			DFS(v);		//if(v.color = white)
			low[u] = min(low[u], low[v]);
			if(low[v] > num[u]) {
				cout << "vao day\n";
				res.push_back(make_pair(u,v));
			}
		} else if(v != parent[u]) low[u] = min(low[u], num[v]);
	}
	///cout << "\tDuyet " << u << endl;		//u.color = black
}

void printNumLow() {
	cout << "print num:\n";
	for (int i = 1; i <= n; ++i)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	cout << "print low:\n";
	for (int i = 1; i <= n; ++i)
	{
		cout << low[i] << " ";
	}
	cout << endl;
}

int main() {
	freopen("bridge.txt", "r", stdin);
	input();
	for (int i = 1; i <= n; i++) {
		if(!visited[i]) DFS(i);
	}

	// in tất cả các cạnh cầu
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i].first << " " << res[i].second << endl;
	}

	printNumLow();
}