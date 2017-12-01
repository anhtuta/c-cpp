#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<bits/stdc++.h>
#define MAX 1000
#define pb push_back
#define mk make_pair

using namespace std;

int n, m;
int *d;
int *near;
vector<pair<int, int> > ds[MAX];
pair<int, int> T[MAX];		//T laf taapj chwas canhj cuar MST
int *S;		//S laf taapj chwas ddinhr cuar MST. neeus S[k] = 0 nghiax laf k ko thuoc MST

void input() {
	cin >> n >> m;
	d = (int*) malloc(sizeof(int)*(n+1));
	near = (int*) malloc(sizeof(int)*(n+1));
	S = (int*) malloc(sizeof(int)*(n+1));
	
	int u,v,w;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		ds[u].pb(mk(v,w));
		ds[v].pb(mk(u,w));
	}
}

// in ra danh sach cac dinh ke voi dinh vertex va trong so tuong ung
void output() {
	for(int vertex = 1; vertex <= n; vertex++) {
		for(int i = 0; i < ds[vertex].size(); i++) {
		 	cout << "(" << ds[vertex][i].first << ", " << ds[vertex][i].second << ") ";
		}
		cout << endl;
	}
}

void prim() {
	//init
	//xuat phat tu dinh 1
	d[1] = 0;
	near[1] = 1;
	S[1] = 1;	//dax cos ddinhr 1 trong caay MST rooif
	
	for(int i=2; i<=n; i++) {
		S[i] = 0;
		near[i] = 1;
		d[i] = -1;
	}
	
	
	for(int u = 2; u <= n; u++) {
		//duyet lan luot cac dinh ke voi u, lay ra dinh ke v ma co gia nho nhat
		int v = -1;
		for(int i = 0; i < ds[u].size(); i++) {
			if()
		}
	}
}

int main() {
	freopen("prim.txt", "r", stdin);
	input();
	output();
	
}

