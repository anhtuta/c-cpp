#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 100000

using namespace std;

int n, L1, L2;
int a[MAX];

void input() {
	cin >> n >> L1 >> L2;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
}

int dp() {
	int max = a[1];
	int mEH = a[1];		//mEH = khoi luong lon nhat cua "day con ket thuc tai ai"
	int t = 1;		//so luong phan tu cua day con ket thuc tai ai
	
	for(int i = 2; i <= n; i++) {
		if(mEH > 0) {
			mEH = mEH + a[i];
			t++;
		} else {
			mEH = a[i];
			t = 1;
		}
		cout << "mEH[" << i << "] = " <<mEH<<", t = " <<t<<endl;
		//if(mEH > max) max = mEH;
		if(mEH > max && t >= L1 && t <= L2) max = mEH;
	}
	
	//Cach giair nafy sai. Neeus t luoon luoon < L1 thi sao?
	
	return max;
}

int main() {
	freopen("maxSubBoundLeng.txt", "r", stdin);
	input();
	cout << dp();
}
