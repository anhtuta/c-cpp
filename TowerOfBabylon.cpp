#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<algorithm>
#define MAX 10000

using namespace std;

int n;
int w[MAX];
int l[MAX];
int h[MAX];
int x,y,z;

void output() {
	for(int i = 1; i <= n; i++) {
		cout << w[i] << " "<<l[i]<<" " <<h[i]<<endl;	
	}	
}

int main() {
	freopen("tower.txt", "r", stdin);
	n = -1;
	while(n != 0) {
		cin >> n;
		int eid = 3*n;
		int gap = 1;
		for(int i = 1; i <= eid; i = i + gap) {
			cout<<"i = "<<i<<", eid = "<<eid<<", gap = "<<gap<<endl;
			cin >> x >> y >> z;
			if(x == y && y == z) {
				w[i] = x;
				l[i] = y;
				h[i] = z;
				gap = 1;
				eid = eid - 2;
			} else {
				w[i] = x; w[i+1] = y; w[i+2] = z;
				l[i] = y; l[i+1] = z; l[i+2] = x;
				h[i] = z; h[i+1] = x; h[i+2] = y;
				gap = 3;
			}
		}
		n = eid;
		output();
	}
	
}
