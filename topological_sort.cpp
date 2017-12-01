#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#define MAX 10005
#define UNVISITED 0
#define VISITED 1
#define pb push_back

using namespace std;

int n,m;
int bbv[MAX];	//bán bậc vào của từng đỉnh. bbv là số đường đi vào đỉnh đó
vector<int> ds[MAX];	//danh sach ke
queue<int> q;
int NR[MAX];	//NR[u] = chỉ số của đỉnh u sau khi đánh số lại đồ thị

void input() {
	cin >> n >> m;
	int u,v;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v;
		ds[u].pb(v);
	}

	//init
	for (int i = 1; i <= n; ++i) {
		bbv[i] = 0;
		NR[i] = 0;
	}

	//tính bbv dựa theo input
	for (int u = 1; u <= n; ++u) {
		for (int i = 0; i < ds[u].size(); ++i) {
			int v = ds[u][i];
			bbv[v]++;
		}
	}
}

void output(){
	cout << "Chi so moi cac dinh:\n";
	for (int i = 1; i <= n; ++i) {
		cout << NR[i] << " ";
	}
}

void numbering() {
	//cho tất cả các đỉnh có bbv = 0 vào queue
	for (int v = 1; v <= n; ++v)
	{
		if(bbv[v] == 0) q.push(v);
	}

	int num = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		num++;
		NR[u] = num;

		for(int i = 0; i < ds[u].size(); ++i) {
			int v = ds[u][i];
			bbv[v]--;
			if(bbv[v] == 0) q.push(v);
		}
	}
}

int main() {
	freopen("topo_sort.txt", "r", stdin);
	input();
	numbering();
	output();
}


