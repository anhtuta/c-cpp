#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<bits/stdc++.h>
#define MAX 10000
#define mp make_pair

/*
Cho 2 diem u,v tren ban co m*n. yeu cau: in ra duong di cua con ma tu diem u -> v
VD: m,n = 5,8
u = (4,3), v = (2,6). Di tu u -> v
>_< -_-
CHU Y: Duyet theo phuong phap BFS thi duong di tim dc se la duong di ngan nhat tu u -> v, nhung chua chac la phuong phap lam toi uu nhat!
*/

using namespace std;

int n,m, u, v, s, t;	//(u,v) la toa do node nguon. (s,t) la toa do node dich
queue<pair<int, int> >q;
pair<int, int> p[MAX][MAX];		//luu dinh cha
int dx[] = {-1,1,2,2,1,-1,-2,-2};
int dy[] = {-2,-2,-1,1,2,2,1,-1};
vector<pair<int, int> > path;

int check(int x, int y) {
	return x>=1 && x<=n && y>=1 && y<=m;
}

void input() {
	cin >> n >> m >> u >> v >> s >> t;
}

void bfs(pair<int, int> start) {
	q.push(start);
	p[start.first][start.second] = mp(0,0);
	while(!q.empty()) {
		pair<int, int> node = q.front(); q.pop();
		int x = node.first;
		int y = node.second;
		if(x == s && y == t) {
			do {
				cout <<x<<" "<<y<<endl;
				path.push_back(mp(x,y));
				x = p[x][y].first;
				y = p[x][y].second;
				
			} while(!(x==0 && y==0));
			break;	//truy nguoc lai duong di
		}
		for(int i = 0; i < 8; i++) {
			if(check(x + dx[i], y + dy[i])) {
				q.push(mp(x+dx[i], y+dy[i]));
				p[x+dx[i]][y+dy[i]] = mp(x,y);
			}
		}
	}
	
	for(int i = path.size()-1; i >=0; i--) {
		cout << path[i].first << " " << path[i].second << endl;
	}
}


int main() {
	freopen("conma.txt", "r", stdin);
	input();
	bfs(mp(u,v));
}
