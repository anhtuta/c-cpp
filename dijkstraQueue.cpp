// BÀI NÀY ÁP DỤNG CHO ĐỒ THỊ CÓ HƯỚNG, SỬ DỤNG HÀNG ĐỢI ƯU TIÊN

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#define MAX 100
#define INF 99999999
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;
int n,m;
int d[MAX];		//d[v] = khoang cach ngan nhat tu dinh s toi dinh v
int p[MAX];		//p[v] = cha cua v tren ddnn
int mark[MAX];
int s,t;
vector<ii> ds[MAX];
priority_queue< ii, vector<ii >, greater<ii > > pq;

void input() {
	cin >> n >> m;
	int u,v,w;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		ds[u].pb(mp(v,w));
	}
	for (int i = 1; i <= n; ++i) {
		d[i] = INF;
		mark[i] = 0;
	}
}

void init(int s) {
	for (int i = 1; i <= n; ++i) {
		p[i] = s;
	}
	for (int i = 0; i < ds[s].size(); ++i)	{
		int v = ds[s][i].first;
		int w = ds[s][i].second;
		d[v] = w;
	}
	d[s] = 0;
	p[s] = 0;
	mark[s] = 1;

}
int dijkstra(int s, int t) {
	init(s);
	pq.push(mp(d[s], s));
	while(!pq.empty()) {
		int u = pq.top().second;
		d[u] = pq.top().first;
		pq.pop();

		if(!mark[u]) {
			mark[u] = 1;
			for (int i = 0; i < ds[u].size(); ++i)	{
				int v = ds[u][i].first;
				int w = ds[u][i].second;
				if(!mark[v]) {
					//Relax(u,v)
					if(d[v] > d[u] + w) {
						d[v] = d[u] + w;
						p[v] = u;
						pq.push(mp(d[v], v));

					}
				}
			}
		}
	}
}

int main() {
	freopen("dijkstra2.txt", "r", stdin);
	input();
	cout << dijkstra(1, 6);
}
