//Tinh can bac 2 cua x, ko dung sqrt()
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

double x;
double EPS = 1E-10;	//do chinh xac = so chu so dang sau dau thap phan
double lo, hi;

bool p(double j) {
	return j*j >= x;
}

int main() {
	cin >> x;
	lo = 0; hi = x/2;
	if(x <= 4) hi = x;
	if(x < 0) {
		cout << "Math error! You asshole!\n";
		return -1;	
	}
	while(hi - lo > EPS) {
		double mid = (hi + lo)/2;
		if(p(mid)) {	//if(mid^2 >= x) thi canBac2CuaX phai o ben trai mid
			hi = mid;
		} else {
			lo = mid;
		}
	}
	printf("%0.10f", lo);
}
