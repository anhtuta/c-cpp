#include<stdio.h>
#include<iostream>
#include<time.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int WaterJug(int x, int y, int c) {
	queue< pair<int, int> > q;
	pair<int, int> pa(x,y);
	q.push(pa);
	
	pair<int, int> kq = q.front();
	cout << kq.first;
	cout << kq.second;
	
	return -1;
}

int main() {
	int a,b,c;
	cin >> a;
	cin >> b;
	cin >> c;
	
	int kq = WaterJug(a, b, c);
	cout << kq;
}
/*
class Pair {
	int x,y;
	public: Pair(int x1, int y1) {
		x = x1;
		y = y1;
	}
};
*/
