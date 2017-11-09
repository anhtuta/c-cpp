#include<stdio.h>
#include<stdlib.h>
#include <iostream>
//#define MAX 1000

using namespace std;

int * a;
int n, m;
int viTriCanInkq;
int cnt;
bool isPrint = false;
int sid = 0, eid = 1;

void printSolution() {
	isPrint = true;
	for(int i=1; i<=n; i++) {
		cout<< *(a+i) <<" ";
	}
}

void binaryList(int k) {
	if(isPrint) return;
	sid = 0; eid = 1;
	
	if(k > 1) {
		int t = k-1;
		int cnt = 0;
		if( (n - k + 1) < m && *(a + n - k) == 1) sid = 0;
		else 
			for(int i = t; i >=1; i--) {
				if(*(a+i) == 0) {
					cnt++;
					if(cnt == m - 1) {
						sid = 1;
						break;	
					}
				} else {
					sid = 0;
					break;	
				}
			}
	}
	
	for(int i = sid; i <= eid; i++) {
		*(a+k) = i;
		if(k == n) {
			cnt++;
			if(cnt == viTriCanInkq)	{
				printSolution();
				return;
			}
		} else {
			binaryList(k+1);
		}
	}
}

int main() {
	cnt = 0;
	cin >> n;
	cin >> viTriCanInkq;
	cin >> m;
	a = (int *) malloc(sizeof(int)*(n+1));
	binaryList(1);
	if(isPrint == false) cout << "-1";
}