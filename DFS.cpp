#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<bits/stdc++.h>
#define MAX 10000
#define pb push_back
#define mk make_pair


using namespace std;

int n, k, m;
vector<pair<int, int> > ds[MAX];		//lwu cacs ddinhr keef vowis nos vaf trongj soos twowng wngs. VD: ds[3] = <5,2> nghiax laf 3 keef vowis 5 vaf gias cuar (3,5) = 2	
int *d;
int *f;
int visited[MAX] = {};

void input() {
	cin >> n >> k >> m;
	d = (int*) malloc(sizeof(int)*n);
	f = (int*) malloc(sizeof(int)*n);
	
	int u,v,w;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		ds[u].pb(mk(v,w));
		ds[v].pb(mk(u,w));
	}
}

// in ra danh sach cac dinh ke voi dinh vertex va trong so tuong ung
void output(int vertex) {
	for(int i = 0; i < ds[vertex].size(); i++) {
	 	cout << "(" << ds[vertex][i].first << ", " << ds[vertex][i].second << ") ";
	}
	cout << endl;
}

void DFS(int u) {
	visited[u] = 1;
	cout << "Tham " << u << endl;
	
	for(int i = 0; i < ds[u].size(); i++) {
		int v = ds[u][i].first;
		if(!visited[v]) DFS(v);
	}
	cout << "\tDuyet " << u << endl;
}

int main() {
	freopen("network.txt", "r", stdin);
	input();
	DFS(1);
}
