#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <iostream>
#define MAX 100000

//#define for(i, a, b) for(int i = a; i < b; i++)

//typedef long long LL;

using namespace std;

int n;
int *t;
int ans;

int main() {
	//freopen("ptrees.txt", "r", stdin);
	cin >> n;
	t = (int *) malloc(sizeof(int) * (n+1));
	for(int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	
	sort(t+1, t+n+1, greater<int>());	//sap xep mang input
	
	int max = -1;
	for(int i = 1; i <= n; i++) {
		if(t[i] + i > max) max = t[i] + i;	
	}
	
	cout << (max + 1);
}

