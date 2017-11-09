#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 20

int N;
int tienTraLai;
int a[6] = {500, 100, 50, 10, 5, 1};
int cnt = 0;

using namespace std;

void moneyChanging(int m) {		//m = so tien can tra lai
	for(int i = 0; i < 6; i++) {
		if(m >= a[i]) {
			cout << "m = " << m << endl;
			m = m - a[i];
			cnt++;
			if(m == 0) {
				cout << cnt;
				break;
			} else moneyChanging(m);
			break;
		}
	}
}

int main() {
	freopen("money.txt", "r", stdin);
	cin >> N;
	tienTraLai = 1000 - N;
	moneyChanging(tienTraLai);
	//cout << cnt;
}
