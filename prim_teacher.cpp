#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<bits/stdc++.h>
#define MAX 1000
#define pb push_back
#define mk make_pair
#define INF 999999

using namespace std;

int c[MAX][MAX] = {};
int n, m;
int mark[MAX] = {};
int d[MAX];
int near[MAX];
int steps[MAX];		//dung de in ra man hinh thu tu tham cac dinh

void input() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			c[i][j] = INF;		//nhwngx ddinhr naof ko noois voiws nhau thif gias giwax chungs = INF
		}
	}
	int u,v,w;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		c[u][v] = w;
		c[v][u] = w;
	}
}

void init(int start) {
	for(int i = 1; i <= n; i++) {
		d[i] = c[i][start];
		mark[i] = 0;
		near[i] = start;
	}
	
	d[start] = 0;
	mark[start] = 1;
	near[start] = start;
	steps[1] = start;
}

int prim(int start) {
	int s = 0;
	init(start);
	for(int i = 2; i <= n; i++) {
		int minVal = INF, u = 0;
		for(int k = 1; k <= n; k++) {
			if(!mark[k]) {
				if(minVal > d[k]) {
					minVal = d[k];
					u = k;
				}
			}
		}
		s += c[u][near[u]];
		mark[u] = 1;
		//cout <<"s = "<<s<<", u = "<<u<<", near[u] = "<<near[u]<<endl;
		steps[i] = u;
		
		
		//update cac dinh con lai
		//update d[v], voi d[v] la khoang cach ngan nhat tu dinh v toi cay hien tai
		for(int v = 1; v <= n; v++) {
			if(!mark[v]) {
				if(d[v] > c[u][v]) {
					d[v] = c[u][v];
					near[v] = u;
				}
			}
		}
	}
	
	return s;
}

void printC() {
	cout << "Ma tran c:\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << c[i][j] <<" ";	
		}
		cout<<endl;
	}
}

void printNear() {
	cout << "Ma tran Near:\n";
	for(int i = 1; i <= n; i++) {
		cout << near[i] <<" ";	
	}
	cout<<endl;
}

void printSteps() {
	cout << "\nThu tu tham:\n";
	for(int i = 1; i <= n-1; i++) {
		cout << steps[i] << " -> ";
	}
	cout<<steps[n] << endl;
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
	//printC();
	cout << prim(1) << endl;
	//printSteps();
	//printNear();
	//printEdges();
}
