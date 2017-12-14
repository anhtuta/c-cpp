#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#define MAX 10000
#define VISITED 1;
#define UNVISITED 0;

using namespace std;

int n,m;
queue<int> q;
vector<int> ds[MAX];
int d[MAX];
int p[MAX];
int visited[MAX] = {};
int head, tail;		// đỉnh đầu và đỉnh cuối của đường đi dài nhất

void init() {
	for(int i = 1; i <= n; i++) {
		d[i] = 0;
		p[i] = 0;
		visited[i] = UNVISITED;
	}
}

void input() {
	cin >> n >> m;
	int u,v;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v;
		ds[u].push_back(v);
		ds[v].push_back(u);
	}
	init();
}

void output() {
	cout <<"\nMang d:\n";
	for(int i = 1; i <= n; i++) {
		cout << d[i] << " ";	
	}
	
	cout <<"\nMang p:\n";
	for(int i = 1; i <= n; i++) {
		cout << p[i] << " ";	
	}
}

int BFS(int s) {
	q.push(s);
	visited[s] = VISITED;
	int u;
	while(!q.empty()) {
		u = q.front();	//lay gia tri cua phan tu dau cua hang doi
		q.pop();	//vut phan tu dau tien cua hang doi di
		cout << "\tDuyet " <<u<<", d["<<u<<"] = "<<d[u]<<endl;		//lay u khoi queue nghia la visited u (da duyet xong u)
		for(int i = 0; i < ds[u].size(); i++) {
			int v = ds[u][i];
			if(!visited[v]) {
				q.push(v);
				visited[v] = VISITED;
				p[v] = u;
				d[v] = d[u] + 1;
				cout << "Tham " <<v<<endl;		//cho v vao queue nghia la discover v
			}
		}
	}
	cout <<"\tu = "<<u<<endl;
	return u;	//u sẽ là đỉnh duyệt cuối cùng
}

void printLongestPath() {
	cout << "\nDuong di dai nhat:\n";
	int currNode = tail;
	while(currNode != head) {
		cout << currNode << " -> ";
		currNode = p[currNode];
	}
	cout << head << endl;
}

int main() {
	freopen("longest_path.txt", "r", stdin);
	input();
	head = BFS(1);
	init();
	tail = BFS(head);
	cout << "head = "<<head<<", tail = "<<tail<<endl;
	output();
	printLongestPath();
}
