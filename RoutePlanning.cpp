#include<bits/stdc++.h>
#define MAX 101

using namespace std;

int n,r;
int a[MAX][MAX] = {};		//ma tran ke, luu tru tat ca cac duong di
//int x[MAX];		//ma tran luu kq cua duong di
int cnt;
char * str;

void input() {
	cin >> n >> r;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	string str;
	getline(std::cin, str); 	//clear buffer de buffer cua "luoongf vaof chuaanr" bij roongx, ddeer ta nhaanj 1 luong vao moi
	for(int i = 1; i <= r; i++) {
		getline(std::cin, str);
		cout << str << endl;
	}
}

int main() {
	freopen("route.txt", "r", stdin);
	input();
}

/*
Input:
6 3
0 1 2 0 1 1
1 0 1 1 1 0
0 2 0 1 3 0
4 3 1 0 0 0
0 0 1 1 0 0
1 0 0 0 0 0
1 3 5
6 3 2 5
6 1 2 3 4 5

output:
5 0 7
*/
