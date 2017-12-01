#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 601

using namespace std;

//int s[MAX][MAX];
int s[MAX][MAX];
int W, H, N;
int T;		//testcase

int min(int a, int b, int c) {
	if(a > b) return a>c?a:c;
	else return b>c?b:c;
}

int min(int a, int b) {
	if(a < b) return a;
	else return b;
}

void input() {
	cin >> W >> H;
	cin >> N;
	for(int i=1; i<=W; i++) {
		for(int j=1; j<=H; j++) {
			s[i][j] = i*j;	//ko cắt gì cả và vứt tấm gỗ này đi vì ko thỏa mã kích thước
							//(có thể nó có kích thước bé hơn kích thước nhỏ nhất của đề bài),
							//do đó phần thừa chính = kích thước tấm gỗ
		}
	}
	int w, h;
	for(int i=1; i<=N; i++) {
		cin >> w >> h;
		s[w][h] = 0;	//ko cắt gì cả, và lấy luôn tấm gỗ này! Do đó phần thừa = 0
	}
	for(int i=1; i<=H; i++) s[i][0]=0;
    for(int i=1; i<=W; i++) s[0][i]=0;	//tấm gỗ kích thước w*0 hoặc 0*h thì phần thừa tất nhiên = 0
}

int dp() {
	for(int w = 1; w <= W; w++) {
		for(int h = 1; h <= H; h++) {
			if(s[w][h] == 0) continue;
			// tính s[w][h]
			for(int i = 1; i < w; i++) {
				s[w][h] = min(s[w][h], s[i][h] + s[w-i][h]);		//cắt dọc
			}
			
			for(int i = 1; i < h; i++) {
				s[w][h] = min(s[w][h], s[w][i] + s[w][h-i]);		//cắt ngang
			}
			//cout << "s["<<w<<"]["<<h<<"] = "<<s[w][h]<<endl;
		}
	}
	return s[W][H];
}

int main() {
	freopen("marble.txt", "r", stdin);
	cin >> T;
	while(T--) {
		input();
		cout << dp();
	}
}
