#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

ll n,m;
ll *a;

void input() {
	cin >> n >> m;
	a = (ll*)malloc(sizeof(ll)*(n+1));

	for (ll i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
}

ll maxSub() {
	ll mEH = 0;		//max end here
	ll max = 0;
	ll sEH = 0;		//sum end here
	bool isHavingM = false;

	for (ll i = 1; i <= n; ++i)
	{
		sEH += a[i];
		if(isHavingM) mEH += a[i];
		if(a[i] == m) {
			mEH = sEH;
			isHavingM = true;
			sEH = 0;
		}
		if(mEH > max) max = mEH;
		cout << "sEH = "<<sEH<<", mEH = "<<mEH<<endl;
	}
	return max;
}

int main()
{
	freopen("alice.txt", "r", stdin);
	input();
	cout << maxSub();
	return 0;
}