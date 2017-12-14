#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define MAX 1000005

using namespace std;

int n,c;
int *x;
/*
x[i] là vị trí của từng ngăn chuồng. VD: x = {1,2,8,4,9} nghĩa là
ngăn 1 và 2 cách nhau 1, ngăn 4 và 5 cách nhau = 9-4=5
cần sắp xếp lại chuồng bò: x = {1,2,4,8,9} sau đó dùng chia đê trị
*/

void input() {
	cin >> n >> c;	//n = số ngăn, c = số bò
	x = (int*)malloc(sizeof(int)*(n+1));
	for (int i = 1; i <= n; ++i)
	{
		cin >> x[i];
	}
	sort(x+1, x+n+1);
}

// nếu có thể xếp c con bò mà khoảng cách ngắn nhất giữa 2 con >= dis thì return true
// chú ý rằng: khoảng cách giữa 2 con bò liên tiếp nhau i, j là: x[i] - x[j] (i > j)
bool p(int dis) {
	// do khoảng cách các ngăn đã sắp xếp trước nên có thể làm như sau
	int prev = 1, cnt = 1;
	for (int i = 2; i <= n; ++i)
	{
		if(x[i] - x[prev] >= dis) {
			cnt++;
			prev = i;
		}
	}
	return cnt >= c;
}

int search() {
	int lo = 0, hi = MAX;
	int mid;
	while(hi > lo + 1) {
		mid = (hi + lo)/2;
		if(p(mid)) lo = mid;
		else hi = mid;
	}

	//sau vong while thi kq la: (lo,lo) hoac(lo,lo+1)
	if(p(hi)) return hi;
	else return lo;
}

int main() {
	freopen("cow.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		input();
		cout << search() << endl;
	}
}