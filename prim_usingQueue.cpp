#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<bits/stdc++.h>
#define MAX 10005
#define pb push_back
#define mp make_pair
#define INF 0xfffffff

using namespace std;

typedef pair<int, int> ii;
int n,m;
int d[MAX];
int mark[MAX];
int near[MAX];
vector<ii> ds[MAX];		//lưu đồ thị = danh sách kề, first = tên đỉnh kề, second = trọng số
priority_queue< ii, vector<ii >, greater<ii > > pq;

void input() {
	cin >> n >> m;
	int u,v,w;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		ds[u].pb(mp(v,w));
		ds[v].pb(mp(u,w));
	}
	for (int i = 1; i <= n; ++i) {
		d[i] = INF;
		mark[i] = 0;
		near[i] = 0;
	}
}

int prim(int s) {	//s = start point
	int len = 0;		//Tổng độ dài đường đi MST
	d[s] = 0;
	pq.push(mp(d[s], s));
	while(!pq.empty()) {
		int u = pq.top().second;
		d[u] = pq.top().first;
		pq.pop();
		if(!mark[u]) {
			mark[u] = 1;
			len += d[u];
			//cout <<"u = "<<u<<", d[u] = "<<d[u]<<endl;

			//cập nhật những đỉnh kề với u
			for (int i = 0; i < ds[u].size(); i++) {
				int v = ds[u][i].first;
				int w = ds[u][i].second;
				if(!mark[v] && d[v] > w) {
					d[v] = w;
					near[v] = u;
					pq.push(mp(d[v], v));
				}
			}
		}
	}

	return len;
}

//in cách cạnh của cây MST theo thứ tự từ điển ("nút nối cạnh" có chỉ số nhỏ hơn thì in trước)
void printEdges() {
	for(int i = 2; i <= n; i++) {
		cout << near[i] << " " << i << " ";
	}
}

int main() {
	freopen("mst2.txt", "r", stdin);
	input();
	cout << prim(1) << endl;
	//printEdges();
}
