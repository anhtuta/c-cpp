#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define MAX 1000005

using namespace std;

int N;
long long M;
long long *x;
long long lo=0, hi=0;

void input() {
	cin >> N >> M;
	x = (long long*)malloc(sizeof(long long)*(N+1));
	for(int i=1; i<=N; i++) {
		cin >> x[i];
		if(hi < x[i]) hi = x[i];
	}
	// hi = max{x[i]}, i = 1,2,...,N
}

// kiểm tra xem cưa với chiều cao = H thì lượng gỗ thu đc có >= M hay ko
// Nếu có thì return true, và cần chặt cao hơn (nâng chiều cao của cưa lên)
// ngược lại cần hạ cưa thấp hơn
int p(int H) {
	long long amountOfWood = 0;
	for (int i = 1; i <= N; ++i) {
		if(x[i] > H) amountOfWood += (x[i] - H);
	}
	return amountOfWood >= M;
}

int search() {
	int mid;
	while(hi > lo + 1) {
		mid = (hi + lo)/2;
		cout <<"mid="<<mid<<endl;
		if(p(mid)) lo = mid;
		else hi = mid;
	}

	if(p(hi)) return hi;
	else return lo;
}

int main() {
	freopen("tree.txt", "r", stdin);
	input();
	cout << search() << endl;
}



