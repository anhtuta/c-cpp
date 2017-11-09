//Tinh can bac 2 cua 2, ko dung sqrt()
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

double x;
double EPS = 1E-10;		//do chinh xac = so chu so dang sau dau thap phan
double lo = -1000.0, hi = 1000.0;

bool p(double j) {
	return j*j >= x;
}

int main() {
	x = 2.0;
	while(hi - lo > EPS) {
		double mid = (hi + lo)/2.0;
		if(p(mid)) hi = mid;
		else lo = mid;
	}
	printf("%0.10f", lo);
}
