#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#define MAX 10005
#define UNVISITED 0
#define VISITED 1

using namespace std;

int n,m;
vector<int> ds[MAX];	//lưu danh sách kề
vector<int> dsT[MAX];	//lưu danh sách kề theo thứ tự ngược lại (Gt) (xem slide)
int visit[MAX];
int cc_num = 0;	//số lượng thành phần liên thông của G
int cc_numT = 0;	//số lượng thành phần liên thông của Gt

void input() {
	cin >> n >> m;
	int u,v;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		ds[u].push_back(v);
		dsT[v].push_back(u);
	}
}

void init() {
	//đầu tiên khởi tạo chưa đỉnh nào đc thăm
	for (int i = 1; i <= n; ++i) {
		visit[i] = UNVISITED;
	}
}

void DFS_CC(int u) {
	visit[u] = VISITED;
	//vSet[cc_num].push_back(u);
	// xem các đỉnh kề với u, đỉnh nào chưa duyệt thì duyệt nó và cho nó vào thành phần liên thông cùng với u
	for (int i = 0; i < ds[u].size(); ++i) {
		int v = ds[u][i];	// duyệt từng đỉnh kề với u
		if(visit[v] == UNVISITED) {
			DFS_CC(v);
		}
	}
}

int compute_cc_usingDFS() {
	init();
	for (int i = 1; i <= n; ++i) {
		if(visit[i] == UNVISITED) {
			cc_num++;
			DFS_CC(i);
		}
	}

	return cc_num;
}

void DFS_CC_T(int u) {
	visit[u] = VISITED;
	//vSet[cc_num].push_back(u);
	// xem các đỉnh kề với u, đỉnh nào chưa duyệt thì duyệt nó và cho nó vào thành phần liên thông cùng với u
	for (int i = 0; i < dsT[u].size(); ++i) {
		int v = dsT[u][i];	// duyệt từng đỉnh kề với u
		if(visit[v] == UNVISITED) {
			DFS_CC(v);
		}
	}
}

int compute_cc_usingDFS_T() {
	init();
	for (int i = 1; i <= n; ++i) {
		if(visit[i] == UNVISITED) {
			cc_numT++;
			DFS_CC(i);
		}
	}

	return cc_num;
}
int main() {
	freopen("strong_cc.txt", "r", stdin);
	input();
	compute_cc_usingDFS();
	compute_cc_usingDFS_T();
	if(cc_num == 1 && cc_numT == 1) {
		cout << "Day la do thi lien thong manh!\n";
	} else cout << "Do thi nay deo lien thong manh!\n";
}