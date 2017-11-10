#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 10000
#include<string>

using namespace std;

int a[MAX+1];
int n;
char s[MAX];

void output() {
	for(int i = 0; i < n; i++) {
		cout << s[i];
	}
}

int main() {
	cin >> n;
	cin >> s;
	
	for(int i = n-1; i >= 0; i--) {
		if(s[i] == '0') {
			//cout << "vi tri = 0 dau tien: " << i << endl;
			int j = i + 1;
			s[i] = '1';
			if(j < n - 1) {
				for(int k = j; k < n; k++) {
					s[k] = '0';
				}	
			}
			
			break;
		}
	}
	
	output();
}
