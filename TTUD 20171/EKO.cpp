#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<algorithm>
#define MAX 1000005

using namespace std;

int N;
long long M;
long long x[MAX];
long long lo=0, hi=0;

void input() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		cin >>x[i];
		if(hi < x[i]) hi = x[i];
	}
	//sort(x+1, x+n+1);
}

int p(int H) {
	long long cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(x[i] > H) cnt = cnt + (x[i] - H);
	}
	return cnt >= M;
}

int search() {
	while(hi > lo + 1) {
		int mid = (hi + lo)/2;
		if(p(mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}

	if(p(hi)) return hi;
	else return lo;
}

int main() {
	//freopen("cut_tree.txt", "r", stdin);
	input();
	cout << search() << endl;
}



