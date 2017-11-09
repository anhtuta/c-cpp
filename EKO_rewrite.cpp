#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<algorithm>
#define MAX 1000005

using namespace std;

int N;
long long M;
long long x[MAX];
long long lo=0, hi=0;

//kiem tra xem neeus chawtj caay vowis chieeuf cao cuar cais cwa laf H thif lwowngj goox thu ddc cos thoar manx ddieeuf kieenj >= M hay ko
bool p(int H) {
	long long cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(x[i] > H) cnt += (x[i] - H);
	}
	return cnt >= M;
}

int input() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		cin >> x[i];
		if(x[i] > hi) hi = x[i];
	}
}

int cutTree() {
	while(hi > lo + 1) {	//Neu hi > lo thi co the se bi lap vo han. VD: hi = 4, lo = 3, khi do mid = 3, va do do lap vo han!
		int mid = (hi + lo)/2;
		if(p(mid)) lo = mid;
		else hi = mid;
	}
	if(p(hi)) return hi;
	else return lo;
}

int main() {
	freopen("cut_tree.txt", "r", stdin);
	input();
	cout << cutTree() << endl;
}


