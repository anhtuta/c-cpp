#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <iostream>
#define MAX 100000

using namespace std;


int N;
int T;		//so luong testcase
int s[MAX];	//start
int f[MAX];	//finish
int ans;
int x,y;

bool compare(const pair<int, int> &x, const pair<int, int> &y) {
	return x.second < y.second;		//sap xep tang dan
}

int main() {
	freopen("busyman.txt", "r", stdin);
	cin >> T;
	
	for(int j = 1; j <= T; j++) {
		vector< pair<int, int> > data;
		cin >> N;
		for(int i = 0; i < N; i++) {
			s[i] = f[i] = 0;
		}
		// giai quyet voi tung test case
		for(int i = 0; i < N; i++) {
			cin >> s[i];
			cin >> f[i];
			data.push_back(make_pair(s[i], f[i]));
		}
		
		std::sort(data.begin(), data.end(), compare);
		
		/*======thuat toan o day=====*/
		int currentFinish = data[0].second;
		ans = 1;
		for(int i = 1; i < N; i++) {
			if(currentFinish <= data[i].first) {
				currentFinish = data[i].second;
				ans++;
				//cout << "currentFinish = " << currentFinish << endl;
			}
		}
		cout << ans << endl;
		/*===========================*/
	}
}


