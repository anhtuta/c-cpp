#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 5000
#define INF 99999999

using namespace std;
int n,m;
int *a;
int w[MAX][MAX] = {};	//ma tran ke
// int d[MAX] = {};
// int p[MAX] = {};
// int e[MAX] = {};
// int T[MAX];
int d2[MAX][MAX];

int *d;
int *p;
int *e;
int *T;

void input() {
	cin >> n >> m;
	int u,v;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		w[u][v] = w[v][u] = 1;
	}

	d = (int*)malloc(sizeof(int)*(n+1));
	p = (int*)malloc(sizeof(int)*(n+1));
	e = (int*)malloc(sizeof(int)*(n+1));
	T = (int*)malloc(sizeof(int)*(n+1));
	
	for (int i = 1; i <= n; ++i) {
		d[i] = p[i] = e[i] = T[i] = 0;
	}
}

bool isEmpty() {
	for(int u = 1; u <= n; u++) {
		if(T[u] > 0) return false;	
	}
	return true;
}

void init(int s, int t) {
	for(int u = 1; u <= n; u++) {
		if(u == s) {
			T[u] = -1;	// T = V\{s}, trong ddos V laf taapj cacs ddinhr cuar ddoof thij: G = {V,E}
			d[s] = 0;
			p[u] = s;
			continue;
		}
		
		d[u] = (w[s][u] > 0 ? w[s][u] : INF);
		p[u] = s;
		T[u] = 1;	//T là mảng đánh dấu. T[u] = 1 nghĩa là chưa tìm DDNN từ s đến u. T[u] = 0 nghĩa là đã có DDNN từ s -> u
	}
}

void dijkstra(int s, int t) {
	init(s, t);

	while(!isEmpty()) {
		// Laays ddinhr u laf ddinhr trong T maf d[u] laf nhor nhaats. CHU Y: u phair laf ddinhr trong T
		int u;
		int min = INF;
		for(int i = 1; i <= n; i++) {
			if(T[i] == -1 || i == s) continue;	// Chir xets ddinhr u thuoocj taapj T
			if(d[i] < min) {
				u = i;
				min = d[i];	
			}
		}
		
		T[u] = -1;		// T = T\{u}: Do ddax timf dc dduwowngf ddi ngawns nhaats twf s towis u neen ta ko xets u nwax!
		if(u == t) break;  //Duyệt tới node đích rồi thì dừng lại luôn

		// Cập nhật lại d[v] và p[v] của các đỉnh v kề với u
		for(int v = 1; v <= n; v++) {
			if(v == s) continue;
			if(w[u][v] > 0) {
				if(d[v] > d[u] + w[u][v]) {
					d[v] = d[u] + w[u][v];	// do d[u] là ddnn từ s -> u đã tìm đc ở trên nên ddnn từ s->v phải đi qua u nếu v kề với u
					p[v] = u;
				}
			}	
		}
	}
}

int ddnn(int s, int t) {
	int ddnn = 0;
	int currNode = t;
	while(currNode != s) {
		//cout << currNode << " <- ";
		ddnn += w[currNode][p[currNode]];
		currNode = p[currNode];
	}
	return ddnn;
}

int netalz() {
	int min = INF;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			//if(w[i][j] == 1) e[i]++;
			dijkstra(i, j);
			d2[i][j] = ddnn(i, j);
			if(e[i] < d2[i][j]) e[i] = d2[i][j];
		}
		if(e[i] < min) min = e[i];
	}

	// for (int i = 1; i <= n; ++i) {
	// 	cout << "e["<<i<<"] = "<<e[i]<<endl;
	// }
	return min;
}

int main(int argc, char const *argv[])
{
	freopen("netalz.txt", "r", stdin);
	input();
	cout << netalz();
	return 0;
}
