#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<algorithm>
#define MAX 10000

using namespace std;

string x, y;
int T, n, m;
int d[MAX][MAX];	//d[i][j] laf edit distance ngawns nhaat cuar "i phan twr ddaauf tieen cuar x" vaf "j phan twr ddaauf tieen cuar y"
//Chir caanf timf d[n][m] laf xong

int min(int a, int b, int c) {
	if(a < b) return a<c?a:c;
	else return b<c?b:c;
}

int max(int a, int b, int c) {
	if(a > b) return a>c?a:c;
	else return b>c?b:c;
}

int main() {
	freopen("ed.txt", "r", stdin);
	cin >> T;
	while(T--) {
		cin >> x;
		cin >> y;
		
		n = x.size();
		m = y.size();
		
		for(int i = 0; i <= n; i++) {
			d[i][0] = i;		//khi xaau y roongx
		}
		for(int i = 0; i <= m; i++) {
			d[0][i] = i;		//khi xaau x roongx
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int temp;
				if(x[i] == y[j]) temp = 0;
				else temp = 1;
				
				d[i+1][j+1] = min(d[i][j] + temp, d[i][j+1] + 1, d[i+1][j] + 1);	// = max(replace/do_nothing, add, remove)  (eg: add means add yj into xi)
				//cout << "d["<<i+1<<"]["<<j+1<<"] = "<< d[i+1][j+1] << endl;
			}
		}
		
		cout << d[n][m] << endl;
	}
}
