#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<algorithm>
#define MAX 100

using namespace std;

typedef struct {
	int x, y, z;	//x,y = width, length, and z = height of brick
} block;

int n;
block a[100];	//toi da la 30*3 = 90 vien gach
int maxH[100];

int max(int x, int y) {
	return x>y?x:y;
}

void input() {
	cin >> n;
	if(n == 0) exit(0);
	int x,y,z;
	for(int i = 1; i <= n; i++) {
		cin >> x >> y >> z;
		a[3*i - 2].x = x;
		a[3*i - 2].y = y;
		a[3*i - 2].z = z;
		a[3*i - 1].x = y;
		a[3*i - 1].y = z;
		a[3*i - 1].z = x;
		a[3*i].x = z;
		a[3*i].y = x;
		a[3*i].z = y;
		
	}
}

int compare(block &a, block &b) {
	return a.x * a.y < b.x * b.y;
}

void sort() {
	for(int i = 1; i <= 3*n; i++) {
		for(int j = i+1; j <= 3*n; j++) {
			if(compare(a[i], a[j])) {
				block temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

//tim chieu cao lon nhat cua tower ma co dinh la vien gach i
int dp(int i) {
	maxH[i] = a[i].z;
	for(int j = 1; j <= i - 1; j++) {
		// if(ai < aj) (so sanh theo dien tich day)
		if((a[i].x < a[j].x && a[i].y < a[j].y) || (a[i].x < a[j].y && a[i].y < a[j].x)) {
			cout << "maxH[" << i << "] = " <<maxH[i] << ", a["<<i<<"].z + maxH[" << i << "] = " << a[i].z + maxH[j] << endl;
//			if(maxH[i] > a[i].z + maxH[j]) {
//				cout << "i = " << i <<", ai.z = " << a[i].z << ", maxHi = " << maxH[i] << ": Lon hon\n";
//				cout << "maxHi = [";
//				for(int k = 1; k <= i; k++) cout << maxH[k] << " ";
//				cout << "]; ai.z + maxHj = " <<a[i].z + maxH[j] <<endl;
//			} //else cout << "\tNho hon\n";
			
			maxH[i] = max(maxH[i], a[i].z + maxH[j]);
			//maxH[i] = a[i].z + maxH[j];	Neu dung ntnay la sai!
		}
	}
	return maxH[i];
}

int main() {
	freopen("tower.txt", "r", stdin);
	int cnt = 1;
	while(1) {
		int res = 0;
		input();
		sort();
		for(int i = 1; i <= 3*n; i++) {
			res = max(res, dp(i));
		}
		printf("Case %d: maximum height = %d\n", cnt++, res);
	}
	
}
