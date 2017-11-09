#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

#define PI acos(-1)
#define EPS 10e-10
#define MAX 10000

long long n, f;	//quantity of pies and quantity of friends, so there are total f+1 people
long long r[MAX];	//array of radiuses
int T;

bool p(double x) {
	long long tong = 0;
	for(int i = 1; i <= n; i++) {
		tong = tong + (long) (PI*r[i]*r[i]/x);
	}
	return tong >= (f+1);
}

int main() {
	freopen("pie.txt", "r", stdin);
	cin >> T;
	while(T--) {
		cin >> n >> f;
		double lo = 0.0, hi = 0.0;	// dien tich min, max
		double mid;
		for(int i = 1; i <= n; i++) {
			cin >> r[i];	//nhap cac ban kich cua tung chiec banh
			if(r[i] > hi) hi = r[i];
		}
		hi = PI*hi*hi;
		cout << "hi = "<<hi<<endl;
		while(hi - lo >= EPS) {
			mid = (hi + lo)/2.0;
			if(p(mid)) lo = mid;
			else hi = mid;
		}
		
		printf("%f\n", lo);
	}
}
