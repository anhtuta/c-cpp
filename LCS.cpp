#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<algorithm>
#define MAX 10000

using namespace std;
//char x[MAX];
//char y[MAX];
string x, y;
int T, n, m;
int s[MAX][MAX];	//s[i][j] laf ddooj daif dayx con chung daif nhaat cuar "i phan twr ddaauf tieen cuar x" vaf "j phan twr ddaauf tieen cuar y"
//Chir caanf timf s[n][m] laf xong

void output() {
	for(int i = 0; i < n; i++) {
		cout << x[i];
	}
	cout << "\n";
	for(int i = 0; i < m; i++) {
		cout << y[i];
	}
	cout << "\n";
}

int max(int a, int b) {
	return a>b?a:b;
}

int main() {
	freopen("lcs2.txt", "r", stdin);
	cin >> T;
	while(T--) {
		//cin >> n >> m;
		cin >> x;
		cin >> y;
		n = x.size();
		m = y.size();
		
		for(int i = 0; i <= n; i++) {
			s[i][0] = 0;		//khi xaau y roongx
		}
		
		for(int i = 0; i <= m; i++) {
			s[0][i] = 0;		//khi xaau x roongx
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(x[i] == y[j]) {
					//s[i][j] = s[i-1][j-1] + 1;
					s[i+1][j+1] = s[i][j] + 1;
				} else {
					s[i+1][j+1] = max(s[i+1][j], s[i][j+1]);
				}
				//cout << "s["<<i+1<<"]["<<j+1<<"] = "<< s[i+1][j+1] << endl;
			}
		}
		
		cout << s[n][m] << endl;
	}
}
