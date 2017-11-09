#include<stdio.h>
#include<stdlib.h>
#include <iostream>

#define MAXN 20
#define MAXM 400
#define INF 1000000000	//ban dau ki luc = vo cung

using namespace std;

int x[MAXN+1];	//luu hanh trinh di, nguoi di du lich se di theo hanh trinh: x1 -> x2 -> ... -> xn -> x1
int n,m;
int c[MAXN+1][MAXM+1] = {};
int f=0;	//chi phí cua hành trình
int fopt = INF;	//f_optimize: ki luc: la gia tri tot nhat hien tai
int mark[MAXN+1] = {};	//mang nay luu tru trang thai thanh pho thu i da di qua hay chua
int cmin = INF;

void input() {
	cin >> n;
	cin >> m;
	for(int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		cin >> c[x][y];
		cmin = min(cmin, c[x][y]);
	}
}

void output() {
	for(int i=1; i<=n; i++) {
		cout << x[i] << " -> ";
	}
	cout << x[1] << endl;
}

void tourist(int k) {	//tim thanh pho phai di qua tai buoc thu k (nghia la tim xk)
	//cout << "k = " << k << endl;
	for(int i = 2; i <= n; i++) {
		if(mark[i] == 0 && c[ x[k-1] ][i] > 0) {
			x[k] = i;
			//cout << "xk = " << i << endl;
			f = f + c[ x[k-1] ][ x[k] ];
			mark[i] = 1;
			if(k == n) {
				//f =  f + c[x[n]][x[1]];
				fopt = min(f + c[x[n]][x[1]], fopt);
			} else {
				if(f + (n - k + 1)*cmin < fopt) tourist(k+1);		//so thanh pho con lai phai di qua. VD: n = 10, k = 6, thi con phai di qua 5 thanh pho nua: x7 -> x8 -> x9 -> x10 -> x1
			}
			f = f - c[ x[k-1] ][ x[k] ];
			mark[i] = 0;
		}
	}
}

int main() {
	freopen("tourist.txt", "r", stdin);
	input();
	x[1] = 1; mark[1] = 1;
	tourist(2);
	output();
	cout << fopt;
}
