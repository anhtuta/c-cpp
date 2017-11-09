#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 1000

/*
liet ke xau nhi phan do dai n ma ko co m so 0 dung lien nhau
in ra xau vi tri thu viTriCanInKq
*/
using namespace std;

int a[MAX+1];
int n, m;
int viTriCanInkq;
int cnt;
bool isPrint = false;
int soLanDuyet = 0;

void printSolution() {
	isPrint = true;
	for(int i=1; i<=n; i++) {
		cout<<a[i]<<" ";
	}
	//cout << endl;
}

//Chu y rang: neu m = 3 thi chi co toi da 2 chu so 0 dung canh nhau!
void binaryList(int k) {
	if(isPrint) return;
	cout << "k = " << k << endl;
	int sid = 0, eid = 1;
	
	if(k > 1) {
		int t = k-1;
		int cnt = 0;
		if( (n - k + 1) < m && a[n - k] == 1) sid = 0;
		else 
			for(int i = t; i >=1; i--) {
				if(a[i] == 0) {
					cnt++;
					if(cnt == m - 1) {
						sid = 1;
						break;	
					}
				} else {
					sid = 0;
					break;	
				}
			}
	}
	
	for(int i = sid; i <= eid; i++) {
		soLanDuyet++;
		a[k] = i;
		if(k == n) {
			cnt++;
			cout << "	cnt = " << cnt << endl;
			if(cnt == viTriCanInkq)	{
				printSolution();
				return;
			}
		} else {
			binaryList(k+1);
		}
	}
}

int main() {
	freopen("binarylist.txt", "r", stdin);
	cnt = 0;
	cin >> n;
	cin >> viTriCanInkq;
	cin >> m;
	binaryList(1);
	if(isPrint == false) cout << "-1";
	cout << "soLanDuyet = " << soLanDuyet;
}
