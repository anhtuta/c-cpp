//Tinh can bac 2 cua x, ko dung sqrt()
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <math.h>

#define EPS pow(10, -5)
#define MAX_TESTCASE 1001

using namespace std;

float x;

float canBac2(float a) {
	if(a*a <= x + EPS && a*a >= x - EPS) return a;
	
	if(a*a > x) {
		cout << "vao day1, a = " << a << endl;
		cout << "a^2 = " << (a*a) << ", x = " << x << endl;
		canBac2(a/2);
	} else {
		cout << "	vao day2\n";
		cout << "	a^2 = " << (a*a) << ", x = " << x << endl;
		canBac2(a*2);	
	}
}

int main() {
	x = 2;
	cout << canBac2(5);
}
