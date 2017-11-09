#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<algorithm>
#define MAX 1000005

using namespace std;

int n,c;
int x[MAX];

void input() {
	cin >> n >> c;
	for(int i=1; i<=n; i++) {
		cin >>x[i];
	}
	sort(x+1, x+n+1);
}

//kiem tra xem co the xep c con bo sao cho khoang cach ngan nhat
//giua 2 con >= dis hay khong
int p(int dis) {
	int prev=1, cnt=1;	//prev la vi tri con bo truoc do vua xep
	for(int i=2; i<=n; i++) {
		if(x[i] >= x[prev] + dis) {
			cnt++;
			prev = i;
		}
	}
	return cnt >= c;
}

int search() {
	int lo = 1, hi = x[n] - x[1];
	while(hi > lo + 1) {
		int mid = (hi+lo)/2;
		if(p(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	
	//sau vong while thi kq la: (lo,lo) hoac(lo,lo+1)
	if(p(hi)) return hi;
	else return lo;
}

int main() {
	freopen("cow.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		input();
		cout << search() << endl;
	}
}
