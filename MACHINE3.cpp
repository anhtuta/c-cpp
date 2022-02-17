#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <iostream>
#define MAX 100000
#define TAKE_THIS 1
#define DONT_TAKE 0

using namespace std;

int N;
int m;
int T;		//so luong testcase
int s[MAX];	//start
int f[MAX];	//finish
int ans;
int x,y;
int maxProduct = 0;
int sumProduct = 0;
int numOfPeriod = 0;
vector< pair<int, int> > data;

bool compare(const pair<int, int> &x, const pair<int, int> &y) {
	return x.second < y.second;		//sap xep tang dan theo chiều của mảng finish
}

void backtrack(int k) {
	if(numOfPeriod > m) return;
	int currentFinish = data[k].second;

	for (int i = k+1; i < N; ++i) {
		if(currentFinish <= data[i].first) {
			for (int j = 0; j < 2; ++j)
			{
				if(j == TAKE_THIS) {
					sumProduct = sumProduct + (f[i] - s[i]);
					numOfPeriod++;
				}


				if(numOfPeriod == m) {
					if(maxProduct < sumProduct) maxProduct = sumProduct;
				} else backtrack(i+1);

				if(j == TAKE_THIS) {
					sumProduct = sumProduct - (f[i] - s[i]);
					numOfPeriod--;
				}
			}
			
		} else if(numOfPeriod < m) backtrack(k+1);
	}
}

int main() {
	freopen("machine3.txt", "r", stdin);
	
	cin >> N >> m;

	for(int i = 0; i < N; i++) {
		cin >> s[i];
		cin >> f[i];
		data.push_back(make_pair(s[i], f[i]));
	}
	
	std::sort(data.begin(), data.end(), compare);
	
	backtrack(0);
	cout << maxProduct;

	
}



