#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 10000

using namespace std;
string str;
char x[MAX];
char y[MAX];
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
}

int max(int a, int b) {
	return a>b?a:b;
}

int main() {
	cin >> str;
	cout << str << endl;
	cout << str.size() << endl;
	cout << str[2] << endl;
}
