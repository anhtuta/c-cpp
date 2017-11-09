#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 130
#define MAX_TESTCASE 1001

using namespace std;

int n[MAX],m[MAX];
int a[MAX][MAX] = {};
int holes[MAX][MAX][MAX] = {};
int soCachXep;
int testCase;
int answer[MAX_TESTCASE];

void printSolution() {
	//cout << "testCase = " << testCase << endl;
	answer[testCase]++;
}

bool thuocUCV(int i, int k) {
	if(holes[testCase][k][i] == 1) return false;
	
	for(int j = 1; j < k; j++) {
		if(a[testCase][j] == i) return false;
		if( abs(a[testCase][j] - i) == abs(j - k) ) return false;		//Neu |a[i] - a[k]| = |i-k|, tuc là con hau thu k cùng duong chéo voi bat ki con hau nào da xep truoc do, thi return false
		// |xj - xk| != |j - k|, voi moi j = {1,2,...,k-1}
		//nghia la |xj - i| != |j - k|
	}
}

void queen(int k) {		//tim vi tri con hau o hang thu k
	//cout << "testCase = " << testCase << endl;
	for(int i = 1; i <= n[testCase]; i++) {
		if(thuocUCV(i, k)) {
			a[testCase][k] = i;
			if(k == n[testCase]) {
				printSolution();
			} else queen(k+1);
		}
	}
}

int main () {
	soCachXep = 0;
	testCase = 0;
	freopen("queen3.txt", "r", stdin);
	int x = 1, y = 1;
	while(x != 0 || y != 0) {
		testCase++;
		cin >> x;
		cin >> y;
		n[testCase] = x;
		m[testCase] = y;
		
		int row, col;
		if(x != 0 || y != 0) {
			for(int i = 1; i <= y; i++) {
				cin >> row >> col;
				holes[testCase][row][col] = 1;
			}
		}
	}
	
	int temp = testCase;
	for(int i = 1; i < temp; i++) {
		testCase = i;
		queen(1);
	}
	
	for(int i = 1; i < temp; i++) {
		cout << answer[i] << endl;
	}
}
