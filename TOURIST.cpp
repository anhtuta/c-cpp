#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 50
#define INF 1000000000	//ban dau ki luc = vo cung

int x[MAX+1];
int n;
int c[MAX][MAX];
int f=0;	//chi phi cua hanh trinh
int fopt = INF;	//f_optimize: ki luc: la gia tri tot nhat hien tai
int mark[MAX] = {};	//mang nay luu tru trang thai thanh pho thu i da di qua hay chua
int cmin = INF;

using namespace std;
int min(int a, int b) {
	return a < b?a : b;
}

void resetData() {
	for(int i=1; i<=n; i++) {
		mark[i] = 0;	
	}
}

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> c[i][j];
			if(i != j) cmin = min(cmin, c[i][j]);
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cout << c[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

void output() {
	for(int i=1; i<=n; i++) {
		cout << x[i] << " -> ";
	}
	cout << x[1];
}

void tourist(int k) {	//tim thanh pho phai di qua tai buoc thu k
	cout << "k = " << k << endl;
	for(int i=1; i<=n; i++) {
		if(mark[i]==0) {
			x[k] = i;
			f = f + c[x[k-1]][k];
			cout << "	i = " << i << ", f = " << f << endl;
			mark[i] = 1;	//dánh dâu diêm này dã di qua rôi!
			if(k == n) {
				f =  f + c[x[n]][1];	//f = gia cua quang duong sau khi di het 1 vong tat ca cac thanh pho va quay ve thanh pho ban dau
				fopt = min(fopt, f);	//update ki luc
				cout << "	f = " << f << ", fopt = " << fopt << endl;
				
				if(f <= fopt) {
					//in solution nay ra man hinh
					cout << "\tKq: ";
					output();
					cout << endl << endl;
				}
			} else {
				if((f + (n - k + 1)*cmin) < fopt)	tourist(k+1);
			}
			
			//khoi phuc trang thai cho cac lan duyet khac
			f = f - c[x[k-1]][k];
			mark[i] = 0;
			//Duyet xong het thi phai tra lai trang thái ban dâu (diêm này chua di qua)
			//va tra lai gia da di qua
			//de lan duyet khac con co the di qua dc!
		}
	}
}

int main() {
	freopen("tourist.txt", "r", stdin);
	input();
	resetData();
	x[1] = 1; mark[1] = 1;
	tourist(2);
	cout << "fopt = " << fopt << endl;
}
