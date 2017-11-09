#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <iostream>
#define MAX 20

int n;
int x[MAX] = {};
int numberCoin [10] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};	//mangr soos towf
int numberWay [10] = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};	//mangr cachs chia
long long w;
int c;

using namespace std;

int main() {
	freopen("atm.txt", "r", stdin);
	int testcase;
	cin >> testcase;
	while(testcase--) {
		for(int i = 0; i < MAX; i++) {
			x[i] = 0;
		}
		cin >> w >> c;
		if(w < 1000 || w % 1000 != 0) {
			cout << "0\n";
			continue;
		}
		
		w = w/1000;
		int id = 0;
		while(w != 0) {
			//tachs twngf chwx soos trong toongr soos tieenf ra. VD: w = 7658 thi x0 = 8, x1 = 5, x2 = 6, x3 = 7
			//cout << "x[" << id << "] = " << x[id] << endl;
			x[id] = w%10;
			w = w/10;
			id++;
		}
		long long sum = 0;
		for(int i = c+1; i < MAX; i++) {
			sum += x[i]*pow(10, i);
		}
		//cout << "sum = " << sum << endl;
		long long numCoin = sum/(5*pow(10, c));
		long long numWay = 1;
		
		for(int i = 0; i <= c; i++) {
			numCoin += numberCoin[x[i]];
			if(i == c) {
				if(sum > 0 && (x[i] == 1 || x[i] == 4)) numWay *= numberWay[x[i]] + 1;
				else numWay *= numberWay[x[i]];
			} else {
				numWay *= numberWay[x[i]];
			}
		}
		
		cout << numCoin << " " << numWay << endl;
	}
}
