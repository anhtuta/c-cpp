#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<algorithm>
#define MAX 100

using namespace std;

int n;

typedef struct {
	int x,y,z;		//x,y la chieu dai, chieu rong, z la chieu cao cua vien gach	
} block;

block a[MAX];
int maxH[MAX];

void output() {
	for(int i = 1; i <= n; i++) {
		cout << a[i].x << " "<<a[i].y <<" " << a[i].z <<endl;	
	}
	cout << "n = "<<n<<endl;
}

int max(int x, int y) {
	return x>y?x:y;
}

void input() {
	cin >> n;
	if(n==0) exit(0);
	int eid = 3*n;
	int gap = 1;
	int x,y,z;
	for(int i = 1; i <= eid; i = i + gap) {
		//cout<<"i = "<<i<<", eid = "<<eid<<", gap = "<<gap<<endl;
		cin >> x >> y >> z;
		if(x == y && y == z) {
			a[i].x = x;
			a[i].y = y;
			a[i].z = z;
			gap = 1;
			eid = eid - 2;
		} else {
			a[i].x = x; a[i+1].x = y; a[i+2].x = z;
			a[i].y = y; a[i+1].y = z; a[i+2].y = x;
			a[i].z = z; a[i+1].z = x; a[i+2].z = y;
			gap = 3;
		}
	}
	n = eid;	/// n bay gio = tong so vien gach, tinh ca vien gach xoay theo thu tu khac
}

int compare(block &a, block &b) {
	return a.x * a.y < b.x * b.y;
}

void sort() {
	for(int i = 1; i <= n; i++) {
		for(int j = i+1; j <= n; j++) {
			if(compare(a[i], a[j])) {
				block temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

// kiem tra xem vien gach b co xep chong len vien gach a dc ko
// nghia la neu (a < b) thi return true
bool checkBlock(block &a, block &b) {
	if((a.x < b.x && a.y < b.y) || (a.x < b.y && a.y < b.x)) return true;
	return false;
}

//tim chieu cao lon nhat cua tower ma co dinh la vien gach i
int dp(int i) {
	maxH[i] = a[i].z;
	for(int j = 1; j < i; j++) {
		if(checkBlock(a[i], a[j])) {
			maxH[i] = max(maxH[i], a[i].z + maxH[j]);
		}
	}
	return maxH[i];
}

int main() {
	freopen("tower.txt", "r", stdin);
	int cnt = 1;
	while(1) {
		input();
		sort();
		//output();
		int maxTower = 0;
		for(int i = 1; i <= n; i++) {
			maxTower = max(maxTower, dp(i));	//maxTower la gia tri lon nhat trong day dp(i)
		}
		printf("Case %d: maximum height = %d\n", cnt++, maxTower);
	}
	
}
