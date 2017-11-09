#include<bits/stdc++.h>
#define MAX 100

/*
VD: n=4, k=3, m=5
1 2
1 3
1 4
2 3
3 4

kq x = {1-2-3-4, 2-3-4-1, 3-4-1-2, 4-1-2-3, 2-1-3-4, 4-1-3-2}
VD neu x = 2-3-4-1 nghia la buoc thu k=2 se phai di qua node 3
*/
using namespace std;

int n,sobuoc,m;
int a[MAX][MAX] = {};		//ma tran ke, luu tru tat car cac duong di
int x[MAX];		//ma tran luu kq cua duong di
int cnt;
bool thuocUCV(int i, int k) {	//tim gia tri node tai buoc thu k
	if(k == 1) return true;
	//cout << "i = " << i << ", k = " << k << endl;
	for(int j = 1; j < k; j++) {
		if(x[j] == i) return false;
	}
	if(a[ i ] [ x[k-1] ] == 1) return true;
	return false;
}

void input() {
	cin >> n >> sobuoc;
	cin >> m;
	for(int i=1; i<=m; i++) {
		int x,y;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
}

void printSolution() {
	cnt++;
	for(int i=1; i<=n; i++) {
		cout<<x[i]<<" ";
	}
	cout << endl;
}

void kpath(int k) {
	//cout << "k = " << k << endl;
	for(int i = 1; i <= n; i++) {
		if(thuocUCV(i, k)) {
			x[k] = i;
			if(k == sobuoc) {
				printSolution();
			} else kpath(k+1);
		}
		//else cout <<"ko thuc UCV" << endl;
	}
}

int main() {
	freopen("kpath.txt", "r", stdin);
	input();
	cnt = 0;
	sobuoc++;
	kpath(1);
	cout << "kq = " << cnt/2;
}
