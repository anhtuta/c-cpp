#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 500
#define INF 100000000

using namespace std;

int N, m, k;	//m = so luong sach, k = so luong scriber
//int p[MAX];
//int b[MAX];
int *p;
int *b;
int minSumPi;

bool check(int mid) {
	int cnt = 0;	//co the chia m cuon sach thanh cnt phan, thoa man dieu kien moi phan co tong so trang <= mid
					//Bay gio cho biet mid, ham nay se tim cnt, neu cnt <= k return true
	int sum = 0, max = 0;
	int index = 0, sumInx = 0;
	int b_temp[k+1];
	for(int i = 1; i <= m; i++) {
		sum += p[i];
		if(sum >= mid) {
			cnt++;
			if(cnt == k) {
				cout<<"\tcnt == k nhe!\n";
				index = i;
				sumInx = sum;
			}
			cout <<"cnt = "<<cnt<<", sum = "<<sum<<endl;
			b_temp[cnt] = i;
			max = sum > max ? sum : max;
			sum = 0;
		}
	}
	
	if(cnt == k-1) {
		cout << "\t\tsum = " <<sum<<endl;
		cnt++;
		index = m;
	}
	
	if(index < m) {
		for(int j = index+1; j <= m; j++) sumInx += p[j];
		//cout << "sumInx = "<<sumInx<<endl;
		max = sumInx > max ? sumInx : max;
		index = m;
	}
	
	if(index == m) {
		cout<<"max = "<<max<<endl;
		if(max < minSumPi) {
			minSumPi = max;
			for(int i = 1; i <= k; i++) {
				b[i] = b_temp[i];
			}
		}
	}
	if(cnt == k) cout <<"cnt == k nhe!\n";
	return cnt <= k;
}

int main() {
	freopen("books2.txt", "r", stdin);
	cin >> N;
	while(N--) {
		cin >> m >> k;
		p = (int*)malloc(sizeof(int)*(m+1));
		b = (int*)malloc(sizeof(int)*(k+1));
		minSumPi = INF;
		
		
		for(int i = 1; i <= m; i++) {
			cin >> p[i];
		}
		
		//for(int i = 0; i <= k; i++) b[i] = i;
		
		int lo = 0, hi = INF;
		while(hi > lo + 1) {
			int mid = (lo + hi)/2;
			cout<<"lo = "<<lo<<", hi = "<<hi<<", mid = "<<mid<<endl;
			if(check(mid)) {	//so mid qua lon, can giam mid xuong
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << "\nMang b la \n";
		for(int i = 0; i <= k; i++) {
			cout << b[i] << " ";		//printf("%d\n",b[i]);
		}
		cout<<endl;
		
		int idx = 1;
		b[k] = 0;	//de ko phai in ra man hinh dau / cuoi cung
		for(int i = 1; i <= m; i++) {
			cout << p[i] << " ";
			if(i == b[idx]) {
				cout << "/ ";
				idx++;
			}
		}
		cout << endl;
	}
}
