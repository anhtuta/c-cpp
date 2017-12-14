#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXN 16
#define INF 1000000000	//ban dau ki luc = vo cung

/*
Khá giống bài TSP: bài này đếm số trường hợp mà fopt <= m
*/
using namespace std;

int x[MAXN+1];	//luu hanh trinh di, nguoi di du lich se di theo hanh trinh: x1 -> x2 -> ... -> xn -> x1
int n,m;
int c[MAXN+1][MAXN+1] = {};
int f=0;	//chi phí cua hành trình
int fopt = INF;	//f_optimize: ki luc: la gia tri tot nhat hien tai
int mark[MAXN+1] = {};	//mang nay luu tru trang thai thanh pho thu i da di qua hay chua
int cmin = INF;
int x0,y0;
int soDapAn = 0;

int min(int a, int b)  {
	return a<b?a:b;
}

void input()
{
	cin >> n;
	cin >> m;
	int temp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> temp;
			c[i][j] = temp;
			cmin = min(cmin, c[i][j]);
			if(temp != 0) c[i][j] = temp;
			else c[i][j] = INF;
		}
	}
}

void printPath() {
	cout << "Duong di: \n";
	for(int i=1; i<=n; i++) {
		cout << x[i] << " -> ";
	}
	cout << x[1] << endl << endl;
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
				fopt = min(f + c[x[n]][x[1]], fopt);
				if(fopt <= m) soDapAn++;
				//cout << "fopt = " << fopt << endl;
				//printPath();
				fopt = m + 1;		//Reset để bắt đầu 1 bài toán khác
			} else {
				if(f + (n - k + 1)*cmin < m) tourist(k+1);		//so thanh pho con lai phai di qua. VD: n = 10, k = 6, thi con phai di qua 5 thanh pho nua: x7 -> x8 -> x9 -> x10 -> x1
				// tourist(k+1);
			}
			f = f - c[ x[k-1] ][ x[k] ];
			mark[i] = 0;
		}
	}
}

int main() {
	freopen("tspcount.txt", "r", stdin);
	input();
	x[1] = 1; mark[1] = 1;
	tourist(2);
	//output();
	cout << soDapAn;
}
