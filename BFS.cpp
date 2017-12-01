#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<bits/stdc++.h>
#define MAX 10000

using namespace std;

int n,m;
queue<int> q;
vector<int> ds[MAX];
int d[MAX];
int p[MAX];
int visited[MAX] = {};

void input() {
	cin >> n >> m;
	int u,v;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v;
		ds[u].push_back(v);
		ds[v].push_back(u);
	}
	
	//init
	for(int i = 0; i < n; i++) {
		d[i] = 0;
		p[i] = 0;
	}
}

void output() {
	cout <<"\nMang d:\n";
	for(int i = 0; i < n; i++) {
		cout << d[i] << " ";	
	}
	
	cout <<"\nMang p:\n";
	for(int i = 0; i < n; i++) {
		cout << p[i] << " ";	
	}
}

void BFS(int s) {
	q.push(s);
	visited[s] = 1;
	while(!q.empty()) {
		int u = q.front();	//lay gia tri cua phan tu dau cua hang doi
		q.pop();	//vut phan tu dau tien cua hang doi di
		cout << "\tDuyet " <<u<<", d["<<u<<"] = "<<d[u]<<endl;		//lay u khoi queue nghia la visited u (da duyet xong u)
		for(int i = 0; i < ds[u].size(); i++) {
			int v = ds[u][i];
			if(!visited[v]) {
				q.push(v);
				visited[v] = 1;
				p[v] = u;
				d[v] = d[u] + 1;
				cout << "Tham " <<v<<endl;		//cho v vao queue nghia la discover v
			}
		}
	}
}

int main() {
	freopen("bfs.txt", "r", stdin);
	input();
	BFS(1);
	output();
}
