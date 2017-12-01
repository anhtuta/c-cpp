#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#define MAX 10005
#define UNVISITED 0
#define VISITED 1


// Tính số thành phần liên thông của đồ thị vô hướng
using namespace std;

int n,m;
std::vector<int> ds[MAX];	// Mỗi đỉnh u sẽ có 1 vector lưu các đỉnh kề với nó, vector đó là ds[u]
std::vector<int> vSet[MAX];	//vector lưu các đỉnh của từng thành phần liên thông
int visit[MAX];
int cc_num = 0;	//số lượng thành phần liên thông

void input() {
	cin >> n >> m;
	int u,v;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		ds[u].push_back(v);
		ds[v].push_back(u);
	}

	//đầu tiên khởi tạo chưa đỉnh nào đc thăm
	for (int i = 1; i <= n; ++i) {
		visit[i] = UNVISITED;
	}
}

void DFS_CC(int u) {
	visit[u] = VISITED;
	vSet[cc_num].push_back(u);
	// xem các đỉnh kề với u, đỉnh nào chưa duyệt thì duyệt nó và cho nó vào thành phần liên thông cùng với u
	for (int i = 0; i < ds[u].size(); ++i) {
		int v = ds[u][i];	// duyệt từng đỉnh kề với u
		if(visit[v] == UNVISITED) {
			DFS_CC(v);
		}
	}
}

int compute_cc_usingDFS() {
	for (int i = 1; i <= n; ++i) {
		if(visit[i] == UNVISITED) {
			cc_num++;
			DFS_CC(i);
		}
	}

	return cc_num;
}

void BFS_CC(int u) {
	//tự làm!
}
int compute_cc_usingBFS() {
	//tự làm!
}

// In các đỉnh của từng thành phần liên thông
void printConnectedComponents() {
	cout << "Cac dinh cua tung thanh phan lien thong\n";
	for (int i = 1; i <= cc_num; ++i) {
		for (int j = 0; j < vSet[i].size(); ++j) {
			cout << vSet[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	freopen("compute_cc.txt", "r", stdin);
	input();
	cout << compute_cc_usingDFS() << endl;
	printConnectedComponents();
}

