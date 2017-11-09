#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 600

using namespace std;

int s[MAX][MAX];
int W, H, N;

int min(int a, int b, int c) {
	if(a > b) return a>c?a:c;
	else return b>c?b:c;
}
void input() {
	cin >> W >> H >> N;
	for(int i=1; i<=W; i++) {
		for(int j=1; j<=H; j++) {
			s[i][j] = i*j;	//ko cawts gif car!
			
		}
		int w, h;
		for(int i=1; i<=N; i++) {
			cin >> w >> h;
			s[w][h] = 0;	//ko cawts gif car!
		}
	}
}

int dp() {
	for(int w = 1; w <= W; w++) {
		for(int h = 1; h <= H; h++) {
			// tinhs s[w][h]
			for(int i = 1; i < w; i++) {
				s[w][h] = min(s[w][h], s[i][h], s[w-i][h]);		//cawts docj
			}
			
			for(int i = 1; i < h; i++) {
				s[w][h] = min(s[w][h], s[w][i], s[w][h-i]);		//cawts docj
			}
		}
	}
	return s[W][H];
}

int main() {
	freopen("marble.txt", "r", stdin);
	input();
	cout << dp();
}
