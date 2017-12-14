#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// DE THI GIUA KI 20171
int n;
long long MODU = 10*10*10*10*10*10*10*10*10+7;

int main() {
	cin >> n;
	long long temp;
	long long s = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		s += temp;
		s = s%MODU;
	}
	cout << s;
}

