#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 130
#define MAX_TESTCASE 1001

using namespace std;

int n,m;
int a[MAX];
int holes[MAX][MAX] = {};
int countSolution;

void printSolution() {
	countSolution++;
}

bool thuocUCV(int i, int k) {
	if(holes[k][i] == 1) return false;
	
	for(int j = 1; j < k; j++) {
		if(a[j] == i) return false;
		if( abs(a[j] - i) == abs(j - k) ) return false;		//Neu |a[i] - a[k]| = |i-k|, tuc là con hau thu k cùng duong chéo voi bat ki con hau nào da xep truoc do, thi return false
		// |xj - xk| != |j - k|, voi moi j = {1,2,...,k-1}
		//nghia la |xj - i| != |j - k|
	}
	return true;
}

void queen(int k) {		//tim vi tri con hau o hang thu k
	for(int i = 1; i <= n; i++) {
		if(thuocUCV(i, k)) {
			a[k] = i;
			if(k == n) {
				printSolution();
			} else queen(k+1);
		}
	}
}

int main () {
	freopen("queen2.txt", "r", stdin);
	cin >> n >> m;
	while(n != 0) {
		countSolution = 0;
		holes[MAX][MAX] = {};
		a[MAX] = {};
		
		int row, col;
		
		for(int i = 1; i <= m; i++) {
			cin >> row >> col;
			holes[row][col] = 1;
		}
		queen(1);
		cout << countSolution << endl;
		cin >> n >> m;
	}
}
