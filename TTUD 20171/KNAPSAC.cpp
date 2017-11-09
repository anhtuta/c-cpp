#include<bits/stdc++.h>
#define MAX 35

using namespace std;

int n,b;
int bk;		//tong trong luong con lai cua cai tui
int x[MAX];		//matrix kq
int a[MAX];		//ma tran khoi luong
int c[MAX];		//ma tran gia tri
vector< pair<int, int> > data;

int f=0;	//gia tri hien tai
int fopt = -1;	//f_optimize: ki luc: la gia tri su dung tot nhat

void input() {
	cin >> n >> b;
	for(int i=0; i<n; i++) {
		cin >> a[i] >> c[i];
		data.push_back(make_pair(a[i], c[i]));
	}
}

bool compare(const pair<int, int> &x, const pair<int, int> &y) {
	return x.second * 1.0/x.first > y.second*1.0/y.first;		//sap xep giam dan, chu y can chuyen sang dangj soos thwcj
}

void knapsac(int k) {
	int sid = 0, eid = 1;	//startID, endID
	if(bk < a[k]) eid = 0;
	else eid = 1;
	
	for(int i = sid; i <= eid; i++) {
		x[k] = i;
		f = f + i*c[k];
		bk = bk - i*a[k];
		if(k == n-1) {
			if(f > fopt) {
				fopt = f;	//update ki luc
				//cout << "fopt toi uu nhat = " << fopt << endl;
				//printSolution();
			}
		} else {
			if(f + bk*c[k+1]/a[k+1] > fopt) knapsac(k+1);
		}
		
		///restore for branch and bound
		f = f - i*c[k];
		bk = bk + i*a[k];
	}
}

int main () {
	input();
	std::sort(data.begin(), data.end(), compare);
	//output();
	fopt = -1;
	f = 0;
	bk = b;
	knapsac(0);
	cout << fopt;
}