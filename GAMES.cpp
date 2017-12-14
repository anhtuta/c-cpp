#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define MAX 31

using namespace std;

int n;
int host[MAX];
int guess[MAX];		// VD: host[3] và guess[3] tương ứng 
// là màu trang phục của đội 3 khi đội này 
// lần lượt là chủ nhà và khách
int soDapAn = 0;

void input() {
	cin >> n;
	int h, g;
	for (int i = 1; i <= n; ++i)
	{
		cin >> h >> g;
		host[i] = h;
		guess[i] = g;
	}
}

void games() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(guess[i] == host[j]) soDapAn++;
			if(host[i] == guess[j]) soDapAn++;
		}		
	}
}

int main() {
	freopen("games.txt", "r", stdin);
	input();
	games();
	cout << soDapAn/2;	// do hàm games đã đếm 2 lần mỗi đội
}