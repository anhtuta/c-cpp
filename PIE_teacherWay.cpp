#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

#define PI acos(-1)
#define EPS 10e-3
#define MAX 10000
 
int n, f;	//quantity of pies and quantity of friends, so there are total f+1 people
int r[MAX];
int T;

int p (double x) {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		cnt += int(r[i]*r[i]/x);	
	}
	return cnt >= f+1;
}

int main() {
	freopen("pie.txt", "r", stdin);
	cin >> T;
	while(T--) {
		cin >> n >> f;
		double lo = 0, hi = 0, mid;
		for(int i = 1; i <= n; i++) {
			cin >> r[i];
			if(hi < r[i]*r[i])	hi = r[i]*r[i];
		}
		
		while(hi - lo >= EPS) {
			mid = (hi + lo)/2;
			if(p(mid)) lo = mid;
			else hi = mid;
		}
		double radius = (lo+hi)/2;
		printf("%.6f\n", acos(-1)*radius);
	}
}
