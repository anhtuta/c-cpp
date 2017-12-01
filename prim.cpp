#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<bits/stdc++.h>
#define MAX 1000
#define pb push_back
#define mk make_pair
#define INF 999999

using namespace std;

int n, m;
int *d;
int *near;
vector<pair<int, int> > ds[MAX];
pair<int, int> T[MAX];		//T laf taapj chwas canhj cuar MST
int *S;		//S laf taapj chwas ddinhr cuar MST. neeus S[k] = 0 nghiax laf k ko thuoc MST
//Neu dung Java thi S co the la ArrayList

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
		d[i] = getWeight(i, 1);
	}
	
	for(int k = 2; k <= n; k++) {
		//duyet lan luot cac dinh trong tap W = V\S, lay ra dinh u ma d[u] nho nhat
		int min = INF;
		for(int u = 1; u <= n; u++) {
			if(S[u] == 0) {
				if(d[u] < INF) {
					min = d[u];
				}
			}
		}
	}
}

int getWeight(int u, int v) {
	for(int i = 0; i < ds[u].size(); i++) {
		if(ds[u][i].first == v) {
			return ds[u][i].second;
		}
	}
	return INF;
}

int main() {
	freopen("prim.txt", "r", stdin);
	input();
	output();
	
}

